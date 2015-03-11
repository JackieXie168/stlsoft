/* ////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/atomic_functions.h (formerly unixstl_atomic_functions.h; originally MLAtomic.cpp, ::SynesisStd)
 *
 * Purpose:     UNIXSTL atomic functions.
 *
 * Created:     23rd October 1997
 * Updated:     1st June 2006
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


/** \file unixstl/synch/synch/atomic_functions.h
 *
 * \brief [C++ only] Definition of the atomic functions.
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_MAJOR     5
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_MINOR     0
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_REVISION  1
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_EDIT      183
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#if defined(UNIXSTL_OS_IS_LINUX)
# if defined(UNIXSTL_ARCH_IS_INTEL)
   /* Nothing needed in current version */
# else /* ? arch */
#  include <asm/atomic.h>
# endif /* arch */
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
# include <libkern/OSAtomic.h>
#else /* ? arch */
# error Currently only defined for Intel and Power-PC architectures.
#endif /* ? arch */

/* /////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_threading Threading Library
/// \ingroup libraries
/// \brief This library provides synchronisation and threading facilities

/// \weakgroup unixstl_threading_library Threading Library (UNIXSTL)
/// \ingroup UNIXSTL libraries_threading
/// \ingroup functions
/// \brief This library provides synchronisation and threading facilities for UNIX
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if defined(UNIXSTL_OS_IS_LINUX)
# if defined(UNIXSTL_ARCH_IS_INTEL)
typedef us_sint32_t                 atomic_int_t;
# else /* ? arch */
typedef atomic_t                    atomic_int_t;
# endif /* arch */
#elif defined(UNIXSTL_ARCH_IS_POWERPC)
typedef ::int32_t                   atomic_int_t;
#else /* ? architecture */
typedef us_sint32_t                 atomic_int_t;
#endif /* architecture */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#if defined(UNIXSTL_OS_IS_LINUX)
# if defined(UNIXSTL_ARCH_IS_INTEL)

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_read(atomic_int_t volatile *pv)
{
    /* STLSOFT_NS_GLOBAL(mb)(); */

    return *pv;
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_write(atomic_int_t volatile *pv, atomic_int_t n)
{
    atomic_int_t    oldval;

    /* Note: the "xchg" instruction does not need a "lock" prefix */
#ifdef STLSOFT_COMPILER_IS_GCC
    __asm__ __volatile__(   "xchgl %0, %1"      /* long (32-bit) xchg, from */
                        :   "=r"(oldval),   "=m"(*(pv))
                        :   "0"(n),         "m"(*(pv))
                        :   "memory");
#else /* ? compiler */
    _asm
    {
        mov ecx, dword ptr [pv]
        mov eax, n
        xchg dword ptr [ecx], eax
        mov oldval, eax
    }
#endif /* compiler */

    return oldval;
}

# else /* ? arch */

#  error Currently only defined for Intel Linuxen; If you would like to contribute for your platform, you would be most welcome.

# endif /* arch */

#elif defined(UNIXSTL_ARCH_IS_POWERPC)

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_preincrement(atomic_int_t volatile *pl)
{
    return STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(const_cast<atomic_int_t*>(pl));
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_predecrement(atomic_int_t volatile *pl)
{
    return STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(const_cast<atomic_int_t*>(pl));
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_postincrement(atomic_int_t volatile *pl)
{
    return STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(const_cast<atomic_int_t*>(pl)) - 1;
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_postdecrement(atomic_int_t volatile *pl)
{
    return STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(const_cast<atomic_int_t*>(pl)) + 1;
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline void atomic_increment(atomic_int_t volatile *pl)
{
    STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(const_cast<atomic_int_t*>(pl));
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline void atomic_decrement(atomic_int_t volatile *pl)
{
    STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(const_cast<atomic_int_t*>(pl));
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
/// Note: atomic_write() for PowerPC is not yet defined. If you wish to suggest an
/// implementation, it will be most welcome.
inline atomic_int_t atomic_write(atomic_int_t volatile *pv, atomic_int_t n);

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_read(atomic_int_t volatile *pv)
{
    STLSOFT_NS_GLOBAL(OSMemoryBarrier)();

    return *pv;
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_preadd(atomic_int_t volatile *pl, atomic_int_t n)
{
    return STLSOFT_NS_GLOBAL(OSAtomicAdd32Barrier)(n, const_cast<atomic_int_t*>(pl));
}

/** \brief 
 *
 * \ingroup group__library__synch
 */
inline atomic_int_t atomic_postadd(atomic_int_t volatile *pl, atomic_int_t n)
{
    return STLSOFT_NS_GLOBAL(OSAtomicAdd32Barrier)(n, const_cast<atomic_int_t*>(pl)) - n;
}

#else /* ? architecture */

# error Currently only defined for Intel and Power-PC architectures.

#endif /* architecture */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group unixstl_threading_library

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/atomic_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
