/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/thread_mutex.hpp (formerly unixstl_thread_mutex.h; originally MLCrtSct.h, ::SynesisStd)
 *
 * Purpose:     Intra-process mutex, based on PTHREADS pthread_mutex_t.
 *
 * Created:     17th December 1996
 * Updated:     23rd September 2006
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
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_MINOR       1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_REVISION    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_THREAD_MUTEX_EDIT        38
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_UNIXSTL_HPP_ERROR_UNIX_EXCEPTIONS
#  include <unixstl/error/exceptions.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_ERROR_HPP_UNIX_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE
# include <stlsoft/smartptr/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#if !defined(_REENTRANT) && \
    !defined(_POSIX_THREADS)
# error unixstl/synch/thread_mutex.hpp must be compiled in the context of PTHREADS
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
/// \name Member Types
/// @{
public:
    typedef thread_mutex        class_type;
    typedef us_bool_t           bool_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Creates an instance of the mutex
    ss_explicit_k thread_mutex(bool_type bRecursive = true) stlsoft_throw_0()
        : m_mx(&m_mx_)
        , m_error(create_(&m_mx_, bRecursive))
        , m_bOwnHandle(true)
    {}

    /// \brief Conversion constructor
    ///
    /// \param mx The raw mutex object handle that this instance will use
    /// \param bTakeOwnership If true, the handle is closed when this instance is destroyed
    thread_mutex(pthread_mutex_t *mx, bool_type bTakeOwnership)
        : m_mx(mx)
        , m_error(0)
        , m_bOwnHandle(bTakeOwnership)
    {
        UNIXSTL_ASSERT(NULL != mx);
    }

    /// \brief Destroys an instance of the mutex
    ~thread_mutex() stlsoft_throw_0()
    {
        if( 0 == m_error &&
            m_bOwnHandle)
        {
            ::pthread_mutex_destroy(m_mx);
        }
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Acquires a lock on the mutex, pending the thread until the lock is aquired
    ///
    /// \exception When compiling with exception support, this will throw
    /// unixstl::unix_exception if the lock cannot be acquired. When
    /// compiling absent exception support, failure to acquire the lock
    /// will be reflected in a non-zero return from get_error().
    void lock()
    {
        m_error = ::pthread_mutex_lock(m_mx);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(0 != m_error)
        {
            throw unix_exception("Mutex lock failed", m_error);
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    /// \brief Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was aquired, or <b>false</b> if not.
    ///
    /// \exception When compiling with exception support, this will throw
    /// unixstl::unix_exception if the lock cannot be acquired for a reason
    /// other than a timeout (<code>EBUSY</code>). When compiling absent
    /// exception support, failure to acquire the lock (for any other
    /// reason) will be reflected in a non-zero return from get_error().
    bool try_lock()
    {
        m_error = ::pthread_mutex_trylock(m_mx);

        if(0 == m_error)
        {
            return true;
        }
        else
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            if(EBUSY != m_error)
            {
                throw unix_exception("Mutex try-lock failed", m_error);
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

            return false;
        }
    }
    /// \brief Releases an aquired lock on the mutex
    ///
    /// \exception When compiling with exception support, this will throw
    /// unixstl::unix_exception if the lock cannot be released. When
    /// compiling absent exception support, failure to release the lock
    /// will be reflected in a non-zero return from get_error().
    void unlock() stlsoft_throw_0()
    {
        m_error = ::pthread_mutex_unlock(m_mx);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(0 != m_error)
        {
            throw unix_exception("Mutex unlock failed", m_error);
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    /// \brief Contains the last failed error code from the underlying PTHREADS API
    int get_error() const stlsoft_throw_0()
    {
        return m_error;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The underlying kernel object handle
    pthread_mutex_t *handle() stlsoft_throw_0()
    {
        return m_mx;
    }
    /// \brief The underlying kernel object handle
    pthread_mutex_t *get() stlsoft_throw_0()
    {
        return m_mx;
    }
/// @}

/// \name Implementation
/// @{
private:
    static int create_(pthread_mutex_t *mx, bool_type bRecursive)
    {
        pthread_mutexattr_t attr;
        int                 res = 0;

        if(0 == (res = ::pthread_mutexattr_init(&attr)))
        {
            stlsoft::scoped_handle<pthread_mutexattr_t*>    attr_(&attr, ::pthread_mutexattr_destroy);

            if( !bRecursive ||
                0 == (res = ::pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE)))
            {
                if(0 == ::pthread_mutex_init(mx, &attr))
                {
                }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                else
                {
                    throw unix_exception("Failed to set initialise PTHREADS mutex", res);
                }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            else
            {
                throw unix_exception("Failed to set recursive attribute to PTHREADS mutex", res);
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        else
        {
            throw unix_exception("Failed to initialise PTHREADS mutex attributes", res);
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return res;
    }
/// @}

/// \name Members
/// @{
private:
    pthread_mutex_t         m_mx_;          // The mutex used when created and owned by the instance
    pthread_mutex_t *const  m_mx;           // The mutex "handle"
    int                     m_error;        // The last PThreads error
    const bool_type         m_bOwnHandle;   // Does the instance own the handle?
/// @}

/// \name Not to be implemented
/// @{
private:
    thread_mutex(class_type const &rhs);
    thread_mutex &operator =(class_type const &rhs);
/// @}
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
 * lock_traits
 */

// class lock_traits
/** \brief Traits for the thread_mutex class
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