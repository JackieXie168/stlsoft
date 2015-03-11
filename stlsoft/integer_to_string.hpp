/* /////////////////////////////////////////////////////////////////////////////
 * File:        integer_to_string.hpp (formerly stlsoft_integer_to_string.h)
 *
 * Purpose:     Number to string conversion functions.
 *
 * Created:     7th April 2002
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


/// \file stlsoft/integer_to_string.hpp
///
/// Number to string conversion functions.

#ifndef STLSOFT_INCL_STLSOFT_HPP_INTEGER_TO_STRING
#define STLSOFT_INCL_STLSOFT_HPP_INTEGER_TO_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_INTEGER_TO_STRING_MAJOR       3
# define STLSOFT_VER_STLSOFT_HPP_INTEGER_TO_STRING_MINOR       3
# define STLSOFT_VER_STLSOFT_HPP_INTEGER_TO_STRING_REVISION    2
# define STLSOFT_VER_STLSOFT_HPP_INTEGER_TO_STRING_EDIT        63
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_UNITTEST
# ifndef STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS
#  include <stlsoft/limit_traits.h>
# endif /* !STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS */
# include <stdio.h>
# include <string.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
# define STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
#endif /* __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT */

/* /////////////////////////////////////////////////////////////////////////////
 * Constants
 */

#if 0
namespace constants
{
    enum
    {
        buffer_width = 21   //!< Sufficient for sprintf()-ing 8/16/32/64 bit signed/unsigned integers
    };

} // namespace int2str
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper Functions
 */

/// Provides an indexable sequence of digit characters
template <ss_typename_param_k C>
#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
inline C const *get_digit_character(C * )
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
inline C const *get_digit_character()
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
{
    static C const  s_characters[19] =
    {
            '9'
        ,   '8'
        ,   '7'
        ,   '6'
        ,   '5'
        ,   '4'
        ,   '3'
        ,   '2'
        ,   '1'
        ,   '0'
        ,   '1'
        ,   '2'
        ,   '3'
        ,   '4'
        ,   '5'
        ,   '6'
        ,   '7'
        ,   '8'
        ,   '9'
    };
#if 0
    static C const  *s_mid  =   s_characters + 9;

    return s_mid;
#else /* ? 0 */
    return s_characters + 9;
#endif /* 0 */
}

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

/// Highly efficient conversion of unsigned integers to string
///
/// \note The function does not check that cchBuf is sufficient for conversion
/// of the particular integer type, except for a debug version
/// <code>assert()</code>. It is the programmer's responsibility to ensure that
/// the supplied buffer is large enough for the conversion. This can be done
/// with the use of the printf_traits templates.
///
/// \param buf A buffer of sufficient space within which to convert the integer
/// \param cchBuf The number of characters available in \c buf
/// \param i The integer to convert
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline C const *unsigned_integer_to_string(C *buf, ss_size_t cchBuf, I i)
{
    C   *psz    =   buf + cchBuf - 1;  // Set pointer to last character.

    *psz = 0;   // Set the terminating null character.

    do
    {
#if defined(STLSOFT_COMPILER_IS_MSVC)
        typedef I           rem_t;
#else /* ? compiler */
        typedef ss_uint_t   rem_t;
#endif /* compiler */

        rem_t   lsd = static_cast<rem_t>(i % 10);   // Determine the least significant digit.

        i = static_cast<I>(i / 10);                 // Deal with next most significant.

        --psz;                                      // Move back.

#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
        *psz = get_digit_character(static_cast<C*>(NULL))[lsd];
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
        *psz = get_digit_character<C>()[lsd];
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */

    } while(i != 0);

    STLSOFT_ASSERT(!(psz < buf));

    return psz;
}


/// Highly efficient conversion of unsigned integers to string
///
/// \note The function does not check that cchBuf is sufficient for conversion
/// of the particular integer type, except for a debug version
/// <code>assert()</code>. It is the programmer's responsibility to ensure that
/// the supplied buffer is large enough for the conversion. This can be done
/// with the use of the printf_traits templates.
///
/// \param buf A buffer of sufficient space within which to convert the integer
/// \param cchBuf The number of characters available in \c buf
/// \param i The integer to convert
/// \param cchRes Receives the number of characters written
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline C const *unsigned_integer_to_string(C *buf, ss_size_t cchBuf, I i, ss_size_t &cchRes)
{
    C const *psz    =   unsigned_integer_to_string<C, I>(buf, cchBuf, i);

    cchRes = cchBuf - (psz - (buf - 1));

    return psz;
}


/// Highly efficient conversion of signed integers to string
///
/// \note The function does not check that cchBuf is sufficient for conversion
/// of the particular integer type, except for a debug version
/// <code>assert()</code>. It is the programmer's responsibility to ensure that
/// the supplied buffer is large enough for the conversion. This can be done
/// with the use of the printf_traits templates.
///
/// \param buf A buffer of sufficient space within which to convert the integer
/// \param cchBuf The number of characters available in \c buf
/// \param i The integer to convert
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline C const *signed_integer_to_string(C *buf, ss_size_t cchBuf, I i)
{
#ifndef STLSOFT_CF_NEGATIVE_MODULUS_POSITIVE_GIVES_NEGATIVE_RESULT
// If the compiler does not evaluate -9 % 10 to equal -9, then we need to work
// with it as if an unsigned, and prepend the -ve
    C const *psz = unsigned_integer_to_string(buf, cchBuf, i);

    if(i < 0)
    {
        *const_cast<C*>(--psz) = C('-');
    }

    return psz;
#else
// Compiler evaluates -9 % 10 to equal -9, so use the full -ve algorithm. This
// is chosen because it is more efficient on most compilers than calling the
// unsigned peer and converting.

#if defined(STLSOFT_COMPILER_IS_MSVC)
    typedef I           rem_t;
#else /* ? compiler */
    typedef ss_sint_t   rem_t;
#endif /* compiler */

    C   *psz    =   buf + cchBuf - 1;  // Set pointer to last character.

    *psz = 0;   // Set the terminating null character.

    if(i < 0)
    {
        do
        {
            rem_t   lsd = static_cast<rem_t>(i % 10);   // Determine the least significant digit.

            i = static_cast<I>(i / 10);                 // Deal with next most significant.

            --psz;                                      // Move back.

#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
            *psz = get_digit_character(static_cast<C*>(NULL))[lsd];
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
            *psz = get_digit_character<C>()[lsd];
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */

        } while(i != 0);

        *(--psz) = C('-');              // Prepend the minus sign.
    }
    else
    {
        do
        {
            rem_t   lsd = static_cast<rem_t>(i % 10);   // Determine the least significant digit.

            i = static_cast<I>(i / 10);                 // Deal with next most significant.

            --psz;                                      // Move back.

#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
            *psz = get_digit_character(static_cast<C*>(NULL))[lsd];
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
            *psz = get_digit_character<C>()[lsd];
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */

        } while(i != 0);
    }

    STLSOFT_ASSERT(!(psz < buf));

    return psz;
#endif /* !STLSOFT_CF_NEGATIVE_MODULUS_POSITIVE_GIVES_NEGATIVE_RESULT */
}

/// Highly efficient conversion of signed integers to string
///
/// \note The function does not check that cchBuf is sufficient for conversion
/// of the particular integer type, except for a debug version
/// <code>assert()</code>. It is the programmer's responsibility to ensure that
/// the supplied buffer is large enough for the conversion. This can be done
/// with the use of the printf_traits templates.
///
/// \param buf A buffer of sufficient space within which to convert the integer
/// \param cchBuf The number of characters available in \c buf
/// \param i The integer to convert
/// \param cchRes Receives the number of characters written
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline C const *signed_integer_to_string(C *buf, ss_size_t cchBuf, I i, ss_size_t &cchRes)
{
    C const *psz    =   signed_integer_to_string<C, I>(buf, cchBuf, i);

    cchRes = cchBuf - (psz - (buf - 1));

    return psz;
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint8_t i)
{
    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint8_t i)
{
    return unsigned_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint16_t i)
{
    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint16_t i)
{
    return unsigned_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint32_t i)
{
    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint32_t i)
{
    return unsigned_integer_to_string(buf, cchBuf, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint64_t const &i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return signed_integer_to_string(buf, cchBuf, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint64_t const &i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return unsigned_integer_to_string(buf, cchBuf, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return unsigned_integer_to_string(buf, cchBuf, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_INT_DISTINCT_TYPE
template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, int i)
{
    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i)
{
    return unsigned_integer_to_string(buf, cchBuf, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_TYPE */


#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_sint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 5));

    return signed_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_uint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 4));

    return unsigned_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_sint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 7));

    return signed_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_uint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 6));

    return unsigned_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_sint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 12));

    return signed_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_uint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 11));

    return unsigned_integer_to_string(buf, N, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_sint64_t const &i)
{
    STLSOFT_STATIC_ASSERT(!(N < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return signed_integer_to_string(buf, N, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return signed_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], ss_uint64_t const &i)
{
    STLSOFT_STATIC_ASSERT(!(N < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return unsigned_integer_to_string(buf, N, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return unsigned_integer_to_string(buf, N, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_INT_DISTINCT_TYPE
template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], int i)
{
    return signed_integer_to_string(buf, N, i);
}

template< ss_typename_param_k C
        , ss_size_t           N
        >
inline C const *integer_to_string(C (&buf)[N], unsigned int i)
{
    return signed_integer_to_string(buf, N, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_TYPE */

#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#if 0
template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_int_t i)
{
    return signed_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint_t i)
{
    return unsigned_integer_to_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_bool_t i);

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_char_a_t i);

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_char_w_t i);
#endif /* 0 */



template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint8_t i, ss_size_t &cchRes)
{
    return signed_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint8_t i, ss_size_t &cchRes)
{
    return unsigned_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint16_t i, ss_size_t &cchRes)
{
    return signed_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint16_t i, ss_size_t &cchRes)
{
    return unsigned_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint32_t i, ss_size_t &cchRes)
{
    return signed_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint32_t i, ss_size_t &cchRes)
{
    return unsigned_integer_to_string(buf, cchBuf, i, cchRes);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_sint64_t const &i, ss_size_t &cchRes)
{
    return signed_integer_to_string(buf, cchBuf, i, cchRes);
}

template <ss_typename_param_k C>
inline C const *integer_to_string(C *buf, ss_size_t cchBuf, ss_uint64_t const &i, ss_size_t &cchRes)
{
    return unsigned_integer_to_string(buf, cchBuf, i, cchRes);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/integer_to_string_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_INTEGER_TO_STRING */

/* ////////////////////////////////////////////////////////////////////////// */
