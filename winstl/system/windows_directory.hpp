/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/windows_directory.hpp (originally winstl_windows_directory.h)
 *
 * Purpose:     Simple class that gets, and makes accessible, the windows
 *              directory.
 *
 * Created:     10th December 2002
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/system/windows_directory.hpp
 *
 * \brief [C++ only] Definition of the winstl::basic_windows_directory class
 *  template.
 *  (\ref group__library__system "System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY_MAJOR       4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY_MINOR       0
# define WINSTL_VER_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY_REVISION    1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY_EDIT        56
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

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
 * basic_windows_directory
 *
 * This class wraps the GetWindowsDirectory() API function, and effectively acts
 * as a C-string of its value.
 */

/// Represents the windows directory
///
/// \ingroup group__library__system
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_windows_directory
{
public:
    /// The char type
    typedef C                               char_type;
    /// The traits type
    typedef T                               traits_type;
    /// The current parameterisation of the type
    typedef basic_windows_directory<C, T>   class_type;
    /// The size type
    typedef ws_size_t                       size_type;

// Operations
public:
    /// Gets the windows directory into the given buffer
    static size_type   get_path(ws_char_a_t *buffer, size_type cchBuffer);
    /// Gets the windows directory into the given buffer
    static size_type   get_path(ws_char_w_t *buffer, size_type cchBuffer);

// Attributes
public:
    /// Returns a non-mutable (const) pointer to the path
    char_type const *get_path() const;
    /// Returns a pointer to a nul-terminated string
    char_type const *c_str() const;
    /// Returns the length of the converted path
    size_type       length() const;

// Conversions
public:
    /// Implicit conversion to a non-mutable (const) pointer to the path
    operator char_type const *() const
    {
        return get_path();
    }

/// \name Invariant
#ifdef STLSOFT_UNITTEST
public:
#else
private:
#endif /* STLSOFT_UNITTEST */
    ws_bool_t is_valid_() const;

// Implementation
private:
    struct Information
    {
        char_type   m_dir[_MAX_PATH];
        size_type   m_len;

        Information()
            : m_len(get_path(m_dir, STLSOFT_NUM_ELEMENTS(m_dir)))
        {}
    };

#if !defined(STLSOFT_COMPILER_IS_DMC) || \
    __DMC__ >= 0x0840
    static Information const &get_information_()
    {
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because unit-testing is single-threaded
#  pragma warning(push)
#  pragma warning(disable : 4640)
# endif /* compiler */

        static Information  s_info;

        return s_info;

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
#  pragma warning(pop)
# endif /* compiler */
    }
#else /* ? compiler */
    // Digital Mars gets an internal compiler error when the
    // preferred implementation is used, so we provide this
    // slightly less efficient implementation.
    Information m_information;
    Information const &get_information_() const
    {
        return m_information;
    }
#endif /* compiler */
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_windows_directory template for the ANSI character type \c char
typedef basic_windows_directory<ws_char_a_t, filesystem_traits<ws_char_a_t> >   windows_directory_a;
/// Instantiation of the basic_windows_directory template for the Unicode character type \c wchar_t
typedef basic_windows_directory<ws_char_w_t, filesystem_traits<ws_char_w_t> >   windows_directory_w;
/// Instantiation of the basic_windows_directory template for the Win32 character type \c TCHAR
typedef basic_windows_directory<TCHAR, filesystem_traits<TCHAR> >               windows_directory;

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/windows_directory_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_windows_directory<C, T>::size_type basic_windows_directory<C, T>::get_path(ws_char_a_t *buffer, ss_typename_type_k basic_windows_directory<C, T>::size_type cchBuffer)
{
    return static_cast<size_type>(::GetWindowsDirectoryA(buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_windows_directory<C, T>::size_type basic_windows_directory<C, T>::get_path(ws_char_w_t *buffer, ss_typename_type_k basic_windows_directory<C, T>::size_type cchBuffer)
{
    return static_cast<size_type>(::GetWindowsDirectoryW(buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_windows_directory<C, T>::char_type const *basic_windows_directory<C, T>::get_path() const
{
    return get_information_().m_dir;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_windows_directory<C, T>::char_type const *basic_windows_directory<C, T>::c_str() const
{
    return get_path();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_windows_directory<C, T>::size_type basic_windows_directory<C, T>::length() const
{
    return get_information_().m_len;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_bool_t basic_windows_directory<C, T>::is_valid_() const
{
    ws_bool_t   bValid  =   true;

    if(traits_type::str_len(*this) != length())
    {
        return false;
    }

    if(0 == length())
    {
        return false;
    }

    return bValid;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// \brief Returns the corresponding C-string pointer of the basic_windows_directory \c sd, or a null pointer
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr_null(basic_windows_directory<C, T> const &sd)
{
    return sd;
}

/// \brief Returns the corresponding C-string pointer of the basic_windows_directory \c sd
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(basic_windows_directory<C, T> const &sd)
{
    return sd.c_str();
}

/// \brief Returns the corresponding C-string pointer of the basic_windows_directory \c sd
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(basic_windows_directory<C, T> const &sd)
{
    return sd.c_str();
}

/// \brief Returns the length (in characters) of the basic_windows_directory \c sd, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_size_t c_str_len(basic_windows_directory<C, T> const &sd)
{
    return sd.length();
}

#if 0
/// \brief Returns the size (in bytes) of the basic_windows_directory \c sd, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_size_t c_str_size(basic_windows_directory<C, T> const &sd)
{
    return sd.length() * sizeof(C);
}
#endif /* 0 */

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

using ::winstl::c_str_ptr_null;

using ::winstl::c_str_ptr;

using ::winstl::c_str_data;

using ::winstl::c_str_len;

#if 0
using ::winstl::c_str_size;
#endif /* 0 */

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_SYSTEM_HPP_WINDOWS_DIRECTORY */

/* ////////////////////////////////////////////////////////////////////// */
