/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/file_path_buffer.hpp (formerly unixstl_file_path_buffer.h)
 *
 * Purpose:     Contains the basic_file_path_buffer template class.
 *
 * Created:     24th May 2004
 * Updated:     6th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/** \file unixstl/filesystem/file_path_buffer.hpp
 *
 * \brief [C++ only] Definition of the unixstl::basic_file_path_buffer class
 *  template.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MAJOR      4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MINOR      0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_REVISION   3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_EDIT       45
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS
# include <unixstl/string_access.hpp>         // for string access shims
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

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class basic_file_path_buffer
/** \brief Acts as a buffer with sufficient size for any drive on the host machine
 *
 * \ingroup group__library__file_system
 *
 * This class is a non-template class primarily so that separate instantiations
 * are not created for each instantiation of the basic_file_path_buffer.
 *
 * This class provides a simple function, which is to provide the maximum path
 * length for the host. This information is then cached due to the static nature
 * of the get_drivesvar_() method, although it can be reset by calling the
 * refresh() method on the buffer class.
 *
 * \param C The character type
 * \param A The allocator type
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_file_path_buffer
{
/// \name Member Constants
/// @{
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

    typedef stlsoft_ns_qual(auto_buffer)<   C
                                        ,   internalBufferSize
                                        ,   A
                                        >                           buffer_type;
/// @}

/// \name Member Types
/// @{
public:
    /// \brief The current parameterisation of the type
    typedef basic_file_path_buffer<C, A>                            class_type;
    /// \brief The value type
    typedef ss_typename_type_k buffer_type::value_type              value_type;
    /// \brief The reference type
    typedef value_type                                              &reference;
    /// \brief The non-mutating (const) reference type
    typedef value_type const                                        &const_reference;
    /// \brief The size type
    typedef ss_typename_type_k buffer_type::size_type               size_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Default constructor
    basic_file_path_buffer()
        : m_buffer(1 + calc_path_max_())
    {
#ifdef _DEBUG
        ::memset(&m_buffer[0], '?', m_buffer.size());
        m_buffer[m_buffer.size() - 1] = '\0';
#endif /* _DEBUG */
    }
    /// \brief Copy constructor
    basic_file_path_buffer(class_type const &rhs)
        : m_buffer(rhs.size())
    {
        stlsoft_ns_qual(pod_copy_n)(data(), rhs.data(), m_buffer.size());
    }
    /// \brief Copy assignment operator
    class_type &operator =(class_type const &rhs)
    {
        m_buffer.resize(rhs.size());
        stlsoft_ns_qual(pod_copy_n)(data(), rhs.data(), m_buffer.size());

        return *this;
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Swaps the contents with those of another instance
    ///
    /// \param rhs The instance whose contents will be swapped with the
    ///  callee
    ///
    /// \note The complexity of this operation is not guaranteed
    ///  to be constant-time. See the documentation for
    ///  \link stlsoft::auto_buffer auto_buffer\endlink for
    ///  further details.
    void swap(class_type &rhs) stlsoft_throw_0()
    {
        m_buffer.swap(rhs.m_buffer);
    }
    /// \brief Resizes the buffer to the given size.
    us_bool_t grow(size_type newSize)
    {
        return m_buffer.resize(newSize);
    }
    /// \brief Doubles the size of the buffer
    us_bool_t grow()
    {
        return grow(2 * size());
    }
/// @}

/// \name Accessors
/// @{
public:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    value_type const    *data() const
    {
        return m_buffer.data();
    }
    value_type          *data()
    {
        return m_buffer.data();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// \brief Returns a pointer to a nul-terminated string
    value_type const *c_str() const
    {
        return this->data();
    }

    /// \brief Returns a mutable (non-const) pointer to the internal buffer
    reference operator [](size_t index)
    {
        buffer_type   &this_  =   m_buffer;

        return this_[index];
    }
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)
    /// \brief Returns a non-mutable (const) pointer to the internal buffer
    const_reference operator [](size_t index) const
    {
        UNIXSTL_MESSAGE_ASSERT("Index out of range", !(size() < index));

        return data()[index];
    }
#endif /* compiler */

    /// \brief Returns the size of the internal buffer
    size_type size() const
    {
        return m_buffer.size();
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Causes the drives to be examined again for the next instance.
    ///
    /// \deprecated
    static void refresh() stlsoft_throw_0()
    {}
/// @}

/// \name Implementation
/// @{
private:
    static size_type    calc_path_max_()
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

        return static_cast<size_type>(pathMax);
#endif /* PATH_MAX */
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type m_buffer;
/// @}
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
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
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
template<   ss_typename_param_k A
        >
inline us_char_a_t const *c_str_ptr_null_a(basic_file_path_buffer<us_char_a_t, A> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}
template<   ss_typename_param_k A
        >
inline us_char_w_t const *c_str_ptr_null_w(basic_file_path_buffer<us_char_w_t, A> const &b)
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
template<   ss_typename_param_k A
        >
inline us_char_a_t const *c_str_ptr_a(basic_file_path_buffer<us_char_a_t, A> const &b)
{
    return b.c_str();
}
template<   ss_typename_param_k A
        >
inline us_char_w_t const *c_str_ptr_w(basic_file_path_buffer<us_char_w_t, A> const &b)
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
template<   ss_typename_param_k A
        >
inline us_char_a_t const *c_str_data_a(basic_file_path_buffer<us_char_a_t, A> const &b)
{
    return b.c_str();
}
template<   ss_typename_param_k A
        >
inline us_char_w_t const *c_str_data_w(basic_file_path_buffer<us_char_w_t, A> const &b)
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

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_size(basic_file_path_buffer<C, A> const &b)
{
    return stlsoft_ns_qual(c_str_size)(b.c_str());
}
#endif /* 0 */

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
            ,   ss_typename_param_k A
            >
    inline void swap(unixstl_ns_qual(basic_file_path_buffer)<C, A> &lhs, unixstl_ns_qual(basic_file_path_buffer)<C, A> &rhs)
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
using ::unixstl::c_str_ptr_null_a;
using ::unixstl::c_str_ptr_null_w;

using ::unixstl::c_str_ptr;
using ::unixstl::c_str_ptr_a;
using ::unixstl::c_str_ptr_w;

using ::unixstl::c_str_data;
using ::unixstl::c_str_data_a;
using ::unixstl::c_str_data_w;

using ::unixstl::c_str_len;

#if 0
using ::unixstl::c_str_size;
#endif /* 0 */

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

/* ////////////////////////////////////////////////////////////////////////// */