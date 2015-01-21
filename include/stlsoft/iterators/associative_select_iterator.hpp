/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/associative_select_iterator.hpp
 *
 * Purpose:     An iterator adaptor that uses a select functor on its underlying
 *              iterator in order to obtain the value_type.
 *
 * Created:     28th January 2005
 * Updated:     10th August 2009
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2009, Matthew Wilson and Synesis Software
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


/** \file stlsoft/iterators/associative_select_iterator.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::contiguous_diluter_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR_MAJOR    2
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR_MINOR    0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR_REVISION 1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR_EDIT     24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Selects the \c first member of the type to which it is applied
 *
 * \ingroup group__library__iterators
 */
// [[synesis:class:function-class:unary-function: select_first<T<P>>]]
template <class P>
struct select_first
{
public:
    typedef ss_typename_type_k P::first_type    value_type;
    typedef value_type&                         reference;
    typedef value_type const&                   const_reference;

public:
    reference operator ()(P const& p)
    {
        return p.first;
    }
    const_reference operator ()(P const& p) const
    {
        return p.first;
    }
};

/** \brief Selects the \c first second of the type to which it is applied
 *
 * \ingroup group__library__iterators
 */
// [[synesis:class:function-class:unary-function: select_second<T<P>>]]
template <class P>
struct select_second
{
public:
    typedef ss_typename_type_k P::second_type   value_type;
    typedef value_type&                         reference;
    typedef value_type const&                   const_reference;

public:
    reference operator ()(P const& p)
    {
        return p.second;
    }
    const_reference operator ()(P const& p) const
    {
        return p.second;
    }
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <class P>
struct select_second_const
{
public:
    typedef const ss_typename_type_k P::second_type value_type;
    typedef value_type&                             reference;
    typedef value_type&                             const_reference;

public:
    const_reference operator ()(P const& p) const
    {
        return p.second;
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** An iterator adaptor that uses a select functor on its base iterator
 *    in order to obtain the value_type.
 *
 * \ingroup group__library__iterators
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
class associative_select_iterator
{
public:
    typedef I                                       adapted_iterator_type;
    typedef F                                       selecting_function_type;
    typedef ss_typename_type_k I::iterator_category iterator_category;
    typedef ss_typename_type_k F::value_type        value_type;
    typedef ss_typename_type_k I::distance_type     distance_type;
    typedef associative_select_iterator<I, F>                           class_type;

    typedef value_type&                                                 reference;
    typedef value_type const&                                           const_reference;
    typedef value_type*                                                 pointer;
    typedef value_type const*                                           const_pointer;

public:
    ss_explicit_k associative_select_iterator(  adapted_iterator_type   i
                                            ,   selecting_function_type f = selecting_function_type())
        : m_i(i)
        , m_f(f)
    {}

public:
    ss_bool_t equal(class_type const& rhs) const
    {
        return m_i == rhs.m_i;
    }

public:
    class_type& operator ++()
    {
        ++m_i;

        return *this;
    }
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }

    reference operator *()
    {
        return m_f(*m_i);
    }

private:
    adapted_iterator_type   m_i;
    selecting_function_type m_f;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator ==(associative_select_iterator<I, F> const& lhs, associative_select_iterator<I, F> const& rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline ss_bool_t operator !=(associative_select_iterator<I, F> const& lhs, associative_select_iterator<I, F> const& rhs)
{
    return !lhs.equal(rhs);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_ASSOCIATIVE_SELECT_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */
