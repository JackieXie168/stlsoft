/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path.hpp (formerly winstl_path.h; originally MLPath.h, ::SynesisStd)
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/filesystem/path.hpp
 *
 * \brief [C++ only] Definition of the winstl::basic_path class template.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MAJOR    6
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MINOR    1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_REVISION 2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_EDIT     214
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
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/allocator_features.hpp>   // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>            // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER */
#include <stdexcept>                            // for std::logic_error

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
 * basic_path
 *
 * This class represents a path, and effectively acts as a C-string of its value.
 */

/** \brief Class used for composing and decomposing file-system paths.
 *
 * \ingroup group__library__file_system
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
 * \param A The allocator type. On translators that support default template arguments, this defaults to processheap_allocator<C>
 *
 * \note This class derives from the Synesis Software class Path, but has been influenced
 * by other, later, ideas. The idea of using the / operator for path concatenation was
 * sparked by the Boost implementation (although the details were not investigated prior
 * to this implementation, so the two may have significant semantic differences). This
 * has been added without requiring any major fundamental changes to the original
 * <code>push/pop</code>-based interface
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
        ,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
        ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_path
{
/// \name Types
/// @{
public:
    /// \brief The char type
    typedef C                           char_type;
    /// \brief The traits type
    typedef T                           traits_type;
    /// \brief The allocator type
    typedef A                           allocator_type;
    /// \brief The current parameterisation of the type
    typedef basic_path<C, T, A>         class_type;
    /// \brief The size type
    typedef ws_size_t                   size_type;
    /// \brief The Boolean type
    typedef ws_bool_t                   bool_type;

// TODO: Use the slice string, and provide iterators over the directory parts

/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs an empty path.
    ///
    /// \htmlonly
    /// <pre>
    /// winstl::path  p;
    ///
    /// assert(0 == p.size());
    /// assert("" == p);
    /// </pre>
    /// \endhtmlonly
    basic_path();
    /// \brief Constructs a path from a nul-terminated character string.
    ///
    /// \htmlonly
    /// <pre>
    /// winstl::path  p("C:\\Windows");
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// </pre>
    /// \endhtmlonly
    ss_explicit_k basic_path(char_type const *path);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// \brief Constructs a path from a string object.
    ///
    /// \remarks The string object may be any type for which the 
    ///  <b>c_str_len</b> and <b>c_str_data</b> 
    ///  \ref group__concept__string_access_shims "String Access Shims" are
    ///  defined. The following example shows the use of a window handle
    ///  (HWND). Other types supported are <code>std::exception</code>,
    ///  <code>std::string</code>, <code>stlsoft::simple_string</code>,
    ///  <code>winstl::error_desc</code>, and many more
    ///
    /// \htmlonly
    /// <pre>
    /// HWND          hwndParent = . . . 
    /// HWND          hwnd       = winstl::CreateEdit(hwndParent, "C:\\Windows", ES_LEFT, 0, 0, 10, 10, 1001);
    /// winstl::path  p(hwnd);
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// </pre>
    /// \endhtmlonly
    template<ss_typename_param_k S>
    ss_explicit_k basic_path(S const &s)
    {
        m_len = stlsoft_ns_qual(c_str_len)(s);

        traits_type::str_n_copy(&m_buffer[0], stlsoft_ns_qual(c_str_data)(s), m_len);
        m_buffer[m_len] = '\0';
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// \brief Constructs a path from a slice of a character string.
    ///
    /// \htmlonly
    /// <pre>
    /// winstl::path  p("C:\\Windows\\system32", 10);
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// </pre>
    /// \endhtmlonly
    basic_path(char_type const *path, size_type cch);

#ifndef STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD
    /// \brief Copies the contents of \c rhs
    basic_path(class_type const &rhs);
#endif /* !STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD */

#ifndef STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD
    /// \brief Copies the contents of \c rhs
    class_type &operator =(class_type const &rhs);
#endif /* !STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD */
    /// \brief Copies the contents of \c rhs
    class_type &operator =(char_type const *rhs);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// \brief Copies the contents of \c s
    template<ss_typename_param_k S>
    class_type &operator =(S const &s)
    {
        return operator =(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

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
    /// \brief Appends the contents of \c rhs to the path
    class_type &push(class_type const &rhs, bool_type bAddPathNameSeparator = false);
    /// \brief Appends the contents of \c rhs to the path
    class_type &push(char_type const *rhs, bool_type bAddPathNameSeparator = false);
    /// \brief Appends the contents of \c rhs to the path as an extension
    class_type &push_ext(class_type const &rhs, bool_type bAddPathNameSeparator = false);
    /// \brief Appends the contents of \c rhs to the path as an extension
    class_type &push_ext(char_type const *rhs, bool_type bAddPathNameSeparator = false);
    /// \brief Ensures that the path has a trailing path name separator
    class_type &push_sep();
    /// \brief Pops the last path element from the path
    ///
    /// \note If the path has 0 or 1 components, this operation does nothing
    class_type &pop(bool_type bRemoveTrailingPathNameSeparator = false);
    /// \brief Ensures that the path does not have a trailing path name separator
    class_type &pop_sep();
    /// \brief Removes the extension, if any, from the file component of the path
    class_type &pop_ext();

    /// \brief Equivalent to push()
    class_type &operator /=(char_type const *rhs);

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED)
    /// \brief Equivalent to push()
    class_type &operator /=(class_type const &rhs);
#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    /// \brief Equivalent to push()
    template <ss_typename_param_k S>
    class_type &operator /=(S const &rhs)
    {
        return operator /=(stlsoft_ns_qual(c_str_ptr)(rhs));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// \brief Converts the path to absolute form
    class_type &make_absolute(bool_type bRemoveTrailingPathNameSeparator = true);
    /// \brief Canonicalises the path, removing all "./" parts and evaluating all "../" parts
    class_type &canonicalise(bool_type bRemoveTrailingPathNameSeparator = true);
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns a pointer to the part of the path after the last path name separator
    ///
    /// \note If the path represents a directory, the name of the directory will be returned, except
    /// if the path is terminated by the path name separator
    ///
    /// \note If the path contains no path name separator, the full path will be returned
    char_type const *get_file() const;
    /// \brief Returns a pointer to the extension, or to the empty string if there is no extension
    char_type const *get_ext() const;
    /// \brief Returns the length of the converted path
    size_type       length() const;
    /// \brief Returns the length of the converted path
    ///
    /// \remarks Equivalent to length()
    size_type       size() const;
    /// \brief Conversion to a non-mutable (const) pointer to the path
    char_type const *c_str() const;
    /// \brief Indicates whether the path represents an existing file system entry
    bool_type       exists() const;
    /// \brief Indicates whether the path is rooted
    bool_type       is_rooted() const;
    /// \brief Indicates whether the path is absolute
    bool_type       is_absolute() const;
/// @}

/// \name Comparison
/// @{
public:
    /// \brief Determines whether the instance holds a string that refers to
    ///  the same file-system entity as the given string.
    ///
    /// \htmlonly
    /// <pre>
    /// winstl::path  p("C:\\Windows\\system32\\..");
    /// 
    /// assert(p != "C:\\WINDOWS\\");
    /// assert(!p.equal("C:\\WINDOWS\\"));
    /// assert(p.equivalent("C:\\WINDOWS\\"));
    /// </pre>
    /// \endhtmlonly
    bool_type equivalent(char_type const *rhs) const;

    /// \brief Evaluates whether the two instances hold strings that refer
    ///  to the same file-system entity.
    ///
    /// \remarks See \link winstl::basic_path::equivalent(char_type const *) equivalent()\endlink for an example.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equivalent(class_type const &rhs) const;

    /// \brief Evaluates whether the instance holds an identical string.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equal(char_type const *rhs) const;
    /// \brief Evaluates whether the two instances hold identical strings.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equal(class_type const &rhs) const;
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

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_path template for the ANSI character type \c char
typedef basic_path<ws_char_a_t, filesystem_traits<ws_char_a_t> >       path_a;
/// Instantiation of the basic_path template for the Unicode character type \c wchar_t
typedef basic_path<ws_char_w_t, filesystem_traits<ws_char_w_t> >       path_w;
/// Instantiation of the basic_path template for the Win32 character type \c TCHAR
typedef basic_path<TCHAR, filesystem_traits<TCHAR> >                   path;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<   ss_typename_param_k C
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = filesystem_traits<C>
            ,   ss_typename_param_k A = processheap_allocator<C>
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = filesystem_traits<C> */
            ,   ss_typename_param_k A /* = processheap_allocator<C> */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_path__
        : public winstl_ns_qual(basic_path)<C, T, A>
    {
    private:
        typedef winstl_ns_qual(basic_path)<C, T, A>                     parent_class_type;
        typedef winstl_ns_qual(basic_path__)<C, T, A>                   class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        basic_path__()
            : parent_class_type()
        {}
        ss_explicit_k basic_path__(char_type const *path)
            : parent_class_type(path)
        {}
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        /// Constructs a path from \c path
        template<ss_typename_param_k S>
        ss_explicit_k basic_path__(S const &s)
            : parent_class_type(s)
        {}
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
        basic_path__(char_type const *path, size_type cch)
            : parent_class_type(path, cch)
        {}
        basic_path__(class_type const &rhs)
            : parent_class_type(rhs)
        {}

        class_type &operator =(class_type const &rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type &operator =(char_type const *rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        template<ss_typename_param_k S>
        class_type &operator =(S const &s)
        {
            parent_class_type::operator =(s);

            return *this;
        }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator ==(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator !=(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return !lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator ==(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return rhs.equal(lhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator !=(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return !rhs.equal(lhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator ==(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t operator !=(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return !lhs.equal(rhs);
}

// operator /

/// \brief Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(basic_path<C, T, A> const &lhs, ss_typename_type_k basic_path<C, T, A>::char_type const *rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/// \brief Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(ss_typename_type_k basic_path<C, T, A>::char_type const *lhs, basic_path<C, T, A> const &rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/// \brief Concatenates \c rhs to the path \c lhs
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> operator /(basic_path<C, T, A> const &lhs, basic_path<C, T, A> const &rhs)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
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

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_a_t const *c_str_ptr_null_a(basic_path<ws_char_a_t, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null_a)(b.c_str());
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_w_t const *c_str_ptr_null_w(basic_path<ws_char_w_t, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null_w)(b.c_str());
}



template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr(basic_path<C, T, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_a_t const *c_str_ptr_a(basic_path<ws_char_a_t, T, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_w_t const *c_str_ptr_w(basic_path<ws_char_w_t, T, A> const &b)
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

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_a_t const *c_str_data_a(basic_path<ws_char_a_t, T, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_char_w_t const *c_str_data_w(basic_path<ws_char_w_t, T, A> const &b)
{
    return b.c_str();
}




template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_size_t c_str_len(basic_path<C, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_size_t c_str_size(basic_path<C, T, A> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}
#endif /* 0 */

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

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/path_unittest_.h"
#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_param_k basic_path<C, T, A>::char_type const *basic_path<C, T, A>::next_slash_or_end(ss_typename_param_k basic_path<C, T, A>::char_type const *p)
{
    for(; ; )
    {
        switch(*p)
        {
            case    '/':
            case    '\\':
                ++p;
            case    '\0':
                return p;
            default:
                ++p;
                break;
        }
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_param_k basic_path<C, T, A>::char_type basic_path<C, T, A>::path_name_separator_alt()
{
    return '/';
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
{
    m_buffer[0] = '\0';
}

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

        WINSTL_ASSERT(cch < m_buffer.size());

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
inline basic_path<C, T, A>::basic_path(ss_typename_type_k basic_path<C, T, A>::char_type const *path, ss_typename_type_k basic_path<C, T, A>::size_type cch)
    : m_len(cch)
{
    WINSTL_ASSERT((NULL != path) || (0 == cch));

    if(0 != cch)
    {
        WINSTL_ASSERT(cch < m_buffer.size());

        traits_type::str_n_copy(&m_buffer[0], path, cch);
    }
    m_buffer[cch] = '\0';
}

#ifndef STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A>::basic_path(basic_path<C, T, A> const &rhs)
    : m_len(rhs.m_len)
{
    traits_type::str_copy(&m_buffer[0], stlsoft_ns_qual(c_str_ptr)(rhs.m_buffer));
}
#endif /* !STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD */

#ifndef STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD
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
#endif /* !STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD */

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
inline basic_path<C, T, A> &basic_path<C, T, A>::push(class_type const &rhs, ws_bool_t bAddPathNameSeparator /* = false */)
{
    return push(rhs.c_str(), bAddPathNameSeparator);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push(char_type const *rhs, ws_bool_t bAddPathNameSeparator /* = false */)
{
    WINSTL_ASSERT(NULL != rhs);

    if(traits_type::is_path_rooted(rhs))
    {
        class_type  newPath(rhs);

        swap(newPath);
    }
    else
    {
        class_type  newPath(*this);

        newPath.push_sep();
        newPath.concat_(rhs);
        if(bAddPathNameSeparator)
        {
            newPath.push_sep();
        }

        swap(newPath);
    }

    return *this;
}

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push_ext(class_type const &rhs, ws_bool_t bAddPathNameSeparator /* = false */)
{
}
#endif /* 0 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::push_ext(char_type const *rhs, ws_bool_t bAddPathNameSeparator /* = false */)
{
    WINSTL_ASSERT(NULL != rhs);

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
            if(path_name_separator_alt() != m_buffer[m_len - 1])
            {
                WINSTL_ASSERT(m_len + 1 < m_buffer.size());

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
inline basic_path<C, T, A> &basic_path<C, T, A>::pop(ws_bool_t bRemoveTrailingPathNameSeparator /* = true */)
{
    char_type   *slash      =   traits_type::str_rchr(c_str_ptr(m_buffer), traits_type::path_name_separator());
    char_type   *slash_a    =   traits_type::str_rchr(c_str_ptr(m_buffer), path_name_separator_alt());

    if(slash_a > slash)
    {
        slash = slash_a;
    }

    if(NULL != slash)
    {
        *(slash + 1) = '\0';
        m_len = (slash + 1) - stlsoft_ns_qual(c_str_ptr)(m_buffer);
    }

    if(bRemoveTrailingPathNameSeparator)
    {
        this->pop_sep();
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
        else if(*last == path_name_separator_alt())
        {
            m_buffer[m_len-- - 1] = '\0';
        }
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_path<C, T, A> &basic_path<C, T, A>::pop_ext()
{
    { for(size_t len = m_len; 0 != len; --len)
    {
        char_type   *last = &m_buffer[len - 1];

        if(traits_type::is_path_name_separator(*last))
        {
            break;
        }
        else if('.' == *last)
        {
            m_len = len - 1;

            m_buffer[m_len] = '\0';

            break;
        }
    }}

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
inline basic_path<C, T, A> &basic_path<C, T, A>::make_absolute(ws_bool_t bRemoveTrailingPathNameSeparator /* = true */)
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
inline basic_path<C, T, A> &basic_path<C, T, A>::canonicalise(ws_bool_t bRemoveTrailingPathNameSeparator /* = true */)
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

    if(traits_type::is_path_UNC(this->c_str()))
    {
        WINSTL_ASSERT('\\' == m_buffer[0]);
        WINSTL_ASSERT('\\' == m_buffer[1]);
        WINSTL_ASSERT('\\' != m_buffer[2]);

        char_type const *slash0 =   next_slash_or_end(&m_buffer[3]);
        char_type const *slash1 =   next_slash_or_end(slash0);

        for(ws_size_t i = 0, n = static_cast<ws_size_t>(slash1 - &m_buffer[0]); i < n; ++i)
        {
            *dest++ = *p1++;
        }
    }
    else if(this->is_absolute())
    {
        // Copy over the drive letter, colon and slash
        *dest++ = *p1++;
        *dest++ = *p1++;
        *dest++ = *p1++;
    }
    else if(this->is_rooted())
    {
        *dest++ = traits_type::path_name_separator();
        ++p1;
    }

    // 1. Parse the path into an uncanonicalised sequence of directory parts
    {
        size_type   i   =   0;

        for(; '\0' != *p1; ++i)
        {
            p2 = next_slash_or_end(p1);

            parts[i].len    =   static_cast<size_type>(p2 - p1);
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
                        else if(path_name_separator_alt() == p1[1])
                        {
                            parts[i].type   =   part::dot;
                        }
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
                        else if(path_name_separator_alt() == p1[2])
                        {
                            parts[i].type   =   part::dotdot;
                        }
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
        for(size_type i = 0; i < parts.size(); ++i)
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
                case    part::normal:
                default:
                    break;
            }
        }
    }

    // 3. Write out all the parts back into the new path instance
    {
#ifdef _DEBUG
        memset(dest, '~', newPath.m_buffer.size() - (dest - &newPath.m_buffer[0]));
#endif /* _DEBUG */

        for(size_type i = 0; i < parts.size(); ++i)
        {
            traits_type::str_n_copy(dest, parts[i].p, parts[i].len);

            dest += parts[i].len;
        }

        *dest = '\0';
        newPath.m_len = static_cast<size_type>(dest - newPath.c_str());
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
    char_type const *slash      =   traits_type::str_rchr(c_str_ptr(m_buffer), traits_type::path_name_separator());
    char_type const *slash_a    =   traits_type::str_rchr(c_str_ptr(m_buffer), path_name_separator_alt());

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
inline ss_typename_type_k basic_path<C, T, A>::size_type basic_path<C, T, A>::size() const
{
    return length();
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
inline ws_bool_t basic_path<C, T, A>::exists() const
{
    return traits_type::file_exists(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::is_rooted() const
{
    return traits_type::is_path_rooted(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::is_absolute() const
{
    return traits_type::is_path_absolute(this->c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::equivalent(basic_path<C, T, A> const &rhs) const
{
    return equivalent(rhs.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::equivalent(ss_typename_type_k basic_path<C, T, A>::char_type const *rhs) const
{
    class_type  lhs_(*this);
    class_type  rhs_(rhs);

    return lhs_.make_absolute(false).canonicalise(true) == rhs_.make_absolute(false).canonicalise(true);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::equal(basic_path<C, T, A> const &rhs) const
{
    return equal(rhs.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_path<C, T, A>::equal(ss_typename_type_k basic_path<C, T, A>::char_type const *rhs) const
{
    return 0 == traits_type::str_compare_no_case(stlsoft_ns_qual(c_str_ptr)(m_buffer), stlsoft_ns_qual(c_str_ptr)(rhs));
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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
    inline void swap(winstl_ns_qual(basic_path)<C, T, A> &lhs, winstl_ns_qual(basic_path)<C, T, A> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

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
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

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

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */

/* ////////////////////////////////////////////////////////////////////// */
