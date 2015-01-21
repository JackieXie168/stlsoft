/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/exception_string.hpp
 *
 * Purpose:     Contains the exception_string limited functionality string class.
 *
 * Created:     26th December 2005
 * Updated:     6th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/util/exception_string.hpp
///
/// Contains the exception_string limited functionality string class.

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_MINOR    2
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_REVISION 2
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_EDIT     8
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */

#ifdef STLSOFT_UNITTEST
# include <string.h>
#endif /* STLSOFT_UNITTEST */

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

class exception_string
{
/// \name Member Types
/// @{
public:
    typedef char                                            char_type;
    typedef stlsoft_char_traits<char>                       traits_type;
    typedef allocator_selector<char>::allocator_type        allocator_type;
    typedef exception_string                                class_type;
    typedef size_t                                          size_type;
private:
    typedef auto_buffer_old<char_type, allocator_type, 96>  buffer_type_;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an empty exception
    exception_string()
        : m_message(1)
    {
        m_message[0] = '\0';
    }
    /// Constructs an exception from the given message
    ss_explicit_k exception_string(char const *message)
        : m_message(1 + ((NULL == message) ? 0 : traits_type::length(message)))
    {
        traits_type::copy(&m_message[0], message, m_message.size() - 1);
        m_message[m_message.size() - 1] = '\0';
    }
    /// Copies the message from the given instance
    exception_string(class_type const &rhs)
        : m_message(rhs.m_message.size())
    {
        traits_type::copy(&m_message[0], &rhs.m_message[0], m_message.size());
        m_message[m_message.size() - 1] = '\0';
    }

    /// Appends the given string to the message
    void operator +=(char const *s)
    {
        const ss_size_t n       =   traits_type::length(s);
        const ss_size_t currLen =   this->length();

        if(m_message.resize(m_message.size() + n))
        {
            traits_type::copy(&m_message[currLen], s, n);
            m_message[m_message.size() - 1] = '\0';
        }
    }
    /// Appends the given string to the message
    void operator +=(class_type const &rhs)
    {
        const ss_size_t n       =   rhs.length();
        const ss_size_t currLen =   this->length();

        if(m_message.resize(m_message.size() + n))
        {
            traits_type::copy(&m_message[currLen], rhs.c_str(), n);
            m_message[m_message.size() - 1] = '\0';
        }
    }
    /// Appends the given character to the message
    void operator +=(char ch)
    {
        const ss_size_t n       =   1;
        const ss_size_t currLen =   this->length();

        if(m_message.resize(m_message.size() + n))
        {
            traits_type::copy(&m_message[currLen], &ch, n);
            m_message[m_message.size() - 1] = '\0';
        }
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns a null-terminated c-style string string representing
    /// the message
    char const *c_str() const
    {
        return m_message.data();
    }
    /// Returns the number of characters in the message
    size_type   length() const
    {
        STLSOFT_ASSERT(m_message.size() > 0);

        return m_message.size() - 1;
    }
    /// Indicates whether or not the message is blank
    ss_bool_t    empty() const
    {
        return 0 == this->length();
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type_    m_message;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline exception_string operator +(exception_string const &lhs, char const *rhs)
{
    exception_string    s(lhs);

    s += rhs;

    return s;
}

inline exception_string operator +(char lhs, exception_string const &rhs)
{
    char                lhs_[2] = { lhs, '\0' };
    exception_string    s(lhs_);

    s += rhs;

    return s;
}

inline exception_string operator +(exception_string const &lhs, char rhs)
{
    exception_string    s(lhs);

    s += rhs;

    return s;
}

inline exception_string operator +(char const *lhs, exception_string const &rhs)
{
    exception_string    s(lhs);

    s += rhs;

    return s;
}

inline exception_string operator +(exception_string const &lhs, exception_string const &rhs)
{
    exception_string    s(lhs);

    s += rhs;

    return s;
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/exception_string_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

/* ////////////////////////////////////////////////////////////////////////// */