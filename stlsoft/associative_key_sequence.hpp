/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/associative_key_sequence.hpp
 *
 * Purpose:     Adapts associative containers into a sequence of their values.
 *
 * Created:     28th January 2005
 * Updated:     11th January 2006
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


/// \file stlsoft/associative_key_sequence.hpp
///
/// Adapts associative containers into a sequence of their values.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE
#define STLSOFT_INCL_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE_MAJOR     1
# define STLSOFT_VER_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE_MINOR     2
# define STLSOFT_VER_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE_EDIT      11
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
#ifndef STLSOFT_INCL_STLSOFT_HPP_ASSOCIATIVE_SELECT_ITERATOR
# include <stlsoft/associative_select_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ASSOCIATIVE_SELECT_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#include <stdexcept>
#ifdef STLSOFT_UNITTEST
# include <map>
#endif /* STLSOFT_UNITTEST */

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

/// Adapts an associative container to provide a sequence over the element keys
template <ss_typename_param_k A>
class associative_key_sequence
    : public stl_collection_tag
{
/// \name Types
/// @{
public:
    /// The current parameterisation of the type
    typedef associative_key_sequence<A>                     class_type;
    /// The value type
#if 0
    typedef ss_typename_type_k A::mapped_type               value_type;
#else /* ? 0 */
    typedef ss_typename_type_k A::value_type::first_type    value_type;
#endif /* 0 */
    /// The associative container type
    typedef A                                               associative_container_type;
    /// The allocator type
    typedef ss_typename_type_k A::allocator_type            allocator_type;
#if 0
    /// The pointer type
    ///
    /// \note This is identical to the const_pointer, since we will not be using
    /// this adaptor sequence to alter the contents of the underlying sequence
    typedef ss_typename_type_k A::const_pointer             pointer;
    /// The non-mutable (const) pointer type
    typedef ss_typename_type_k A::const_pointer             const_pointer;
#endif /* 0 */
    /// The reference type
    ///
    /// \note This is identical to the const_reference, since we will not be using
    /// this adaptor sequence to alter the contents of the underlying sequence
    typedef ss_typename_type_k A::const_reference   reference;
    /// The non-mutable (const) reference type
    typedef ss_typename_type_k A::const_reference   const_reference;
    /// The size type
    typedef ss_typename_type_k A::size_type         size_type;
    /// The difference type
    typedef ss_typename_type_k A::difference_type   difference_type;

    /// The iterator type
private:
    typedef ss_typename_type_k A::iterator          A_iterator_type;
    typedef ss_typename_type_k A::const_iterator    A_const_iterator_type;
    typedef ss_typename_type_k A::value_type        A_value_type;
    typedef ::stlsoft::select_first<A_value_type>   select_first_type;

//  typedef ::stlsoft::select_first<ss_typename_type_k A::value_type>
public:
    typedef associative_select_iterator <   A_iterator_type
                                        ,   select_first_type
                                        >           iterator;
    /// The non-mutating (const) iterator type
    typedef associative_select_iterator <   A_const_iterator_type
                                        ,   select_first_type
                                        >           const_iterator;

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The reverse iterator type
    typedef reverse_iterator_base       <   iterator
                                        ,   value_type
                                        ,   reference
                                        ,   value_type*
                                        ,   difference_type
                                        >           reverse_iterator;

    /// The non-mutating (const) reverse iterator type
    typedef const_reverse_iterator_base <   const_iterator
                                        ,   value_type const
                                        ,   const_reference
                                        ,   value_type const*
                                        ,   difference_type
                                        >           const_reverse_iterator;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k associative_key_sequence(associative_container_type const &container);
/// @}

/// \name Attributes
/// @{
public:
    /// The number of elements in the container
    size_type size() const;
    /// The maximum number of elements that can be stored in the container
    size_type max_size() const;
    /// Indicates whether the container is empty
    ss_bool_t empty() const;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the sequence
    const_iterator          begin() const;
    /// Ends the iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the sequence
    const_iterator          end() const;

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Members
/// @{
private:
    associative_container_type const    &m_container;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Construction

template <ss_typename_param_k A>
inline associative_key_sequence<A>::associative_key_sequence(ss_typename_type_k associative_key_sequence<A>::associative_container_type const &container)
    : m_container(container)
{}

// Attributes

template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::size_type associative_key_sequence<A>::size() const
{
    return m_container.size();
}

template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::size_type associative_key_sequence<A>::max_size() const
{
    return m_container.max_size();
}

template <ss_typename_param_k A>
inline ss_bool_t associative_key_sequence<A>::empty() const
{
    return m_container.empty();
}

// Iteration

template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::const_iterator associative_key_sequence<A>::begin() const
{
    return const_iterator(m_container.begin());
}

template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::const_iterator associative_key_sequence<A>::end() const
{
    return const_iterator(m_container.end());
}

# if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::const_reverse_iterator associative_key_sequence<A>::rbegin() const
{
    return const_reverse_iterator(m_container.rbegin());
}

template <ss_typename_param_k A>
inline ss_typename_type_k associative_key_sequence<A>::const_reverse_iterator associative_key_sequence<A>::rend() const
{
    return const_reverse_iterator(m_container.rend());
}
# endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ASSOCIATIVE_KEY_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */