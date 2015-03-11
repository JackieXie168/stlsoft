/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/absolute_path.hpp (formerly winstl_absolute_path.h)
 *
 * Purpose:     Simple class that converts a relative path to an absolute one.
 *
 * Created:     20th December 2002
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


/** \file winstl/filesystem/absolute_path.hpp
 *
 * \brief [C++ only] Definition of the winstl::basic_absolute_path class template.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH_MAJOR       4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH_REVISION    1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH_EDIT        54
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
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
# include <winstl/filesystem/file_path_buffer.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>      // for string access shims
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
 * basic_absolute_path
 *
 * This class converts a relative path to an absolute one, and effectively acts
 * as a C-string of its value.
 */

/** \brief Converts a relative path to an absolute path
 *
 * \ingroup group__library__file_system
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template
 *  arguments, this defaults to filesystem_traits<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_absolute_path
{
/// \name Member Types
/// @{
public:
    /// \brief The char type
    typedef C                           char_type;
    /// \brief The traits type
    typedef T                           traits_type;
    /// \brief The current parameterisation of the type
    typedef basic_absolute_path<C, T>   class_type;
    /// \brief The size type
    typedef ws_size_t                   size_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs an absolute path from \c path
    ss_explicit_k basic_absolute_path(char_type const *path)
        : m_len(traits_type::get_full_path_name(path, m_path.size(), &m_path[0]))
    {}
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// \brief Constructs an absolute path from \c path
    template<ss_typename_param_k S>
    ss_explicit_k basic_absolute_path(S const &path)
        : m_len(traits_type::get_full_path_name(stlsoft_ns_qual(c_str_ptr)(path), stlsoft_ns_qual(c_str_len)(m_path), &m_path[0]))
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
/// @}

/// \name Conversions
/// @{
public:
    /// \brief Implicit conversion to a non-mutable (const) pointer to the path
    operator char_type const *() const
    {
        return stlsoft_ns_qual(c_str_ptr)(m_path);
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns the length of the converted path
    size_type length() const
    {
        return m_len;
    }
/// @}

/// \name Members
/// @{
private:
    basic_file_path_buffer<char_type>   m_path;
    size_type const                     m_len;
/// @}

/// \name Not to be implemented
/// @{
private:
    basic_absolute_path(class_type const &);
    class_type &operator =(class_type const &);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// \brief Instantiation of the basic_absolute_path template for the ANSI character type \c char
typedef basic_absolute_path<ws_char_a_t, filesystem_traits<ws_char_a_t> >       absolute_path_a;
/// \brief Instantiation of the basic_absolute_path template for the Unicode character type \c wchar_t
typedef basic_absolute_path<ws_char_w_t, filesystem_traits<ws_char_w_t> >       absolute_path_w;
/// \brief Instantiation of the basic_absolute_path template for the Win32 character type \c TCHAR
typedef basic_absolute_path<TCHAR, filesystem_traits<TCHAR> >                   absolute_path;

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1100

/** \brief This \ref group__pattern__creator_function "creator function"
 *   makes an absolute path variable without needing to qualify the template
 *   parameter.
 */
template<ss_typename_param_k C>
inline basic_absolute_path<C> make_absolute_path(C const *path)
{
    return basic_absolute_path<C>(path);
}

#endif /* compiler */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/absolute_path_unittest_.h"
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH */

/* ////////////////////////////////////////////////////////////////////// */
