/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/conversion_functions.h (originally winstl_time_functions.h)
 *
 * Purpose:     Comparison functions for Windows time structures.
 *
 * Created:     21st November 2003
 * Updated:     13th September 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/time/conversion_functions.h
 *
 * \brief [C, C++] Conversion functions for Windows time types.
 *  (\ref group__library__time "Time" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_MAJOR    4
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_REVISION 2
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_EDIT     39
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS
# include <stlsoft/util/limit_traits.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS */
#include <time.h>

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** \brief Converts a time_t into a FILETIME
 *
 * \ingroup group__library__time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
STLSOFT_INLINE void winstl__UNIXTimeToFILETIME(time_t t, FILETIME *ft)
{
    const ws_uint64_t i = UInt32x32To64(t, 10000000) + STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);

    WINSTL_ASSERT(NULL != ft);

    ft->dwLowDateTime = (DWORD)i;
    ft->dwHighDateTime = (DWORD)(i >> 32);
}

STLSOFT_INLINE void winstl__UNIXTimeToFILETIME_us(time_t t, ws_sint32_t usec, FILETIME *ft)
{
    ws_uint64_t i = UInt32x32To64(t, 10000000) + Int32x32To64(usec, 10) + STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);

    WINSTL_ASSERT(NULL != ft);

    ft->dwLowDateTime = (DWORD)i;
    ft->dwHighDateTime = (DWORD)(i >> 32);
}

STLSOFT_INLINE time_t winstl__FILETIMEToUNIXTime(FILETIME const *ft, ws_sint32_t *microseconds)
{
    ws_sint64_t i;

    i = ft->dwHighDateTime;
    i <<= 32;
    i |= ft->dwLowDateTime;

    i -= STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);
    if(NULL != microseconds)
    {
        *microseconds = stlsoft_static_cast(ws_sint32_t, (i % 10000000) / 10);

        WINSTL_ASSERT(*microseconds >= 0 && *microseconds <= 999);
    }
    i /= 10000000;

    return stlsoft_static_cast(time_t, i);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

/** \brief Converts a time_t into a FILETIME
 *
 * \ingroup group__library__time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline void UNIXTimeToFILETIME(time_t t, FILETIME &ft)
{
    winstl__UNIXTimeToFILETIME(t, &ft);
}

/** \brief Converts a time_t into a FILETIME
 *
 * \ingroup group__library__time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline FILETIME UNIXTimeToFILETIME(time_t t)
{
    FILETIME    ft;

    winstl__UNIXTimeToFILETIME(t, &ft);

    return ft;
}

/** \brief Converts a time_t + microseconds into a FILETIME
 *
 * \ingroup group__library__time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline void UNIXTimeToFILETIME(time_t t, ws_sint32_t usec, FILETIME &ft)
{
    winstl__UNIXTimeToFILETIME_us(t, usec, &ft);
}

/** \brief Converts a time_t + microseconds into a FILETIME
 *
 * \ingroup group__library__time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline FILETIME UNIXTimeToFILETIME(time_t t, ws_sint32_t usec)
{
    FILETIME    ft;

    winstl__UNIXTimeToFILETIME_us(t, usec, &ft);

    return ft;
}

/** \brief Converts a FILETIME into a time_t
 *
 * \ingroup group__library__time
 */
inline time_t FILETIMEToUNIXTime(FILETIME const &ft, ws_sint32_t *microseconds = NULL)
{
    return winstl__FILETIMEToUNIXTime(&ft, microseconds);
}

/** \brief Converts a FILETIME into a time_t
 *
 * \ingroup group__library__time
 */
inline void FILETIMEToUNIXTime(FILETIME const &ft, time_t &t)
{
    t = winstl__FILETIMEToUNIXTime(&ft, NULL);
}

/** \brief Converts a FILETIME into a time_t
 *
 * \ingroup group__library__time
 */
inline void FILETIMEToUNIXTime(FILETIME const &ft, time_t &t, ws_sint32_t &microseconds)
{
    t = winstl__FILETIMEToUNIXTime(&ft, &microseconds);
}

# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/conversion_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
