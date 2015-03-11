/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/module_directory.hpp (formerly winstl_module_directory.h)
 *
 * Purpose:     Simple class that gets, and makes accessible, the module's
 *              directory.
 *
 * Created:     5th June 2003
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file winstl/module_directory.hpp
///
/// Simple class that gets, and makes accessible, the module's directory.

#ifndef WINSTL_INCL_WINSTL_HPP_MODULE_DIRECTORY
#define WINSTL_INCL_WINSTL_HPP_MODULE_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_MODULE_DIRECTORY_MAJOR       3
# define WINSTL_VER_WINSTL_HPP_MODULE_DIRECTORY_MINOR       3
# define WINSTL_VER_WINSTL_HPP_MODULE_DIRECTORY_REVISION    2
# define WINSTL_VER_WINSTL_HPP_MODULE_DIRECTORY_EDIT        42
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
# error winstl_module_directory.h is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>      // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_FILE_PATH_BUFFER
# include <winstl/file_path_buffer.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_FILE_PATH_BUFFER */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
#  include <winstl/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_UNITTEST
# include <stdlib.h>                    // for malloc(), free()
#endif /* STLSOFT_UNITTEST */

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
 * basic_module_directory
 *
 * This class determines the directory of a module, and effectively acts as a
 * C-string of its value.
 */

/// \brief Represents the directory of a module
///
/// <h2>How</h2>
///
/// An instance of basic_module_directory encapsulates the directory of a given module. You instantiate it
/// from a given module handle, as follows:
///
/// [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
/// HINSTANCE                           hinst = . . .;
/// basic_module_directory<char>(hinst) mdir(hinst);
/// puts(mdir);
/// [STLSOFT-DOC:VERBATIM:end]
///
/// You can also use one of the three given typedefs:
/// \c module_directory (parameterised on TCHAR),
/// \c module_directory_a (parameterised on CHAR),
/// \c module_directory_w (parameterised on WCHAR).
///
/// <h2>Why</h2>
///
/// 1. It affords a simpler syntax. You can use temporary instances of the class, and use the <code>char_type const *</code>
/// implicit conversion, or the \c c_str() method inline
///
/// [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
/// puts(module_directory_a(hinst));
/// [STLSOFT-DOC:VERBATIM:end]
///
/// You can also use it with the IOStreams:
///
/// [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
/// cout << L"The module was loaded from the " << module_directory_w(hinst) << L" directory" << endl;
/// [STLSOFT-DOC:VERBATIM:end]
///
/// 2. It relieves you from the boilerplate coding of calling \c GetModuleFileName() and then parsing the
/// returned path to trim off the directory. All that is handled in the class.
///
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
class basic_module_directory
{
public:
    /// The char type
    typedef C                               char_type;
    /// The traits type
    typedef T                               traits_type;
    /// The current parameterisation of the type
    typedef basic_module_directory<C, T>   class_type;
    /// The size type
    typedef ws_size_t                       size_type;

// Construction
public:
    /// Default constructor
    ss_explicit_k basic_module_directory(HINSTANCE hinst = NULL);

// Operations
public:
    /// Gets the module directory into the given buffer
    static size_type   get_path(HINSTANCE hinst, ws_char_a_t *buffer, size_type cchBuffer);
    /// Gets the module directory into the given buffer
    static size_type   get_path(HINSTANCE hinst, ws_char_w_t *buffer, size_type cchBuffer);

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

// Members
private:
    basic_file_path_buffer<char_type>   m_dir;
    size_type const                     m_len;

// Not to be implemented
public:
    basic_module_directory(const class_type &);
private:
    basic_module_directory &operator =(const class_type &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_module_directory template for the ANSI character type \c char
typedef basic_module_directory<ws_char_a_t, filesystem_traits<ws_char_a_t> >     module_directory_a;
/// Instantiation of the basic_module_directory template for the Unicode character type \c wchar_t
typedef basic_module_directory<ws_char_w_t, filesystem_traits<ws_char_w_t> >     module_directory_w;
/// Instantiation of the basic_module_directory template for the Win32 character type \c TCHAR
typedef basic_module_directory<TCHAR, filesystem_traits<TCHAR> >                 module_directory;

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline module_directory get_module_directory()
{
    return module_directory();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr_null(basic_module_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(basic_module_directory<C, T> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(basic_module_directory<C, T> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_size_t c_str_len(basic_module_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ws_size_t c_str_size(basic_module_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S & s, basic_module_directory<C, T> const &b)
{
    s << b.c_str();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/module_directory_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_module_directory<C, T>::basic_module_directory(HINSTANCE hinst /* = NULL */)
    : m_len(get_path(hinst, &m_dir[0], m_dir.size()))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(0 == m_len)
    {
        throw windows_exception("could not determine module directory", ::GetLastError());
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_module_directory<C, T>::size_type basic_module_directory<C, T>::get_path(HINSTANCE hinst, ws_char_a_t *buffer, ss_typename_type_k basic_module_directory<C, T>::size_type cchBuffer)
{
    basic_file_path_buffer<ws_char_a_t> path;
    ws_dword_t                          dw  =   ::GetModuleFileNameA(hinst, &path[0], path.size());

    if(0 == dw)
    {
        path[0] = '\0';
    }
    else
    {
        basic_file_path_buffer<ws_char_a_t> directory;
        ws_char_a_t                         *filePart;

        dw = ::GetFullPathNameA(stlsoft_ns_qual(c_str_ptr)(path), directory.size(), &directory[0], &filePart);

        if(0 == dw)
        {
            path[0] = '\0';
        }
        else
        {
            *filePart = '\0';

            lstrcpynA(buffer, stlsoft_ns_qual(c_str_ptr)(directory), static_cast<int>(cchBuffer));
        }
    }

    return dw;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_module_directory<C, T>::size_type basic_module_directory<C, T>::get_path(HINSTANCE hinst, ws_char_w_t *buffer, ss_typename_type_k basic_module_directory<C, T>::size_type cchBuffer)
{
    basic_file_path_buffer<ws_char_w_t> path;
    ws_dword_t                          dw  =   ::GetModuleFileNameW(hinst, &path[0], path.size());

    if(0 == dw)
    {
        path[0] = '\0';
    }
    else
    {
        basic_file_path_buffer<ws_char_w_t> directory;
        ws_char_w_t                         *filePart;

        dw = ::GetFullPathNameW(stlsoft_ns_qual(c_str_ptr)(path), directory.size(), &directory[0], &filePart);

        if(0 == dw)
        {
            path[0] = '\0';
        }
        else
        {
            *filePart = '\0';

            lstrcpynW(buffer, stlsoft_ns_qual(c_str_ptr)(directory), static_cast<int>(cchBuffer));
        }
    }

    return dw;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_directory<C, T>::char_type const *basic_module_directory<C, T>::get_path() const
{
    return stlsoft_ns_qual(c_str_ptr)(m_dir);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_directory<C, T>::char_type const *basic_module_directory<C, T>::c_str() const
{
    return get_path();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_module_directory<C, T>::size_type basic_module_directory<C, T>::length() const
{
    return m_len;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

using ::winstl::c_str_len;

using ::winstl::c_str_size;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_HPP_MODULE_DIRECTORY */

/* ////////////////////////////////////////////////////////////////////////// */
