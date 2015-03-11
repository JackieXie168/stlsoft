/* /////////////////////////////////////////////////////////////////////////////
 * File:        limit_traits.h (formerly stlsoft_limit_traits.h, originally MLLimits.h; ::SynesisStd)
 *
 * Purpose:     limit_traits classes. Provides nothing that is not in
 *              std::numeric_limits, but uses minimum() and maximum() rather
 *              than min() and max(), since some compilers are not well-behaved
 *              in making these functions rather than macros.
 *
 * Created:     16th January 2002
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/limit_traits.h
///
/// limit_traits classes. Provides nothing that is not in std::numeric_limits, but uses minimum() and maximum() rather than min() and max(), since some compilers are not well-behaved in making these functions rather than macros.

#ifndef STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS
#define STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_H_LIMIT_TRAITS_MAJOR    3
# define STLSOFT_VER_STLSOFT_H_LIMIT_TRAITS_MINOR    1
# define STLSOFT_VER_STLSOFT_H_LIMIT_TRAITS_REVISION 1
# define STLSOFT_VER_STLSOFT_H_LIMIT_TRAITS_EDIT     40
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#if defined(__cplusplus)
# ifndef STLSOFT_INCL_STLSOFT_HPP_SIZE_TRAITS
#  include <stlsoft/size_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_SIZE_TRAITS */
#endif /* __cplusplus */

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

#define __STLSOFT_GEN_SINT8_SUFFIX(i)           (i)
#define __STLSOFT_GEN_UINT8_SUFFIX(i)           (i ## U)
#define __STLSOFT_GEN_SINT16_SUFFIX(i)          (i)
#define __STLSOFT_GEN_UINT16_SUFFIX(i)          (i ## U)
#define __STLSOFT_GEN_SINT32_SUFFIX(i)          (i ## L)
#define __STLSOFT_GEN_UINT32_SUFFIX(i)          (i ## UL)
#if (   defined(STLSOFT_COMPILER_IS_DMC) || \
        defined(STLSOFT_COMPILER_IS_COMO) || \
        defined(STLSOFT_COMPILER_IS_GCC) || \
        defined(STLSOFT_COMPILER_IS_MWERKS))
# define __STLSOFT_GEN_SINT64_SUFFIX(i)         (i ## LL)
# define __STLSOFT_GEN_UINT64_SUFFIX(i)         (i ## ULL)
#elif ( defined(STLSOFT_COMPILER_IS_BORLAND) || \
        defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_VECTORC) || \
        defined(STLSOFT_COMPILER_IS_WATCOM))
# define __STLSOFT_GEN_SINT64_SUFFIX(i)         (i ## L)
# define __STLSOFT_GEN_UINT64_SUFFIX(i)         (i ## UL)
#else
# error Compiler not discriminated
#endif /* __STLSOFT_DVS_COMPILER_GNUC || __STLSOFT_DVS_COMPILER_DECCXX */


#define   STLSOFT_LIMIT_TRAITS__SINT8_MIN     (- __STLSOFT_GEN_SINT8_SUFFIX(127) - 1)
#define   STLSOFT_LIMIT_TRAITS__SINT8_MAX     (+ __STLSOFT_GEN_SINT8_SUFFIX(127))

#define   STLSOFT_LIMIT_TRAITS__UINT8_MIN     (  __STLSOFT_GEN_UINT8_SUFFIX(0))
#define   STLSOFT_LIMIT_TRAITS__UINT8_MAX     (  __STLSOFT_GEN_UINT8_SUFFIX(255))


#define   STLSOFT_LIMIT_TRAITS__SINT16_MIN    (- __STLSOFT_GEN_SINT16_SUFFIX(32767) - 1)
#define   STLSOFT_LIMIT_TRAITS__SINT16_MAX    (+ __STLSOFT_GEN_SINT16_SUFFIX(32767))

#define   STLSOFT_LIMIT_TRAITS__UINT16_MIN    (  __STLSOFT_GEN_UINT16_SUFFIX(0))
#define   STLSOFT_LIMIT_TRAITS__UINT16_MAX    (  __STLSOFT_GEN_UINT16_SUFFIX(65535))


#define   STLSOFT_LIMIT_TRAITS__SINT32_MIN    (- __STLSOFT_GEN_SINT32_SUFFIX(2147483647) - 1)
#define   STLSOFT_LIMIT_TRAITS__SINT32_MAX    (+ __STLSOFT_GEN_SINT32_SUFFIX(2147483647))

#define   STLSOFT_LIMIT_TRAITS__UINT32_MIN    (  __STLSOFT_GEN_UINT32_SUFFIX(0))
#define   STLSOFT_LIMIT_TRAITS__UINT32_MAX    (  __STLSOFT_GEN_UINT32_SUFFIX(4294967295))


#define   STLSOFT_LIMIT_TRAITS__SINT64_MIN    (- __STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) - 1)
#define   STLSOFT_LIMIT_TRAITS__SINT64_MAX    (+ __STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) )

#define   STLSOFT_LIMIT_TRAITS__UINT64_MIN    (  __STLSOFT_GEN_UINT64_SUFFIX(0) )
#define   STLSOFT_LIMIT_TRAITS__UINT64_MAX    (  __STLSOFT_GEN_UINT64_SUFFIX(18446744073709551615) )

#define __STLSOFT_LIMIT_TRAITS__SINT8_MIN       STLSOFT_LIMIT_TRAITS__SINT8_MIN
#define __STLSOFT_LIMIT_TRAITS__SINT8_MAX       STLSOFT_LIMIT_TRAITS__SINT8_MAX

#define __STLSOFT_LIMIT_TRAITS__UINT8_MIN       STLSOFT_LIMIT_TRAITS__UINT8_MIN
#define __STLSOFT_LIMIT_TRAITS__UINT8_MAX       STLSOFT_LIMIT_TRAITS__UINT8_MAX


#define __STLSOFT_LIMIT_TRAITS__SINT16_MIN      STLSOFT_LIMIT_TRAITS__SINT16_MIN
#define __STLSOFT_LIMIT_TRAITS__SINT16_MAX      STLSOFT_LIMIT_TRAITS__SINT16_MAX

#define __STLSOFT_LIMIT_TRAITS__UINT16_MIN      STLSOFT_LIMIT_TRAITS__UINT16_MIN
#define __STLSOFT_LIMIT_TRAITS__UINT16_MAX      STLSOFT_LIMIT_TRAITS__UINT16_MAX


#define __STLSOFT_LIMIT_TRAITS__SINT32_MIN      STLSOFT_LIMIT_TRAITS__SINT32_MIN
#define __STLSOFT_LIMIT_TRAITS__SINT32_MAX      STLSOFT_LIMIT_TRAITS__SINT32_MAX

#define __STLSOFT_LIMIT_TRAITS__UINT32_MIN      STLSOFT_LIMIT_TRAITS__UINT32_MIN
#define __STLSOFT_LIMIT_TRAITS__UINT32_MAX      STLSOFT_LIMIT_TRAITS__UINT32_MAX


#define __STLSOFT_LIMIT_TRAITS__SINT64_MIN      STLSOFT_LIMIT_TRAITS__SINT64_MIN
#define __STLSOFT_LIMIT_TRAITS__SINT64_MAX      STLSOFT_LIMIT_TRAITS__SINT64_MAX

#define __STLSOFT_LIMIT_TRAITS__UINT64_MIN      STLSOFT_LIMIT_TRAITS__UINT64_MIN
#define __STLSOFT_LIMIT_TRAITS__UINT64_MAX      STLSOFT_LIMIT_TRAITS__UINT64_MAX

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef __cplusplus

# ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// Traits for determining the minimum and maximum values of types
///
/// limit_traits is a traits class for acquiring the minimum and maximum values
/// of types.
///
/// &nbsp;&nbsp;<code>limit_traits<ss_sint16_t>::minimum() == -32768</code><br>
/// &nbsp;&nbsp;<code>limit_traits<ss_sint16_t>::maximum() == 32767</code><br>
///
/// \param T The type
template <ss_typename_param_k T>
struct limit_traits
{
public:
    /// The value type
    typedef T value_type;

public:
    /// Returns the minimum value for the type
    static value_type       minimum();
    /// Returns the maximum value for the type
    static value_type       maximum();

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = ???;
    static const value_type maximum_value = ???;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

# else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

// class limit_traits

template <ss_typename_param_k T>
struct limit_traits;
template <ss_typename_param_k T>
struct limit_traits_fixed;

/* s/uint8 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint8_t>
{
public:
    typedef ss_sint8_t  value_type;

public:
    static value_type       minimum() { return __STLSOFT_LIMIT_TRAITS__SINT8_MIN; }
    static value_type       maximum() { return __STLSOFT_LIMIT_TRAITS__SINT8_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__SINT8_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__SINT8_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint8_t>
{
public:
    typedef ss_uint8_t  value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__UINT8_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__UINT8_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__UINT8_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__UINT8_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

/* s/uint16 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint16_t>
{
public:
    typedef ss_sint16_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__SINT16_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__SINT16_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__SINT16_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__SINT16_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint16_t>
{
public:
    typedef ss_uint16_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__UINT16_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__UINT16_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__UINT16_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__UINT16_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

/* s/uint32 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint32_t>
{
public:
    typedef ss_sint32_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__SINT32_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__SINT32_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__SINT32_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__SINT32_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint32_t>
{
public:
    typedef ss_uint32_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__UINT32_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__UINT32_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__UINT32_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__UINT32_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

/* s/uint64 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint64_t>
{
public:
    typedef ss_sint64_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__SINT64_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__SINT64_MAX; }

#  if defined(STLSOFT_CF_MEMBER_CONSTANT_SUPPORT) && \
      !defined(STLSOFT_COMPILER_IS_BORLAND)
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__SINT64_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__SINT64_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint64_t>
{
public:
    typedef ss_uint64_t value_type;

public:
    static value_type   minimum() { return __STLSOFT_LIMIT_TRAITS__UINT64_MIN; }
    static value_type   maximum() { return __STLSOFT_LIMIT_TRAITS__UINT64_MAX; }

#  if defined(STLSOFT_CF_MEMBER_CONSTANT_SUPPORT) && \
      !defined(STLSOFT_COMPILER_IS_BORLAND)
    static const value_type minimum_value = __STLSOFT_LIMIT_TRAITS__UINT64_MIN;
    static const value_type maximum_value = __STLSOFT_LIMIT_TRAITS__UINT64_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_sint8_t>
    : limit_traits_fixed<ss_sint8_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_uint8_t>
    : limit_traits_fixed<ss_uint8_t>
{};

#ifdef STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_sint16_t>
    : limit_traits_fixed<ss_sint16_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_uint16_t>
    : limit_traits_fixed<ss_uint16_t>
{};
#endif // STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT

#ifdef STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_sint32_t>
    : limit_traits_fixed<ss_sint32_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_uint32_t>
    : limit_traits_fixed<ss_uint32_t>
{};
#endif // STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_sint64_t>
    : limit_traits_fixed<ss_sint64_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<ss_uint64_t>
    : limit_traits_fixed<ss_uint64_t>
{};
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<short>
    : limit_traits_fixed<int_size_traits<sizeof(short)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<unsigned short>
    : limit_traits_fixed<int_size_traits<sizeof(unsigned short)>::unsigned_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<int>
    : limit_traits_fixed<int_size_traits<sizeof(int)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<unsigned int>
    : limit_traits_fixed<int_size_traits<sizeof(unsigned int)>::unsigned_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<long>
    : limit_traits_fixed<int_size_traits<sizeof(long)>::signed_type>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits<unsigned long>
    : limit_traits_fixed<int_size_traits<sizeof(unsigned long)>::unsigned_type>
{};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */
