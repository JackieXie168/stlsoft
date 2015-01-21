/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/transform_iterator.hpp (formerly MTTrnsIt.h; ::SynesisStl)
 *
 * Purpose:     An iterator adaptor that uses a unary function object to transform
 *              the values from the iterator's underlying sequence.
 *
 * Created:     6th February 1999
 * Updated:     20th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/iterators/transform_iterator.hpp
///
/// An iterator adaptor that uses a predicate to filter desired values from the iterator's underlying sequence.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR_MAJOR     2
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR_MINOR     0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR_REVISION  5
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR_EDIT      89
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
# include <stlsoft/iterator.hpp>      // stlsoft::iterator, and macros
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

#ifdef STLSOFT_UNITTEST
# include <algorithm>
# include <functional>
# include <string>
# include <vector>
# include <stlsoft/integer_to_string.hpp>
#endif /* STLSOFT_UNITTEST */

// #define STLSOFT_TRANSFORM_ITERATOR_IS_COMPATIBLE_WITH_HETEROGENOUS_ITERATOR_ALGOS

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

#if 0
struct null_function
{
public:
    typedef void    *result_type;
};
#endif /* 0 */


/// Transforms the elements of an iterator 
///
/// I The iterator to transform
/// F The unary function that will be used to transform the values
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
class transform_iterator
{
/// \name Member Types
/// @{
public:
    /// The iterator to transform
    typedef I                                                       source_iterator_type;
    /// The unary function that will be used to transform the values
    typedef F                                                       transform_function_type;
    /// The value type
    typedef ss_typename_type_k transform_function_type::result_type value_type;
#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1
    /// The iterator category
    typedef stlsoft_ns_qual_std(input_iterator_tag)                 iterator_category;
    /// The difference type
    typedef ss_ptrdiff_t                                            difference_type;
#else /* ? library */
    typedef stlsoft_ns_qual_std(iterator_traits)<I>                 traits_type;
    /// The iterator category
    typedef ss_typename_type_k traits_type::iterator_category       iterator_category;
    /// The difference type
    typedef ss_typename_type_k traits_type::difference_type         difference_type;
#endif /* library */
    /// The size type
    typedef ss_size_t                                               size_type;
    /// The parameterisation of the type
    typedef transform_iterator<I, F>                                class_type;
    /// The mutating (non-const) pointer type
    typedef value_type                                              *pointer;
    /// The non-mutating (const) pointer type
    typedef value_type const                                        *const_pointer;
    /// The mutating (non-const) reference type
    typedef value_type                                              &reference;
    /// The non-mutating (const) reference type
    typedef value_type const                                        &const_reference;
/// @}

/// \name Construction
/// @{
public:
    transform_iterator(source_iterator_type it, transform_function_type pr)
        : m_it(it)
        , m_transformer(pr)
    {}
    transform_iterator()
        : m_it()
        , m_transformer()
    {}
/// @}

/// \name Conversion
/// @{
public:
#if 0
# if 1
    transform_iterator(class_type const &rhs)
        : m_it(rhs.m_it)
        , m_transformer(rhs.m_transformer)
    {}
# endif /* 0 */

    template <typename F2>
    transform_iterator(transform_iterator<I, F2> const &rhs)
        : m_it(rhs.m_it)
        , m_transformer()
    {}

# if 0
    template <typename F2>
    operator transform_iterator<I, F2>() const
    {
        return transform_iterator<I, F2>(m_it, F2());
    }
# endif /* 0 */
#endif /* 0 */
/// @}

/// \name Accessors
/// @{
public:
    reference operator *()
    {
        m_current = m_transformer(*m_it);

        return m_current;
    }
    const_reference operator *() const
    {
        m_current = m_transformer(*m_it);

        return m_current;
    }
/// @}

/// \name Forward Iterator methods
/// @{
public:
    class_type &operator ++()
    {
        ++m_it;

        return *this;
    }
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }
/// @}

/// \name Bidirectional Iterator methods
/// @{
public:
    class_type &operator --()
    {
        ++m_it;

        return *this;
    }
    class_type operator --(int)
    {
        class_type  ret(*this);

        operator --();

        return ret;
    }
/// @}

/// \name Random Access Iterator methods
/// @{
public:
    class_type &operator +=(difference_type d)
    {
        m_it += d;

        return *this;
    }
    class_type &operator -=(difference_type d)
    {
        m_it -= d;

        return *this;
    }

    // NOTE: Can't be reference, since what would it reference??
    value_type operator [](difference_type index)
    {
        return m_transformer(m_it[index]);
    }
    // NOTE: Can't be reference, since what would it reference??
    const value_type operator [](difference_type index) const
    {
        return m_transformer(m_it[index]);
    }
/// @}

/// \name Comparison
/// @{
public:
    ss_bool_t equal(class_type const &rhs) const
    {
        return m_it == rhs.m_it;
    }
#if 0
    ss_bool_t equal(source_iterator_type rhs) const
    {
        return m_it == rhs;
    }
#endif /* 0 */
    ss_sint_t compare(class_type const &rhs) const
    {
        return m_it - rhs.m_it;
    }
    difference_type difference(class_type const &rhs) const
    {
        return m_it - rhs.m_it;
    }
/// @}

/// \name Members
/// @{
private:
#if 0
public:
#endif /* 0 */
    source_iterator_type        m_it;
private:
    transform_function_type     m_transformer;
    value_type                  m_current;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Creator function
 */

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline transform_iterator<I, F> make_transform_iterator(I i, F f)
{
    return transform_iterator<I, F>(i, f);
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline transform_iterator<I, F> transformer(I i, F f)
{
    return transform_iterator<I, F>(i, f);
}

#if 0
template<   ss_typename_param_k I
        >
inline transform_iterator<I, null_function> transformer(I i)
{
    return transform_iterator<I, null_function>(i, null_function());
}
#endif

#if 0
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline transform_iterator<I, F> transform(I i, F f)
{
    return transform_iterator<I, F>(i, f);
}
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

// operator +

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline transform_iterator<I, F> operator +(transform_iterator<I, F> const &lhs, ss_typename_type_k transform_iterator<I, F>::difference_type rhs)
{
    return transform_iterator<I, F>(lhs) += rhs;
}

// operator -

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
#if 0
inline transform_iterator<I, F> operator -(transform_iterator<I, F> const &lhs, ss_typename_type_k transform_iterator<I, F>::difference_type rhs)
#else /* ? 0 */
inline transform_iterator<I, F> operator -(transform_iterator<I, F> const &lhs, ss_ptrdiff_t rhs)
#endif /* 0 */
{
    return transform_iterator<I, F>(lhs) -= rhs;
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_typename_type_k transform_iterator<I, F>::difference_type operator -(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.difference(rhs);
}

// operator ==

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator ==(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.equal(rhs);
}

// operator !=

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator !=(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return !lhs.equal(rhs);
}

#if 0
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator !=(transform_iterator<I, F> const &lhs, I rhs)
{
    return !lhs.equal(rhs);
}
#endif /* 0 */

// operator <

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator <(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.compare(rhs) < 0;
}

// operator <=

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator <=(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.compare(rhs) <= 0;
}

// operator >

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator >(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.compare(rhs) > 0;
}

// operator >=

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator >=(transform_iterator<I, F> const &lhs, transform_iterator<I, F> const &rhs)
{
    return lhs.compare(rhs) >= 0;
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/transform_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
