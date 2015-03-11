/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/error/error_desc.hpp
 *
 * Purpose:     Converts a Win32 error code to a printable string.
 *
 * Created:     13th July 2003
 * Updated:     2nd January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2007, Matthew Wilson and Synesis Software
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


/** \file winstl/error/error_desc.hpp
 *
 * \brief [C++ only] Definition of the winstl::basic_error_desc class
 *  template.
 * (\ref group__library__error "Error" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_ERROR_DESC
#define WINSTL_INCL_WINSTL_ERROR_HPP_ERROR_DESC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_ERROR_HPP_ERROR_DESC_MAJOR       4
# define WINSTL_VER_WINSTL_ERROR_HPP_ERROR_DESC_MINOR       4
# define WINSTL_VER_WINSTL_ERROR_HPP_ERROR_DESC_REVISION    1
# define WINSTL_VER_WINSTL_ERROR_HPP_ERROR_DESC_EDIT        69
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[DocumentationStatus:Ready]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS
# include <winstl/error/error_functions.h>
#endif /* !WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>    // for load_library()
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS
# include <stlsoft/string/char_alt_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS */

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
 * Classes
 */

/** \brief Utility class that loads the system string representation
 *   corresponding to a given error code.
 *
 * \ingroup group__library__error
 *
 * Consider the following example:
\code
  winstl::error_desc_a  ed1(ERROR_ACCESS_DENIED);
  winstl::error_desc_w  ed2(ERROR_ACCESS_DENIED);
  winstl::error_desc    ed3(ERROR_ACCESS_DENIED);

  assert(0 == ::strcmp("Access is denied", ed1.c_str()));
  assert(0 == ::wcscmp(L"Access is denied", ed2.c_str()));
  assert(0 == ::_tcscmp(_T("Access is denied"), ed3.c_str()));
\endcode
 *
 * By default, the strings are looked up from the Windows system DLLs. To
 * use a specific message-string DLL, simply specify this as the second
 * argument to the constructor, as in (assuming <b>MyCustomDll.DLL</b> maps
 * <code>ERROR_ACCESS_DENIED</code> to <code>"No Access!"</code>):
 *
\code
  winstl::error_desc_a  ed1(ERROR_ACCESS_DENIED, "MyCustomDll.DLL");

  assert(0 == ::strcmp("No Access!", ed1.c_str()));
\endcode
 *
 * \note Naturally, \ref group__concept__shim__string_access "String Access Shim"
 *   functions <b>c_str_ptr(_a/_w)</b>, <b>c_str_data(_a/_w)</b>, <b>c_str_len(_a/_w)</b>
 *   are defined for the class template, so it may be manipulated
 *   generically. (This is very handy when used with the
 *   <a href = "http://pantheios.org/">Pantheios</a> logging library.)
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T = system_traits<C>
        >
class basic_error_desc
{
/// \name Types
/// @{
private:
    typedef 
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
      ss_typename_type_k 
#endif /* compiler */
        stlsoft_ns_qual(char_alt_traits)<C>::alt_char_type  alt_char_type;
public:
    /// \brief The character type
    typedef C                       char_type;
    /// \brief The traits_type
    typedef T                       traits_type;
    /// \brief The current parameterisation of the type
    typedef basic_error_desc<C, T>  class_type;
    /// \brief The error type
    typedef ws_dword_t              error_type;
    /// \brief The size type
    typedef ws_size_t               size_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Loads the error string associated with the given code.
    ///
    /// \param error The Win32 error whose string equivalent will be searched
    /// \param modulePath The module in which the string will be searched
    ///
    /// \note If the error string is not found in the given module, the standard
    /// system libraries will be searched
    ss_explicit_k basic_error_desc(error_type error = GetLastError(), char_type const *modulePath = NULL);

private:
    /// This method is defined to remind users that using a different
    /// character encoding to specify the module path is not allowed
    basic_error_desc(error_type error, alt_char_type const *modulePath);
public:

    /// \brief Loads the error string associated with the given code.
    ///
    /// \param hr The COM error whose string equivalent will be searched
    /// \param modulePath The module in which the string will be searched
    ///
    /// \note If the error string is not found in the given module, the standard
    /// system libraries will be searched
    basic_error_desc(HRESULT hr, char_type const *modulePath = NULL);


private:
    /// This method is defined to remind users that using a different
    /// character encoding to specify the module path is not allowed
    basic_error_desc(HRESULT error, alt_char_type const *modulePath);
public:

    /// \brief Loads the error string associated with the given code from
    ///  the first module in the given container of paths that contains a
    ///  mapping.
    ///
    /// \param error The Win32 error whose string equivalent will be searched
    /// \param modulePaths A sequence container of paths, which will be searched
    /// incrementally for the error string
    ///
    /// \note If the error string is not found in any of the given modules, the
    /// standard system libraries will be searched
    template <ss_typename_param_k S>
    basic_error_desc(error_type error, S const &modulePaths)
        : m_length(0)
        , m_message(NULL)
    {
        ss_typename_type_k S::const_iterator    b   =   modulePaths.begin();
        ss_typename_type_k S::const_iterator    e   =   modulePaths.end();

        for(; b != e && NULL == (m_message = find_message_(error, stlsoft_ns_qual(c_str_ptr)(*b), &m_length)); ++b)
        {}

        if(NULL == m_message)
        {
            m_message = find_message_(error, NULL, &m_length);
        }
    }
    /// \brief Releases any resources.
    ~basic_error_desc() stlsoft_throw_0();

#if defined(STLSOFT_COMPILER_IS_GCC) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
    /// \brief This move constructor satisfies GCC, which misunderstands
    ///   certain expressions containing non-mutating (const) references
    ///   to instances of the type.
    ///
    /// \note Defined only for GCC compilation.
    basic_error_desc(class_type &rhs) stlsoft_throw_0();
#endif /* compiler */
/// @}

/// \name Attributes
/// @{
public:
    /// \brief The error description
    char_type const *get_description() const;
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The error description
    char_type const *c_str() const;
#if !defined(WINSTL_ERROR_DESC_NO_IMPLICIT_CONVERSION)
    /// \brief Implicit conversion operator that yields the error description
    ///
    /// \deprecated This will be removed in a future version.
    operator char_type const *() const;
#endif /* !WINSTL_ERROR_DESC_NO_IMPLICIT_CONVERSION) */
    /// \brief The length of the error description
    size_type       length() const stlsoft_throw_0();
    /// \brief The length of the error description
    size_type       size() const stlsoft_throw_0();
/// @}

/// \name Implementation
/// @{
private:
    char_type   *find_message_(error_type error, char_type const *modulePath, size_type *length);
/// @}

/// \name Members
/// @{
private:
    size_type   m_length;
    char_type   *m_message;
/// @}

/// \name Not to be implemented
/// @{
private:
#if !defined(STLSOFT_COMPILER_IS_GCC)
    basic_error_desc(class_type const &);
#endif /* compiler */
    basic_error_desc &operator =(class_type const &);
/// @}
};

/* Typedefs to commonly encountered types. */
/** \brief Specialisation of the basic_error_desc template for the ANSI character type \c char
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<ws_char_a_t>   error_desc_a;
/** \brief Specialisation of the basic_error_desc template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<ws_char_w_t>   error_desc_w;
/** \brief Specialisation of the basic_error_desc template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<TCHAR>         error_desc;

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::char_type *basic_error_desc<C, T>::find_message_(ss_typename_type_k basic_error_desc<C, T>::error_type error, ss_typename_type_k basic_error_desc<C, T>::char_type const *modulePath, ss_typename_type_k basic_error_desc<C, T>::size_type *length)
{
    WINSTL_ASSERT(NULL != length);
    WINSTL_MESSAGE_ASSERT("Constructor initialisation order error", 0 == *length);

    ws_dword_t  cch         =   0;
    char_type   *message    =   NULL;

    STLSOFT_SUPPRESS_UNUSED(message);

    if(NULL != modulePath)
    {
        HINSTANCE   hinstSource =   traits_type::load_library(modulePath);

        if(NULL != hinstSource)
        {
            cch = format_message(error, hinstSource, &message);

            traits_type::free_library(hinstSource);
        }
    }
    else
    {
        cch = format_message(error, NULL, &message);
    }

    if(0 == cch)
    {
        message = NULL;
    }

    *length = cch;

    return message;
}


template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::basic_error_desc(ss_typename_type_k basic_error_desc<C, T>::error_type error /* = ::GetLastError() */, char_type const *modulePath /* = NULL */)
    : m_length(0)
    , m_message(find_message_(error, modulePath, &m_length))
{
    if(NULL == m_message)
    {
        if(0 == format_message(error, NULL, &m_message))
        {
            m_message = NULL;
        }
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::basic_error_desc(HRESULT hr, char_type const *modulePath /* = NULL */)
    : m_length(0)
    , m_message(find_message_(static_cast<DWORD>(hr), modulePath, &m_length))
{
    if(NULL == m_message)
    {
        if(0 == format_message(static_cast<DWORD>(hr), NULL, &m_message))
        {
            m_message = NULL;
        }
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::~basic_error_desc() stlsoft_throw_0()
{
#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT
    STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_length) < STLSOFT_RAW_OFFSETOF(class_type, m_message));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */

    if(m_message != NULL)
    {
        ::LocalFree(m_message);
    }
}

#if defined(STLSOFT_COMPILER_IS_GCC)
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::basic_error_desc(ss_typename_type_k basic_error_desc<C, T>::class_type &rhs) stlsoft_throw_0()
{
    m_length        =   rhs.m_length;
    rhs.m_length    =   0;
    m_message       =   rhs.m_message;
    rhs.m_message   =   NULL;
}
#endif /* compiler */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::char_type const *basic_error_desc<C, T>::get_description() const
{
    static const char_type s_nullMessage[1] = { '\0' };

    return (NULL != m_message) ? m_message : s_nullMessage;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::char_type const *basic_error_desc<C, T>::c_str() const
{
    return get_description();
}

#if !defined(WINSTL_ERROR_DESC_NO_IMPLICIT_CONVERSION)
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
#if defined(STLSOFT_COMPILER_IS_GCC)
inline basic_error_desc<C, T>::operator C const *() const
#else /* ? compiler */
inline basic_error_desc<C, T>::operator ss_typename_type_k basic_error_desc<C, T>::char_type const *() const
#endif /* compiler */
{
    return get_description();
}
#endif /* !WINSTL_ERROR_DESC_NO_IMPLICIT_CONVERSION */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::size_type basic_error_desc<C, T>::length() const stlsoft_throw_0()
{
    return m_length;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::size_type basic_error_desc<C, T>::size() const stlsoft_throw_0()
{
    return length();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * String access shims
 */

#ifndef STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

/** \brief \ref group__concept__shim__string_access__c_str_ptr_null for winstl::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr_null(winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    C const *p  =   e;

    return ('\0' != *e) ? p : NULL;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k T>
inline ws_char_a_t const *c_str_ptr_null_a(winstl_ns_qual(basic_error_desc)<ws_char_a_t, T> const &e)
{
    ws_char_a_t const *p  =   e;

    return ('\0' != *e) ? p : NULL;
}
template <ss_typename_param_k T>
inline ws_char_w_t const *c_str_ptr_null_w(winstl_ns_qual(basic_error_desc)<ws_char_w_t, T> const &e)
{
    ws_char_w_t const *p  =   e;

    return (L'\0' != *e) ? p : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_ptr for winstl::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k T>
inline ws_char_a_t const *c_str_ptr_a(winstl_ns_qual(basic_error_desc)<ws_char_a_t, T> const &e)
{
    return e.c_str();
}
template <ss_typename_param_k T>
inline ws_char_w_t const *c_str_ptr_w(winstl_ns_qual(basic_error_desc)<ws_char_w_t, T> const &e)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_data for winstl::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k T>
inline ws_char_a_t const *c_str_data_a(winstl_ns_qual(basic_error_desc)<ws_char_a_t, T> const &e)
{
    return e.c_str();
}
template <ss_typename_param_k T>
inline ws_char_w_t const *c_str_data_w(winstl_ns_qual(basic_error_desc)<ws_char_w_t, T> const &e)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_len for winstl::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_size_t c_str_len(winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    return e.length();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<   ss_typename_param_k T
        >
inline ws_size_t c_str_len_a(winstl_ns_qual(basic_error_desc)<ws_char_a_t, T> const &e)
{
    return e.length();
}
template<   ss_typename_param_k T
        >
inline ws_size_t c_str_len_w(winstl_ns_qual(basic_error_desc)<ws_char_w_t, T> const &e)
{
    return e.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** [DEPRECATED] \ref group__concept__shim__pointer_attribute__get_ptr for winstl::basic_error_desc
 *
 * \deprecated get_ptr is for pointers and "smart pointers".
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *get_ptr(winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    return e;
}


/** \brief \ref group__concept__shim__stream_insertion "stream insertion shim" for winstl::basic_error_desc
 *
 * \ingroup group__concept__shim__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S &s, winstl_ns_qual(basic_error_desc)<C, T> const &e)
{
    s << e.get_description();

    return s;
}

#endif /* !STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/error_desc_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _WINSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

using ::winstl::get_ptr;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_ERROR_HPP_ERROR_DESC */

/* ////////////////////////////////////////////////////////////////////// */
