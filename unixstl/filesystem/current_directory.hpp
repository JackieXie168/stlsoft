/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/current_directory.hpp (formerly unixstl/current_directory.hpp; originally unixstl_current_directory.h)
 *
 * Purpose:     Definition of the current_directory class.
 *
 * Created:     1st November 2003
 * Updated:     10th June 2006
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


/** \file unixstl/filesystem/current_directory.hpp
 *
 * \brief [C++ only] Definition of the unixstl::basic_current_directory
 *  class template.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MINOR     0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_REVISION  3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_EDIT      43
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
# include <unixstl/filesystem/file_path_buffer.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * basic_current_directory
 *
 * This class wraps the GetCurrentDirectory() API function, and effectively acts
 * as a C-string of its value.
 */

/** \brief Represents the current directory
 *
 * \ingroup group__library__file_system
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_current_directory
{
public:
    /// \brief The char type
    typedef C                               char_type;
    /// \brief The traits type
    typedef T                               traits_type;
    /// \brief The current parameterisation of the type
    typedef basic_current_directory<C, T>   class_type;
    /// \brief The size type
    typedef us_size_t                       size_type;

// Construction
public:
    /// \brief Default constructor
    basic_current_directory();

// Operations
public:
    /// \brief Gets the current directory into the given buffer
    static size_type   get_path(char_type *buffer, size_type cchBuffer);

// Attributes
public:
    /// \brief Returns a non-mutable (const) pointer to the path
    char_type const *get_path() const;
    /// \brief Returns a pointer to a nul-terminated string
    char_type const *c_str() const;
    /// \brief Returns the length of the converted path
    size_type       length() const;

// Conversions
public:
    /// \brief Implicit conversion to a non-mutable (const) pointer to the path
    operator char_type const *() const
    {
        return get_path();
    }

// Members
private:
    basic_file_path_buffer<char_type>   m_dir;
    size_type const                     m_len;

// Not to be implemented
private:
    basic_current_directory(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_current_directory template for the ANSI character type \c char
typedef basic_current_directory<us_char_a_t, filesystem_traits<us_char_a_t> >   current_directory_a;
/// Instantiation of the basic_current_directory template for the Unicode character type \c wchar_t
typedef basic_current_directory<us_char_w_t, filesystem_traits<us_char_w_t> >   current_directory_w;
/// Instantiation of the basic_current_directory template for the ANSI character type \c char
typedef basic_current_directory<char, filesystem_traits<char> >                 current_directory;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_current_directory__
        : public basic_current_directory<C, T>
    {
    private:
        typedef basic_current_directory<C, T>                           parent_class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef basic_current_directory__<C, T>                         class_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr_null(basic_current_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(basic_current_directory<C, T> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(basic_current_directory<C, T> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline us_size_t c_str_len(basic_current_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline us_size_t c_str_size(basic_current_directory<C, T> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}
#endif /* 0 */

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S & s, basic_current_directory<C, T> const &b)
{
    s << b.c_str();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/current_directory_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline basic_current_directory<C, T>::basic_current_directory()
    : m_len(get_path(&m_dir[0], m_dir.size()))
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline /* static */ ss_typename_type_k basic_current_directory<C, T>::size_type basic_current_directory<C, T>::get_path(ss_typename_type_k basic_current_directory<C, T>::char_type *buffer, ss_typename_type_k basic_current_directory<C, T>::size_type cchBuffer)
{
    return static_cast<size_type>(traits_type::get_current_directory(cchBuffer, buffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_current_directory<C, T>::char_type const *basic_current_directory<C, T>::get_path() const
{
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
    return m_dir.c_str();
#else /* ? __GNUC__ < 3 */
    return stlsoft_ns_qual(c_str_ptr)(m_dir);
#endif /* ? __GNUC__ < 3 */
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_current_directory<C, T>::char_type const *basic_current_directory<C, T>::c_str() const
{
    return get_path();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k basic_current_directory<C, T>::size_type basic_current_directory<C, T>::length() const
{
    return m_len;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */

/* ////////////////////////////////////////////////////////////////////// */
