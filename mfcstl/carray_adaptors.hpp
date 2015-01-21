/* /////////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/carray_adaptors.hpp (derived from mfcstl_array_adaptor.h)
 *
 * Purpose:     Contains the definition of the CArray_cadaptor and CArray_iadaptor
 *              class templates.
 *
 * Created:     1st December 2002
 * Updated:     23rd December 2005
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


/// \file mfcstl/carray_adaptors.hpp
///
/// Contains the definition of the CArray_cadaptor and CArray_iadaptor class templates.

#ifndef MFCSTL_INCL_MFCSTL_HPP_CARRAY_ADAPTORS
#define MFCSTL_INCL_MFCSTL_HPP_CARRAY_ADAPTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_HPP_CARRAY_ADAPTORS_MAJOR    3
# define MFCSTL_VER_MFCSTL_HPP_CARRAY_ADAPTORS_MINOR    1
# define MFCSTL_VER_MFCSTL_HPP_CARRAY_ADAPTORS_REVISION 1
# define MFCSTL_VER_MFCSTL_HPP_CARRAY_ADAPTORS_EDIT     40
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC:  _MSC_VER==1300
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifndef MFCSTL_INCL_MFCSTL_HPP_AFX_ALLOCATOR
# include <mfcstl/afx_allocator.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_AFX_ALLOCATOR */
#ifndef MFCSTL_INCL_MFCSTL_CONTAINERS_HPP_CARRAY_SWAP
# include <mfcstl/containers/carray_swap.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_CONTAINERS_HPP_CARRAY_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS
# include <stlsoft/util/std/iterator_generators.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_GENERATORS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_META
# include <stlsoft/meta.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_META */
#if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(MFCSTL_NO_INCLUDE_AFXTEMPL_BY_DEFAULT)
# include <afxtempl.h>
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT && !MFCSTL_NO_INCLUDE_AFXTEMPL_BY_DEFAULT */

#ifdef STLSOFT_UNITTEST
# include <afxtempl.h>
# include <stlsoft/simple_string.hpp>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
# define MFCSTL_ARRAY_ADAPTORS_NO_TEMPLATE_RANGE_OPS
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */

namespace stlsoft
{

namespace mfcstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_container Container Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulation containers

/// \weakgroup mfcstl_container_library Container Library (MFCSTL)
/// \ingroup MFCSTL libraries_container
/// \brief This library provides facilities for defining and manipulation containers for MFC types

/// \defgroup mfcstl_container_library__carray_adaptors CArray Adaptors (MFCSTL)
/// \brief Class templates for adapting MFC CArray family classes
/// \ingroup mfcstl_container_library libraries__containers__adaptors
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// \brief Traits for CArray_adaptor_base
template <ss_typename_param_k C>
struct CArray_adaptor_traits
{
    /// \brief Typedef that defines the type of the elements in the array
    typedef ????            value_type;
    /// \brief Typedef that defines the type of the arguments to the methods of the array
    typedef ????            arg_type;
    /// \brief Typedef that identifies the actual class type used to parameterise the traits
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct CArray_adaptor_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CByteArray>
{
    typedef BYTE            value_type;
    typedef BYTE            arg_type;
    typedef CByteArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CDWordArray>
{
    typedef DWORD           value_type;
    typedef DWORD           arg_type;
    typedef CDWordArray     array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CUIntArray>
{
    typedef UINT            value_type;
    typedef UINT            arg_type;
    typedef CUIntArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CWordArray>
{
    typedef WORD            value_type;
    typedef WORD            arg_type;
    typedef CWordArray      array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CPtrArray>
{
    typedef void            *value_type;
    typedef void            *arg_type;
    typedef CPtrArray       array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CObArray>
{
    typedef CObject         *value_type;
    typedef CObject         *arg_type;
    typedef CObArray        array_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct CArray_adaptor_traits<CStringArray>
{
    typedef CString         value_type;
#if 0
    typedef const CString   &arg_type;
#else /* ? 0 */
    typedef LPCTSTR         arg_type;
#endif /* 0 */
    typedef CStringArray    array_type;
};

#if defined(__AFXTEMPL_H__) && \
    defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
template <class V, class A>
struct CArray_adaptor_traits<CArray<V, A> >
{
    typedef V               value_type;
    typedef A               arg_type;
    typedef CArray<V, A>    array_type;
};
#endif /* __AFXTEMPL_H__ && __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// \brief Traits type for specific setting of value_type and arg_type
template<   ss_typename_param_k V
        ,   ss_typename_param_k A
        ,   ss_typename_param_k C
        >
struct CArray_specific_traits
{
    typedef V               value_type;
    typedef A               arg_type;
    typedef C               array_type;
};


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
// Forward declarations
template<   ss_typename_param_k A
        ,   ss_typename_param_k I
        ,   ss_typename_param_k T
        >
class CArray_adaptor_base;

template<   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
class CArray_cadaptor;

template<   ss_typename_param_k A
        ,   ss_typename_param_k T
        >
class CArray_iadaptor;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// \brief Adaptor class, providing implementation for CArray_cadaptor and 
/// CArray_iadaptor classes
///
/// \param A The array class, e.g. CObArray, CArray<long>, etc.
/// \param I The interface specialisation, i.e. CArray_cadaptor<CObArray>, CArray_iadaptor<CArray<long> >, etc.
///
/// \note The elements in an adapted array are moved, during insertion / erasure, rather than copied. This
///   means that if the elements in the container maintain pointers to their elements, or their peers, then
///   they are not suitable for use.
template<   ss_typename_param_k A
        ,   ss_typename_param_k I
        ,   ss_typename_param_k T
        >
class CArray_adaptor_base
{
private:
    typedef A                                                                   array_type;
    typedef I                                                                   interface_type;
    typedef T                                                                   array_traits_type;
public:
    /// The value type
    ///
    /// \note If the compiler report "use of undefined type" when you're using the adaptor class(es)
    /// with CArray<>, ensure that you've included <b>afxtempl</b> <i>before</i> you include this file.
    typedef ss_typename_type_k array_traits_type::value_type                    value_type;
    /// The allocator type
    typedef afx_allocator<value_type>                                           allocator_type;
    /// The mutating (non-const) reference type
    typedef ss_typename_type_k allocator_type::reference                        reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k allocator_type::const_reference                  const_reference;
    /// The mutating (non-const) pointer type
    typedef ss_typename_type_k allocator_type::pointer                          pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k allocator_type::const_pointer                    const_pointer;
    /// The mutating (non-const) iterator type
    typedef
# if !defined(__STLSOFT_COMPILER_IS_BORLAND)
           ss_typename_type_k
# endif /* compiler */
                       pointer_iterator <   value_type
                                        ,   pointer
                                        ,   reference
                                        >::iterator_type                        iterator;
    /// The non-mutating (const) iterator type
    typedef
# if !defined(__STLSOFT_COMPILER_IS_BORLAND)
         ss_typename_type_k
# endif /* __STLSOFT_COMPILER_IS_BORLAND */
                       pointer_iterator <   value_type const
                                        ,   const_pointer
                                        ,   const_reference
                                        >::iterator_type                        const_iterator;
    /// The size type
    typedef ms_size_t                                                           size_type;
    /// The difference type
    typedef ms_ptrdiff_t                                                        difference_type;
    /// The instantiation of the current type
    typedef CArray_adaptor_base<A, I, T>                                        class_type;
#ifdef __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
    /// The mutating (non-const) reverse iterator type
    typedef ss_typename_type_k reverse_iterator_generator   <   iterator
                                                            ,   value_type
                                                            ,   reference
                                                            ,   pointer
                                                            ,   difference_type
                                                            >::type             reverse_iterator;

    /// The non-mutating (const) reverse iterator type
    typedef ss_typename_type_k const_reverse_iterator_generator <   const_iterator
                                                            ,   value_type
                                                            ,   const_reference
                                                            ,   const_pointer
                                                            ,   difference_type
                                                            >::type             const_reverse_iterator;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

/// \name Underlying container
/// @{
public:
    /// \brief Returns a mutating (non-const) reference to the underlying array
    array_type          &get_CArray()
    {
        return static_cast<interface_type*>(this)->get_actual_array_();
    }
    /// \brief Returns a non-mutating (const) reference to the underlying array
    array_type const    &get_CArray() const
    {
        return static_cast<interface_type const*>(this)->get_actual_array_();
    }
/// @}

/// \name Construction
/// @{
protected:
    /// \brief Default constructor.
    ///
    /// This is protected, because CArray_adaptor_base serves as an abstract base
    /// for CArray_cadaptor and CArray_iadaptor
    CArray_adaptor_base()
    {}
public:
    /// \brief Destructor
    ~CArray_adaptor_base()
    {}

    /// Returns a copy of the allocator used by the container
    allocator_type get_allocator() const
    {
        return allocator_type();
    }
/// @}

/// \name Assignment
/// @{
public:
    /// \brief Assigns a number of copies of the given value to the array, erasing all prior content
    ///
    /// \param n The number of values to assign
    /// \param value The value of which n copies are to be assigned
    ///
    /// \note Exception-safety is <b>strong</b> if MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT is defined, otherwise <b>weak</b>.
    ///
    /// \note The elements are default constructed, and then copy-assigned
    void assign(size_type n, value_type const &value)
    {
#ifdef MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT
        array_type  ar;

        // TODO: deal with allocation failures
        ar.InsertAt(0, value, static_cast<int>(n));

        CArray_swap(this->get_CArray(), ar);
#else /* ? MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */
        // TODO: deal with allocation failures
        resize(n);
        std::fill_n(begin(), n, value);
#endif /* MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */
    }

    /// \brief Assigns each element in the range [first, last) to the array, erasing all prior content
    ///
    /// \param first The first element in the range
    /// \param last The (one past the) last element in the range
    ///
    /// \note Exception-safety is <b>strong</b> if MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT is defined, otherwise <b>weak</b>.
    ///
    /// \note The elements are default constructed, and then copy-assigned
    template <ss_typename_param_k I>
    void assign(I first, I last)
    {
        // Precondition checks
        MFCSTL_ASSERT(is_valid_source_range_(first, last));

# if defined(MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT) && \
     !defined(MFCSTL_ARRAY_ADAPTORS_NO_TEMPLATE_RANGE_OPS)
        CArray_cadaptor<array_type>   arf(first, last);

        CArray_swap(this->get_CArray(), arf.get_CArray());
# else /* ? MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */
        // TODO: Specialise for random access iterators
        clear();
        std::copy(first, last, std::back_inserter<class_type>(*this));
# endif /* MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */
    }
/// @}

/// \name Capacity
/// @{
public:
    /// \brief The number of items in the array
    size_type size() const
    {
        return static_cast<size_type>(get_CArray().GetSize());
    }
    /// \brief The maximum number of items that can be stored in the array
    size_type max_size() const
    {
        return get_allocator().max_size();
    }
    /// \brief Indicates whether the array is empty
    ms_bool_t empty() const
    {
        return 0 == size();
    }
    /// \brief Adjusts the number of elements in the array
    ///
    /// \param n The number of elements that the array will contain after resizing
    ///
    /// \note Exception-safety is <b>strong</b>
    void resize(size_type n)
    {
        // TODO: deal with allocation failures
        get_CArray().SetSize(n);
    }
    /// \brief Adjusts the number of elements in the array
    ///
    /// \param n The number of elements that the array will contain after resizing
    /// \param value The value of any additional elements created during resizing
    ///
    /// \note Due to the limitations of the underlying CArray-family containers, the
    ///   additional elements are default constructed and then subjected to 
    ///   copy-assignment.
    ///
    /// \note Exception-safety is <b>strong</b>
    void resize(size_type n, value_type value)
    {
        const size_type oldSize = size();
        resize(n);
        if(oldSize < n)
        {
            try
            {
                std::fill_n(begin() + oldSize, n - oldSize, value);
            }
            catch(...)
            {
                resize(oldSize);
                throw;
            }
        }
    }
/// @}

/// \name Element access
/// @{
public:
    /// \brief Returns a mutable (non-const) reference to the element at the given index
    ///
    /// \param n The requested index. Must be less than size()
    ///
    /// \note The implementation will assert in debug mode if the index is out of range
    reference operator [](size_type n)
    {
        MFCSTL_MESSAGE_ASSERT("index out of bounds", n < size());

        return get_CArray()[n];
    }
    /// \brief Returns a non-mutable (const) reference to the element at the given index
    ///
    /// \param n The requested index. Must be less than size()
    ///
    /// \note The implementation will assert in debug mode if the index is out of range
    const_reference operator [](size_type n) const
    {
        MFCSTL_MESSAGE_ASSERT("index out of bounds", n < size());

        return get_CArray()[n];
    }
    /// \brief Returns a mutable (non-const) reference to the element at the given index
    ///
    /// \param n The requested index. If the index is not less than size() an
    /// instance of std::out_of_range will be thrown
    reference at(size_type n)
    {
        if(n >= size())
        {
            throw std::out_of_range("Invalid index specified");
        }

        return (*this)[n];
    }
    /// \brief Returns a non-mutable (const) reference to the element at the given index
    ///
    /// \param n The requested index. If the index is not less than size() an
    /// instance of std::out_of_range will be thrown
    const_reference at(size_type n) const
    {
        if(n >= size())
        {
            throw std::out_of_range("Invalid index specified");
        }
        return (*this)[n];
    }
    /// \brief Returns a mutable (non-const) reference to the first element in the array
    reference front()
    {
        MFCSTL_MESSAGE_ASSERT("front() called on an empty instance", !empty());

        return (*this)[0];
    }
    /// \brief Returns a mutable (non-const) reference to the last element in the array
    reference back()
    {
        MFCSTL_MESSAGE_ASSERT("back() called on an empty instance", !empty());

        return (*this)[size() - 1];
    }
    /// \brief Returns a non-mutable (const) reference to the first element in the array
    const_reference front() const
    {
        MFCSTL_MESSAGE_ASSERT("front() called on an empty instance", !empty());

        return (*this)[0];
    }
    /// \brief Returns a non-mutable (const) reference to the last element in the array
    const_reference back() const
    {
        MFCSTL_MESSAGE_ASSERT("back() called on an empty instance", !empty());

        return (*this)[size() - 1];
    }
/// @}

/// \name Iteration
public:
/// @{
    /// \brief Returns a mutable (non-const) iterator representing the start of the array
    iterator begin()
    {
        return get_CArray().GetData();
    }
    /// \brief Returns a mutable (non-const) iterator representing the end of the array
    iterator end()
    {
        return begin() + size();
    }
    /// \brief Returns a non-mutable (const) iterator representing the start of the array
    const_iterator begin() const
    {
        // This is needed because CXxxxArray::GetData() const returns, e.g., const CObject** instead of CObject* const* 
        value_type const    *p1 =   get_CArray().GetData();
        value_type *const   p2  =   const_cast<value_type *const>(p1);

        return p2;
    }
    /// \brief Returns a non-mutable (const) iterator representing the end of the array
    const_iterator end() const
    {
        return begin() + size();
    }
#ifdef __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
    /// \brief Returns a mutable (non-const) reverse iterator representing the start of the array
    reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }
    /// \brief Returns a mutable (non-const) reverse iterator representing the end of the array
    reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }
    /// \brief Returns a non-mutable (const) reverse iterator representing the start of the array
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }
    /// \brief Returns a non-mutable (const) reverse iterator representing the end of the array
    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Comparison
/// @{
public:
#if 0
    template<   ss_typename_param_k A2
            ,   ss_typename_param_k I2
            ,   ss_typename_param_k T2
            >
    ms_bool_t equal(CArray_adaptor_base<A2, I2, T2> const &rhs) const
    {
        return size() == rhs.size() && stlsoft_ns_qual_std(equal)(begin(), end(), rhs.begin());
    }
#endif /* 0 */
    template <ss_typename_param_k A2>
    ms_bool_t equal(A2 const &rhs) const
    {
        return size() == rhs.size() && stlsoft_ns_qual_std(equal)(begin(), end(), rhs.begin());
    }
/// @}

/// \name Modifiers
/// @{
public:
    /// \brief Adds the given element to the end of the array
    ///
    /// \param value The value to add to the end of the array
    ///
    /// \note All iterators, pointers and references are invalidated
    void push_back(value_type const &value)
    {
        // TODO: deal with allocation failures
        get_CArray().Add(value);
    }
    /// \brief Removes the last element from the non-empty array
    ///
    /// \note The behaviour is undefined if the array is empty
    void pop_back()
    {
        // Precondition checks
        MFCSTL_MESSAGE_ASSERT("pop_back() called on empty container", !empty());

        get_CArray().RemoveAt(get_CArray().GetUpperBound());
    }
    /// \brief Inserts the given value at the given position
    ///
    /// \param pos The position at which to insert. The value will be inserted
    ///   before the element referred to by pos, or at the end if pos == end()
    /// \param value The value to be inserted
    ///
    /// \retval The position of the inserted value
    ///
    /// \note All iterators, pointers and references are invalidated
    ///
    /// \note Any elements after the insertion position are moved using memmove,
    ///   rather than by copy construction. If the element type maintains
    ///   pointers to its internal members, or to its peer elements, then these
    ///   relationships will be broked, and the subsequent behaviour of the
    ///   program will be undefined
    iterator insert(iterator pos, value_type const &value)
    {
        // Precondition checks
        MFCSTL_ASSERT(pos == end() || (pos >= begin() && pos < end()));

        difference_type index = pos - begin();

        // TODO: deal with allocation failures
        get_CArray().InsertAt(static_cast<int>(index), value, 1);

        return begin() + index;
    }
    /// \brief Inserts a number of copies of the given value at the given position
    ///
    /// \param pos The position at which to insert. The value(s) will be inserted
    ///   before the element referred to by pos, or at the end if pos == end()
    /// \param n The number of values to insert
    /// \param value The value to be inserted
    ///
    /// \note All iterators, pointers and references are invalidated
    ///
    /// \note Any elements after the insertion position are moved using memmove,
    ///   rather than by copy construction. If the element type maintains
    ///   pointers to its internal members, or to its peer elements, then these
    ///   relationships will be broked, and the subsequent behaviour of the
    ///   program will be undefined
    void insert(iterator pos, size_type n, value_type const &value)
    {
        // Precondition checks
        MFCSTL_ASSERT(pos == end() || (pos >= begin() && pos < end()));

        difference_type index = pos - begin();

        // TODO: deal with allocation failures
        get_CArray().InsertAt(static_cast<int>(index), value, n);
    }
    /// \brief Inserts the elements in the range [first, last) at the given position
    ///
    /// \param pos The position at which to insert. The value(s) will be inserted
    ///   before the element referred to by pos, or at the end if pos == end()
    /// \param first The start of the range of values to insert
    /// \param last The (one past the) end of the range of values to insert
    ///
    /// \note All iterators, pointers and references are invalidated
    ///
    /// \note Any elements after the insertion position are moved using memmove,
    ///   rather than by copy construction. If the element type maintains
    ///   pointers to its internal members, or to its peer elements, then these
    ///   relationships will be broked, and the subsequent behaviour of the
    ///   program will be undefined
    template <ss_typename_param_k I>
    void insert(iterator pos, I first, I last)
    {
        // Precondition checks
        MFCSTL_ASSERT(is_valid_source_range_(first, last));
        MFCSTL_ASSERT(pos == end() || (pos >= begin() && pos < end()));

        array_type                  ar;
        CArray_iadaptor<array_type
                    ,   array_traits_type
                    >               arp(ar);
        arp.assign(first, last);
        difference_type             index = pos - begin();

        // TODO: deal with allocation failures
        get_CArray().InsertAt(static_cast<int>(index), &ar);
    }
    /// \brief Erases the element at the given position
    ///
    /// \param pos The position of the element to be removed
    ///
    /// \retval The position of the value immediately following the element erased
    ///
    /// \note Any iterators, pointers or references to elements at or after \c
    ///   pos will be invalidated. Those before \c pos remain valid
    ///
    /// \note Any elements after the erasure position are moved using memmove,
    ///   rather than by copy construction. If the element type maintains
    ///   pointers to its internal members, or to its peer elements, then these
    ///   relationships will be broked, and the subsequent behaviour of the
    ///   program will be undefined
    iterator erase(iterator pos)
    {
        // Precondition checks
        MFCSTL_ASSERT(pos == end() || (pos >= begin() && pos < end()));

        difference_type index = pos - begin();
        get_CArray().RemoveAt(static_cast<int>(index), 1);

        // Postcondition checks
        MFCSTL_ASSERT(pos == begin() + index);

        return pos;
    }
    /// \brief Erases a range of elements from the array
    ///
    /// \param first The first element in the range to be removed
    /// \param last The (one past the) end element in the range to be removed
    ///
    /// \retval The position of the value immediately following the elements erased
    ///
    /// \note Any iterators, pointers or references to elements at or after \c
    ///   first will be invalidated. Those before \c first remain valid
    ///
    /// \note Any elements after the erasure position are moved using memmove,
    ///   rather than by copy construction. If the element type maintains
    ///   pointers to its internal members, or to its peer elements, then these
    ///   relationships will be broked, and the subsequent behaviour of the
    ///   program will be undefined
    iterator erase(iterator first, iterator last)
    {
        // Precondition checks
        MFCSTL_ASSERT(first <= last);
        MFCSTL_ASSERT(first == end() || (first >= begin() && first < end()));
        MFCSTL_ASSERT(last == end() || (last >= begin() && last < end()));

        difference_type index = first - begin();
        get_CArray().RemoveAt(static_cast<int>(index), std::distance(first, last));

// NOTE: CArray - uses memmove

        // Postcondition checks
        MFCSTL_ASSERT(first == begin() + index);

        return first;
    }
    /// \brief Removes all the elements from the array
    void clear()
    {
        get_CArray().RemoveAll();
    }

#ifdef MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT
    /// \brief Efficiently exchanges the contents with those of another array
    ///   by swapping the internal structures
    ///
    /// \param rhs The instance whose contents will be exchanged with the callee
    ///
    /// \note This method is only defined if the preprocessor symbol 
    ///   MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT is defined
    void swap(class_type &rhs)
    {
        mfcstl::CArray_swap(this->get_CArray(), rhs.get_CArray());
    }
#endif /* MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */

    /// \brief Exchanges the contents with those of another array by copying
    ///   each of the constituents, using a temporary array instance.
    ///
    /// \param rhs The instance whose contents will be exchanged with the callee
    void         swap_by_copy(class_type &rhs)
    {
        class_type  t       =   rhs;
                    rhs     =   *this;
                    *this   =   t;
    }
/// @}

protected:
#if (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1200)
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS)
    // There seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    static ms_bool_t is_valid_source_range_(II first, II last, stlsoft_ns_qual_std(input_iterator_tag) const *)
# else /* ? compiler */
    static ms_bool_t is_valid_source_range_(II first, II last, stlsoft_ns_qual_std(input_iterator_tag))
# endif /* compiler */
    {
        return true;    // Can't test them, as that eats their state, so have to assume yes
    }
#endif /* compiler */

    template<   ss_typename_param_k II
            ,   ss_typename_param_k T
            >
    static ms_bool_t is_valid_source_range_(II first, II last, T)
    {
        return true;    // FI and BI don't have <=, so cannot test, so have to assume yes
    }

#if (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1200)
    template <ss_typename_param_k II>
# if defined(STLSOFT_COMPILER_IS_MWERKS)
    // There seems to be a bug in CodeWarrior that makes it have a cow with iterator tags by value, so we just use a ptr
    static ms_bool_t is_valid_source_range_(II first, II last, stlsoft_ns_qual_std(random_access_iterator_tag) const *)
# else /* ? compiler */
    static ms_bool_t is_valid_source_range_(II first, II last, stlsoft_ns_qual_std(random_access_iterator_tag))
# endif /* compiler */
    {
        return first <= last;
    }
#endif /* compiler */

    template <ss_typename_param_k I>
    static ms_bool_t is_valid_source_range_(I first, I last)
    {
# if defined(STLSOFT_COMPILER_IS_GCC) && \
     __GNUC__ < 3
        typedef ss_typename_type_k std::iterator_traits<II> traits_t;

        return is_valid_source_range_(first, last, traits_t::iterator_category());
# elif defined(STLSOFT_COMPILER_IS_MWERKS)
        return is_valid_source_range_(first, last, stlsoft_iterator_query_category_ptr(II, first));
# elif defined(STLSOFT_COMPILER_IS_DMC)
        return true;
# else /* ? compiler */
        return is_valid_source_range_(first, last, stlsoft_iterator_query_category(II, first));
# endif /* compiler */
    }

#if 0
    template <ss_typename_param_k T>
    static ms_bool_t is_valid_source_range_(T *first, T *last)
    {
        return first <= last;
    }
#endif /* 0 */

#if 0
    template <ss_typename_param_k T>
    static ms_bool_t is_valid_source_range_(T const *first, T const *last)
    {
        return first <= last;
    }
#endif /* 0 */

/// Not to be implemented
private:
    CArray_adaptor_base(class_type const &rhs);
    class_type &operator =(class_type const &rhs);
};

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// \brief Adaptor class, representing a Class Adaptor over the CArray family of MFC containers
///
/// The adaptor, being a facade, is 
///
/// It is used as follows:
///
/// \code
  mfcstl::CArray_cadaptor<CStringArray>   ar;

  // As an MFC CStringArray:
  ar.Add("String 1");
  ar.InsertAt(0, "String 0");

  // As an STL container
  ar.push_back("String 2");
  std::list<CString>  l;
  l.push_back("String 3");
  l.push_back("String 4");
  ar.insert(ar.begin() + 2, l.begin(), l.end());
  std::sort(ar.begin(), ar.end());
/// \endcode
///
/// \param A The array class, e.g. CObArray, CArray<long>, etc.
///
/// \note The elements in an adapted array are moved, during insertion / erasure, rather than copied. This
///   means that if the elements in the container maintain pointers to their elements, or their peers, then
///   they are not suitable for use.
#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */
template<   ss_typename_param_k A
        ,   ss_typename_param_k T = CArray_adaptor_traits<A>
        >
class CArray_cadaptor
        : public A
        , public CArray_adaptor_base<A, CArray_cadaptor<A, T>, T>
{
private:
    typedef A                                                       array_type;
    typedef CArray_adaptor_base<A, CArray_cadaptor<A, T>, T>        parent_class_type;
public:
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    /// The allocator type
    typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
    /// The mutating (non-const) reference type
    typedef ss_typename_type_k parent_class_type::reference         reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
    /// The mutating (non-const) pointer type
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k parent_class_type::const_pointer     const_pointer;
    /// The mutating (non-const) iterator type
    typedef ss_typename_type_k parent_class_type::iterator          iterator;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k parent_class_type::const_iterator    const_iterator;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type         size_type;
    /// The difference type
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    /// The instantiation of the current type
    typedef CArray_cadaptor<A, T>                                   class_type;

private:
    friend class CArray_adaptor_base<A, CArray_cadaptor<A, T>, T>;

    array_type          &get_actual_array_()
    {
        return *this;
    }
    array_type const    &get_actual_array_() const
    {
        return *this;
    }

public: // Construction
    CArray_cadaptor()
    {}
    explicit CArray_cadaptor(size_type n)
    {
        resize(n);
    }
    CArray_cadaptor(size_type n, value_type const &value)
    {
        resize(n, v);
    }
    CArray_cadaptor(class_type const &rhs)
    {
        resize(rhs.size());
        std::copy(rhs.begin(), rhs.end(), begin());
    }
    CArray_cadaptor(array_type const &rhs)
    {
        resize(static_cast<size_type>(rhs.GetSize()));
        std::copy(rhs.GetData(), rhs.GetData() + rhs.GetSize(), begin());
    }
    template <ss_typename_param_k I>
    CArray_cadaptor(I first, I last)
    {
        // Precondition checks
        MFCSTL_ASSERT(is_valid_source_range_(first, last));

        std::copy(first, last, std::back_inserter<class_type>(*this));
    }
    ~CArray_cadaptor()
    {
        STLSOFT_STATIC_ASSERT(sizeof(A) == sizeof(typename T::array_type));
    }

    class_type &operator =(class_type const &rhs)
    {
#ifdef MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT
        class_type t(rhs);
        t.swap(*this);
#else /* ? MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */
        parent_class_type::operator =(rhs);
#endif /* MFCSTL_CARRAY_SWAP_MEMBERS_SUPPORT */

        return *this;
    }
public:
#if defined(STLSOFT_COMPILER_IS_DMC)
    reference operator [](size_type index)
    {
        return parent_class_type::operator [](index);
    }
    const_reference operator [](size_type index) const
    {
        return parent_class_type::operator [](index);
    }
#else /* ? compiler */
    using parent_class_type::operator [];
#endif /* compiler */
};


#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// \brief Adaptor class, representing a proxy over the CArray family of MFC containers
///
/// It is used as follows:
///
/// \code
  CStringArray                          ar;
  mfcstl::CArray_iadaptor<CStringArray> arp;

  // As an MFC CStringArray:
  ar.Add("String 1");
  ar.InsertAt(0, "String 0");

  // As an STL container
  arp.push_back("String 2");
  std::list<CString>  l;
  l.push_back("String 3");
  l.push_back("String 4");
  arp.insert(arp.begin() + 2, l.begin(), l.end());
  std::sort(arp.begin(), arp.end());
/// \endcode
///
/// \param A The array class, e.g. CObArray, CArray<long>, etc.
///
/// \note The elements in an adapted array are moved, during insertion / erasure, rather than copied. This
///   means that if the elements in the container maintain pointers to their elements, or their peers, then
///   they are not suitable for use.
#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */
template<   ss_typename_param_k A
        ,   ss_typename_param_k T = CArray_adaptor_traits<A>
        >
class CArray_iadaptor
        : public CArray_adaptor_base<A, CArray_iadaptor<A, T>, T>
{
private:
    typedef A                                                       array_type;
    typedef CArray_adaptor_base<A, CArray_iadaptor<A, T>, T>        parent_class_type;
public:
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    /// The allocator type
    typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
    /// The mutating (non-const) reference type
    typedef ss_typename_type_k parent_class_type::reference         reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
    /// The mutating (non-const) pointer type
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k parent_class_type::const_pointer     const_pointer;
    /// The mutating (non-const) iterator type
    typedef ss_typename_type_k parent_class_type::iterator          iterator;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k parent_class_type::const_iterator    const_iterator;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type         size_type;
    /// The difference type
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    /// The instantiation of the current type
    typedef CArray_iadaptor<A, T>                                   class_type;

private:
    friend class CArray_adaptor_base<A, CArray_iadaptor<A, T>, T>;

    array_type          &get_actual_array_()
    {
        MFCSTL_ASSERT(NULL != m_pArray);
        return *m_pArray;
    }
    array_type const    &get_actual_array_() const
    {
        MFCSTL_ASSERT(NULL != m_pArray);
        return *m_pArray;
    }

/// \name Construction
/// @{
public:
    template <ss_typename_param_k A2>
    CArray_iadaptor(A2 &array)
         : m_pArray(&array)
    {
        STLSOFT_STATIC_ASSERT(sizeof(array_type) == sizeof(A2));
#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
        STLSOFT_STATIC_ASSERT((stlsoft::is_same_type<array_type, A2>::value));
#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
        ASSERT(0 == strcmp(array.GetRuntimeClass()->m_lpszClassName, array_type().GetRuntimeClass()->m_lpszClassName));
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#ifdef _CPPUNWIND
        ASSERT(0 == strcmp(typeid(A2).name(), typeid(array_type).name()));
#endif /* _CPPUNWIND */
    }
    template <ss_typename_param_k A2>
    CArray_iadaptor(A2 *pArray)
         : m_pArray(pArray)
    {
        MFCSTL_MESSAGE_ASSERT("Cannot initialise a CArray_iadaptor with a NULL pointer", NULL != pArray);

        STLSOFT_STATIC_ASSERT(sizeof(array_type) == sizeof(A2));
#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
        STLSOFT_STATIC_ASSERT((stlsoft::is_same_type<array_type, A2>::value));
#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
        ASSERT(0 == strcmp(pArray->GetRuntimeClass()->m_lpszClassName, array_type().GetRuntimeClass()->m_lpszClassName));
#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#ifdef _CPPUNWIND
        ASSERT(0 == strcmp(typeid(A2).name(), typeid(array_type).name()));
#endif /* _CPPUNWIND */
    }
/// @}
        
private:
    array_type  *m_pArray;

/// Not to be implemented
private:
    CArray_iadaptor(class_type const &rhs);            // Only possible semantics for copy-ctor are share underlying array
    class_type &operator =(class_type const &rhs);  // Could either repoint, or could do deep copy.
};

/* /////////////////////////////////////////////////////////////////////////////
 * Comparison
 */

#if 1
template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k I1
        ,   ss_typename_param_k I2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator ==(CArray_adaptor_base<A1, I1, T1> const &lhs, CArray_adaptor_base<A2, I2, T2> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k I1
        ,   ss_typename_param_k I2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator !=(CArray_adaptor_base<A1, I1, T1> const &lhs, CArray_adaptor_base<A2, I2, T2> const &rhs)
{
    return !lhs.equal(rhs);
}
#endif /* 0 */

#if 0
template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator !=(CArray_cadaptor<A1, T1> const &lhs, CArray_cadaptor<A2, T2> const &rhs)
{
    return !lhs.equal(rhs.get_CArray());
}

template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator !=(CArray_iadaptor<A1, T1> const &lhs, CArray_iadaptor<A2, T2> const &rhs)
{
    return !lhs.equal(rhs.get_CArray());
}

template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator !=(CArray_cadaptor<A1, T1> const &lhs, CArray_iadaptor<A2, T2> const &rhs)
{
    return !lhs.equal(rhs.get_CArray());
}

template<   ss_typename_param_k A1
        ,   ss_typename_param_k A2
        ,   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
inline ms_bool_t operator !=(CArray_iadaptor<A1, T1> const &lhs, CArray_cadaptor<A2, T2> const &rhs)
{
    return !lhs.equal(rhs.get_CArray());
}
#endif /* 0 */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/carray_adaptors_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group mfcstl_container_library__carray_adaptors

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace mfcstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_MFCSTL_HPP_CARRAY_ADAPTORS */

/* ////////////////////////////////////////////////////////////////////////// */
