/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/file_path_buffer.hpp (formerly unixstl_file_path_buffer.h)
 *
 * Purpose:     Contains the basic_file_path_buffer template class.
 *
 * Created:     24th May 2004
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


/// \file unixstl/file_path_buffer.hpp
///
/// Contains the basic_file_path_buffer template class.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER
#define UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_FILE_PATH_BUFFER_MAJOR     3
# define UNIXSTL_VER_UNIXSTL_HPP_FILE_PATH_BUFFER_MINOR     3
# define UNIXSTL_VER_UNIXSTL_HPP_FILE_PATH_BUFFER_REVISION  1
# define UNIXSTL_VER_UNIXSTL_HPP_FILE_PATH_BUFFER_EDIT      35
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>           // stlsoft::auto_buffer
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/allocator_selector.hpp>  // stlsoft::allocator_selector
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS
# include <unixstl/string_access.hpp>         // unixstl::c_str_ptr, etc.
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS */
#include <unistd.h>

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
/// \brief This library provides facilities for defining and manipulating file-system objects on UNIX
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class basic_file_path_buffer
/// Acts as a buffer with sufficient size for any drive on the host machine
///
/// This class is a non-template class primarily so that separate instantiations
/// are not created for each instantiation of the basic_file_path_buffer.
///
/// This class provides a simple function, which is to provide the maximum path
/// length for the host. This information is then cached due to the static nature
/// of the get_drivesvar_() method, although it can be reset by calling the
/// refresh() method on the buffer class.
///
/// \param C The character type
/// \param A The allocator type
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_file_path_buffer
{
private:
    enum
    {
#ifdef PATH_MAX
        internalBufferSize  =   1 + PATH_MAX
#else /* ? PATH_MAX */
        internalBufferSize  =   1 + 512
#endif /* PATH_MAX */
    };

    enum
    {
        indeterminateMaxPathGuess   =   2048
    };

    typedef stlsoft_ns_qual(auto_buffer)<C, A, internalBufferSize>  buffer_type;
public:
    /// The current parameterisation of the type
    typedef basic_file_path_buffer<C, A>                            class_type;
    /// The value type
    typedef ss_typename_type_k buffer_type::value_type              value_type;
    /// The reference type
    typedef value_type                                              &reference;
    /// The non-mutating (const) reference type
    typedef value_type const                                        &const_reference;
    /// The size type
    typedef ss_typename_type_k buffer_type::size_type               size_type;

// Construction
public:
    /// Default constructor
    basic_file_path_buffer()
        : m_buffer(1 + calc_path_max_())
    {}

    basic_file_path_buffer(class_type const &rhs)
        : m_buffer(rhs.size())
    {
        buffer_type::block_copy(m_buffer, rhs, rhs.size());
    }

    const basic_file_path_buffer &operator =(class_type const &rhs)
    {
        m_buffer.resize(rhs.size());
        buffer_type::block_copy(m_buffer, rhs, rhs.size());

        return *this;
    }

// Operations
public:
    void swap(class_type &rhs) stlsoft_throw_0()
    {
        m_buffer.swap(rhs.m_buffer);
    }

    us_bool_t grow(us_size_t newSize)
    {
        return m_buffer.resize(newSize);
    }

    us_bool_t grow()
    {
        return grow(2 * size());
    }

// Accessors
public:
    /// Returns a pointer to a nul-terminated string
    value_type const *c_str() const
    {
        return m_buffer.data();
    }

    /// Returns a mutable (non-const) pointer to the internal buffer
    reference operator [](size_t index)
    {
        buffer_type   &this_  =   m_buffer;

        return this_[index];
    }
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)
    /// Returns a non-mutable (const) pointer to the internal buffer
    const_reference operator [](size_t index) const
    {
        UNIXSTL_MESSAGE_ASSERT("Index out of range", !(size() < index));

        return m_buffer.data()[index];
    }
#endif /* compiler */

    /// Returns the size of the internal buffer
    size_type size() const
    {
        return m_buffer.size();
    }

// Operations
public:
    /// Causes the drives to be examined again for the next instance.
    ///
    /// \deprecated
    static void refresh() stlsoft_throw_0()
    {}

// Implementation
private:
    static us_size_t    calc_path_max_()
    {
#ifdef PATH_MAX
        return PATH_MAX;
#else /* ? PATH_MAX */
        int pathMax = ::pathconf("/", _PC_PATH_MAX);

        if(pathMax < 0)
        {
            pathMax = indeterminateMaxPathGuess;
        }
        else
        {
            ++pathMax;
        }

        return static_cast<us_size_t>(pathMax);
#endif /* PATH_MAX */
    }

// Members
private:
    buffer_type m_buffer;
};

/* Typedefs to commonly encountered types. */
/// Instantiation of the basic_file_path_buffer template for the ANSI character type \c char
typedef basic_file_path_buffer<us_char_a_t, stlsoft_ns_qual(allocator_selector)<us_char_a_t>::allocator_type>   file_path_buffer_a;
/// Instantiation of the basic_file_path_buffer template for the Unicode character type \c wchar_t
typedef basic_file_path_buffer<us_char_w_t, stlsoft_ns_qual(allocator_selector)<us_char_w_t>::allocator_type>   file_path_buffer_w;
/// Instantiation of the basic_file_path_buffer template for the ANSI character type \c char
typedef basic_file_path_buffer<us_char_a_t, stlsoft_ns_qual(allocator_selector)<us_char_a_t>::allocator_type>   file_path_buffer;

/* /////////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_file_path_buffer__
        : public unixstl_ns_qual(basic_file_path_buffer)<C, A>
    {
    private:
        typedef unixstl_ns_qual(basic_file_path_buffer)<C, A>           parent_class_type;
    public:
        typedef basic_file_path_buffer__<C, A>                          class_type;
        typedef ss_typename_type_k parent_class_type::value_type        value_type;
        typedef ss_typename_type_k parent_class_type::reference         reference;
        typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline void swap(basic_file_path_buffer<C, A> &lhs, basic_file_path_buffer<C, A> &rhs)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr_null(basic_file_path_buffer<C, A> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const *c_str_ptr(basic_file_path_buffer<C, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const *c_str_data(basic_file_path_buffer<C, A> const &b)
{
    return b.c_str();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_len(basic_file_path_buffer<C, A> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_size(basic_file_path_buffer<C, A> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline S &operator <<(S & s, basic_file_path_buffer<C, A> const &b)
{
    s << b.c_str();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/file_path_buffer_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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
#if defined(__STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k C
            ,   ss_typename_param_k A
            >
    inline void swap(unixstl_ns_qual(basic_file_path_buffer)<C, A> &lhs, unixstl_ns_qual(basic_file_path_buffer)<C, A> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* __STLSOFT_CF_std_NAMESPACE */

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

#endif /* UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER */

/* ////////////////////////////////////////////////////////////////////////// */
