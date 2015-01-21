/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/trim_functions.hpp (originally stlsoft/string_trim_functions.hpp)
 *
 * Purpose:     String utility functions for trimming and removing string contents.
 *
 * Created:     25th April 2005
 * Updated:     14th July 2006
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


/** \file stlsoft/string/trim_functions.hpp
 *
 * \brief [C++ only] String utility functions for trimming and removing
 *  string contents.
 *  (\ref group__library__string "String" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS_MAJOR       2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS_MINOR       1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS_REVISION    1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS_EDIT        24
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
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS
# include <stlsoft/string/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STD_HPP_CSTRING
# include <stlsoft/std/cstring.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STD_HPP_CSTRING */
#include <algorithm>
#include <functional>

#ifdef STLSOFT_UNITTEST
# include <string>
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#  include <stlsoft/string/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
inline C const *default_trim_chars(C const *, ss_size_t &n)
{
    static const C  s_trimChars[] =
    {
            ' '
        ,   '\n'
        ,   '\r'
        ,   '\t'
        ,   '\v'
        ,   '\0'
    };

    n = STLSOFT_NUM_ELEMENTS(s_trimChars) - 1;

    return &s_trimChars[0];
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &trim_left_impl(S &str, C const *trimChars)
#else /* ? compiler */
template<ss_typename_param_k S>
inline S &trim_left_impl(S &str, ss_typename_type_k string_traits<S>::char_type const *trimChars)
#endif /* compiler */
{
    // 1. 'use' the std namespace here, otherwise get totally clogged in stlsoft_ns_qual_std(XX)
#ifdef STLSOFT_CF_std_NAMESPACE
    using namespace std;
#endif /* STLSOFT_CF_std_NAMESPACE */
    // 2. typedef the string traits
    typedef string_traits<S>                                        string_traits_t;
    // 3. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type           char_t;
    // 4. typedef the iterator type(s)
    typedef ss_typename_type_k string_traits_t::iterator            iterator_t;
//    typedef ss_typename_type_k string_traits_t::reverse_iterator  reverse_iterator_t;
    // 5. Since ::stlsoft::strchr is an overloaded function, we disambiguate by casting to the type required
    char_t const *(*pfn)(char_t const *, char_t)   =   ::stlsoft::strchr;

    // Get an iterator to the first element that
    const iterator_t  it_b    =   str.begin();
    const iterator_t  it_e    =   str.end();
    const iterator_t  it_l    =   find_if(it_b, it_e, not1(bind1st(ptr_fun(pfn), trimChars)));
    const iterator_t  &it_r   =   it_e;

    return string_traits_t::assign_inplace(str, it_l, it_r);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief
 *
 * \ingroup group__library__string
 */
template<ss_typename_param_k S>
inline S &trim_left(S &str)
{
    // 1. typedef the string traits
    typedef string_traits<S>                                string_traits_t;

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    // This is needed here to tell the Borland compiler that it's a type!
    string_traits_t::char_type  *p  =   NULL;
# endif /* compiler */

    // 2. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type   char_t;

    ss_size_t       n;
    char_t const    *trimChars  =   default_trim_chars(static_cast<char_t const*>(0), n);

    STLSOFT_SUPPRESS_UNUSED(n);

    return trim_left_impl(str, trimChars);
}

/** \brief
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k S0
        ,   ss_typename_param_k S1
        >
inline S0 &trim_left(S0 &str, S1 const &trimChars)
{
    return trim_left_impl(str, stlsoft_ns_qual(c_str_ptr)(trimChars));
}



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(__BORLANDC__)
#  pragma warn -8091 // Otherwise BC++ complains that rbegin()/rend() returns passed to find_if() are output iterators
#  pragma warn -8092 // Otherwise BC++ complains that rbegin()/rend() returns passed to find_if() are not iterators
# endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &trim_right_impl(S &str, C const *trimChars)
#else /* ? compiler */
template<ss_typename_param_k S>
inline S &trim_right_impl(S &str, ss_typename_type_k string_traits<S>::char_type const *trimChars)
#endif /* compiler */
{
    // 1. 'use' the std namespace here, otherwise get totally clogged in stlsoft_ns_qual_std(XX)
#ifdef STLSOFT_CF_std_NAMESPACE
    using namespace std;
#endif /* STLSOFT_CF_std_NAMESPACE */
    // 2. typedef the string traits
    typedef string_traits<S>                                        string_traits_t;
    // 3. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type           char_t;
    // 4. typedef the iterator type(s)
    typedef ss_typename_type_k string_traits_t::iterator            iterator_t;
    typedef ss_typename_type_k string_traits_t::reverse_iterator    reverse_iterator_t;
    // 5. Since ::stlsoft::strchr is an overloaded function, we disambiguate by casting to the type required
    char_t const *(*pfn)(char_t const *, char_t)   =   ::stlsoft::strchr;

    // Get a (reverse) iterator to the first element that is not a space === find_last_not_of
    const iterator_t            it_b    =   str.begin();
//    const iterator_t            it_e    =   str.end();
    const iterator_t            it_l    =   it_b;
    const reverse_iterator_t    rit     =   find_if(str.rbegin(), str.rend(), not1(bind1st(ptr_fun(pfn), trimChars)));
    const iterator_t            it_r    =   rit.base();

    return string_traits_t::assign_inplace(str, it_l, it_r);
}

# if defined(__BORLANDC__)
#  pragma warn .8092
#  pragma warn .8091
# endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief
 *
 * \ingroup group__library__string
 */
template<ss_typename_param_k S>
inline S &trim_right(S &str)
{
    // 1. typedef the string traits
    typedef string_traits<S>                                string_traits_t;

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    // This is needed here to tell the Borland compiler that it's a type!
    string_traits_t::char_type  *p  =   NULL;
# endif /* compiler */

    // 2. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type   char_t;

    ss_size_t       n;
    char_t const    *trimChars  =   default_trim_chars(static_cast<char_t const*>(0), n);

    STLSOFT_SUPPRESS_UNUSED(n);

    return trim_right_impl(str, trimChars);
}

/** \brief
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k S0
        ,   ss_typename_param_k S1
        >
inline S0 &trim_right(S0 &str, S1 const &trimChars)
{
    return trim_right_impl(str, stlsoft_ns_qual(c_str_ptr)(trimChars));
}




#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(__BORLANDC__)
#  pragma warn -8091 // Otherwise BC++ complains that rbegin()/rend() returns passed to find_if() are output iterators
#  pragma warn -8092 // Otherwise BC++ complains that rbegin()/rend() returns passed to find_if() are not iterators
# endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &trim_all_impl(S &str, C const *trimChars)
#else /* ? compiler */
template<ss_typename_param_k S>
inline S &trim_all_impl(S &str, ss_typename_type_k string_traits<S>::char_type const *trimChars)
#endif /* compiler */
{
    // 1. 'use' the std namespace here, otherwise get totally clogged in stlsoft_ns_qual_std(XX)
#ifdef STLSOFT_CF_std_NAMESPACE
    using namespace std;
#endif /* STLSOFT_CF_std_NAMESPACE */
    // 2. typedef the string traits
    typedef string_traits<S>                                        string_traits_t;
    // 3. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type           char_t;
    // 4. typedef the iterator type(s)
    typedef ss_typename_type_k string_traits_t::iterator            iterator_t;
    typedef ss_typename_type_k string_traits_t::reverse_iterator    reverse_iterator_t;
    // 5. Since ::stlsoft::strchr is an overloaded function, we disambiguate by casting to the type required
    char_t const *(*pfn)(char_t const *, char_t)   =   ::stlsoft::strchr;

    // Get an iterator to the first element that
    const iterator_t            it_b    =   str.begin();
//    const iterator_t            it_e    =   str.end();
    const iterator_t            it_l    =   find_if(it_b, str.end(), not1(bind1st(ptr_fun(pfn), trimChars)));
    const reverse_iterator_t    rit     =   find_if(str.rbegin(), str.rend(), not1(bind1st(ptr_fun(pfn), trimChars)));
    const iterator_t            it_r    =   rit.base();

    return string_traits_t::assign_inplace(str, it_l, it_r);
}

# if defined(__BORLANDC__)
#  pragma warn .8092
#  pragma warn .8091
# endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief
 *
 * \ingroup group__library__string
 */
template<ss_typename_param_k S>
inline S &trim_all(S &str)
{
    // 1. typedef the string traits
    typedef string_traits<S>                                string_traits_t;

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    // This is needed here to tell the Borland compiler that it's a type!
    string_traits_t::char_type  *p  =   NULL;
# endif /* compiler */

    // 2. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type   char_t;

    ss_size_t       n;
    char_t const    *trimChars  =   default_trim_chars(static_cast<char_t const*>(0), n);

    STLSOFT_SUPPRESS_UNUSED(n);

    return trim_all_impl(str, trimChars);
}

/** \brief
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k S0
        ,   ss_typename_param_k S1
        >
inline S0 &trim_all(S0 &str, S1 const &trimChars)
{
    return trim_all_impl(str, stlsoft_ns_qual(c_str_ptr)(trimChars));
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &remove_all_impl(S &str, C const *removeChars)
#else /* ? compiler */
template<ss_typename_param_k S>
inline S &remove_all_impl(S &str, ss_typename_type_k S::value_type const *removeChars)
#endif /* compiler */
{
    // 1. 'use' the std namespace here, otherwise get totally clogged in stlsoft_ns_qual_std(XX)
#ifdef STLSOFT_CF_std_NAMESPACE
    using namespace std;
#endif /* STLSOFT_CF_std_NAMESPACE */
    // 2. typedef the string traits
    typedef string_traits<S>                                        string_traits_t;
    // 3. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type           char_t;
    // 4. typedef the iterator type(s)
    typedef ss_typename_type_k string_traits_t::iterator            iterator_t;
//    typedef ss_typename_type_k string_traits_t::reverse_iterator  reverse_iterator_t;
    // 5. Since ::stlsoft::strchr is an overloaded function, we disambiguate by casting to the type required
    char_t const *(*pfn)(char_t const *, char_t)   =   ::stlsoft::strchr;

    // Get an iterator to the first element that
    /* const */ iterator_t        it_b    =   str.begin();
//    const iterator_t        it_e    =   str.end();
    const iterator_t        it_l    =   it_b;
    const iterator_t        it_r    =   remove_if(it_b, str.end(), bind1st(ptr_fun(pfn), removeChars));

    return string_traits_t::assign_inplace(str, it_l, it_r);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief
 *
 * \ingroup group__library__string
 */
template<ss_typename_param_k S>
inline S &remove_all(S &str)
{
    // 1. typedef the string traits
    typedef string_traits<S>                                string_traits_t;

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    // This is needed here to tell the Borland compiler that it's a type!
    string_traits_t::char_type  *p  =   NULL;
# endif /* compiler */

    // 2. typedef the char_t
    typedef ss_typename_type_k string_traits_t::char_type   char_t;

    ss_size_t       n;
    char_t const    *removeChars    =   default_trim_chars(static_cast<char_t const*>(0), n);

    STLSOFT_SUPPRESS_UNUSED(n);

    return remove_all_impl(str, removeChars);
}

/** \brief
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k S0
        ,   ss_typename_param_k S1
        >
inline S0 &remove_all(S0 &str, S1 const &removeChars)
{
    return remove_all_impl(str, stlsoft_ns_qual(c_str_ptr)(removeChars));
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/trim_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_TRIM_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */