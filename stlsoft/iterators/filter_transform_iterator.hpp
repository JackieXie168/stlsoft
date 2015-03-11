/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/filter_transform_iterator.hpp
 *
 * Purpose:     A combination of the filter_iterator and the transform_iterator.
 *
 * Created:     2nd January 2006
 * Updated:     31st January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/iterators/filter_transform_iterator.hpp
///
/// A combination of the filter_iterator and the transform_iterator.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR_MAJOR     1
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR_MINOR     0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR_REVISION  2
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR_EDIT      4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_BORLAND:
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1310
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR
# include <stlsoft/iterators/transform_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_ITERATOR
# include <stlsoft/iterators/filter_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_ITERATOR */
/* TODO: Explicitly include header for is_integral_type when it's moved out of stlsoft_meta.h */

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
 * Creator functions
 */

/// Creator function for filter_iterator + transform_iterator
///
/// \param from The start of the iterator range to be transformed
/// \param to The end-point of the iterator range to be transformed
/// \param pr The predicate used to filter the underlying range
/// \param fn The function object used to effect the transformation
///
/// \return An instance of the specialisation filter_iterator&lt;T, P&gt;
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        ,   ss_typename_param_k P
        >
inline filter_iterator<transform_iterator<I, F>, P> make_filter_transform_iterator(I from, I to, P pr, F fn)
{
    typedef ss_typename_param_k P::result_type  predicate_result_t;

    // If this fires, you've either specified the transforming function and
    // the filtering predicate in the wrong order, or your predicate has a
    // non-integral return type (which would be decidedly odd).
    STLSOFT_STATIC_ASSERT(0 != is_integral_type<predicate_result_t>::value);

    return filter(transformer(from, fn), transformer(to, fn), pr);
}

/// Creator function for filter_iterator + transform_iterator
///
/// \param from The start of the iterator range to be transformed
/// \param to The end-point of the iterator range to be transformed
/// \param pr The predicate used to filter the underlying range
/// \param fn The function object used to effect the transformation
///
/// \return An instance of the specialisation filter_iterator&lt;T, P&gt;
///
/// \note Short-hand for make_filter_transform_iterator()
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        ,   ss_typename_param_k P
        >
inline filter_iterator<transform_iterator<I, F>, P> filter_transformer(I from, I to, P pr, F fn)
{
    return make_filter_transform_iterator(from, to, pr, fn);
}

////////////////////////////////////////////////////////////////////////////////

/// @} // end of group

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
//# include "./unittest/filter_transform_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_TRANSFORM_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
