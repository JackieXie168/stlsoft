/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/tref_reverse_iterator.hpp
 *
 * Purpose:     tref_reverse_iterator class template.
 *
 * Created:     4th October 2005
 * Updated:     18th December 2005
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


/// \file stlsoft/iterators/tref_reverse_iterator.hpp
///
/// tref_reverse_iterator class template.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR_MAJOR      1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR_MINOR      1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR_REVISION   1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR_EDIT       2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#error This file is experimental, and should not (yet) be used

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_DESTRUCTOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

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

/// This class template provides the same services as std::reverse_iterator, but
/// uses pointers in order to facilitate reverse adaptation of incompletely
/// defined types, such as forward-declared member classes
/// 
/// \param I The iterator to be adapted for reverse iteration
/// \param T The value type
/// \param R The reference type
/// \param P The pointer type
/// \param D The distance type
/// \param C The iterator category
template<   ss_typename_param_k I
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# ifdef __STLSOFT_CF_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT
#  error __STLSOFT_CF_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT
# endif /* __STLSOFT_CF_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT */
        ,   ss_typename_param_k T /* = stlsoft_ns_qual_std(iterator_traits)<I>::value_type */
#else /* ? compiler */
        ,   ss_typename_param_k T = ss_typename_type_def_k stlsoft_ns_qual_std(iterator_traits)<I>::value_type
#endif /* compiler */
        ,   ss_typename_param_k R = T&
        ,   ss_typename_param_k P = T*
        ,   ss_typename_param_k D = ptrdiff_t
#if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
//		,	ss_typename_param_k C = /* ss_typename_type_k */ stlsoft_ns_qual_std(iterator_traits)<I>::iterator_category
		,	ss_typename_param_k C = std::iterator_traits<I>::iterator_category
#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
		,	ss_typename_param_k C = stlsoft_ns_qual_std(input_iterator_tag)
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
        >
class tref_reverse_iterator
{
private:
public:
    typedef tref_reverse_iterator<I, T, R, P, D, C>                    class_type;
#if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
    typedef 
    typedef I                                                           iterator_type;
    typedef T                                                           value_type;
    typedef R                                                           reference;
    typedef P                                                           pointer;
    typedef D                                                           difference_type;
    typedef C															iterator_category;

public:
    tref_reverse_iterator()
        : m_it(iterator_type())
    {}
    explicit tref_reverse_iterator(I it)
        : m_it(it)
    {}
    tref_reverse_iterator(class_type const &rhs)
        : m_it(rhs.m_it)
    {}

public:
    I base() const
    {
        return m_it;
    }
    reference operator *() const
    {
        return *(m_it - 1);
    }
    class_type &operator ++()
    {
        --(m_it);

        return *this;
    }
    class_type operator ++(int)
    {
        class_type ret(*this);

        operator ++();

        return ret;
    }

    class_type &operator --()
    {
        ++(m_it);

        return *this;
    }
    class_type operator --(int)
    {
        class_type ret(*this);

        operator --();

        return ret;
    }

    reference operator [](difference_type index) const
    {
        return (*(*this + index));
    }

    class_type &operator +=(difference_type index)
    {
        m_it -= index;

        return (*this);
    }
    class_type operator +(difference_type index) const
    {
        return (class_type(m_it - index));
    }
    class_type &operator -=(difference_type index)
    {
        m_it += index;

        return (*this);
    }
    class_type operator -(difference_type index) const
    {
        return (class_type(m_it + index));
    }
    difference_type operator -(class_type const &rhs) const
    {
        // NOTE: The operands are reversed (since it's a reverse range)
        return rhs.m_it - m_it;
    }

    bool equal(class_type const &rhs) const
    {
        return m_it == rhs.m_it;
    }

    int compare(class_type const &rhs) const
    {
        return (m_it < rhs.m_it) ? -1 : (rhs.m_it < m_it) ? +1 : 0;
    }

private:
    iterator_type   m_it;
};

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator ==(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator !=(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return !lhs.equal(rhs);
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator <(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return lhs.compare(rhs) < 0;
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator <=(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return lhs.compare(rhs) <= 0;
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator >(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return lhs.compare(rhs) > 0;
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        ,   ss_typename_param_k R
        ,   ss_typename_param_k P
        ,   ss_typename_param_k D
        ,   ss_typename_param_k C
        >
inline bool operator >=(tref_reverse_iterator<I, T, R, P, D, C> const &lhs, tref_reverse_iterator<I, T, R, P, D, C> const &rhs)
{
    return lhs.compare(rhs) >= 0;
}

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TREF_REVERSE_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
