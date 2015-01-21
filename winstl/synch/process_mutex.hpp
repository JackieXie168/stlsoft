/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/process_mutex.hpp (formerly winstl/process_mutex.hpp; originally winstl_process_mutex.h)
 *
 * Purpose:     Inter-process mutex, based on Windows MUTEX.
 *
 * Created:     15th May 2002
 * Updated:     3rd June 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/** \file winstl/synch/process_mutex.hpp
 *
 * \brief [C++ only] Definition of winstl::process_mutex class.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX
#define WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_MAJOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_MINOR    0
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_REVISION 1
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_EDIT     40
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
# include <winstl/synch/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class process_mutex
/** \brief This class acts as an inter-process mutex based on the Win32
 *   mutex kernel object
 *
 * \ingroup group__library__synch
 */
class process_mutex
    : public stlsoft_ns_qual(critical_section)< STLSOFT_CRITICAL_SECTION_IS_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
    , public stlsoft_ns_qual(synchronisable_object_tag)
{
public:
    typedef process_mutex   class_type;
	typedef HANDLE			handle_type;

/// \name Construction
/// @{
public:
    /// \brief Creates an instance of the mutex
    process_mutex()
        : m_mx(create_mutex_(NULL, false, static_cast<ws_char_a_t const *>(0), m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Conversion constructor
    process_mutex(HANDLE mx, ws_bool_t bTakeOwnership)
        : m_mx(mx)
        , m_bOwnHandle(bTakeOwnership)
        , m_bCreated(false)
        , m_bAbandoned(false)
    {
        WINSTL_ASSERT(NULL != mx);
    }
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_a_t const *name)
        : m_mx(create_mutex_(NULL, false, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_w_t const *name)
        : m_mx(create_mutex_(NULL, false, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_bool_t bInitialOwer)
        : m_mx(create_mutex_(NULL, bInitialOwer, static_cast<ws_char_a_t const *>(0), m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_a_t const *name, ws_bool_t bInitialOwer)
        : m_mx(create_mutex_(NULL, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_w_t const *name, ws_bool_t bInitialOwer)
        : m_mx(create_mutex_(NULL, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_a_t const *name, ws_bool_t bInitialOwer, LPSECURITY_ATTRIBUTES psa)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}
    /// \brief Creates an instance of the mutex
    ss_explicit_k process_mutex(ws_char_w_t const *name, ws_bool_t bInitialOwer, LPSECURITY_ATTRIBUTES psa)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
    {}

    /// \brief Destroys an instance of the mutex
    ~process_mutex() stlsoft_throw_0()
    {
        if( NULL != m_mx &&
            m_bOwnHandle)
        {
            ::CloseHandle(m_mx);
        }
    }

#if 0
    void close() stlsoft_throw_0()
    {
        if( NULL != m_mx &&
            m_bOwnHandle)
        {
            CloseHandleSetNull(m_mx);
        }
    }
#endif /* 0 */

/// @}

/// \name Operations
/// @{
public:
    /// \brief Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock()
    {
        WINSTL_ASSERT(NULL != m_mx);

        DWORD   dwRes   =   ::WaitForSingleObject(m_mx, INFINITE);

        if(WAIT_ABANDONED == dwRes)
        {
            m_bAbandoned = true;
        }
        else
        {
            m_bAbandoned = false;

            if(WAIT_OBJECT_0 != dwRes)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                throw synchronisation_exception("semaphore wait failed", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
    }
    /// \brief Acquires a lock on the mutex, pending the thread until the lock is aquired
    ws_bool_t lock(ws_dword_t wait)
    {
        WINSTL_ASSERT(NULL != m_mx);

        DWORD   dwRes   =   ::WaitForSingleObject(m_mx, wait);

        if(WAIT_ABANDONED == dwRes)
        {
            m_bAbandoned = true;

            return true;
        }
        else
        {
            m_bAbandoned = false;

            if(WAIT_TIMEOUT == dwRes)
            {
                return false;
            }
            else
            {
                if(WAIT_OBJECT_0 != dwRes)
                {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    throw synchronisation_exception("semaphore wait failed", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }

                return true;
            }
        }
    }
    /// \brief Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was aquired, or <b>false</b> if not
    ws_bool_t try_lock()
    {
        return lock(0);
    }
    /// \brief Releases an aquired lock on the mutex
    void unlock()
    {
        WINSTL_ASSERT(NULL != m_mx);

        ::ReleaseMutex(m_mx);
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The underlying kernel object handle
    HANDLE  handle()
    {
        return m_mx;
    }
    /// \brief The underlying kernel object handle
    HANDLE  get()
    {
        return m_mx;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Indicates whether this object instance created the underlying mutex object
    ///
    /// \return true The mutex object was created by this instance
    /// \return false The mutex object was not created by this instance
    /// \note For unnamed mutexes this will always be false
    ws_bool_t created() const
    {
        return m_bCreated;
    }

    /// \brief Indicates whether a successful call to lock occurred because the underlying
    /// mutex was previously held by a thread that abandoned.
    ///
    /// \return true The mutex object was abandoned by its previous owning thread
    /// \return false The mutex object was not abandoned by its previous owning thread
    /// \note This attribute is meaningful with respect to the result of the last call to lock() or try_lock(). Subsequent calls to unlock() do not affect this attribute.
    ws_bool_t abandoned() const
    {
        return m_bAbandoned;
    }
/// @}

// Implementation
private:
    static HANDLE create_mutex_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bInitialOwner, ws_char_a_t const *name, ws_bool_t &bCreated)
    {
        HANDLE  mx  =   ::CreateMutexA(psa, bInitialOwner, name);

        if(NULL == mx)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to create kernel mutex object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != NULL && ::GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE create_mutex_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bInitialOwner, ws_char_w_t const *name, ws_bool_t &bCreated)
    {
        HANDLE  mx  =   ::CreateMutexW(psa, bInitialOwner, name);

        if(NULL == mx)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to create kernel mutex object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != NULL && ::GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE open_mutex_(ws_dword_t access, ws_bool_t bInheritHandle, ws_char_a_t const *name, ws_bool_t &bCreated)
    {
        HANDLE  mx  =   ::OpenMutexA(access, bInheritHandle, name);

        if(NULL == mx)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to open kernel mutex object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != NULL && ::GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE open_mutex_(ws_dword_t access, ws_bool_t bInheritHandle, ws_char_w_t const *name, ws_bool_t &bCreated)
    {
        HANDLE  mx  =   ::OpenMutexW(access, bInheritHandle, name);

        if(NULL == mx)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to open kernel mutex object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != NULL && ::GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }

// Members
private:
    HANDLE          m_mx;           // The underlying mutex object
    const ws_bool_t m_bOwnHandle;   // Does the instance own the handle?
    ws_bool_t       m_bCreated;     // Did this object (thread) create the underlying mutex object?
    ws_bool_t       m_bAbandoned;   // Did the previous owner abandon the underlying mutex object?

// Not to be implemented
private:
    process_mutex(class_type const &rhs);
    process_mutex &operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Control shims
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/** \brief This \ref group__concept__shims "control shim" aquires a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to aquire the lock.
 */
inline void lock_instance(winstl_ns_qual(process_mutex) &mx)
{
    mx.lock();
}

/** \brief This \ref group__concept__shims "control shim" releases a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to release the lock
 */
inline void unlock_instance(winstl_ns_qual(process_mutex) &mx)
{
    mx.unlock();
}


#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace winstl {
# else
namespace winstl_project {
#  if defined(STLSOFT_COMPILER_IS_BORLAND)
using ::stlsoft::lock_instance;
using ::stlsoft::unlock_instance;
#  endif /* compiler */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
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
        lock_instance(c);
    }

    /// Unlock the given process_mutex instance
    static void unlock(process_mutex &c)
    {
        unlock_instance(c);
    }
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/process_mutex_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */