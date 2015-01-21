/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/std/algorithm.hpp (derived in part from stlsoft_simple_algorithms.h)
 *
 * Purpose:     Contains various standard functions, or their equivalents.
 *
 * Created:     17th January 2002
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


/// \file stlsoft/util/std/algorithm.hpp
///
/// Contains various standard functions, or their equivalents.

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM
#define STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ALGORITHM_MAJOR       3
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ALGORITHM_MINOR       1
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ALGORITHM_REVISION    1
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ALGORITHM_EDIT        64
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#if defined(__STLSOFT_CF_std_NAMESPACE)
# include <algorithm>
#endif /* __STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* The third parameter in the following two implementation functions is used for
 * disambiguation on Visual C++ 6.0, which otherwise gets confused.
 */

template <ss_typename_param_k I>
void std_advance_impl(I &i, ss_size_t n, I *)
{
    for(; 0 != n; ++i, --n)
    {}
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k T2
        >
void std_advance_impl(I *&i, ss_size_t n, T2 const **)
{
    i += n;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

/// \brief Equivalent to std::advance()
template<ss_typename_param_k I>
void std_advance(I &i, ss_size_t n)
{
    std_advance_impl(i, n, &i);
}

/// \brief Equivalent to std::copy()
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline O std_copy(I first, I last, O dest)
{
    for(; first != last; ++first, ++dest)
    {
        *dest = *first;
    }

    return dest;
}

/// \brief Equivalent to std::count_if()
template<   ss_typename_param_k I
        ,   ss_typename_param_k P
        >
inline ss_size_t std_count_if(I first, I to, P pred)
{
#ifdef __STLSOFT_CF_std_NAMESPACE
    return stlsoft_ns_qual_std(count_if)(first, to, pred);
#else /* ? __STLSOFT_CF_std_NAMESPACE */
    ss_size_t r;

    for (r = 0; first != to; ++first)
    {
        if(pred(*first))
        {
            ++r;
        }
    }

    return r;
#endif /* __STLSOFT_CF_std_NAMESPACE */
}

/// \brief Equivalent to std::fill()
template<   ss_typename_param_k O
        ,   ss_typename_param_k V
        >
inline void std_fill(O first, O last, V const &v)
{
#ifdef __STLSOFT_CF_std_NAMESPACE
    stlsoft_ns_qual_std(fill)(first, last, v);
#else /* ? __STLSOFT_CF_std_NAMESPACE */
    for(; first != last; ++first)
    {
        *first = v;
    }
#endif /* __STLSOFT_CF_std_NAMESPACE */
}

/// \brief Equivalent to std::fill_n()
template<   ss_typename_param_k O
        ,   ss_typename_param_k V
        >
inline void std_fill_n(O dest, ss_size_t n, V const &v)
{
#ifdef __STLSOFT_CF_std_NAMESPACE
    stlsoft_ns_qual_std(fill_n)(dest, n, v);
#else /* ? __STLSOFT_CF_std_NAMESPACE */
    for(; 0 != n; ++dest, --n)
    {
        *dest = v;
    }
#endif /* __STLSOFT_CF_std_NAMESPACE */
}

/// \brief Equivalent to std::for_each()
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline F std_for_each(I first, I last, F f)
{
#ifdef __STLSOFT_CF_std_NAMESPACE
    return stlsoft_ns_qual_std(for_each)(first, last, f);
#else /* ? __STLSOFT_CF_std_NAMESPACE */
    for(; first != last; ++first)
    {
        f(*first);
    }

    return f;
#endif /* __STLSOFT_CF_std_NAMESPACE */
}

/// \brief Equivalent to std::replace()
template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        >
inline void std_replace(I first, I last, T const &valFind, T const &valReplace)
{
    for(; first != last; ++first)
    {
        if(valFind == *first)
        {
            *first = valReplace;
        }
    }
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        ,   ss_typename_param_k F
        >
inline O std_transform(I first, I last, O dest, F fn)
{
#ifdef __STLSOFT_CF_std_NAMESPACE
    return stlsoft_ns_qual_std(transform)(first, last, dest, fn);
#else /* ? __STLSOFT_CF_std_NAMESPACE */
    for(; first != last; ++first)
    {
        f(*first);
    }

    return f;
#endif /* __STLSOFT_CF_std_NAMESPACE */
    for(; first != last; ++first, ++dest)
    {
        *dest = fn(*first);
    }

    return dest;
}

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM */

/* ////////////////////////////////////////////////////////////////////////// */
