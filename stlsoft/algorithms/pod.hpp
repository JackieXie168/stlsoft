/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithms/pod.hpp (formerly in stlsoft_simple_algorithms.h)
 *
 * Purpose:     Algorithms for Plain-Old Data types.
 *
 * Created:     17th January 2002
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/algorithms/pod.hpp
///
/// Contains various simple self-contained algorithms.

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD
#define STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_POD_MAJOR       3
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_POD_MINOR       2
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_POD_REVISION    1
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_POD_EDIT        68
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM
# include <stlsoft/util/std/algorithm.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM */
#if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
# ifndef STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS
#  include <stlsoft/type_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS */
# ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
#  include <stlsoft/constraints.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    defined(STLSOFT_COMPILER_IS_INTEL) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
# include <memory.h>                    // memcpy
#else /* ? compiler */
# include <string.h>                    // memcpy
#endif /* compiler */

#ifdef STLSOFT_UNITTEST
# ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
#  include <stlsoft/exceptions.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup algorithms Algorithms
/// \brief STL-compatible algorithms

/// \weakgroup utilities Utilities
/// \brief Utility functions and constructs used throughout the STLSoft libraries

/// \weakgroup pod_algorithms POD Algorithms
/// \brief Algorithms for manipulating POD types 
/// \ingroup algorithms
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Algorithms
 */

/** Copies one range of POD (Plain Old Data) entities to another
 *
 * This algorithm has the same semantics as std::copy(), but it uses
 * ::memcpy() to copy elements en bloc, rather than copy assignment of one element
 * at a time.
 *
 * \htmlonly
 * <pre>
 * const int8_t  src_bytes[3] = { -1, 0, +1 };
 * int8_t        dest_bytes[3];
 * 
 * pod_copy(&src_bytes[0], &src_bytes[0] + STLSOFT_NUM_ELEMENTS(src_bytes), &dest_bytes[0]);
 * assert(0 == memcmp(&src_bytes[0], &dest_bytes[0], sizeof(src_bytes)));
 * 
 * </pre>
 * \endhtmlonly
 *
 * \note The implementation uses static assertions to ensure that the source and
 * destination element types are the same size.
 *
 * \note The implementation uses constraints ensure sure that the source and
 * destination element types are POD
 *
 * \param first Contiguous Iterator marking the start of the source range
 * \param last Contiguous Iterator marking the one-past-the-end of the source range
 * \param dest Contiguous Iterator marking the start of the source range
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline void pod_copy(I *first, I *last, O *dest)
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    std_copy(&first[0], &last[0], &dest[0]);
#else /* ? compiler */
    STLSOFT_STATIC_ASSERT(sizeof(*dest) == sizeof(*first));
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
        // Both must be non-pointers, or must point to POD types
    typedef ss_typename_type_k base_type_traits<I>::base_type   i_base_type;
    typedef ss_typename_type_k base_type_traits<O>::base_type   o_base_type;

    stlsoft_constraint_must_be_pod(i_base_type);
    stlsoft_constraint_must_be_pod(o_base_type);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    ss_size_t n = static_cast<ss_size_t>(last - first);

    if(0 != n)
    {
        ::memcpy(&dest[0], &first[0], n * sizeof(*first));
    }
#endif /* compiler */
}

/** Copies one range of POD (Plain Old Data) entities to another
 *
 * This algorithm uses ::memcpy() to copy elements en bloc, rather than
 * copy assignment of one element at a time.
 *
 * \htmlonly
 * <pre>
 * const int8_t  src_bytes[3] = { -1, 0, +1 };
 * int8_t        dest_bytes[3];
 * 
 * pod_copy_n(&dest_bytes[0], &src_bytes[0], STLSOFT_NUM_ELEMENTS(src_bytes));
 * assert(0 == memcmp(&src_bytes[0], &dest_bytes[0], sizeof(src_bytes)));
 * 
 * </pre>
 * \endhtmlonly
 *
 * \note The implementation uses static assertions to ensure that the source and
 * destination element types are the same size.
 *
 * \note The implementation uses constraints ensure sure that the source and
 * destination element types are POD
 *
 * \param dest Contiguous Iterator marking the start of the source range
 * \param src Contiguous Iterator marking the start of the source range
 * \param n Number of elements in the range
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline void pod_copy_n(O *dest, I *src, ss_size_t n)
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    std_copy(&src[0], &src[n], &dest[0]);
#else /* ? compiler */
    STLSOFT_STATIC_ASSERT(sizeof(*dest) == sizeof(*src));
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
        // Both must be non-pointers, or must point to POD types
    typedef ss_typename_type_k base_type_traits<I>::base_type   i_base_type;
    typedef ss_typename_type_k base_type_traits<O>::base_type   o_base_type;

    stlsoft_constraint_must_be_pod(i_base_type);
    stlsoft_constraint_must_be_pod(o_base_type);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    if(0 != n)
    {
        ::memcpy(&dest[0], &src[0], n * sizeof(*dest));
    }
#endif /* compiler */
}

/** Copies one range of POD (Plain Old Data) entities to another, where the two
 * may potentially overlap
 *
 * This algorithm has the same semantics as std::copy(), but it uses
 * ::memmove() to copy elements en bloc, rather than copy assignment of one element
 * at a time.
 *
 * \note The implementation uses static assertions to ensure that the source and
 * destination element types are the same size.
 *
 * \note The implementation uses constraints ensure sure that the source and
 * destination element types are POD
 *
 * \param first Contiguous Iterator marking the start of the source range
 * \param last Contiguous Iterator marking the one-past-the-end of the source range
 * \param dest Contiguous Iterator marking the start of the source range
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline void pod_move(I *first, I *last, O *dest)
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    std_copy(&first[0], &last[0], &dest[0]);
#else /* ? compiler */
    STLSOFT_STATIC_ASSERT(sizeof(*first) == sizeof(*dest));
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
        // Both must be non-pointers, or must point to POD types
    typedef ss_typename_type_k base_type_traits<I>::base_type   i_base_type;
    typedef ss_typename_type_k base_type_traits<O>::base_type   o_base_type;

    stlsoft_constraint_must_be_pod(i_base_type);
    stlsoft_constraint_must_be_pod(o_base_type);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    ss_size_t n = static_cast<ss_size_t>(last - first);

    if(0 != n)
    {
        ::memmove(dest, first, n * sizeof(*first));
    }
#endif /* compiler */
}

/** Copies one range of POD (Plain Old Data) entities to another, where the two
 * may potentially overlap
 *
 * \note This algorithm uses ::memmove() to copy elements en bloc, rather than
 * copy assignment of one element at a time.
 *
 * \note The implementation uses static assertions to ensure that the source and
 * destination element types are the same size.
 *
 * \note The implementation uses constraints ensure sure that the source and
 * destination element types are POD
 *
 * \param dest Contiguous Iterator marking the start of the source range
 * \param src Contiguous Iterator marking the start of the source range
 * \param n Number of elements in the range
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline void pod_move_n(O *dest, I *src, ss_size_t n)
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    std_copy(&src[0], &src[n], &dest[0]);
#else /* ? compiler */
    STLSOFT_STATIC_ASSERT(sizeof(*dest) == sizeof(*src));
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
        // Both must be non-pointers, or must point to POD types
    typedef ss_typename_type_k base_type_traits<I>::base_type   i_base_type;
    typedef ss_typename_type_k base_type_traits<O>::base_type   o_base_type;

    stlsoft_constraint_must_be_pod(i_base_type);
    stlsoft_constraint_must_be_pod(o_base_type);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    if(0 != n)
    {
        ::memmove(&dest[0], &src[0], n * sizeof(*dest));
    }
#endif /* compiler */
}


/** Sets all the elements in a range of POD (Plain Old Data) to a given value
 *
 * This algorithm has the same semantics as std::fill_n(), but it uses
 * ::memset() for some types to set the range of elements, rather than copy
 * assignment of one element at a time.
 *
 * \htmlonly
 * <pre>
 * const int8_t  src_bytes[3] = { 3, 3, 3 };
 * int8_t        dest_bytes[3];
 * 
 * pod_fill_n(&dest_bytes[0], STLSOFT_NUM_ELEMENTS(src_bytes), 3);
 * assert(0 == memcmp(&src_bytes[0], &dest_bytes[0], sizeof(src_bytes)));
 * 
 * </pre>
 * \endhtmlonly
 *
 * The generic overload uses std::fill_n(), so performance is likely to be
 * identical to std::fill_n() in the general case. However, it is overloaded
 * to use ::memset() on \c char, \c signed \c char and \c unsigned \c char
 * types, for which performance gains are likely.
 *
 * \param dest Contiguous Iterator marking the start of the source range
 * \param n Number of elements in the range
 * \param value Value to which each element in dest[0, n) will be set
 */
template<   ss_typename_param_k T
        ,   ss_typename_param_k V
        >
inline void pod_fill_n(T *dest, ss_size_t n, V const &value)
{
    // Constrain to POD type:
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
    typedef ss_typename_type_k base_type_traits<T>::base_type   base_type;

    stlsoft_constraint_must_be_pod(base_type);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    std_fill_n(dest, n, value);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline void pod_fill_n(char *dest, ss_size_t n, int value)
{
    ::memset(dest, value, n);
}
inline void pod_fill_n(signed char *dest, ss_size_t n, int value)
{
    ::memset(dest, value, n);
}
inline void pod_fill_n(unsigned char *dest, ss_size_t n, int value)
{
    ::memset(dest, value, n);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////

/// @} // end of group pod_algorithms

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/pod_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD */

/* ////////////////////////////////////////////////////////////////////////// */
