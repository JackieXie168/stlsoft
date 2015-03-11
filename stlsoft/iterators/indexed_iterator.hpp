/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/indexed_iterator.hpp
 *
 * Purpose:     indexed_iterator class template.
 *
 * Created:     5th April 2005
 * Updated:     27th December 2005
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


/// \file stlsoft/iterators/indexed_iterator.hpp
///
/// indexed_iterator class template.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR_MAJOR       1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR_MINOR       0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR_REVISION    1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR_EDIT        2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup iterators Iterators
/// \brief STL-compatible iterators

/// \weakgroup adaptors Adaptors
/// \brief Adaptor functions and classes used throughout the STLSoft libraries

/// \weakgroup adaptors_iterator Iterator Adaptors
/// \brief Classes that provide iterator adaptation
/// \ingroup iterators adaptors
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<   ss_typename_param_k I
        >
// [[synesis:class:iterator: indexed_iterator<T<I>>]]
class indexed_iterator
{
private:
    typedef ::std::iterator_traits<I>                           iterator_traits_type;
public:
    typedef I                                                   iterator_type;
    typedef indexed_iterator<I>                                 class_type;
    typedef ss_typename_type_k iterator_traits_type::value_type value_type;
//  typedef ss_typename_type_k iterator_type::value_type        value_type;
    typedef ss_size_t                                           size_type;

public:
    indexed_iterator()
        : m_i(I())
        , m_index(0)
    {}
    ss_explicit_k indexed_iterator(I i, size_type index = 0)
        : m_i(i)
        , m_index(index)
    {}
#if 0
    ss_explicit_k indexed_iterator(I i, size_type index)
        : m_i(i)
        , m_index(index)
    {}
#endif /* 0 */
    indexed_iterator(class_type const &rhs)
        : m_i(rhs.m_i)
        , m_index(rhs.m_index)
    {}

public:
    class_type &operator ++()
    {
        ++m_i;
        ++m_index;

        return *this;
    }

    class_type operator ++(int)
    {
        class_type  r(*this);

        operator ++();

        return r;
    }

    value_type &operator *()
    {
        return *m_i;
    }

    value_type const &operator *() const
    {
        return *m_i;
    }

    value_type *operator ->()
    {
        return m_i.operator ->();
    }

    value_type const *operator ->() const
    {
        return m_i.operator ->();
    }

public:
    size_type index() const
    {
        return m_index;
    }

public:
    ss_bool_t equal(class_type const &rhs) const
    {
        return m_i == rhs.m_i;
    }

private:
    I           m_i;
    size_type   m_index;
};

template<   ss_typename_param_k I
        >
inline ss_bool_t operator ==(indexed_iterator<I> const &lhs, indexed_iterator<I> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k I
        >
inline ss_bool_t operator !=(indexed_iterator<I> const &lhs, indexed_iterator<I> const &rhs)
{
    return !lhs.equal(rhs);
}

////////////////////////////////////////////////////////////////////////////////

/// @} // end of group

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/indexed_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_INDEXED_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
