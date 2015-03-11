/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/split_functions.hpp
 *
 * Purpose:     String split functions.
 *
 * Created:     28th January 2005
 * Updated:     12th March 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/split_functions.hpp
 *
 * \brief [C++ only] String split functions
 *   (\ref group__library__string "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_MAJOR      2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_MINOR      1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_REVISION   1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_EDIT       33
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_BORLAND:  __BORLANDC__<0x0564
STLSOFT_COMPILER_IS_DMC:  __DMC__<0x0844
STLSOFT_COMPILER_IS_GCC:  __GNUC__<3
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#if (   defined(STLSOFT_COMPILER_IS_BORLAND) && \
        __BORLANDC__ < 0x0560) || \
    (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ < 0x0844) || \
    (   defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200)
# define STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
# ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY
#  include <stlsoft/containers/static_array.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY */
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
# include <vector>
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
#include <algorithm>

#ifdef STLSOFT_UNITTEST
# include <stlsoft/string/simple_string.hpp>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

template<   ss_typename_param_k S
        ,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
        >
inline ss_bool_t split_impl(C const* s, ss_size_t n, C delim, S& s0, S& s1)
{
    typedef ss_typename_type_k S::const_iterator    iterator_t;

    C const* const  b   =   s;
    C const* const  e   =   s + n;
    C const*        it  =   stlsoft_ns_qual_std(find)(b, e, delim);

    s0 = S(b, it);

    return (e == it) ? false : (++it, s1 = S(it, e), true);
}

/** \brief Splits a string into two, at the first incidence of a delimiter
 *
 * \ingroup group__library__string
 *
 * \note The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 */
template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        ,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
        >
inline ss_bool_t split(S1 const& s, C delim, S2& s0, S2& s1)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));

    return split_impl(c_str_data(s), c_str_len(s), delim, s0, s1);
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
        >
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
inline static_array_1d<S, 2>            split(S const& s, C delim)
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
inline stlsoft_ns_qual_std_(vector)<S>  split(S const& s, C delim)
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
{
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
    static_array_1d<S, 2>           r;
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
    stlsoft_ns_qual_std_(vector)<S> r(2);
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */

    split_impl(c_str_data(s), c_str_len(s), delim, r[0], r[1]);

    return r;
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/split_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
