/* ////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/spin_mutex.hpp (formerly unixstl_spin_mutex.h; originally MWSpinMx.h, ::SynesisWin)
 *
 * Purpose:     Intra-process mutex, based on spin waits.
 *
 * Created:     27th August 1997
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2005, Matthew Wilson and Synesis Software
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


/// \file unixstl/spin_mutex.hpp
///
/// Intra-process mutex, based on spin waits.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_SPIN_MUTEX
#define UNIXSTL_INCL_UNIXSTL_HPP_SPIN_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_SPIN_MUTEX_MAJOR       3
# define UNIXSTL_VER_UNIXSTL_HPP_SPIN_MUTEX_MINOR       1
# define UNIXSTL_VER_UNIXSTL_HPP_SPIN_MUTEX_REVISION    1
# define UNIXSTL_VER_UNIXSTL_HPP_SPIN_MUTEX_EDIT        37
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#if defined(UNIXSTL_OS_IS_LINUX) && \
    !defined(UNIXSTL_ARCH_IS_INTEL)
# include <asm/atomic.h> // Only works for Linux. For other OSs, use unixstl_process_mutex.h
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
# include <libkern/OSAtomic.h>
#else /* ? architecture */
# include <unixstl/atomic_functions.h>
#endif /* architecture */
#include <sched.h>

#ifdef STLSOFT_UNITTEST
# include <stlsoft/lock_scope.hpp>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(__STLSOFT_DOCUMENTATION_SKIP_SECTION)
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

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class spin_mutex
/// This class provides an implementation of the mutex model based on a spinning mechanism
class spin_mutex
{
public:
    typedef spin_mutex  class_type;
#if defined(UNIXSTL_OS_IS_LINUX) && \
    !defined(UNIXSTL_ARCH_IS_INTEL)
    typedef atomic_t    atomic_int_type;
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
    typedef ::int32_t   atomic_int_type;
#else /* ? architecture */
    typedef us_sint32_t atomic_int_type;
#endif /* architecture */

// Construction
public:
    /// Creates an instance of the mutex
    ss_explicit_k spin_mutex(atomic_int_type *p = NULL) stlsoft_throw_0()
        : m_spinCount((NULL != p) ? p : &m_internalCount)
        , m_internalCount(0)
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        , m_cLocks(0)
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    {}
    /// Destroys an instance of the mutex
    ~spin_mutex() stlsoft_throw_0()
    {
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 == m_cLocks);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    }

// Operations
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock() stlsoft_throw_0()
    {
#if defined(UNIXSTL_OS_IS_LINUX) && \
    !defined(UNIXSTL_ARCH_IS_INTEL)
        for(; 0 != ::atomic_inc_and_test(m_spinCount); ::sched_yield())
        {}
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
    for(; !::OSAtomicCompareAndSwap32Barrier(0, 1, m_spinCount); ::sched_yield())
    {}
#else /* ? arch */
        for(; 0 != atomic_write(m_spinCount, 1); ::sched_yield())
        {}
#endif /* arch */
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 != ++m_cLocks);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
    }
    /// Releases an aquired lock on the mutex
    void unlock() stlsoft_throw_0()
    {
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(m_cLocks-- != 0);
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS
#if defined(UNIXSTL_OS_IS_LINUX) && \
    !defined(UNIXSTL_ARCH_IS_INTEL)
        ::atomic_dec(m_spinCount);
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
        ::OSAtomicDecrement32Barrier(m_spinCount);
#else /* ? arch */
        atomic_write(m_spinCount, 0);
#endif /* arch */
    }

// Members
private:
    atomic_int_type *m_spinCount;
    atomic_int_type m_internalCount;
#ifdef STLSOFT_SPINMUTEX_COUNT_LOCKS
    atomic_int_type m_cLocks;       // Used as check on matched Lock/Unlock calls
#endif // STLSOFT_SPINMUTEX_COUNT_LOCKS

// Not to be implemented
private:
    spin_mutex(class_type const &rhs);
    spin_mutex &operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Control shims
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(__STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_sync_control Synchronisation Control Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" control the behaviour of synchronisation objects

/// \defgroup unixstl_sync_control_shims Synchronisation Control Shims (UNIXSTL)
/// \ingroup UNIXSTL concepts_shims_sync_control
/// \brief These \ref concepts_shims "shims" control the behaviour of Win32 synchronisation objects
/// @{

/// This control ref concepts_shims "shim" aquires a lock on the given mutex
///
/// \param mx The mutex on which to aquire the lock
inline void lock_instance(unixstl_ns_qual(spin_mutex) &mx)
{
    mx.lock();
}

/// This control ref concepts_shims "shim" releases a lock on the given mutex
///
/// \param mx The mutex on which to release the lock
inline void unlock_instance(unixstl_ns_qual(spin_mutex) &mx)
{
    mx.unlock();
}

/// @} // end of group unixstl_sync_control_shims

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(__STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace unixstl
{
# else
namespace unixstl_project
{
#  if defined(STLSOFT_COMPILER_IS_BORLAND)
using ::stlsoft::lock_instance;
using ::stlsoft::unlock_instance;
#  endif /* STLSOFT_COMPILER_IS_BORLAND */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

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

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(__STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_UNIXSTL_HPP_SPIN_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */
