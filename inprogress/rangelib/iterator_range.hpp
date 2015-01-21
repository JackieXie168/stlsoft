/* /////////////////////////////////////////////////////////////////////////////
 * File:        rangelib/iterator_range.hpp
 *
 * Purpose:     Iterator range adaptor.
 *
 * Created:     4th November 2003
 * Updated:     13th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/** \file rangelib/iterator_range.hpp Iterator range adaptor */

#ifndef STLSOFT_INCL_RANGELIB_HPP_ITERATOR_RANGE
#define STLSOFT_INCL_RANGELIB_HPP_ITERATOR_RANGE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_RANGELIB_HPP_ITERATOR_RANGE_MAJOR    2
# define STLSOFT_VER_RANGELIB_HPP_ITERATOR_RANGE_MINOR    2
# define STLSOFT_VER_RANGELIB_HPP_ITERATOR_RANGE_REVISION 4
# define STLSOFT_VER_RANGELIB_HPP_ITERATOR_RANGE_EDIT     21
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
[Incompatibilies-start]
STLSOFT_COMPILER_IS_BORLAND:
STLSOFT_COMPILER_IS_GCC:     __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 4)
STLSOFT_COMPILER_IS_MSVC:     _MSC_VER < 1200
STLSOFT_COMPILER_IS_MWERKS:   (__MWERKS__ & 0xFF00) < 0x3000
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGELIB
# include <rangelib/rangelib.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGELIB */
#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES
# include <rangelib/range_categories.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES */
#ifndef STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL
# include <stlsoft/operator_bool.hpp> //
#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_META
# include <stlsoft/meta.hpp>  //
#endif /* !STLSOFT_INCL_STLSOFT_HPP_META */
#ifndef STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS
# include <stlsoft/type_traits.hpp>   //
#endif /* !STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>   //
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

#ifdef STLSOFT_UNITTEST
# include <algorithm>
# include <deque>
# include <list>
# include <numeric>
# include <vector>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::rangelib */
namespace rangelib
{
# else
/* Define stlsoft::rangelib_project */

namespace stlsoft
{

namespace rangelib_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \defgroup rangelib_adaptors Range Adaptors
/// \ingroup rangelib
/// \brief Range Adaptors
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

/// Traits class for determining the attributes of range-adapted iterator types
template<   ss_typename_param_k I
        ,   bool                B_CONST
        >
struct iterator_range_traits
{
public:
    /// The iterator type
    typedef I                                                                           iterator_type;
    /// The value type
    typedef ss_typename_type_k I::value_type                                            value_type;
private:
#ifdef STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT
    // Use the iterator itself to determine whether the iterator is const
    enum { IS_CONST = base_type_traits<value_type>::is_const };
#else /* ? STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT */
    // 1. Use iterator_traits ...
    typedef std::iterator_traits<I>                                                     traits_type_;
    // ... to get the pointer type ...
    typedef ss_typename_type_k traits_type_::pointer                                    pointer_type_;
    // ... to determine whether the iterator is const
    enum { IS_CONST = base_type_traits<pointer_type_>::is_const };
#endif /* !STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT */
    // 2. Use Determine the base type of the value_type, which may then be used to create a reference of the appropriate type
    typedef ss_typename_type_k base_type_traits<value_type>::base_type                  base_value_type;
//  enum { IS_CONST = is_const<pointer>::value };
public:
    /// The mutating (non-const) iterator type
    typedef I                                                                           iterator;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k base_type_traits<iterator>::base_type const              &const_iterator;
    /// The mutating (non-const) refernce type
    typedef ss_typename_type_k select_first_type_if<   base_value_type const &
                                                ,   base_value_type &, IS_CONST>::type  reference;
    /// The non-mutating (const) reference type
    typedef base_value_type const                                                       &const_reference;
// TODO: Stick in the member-finder stuff here, so can assume ptrdiff_t if none found
    /// The difference type
    typedef ss_typename_type_k iterator_type::difference_type                           difference_type;
    /// The size type
    typedef ss_typename_type_k iterator_type::size_type                                 size_type;
};

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k T
        ,   bool                B_CONST
        >
struct iterator_range_traits<T*, B_CONST>
{
    typedef T                   value_type;
    typedef value_type          *iterator;
    typedef value_type const    *const_iterator;
    typedef value_type          &reference;
    typedef value_type const    &const_reference;
};

template<   ss_typename_param_k T
        ,   bool                B_CONST
        >
struct iterator_range_traits<T const*, B_CONST>
{
    typedef T                   value_type;
    typedef value_type const    *iterator;
    typedef value_type const    *const_iterator;
    typedef value_type const    &reference;
    typedef value_type const    &const_reference;
};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

template<   ss_typename_param_k I
        >
struct iterator_range_traits
{
public:
    typedef I                                                       iterator_type;
    typedef ss_typename_type_k iterator_type::value_type            value_type;
    typedef ss_typename_type_k iterator_type::iterator              iterator;
    typedef ss_typename_type_k iterator_type::const_iterator        const_iterator;
    typedef ss_typename_type_k iterator_type::reference             reference;
    typedef ss_typename_type_k iterator_type::const_reference       const_reference;
// TODO: Stick in the member-finder stuff here, so can assume ptrdiff_t if none found
    typedef ss_typename_type_k iterator_type::difference_type       difference_type;
    typedef ss_typename_type_k iterator_type::size_type             size_type;
};

template<   ss_typename_param_k I
        >
struct const_iterator_range_traits
{
public:
    typedef I                                                       iterator_type;
    typedef ss_typename_type_k iterator_type::value_type            value_type;
    typedef ss_typename_type_k iterator_type::const_iterator        iterator;
    typedef ss_typename_type_k iterator_type::const_iterator        const_iterator;
    typedef ss_typename_type_k iterator_type::const_reference       reference;
    typedef ss_typename_type_k iterator_type::const_reference       const_reference;
    typedef ss_typename_type_k iterator_type::difference_type       difference_type;
    typedef ss_typename_type_k iterator_type::size_type             size_type;
};

template<   ss_typename_param_k T
        >
struct pointer_iterator_range_traits
{
    typedef T                                                       value_type;
    typedef T                                                       *iterator;
    typedef T const                                                 *const_iterator;
    typedef T                                                       &reference;
    typedef T const                                                 &const_reference;
    typedef ptrdiff_t                                               difference_type;
    typedef size_t                                                  size_type;
};

template<   ss_typename_param_k T
        >
struct const_pointer_iterator_range_traits
{
    typedef T                                                       value_type;
    typedef T const                                                 *iterator;
    typedef T const                                                 *const_iterator;
    typedef T const                                                 &reference;
    typedef T const                                                 &const_reference;
    typedef ptrdiff_t                                               difference_type;
    typedef size_t                                                  size_type;
};

#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */


/// \brief This class adapts an iterator pair into a Range
///
/// \param I The iterator type
/// \param T The iterator range traits, used to deduce the Range's iterator, const_iterator, reference, const_reference and value_type
///
/// It is categoried as an Iterable Range
///
/// It could be used as follows
/// \htmlonly
/// <code>
/// <pre>
/// template&lt;typename I&gt;
/// void dump_elements(I from, I to)
/// {
///   for(iterator_range&lt;I&gt; r(from, to); r; ++r)
///   {
///     std::cout &lt;&lt; &r; // Dump the current value to stdout
///   }
/// }
/// </pre>
/// </code>
/// \endhtmlonly
template<   ss_typename_param_k I
#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
        ,   ss_typename_param_k T = iterator_range_traits<I, is_const<I>::value>    // Determines whether the iterator is const
#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
        ,   ss_typename_param_k T
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
        >
class iterator_range
    : public iterable_range_tag
{
public:
    /// The iterator type
    typedef I                                                       iterator_type;
    /// The traits type
    typedef T                                                       traits_type;
    /// The range tag type
    typedef iterable_range_tag                                      range_tag_type;
    /// The current instantiation of this type
    typedef iterator_range<I, T>                                    class_type;
    /// The value type
    typedef ss_typename_type_k traits_type::value_type              value_type;
    /// The mutating (non-const) iterator type
    typedef ss_typename_type_k traits_type::iterator                iterator;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k traits_type::const_iterator          const_iterator;
    /// The mutating (non-const) refernce type
    typedef ss_typename_type_k traits_type::reference               reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k traits_type::const_reference         const_reference;

public:
#if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER == 1200)
    /// Constructs from an iterator pair
    iterator_range(iterator first, iterator last)
        : m_position(first)
        , m_last(last)
    {}
#endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER != 1200)
    /// Constructs from an iterator pair
    template <ss_typename_param_k I2>
    iterator_range(I2 first, I2 last)
        : m_position(first)
        , m_last(last)
    {}
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

#ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
    /// Constructs from an array
    template <ss_typename_param_k T2, ss_size_t N>
    iterator_range(T2 (&ar)[N])
        : m_position(&ar[0])
        , m_last(&ar[N])
    {}
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/// \name Notional Range methods
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, boolean_generator_type, boolean_type);
public:
    /// Indicates whether the range is open
    ss_bool_t is_open() const
    {
        return m_position != m_last;
    }
    /// Returns the current value in the range
    reference current()
    {
        STLSOFT_ASSERT(is_open());

        return *m_position;
    }
    /// Returns the current value in the range
    const_reference current() const
    {
        STLSOFT_ASSERT(is_open());

        return *m_position;
    }

    /// Indicates whether the range is open
    operator boolean_type() const
    {
        return boolean_generator_type::translate(is_open());
    }
    /// Returns the current value in the range
    reference operator *()
    {
        return current();
    }
    /// Returns the current value in the range
    const_reference operator *() const
    {
        return current();
    }

    /// Advances the current position in the range
    class_type &advance()
    {
        STLSOFT_MESSAGE_ASSERT("Attempting to increment the range past its end point", is_open());

        ++m_position;

        return *this;
    }
    /// Advances the current position in the range
    class_type &operator ++()
    {
        return advance();
    }
    /// Advances the current position in the range, returning a copy of the
    /// range prior to its being advanced
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }
/// @}

/// \name Iterable Range methods
/// @{
public:
    /// Returns an iterator to the current position of the range
    iterator begin()
    {
        return m_position;
    }
    /// Returns an iterator to the end of the range
    iterator end()
    {
        return m_last;
    }

    /// Returns an iterator to the current position of the range
    const_iterator begin() const
    {
        return m_position;
    }
    /// Returns an iterator to the end of the range
    const_iterator end() const
    {
        return m_last;
    }
/// @}

// Members
private:
    iterator  m_position;
    iterator  m_last;
};

////////////////////////////////////////////////////////////////////////////////
// Functions

#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

template<ss_typename_param_k I>
inline iterator_range<I> make_iterator_range(I &first, I &last)
{
    return iterator_range<I>(first, last);
}

#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

template<ss_typename_param_k I>
inline iterator_range<I, iterator_range_traits<I> > make_iterator_range(I &first, I &last)
{
    return iterator_range<I, iterator_range_traits<I> >(first, last);
}

#if 0
template<ss_typename_param_k T>
inline iterator_range<T*, iterator_range_traits<T> > make_iterator_range(T *first, T *last)
{
    return iterator_range<T*, iterator_range_traits<T> >(first, last);
}
#endif /* 0 */

template<ss_typename_param_k T>
inline iterator_range<T const*, const_pointer_iterator_range_traits<const T> > make_iterator_range(T const *first, T const *last)
{
    return iterator_range<T const*, const_pointer_iterator_range_traits<const T> >(first, last);
}

#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace iterator_range_util
    {
        template <typename T>
        ss_bool_t test_container()
        {
            T           cont;
            int         total0  =   0;
            int         total1  =   0;

            for(int i = 0; i < 100; i += 5)
            {
#if defined(STLSOFT_COMPILER_IS_DMC)
                typedef ss_typename_type_k T::value_type    value_t;

                cont.push_back(value_t(i));
#else /* ? compiler */
                cont.push_back(ss_typename_type_k T::value_type(i));
#endif /* compiler */
            }

            for(iterator_range<ss_typename_type_k T::iterator> range(cont.begin(), cont.end()); range; ++range)
            {
                total0 += *range;
            }

#if defined(STLSOFT_COMPILER_IS_DMC)
            typedef ss_typename_type_k T::value_type    value_t;

            total1 = std::accumulate(cont.begin(), cont.end(), value_t(0));
#else /* ? compiler */
            total1 = std::accumulate(cont.begin(), cont.end(), ss_typename_type_k T::value_type(0));
#endif /* compiler */

            return total0 == total1;
        }
    } // namespace iterator_range_util

    ss_bool_t test_rangelib_iterator_range(unittest_reporter *r)
    {
        using stlsoft::unittest::unittest_initialiser;

        ss_bool_t               bSuccess    =   true;

        unittest_initialiser    init(r, "RangeLib", "iterator_range", __FILE__);

        if(!iterator_range_util::test_container<std::list<int> >())
        {
            r->report("summation over list<int> failed", __LINE__);
            bSuccess = false;
        }

        if(!iterator_range_util::test_container<std::vector<int> >())
        {
            r->report("summation over vector<int> failed", __LINE__);
            bSuccess = false;
        }

        if(!iterator_range_util::test_container<std::deque<short> >())
        {
            r->report("summation over deque<short> failed", __LINE__);
            bSuccess = false;
        }

        return bSuccess;
    }

    unittest_registrar    unittest_rangelib_iterator_range(test_rangelib_iterator_range);

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group rangelib_adaptors

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace rangelib
# else
} // namespace rangelib_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_RANGELIB_HPP_ITERATOR_RANGE */

/* ////////////////////////////////////////////////////////////////////////// */
