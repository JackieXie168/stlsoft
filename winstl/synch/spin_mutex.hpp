/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/spin_mutex.hpp (originally MWSpinMx.h, ::SynesisWin)
 *
 * Purpose:     Intra-process mutex, based on spin waits.
 *
 * Created:     27th August 1997
 * Updated:     6th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/spin_mutex.hpp
 *
 * \brief [C++ only] Definition of winstl::spin_index class.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX
#define WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_MAJOR       4
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_REVISION    1
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_EDIT        43
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

#ifdef STLSOFT_UNITTEST
# include <stlsoft/synch/lock_scope.hpp>
#endif /* STLSOFT_UNITTEST */

#if defined(_DEBUG)
# define    STLSOFT_SPINMUTEX_COUNT_LOCKS
#endif /* _DEBUG */

#if defined(_ATL_MIN_CRT)
# define    WINSTL_SPINMUTEX_CHECK_INIT
#endif /* _ATL_MIN_CRT */

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

// class spin_mutex
/** \brief This class provides an implementation of the mutex model based on
 *   a spinning mechanism
 *
 * \ingroup group__library__synch
 *
 * \note A spin mutex is not recursive. If you re-enter it your thread will
 *  be in irrecoverable deadlock.
 */
class spin_mutex
    : public stlsoft_ns_qual(critical_section)< STLSOFT_CRITICAL_SECTION_ISNOT_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_ISNOT_TRYABLE
                                            >
{
/// \name Member Types
/// @{
public:
    /// \brief This class
    typedef spin_mutex      class_type;
    /// \brief The atomic integer type
    typedef ws_sint32_t     atomic_int_type;
    /// \brief The count type
    typedef ws_sint32_t     count_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Creates an instance of the mutex
    ///
    /// \param p Pointer to an external counter variable. May be NULL, in
    ///  which case an internal member is used for the counter variable.
    ss_explicit_k spin_mutex(atomic_int_type *p = NULL) stlsoft_throw_0()
        : m_spinCount((NULL != p) ? p : &m_internalCount)
        , m_internalCount(0)
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        , m_cLocks(0)
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
        , m_spunCount(0)
    {}
    /// Destroys an instance of the mutex
    ~spin_mutex() stlsoft_throw_0()
    {
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 == m_cLocks);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock() stlsoft_throw_0()
    {
#ifdef WINSTL_SPINMUTEX_CHECK_INIT 
        // If the dynamic initialisation phase has been skipped, the
        // members will all be assigned to 0, which is correct for
        // all except m_spinCount, which must be assigned to 
        // &m_internalCount
        if(NULL == m_spinCount)
        {
            m_spinCount = &m_internalCount;
        }
#endif /* WINSTL_SPINMUTEX_CHECK_INIT  */

        WINSTL_MESSAGE_ASSERT("A global instance of spin_mutex has skipped dynamic initialisation. You must #define WINSTL_SPINMUTEX_CHECK_INIT if your compilation causes dynamic initialisation to be skipped.", NULL != m_spinCount);

//      WINSTL_MESSAGE_ASSERT("Attempting to re-enter a spin mutex that is already acquired: this will deadlock!", 0 == m_spunCount);

        for(m_spunCount = 1; 0 != ::InterlockedExchange(reinterpret_cast<LPLONG>(m_spinCount), 1); ++m_spunCount, ::Sleep(1))
        {}

#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 != ++m_cLocks);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    }
    /// \brief Releases an aquired lock on the mutex
    void unlock() stlsoft_throw_0()
    {
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 != m_cLocks--);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS

        m_spunCount = 0;

        static_cast<void>(::InterlockedExchange(reinterpret_cast<LPLONG>(m_spinCount), 0));
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief An indicator as to the level of contention on the mutex.
    ///
    /// \note The value returned is only meaningful after lock() has been
    ///  called and before a corresponding unlock() has been called.
    ///
    /// \note The value returned is only reliable when an external counter
    ///  variable is being used, and when each spin_mutex instance is
    ///  thread-specific. In all other cases, the spun count is subject to
    ///  race conditions (that do <b>not</b> affect the good functioning of
    ///  the spin_mutex) and value returned may be, at best, used only as a
    ///  guide as to contention.
    count_type  spun_count() const
    {
        return m_spunCount;
    }
/// @}

/// \name Members
/// @{
private:
    atomic_int_type *m_spinCount;
    atomic_int_type m_internalCount;
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
    count_type      m_cLocks;       // Used as check on matched Lock/Unlock calls
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    count_type      m_spunCount;
/// @}

/// \name Not to be implemented
/// @{
private:
    spin_mutex(class_type const &rhs);
    class_type &operator =(class_type const &rhs);
/// @}
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
inline void lock_instance(winstl_ns_qual(spin_mutex) &mx)
{
    mx.lock();
}

/** \brief This \ref group__concept__shims "control shim" releases a lock on the given mutex
 *
 * \ingroup group__composite__synch_control_shims
 *
 * \param mx The mutex on which to release the lock
 */
inline void unlock_instance(winstl_ns_qual(spin_mutex) &mx)
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
/// Traits for the spin_mutex class (for compilers that do not support Koenig Lookup)
struct spin_mutex_lock_traits
{
public:
    /// The lockable type
    typedef spin_mutex                lock_type;
    typedef spin_mutex_lock_traits    class_type;

// Operations
public:
    /// Lock the given spin_mutex instance
    static void lock(spin_mutex &c)
    {
        lock_instance(c);
    }

    /// Unlock the given spin_mutex instance
    static void unlock(spin_mutex &c)
    {
        unlock_instance(c);
    }
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/spin_mutex_unittest_.h"
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */
