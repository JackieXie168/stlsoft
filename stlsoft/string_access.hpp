/* /////////////////////////////////////////////////////////////////////////////
 * File:        string_access.hpp (formerly stlsoft_string_access.h)
 *
 * Purpose:     Contains the c_str_ptr, c_str_ptr_null, c_str_len, and
 *              c_str_size accessors.
 *
 * Created:     16th January 2002
 * Updated:     29th January 2006
 *
 * Thanks to:   Robert Kreger for spotting a bug in the discrimination of wide
 *              character support on GCC 3.3.3.
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


/// \file stlsoft/string_access.hpp
///
/// Contains the c_str_ptr, c_str_ptr_null, c_str_len, and c_str_size accessors.

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_STRING_ACCESS_MAJOR       3
# define STLSOFT_VER_STLSOFT_HPP_STRING_ACCESS_MINOR       2
# define STLSOFT_VER_STLSOFT_HPP_STRING_ACCESS_REVISION    3
# define STLSOFT_VER_STLSOFT_HPP_STRING_ACCESS_EDIT        73
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD
# include <stlsoft/string_access_fwd.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD */

#ifdef STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
# undef STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
#endif /* STLSOFT_CF_STRING_ACCESS_USE_std_char_traits */

/* No currently supported Watcom version can handle std::string. */
#ifdef STLSOFT_COMPILER_IS_WATCOM
# define STLSOFT_STRING_ACCESS_NO_STD_STRING
#endif /* STLSOFT_COMPILER_IS_WATCOM */

/* <string> is included for two reasons:
 *
 * (i) for std::string
 * (ii) for std::char_traits
 *
 * If STLSOFT_STRING_ACCESS_NO_STD_STRING is defined, then <string> is not
 * included, and STLSOFT_CF_STRING_ACCESS_USE_std_char_traits is not
 * defined.
 *
 * If _STLSOFT_NO_NAMESPACE is defined then
 * STLSOFT_CF_STRING_ACCESS_USE_std_char_traits is not defined.
 *
 * If __STLSOFT_CF_std_char_traits_AVAILABLE is not defined then
 * STLSOFT_CF_STRING_ACCESS_USE_std_char_traits is not defined.
 *
 */

#ifdef _STLSOFT_STRING_ACCESS_NO_STD_STRING
# define STLSOFT_STRING_ACCESS_NO_STD_STRING
#endif /* _STLSOFT_STRING_ACCESS_NO_STD_STRING */

#if defined(STLSOFT_STRING_ACCESS_NO_STD_STRING)
# undef STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
#elif defined(_STLSOFT_NO_NAMESPACE)
# undef STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
#elif !defined(__STLSOFT_CF_std_char_traits_AVAILABLE)
# undef STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
#else /* ? Use char_traits? */
# define STLSOFT_CF_STRING_ACCESS_USE_std_char_traits
#endif /* Use char_traits? */

/* Are we going to cater for std::(w)string? */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# include <string>
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* Include stlsoft_char_traits if not using std::string, or std::char_traits
 * is not available.
 */
#if !defined(STLSOFT_CF_STRING_ACCESS_USE_std_char_traits)
# ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
#  include <stlsoft/char_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */
#endif /* !STLSOFT_CF_STRING_ACCESS_USE_std_char_traits */

#if defined(STLSOFT_COMPILER_IS_GCC)
# include <wchar.h>
#endif /* STLSOFT_COMPILER_IS_GCC */

#ifdef STLSOFT_UNITTEST
# include <stdio.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Pre-processor control
 *
 * By default, conversions from non-const strings, or rather from pointers to
 * non-const characters, are not allowed, since the implied semantics for a
 * pointer-to-const character representing a null-terminated string are stronger
 * than those for a pointer-to-non-const character.
 *
 * However, you can override this by defining the symbol
 * _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST, which will then treat both the types
 * (in fact all four types: char*; char const*; wchar_t*; wchar_t const*) as
 * representing null-terminated strings.
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_string_access String Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types

/// \defgroup stlsoft_string_access_shims String Access Shims (STLSoft)
/// \ingroup STLSoft concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_GCC) && \
     (   __GNUC__ < 3 /* TODO: This is probably not needed now, so may remove it in a future version ... */ || \
         !defined(_GLIBCPP_USE_WCHAR_T)) // Thanks to Robert Kreger for suggesting this fix for GCC 3.3.3 on HP UX
  typedef stlsoft_ns_qual_std(basic_string)<ss_char_w_t>    _stlsoft_wstring_t;
# else /* ? GCC */
  typedef stlsoft_ns_qual_std(wstring)                      _stlsoft_wstring_t;
# endif /* STLSOFT_COMPILER_IS_GCC) && __GNUC__ < 3 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* C-style ANSI string */
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(ss_char_a_t const *s)
{
    return (NULL == s || '\0' == *s) ? NULL : s;
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null(ss_char_a_t const *s)
{
    return c_str_ptr_null_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null_w(ss_char_w_t const *s)
{
    return (NULL == s || L'\0' == *s) ? NULL : s;
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null(ss_char_w_t const *s)
{
    return c_str_ptr_null_w(s);
}

/* C-style ANSI string */
#ifdef _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(ss_char_a_t *s)
{
    return (NULL == s || '\0' == *s) ? NULL : s;
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null(ss_char_a_t *s)
{
    return c_str_ptr_null_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null_w(ss_char_w_t *s)
{
    return (NULL == s || L'\0' == *s) ? NULL : s;
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null(ss_char_w_t *s)
{
    return c_str_ptr_null_w(s);
}
#endif /* _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST */

/* std::basic_string */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1100
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(string const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null(string const &s)
{
    return c_str_ptr_null_a(s);
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null_w(wstring const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null(wstring const &s)
{
    return c_str_ptr_null_w(s);
}
# else /* ? compiler */
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(stlsoft_ns_qual_std(string) const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

#  if !defined(STLSOFT_COMPILER_IS_GCC) || \
      !(__GNUC__ < 3)
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null_w(_stlsoft_wstring_t const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}
#  endif /* !STLSOFT_COMPILER_IS_GCC || !(__GNUC__ < 3) */

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr_null(stlsoft_ns_qual_std(basic_string)<C, T, A> const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

# endif /* STLSOFT_COMPILER_IS_MSVC && _MSC_VER < 1100 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* stlport::basic_string */
#if defined(_STLP_USE_NAMESPACES) && \
    defined(_STLP_USE_OWN_NAMESPACE) && \
    !defined(_STLP_REDEFINE_STD) && \
    (   !defined(_STLPORT_MAJOR) || \
        _STLPORT_MAJOR < 5)
/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(stlport::string const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
inline ss_char_w_t const *c_str_ptr_null_w(stlport::wstring const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
template <class C>
inline C const *c_str_ptr_null(stlport::basic_string<C> const &s)
{
    return (0 == s.length()) ? 0 : s.c_str();
}
#endif /* _STLP_USE_NAMESPACES && _STLP_USE_OWN_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* C-style ANSI string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr_a(ss_char_a_t const *s)
{
    return (NULL != s) ? s : "";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr(ss_char_a_t const *s)
{
    return c_str_ptr_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr_w(ss_char_w_t const *s)
{
    return (NULL != s) ? s : L"";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr(ss_char_w_t const *s)
{
    return c_str_ptr_w(s);
}

/* C-style ANSI string */
#ifdef _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr_a(ss_char_a_t *s)
{
    return (NULL != s) ? s : "";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr(ss_char_a_t *s)
{
    return c_str_ptr_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr_w(ss_char_w_t *s)
{
    return (NULL != s) ? s : L"";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr(ss_char_w_t *s)
{
    return c_str_ptr_w(s);
}
#endif /* _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST */

/* std::basic_string */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1100
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr_a(string const &s)
{
    return s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr(string const &s)
{
    return c_str_ptr_a(s);
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr_w(wstring const &s)
{
    return s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr(wstring const &s)
{
    return c_str_ptr_w(s);
}
# else /* ? compiler */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr_a(stlsoft_ns_qual_std(string) const &s)
{
    return s.c_str();
}

#  if !defined(STLSOFT_COMPILER_IS_GCC) || \
      !(__GNUC__ < 3)
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr_w(_stlsoft_wstring_t const &s)
{
    return s.c_str();
}
#  endif /* !STLSOFT_COMPILER_IS_GCC || !(__GNUC__ < 3) */

/// \brief Returns the corresponding C-string pointer of \c s
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr(stlsoft_ns_qual_std(basic_string)<C, T, A> const &s)
{
    return s.c_str();
}
# endif /* STLSOFT_COMPILER_IS_MSVC && _MSC_VER < 1100 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* stlport::basic_string */
#if defined(_STLP_USE_NAMESPACES) && \
    defined(_STLP_USE_OWN_NAMESPACE) && \
    !defined(_STLP_REDEFINE_STD) && \
    (   !defined(_STLPORT_MAJOR) || \
        _STLPORT_MAJOR < 5)
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_ptr_a(stlport::string const &s)
{
    return s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_ptr_w(stlport::wstring const &s)
{
    return s.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c s
template <class C>
inline C const *c_str_ptr(stlport::basic_string<C> const &s)
{
    return s.c_str();
}
#endif /* _STLP_USE_NAMESPACES && _STLP_USE_OWN_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* C-style ANSI string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data_a(ss_char_a_t const *s)
{
    return (NULL != s) ? s : "";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data(ss_char_a_t const *s)
{
    return c_str_data_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data_w(ss_char_w_t const *s)
{
    return (NULL != s) ? s : L"";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data(ss_char_w_t const *s)
{
    return c_str_data_w(s);
}

/* C-style ANSI string */
#ifdef _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data_a(ss_char_a_t *s)
{
    return (NULL != s) ? s : "";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data(ss_char_a_t *s)
{
    return c_str_data_a(s);
}

/* C-style Unicode string */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data_w(ss_char_w_t *s)
{
    return (NULL != s) ? s : L"";
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data(ss_char_w_t *s)
{
    return c_str_data_w(s);
}
#endif /* _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST */

/* std::basic_string */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1100
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data_a(string const &s)
{
    return s.data();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data(string const &s)
{
    return c_str_data_a(s);
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data_w(wstring const &s)
{
    return s.data();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data(wstring const &s)
{
    return c_str_data_w(s);
}
# else /* ? compiler */
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data_a(stlsoft_ns_qual_std(string) const &s)
{
    return s.data();
}

#  if !defined(STLSOFT_COMPILER_IS_GCC) || \
      !(__GNUC__ < 3)
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data_w(_stlsoft_wstring_t const &s)
{
    return s.data();
}
#  endif /* !STLSOFT_COMPILER_IS_GCC || !(__GNUC__ < 3) */

/// \brief Returns the corresponding C-string pointer of \c s
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_data(stlsoft_ns_qual_std(basic_string)<C, T, A> const &s)
{
    return s.data();
}
# endif /* STLSOFT_COMPILER_IS_MSVC && _MSC_VER < 1100 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* stlport::basic_string */
#if defined(_STLP_USE_NAMESPACES) && \
    defined(_STLP_USE_OWN_NAMESPACE) && \
    !defined(_STLP_REDEFINE_STD) && \
    (   !defined(_STLPORT_MAJOR) || \
        _STLPORT_MAJOR < 5)
/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_a_t const *c_str_data_a(stlport::string const &s)
{
    return s.data();
}

/// \brief Returns the corresponding C-string pointer of \c s
inline ss_char_w_t const *c_str_data_w(stlport::wstring const &s)
{
    return s.data();
}

/// \brief Returns the corresponding C-string pointer of \c s
template <class C>
inline C const *c_str_data(stlport::basic_string<C> const &s)
{
    return s.data();
}
#endif /* _STLP_USE_NAMESPACES && _STLP_USE_OWN_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* C-style ANSI string */
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(ss_char_a_t const *s)
{
#if !defined(STLSOFT_CF_STRING_ACCESS_USE_std_char_traits)
    return (s == 0) ? 0 : stlsoft_char_traits<ss_char_a_t>::length(s);
#else /* ? STLSOFT_CF_STRING_ACCESS_USE_std_char_traits */
    return (s == 0) ? 0 : stlsoft_ns_qual_std(char_traits)<ss_char_a_t>::length(s);
#endif /* !__STLSOFT_CF_std_char_traits_AVAILABLE */
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(ss_char_a_t const *s)
{
    return c_str_len_a(s);
}

/* C-style Unicode string */
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_w(ss_char_w_t const *s)
{
#if defined(STLSOFT_COMPILER_IS_GCC)
    return (s == 0) ? 0 : wcslen(s);
#elif !defined(STLSOFT_CF_STRING_ACCESS_USE_std_char_traits)
    return (s == 0) ? 0 : stlsoft_char_traits<ss_char_w_t>::length(s);
#else /* ? STLSOFT_CF_STRING_ACCESS_USE_std_char_traits */
    return (s == 0) ? 0 : stlsoft_ns_qual_std(char_traits)<ss_char_w_t>::length(s);
#endif /* !STLSOFT_CF_STRING_ACCESS_USE_std_char_traits */
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(ss_char_w_t const *s)
{
    return c_str_len_w(s);
}

/* C-style ANSI string */
#ifdef _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(ss_char_a_t *s)
{
    return c_str_len_a(static_cast<ss_char_a_t const *>(s));
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(ss_char_a_t *s)
{
    return c_str_len_a(s);
}

/* C-style Unicode string */
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_w(ss_char_w_t *s)
{
    return c_str_len_w(static_cast<ss_char_w_t const *>(s));
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(ss_char_w_t *s)
{
    return c_str_len_w(s);
}
#endif /* _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST */

/* std::basic_string */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1100
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(string const &s)
{
    return s.length();
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(string const &s)
{
    return c_str_len_a(s);
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_w(wstring const &s)
{
    return s.length();
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(wstring const &s)
{
    return c_str_len_w(s);
}
# else /* ? compiler */
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(stlsoft_ns_qual_std(string) const &s)
{
    return s.length();
}

#  if !defined(STLSOFT_COMPILER_IS_GCC) || \
      !(__GNUC__ < 3)
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_w(_stlsoft_wstring_t const &s)
{
    return s.length();
}
#  endif /* !STLSOFT_COMPILER_IS_GCC || !(__GNUC__ < 3) */

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_size_t c_str_len(stlsoft_ns_qual_std(basic_string)<C, T, A> const &s)
{
    return s.length();
}
# endif /* STLSOFT_COMPILER_IS_MSVC && _MSC_VER < 1100 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* stlport::basic_string */
#if defined(_STLP_USE_NAMESPACES) && \
    defined(_STLP_USE_OWN_NAMESPACE) && \
    !defined(_STLP_REDEFINE_STD) && \
    (   !defined(_STLPORT_MAJOR) || \
        _STLPORT_MAJOR < 5)
/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(stlport::string const &s)
{
    return s.length();
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_w(stlport::wstring const &s)
{
    return s.length();
}

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
template <class C>
inline ss_size_t c_str_len(stlport::basic_string<C> const &s)
{
    return s.length();
}
#endif /* _STLP_USE_NAMESPACES && _STLP_USE_OWN_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_size
 *
 * This can be applied to an expression, and the return value is the number of
 * bytes required to store the character string in the expression, NOT including
 * the null-terminating character.
 */

/* C-style ANSI string */
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_a(ss_char_a_t const *s)
{
    return c_str_len(s) * sizeof(ss_char_a_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(ss_char_a_t const *s)
{
    return c_str_size_a(s);
}

/* C-style Unicode string */
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_w(ss_char_w_t const *s)
{
    return c_str_len(s) * sizeof(ss_char_w_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(ss_char_w_t const *s)
{
    return c_str_size_w(s);
}

/* C-style ANSI string */
#ifdef _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_a(ss_char_a_t *s)
{
    return c_str_len(s) * sizeof(ss_char_a_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(ss_char_a_t *s)
{
    return c_str_size_a(s);
}

/* C-style Unicode string */
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_w(ss_char_w_t *s)
{
    return c_str_len(s) * sizeof(ss_char_w_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(ss_char_w_t *s)
{
    return c_str_size_w(s);
}
#endif /* _STLSOFT_STRING_ACCESS_ALLOW_NON_CONST */

/* std::basic_string */
#ifndef STLSOFT_STRING_ACCESS_NO_STD_STRING
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1100
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_a(string const &s)
{
    return c_str_len(s) * sizeof(string::value_type);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(string const &s)
{
    return c_str_size_a(s);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_w(wstring const &s)
{
    return c_str_len(s) * sizeof(wstring::value_type);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(wstring const &s)
{
    return c_str_size_w(s);
}
# else /* ? compiler */
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_a(stlsoft_ns_qual_std(string) const &s)
{
    return c_str_len(s) * sizeof(ss_char_a_t);
}

#  if !defined(STLSOFT_COMPILER_IS_GCC) || \
      !(__GNUC__ < 3)
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_w(_stlsoft_wstring_t const &s)
{
    return c_str_len(s) * sizeof(ss_char_w_t);
}
#  endif /* !STLSOFT_COMPILER_IS_GCC || !(__GNUC__ < 3) */

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_size_t c_str_size(stlsoft_ns_qual_std(basic_string)<C, T, A> const &s)
{
    return c_str_len(s) * sizeof(C);
}
# endif /* STLSOFT_COMPILER_IS_MSVC && _MSC_VER < 1100 */
#endif /* STLSOFT_STRING_ACCESS_NO_STD_STRING */

/* stlport::basic_string */
/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
#if defined(_STLP_USE_NAMESPACES) && \
    defined(_STLP_USE_OWN_NAMESPACE) && \
    !defined(_STLP_REDEFINE_STD) && \
    (   !defined(_STLPORT_MAJOR) || \
        _STLPORT_MAJOR < 5)
inline ss_size_t c_str_size_a(stlport::string const &s)
{
    return c_str_len(s) * sizeof(ss_char_a_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_w(stlport::wstring const &s)
{
    return c_str_len(s) * sizeof(ss_char_w_t);
}

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
template <class C>
inline ss_size_t c_str_size(stlport::basic_string<C> const &s)
{
    return c_str_len(s) * sizeof(C);
}
#endif /* _STLP_USE_NAMESPACES && _STLP_USE_OWN_NAMESPACE */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_string_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
