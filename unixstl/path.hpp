/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/path.hpp (formerly unixstl_path.h; originally MLPath.h, ::SynesisStd)
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     24th May 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1993-2006, Matthew Wilson and Synesis Software
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


/// \file unixstl/path.hpp
///
/// Simple class that represents a path

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_PATH
#define UNIXSTL_INCL_UNIXSTL_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_PATH_MAJOR     5
# define UNIXSTL_VER_UNIXSTL_HPP_PATH_MINOR     8
# define UNIXSTL_VER_UNIXSTL_HPP_PATH_REVISION  1
# define UNIXSTL_VER_UNIXSTL_HPP_PATH_EDIT      196
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER
# include <unixstl/file_path_buffer.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS
# include <unixstl/string_access.hpp>           // for string access shims
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#include <stdexcept>                            // for std::logic_error
#ifdef WIN32
# include <ctype.h>
#endif /* WIN32 */

/* /////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_filesystem File-System Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating file-system objects

/// \weakgroup unixstl_filesystem_library File-System Library (UNIXSTL)
/// \ingroup UNIXSTL libraries_filesystem
/// \brief This library provides facilities for defining and manipulating file-system objects for UNIX
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * basic_path
 *
 * This class represents a path, and effectively acts as a C-string of its value.
 */

/// \brief Represents a path
///
/// \param C The character type
/// \param T The traits type. Defaults to filesystem_traits<C>. On translators that do not support default template arguments, it must be explicitly stipulated
/// \param A The allocator class. Defaults to stlsoft::allocator_selector<C>::allocator_type. On translators that do not support default template arguments, it must be explicitly stipulated
///
/// \note This class derives from the Synesis Software class Path, but has been influenced
/// by other, later, ideas. The idea of using the / operator for path concatenation was
/// sparked by the Boost implementation (although the details were not investigated prior
/// to this implementation, so the two may have significant semantic differences). This
/// has been added without requiring any major fundamental changes to the original
/// <code>push/pop</code>-based interface
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
        ,   ss_typename_param_k A = ss_typename_type_def_k stlsoft_ns_qual(allocator_selector)<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k stlsoft_ns_qual(allocator_selector)<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_path
{
/// \name Types
/// @{
public:
    /// The char type
    typedef C                           char_type;
    /// The traits type
    typedef T                           traits_type;
    /// The allocator type
    typedef A                           allocator_type;
    /// The current parameterisation of the type
    typedef basic_path<C, T, A>         class_type;
    /// The size type
    typedef us_size_t                   size_type;

// TODO: Use the slice string, and provide iterators over the directory parts

/// @}

/// \name Construction
/// @{
public:
    /// Constructs an empty path
    basic_path();
    /// Constructs a path from \c path
    ss_explicit_k basic_path(char_type const *path);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Constructs a path from \c path
    template<ss_typename_param_k S>
    ss_explicit_k basic_path(S const &s)
    {
        traits_type::str_copy(&m_buffer[0], stlsoft_ns_qual(c_str_ptr)(s));

        m_len = stlsoft_ns_qual(c_str_len)(s);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// Constructs a path from \c cch characters in \c path
    basic_path(char_type const *path, size_type cch);

    /// \brief Copies the contents of \c rhs
    basic_path(class_type const &rhs);

    /// \brief Copies the contents of \c rhs
    class_type &operator =(class_type const &rhs);
    /// \brief Copies the contents of \c rhs
    class_type &operator =(char_type const *rhs);

    // Creates a root path
    static class_type root(char_type const *s);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    // Creates a root path
    template<ss_typename_param_k S>
    static class_type root(S const &s)
    {
        return root(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
/// @}

/// \name Operations
/// @{
public:
    /// Appends the contents of \rhs to the path
    class_type &push(class_type const &rhs, us_bool_t bAddPathNameSeparator = false);
    /// Appends the contents of \rhs to the path
    class_type &push(char_type const *rhs, us_bool_t bAddPathNameSeparator = false);
    /// Appends the contents of \rhs to the path as an extension
    class_type &push_ext(class_type const &rhs, us_bool_t bAddPathNameSeparator = false);
    /// Appends the contents of \rhs to the path as an extension
    class_type &push_ext(char_type const *rhs, us_bool_t bAddPathNameSeparator = false);
    /// Ensures that the path has a trailing path name separator
    class_type &push_sep();
    /// Pops the last path element from the path
    ///
    /// \note If the path has 0 or 1 components, this operation does nothing
    class_type &pop();
    /// Ensures that the path does not have a trailing path name separator
    class_type &pop_sep();

    /// Equivalent to push()
    class_type &operator /=(char_type const *rhs);

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED)
    /// Equivalent to push()
    class_type &operator /=(class_type const &rhs);
#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    /// Equivalent to push()
    template <ss_typename_param_k S>
    class_type &operator /=(S const &rhs)
    {
        return operator /=(stlsoft_ns_qual(c_str_ptr)(rhs));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// Converts the path to absolute form
    class_type &make_absolute(us_bool_t bRemoveTrailingPathNameSeparator = true);
    /// Canonicalises the path, removing all "./" parts and evaluating all "../" parts
    class_type &canonicalise(us_bool_t bRemoveTrailingPathNameSeparator = true);
/// @}

/// \name Attributes
/// @{
public:
    /// Returns a pointer to the part of the path after the last path name separator
    ///
    /// \note If the path represents a directory, the name of the directory will be returned, except
    /// if the path is terminated by the path name separator
    ///
    /// \note If the path contains no path name separator, the full path will be returned
    char_type const *get_file() const;
    /// Returns a pointer to the extension, or to the empty string if there is no extension
    char_type const *get_ext() const;
    /// Returns the length of the converted path
    size_type       length() const;
    /// Conversion to a non-mutable (const) pointer to the path
    char_type const *c_str() const;
    /// Indicates whether the path represents an existing file system entry
    us_bool_t       exists() const;
    /// Indicates whether the path is rooted
    us_bool_t       is_rooted() const;
    /// Indicates whether the path is absolute
    us_bool_t       is_absolute() const;
/// @}

/// \name Comparison
/// @{
public:
    us_bool_t equivalent(char_type const *rhs) const;
    us_bool_t equivalent(class_type const &rhs) const;

    us_bool_t equal(char_type const *rhs) const;
    us_bool_t equal(class_type const &rhs) const;
/// @}

/// \name Iteration
/// @{
public:
#if 0
    directory_iterator  dir_begin() const;
    directory_iterator  dir_end() const;
#endif /* 0 */
/// @}

// Implementation
private:
    void                    swap(class_type &rhs);
    class_type              &concat_(char_type const *rhs);
    class_type              &concat_(class_type const &rhs);

    static char_type const  *next_slash_or_end(char_type const *p);
    static char_type        path_name_separator_alt();

// Members
private:
    typedef basic_file_path_buffer< char_type
                                ,   allocator_type
                                >                   buffer_type;

    struct part
    {
        enum Type
        {
                normal
            ,   dot
            ,   dotdot
        };

        size_type       len;
        char_type const *p;
        Type            type;
    };

    buffer_type m_buffer;
    size_type   m_len;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_path template for the ANSI character type \c char
typedef basic_path<us_char_a_t, filesystem_traits<us_char_a_t> >       path_a;
/// Instantiation of the basic_path template for the Unicode character type \c wchar_t
typedef basic_path<us_char_w_t, filesystem_traits<us_char_w_t> >       path_w;
/// Instantiation of the basic_path template for the ANSI character type \c char
typedef basic_path<us_char_a_t, filesystem_traits<us_char_a_t> >       path;

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator ==(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator !=(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return !lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator ==(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return rhs.equal(lhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator !=(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return !rhs.equal(lhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator ==(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t operator !=(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return !lhs.equal(rhs);
}

// operator /

/// Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/// Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/// Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1100

/// This helper function makes a path variable without needing to
/// qualify the template parameter.
template<ss_typename_param_k C>
inline basic_path<C> make_path(C const *path)
{
    return basic_path<C>(path);
}

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline void swap(basic_path<C, T, A> &lhs, basic_path<C, T, A> &rhs)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr_null(basic_path<C, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr(basic_path<C, T, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_data(basic_path<C, T, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_len(basic_path<C, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_size(basic_path<C, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline S &operator <<(S & s, basic_path<C, T, A> const &b)
{
    s << b.c_str();

    return s;
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/path_unittest_.h"
#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1300
#  pragma warning(push)
#  pragma warning(disable : 4702)
# endif /* compiler*/

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_param_k basic_path<C, T, A>::char_type const *basic_path<C, T, A>::next_slash_or_end(ss_typename_param_k basic_path<C, T, A>::char_type const *p)
{
    for(; ; ++p)
    {
        switch(*p)
        {
            case    '/':
#ifdef WIN32
            case    '\\':
#endif /* WIN32 */
                ++p;
            case    '\0':
                return p;
            default:
                break;
        }
    }

    return NULL;
}

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1300
#  pragma warning(pop)
# endif /* compiler*/


template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_param_k basic_path<C, T, A>::char_type basic_path<C, T, A>::path_name_separator_alt()
{
    return '\\';
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline void basic_path<C, T, A>::swap(basic_path<C, T, A> &rhs)
{
    m_buffer.swap(rhs.m_buffer);
    std::swap(m_len, rhs.m_len);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_param_k basic_path<C, T, A>::class_type &basic_path<C, T, A>::concat_(ss_typename_param_k basic_path<C, T, A>::char_type const *rhs)
{
    m_len = traits_type::str_len(traits_type::str_cat(&m_buffer[0], rhs));

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_param_k basic_path<C, T, A>::class_type &basic_path<C, T, A>::concat_(basic_path<C, T, A> const &rhs)
{
    m_len = traits_type::str_len(traits_type::str_cat(&m_buffer[0], rhs.c_str()));

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A>::basic_path()
    : m_len(0)
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* ss_explicit_k */ basic_path<C, T, A>::basic_path(ss_typename_type_k basic_path<C, T, A>::char_type const *path)
    : m_len(0)
{
    if(NULL != path)
    {
        size_type   cch =   traits_type::str_len(path);

        UNIXSTL_ASSERT(cch < m_buffer.size());

        traits_type::str_copy(&m_buffer[0], path);

        m_len = cch;
    }
    else
    {
        m_buffer[0] = '\0';
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A>::basic_path( ss_typename_type_k basic_path<C, T, A>::char_type const *path
                                    ,   ss_typename_type_k basic_path<C, T, A>::size_type       cch)
    : m_len(cch)
{
    UNIXSTL_ASSERT((NULL != path) || (0 == cch));

    if(0 != cch)
    {
        UNIXSTL_ASSERT(cch < m_buffer.size());

        traits_type::str_n_copy(&m_buffer[0], path, cch);
    }
    m_buffer[cch] = '\0';
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A>::basic_path(basic_path<C, T, A> const &rhs)
    : m_len(rhs.m_len)
{
    traits_type::str_copy(&m_buffer[0], stlsoft_ns_qual(c_str_ptr)(rhs.m_buffer));
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::operator =(basic_path<C, T, A> const &path)
{
    class_type  newPath(path);

    swap(newPath);

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::operator =(ss_typename_type_k basic_path<C, T, A>::char_type const *path)
{
    class_type  newPath(path);

    swap(newPath);

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_type_k basic_path<C, T, A>::class_type basic_path<C, T, A>::root(ss_typename_type_k basic_path<C, T, A>::char_type const *s)
{
    return class_type(s);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push(class_type const &rhs, us_bool_t bAddPathNameSeparator /* = false */)
{
    return push(rhs.c_str(), bAddPathNameSeparator);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push(char_type const *rhs, us_bool_t bAddPathNameSeparator /* = false */)
{
    class_type  newPath(*this);

    newPath.push_sep();
    newPath.concat_(rhs);
    if(bAddPathNameSeparator)
    {
        newPath.push_sep();
    }

    swap(newPath);

    return *this;
}

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push_ext(class_type const &rhs, us_bool_t bAddPathNameSeparator /* = false */)
{
}
#endif /* 0 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push_ext(char_type const *rhs, us_bool_t bAddPathNameSeparator /* = false */)
{
    UNIXSTL_ASSERT(NULL != rhs);

    class_type  newPath(*this);

    newPath.pop_sep();
    if('.' != *rhs)
    {
        newPath.concat_(".");
    }
    newPath.concat_(rhs);
    if(bAddPathNameSeparator)
    {
        newPath.push_sep();
    }

    swap(newPath);

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push_sep()
{
    if(0 != m_len)
    {
        if(traits_type::path_name_separator() != m_buffer[m_len - 1])
        {
#ifdef WIN32
            if(path_name_separator_alt() != m_buffer[m_len - 1])
#endif /* WIN32 */
            {
                UNIXSTL_ASSERT(m_len + 1 < m_buffer.size());

                m_buffer[m_len]     =   traits_type::path_name_separator();
                m_buffer[m_len + 1] =   '\0';
                ++m_len;
            }
        }
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::pop()
{
    char_type   *slash      =   traits_type::str_rchr(stlsoft_ns_qual(c_str_ptr)(m_buffer), traits_type::path_name_separator());
#ifdef WIN32
    char_type   *slash_a    =   traits_type::str_rchr(stlsoft_ns_qual(c_str_ptr)(m_buffer), path_name_separator_alt());

    if(slash_a > slash)
    {
        slash = slash_a;
    }
#endif /* WIN32 */

    if(NULL != slash)
    {
        *(slash + 1) = '\0';
        m_len = (slash + 1) - stlsoft_ns_qual(c_str_ptr)(m_buffer);
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::pop_sep()
{
    if(0 != m_len)
    {
        char_type *last = &m_buffer[m_len - 1];

        if(*last == traits_type::path_name_separator())
        {
            m_buffer[m_len-- - 1] = '\0';
        }
#ifdef WIN32
        else if(*last == path_name_separator_alt())
        {
            m_buffer[m_len-- - 1] = '\0';
        }
#endif /* WIN32 */
    }

    return *this;
}


#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED)

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::operator /=(basic_path<C, T, A> const &path)
{
    return push(path);
}

#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::operator /=(ss_typename_type_k basic_path<C, T, A>::char_type const *path)
{
    return push(path);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::make_absolute(us_bool_t bRemoveTrailingPathNameSeparator /* = true */)
{
    buffer_type buffer;
    size_type   cch = traits_type::get_full_path_name(c_str(), buffer.size(), &buffer[0]);
    class_type  newPath(stlsoft_ns_qual(c_str_ptr)(buffer), cch);

    if(bRemoveTrailingPathNameSeparator)
    {
        newPath.pop_sep();
    }

    swap(newPath);

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::canonicalise(us_bool_t bRemoveTrailingPathNameSeparator /* = true */)
{
    class_type  newPath(*this);

#ifdef _DEBUG
    memset(&newPath.m_buffer[0], '~', newPath.m_buffer.size());
#endif /* _DEBUG */

    // Basically we scan through the path looking for ./ .\ ..\ and ../
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    typedef ss_typename_type_k A::ss_template_qual_k rebind<part>::other    part_ator_type;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    typedef ss_typename_type_k allocator_selector<part>::allocator_type     part_ator_type;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    typedef stlsoft_ns_qual(auto_buffer_old)<   part
                                            ,   part_ator_type
                                            >                               part_buffer_t;

    part_buffer_t   parts(this->length() / 2);  // Uncanonicalised directory parts
    char_type       *dest   =   &newPath.m_buffer[0];
    char_type const *p1     =   this->c_str();
    char_type const *p2;

    if(this->is_absolute())
    {
#ifdef WIN32
        if(traits_type::is_path_UNC(this->c_str()))
        {
            UNIXSTL_ASSERT('\\' == m_buffer[0]);
            UNIXSTL_ASSERT('\\' == m_buffer[1]);
            UNIXSTL_ASSERT('\\' != m_buffer[2]);

            char_type const *slash0 =   next_slash_or_end(&m_buffer[3]);
            char_type const *slash1 =   next_slash_or_end(slash0);

            for(us_size_t i = 0, n = slash1 - &m_buffer[0]; i < n; ++i)
            {
                *dest++ = *p1++;
            }
        }
        else if( isalpha(m_buffer[0]) &&
            ':' == m_buffer[1])
        {
            // Copy over the drive letter, colon and slash
            *dest++ = *p1++;
            *dest++ = *p1++;
            *dest++ = *p1++;
        }
        else
#endif /* WIN32 */
        {
            *dest++ = traits_type::path_name_separator();
            ++p1;
        }
    }

    // 1. Parse the path into an uncanonicalised sequence of directory parts
    {
        size_type   i   =   0;

        for(; '\0' != *p1; ++i)
        {
            p2 = next_slash_or_end(p1);

            parts[i].len    =   p2 - p1;
            parts[i].p      =   p1;
            parts[i].type   =   part::normal;
            switch(parts[i].len)
            {
                case    1:
                    if('.' == p1[0])
                    {
                        parts[i].type   =   part::dot;
                    }
                    break;
                case    2:
                    if('.' == p1[0])
                    {
                        if('.' == p1[1])
                        {
                            parts[i].type   =   part::dotdot;
                        }
                        else if(traits_type::path_name_separator() == p1[1])
                        {
                            parts[i].type   =   part::dot;
                        }
#ifdef WIN32
                        else if(path_name_separator_alt() == p1[1])
                        {
                            parts[i].type   =   part::dot;
                        }
#endif /* WIN32 */
                    }
                    break;
                case    3:
                    if( '.' == p1[0] &&
                        '.' == p1[1])
                    {
                        if(traits_type::path_name_separator() == p1[2])
                        {
                            parts[i].type   =   part::dotdot;
                        }
#ifdef WIN32
                        else if(path_name_separator_alt() == p1[2])
                        {
                            parts[i].type   =   part::dotdot;
                        }
#endif /* WIN32 */
                    }
                    break;
                default:
                    break;
            }

            p1 = p2;
        }

        parts.resize(i);
    }

    // 2. Process the parts into a canonicalised sequence
    {
        size_type   i   =   0;

        for(i = 0; i < parts.size(); ++i)
        {
            switch(parts[i].type)
            {
                case    part::dot:
                    parts[i].len = 0;
                    break;
                case    part::dotdot:
                    // Now need to track back and find a prior normal element
                    {
                        size_type   prior;

                        for(prior = i; ; )
                        {
                            if(0 == prior)
                            {
                                throw std::logic_error("No prior part to \"..\" for path canonicalisation");
                            }
                            else
                            {
                                --prior;

                                if( part::normal == parts[prior].type &&
                                    0 != parts[prior].len)
                                {
                                    parts[i].len = 0;
                                    parts[prior].len = 0;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

    // 3. Write out all the parts back into the new path instance
    {
        size_type   i   =   0;

#ifdef _DEBUG
        memset(dest, '~', newPath.m_buffer.size() - (dest - &newPath.m_buffer[0]));
#endif /* _DEBUG */

        for(i = 0; i < parts.size(); ++i)
        {
            traits_type::str_n_copy(dest, parts[i].p, parts[i].len);

            dest += parts[i].len;
        }

        *dest = '\0';
        newPath.m_len = dest - newPath.c_str();
    }

    if(bRemoveTrailingPathNameSeparator)
    {
        newPath.pop_sep();
    }

    swap(newPath);

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_path<C, T, A>::char_type const *basic_path<C, T, A>::get_file() const
{
    char_type const *slash      =   traits_type::str_rchr(stlsoft_ns_qual(c_str_ptr)(m_buffer), traits_type::path_name_separator());
    char_type const *slash_a    =   traits_type::str_rchr(stlsoft_ns_qual(c_str_ptr)(m_buffer), path_name_separator_alt());

    if(slash_a > slash)
    {
        slash = slash_a;
    }

    if(NULL == slash)
    {
        slash = stlsoft_ns_qual(c_str_ptr)(m_buffer);
    }
    else
    {
        ++slash;
    }

    return slash;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_path<C, T, A>::char_type const *basic_path<C, T, A>::get_ext() const
{
    char_type const         *dot    =   traits_type::str_rchr(this->c_str(), '.');
    char_type const         *file   =   get_file();
    static const char_type  s_empty[1]  =   { '\0' };

    if(NULL == dot)
    {
        return s_empty;
    }
    else if(dot < file)
    {
        return s_empty;
    }
    else
    {
        return dot + 1;
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_path<C, T, A>::size_type basic_path<C, T, A>::length() const
{
    return m_len;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_path<C, T, A>::char_type const *basic_path<C, T, A>::c_str() const
{
    return stlsoft_ns_qual(c_str_ptr)(m_buffer);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::exists() const
{
    return traits_type::file_exists(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::is_rooted() const
{
    return traits_type::is_path_rooted(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::is_absolute() const
{
    return traits_type::is_path_absolute(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::equivalent(basic_path<C, T, A> const &rhs) const
{
    return equivalent(rhs.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::equivalent(ss_typename_type_k basic_path<C, T, A>::char_type const *rhs) const
{
    class_type  lhs_(*this);
    class_type  rhs_(rhs);

    return lhs_.make_absolute(false).canonicalise(true) == rhs_.make_absolute(false).canonicalise(true);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::equal(basic_path<C, T, A> const &rhs) const
{
    return equal(rhs.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline us_bool_t basic_path<C, T, A>::equal(ss_typename_type_k basic_path<C, T, A>::char_type const *rhs) const
{
    return 0 == traits_type::str_compare(stlsoft_ns_qual(c_str_ptr)(m_buffer), stlsoft_ns_qual(c_str_ptr)(rhs));
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group unixstl_filesystem_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k C
            ,   ss_typename_param_k T
            ,   ss_typename_param_k A
            >
    inline void swap(unixstl_ns_qual(basic_path)<C, T, A> &lhs, unixstl_ns_qual(basic_path)<C, T, A> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::unixstl::c_str_ptr_null;

using ::unixstl::c_str_ptr;

using ::unixstl::c_str_data;

using ::unixstl::c_str_len;

using ::unixstl::c_str_size;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_HPP_PATH */

/* ////////////////////////////////////////////////////////////////////////// */
