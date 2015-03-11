/* /////////////////////////////////////////////////////////////////////////////
 * File:        environment_block.hpp (formerly winstl_environment_block.h)
 *
 * Purpose:     Contains the basic_environment_block class.
 *
 * Created:     25th June 2004
 * Updated:     18th December 2005
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


/// \file winstl/environment_block.hpp
///
/// Contains the basic_environment_block class.

#ifndef WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_BLOCK
#define WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_BLOCK

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_BLOCK_MAJOR    3
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_BLOCK_MINOR    1
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_BLOCK_REVISION 1
# define WINSTL_VER_WINSTL_HPP_ENVIRONMENT_BLOCK_EDIT     31
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>  // processheap_allocator
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp> // stlsoft::char_traits
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>          // c_str_ptr
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

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
/// \brief This library provides facilities for defining and manipulating operating-system specific constructs

/// \weakgroup winstl_system_library System Library (WinSTL)
/// \ingroup WinSTL libraries_system
/// \brief This library provides facilities for defining and manipulating operating-system specific constructs for the Win32 operating system
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Class used for preparing environment blocks
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = char_traits<C>
        ,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = char_traits<C> */
        ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_environment_block
{
/// \name Types
/// @{
public:
    /// The value type
    typedef C                                   value_type;
    /// The char type
    typedef C                                   char_type;
    /// The traits type
    typedef T                                   traits_type;
    /// The allocator type
    typedef A                                   allocator_type;
    /// The current parameterisation of the type
    typedef basic_environment_block<C, T, A>    class_type;
    /// The size type
    typedef ws_size_t                           size_type;
/// @}

/// \name Construction
/// @{
public:
    basic_environment_block()
        : m_buffer(2)
    {
        m_buffer[0] = '\0';
        m_buffer[1] = '\0';
    }
    basic_environment_block(class_type const &rhs)
        : m_buffer(rhs.m_buffer.size())
    {
        pod_copy_n(&m_buffer.data()[0], &rhs.m_buffer.data()[0], m_buffer.size());
    }

    class_type &operator =(class_type const &rhs)
    {
        if(m_buffer.resize(rhs.m_buffer.size()))
        {
            pod_copy_n(&m_buffer.data()[0], &rhs.m_buffer.data()[0], m_buffer.size());
        }

        return *this;
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Append a full NAME=VALUE environment pair
    void push_back(char_type const *s, size_t cch)
    {
        WINSTL_ASSERT(NULL != s);
        WINSTL_ASSERT(cch >= 3);
        WINSTL_ASSERT(NULL != traits_type::find(s, cch, '='));

        size_type   oldSize = m_buffer.size();

        WINSTL_ASSERT(m_buffer.size() > 1);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 1]);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 2]);

        m_buffer.resize(oldSize + cch + 1);

        traits_type::copy(&m_buffer[oldSize - 1], s, cch);
        m_buffer[m_buffer.size() - 2] = '\0';
        m_buffer[m_buffer.size() - 1] = '\0';

        WINSTL_ASSERT(m_buffer.size() > 1);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 1]);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 2]);
    }
    template <typename S>
    void push_back(S const &s)
    {
        push_back(stlsoft_ns_qual(c_str_data)(s), stlsoft_ns_qual(c_str_len)(s));
    }
    void push_back(char_type const *name, size_t cchName, char_type const *value, size_t cchValue)
    {
        WINSTL_ASSERT(NULL != name);
        WINSTL_ASSERT(NULL != value);
        WINSTL_ASSERT(cchName > 1);
        WINSTL_ASSERT(cchValue > 1);

        size_type   oldSize = m_buffer.size();

        WINSTL_ASSERT(m_buffer.size() > 1);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 1]);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 2]);

        m_buffer.resize(oldSize + cchName + 1 + cchValue + 1);

        traits_type::copy(&m_buffer[oldSize - 2], name, cchName);
        m_buffer[oldSize - 2 + cchName] = '=';
        traits_type::copy(&m_buffer[oldSize - 2 + cchName + 1], value, cchValue);
        m_buffer[oldSize - 2 + cchName + 1 + cchValue] = '\0';
        m_buffer[m_buffer.size() - 2] = '\0';
        m_buffer[m_buffer.size() - 1] = '\0';

        WINSTL_ASSERT(m_buffer.size() > 1);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 1]);
        WINSTL_ASSERT('\0' == m_buffer[m_buffer.size() - 2]);
    }
    template <typename S1, typename S2>
    void push_back(S1 const &name, S2 const &value)
    {
        push_back(stlsoft_ns_qual(c_str_data)(name), stlsoft_ns_qual(c_str_len)(name), stlsoft_ns_qual(c_str_data)(value), stlsoft_ns_qual(c_str_len)(value));
    }

    void clear()
    {
        m_buffer.resize(2);

        m_buffer[0] = '\0';
        m_buffer[1] = '\0';
    }
/// @}

/// \name Accessors
/// @{
public:
    void const  *base() const
    {
        return m_buffer.data();
    }
    size_type length() const
    {
        return m_buffer.size();
    }
/// @}

/// Members
private:
    typedef stlsoft_ns_qual(auto_buffer)<char_type, allocator_type, 1024>   buffer_type;

    buffer_type m_buffer;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT

 /// Instantiation of the basic_path template for the ANSI character type \c char
typedef basic_environment_block<ws_char_a_t>    environment_block_a;
/// Instantiation of the basic_environment_block template for the Unicode character type \c wchar_t
typedef basic_environment_block<ws_char_w_t>    environment_block_w;
/// Instantiation of the basic_environment_block template for the Win32 character type \c TCHAR
typedef basic_environment_block<TCHAR>          environment_block;

#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/environment_block_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_system_library

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

#endif /* WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_BLOCK */

/* ////////////////////////////////////////////////////////////////////////// */
