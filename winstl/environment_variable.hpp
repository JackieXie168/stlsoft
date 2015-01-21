/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/environment_variable.hpp (formerly winstl_environment_variable.h)
 *
 * Purpose:     Simple class that provides access to an environment variable.
 *
 * Created:     20th December 2002
 * Updated:     22nd December 2005
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


/// \file winstl/environment_variable.hpp
///
/// Simple class that provides access to an environment variable.

#ifndef WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_VARIABLE
#define WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_VARIABLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_VARIABLE_MAJOR       3
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_VARIABLE_MINOR       1
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_VARIABLE_REVISION    2
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_VARIABLE_EDIT        44
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

#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>      // for get_environment_variable()
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>          // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */

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

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing system attributes

/// \defgroup winstl_system_library System Library (WinSTL)
/// \ingroup WinSTL libraries_system
/// \brief This library provides facilities for accessing Win32 system attributes
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * basic_environment_variable
 *
 * This class converts a relative path to an absolute one, and effectively acts
 * as a C-string of its value.
 */

/// Represents an environment variable
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_environment_variable
{
public:
    /// The char type
    typedef C                                   char_type;
    /// The traits type
    typedef T                                   traits_type;
    /// The allocator type
    typedef processheap_allocator<C>            allocator_type;
    /// The current parameterisation of the type
    typedef basic_environment_variable<C, T>    class_type;
    /// The size type
    typedef ws_size_t                           size_type;
    /// The difference type
    typedef ws_ptrdiff_t                        difference_type;

// Construction
public:
    /// Create an instance representing the given environment variable
    ss_explicit_k basic_environment_variable(char_type const *name)
        : m_buffer(1 + traits_type::get_environment_variable(name, 0, 0))
    {
        if( 0 == traits_type::get_environment_variable(name, &m_buffer[0], m_buffer.size()) &&
            0 != m_buffer.size())
        {
            m_buffer[0] = 0;
        }
        else
        {
            // This is necessary because GetEnvironmentVariable() does not do what
            // it's documented to do
            m_buffer.resize(1 + traits_type::str_len(m_buffer.data()));
        }
    }
#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Create an instance representing the given environment variable
    template<ss_typename_param_k S>
    ss_explicit_k basic_environment_variable(S const &name)
        : m_buffer(1 + traits_type::get_environment_variable(stlsoft_ns_qual(c_str_ptr)(name), 0, 0))
    {
        if( 0 == traits_type::get_environment_variable(stlsoft_ns_qual(c_str_ptr)(name), &m_buffer[0], m_buffer.size()) &&
            0 != m_buffer.size())
        {
            m_buffer[0] = 0;
        }
        else
        {
            // This is necessary because GetEnvironmentVariable() does not do what
            // it's documented to do
            m_buffer.resize(1 + traits_type::str_len(m_buffer.data()));
        }
    }
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

// Conversions
public:
    /// Implicit conversion to a non-mutable (const) pointer to the variable
    operator char_type const *() const
    {
        return m_buffer.data();
    }

    /// Returns a pointer to a nul-terminated string
    char_type const *c_str() const
    {
        return m_buffer.data();
    }

// Attributes
public:
    /// Returns the length of the variable
    size_type length() const
    {
        return m_buffer.size() - 1;
    }

// Members
private:
    typedef stlsoft_ns_qual(auto_buffer)<   char_type
                                        ,   allocator_type
                                        >       buffer_type_;

    buffer_type_    m_buffer;

// Not to be implemented
private:
    basic_environment_variable(basic_environment_variable const &);
    basic_environment_variable &operator =(basic_environment_variable const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_environment_variable template for the ANSI character type \c char
typedef basic_environment_variable<ws_char_a_t, filesystem_traits<ws_char_a_t> >    environment_variable_a;
/// Instantiation of the basic_environment_variable template for the Unicode character type \c wchar_t
typedef basic_environment_variable<ws_char_w_t, filesystem_traits<ws_char_w_t> >    environment_variable_w;
/// Instantiation of the basic_environment_variable template for the Win32 character type \c TCHAR
typedef basic_environment_variable<TCHAR, filesystem_traits<TCHAR> >                environment_variable;

/* /////////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1100

/// This helper function makes an environment variable without needing to
/// qualify the template parameter.
template<ss_typename_param_k C>
inline basic_environment_variable<C> make_environment_variable(C const *path)
{
    return basic_environment_variable<C>(path);
}

#endif /* !(_MSC_VER < 1100) */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/environment_variable_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_VARIABLE */

/* ////////////////////////////////////////////////////////////////////////// */
