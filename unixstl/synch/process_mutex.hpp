/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/process_mutex.hpp (formerly unixstl_process_mutex.h)
 *
 * Purpose:     Intra-process mutext, based on PTHREADS.
 *
 * Created:     15th May 2002
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/** \file unixstl/synch/process_mutex.hpp
 *
 * \brief [C++ only] Definition of the unixstl::process_mutex class.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX_MAJOR      4
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX_MINOR      0
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX_REVISION   1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX_EDIT       49
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_H_UNIXSTL_EXCEPTIONS
#  include <unixstl/exceptions.hpp>
# endif /* !UNIXSTL_INCL_H_UNIXSTL_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#if !defined(_REENTRANT) && \
    !defined(_POSIX_THREADS)
# error unixstl_process_mutex.h must be compiled in the context of PTHREADS
#endif /* !_REENTRANT && !_POSIX_THREADS */
#include <errno.h>
#include <pthread.h>

#ifdef STLSOFT_UNITTEST
# include <stdio.h>
#endif /* STLSOFT_UNITTEST */

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

// class process_mutex
/** \brief This class provides an implementation of the mutex model based on
 *   the PTHREADS pthread_mutex_t.
 *
 * \ingroup group__library__synch
 */
class process_mutex
    : public stlsoft_ns_qual(critical_section)< STLSOFT_CRITICAL_SECTION_ISNOT_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
{
public:
    typedef process_mutex class_type;

// Construction
public:
    /// Creates an instance of the mutex
    ///
    /// \note On systems that support shared mutexes, this will be not shared. Use
    /// the other constructor to obtain a shared mutex
    ss_explicit_k process_mutex(us_bool_t bRecursive) stlsoft_throw_0()
#if defined(_POSIX_THREAD_PROCESS_SHARED)
        : m_error(create_(&m_mx, PTHREAD_PROCESS_PRIVATE, bRecursive))
#else /* ? _POSIX_THREAD_PROCESS_SHARED */
        : m_error(create_(&m_mx, 0, bRecursive))
#endif /* _POSIX_THREAD_PROCESS_SHARED */
    {}
#if defined(_POSIX_THREAD_PROCESS_SHARED)
    /// Creates an instance of the mutex, optionally recursive and/or shared between processes
    ///
    /// \param pshared A value from the PTHREADS_PROCESS_* group that determines the sharing
    ///  characteristics of the mutex.
    /// \param bRecursive A boolean value denoting whether the mutex should be recursive or not
    process_mutex(int pshared, us_bool_t bRecursive) stlsoft_throw_0()
        : m_error(create_(&m_mx, pshared, bRecursive))
    {}
#endif /* _POSIX_THREAD_PROCESS_SHARED */
    /// Destroys an instance of the mutex
    ~process_mutex() stlsoft_throw_0()
    {
        if(0 == m_error)
        {
            ::pthread_mutex_destroy(&m_mx);
        }
    }

// Operations
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock() stlsoft_throw_0()
    {
        m_error = ::pthread_mutex_lock(&m_mx);
    }
    /// Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was aquired, or <b>false</b> if not
    /// \note Only available with Windows NT 4 and later
    bool try_lock()
    {
        return 0 == (m_error = ::pthread_mutex_trylock(&m_mx));
    }
    /// Releases an aquired lock on the mutex
    void unlock() stlsoft_throw_0()
    {
        m_error = ::pthread_mutex_unlock(&m_mx);
    }

    /// Contains the last failed error code from the underlying PTHREADS API
    int get_error() const
    {
        return m_error;
    }

// Implementation
private:
    static int create_(pthread_mutex_t *mx, int pshared, us_bool_t bRecursive)
    {
        pthread_mutexattr_t attr;
        int                 res = 0;

        if(0 == (res = ::pthread_mutexattr_init(&attr)))
        {
            if( !bRecursive ||
                0 == (res = ::pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE)))
            {
#if defined(_POSIX_THREAD_PROCESS_SHARED)
                if(0 != (res = ::pthread_mutexattr_setpshared(&attr, pshared)))
                {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    throw unix_exception("Failed to set process-sharing attribute for PTHREADS mutex", res);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }
                else
#else /* ? _POSIX_THREAD_PROCESS_SHARED */
                STLSOFT_SUPPRESS_UNUSED(pshared);
#endif /* _POSIX_THREAD_PROCESS_SHARED */
                {
                    if(0 == (res = ::pthread_mutex_init(mx, &attr)))
                    {
                    }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    else
                    {
                        throw unix_exception("Failed to set initialise PTHREADS mutex", res);
                    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }
            }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            else
            {
                throw unix_exception("Failed to set recursive attribute to PTHREADS mutex", res);
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

            int res2 = res;

            ::pthread_mutexattr_destroy(&attr);

            res = res2;
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        else
        {
            throw unix_exception("Failed to initialise PTHREADS mutex attributes", res);
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        return res;
    }

// Members
private:
    pthread_mutex_t m_mx;       // The mutex
    int             m_error;    // The last PTHREADS error

// Not to be implemented
private:
    process_mutex(class_type const &rhs);
    process_mutex &operator =(class_type const &rhs);
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
inline void lock_instance(unixstl_ns_qual(process_mutex) &mx)
{
    mx.lock();
}

/** \brief This \ref group__concept__shims "control shim" releases a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to release the lock
 */
inline void unlock_instance(unixstl_ns_qual(process_mutex) &mx)
{
    mx.unlock();
}


#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace unixstl
{
# else /* ? _STLSOFT_NO_NAMESPACE */
namespace unixstl_project
{
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * lock_traits (for the compilers that do not support Koenig Lookup)
 */

// class lock_traits
/// Traits for the process_mutex class (for compilers that do not support Koenig Lookup)
struct process_mutex_lock_traits
{
public:
    /// The lockable type
    typedef process_mutex                lock_type;
    typedef process_mutex_lock_traits    class_type;

// Operations
public:
    /// Lock the given process_mutex instance
    static void lock(process_mutex &c)
    {
#if defined(STLSOFT_COMPILER_IS_BORLAND)
        // Borland requires that we explicitly qualify the shim functions, even
        // though they're defined in the enclosing namespace of this one.
        stlsoft_ns_qual(lock_instance)(c);
#else /* ? compiler */
        lock_instance(c);
#endif /* compiler */
    }

    /// Unlock the given process_mutex instance
    static void unlock(process_mutex &c)
    {
#if defined(STLSOFT_COMPILER_IS_BORLAND)
        // Borland requires that we explicitly qualify the shim functions, even
        // though they're defined in the enclosing namespace of this one.
        stlsoft_ns_qual(unlock_instance)(c);
#else /* ? compiler */
        unlock_instance(c);
#endif /* compiler */
    }
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/process_mutex_unittest_.h"
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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX */

/* ////////////////////////////////////////////////////////////////////// */
