/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/error_desc.hpp (formerly winstl_error_desc.h)
 *
 * Purpose:     Converts a Win32 error code to a printable string.
 *
 * Created:     13th July 2003
 * Updated:     26th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/error_desc.hpp
///
/// Converts a Win32 error code to a printable string.

#ifndef WINSTL_INCL_WINSTL_HPP_ERROR_DESC
#define WINSTL_INCL_WINSTL_HPP_ERROR_DESC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_ERROR_DESC_MAJOR     3
# define WINSTL_VER_WINSTL_HPP_ERROR_DESC_MINOR     2
# define WINSTL_VER_WINSTL_HPP_ERROR_DESC_REVISION  1
# define WINSTL_VER_WINSTL_HPP_ERROR_DESC_EDIT      47
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_H_FUNCTIONS
# include <winstl/functions.h>              // for winstl::FormatMessage()
#endif /* !WINSTL_INCL_WINSTL_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>    // for load_library()
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>        // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup winstl_error_library Error Library (WinSTL)
/// \ingroup WinSTL libraries
/// \brief This library provides facilities for manipulating Win32 error information
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// String form of a Win32 error
///
/// This class
template<   ss_typename_param_k C
        ,   ss_typename_param_k T = filesystem_traits<C>
        >
class basic_error_desc
{
/// \name Types
/// @{
public:
    /// The character type
    typedef C                       char_type;
    /// The traits_type
    typedef T                       traits_type;
    /// The current parameterisation of the type
    typedef basic_error_desc<C, T>  class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructor
    ///
    /// \param error The Win32 error whose string equivalent will be searched
    /// \param modulePath The module in which the string will be searched
    ///
    /// \note If the error string is not found in the given module, the standard
    /// system libraries will be searched
    ss_explicit_k basic_error_desc(ws_dword_t error = GetLastError(), char_type const *modulePath = NULL);

    /// Constructor
    ///
    /// \param ht The COM error whose string equivalent will be searched
    /// \param modulePath The module in which the string will be searched
    ///
    /// \note If the error string is not found in the given module, the standard
    /// system libraries will be searched
    basic_error_desc(HRESULT hr, char_type const *modulePath = NULL);

    /// Constructor
    ///
    /// \param error The Win32 error whose string equivalent will be searched
    /// \param modulePaths A sequence container of paths, which will be searched
    /// incrementally for the error string
    ///
    /// \note If the error string is not found in any of the given modules, the
    /// standard system libraries will be searched
    template <ss_typename_param_k S>
    basic_error_desc(ws_dword_t error, S const &modulePaths)
        : m_message(NULL)
    {
        ss_typename_type_k S::const_iterator    b   =   modulePaths.begin();
        ss_typename_type_k S::const_iterator    e   =   modulePaths.end();

        for(; b != e && NULL == (m_message = find_message_(error, stlsoft_ns_qual(c_str_ptr)(*b))); ++b)
        {}

        if(NULL == m_message)
        {
            m_message = find_message_(error, NULL);
        }
    }
    /// Destructor
    ~basic_error_desc() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// The error description
    char_type const *get_description() const;
/// @}

// Accessors
public:
    /// The error description
    char_type const *c_str() const;
    /// The error description
    operator char_type const *() const;

// Implementation
private:
    char_type   *find_message_(ws_dword_t error, char_type const *modulePath);

// Members
private:
    char_type   *m_message;

// Not to be implemented
public:
    basic_error_desc(class_type const &);
    basic_error_desc &operator =(class_type const &);
};

/* Typedefs to commonly encountered types. */
/// Instantiation of the basic_error_desc template for the ANSI character type \c char
typedef basic_error_desc<ws_char_a_t>   error_desc_a;
/// Instantiation of the basic_error_desc template for the Unicode character type \c wchar_t
typedef basic_error_desc<ws_char_w_t>   error_desc_w;
/// Instantiation of the basic_error_desc template for the Win32 character type \c TCHAR
typedef basic_error_desc<TCHAR>         error_desc;

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_error_desc<C, T>::char_type *basic_error_desc<C, T>::find_message_(ws_dword_t error, ss_typename_type_k basic_error_desc<C, T>::char_type const *modulePath)
{
    ws_dword_t  cch         =   0;
    char_type   *message    =   NULL;

    STLSOFT_SUPPRESS_UNUSED(message);

    if(NULL != modulePath)
    {
        HINSTANCE   hinstSource =   traits_type::load_library(modulePath);

        if(NULL != hinstSource)
        {
            cch =   FormatMessage(error, hinstSource, &message);

            traits_type::free_library(hinstSource);
        }
    }
    else
    {
        cch = FormatMessage(error, NULL, &message);
    }

    if(0 == cch)
    {
        message = NULL;
    }

    return message;
}


template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::basic_error_desc(ws_dword_t error /* = ::GetLastError() */, char_type const *modulePath /* = NULL */)
    : m_message(find_message_(error, modulePath))
{
    if(NULL == m_message)
    {
        if(0 == FormatMessage(error, NULL, &m_message))
        {
            m_message = NULL;
        }
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_error_desc<C, T>::basic_error_desc(HRESULT hr, char_type const *modulePath /* = NULL */)
    : m_message(find_message_(static_cast<DWORD>(hr), modulePath))
{
    if(NULL == m_message)
    {
        if(0 == FormatMessage(static_cast<DWORD>(hr), NULL, &m_message))
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
    if(m_message != NULL)
    {
        ::LocalFree(m_message);
    }
}

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

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * String access shims
 */

#ifndef __STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

/// \brief Returns the corresponding C-string pointer of \c e
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr_null(basic_error_desc<C, T> const &e)
{
    C const *p  =   e;

    return ('\0' != *e) ? p : NULL;
}

/// \brief Returns the corresponding C-string pointer of \c e
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(basic_error_desc<C, T> const &e)
{
    return e.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c e
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(basic_error_desc<C, T> const &e)
{
    return e.c_str();
}

/// \brief Returns the corresponding C-string pointer of \c e
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *get_ptr(basic_error_desc<C, T> const &e)
{
    return e;
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S &s, basic_error_desc<C, T> const &e)
{
    s << e.get_description();

    return s;
}

#endif /* !__STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/error_desc_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_error_library

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

/* /////////////////////////////////////////////////////////////////////////////
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

using ::winstl::c_str_ptr_null;

using ::winstl::c_str_ptr;

using ::winstl::c_str_data;

using ::winstl::get_ptr;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_HPP_ERROR_DESC */

/* ////////////////////////////////////////////////////////////////////////// */
