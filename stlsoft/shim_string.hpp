/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shim_string.hpp (formerly stlsoft_shim_string.h)
 *
 * Purpose:     Contains the basic_shim_string template class.
 *
 * Created:     9th July 2004
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


/// \file stlsoft/shim_string.hpp
///
/// Contains the basic_shim_string template class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING
#define STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_SHIM_STRING_MAJOR      2
# define STLSOFT_VER_STLSOFT_HPP_SHIM_STRING_MINOR      2
# define STLSOFT_VER_STLSOFT_HPP_SHIM_STRING_REVISION   1
# define STLSOFT_VER_STLSOFT_HPP_SHIM_STRING_EDIT       19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp>     // stlsoft::char_traits
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/allocator_selector.hpp>  // stlsoft::allocator_selector
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>     // auto_buffer
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_META_YESNO
# include <stlsoft/meta/yesno.hpp>          // yes_type, no_type
#endif /* !STLSOFT_INCL_STLSOFT_HPP_META_YESNO */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief An implementation class, which provides efficient intermediate string
/// objects for conversion shims.
///
/// \param C The character type
/// \param N The number of characters in the internal auto_buffer
/// \param U The nUll indicator. If true, the implicit conversion operator returns
///           NULL for an empty string, otherwise it returns the empty string
/// \param A The allocator
/// \param T The char tratis type
template<   ss_typename_param_k C
        ,   ss_size_t           N   = 64
        ,   ss_bool_t           U   = false
        ,   ss_typename_param_k A   = ss_typename_type_def_k allocator_selector<C>::allocator_type
        ,   ss_typename_param_k T   = stlsoft_char_traits<C>
        >
class basic_shim_string
{
/// \name Types
/// @{
public:
    /// The value type
    typedef C                                           char_type;
    /// The traits type
    typedef T                                           traits_type;
    /// The allocator type
    typedef A                                           allocator_type;
    /// The current parameterisation of the type
    typedef basic_shim_string<C, N, U, A, T>            class_type;
    /// The size type
    typedef size_t                                      size_type;
    /// The buffer type
    typedef auto_buffer<char_type, allocator_type, N>   buffer_type;

/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructor
    ss_explicit_k basic_shim_string(size_type n)
        : m_buffer(1 + n)
    {
        m_buffer[0] = '\0';
        m_buffer[m_buffer.size() - 1] = '\0';
    }

    /// \brief Constructor
    basic_shim_string(char_type const *s, size_type n)
        : m_buffer(1 + n)
    {
        traits_type::copy(&m_buffer[0], s, m_buffer.size() - 1);
        m_buffer[m_buffer.size() - 1] = '\0';
    }

    /// \brief Constructor
    basic_shim_string(char_type const *s)
        : m_buffer(1 + ((NULL == s) ? 0 : traits_type::length(s)))
    {
        traits_type::copy(&m_buffer[0], s, m_buffer.size() - 1);
        m_buffer[m_buffer.size() - 1] = '\0';
    }

    /// \brief Copy constructor
    basic_shim_string(class_type const &rhs)
        : m_buffer(rhs.m_buffer.size())
    {
        traits_type::copy(&m_buffer[0], &rhs.m_buffer[0], m_buffer.size());
        m_buffer[m_buffer.size() - 1] = '\0';
    }
/// @}

/// \name Operations
/// @{
public:
    void write(char_type const *s)
    {
        traits_type::copy(&m_buffer[0], s, m_buffer.size());
        m_buffer[m_buffer.size() - 1] = '\0';
    }

    /// Truncates the string to the given length
    ///
    /// \note The length specified must be less than or equal to the current length
    void truncate(ss_size_t n)
    {
        STLSOFT_MESSAGE_ASSERT("shim_string truncation size must be <= current size", n <= size());

        m_buffer.resize(1 + n);
        m_buffer[m_buffer.size() - 1] = '\0';
    }

    buffer_type &get_buffer()
    {
        return m_buffer;
    }
/// @}

/// \name Accessors
/// @{
public:
    size_type size() const
    {
        STLSOFT_ASSERT(m_buffer.size() > 0);

        return m_buffer.size() - 1;
    }

    char_type *data()
    {
        return m_buffer.data();
    }

    char_type const *data() const
    {
        return m_buffer.data();
    }
/// @}

/// \name Implicit Conversions
/// @{
    operator char_type const *() const
    {
        typedef ss_typename_type_k value_to_yesno_type<U>::type yesno_t;

        return get_ptr_(m_buffer, yesno_t());
    }
    operator ss_size_t() const
    {
        return size();
    }
/// @}

/// \name Implementation
/// @{
private:
    static char_type const *get_ptr_(buffer_type const &buffer, yes_type)
    {
        return ('\0' != buffer[0]) ? buffer.data() : NULL;
    }
    static char_type const *get_ptr_(buffer_type const &buffer, no_type)
    {
        return buffer.data();
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type m_buffer;
/// @}

// Not to be implemented
private:
    basic_shim_string &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

template<   ss_typename_param_k C
        ,   ss_size_t           N
        ,   ss_bool_t           U
        ,   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
inline C const *c_str_ptr(basic_shim_string<C, N, U, A, T> const &ss)
{
    return ss.data();
}

template<   ss_typename_param_k C
        ,   ss_size_t           N
        ,   ss_bool_t           U
        ,   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
inline C const *c_str_data(basic_shim_string<C, N, U, A, T> const &ss)
{
    return ss.data();
}

template<   ss_typename_param_k C
        ,   ss_size_t           N
        ,   ss_bool_t           U
        ,   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
inline ss_size_t c_str_len(basic_shim_string<C, N, U, A, T> const &ss)
{
    return ss.size();
}

template<   ss_typename_param_k C
        ,   ss_size_t           N
        ,   ss_bool_t           U
        ,   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
inline ss_size_t c_str_size(basic_shim_string<C, N, U, A, T> const &ss)
{
    return ss.size() * sizeof(C);
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_size_t           N
        ,   ss_bool_t           U
        ,   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
inline S &operator <<(S &s, basic_shim_string<C, N, U, A, T> const &ss)
{
    s << ss.data();

    return s;
}

#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING */

/* ////////////////////////////////////////////////////////////////////////// */
