/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/printf_traits.hpp (formerly stlsoft_printf_traits.h)
 *
 * Purpose:     printf_traits classes.
 *
 * Created:     16th January 2002
 * Updated:     8th February 2006
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


/// \file stlsoft/printf_traits.hpp
///
/// printf_traits classes.

#ifndef STLSOFT_INCL_STLSOFT_HPP_PRINTF_TRAITS
#define STLSOFT_INCL_STLSOFT_HPP_PRINTF_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_PRINTF_TRAITS_MAJOR    3
# define STLSOFT_VER_STLSOFT_HPP_PRINTF_TRAITS_MINOR    3
# define STLSOFT_VER_STLSOFT_HPP_PRINTF_TRAITS_REVISION 3
# define STLSOFT_VER_STLSOFT_HPP_PRINTF_TRAITS_EDIT     47
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SIZE_TRAITS
# include <stlsoft/size_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SIZE_TRAITS */

#ifdef STLSOFT_UNITTEST
# include <stlsoft/limit_traits.h>
# include <stlsoft/meta/yesno.hpp>
# include <stlsoft/util/std/stdio_overload_detectors.hpp>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <wchar.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Constants & definitions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define STLSOFT_PRINTF_TRAITS_SINT8_MIN         -128
#define STLSOFT_PRINTF_TRAITS_SINT8_MAX         127

#define STLSOFT_PRINTF_TRAITS_UINT8_MIN         0
#define STLSOFT_PRINTF_TRAITS_UINT8_MAX         255

#define STLSOFT_PRINTF_TRAITS_SINT16_MIN        -32768
#define STLSOFT_PRINTF_TRAITS_SINT16_MAX        32767

#define STLSOFT_PRINTF_TRAITS_UINT16_MIN        0
#define STLSOFT_PRINTF_TRAITS_UINT16_MAX        65535

#define STLSOFT_PRINTF_TRAITS_SINT32_MIN        -2147483648
#define STLSOFT_PRINTF_TRAITS_SINT32_MAX        2147483647

#define STLSOFT_PRINTF_TRAITS_UINT32_MIN        0
#define STLSOFT_PRINTF_TRAITS_UINT32_MAX        4294967295

#define STLSOFT_PRINTF_TRAITS_SINT64_MIN        -9223372036854775808
#define STLSOFT_PRINTF_TRAITS_SINT64_MAX        9223372036854775807

#define STLSOFT_PRINTF_TRAITS_UINT64_MIN        0
#define STLSOFT_PRINTF_TRAITS_UINT64_MAX        18446744073709551615

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define __STLSOFT_PRINTF_TRAITS__SINT8_MIN     STLSOFT_PRINTF_TRAITS_SINT8_MIN
# define __STLSOFT_PRINTF_TRAITS__SINT8_MAX     STLSOFT_PRINTF_TRAITS_SINT8_MAX

# define __STLSOFT_PRINTF_TRAITS__UINT8_MIN     STLSOFT_PRINTF_TRAITS_UINT8_MIN
# define __STLSOFT_PRINTF_TRAITS__UINT8_MAX     STLSOFT_PRINTF_TRAITS_UINT8_MAX

# define __STLSOFT_PRINTF_TRAITS__SINT16_MIN    STLSOFT_PRINTF_TRAITS_SINT16_MIN
# define __STLSOFT_PRINTF_TRAITS__SINT16_MAX    STLSOFT_PRINTF_TRAITS_SINT16_MAX

# define __STLSOFT_PRINTF_TRAITS__UINT16_MIN    STLSOFT_PRINTF_TRAITS_UINT16_MIN
# define __STLSOFT_PRINTF_TRAITS__UINT16_MAX    STLSOFT_PRINTF_TRAITS_UINT16_MAX

# define __STLSOFT_PRINTF_TRAITS__SINT32_MIN    STLSOFT_PRINTF_TRAITS_SINT32_MIN
# define __STLSOFT_PRINTF_TRAITS__SINT32_MAX    STLSOFT_PRINTF_TRAITS_SINT32_MAX

# define __STLSOFT_PRINTF_TRAITS__UINT32_MIN    STLSOFT_PRINTF_TRAITS_UINT32_MIN
# define __STLSOFT_PRINTF_TRAITS__UINT32_MAX    STLSOFT_PRINTF_TRAITS_UINT32_MAX

# define __STLSOFT_PRINTF_TRAITS__SINT64_MIN    STLSOFT_PRINTF_TRAITS_SINT64_MIN
# define __STLSOFT_PRINTF_TRAITS__SINT64_MAX    STLSOFT_PRINTF_TRAITS_SINT64_MAX

# define __STLSOFT_PRINTF_TRAITS__UINT64_MIN    STLSOFT_PRINTF_TRAITS_UINT64_MIN
# define __STLSOFT_PRINTF_TRAITS__UINT64_MAX    STLSOFT_PRINTF_TRAITS_UINT64_MAX

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define ___stringise_(x)           # x
# define ___stringise(x)            ___stringise_(x)

# if defined(STLSOFT_COMPILER_IS_BORLAND)
#  define ___stringise_w_(x)        L"" ## #x
# else /* ? compiler */
#  define ___stringise_w_(x)        L ## #x
# endif /* compiler */
# define ___stringise_w(x)          ___stringise_w_(x)

#ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
# undef STLSOFT_CF_64_BIT_PRINTF_USES_I64
#endif /* STLSOFT_CF_64_BIT_PRINTF_USES_I64 */

#ifdef STLSOFT_CF_64_BIT_PRINTF_USES_LL
# undef STLSOFT_CF_64_BIT_PRINTF_USES_LL
#endif /* STLSOFT_CF_64_BIT_PRINTF_USES_LL */

# if defined(STLSOFT_COMPILER_IS_BORLAND) || \
     (  defined(STLSOFT_COMPILER_IS_COMO) && \
        defined(_MSC_VER)) || \
     (  defined(WIN32) && \
        (   defined(STLSOFT_COMPILER_IS_GCC)) || \
            defined(STLSOFT_COMPILER_IS_INTEL)) || \
     defined(STLSOFT_COMPILER_IS_MSVC) || \
     defined(STLSOFT_COMPILER_IS_VECTORC) || \
     defined(STLSOFT_COMPILER_IS_WATCOM)
#  define STLSOFT_CF_64_BIT_PRINTF_USES_I64
# elif defined(STLSOFT_COMPILER_IS_COMO) || \
       defined(STLSOFT_COMPILER_IS_DMC) || \
       defined(STLSOFT_COMPILER_IS_INTEL) || \
       defined(STLSOFT_COMPILER_IS_MSVC) || \
       defined(STLSOFT_COMPILER_IS_GCC) || \
       defined(STLSOFT_COMPILER_IS_MWERKS)
#  define STLSOFT_CF_64_BIT_PRINTF_USES_LL
# else /* ? compiler */
#  error Further compiler discrimination is required
# endif /* printf-64 */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// struct printf_traits

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/// Traits for determining the size, in printf-ed form, of the minimum and
/// maximum values of types
///
/// printf_traits is a traits class for acquiring enum values representing the
/// lengths, when expressed in string form, of the minimum and maximum values of
/// the type, and the maximum of the two. The lengths are inclusive of the
/// null terminator.
///
/// &nbsp;&nbsp;<code>printf_traits<ss_sint16_t>::size_min == 6</code><br>
/// &nbsp;&nbsp;<code>printf_traits<ss_sint16_t>::size_max == 7</code><br>
/// &nbsp;&nbsp;<code>printf_traits<ss_sint16_t>::size == 7</code><br>
///
/// \param T The type
template <ss_typename_param_k T>
struct printf_traits
{
    enum
    {
            size_min    //!< The number of characters (& null) in the minimum value
        ,   size_max    //!< The number of characters (& null) in the maximum value
        ,   size        //!< The maximum of \c size_min and \c size_max
    };

    /// Returns the appropriate printf format for the type
    static ss_char_a_t const *format_a();
    /// Returns the appropriate wprintf format for the type
    static ss_char_w_t const *format_w();
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k T>
struct printf_traits;
template <ss_typename_param_k T>
struct printf_traits_fixed;

//#ifdef STLSOFT_CF_8BIT_INT_EXTENDED_TYPE_IS_DISTINCT

/* s/uint8 */
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_sint8_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT8_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT8_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%d";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%d";
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_uint8_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT8_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT8_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%u";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%u";
    }
};

//#endif // STLSOFT_CF_8BIT_INT_EXTENDED_TYPE_IS_DISTINCT
//#ifdef STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT

/* s/uint16 */
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_sint16_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT16_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT16_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%d";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%d";
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_uint16_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT16_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT16_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%u";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%u";
    }
};

//#endif // STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
//#ifdef STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT

/* s/uint32 */
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_sint32_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT32_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT32_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%ld";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%ld";
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_uint32_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT32_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT32_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
        return "%lu";
    }
    static ss_char_w_t const *format_w()
    {
        return L"%lu";
    }
};

//#endif // STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

/* s/uint64 */
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_sint64_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT64_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_SINT64_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
#if defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)
        return "%I64d";
#elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)
        return "%lld";
#else
# error Further compiler discrimination is required
#endif /* printf-64 */
    }
    static ss_char_w_t const *format_w()
    {
#if defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)
        return L"%I64d";
#elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)
        return L"%lld";
#else
# error Further compiler discrimination is required
#endif /* printf-64 */
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits_fixed<ss_uint64_t>
{
    enum
    {
            size_min = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT64_MIN))
        ,   size_max = sizeof(___stringise(STLSOFT_PRINTF_TRAITS_UINT64_MAX))
        ,   size = (size_min < size_max) ? size_max : size_min
    };

    static ss_char_a_t const *format_a()
    {
#if defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)
        return "%I64u";
#elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)
        return "%llu";
#else
# error Further compiler discrimination is required
#endif /* printf-64 */
    }
    static ss_char_w_t const *format_w()
    {
#if defined(STLSOFT_CF_64_BIT_PRINTF_USES_I64)
        return L"%I64u";
#elif defined(STLSOFT_CF_64_BIT_PRINTF_USES_LL)
        return L"%llu";
#else
# error Further compiler discrimination is required
#endif /* printf-64 */
    }
};

#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_sint8_t>
    : printf_traits_fixed<ss_sint8_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_uint8_t>
    : printf_traits_fixed<ss_uint8_t>
{};

#ifdef STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_sint16_t>
    : printf_traits_fixed<ss_sint16_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_uint16_t>
    : printf_traits_fixed<ss_uint16_t>
{};
#endif // STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT

#ifdef STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_sint32_t>
    : printf_traits_fixed<ss_sint32_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_uint32_t>
    : printf_traits_fixed<ss_uint32_t>
{};
#endif // STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_sint64_t>
    : printf_traits_fixed<ss_sint64_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<ss_uint64_t>
    : printf_traits_fixed<ss_uint64_t>
{};
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<short>
    : printf_traits_fixed<int_size_traits<sizeof(short)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<unsigned short>
    : printf_traits_fixed<int_size_traits<sizeof(unsigned short)>::unsigned_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<int>
    : printf_traits_fixed<int_size_traits<sizeof(int)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<unsigned int>
    : printf_traits_fixed<int_size_traits<sizeof(unsigned int)>::unsigned_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<long>
    : printf_traits_fixed<int_size_traits<sizeof(long)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct printf_traits<unsigned long>
    : printf_traits_fixed<int_size_traits<sizeof(unsigned long)>::unsigned_type>
{};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/printf_traits_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_PRINTF_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */
