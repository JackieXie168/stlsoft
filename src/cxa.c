#include "stlport_prefix.h"

#if defined(__unix) && defined(__GNUC__)

#ifdef __FreeBSD__
#  include <osreldate.h>
#endif

#if (defined(__FreeBSD__) && (__FreeBSD_version < 503001)) || defined(__sun)
/* Note: __cxa_finalize and __cxa_atexit present in libc in FreeBSD 5.3 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* __asm__ (".symver " "__cxa_finalize" "," "__cxa_finalize" "@" "STLPORT_5_0_0"); */
/* __asm__ (".symver " "__cxa_finalize" "," "__cxa_finalize" "@@" "STLPORT_5_0_0"); */

/* Not atomic! */
/* But we can use static mutexes here: I hope that performance issue isn't very
   significant on unloading (for only few calls, ~10) - ptr */

/*
#define atomic_compare_and_exchange_bool_acq(mem, newval, oldval) \
  ({ __typeof (mem) __gmemp = (mem);                                  \
     __typeof (*mem) __gnewval = (newval);                            \
                                                                      \
     *__gmemp == (oldval) ? (*__gmemp = __gnewval, 0) : 1; })
*/

enum {
  ef_free, /* `ef_free' MUST be zero!  */
  ef_us,
  ef_on,
  ef_at,
  ef_cxa
};

struct exit_function
{
  /* `flavour' should be of type of the `enum' above but since we need
     this element in an atomic operation we have to use `long int'.  */
  long int flavor;
  union {
    void (*at)(void);
    struct {
      void (*fn)(int status, void *arg);
      void *arg;
    } on;
    struct {
      void (*fn)(void *arg, int status);
      void *arg;
      void *dso_handle;
    } cxa;
  } func;
};

struct exit_function_list
{
  struct exit_function_list *next;
  size_t idx;
  struct exit_function fns[32];
};

struct exit_function *__new_exitfn (void);

/* Register a function to be called by exit or when a shared library
   is unloaded.  This function is only called from code generated by
   the C++ compiler.  */
int __cxa_atexit(void (*func)(void *), void *arg, void *d)
{
  struct exit_function *new = __new_exitfn ();

  if ( new == NULL )
    return -1;

  new->flavor = ef_cxa;
  new->func.cxa.fn = (void (*) (void *, int)) func;
  new->func.cxa.arg = arg;
  new->func.cxa.dso_handle = d;
  return 0;
}


/* We change global data, so we need locking.  */
#ifdef __linux__
static pthread_mutex_t lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#endif
/* #ifdef __FreeBSD__ */
#if 0
static pthread_mutex_t lock =
  { PTHREAD_MUTEX_RECURSIVE /* PTHREAD_MUTEX_DEFAULT */, PTHREAD_PRIO_NONE, {NULL,NULL},
    NULL, { NULL }, /* MUTEX_FLAGS_PRIVATE */ 0x1, 0, 0, 0, {NULL, NULL},
    { 0, 0, 0, 0 } };
#endif
#ifdef __sun
static pthread_mutex_t lock =
  {{0, 0, 0, PTHREAD_MUTEX_RECURSIVE, _MUTEX_MAGIC}, {{{0}}}, 0};
#endif


static struct exit_function_list initial;
struct exit_function_list *__exit_funcs = &initial;

struct exit_function *__new_exitfn(void)
{
  struct exit_function_list *l;
  size_t i = 0;

#ifndef __FreeBSD__
  pthread_mutex_lock( &lock );
#endif

  for (l = __exit_funcs; l != NULL; l = l->next) {
    for (i = 0; i < l->idx; ++i)
      if (l->fns[i].flavor == ef_free)
        break;
    if ( i < l->idx )
      break;

    if (l->idx < sizeof (l->fns) / sizeof (l->fns[0])) {
      i = l->idx++;
      break;
    }
  }

  if (l == NULL) {
    l = (struct exit_function_list *)malloc( sizeof(struct exit_function_list) );
    if (l != NULL) {
      l->next = __exit_funcs;
      __exit_funcs = l;

      l->idx = 1;
      i = 0;
    }
  }

  /* Mark entry as used, but we don't know the flavor now.  */
  if ( l != NULL )
    l->fns[i].flavor = ef_us;

#ifndef __FreeBSD__
  pthread_mutex_unlock( &lock );
#endif

  return l == NULL ? NULL : &l->fns[i];
}

/* If D is non-NULL, call all functions registered with `__cxa_atexit'
   with the same dso handle.  Otherwise, if D is NULL, call all of the
   registered handlers.  */

/* 
 * Note, that original __cxa_finalize don't use lock, but use __exit_funcs
 * i.e. global data.
 */
void __cxa_finalize(void *d)
{
  struct exit_function_list *funcs;

#ifndef __FreeBSD__
  pthread_mutex_lock( &lock );
#endif

  for (funcs = __exit_funcs; funcs; funcs = funcs->next) {
    struct exit_function *f;

    for (f = &funcs->fns[funcs->idx - 1]; f >= &funcs->fns[0]; --f) {
      if ( (d == NULL || d == f->func.cxa.dso_handle) && (f->flavor == ef_cxa) ) {
        f->flavor = ef_free;
        (*f->func.cxa.fn) (f->func.cxa.arg, 0);
      }
    }
  }

  /* Remove the registered fork handlers.  We do not have to
     unregister anything if the program is going to terminate anyway.  */
#ifdef UNREGISTER_ATFORK
  if (d != NULL)
    UNREGISTER_ATFORK (d);
#endif
#ifndef __FreeBSD__
  pthread_mutex_unlock( &lock );
#endif
}

/* __asm__ (".symver " "__cxa_finalize" "," "__cxa_finalize" "@@" "STLPORT_5_0_0"); */
/* void __cxa_finalize(void *d) __attribute__ ((weak)); */

#endif /* OS name */
#endif /* __unix */

