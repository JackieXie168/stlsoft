/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/thread_mutex.hpp (formerly unixstl_thread_mutex.h; originally MLCrtSct.h, ::SynesisStd)
 *
 * Purpose:     Intra-process mutex, based on PTHREADS pthread_mutex_t.
 *
 * Created:     17th December 1996
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2006, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file unixstl/synch/thread_mutex.hpp
 *
 * \brief [C++ only] Definition of the unixstl::thread_mutex class.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_THREAD_MUTEX
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_THREAD_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_MAJOR       4
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_MINOR       0
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_REVISION    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_EDIT        37
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#if !defined(_REENTRANT) && \
    !defined(_POSIX_THREADS)
# error unixstl_thread_mutex.h must be compiled in the context of PTHREADS
#endif /* !_REENTRANT && !_POSIX_THREADS */
#include <pthread.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class thread_mutex
/** \brief This class provides an implementation of the mutex model based on
 *   the PTHREADS mutex.
 *
 * \ingroup group__library__synch
 */
class thread_mutex
    : public stlsoft_ns_qual(critical_section)< STLSOFT_CRITICAL_SECTION_IS_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
{
public:
    typedef thread_mutex class_type;

// Construction
public:
    /// Creates an instance of the mutex
    ss_explicit_k thread_mutex(us_bool_t bRecursive = true) stlsoft_throw_0()
        : m_init(create_(&m_mx, bRecursive))
    {}
    /// Destroys an instance of the mutex
    ~thread_mutex() stlsoft_throw_0()
    {
        if(m_init)
        {
            ::pthread_mutex_destroy(&m_mx);
        }
    }

// Operations
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock() stlsoft_throw_0()
    {
        pthread_mutex_lock(&m_mx);
    }
    /// Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was aquired, or <b>false</b> if not
    /// \note Only available with Windows NT 4 and later
    bool try_lock()
    {
        return pthread_mutex_trylock(&m_mx) == 0;
    }
    /// Releases an aquired lock on the mutex
    void unlock() stlsoft_throw_0()
    {
        pthread_mutex_unlock(&m_mx);
    }

// Implementation
private:
    static us_bool_t create_(pthread_mutex_t *mx, us_bool_t bRecursive)
    {
        us_bool_t           bSuccess    =   false;
        pthread_mutexattr_t attr;

        if(0 == ::pthread_mutexattr_init(&attr))
        {
            if( !bRecursive ||
                0 == ::pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE))
            {
                if(0 == ::pthread_mutex_init(mx, &attr))
                {
                    bSuccess = true;
                }
            }

            ::pthread_mutexattr_destroy(&attr);
        }

        return bSuccess;
    }

// Members
private:
    pthread_mutex_t m_mx;   // mx
    us_bool_t       m_init;

// Not to be implemented
private:
    thread_mutex(class_type const &rhs);
    thread_mutex &operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////
 * Control shims
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/** \brief This \ref group__concept__shims "control shim" aquires a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to aquire the lock.
 */
inline void lock_instance(unixstl_ns_qual(thread_mutex) &mx)
{
    mx.lock();
}

/** \brief This \ref group__concept__shims "control shim" releases a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to release the lock
 */
inline void unlock_instance(unixstl_ns_qual(thread_mutex) &mx)
{
    mx.unlock();
}



#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace unixstl
{
# else
namespace unixstl_project
{
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * lock_traits (for the compilers that do not support Koenig Lookup)
 */

// class lock_traits
/** \brief Traits for the thread_mutex class (for compilers that do not support Koenig Lookup)
 *
 * \ingroup group__library__synch
 */
struct thread_mutex_lock_traits
{
public:
    /// The lockable type
    typedef thread_mutex                lock_type;
    typedef thread_mutex_lock_traits    class_type;

// Operations
public:
    /// Lock the given thread_mutex instance
    static void lock(thread_mutex &c)
    {
        lock_instance(c);
    }

    /// Unlock the given thread_mutex instance
    static void unlock(thread_mutex &c)
    {
        unlock_instance(c);
    }
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/thread_mutex_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_THREAD_MUTEX */

/* ////////////////////////////////////////////////////////////////////// */
