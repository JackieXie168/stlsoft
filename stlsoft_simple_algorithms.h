/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_simple_algorithms.h
 *
 * Purpose:     Contains various simple self-contained algorithms.
 *
 * Created:     17th January 2002
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft_simple_algorithms.h
///
/// Contains various simple self-contained algorithms.

#ifndef STLSOFT_INCL_H_STLSOFT_SIMPLE_ALGORITHMS
#define STLSOFT_INCL_H_STLSOFT_SIMPLE_ALGORITHMS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_SIMPLE_ALGORITHMS_MAJOR      2
# define STLSOFT_VER_H_STLSOFT_SIMPLE_ALGORITHMS_MINOR      4
# define STLSOFT_VER_H_STLSOFT_SIMPLE_ALGORITHMS_REVISION   1
# define STLSOFT_VER_H_STLSOFT_SIMPLE_ALGORITHMS_EDIT       70
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM
# include <stlsoft/util/std/algorithm.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ALGORITHM */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

/** \brief \weakgroup algorithms Algorithms
 * \brief STL-compatible algorithms
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */

/** \brief \weakgroup utilities Utilities
 * \brief Utility functions and constructs used throughout the STLSoft libraries
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */

/** \brief \weakgroup simple_algorithms Simple Algorithms
 * \brief Algorithms for manipulating types
 * \ingroup algorithms utilities
 * @{
 */

/* /////////////////////////////////////////////////////////////////////////
 * Algorithms
 */

// function for_each_if

/** \brief Applies the function to all items in the series for which the predicate is
 * true.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param first The start of the sequence
 * \param last The (one past the) end of the sequence
 * \param func The function to be applied to each element in the range [first, last) if \c pred evaluates to true
 * \param pred The predicate which is applied to each element in the range to determine whether \c func should be applied
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        ,   ss_typename_param_k P
        >
inline F for_each_if(I first, I last, F func, P pred)
{
    for(; first != last; ++first)
    {
        if(pred(*first))
        {
            func(*first);
        }
    }

    return func;
}

// function for_each_count_success

/** \brief Counts the number of items in the sequence which the predicate is true.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \note This function is identical in semantics to std::count_if(). If you are
 * compiling in the context of a standard compliant library, you should prefer
 * std::count_if().
 *
 * \param first The start of the range to count
 * \param to The end of the range to count
 * \param pred The predicate
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k P
        >
inline ss_size_t for_each_count_success(I first, I to, P pred)
{
    return std_count_if(first, to, pred);
}


// function for_each_set_value

/** \brief Sets the value of all items in the sequence.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \note This function is identical in semantics to std::fill(), except that
 * it returns the value. If you are compiling in the context of a standard
 * compliant library, and do not need the value returned, you should prefer
 * std::fill().
 *
 * \param begin The start of the sequence
 * \param end The end of the sequence
 * \param v The value to be applied to item N, for each N in [begin, end)
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k V
        >
inline V const &for_each_set_value(I begin, I end, V const &v)
{
    std_fill(begin, end);

    return v;
}


// function fill_if

/** \brief Sets the value of all items in the sequence.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param begin The start of the sequence
 * \param end The end of the sequence
 * \param v The value to be applied to item N, for each N in [begin, end), when <code>pred(*(begin + N))</code> evaluates non-zero
 * \param pred The predicate that determines whether the value is to be modified
 */
template<   ss_typename_param_k O
        ,   ss_typename_param_k V
        ,   ss_typename_param_k P
        >
inline void fill_if(O begin, O end, V const &v, P pred)
{
    for(; begin != end; ++begin)
    {
        if(pred(*begin))
        {
            *begin = v;
        }
    }
}


// function for_each_set_value_if

/** \brief Sets the value of all items in the sequence.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \deprecated This is the old name for fill_if().
 *
 * \param begin The start of the sequence
 * \param end The end of the sequence
 * \param v The value to be applied to item N, for each N in [begin, end), when <code>pred(*(begin + N))</code> evaluates non-zero
 * \param pred The predicate that determines whether the value is to be modified
 */
template<   ss_typename_param_k O
        ,   ss_typename_param_k V
        ,   ss_typename_param_k P
        >
inline V const &for_each_set_value_if(O begin, O end, V const &v, P pred)
{
    fill_if(begin, end, v, pred);

    return v;
}


// function remove_duplicates_from_unordered_sequence

/** \brief This algorithm removes duplicate entries from unordered sequences. It
 * necessarily runs in O(n) time, since it must do a bubble-like double
 * pass on the sequence (in order to work with unordered sequences).
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param container The container
 * \param pred The predicate
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k P
        >
inline void remove_duplicates_from_unordered_sequence(C &container, P pred)
{
    typedef ss_typename_type_k C::iterator  iterator_t;

#if 0
    for(iterator_t begin = container.begin(); begin != container.end(); ++begin)
    {
        iterator_t it = begin;

        for(++it; it != container.end(); ++it)
        {
            if(pred(*begin, *it))
            {
                //
                container.erase(it);
                it = begin;
            }
        }
    }
#endif /* 0 */

    ss_size_t   last;
    ss_size_t   index;
    iterator_t  begin;

    for(index = 0, last = 0, begin = container.begin(); begin != container.end(); )
    {
        iterator_t  it  =   begin;
        iterator_t  end =   container.end();

        if(++it == end)
        {
            ++begin;
        }
        else
        {
            for(;;)
            {
                if(pred(*begin, *it))
                {
                    // Erase the element. We now assume that all iterators
                    // are invalidated
                    container.erase(it);
                    // Remember the last erasure point
                    last = index;
                    // Set begin back to the start of the sequence
                    begin = container.begin();
                    // Move begin to the point where it was at the last erasure
                    std_advance(begin, static_cast<ss_ptrdiff_t>(last)); // Need to cast so that RAI impl doesn't incur impl conv from unsigned to signed in i += n;
                    break;
                }
                else
                {
                    if(++it == end)
                    {
                        ++begin;
                        ++index;
                        break;
                    }
                }
            }
        }
    }

    // Borland seems to think that 'last' is not used, when it clearly is.
    STLSOFT_SUPPRESS_UNUSED(last);
}


// function fill_all
/** \brief Carries out for_each on the range of items in a container
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param c The container
 * \param v The value to set to each element in the container
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k V
        >
inline void fill_all(C &c, V const &v)
{
    fill(c.begin(), c.end(), v);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
// function fill_all
/** \brief Carries out for_each on the range of items in an array
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param ar The array
 * \param v The value to set to each element in the array
 */
template<   ss_typename_param_k T
        ,   ss_size_t           N
        ,   ss_typename_param_k V
        >
inline void fill_all(T (&ar)[N], V const &v)
{
    fill(&ar[0], &ar[N], v);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */



// function for_all
/** \brief Carries out for_each on the range of items in a container
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param c The container
 * \param f The function
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k F
        >
inline F for_all(C &c, F f)
{
    return std_for_each(c.begin(), c.end(), f);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
// function for_all
/** \brief Carries out for_each on the range of items in an array
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param ar The array
 * \param f The function
 */
template<   ss_typename_param_k T
        ,   ss_size_t           N
        ,   ss_typename_param_k F
        >
inline F for_all(T (&ar)[N], F f)
{
    return std_for_each(&ar[0], &ar[N], f);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */



// function for_all_r
/** \brief Carries out for_each on the reverse range of items in a container
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param c The container
 * \param f The function
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k F
        >
inline F for_all_r(C &c, F f)
{
    return std_for_each(c.rbegin(), c.rend(), f);
}



// function copy_all
/** \brief Carries out copy on all the items in a container
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param c The container
 * \param o The output iterator
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k O
        >
inline O copy_all(C &c, O o)
{
    return std_copy(c.begin(), c.end(), o);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
// function for_all
/** \brief Carries out copy on the range of items in an array
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param ar The array
 * \param o The output iterator
 */
template<   ss_typename_param_k T
        ,   ss_size_t           N
        ,   ss_typename_param_k O
        >
inline O copy_all(T (&ar)[N], O o)
{
    return std_copy(&ar[0], &ar[N], o);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */



// function for_each_preinc
/** \brief Carries out for_each on the range, using pre-increment on the iterator
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param first The start of the sequence
 * \param last The end of the sequence
 * \param f The function
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline F for_each_preinc(I first, I last, F f)
{
    for(; first != last; ++first)
    {
        f(*first);
    }

    return f;
}


// function for_each_postinc
/** \brief Carries out for_each on the range, using post-increment on the iterator
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param first The start of the sequence
 * \param last The end of the sequence
 * \param f The function
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k F
        >
inline F for_each_postinc(I first, I last, F f)
{
    for(; first != last; first++)
    {
        f(*first);
    }

    return f;
}

////////////////////////////////////////////////////////////////////////////

/** \brief @} // end of group simple_algorithms
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_simple_algorithms(unittest_reporter *r)
        {
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
            using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "simple_algorithms", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_simple_algorithms(test_stlsoft_simple_algorithms);
    } // anonymous namespace

} /* namespace unittest */

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_SIMPLE_ALGORITHMS */

/* ////////////////////////////////////////////////////////////////////// */
