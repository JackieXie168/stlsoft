/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithms.hpp
 *
 * Purpose:     Contains various simple self-contained algorithms.
 *
 * Created:     23rd October 2004
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/algorithms.hpp
///
/// Contains various simple self-contained algorithms.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ALGORITHMS
#define STLSOFT_INCL_STLSOFT_HPP_ALGORITHMS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ALGORITHMS_MAJOR       1
# define STLSOFT_VER_STLSOFT_HPP_ALGORITHMS_MINOR       6
# define STLSOFT_VER_STLSOFT_HPP_ALGORITHMS_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_ALGORITHMS_EDIT        24
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
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM
# include <stlsoft/util/std/algorithm.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM */
#ifdef STLSOFT_CF_std_NAMESPACE
# include <iterator>        // for the iterator tags
# include <utility>         // for std::pair
#endif /* STLSOFT_CF_std_NAMESPACE */

#ifdef STLSOFT_UNITTEST
# include <string.h>        // for strcmp()
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Algorithms
 */

// function copy_n

/// Copies N elements from the range [src, src + n) to the range
/// [dest, dest + n).
///
/// \param src The iterator copied from
/// \param n The number of elements copied
/// \param dest The iterator copied to
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline O copy_n(I src, ss_size_t n, O dest)
{
    for(; n != 0; ++src, ++dest, --n)
    {
        *dest = *src;
    }

    return dest;
}

// function copy_if

/// Copies N elements from the range [src, src + n) to the range
/// [dest, dest + n).
///
/// \param first The start of the (unordered) sequence
/// \param last The (one past the) end point of the sequence
/// \param dest The output iterator to which the copies are written
/// \param pr The predicate
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        ,   ss_typename_param_k P
        >
inline O copy_if(I first, I last, O dest, P pr)
{
    for(; first != last; ++first)
    {
        if(pr(*first))
        {
            *dest++ = *first;
        }
    }

    return dest;
}

// function skip_equal

/// Skips along from a given iteration point to the first subsequent
/// iteration point whose value is not equal to that of the starting
/// point
///
/// \param first The start of the sequence
/// \param last The (one past the) end point of the sequence
template<ss_typename_param_k I>
inline I skip_equal(I first, I last)
{
    if(first == last)
    {
        return last;
    }
    else
    {
        for(I next = first; next != last; ++next)
        {
            if(*next != *first)
            {
                return next;
            }
        }

        return last;
    }
}

#ifdef STLSOFT_CF_std_NAMESPACE
// function find_first_duplicate

/// Finds the first duplicate item in the unordered sequence [first, last)
/// If a duplicate is found, the return value is a pair of the iterators
/// referring to the first and second elements comprising the duplicate.
/// If no duplicate is found, the return value is a pair containing the
/// \c last iterator in both its members
///
/// \param first The start of the (unordered) sequence
/// \param last The (one past the) end point of the sequence
///
/// \note This algorithm works for ordered sequences, but \c std::adjacent_find
/// is more suitable for such cases
template<ss_typename_param_k I>
#if defined(STLSOFT_COMPILER_IS_DMC) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
inline stlsoft_ns_qual_std_(pair)<I, I> find_first_duplicate(I first, I last)
#else /* ? compiler */
inline stlsoft_ns_qual_std(pair)<I, I> find_first_duplicate(I first, I last)
#endif /* compiler */
{
    for(; first != last; ++first)
    {
        I next = first;

        for(++next; next != last; ++next)
        {
            if(*next == *first)
            {
                return stlsoft_ns_qual_std(make_pair)(first, next);
            }
        }
    }

    return stlsoft_ns_qual_std(make_pair)(last, last);
}

template<   ss_typename_param_k I
        ,   ss_typename_param_k P
        >
#if defined(STLSOFT_COMPILER_IS_DMC) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
inline stlsoft_ns_qual_std_(pair)<I, I> find_first_duplicate(I first, I last, P pr)
#else /* ? compiler */
inline stlsoft_ns_qual_std(pair)<I, I> find_first_duplicate(I first, I last, P pr)
#endif /* compiler */
{
    for(; first != last; ++first)
    {
        I next = first;

        for(++next; next != last; ++next)
        {
            if(pr(*next, *first))
            {
                return stlsoft_ns_qual_std(make_pair)(first, next);
            }
        }
    }

    return stlsoft_ns_qual_std(make_pair)(last, last);
}

#endif /* STLSOFT_CF_std_NAMESPACE */

// function replace_n

/// Copies N elements from the range [src, src + n) to the range
/// [dest, dest + n).
///
/// \param from The iterator copied from
/// \param n The number of elements copied
/// \param oldValue The existing value to search for
/// \param newValue The existing value with which oldValue will be replaced
template<   ss_typename_param_k I
        ,   ss_typename_param_k T
        >
inline void replace_n(I from, ss_size_t n, T const &oldValue, T const &newValue)
{
#if 0
    std_replace(from, from + n, oldValue, newValue);
#else /* ? 0 */
    for(; 0 != n; ++from, --n)
    {
        if(oldValue == *from)
        {
            *from = newValue;
        }
    }
#endif /* 0 */
}

/** Determines whether all elements from the range [first2, last2) are
 * contained within the range [first1, last1)
 *
 * \note The algorithm does <i>not</i> assume that the ranges are ordered, and
 * so does linear searches. If the ranges are ordered, you should use \c std::includes
 */
template<   ss_typename_param_k I1
        ,   ss_typename_param_k I2
        >
inline ss_bool_t unordered_includes(I1 first1, I1 last1, I2 first2, I2 last2)
{
    for(; first2 != last2; ++first2)
    {
        ss_bool_t   bFound  =   false;

        for(I1 i1 = first1; i1 != last1; ++i1)
        {
            if(*first2 == *i1)
            {
                bFound = true;
                break;
            }
        }

        if(!bFound)
        {
            return false;
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_stlsoft_algorithms__copy_n(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            char        src[]   =   "abcdefghijklm";
            char        dest[]  =   "~~~~~~~~~~~~~";

            // 1. n == 0

            copy_n(src, 0, dest);

            if(dest[0] != '~')
            {
                r->report("copy_n() failed for n == 0", __LINE__);
                bSuccess = false;
            }

            // 2. n == 1

            copy_n(src, 1, dest);

            if( dest[0] != 'a' ||
                dest[1] != '~')
            {
                r->report("copy_n() failed for n == 1", __LINE__);
                bSuccess = false;
            }

            // 3. all n

            copy_n(src, sizeof(src), dest);

            if(0 != strcmp(dest, dest))
            {
                r->report("copy_n() failed for all n", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__copy_n_pr(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__copy_if(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__copy_if_pr(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__skip_equal(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__skip_equal_pr(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__find_first_duplicate(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            const char  r1[]        =   "abcdefghfijklm";
            const char  r2[]        =   "abcdefghijklmn";

            typedef stlsoft_ns_qual_std(pair)<char const*, char const*> char_pair_t;

            char_pair_t p1  =   find_first_duplicate(&r1[0], &r1[0] + STLSOFT_NUM_ELEMENTS(r1) - 1);

            if( p1.first == &r1[0] + STLSOFT_NUM_ELEMENTS(r1) - 1 ||
                p1.second == &r1[0] + STLSOFT_NUM_ELEMENTS(r1) - 1)
            {
                r->report("find_first_duplicate() failed for not finding duplicates within \"abcdefghfijklm\"", __LINE__);
                bSuccess = false;
            }
            else if(*p1.first != *p1.second)
            {
                r->report("find_first_duplicate() failed for reporting wrong duplicates within \"abcdefghfijklm\"", __LINE__);
                bSuccess = false;
            }

            char_pair_t p2  =   find_first_duplicate(&r2[0], &r2[0] + STLSOFT_NUM_ELEMENTS(r1) - 1);

            if( p2.first != &r2[0] + STLSOFT_NUM_ELEMENTS(r2) - 1 ||
                p2.second != &r2[0] + STLSOFT_NUM_ELEMENTS(r2) - 1)
            {
                r->report("find_first_duplicate() failed for finding duplicates within \"abcdefghijklmn\"", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__find_first_duplicate_pr(unittest_reporter * /* r */)
        {
            ss_bool_t   bSuccess    =   true;

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms__unordered_includes(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            const char  r1[]        =   "abcdefgh";
            const char  r2[]        =   "deadbeaf";

            if(!unordered_includes(&r1[0], &r1[0] + STLSOFT_NUM_ELEMENTS(r1) - 1, &r2[0], &r2[0] + STLSOFT_NUM_ELEMENTS(r1) - 1))
            {
                r->report("unordered_includes() failed for not finding \"deadbeaf\" within \"abcdefgh\"", __LINE__);
                bSuccess = false;
            }

            if(unordered_includes(&r2[0], &r2[0] + STLSOFT_NUM_ELEMENTS(r1) - 1, &r1[0], &r1[0] + STLSOFT_NUM_ELEMENTS(r1) - 1))
            {
                r->report("unordered_includes() failed for finding \"abcdefgh\" within \"deadbeaf\"", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_stlsoft_algorithms(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "stlsoft/algorithms", __FILE__);

            if(!test_stlsoft_stlsoft_algorithms__copy_n(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__copy_n_pr(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__copy_if(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__copy_if_pr(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__skip_equal(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__skip_equal_pr(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__find_first_duplicate(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__find_first_duplicate_pr(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_stlsoft_algorithms__unordered_includes(r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_stlsoft_algorithms(test_stlsoft_stlsoft_algorithms);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALGORITHMS */

/* ////////////////////////////////////////////////////////////////////// */
