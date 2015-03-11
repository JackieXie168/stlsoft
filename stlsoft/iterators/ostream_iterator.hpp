/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/ostream_iterator.hpp
 *
 * Purpose:     Enhanced ostream iterator.
 *
 * Created:     16th December 2005
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file stlsoft/iterators/ostream_iterator.hpp
///
/// Enhanced ostream iterator.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_MAJOR       1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_MINOR       2
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_REVISION    4
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR_EDIT        24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#include <string>

/* For some reason, VC++ 6.0 has an ICE if the following is not included */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1200
# include <iterator>
# include <stlsoft/string/char_traits.hpp>
#endif /* compiler */

#ifdef STLSOFT_UNITTEST
# include <algorithm>
# include <sstream>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

/// \weakgroup iterators Iterators
/// \brief STL-compatible iterators

/// \weakgroup iterators_output Output Iterators
/// \brief Classes that provide Output Iteration functionality
/// \ingroup iterators
/// @{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

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
        ,   ss_typename_param_k T = stlsoft_ns_qual_std(char_traits)<C>
        ,   ss_typename_param_k S = stlsoft_ns_qual_std(basic_string)<C, T>
        >
// [[synesis:class:iterator: ostream_iterator<T<V>, T<C>, T<T>, T<S>>]]
class ostream_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The value type
    typedef V                                                           assigned_type;
    /// The character type
    typedef C                                                           char_type;
    /// The traits type
    typedef T                                                           traits_type;
    /// The string type
    typedef S                                                           string_type;
    /// The stream type
    typedef stlsoft_ns_qual_std(basic_ostream)< char_type
                                            ,   traits_type
                                            >           ostream_type;
    /// The class type
    typedef ostream_iterator<V, C, T, S>                                class_type;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs an instance holding a reference to the given stream, with default prefix and suffix
    ///
    /// \note This is 100% functionally compatible with std::iostream_iterator
    ss_explicit_k ostream_iterator(ostream_type &os)
        : m_stm(&os)
        , m_prefix()
        , m_suffix()
    {}
    /// \brief Constructs an instance holding a reference to the given stream, with a suffix
    ///
    /// \note This is 100% functionally compatible with std::iostream_iterator
    template <ss_typename_param_k S1>
    ostream_iterator(ostream_type &os, S1 const &suffix)
        : m_stm(&os)
        , m_prefix()
        , m_suffix(get_string_(suffix))
    {}
    /// \brief Constructs an instance holding a reference to the given stream, with a prefix and a suffix
    template <ss_typename_param_k S1, ss_typename_param_k S2>
    ostream_iterator(ostream_type &os, S1 const &prefix, S2 const &suffix)
        : m_stm(&os)
        , m_prefix(get_string_(prefix))
        , m_suffix(get_string_(suffix))
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

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(ostream_iterator *it)
            : m_it(it)
        {}

    public:
        void operator =(assigned_type const &value)
        {
            m_it->invoke_(value);
        }

    private:
        ostream_iterator  *const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const &);
    };

    void invoke_(assigned_type const &value)
    {
        *m_stm << m_prefix << value << m_suffix;
    }
/// @}

/// \name Ouput Iterator Methods
/// @{
public:
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
    class_type &operator ++()
    {
        return *this;
    }
    class_type &operator ++(int)
    {
        return *this;
    }
/// @}

/// \name Implementation
/// @{
private:
    template <ss_typename_param_k S2>
    static string_type get_string_(S2 const &s)
    {
        return stlsoft::c_str_ptr(s);
    }
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER > 1300
    static string_type const &get_string_(string_type const &s)
    {
        return s;
    }
#endif /* compiler */
/// @}

/// \name Members
/// @{
private:
    ostream_type    *m_stm;
    string_type     m_prefix;
    string_type     m_suffix;
/// @}
};

////////////////////////////////////////////////////////////////////////////

/// @} // end of group

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/ostream_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR */

/* ////////////////////////////////////////////////////////////////////// */
