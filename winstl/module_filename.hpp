/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/module_filename.hpp (formerly winstl_module_filename.h; originally MWModFNm.h; ::SynesisWin)
 *
 * Purpose:     Preposterously simple class that gets, and makes accessible, the
 *              module filename.
 *
 * Created:     31st March 2002
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


/// \file winstl/module_filename.hpp
///
/// Preposterously simple class that gets, and makes accessible, the module filename.

#ifndef WINSTL_INCL_WINSTL_HPP_MODULE_FILENAME
#define WINSTL_INCL_WINSTL_HPP_MODULE_FILENAME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_MODULE_FILENAME_MAJOR    3
# define WINSTL_VER_WINSTL_HPP_MODULE_FILENAME_MINOR    1
# define WINSTL_VER_WINSTL_HPP_MODULE_FILENAME_REVISION 1
# define WINSTL_VER_WINSTL_HPP_MODULE_FILENAME_EDIT     54
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error winstl_module_filename.h is not compatible with Visual C++ 5.0 or earlier
#endif /* _MSC_VER < 1200 */

#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>  // filesystem_traits
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_FILE_PATH_BUFFER
# include <winstl/file_path_buffer.hpp>   // basic_file_path_buffer
#endif /* !WINSTL_INCL_WINSTL_HPP_FILE_PATH_BUFFER */

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

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_filesystem File-System Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating file-system objects

/// \weakgroup winstl_filesystem_library File-System Library (WinSTL)
/// \ingroup WinSTL libraries_filesystem
/// \brief This library provides facilities for defining and manipulating file-system objects for the Win32 API
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * basic_module_filename
 *
 * This class wraps the GetModuleFilename() API function, and effectively acts
 * as an adaptor between HINSTANCE and a C-string to the name.
 */

/// Represents a module filename
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_module_filename
{
public:
    /// The char type
    typedef C                           char_type;
    /// The traits type
    typedef T                           traits_type;
    /// The current parameterisation of the type
    typedef basic_module_filename<C, T> class_type;
    /// The size type
    typedef ws_size_t                   size_type;

// Construction
public:
    /// Default constructor - represent the filename of the current process
    basic_module_filename();
    /// Represent the filename of the given instance
    ss_explicit_k basic_module_filename(HINSTANCE hinst);

// Operations
public:
    /// Copy the module filename to the given buffer
    size_type           get_filename(ws_char_a_t *buffer, size_type cchBuffer) const;
    /// Copy the module filename to the given buffer
    size_type           get_filename(ws_char_w_t *buffer, size_type cchBuffer) const;
    /// Copy the module filename to the given buffer
    static size_type    get_filename(HINSTANCE hinst, ws_char_a_t *buffer, size_type cchBuffer);
    /// Copy the module filename to the given buffer
    static size_type    get_filename(HINSTANCE hinst, ws_char_w_t *buffer, size_type cchBuffer);

// Attributes
public:
    /// Returns a non-mutable (const) pointer to the path
    char_type const *get_filename() const;
    /// Returns the length of the converted path
    size_type       length() const;
    /// Explicit conversion to a non-mutable (const) pointer to the path
    char_type const *c_str() const;

// Conversions
public:
    /// Implicit conversion to a non-mutable (const) pointer to the path
    operator char_type const *() const
    {
        return get_filename();
    }

// Members
private:
    basic_file_path_buffer<char_type>   m_path;
    HINSTANCE const                     m_hinst;
    size_type const                     m_len;

// Not to be implemented
private:
    basic_module_filename(class_type const &);
    basic_module_filename &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_module_filename template for the ANSI character type \c char
typedef basic_module_filename<ws_char_a_t, filesystem_traits<ws_char_a_t> >     module_filename_a;
/// Instantiation of the basic_module_filename template for the Unicode character type \c wchar_t
typedef basic_module_filename<ws_char_w_t, filesystem_traits<ws_char_w_t> >     module_filename_w;
/// Instantiation of the basic_module_filename template for the Win32 character type \c TCHAR
typedef basic_module_filename<TCHAR, filesystem_traits<TCHAR> >                 module_filename;

/* //////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/module_filename_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_module_filename<C, T>::basic_module_filename()
    : m_hinst(::GetModuleHandle(NULL))
    , m_len(get_filename(&m_path[0], m_path.size()))
{
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_INTEL)
    WINSTL_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_hinst) < STLSOFT_RAW_OFFSETOF(class_type, m_len));
#endif /* compiler */
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_module_filename<C, T>::basic_module_filename(HINSTANCE hinst)
    : m_hinst(hinst)
    , m_len(get_filename(hinst, &m_path[0], m_path.size()))
{
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_INTEL)
    WINSTL_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_hinst) < STLSOFT_RAW_OFFSETOF(class_type, m_len));
#endif /* compiler */
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::size_type basic_module_filename<C, T>::get_filename(ws_char_a_t *buffer, ss_typename_type_k basic_module_filename<C, T>::size_type cchBuffer) const
{
    return static_cast<size_type>(::GetModuleFileNameA(m_hinst, buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::size_type basic_module_filename<C, T>::get_filename(ws_char_w_t *buffer, ss_typename_type_k basic_module_filename<C, T>::size_type cchBuffer) const
{
    return static_cast<size_type>(::GetModuleFileNameW(m_hinst, buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_module_filename<C, T>::size_type basic_module_filename<C, T>::get_filename(HINSTANCE hinst, ws_char_a_t *buffer, ss_typename_type_k basic_module_filename<C, T>::size_type cchBuffer)
{
    return static_cast<size_type>(::GetModuleFileNameA(hinst, buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_module_filename<C, T>::size_type basic_module_filename<C, T>::get_filename(HINSTANCE hinst, ws_char_w_t *buffer, ss_typename_type_k basic_module_filename<C, T>::size_type cchBuffer)
{
    return static_cast<size_type>(::GetModuleFileNameW(hinst, buffer, cchBuffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::char_type const *basic_module_filename<C, T>::get_filename() const
{
    return stlsoft_ns_qual(c_str_ptr)(m_path);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::size_type basic_module_filename<C, T>::length() const
{
    return m_len;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::char_type const *basic_module_filename<C, T>::c_str() const
{
    return get_filename();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * String access shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_char_a_t const *c_str_ptr_a_null(basic_module_filename<C, T> const &mfn)
{
    return mfn; // Can never be empty, so no need to cater for NULL return
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_char_w_t const *c_str_ptr_w_null(basic_module_filename<C, T> const &mfn)
{
    return mfn; // Can never be empty, so no need to cater for NULL return
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_char_a_t const *c_str_ptr_a(basic_module_filename<C, T> const &mfn)
{
    return mfn;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_char_w_t const *c_str_ptr_w(basic_module_filename<C, T> const &mfn)
{
    return mfn;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::size_type c_str_len_a(basic_module_filename<C, T> const &mfn)
{
    return mfn.length();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_filename<C, T>::size_type c_str_size(basic_module_filename<C, T> const &mfn)
{
    return mfn.length() * sizeof(ss_typename_type_k basic_module_filename<C, T>::char_type);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S &s, basic_module_filename<C, T> const &mfn)
{
    s << mfn.c_str();

    return s;
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_filesystem_library

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

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_HPP_MODULE_FILENAME */

/* ////////////////////////////////////////////////////////////////////////// */
