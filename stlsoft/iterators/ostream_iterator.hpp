/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/ostream_iterator.hpp
 *
 * Purpose:     Enhanced ostream iterator.
 *
 * Created:     16th December 2005
 * Updated:     20th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/iterators/ostream_iterator.hpp
///
/// Enhanced ostream iterator.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_MAJOR       1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_MINOR       0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_REVISION    4
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_EDIT        6
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#include <string>

/* For some reason, VC++ 6.0 has an ICE if the following is not included */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1200
# include <iterator>
#endif /* compiler */

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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k C>
struct character_encoding_check
{
    character_encoding_check()
    {}

    template <ss_typename_param_k S>
    character_encoding_check(S const &s)
    {
        C   const   *p1 =   stlsoft::c_str_ptr(s);

        STLSOFT_STATIC_ASSERT(sizeof(C) == sizeof(*stlsoft::c_str_ptr(s)));
    }

    template<   ss_typename_param_k S1
            ,   ss_typename_param_k S2
            >
    character_encoding_check(S1 const &s1, S2 const &s2)
    {
        C   const   *p1 =   stlsoft::c_str_ptr(s1);
        C   const   *p2 =   stlsoft::c_str_ptr(s2);

        STLSOFT_STATIC_ASSERT(sizeof(C) == sizeof(*stlsoft::c_str_ptr(s1)));
        STLSOFT_STATIC_ASSERT(sizeof(C) == sizeof(*stlsoft::c_str_ptr(s2)));
    }

private:
    template<   ss_typename_param_k S
            ,   ss_typename_param_k C2
            >
    static void check_stream_has_correct_encoding(S const &given_string_type)
    {
        C2 const *required_char_encoding_type   =   stlsoft::c_str_ptr(given_string_type);

        STLSOFT_STATIC_ASSERT(sizeof(C) == sizeof(*stlsoft::c_str_ptr(given_string_type)));
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// \brief Enhanced functionality over std::ostream_iterator
///
/// This class template provides full backwards-compatibility with 
/// std::ostream_iterator, but offers the additional capability to supply both
/// prefix <i>and</i> suffix to each delimited item.
///
/// For example, the following code indents each entry in the sequence as well
/// as appending a carriage return.
/// 
/// \htmlonly
/// <pre>
///
/// std::vector&lt;int>  ints(10);
///
/// { for(size_t i = 0; i &lt; ints.size(); ++i)
/// {
///   ints[i] = i;
/// }}
///
/// std::cout &lt;&lt; "Elements:" &lt;&lt; std::endl;
/// std::copy(ints.begin(), ints.end(), stlsoft::ostream_iterator&lt;int>(std::cout, "\t", "\n");
/// </pre>
/// \endhtmlonly
///
/// This gives the following output:
/// 
/// \htmlonly
/// <pre>
/// <b>
/// Elements:
///         0
///         1
///         2
///         3
///         4
///         5
///         6
///         7
///         8
///         9
/// </b>
/// </pre>
/// \endhtmlonly
///
/// \param V The value type.
/// \param C The character type. Defaults to <code>char</code>.
/// \param T The traits type. Defaults to <code>std::char_traits&lt;C></code>.
/// \param S The string type. Defaults to <code>std::basic_string&lt;C></code>.
template<   ss_typename_param_k V
        ,   ss_typename_param_k C = char
        ,   ss_typename_param_k T = std::char_traits<C>
        ,   ss_typename_param_k S = std::basic_string<C, T>
        >
class ostream_iterator
    : private character_encoding_check<C>
{
/// \name Member Types
/// @{
public:
    /// The value type
    typedef V                                           value_type;
    /// The character type
    typedef C                                           char_type;
    /// The traits type
    typedef T                                           traits_type;
    /// The string type
    typedef S                                           string_type;
    /// The stream type
    typedef std::basic_ostream<char_type, traits_type>  ostream_type;
private:
    typedef character_encoding_check<C>                 encoding_verifier_type;
public:
    /// The class type
    typedef ostream_iterator<V, C, T, S>                class_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs an instance holding a reference to the given stream, with default prefix and suffix
    ///
    /// \note This is 100% functionally compatible with std::iostream_iterator
    ss_explicit_k ostream_iterator(ostream_type &os)
        : m_stm(os)
        , m_prefix()
        , m_suffix()
    {}
    /// \brief Constructs an instance holding a reference to the given stream, with a suffix
    ///
    /// \note This is 100% functionally compatible with std::iostream_iterator
    template <ss_typename_param_k S1>
    ostream_iterator(ostream_type &os, S1 const &suffix)
        : encoding_verifier_type(suffix)
        , m_stm(os)
        , m_prefix()
        , m_suffix(stlsoft::c_str_ptr(suffix))
    {}
    /// \brief Constructs an instance holding a reference to the given stream, with a prefix and a suffix
    template <ss_typename_param_k S1, ss_typename_param_k S2>
    ostream_iterator(ostream_type &os, S1 const &prefix, S2 const &suffix)
        : encoding_verifier_type(prefix, suffix)
        , m_stm(os)
        , m_prefix(stlsoft::c_str_ptr(prefix))
        , m_suffix(stlsoft::c_str_ptr(suffix))
    {}
    /// \brief Creates a copy of an ostream_iterator instance
    ///
    /// \param rhs The instance to copy
    ostream_iterator(class_type const &rhs)
        : m_stm(rhs.m_stm)
        , m_prefix(rhs.m_prefix)
        , m_suffix(rhs.m_suffix)
    {}
    ~ostream_iterator() stlsoft_throw_0()
    {}
/// @}

/// \name Assignment
/// @{
public:
    class_type &operator =(value_type const &value)
    {
        m_stm << m_prefix << value << m_suffix;

        return *this;
    }
/// @}

/// \name Ouput Iterator Methods
/// @{
public:
    class_type &operator *()
    {
        return *this;
    }
    class_type &operator ++()
    {
        return *this;
    }
    class_type operator ++(int)
    {
        return *this;
    }
/// @}

/// \name Members
/// @{
private:
    ostream_type    &m_stm;
    string_type     m_prefix;
    string_type     m_suffix;
/// @}
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/ostream_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
