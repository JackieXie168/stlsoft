/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl_array_veneer.h
 *
 * Purpose:     Contains the definition of the array_veneer template.
 *
 * Created:     28th January 2003
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/// \file mfcstl_array_veneer.h
///
/// Contains the definition of the array_veneer template.

#ifndef MFCSTL_INCL_H_MFCSTL_ARRAY_VENEER
#define MFCSTL_INCL_H_MFCSTL_ARRAY_VENEER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_H_MFCSTL_ARRAY_VENEER_MAJOR     3
# define MFCSTL_VER_H_MFCSTL_ARRAY_VENEER_MINOR     4
# define MFCSTL_VER_H_MFCSTL_ARRAY_VENEER_REVISION  1
# define MFCSTL_VER_H_MFCSTL_ARRAY_VENEER_EDIT      53
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:OBSOLETE]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */

#if !defined(STLSOFT_OBSOLETE)
# error mfcstl::array_veneer is now obsolete. Please include mfcstl/carray_adaptors.hpp, and use mfcstl::CArray_cadaptor
#endif /* !STLSOFT_OBSOLETE */

#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
# include <stlsoft/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

// struct array_veneer_traits
//
// Regrettably, since MFC's template classes do not define any member types,
// it is not possible to generalise the traits, so we must just use
// specialisations. Sigh!

template <class C>
struct array_veneer_traits;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
// For CByteArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CByteArray>
{
    typedef BYTE                value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};

// For CDWordArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CDWordArray>
{
    typedef DWORD               value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};

// For CObArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CObArray>
{
    typedef CObject             *value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};

// For CPtrArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CPtrArray>
{
    typedef void                *value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};

// For CStringArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CStringArray>
{
    typedef CString             value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef reference           arg_type;
};

// For CUIntArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CUIntArray>
{
    typedef UINT                value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};

// For CWordArray

STLSOFT_TEMPLATE_SPECIALISATION
struct array_veneer_traits<CWordArray>
{
    typedef WORD                value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef value_type          arg_type;
};


// For CArray<, >

#ifdef __AFXTEMPL_H__
# ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
/* If your translator supports partial template specialisation, then
 * you should be fine with the following specialisation ...
 */

template <class V, class A>
struct array_veneer_traits<CArray<V, A> >
{
    typedef V                   value_type;
    typedef value_type          *pointer;
    typedef value_type          &reference;
    typedef value_type const    *const_pointer;
    typedef value_type const    &const_reference;
    typedef const_reference     arg_type;
};

# else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* ... otherwise you will need to provide your own traits class, e.g
 *
 *  struct my_traits_type
 *  {
 *    typedef MyValType       value_type;
 *    typedef MyValType const &arg_type;
 *  };
 */

# endif // STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
#endif // __AFXTEMPL_H__
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief Adapts MFC Array classes to the STL container concept
 *
 * This class takes a container type, e.g. CStringArray, as its primary (and
 * only non-default) template argument, C. The second template parameter, T,
 * defaults to array_veneer_traits<C>, for which specialisations are provided
 * for the following types
 *
 *  - CObArray      (stores pointers to CObject, or derived, instances)
 *  - CPtrArray     (stores raw pointers, ie. void*)
 *  - CStringArray  (stores strings, in the form of CString)
 *
 * and for compilers that support partial specialisation
 *
 *  - CArray<V, A>  (stores instances of V, with argument type A)
 *
 * \param C The container type
 * \param T The traits type. With translators that support default template arguments, this is defaulted to array_veneer_traits<C>
 *
 * \ingroup concepts_veneer
 */

template<   class C                             // The container type
        ,   class T = array_veneer_traits<C>    // The traits type
        >
class array_veneer
    : public C
    , public stlsoft_ns_qual(stl_collection_tag)
{
public:
    /// The type of the instantiated template
    typedef array_veneer<C, T>                              class_type;
    /// The type of the adapted container
    typedef C                                               container_type;
private:
    typedef T                                               traits_type;
    typedef class_type                                      adapted_container_type;
public:
    // If you get a warning about a array_veneer_traits<CArray<,> > parameterisation not
    // having a value_type on the next line, you need to include afxtempl.h _before_
    // this header file
    typedef ss_typename_type_k traits_type::value_type      value_type;
    typedef ss_typename_type_k traits_type::pointer         pointer;
    typedef ss_typename_type_k traits_type::const_pointer   const_pointer;
    typedef ss_typename_type_k traits_type::reference       reference;
    typedef ss_typename_type_k traits_type::const_reference const_reference;
    /// The size type
    typedef ms_size_t                                       size_type;
    /// The difference type
    typedef ms_ptrdiff_t                                    difference_type;

public:
    /// Non-mutating (const) iterator for the list_veneer class
    ///
    /// \note This supports the Random-Access Iterator concept
    class const_iterator
        : public stlsoft_ns_qual(iterator_base)<mfcstl_ns_qual_std(random_access_iterator_tag)
                                            ,   value_type
                                            ,   ms_ptrdiff_t
                                            ,   container_type::const_pointer
                                            ,   container_type::const_reference
                                            >
    {
    protected:
        friend class array_veneer<C, T>;

        typedef const_iterator                                      class_type;
        // NOTE: If you get a compiler error on the next line, referring to
        // undefined 'value_type' then you need to provide a traits type
        // with the member type 'value_type' defined.
    public:
        typedef int                                                 index_type;
#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
        typedef ss_typename_type_k array_veneer<C, T>::value_type   value_type;
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    // Construction
    protected:
        const_iterator(container_type const *const c, index_type index)
            : m_c(c)
            , m_index(index)
        {}
    public:
        /// Default constructor
        const_iterator()
            : m_c(0)
            , m_index(0)
        {}
        /// Copy constructor
        ///
        /// \param rhs The instance from which to copy construct
        const_iterator(class_type const &rhs)
            : m_c(rhs.m_c)
            , m_index(rhs.m_index)
        {}

        /// Copy assignment operator
        ///
        /// \param rhs The instance from which to copy assign
        const_iterator const &operator =(class_type const &rhs)
        {
            MFCSTL_MESSAGE_ASSERT("Attempting to assign iterator from another container!", m_c == NULL || rhs.m_c == NULL || m_c == rhs.m_c);

            m_c     =   rhs.m_c;
            m_index =   rhs.m_index;

            return *this;
        }

    // Operators
    public:
        const_reference operator *() const
        {
            MFCSTL_MESSAGE_ASSERT("", m_c != 0);

            // The non-mutating form of the subscript operator on
            // MFC CArray classes does not return a reference, so
            // we need to const_cast
            container_type  *c  =   const_cast<container_type*>(m_c);

            return (*c)[m_index];
        }

        /// Pre-increment operator
        class_type &operator ++()
        {
            ++m_index;

            return *this;
        }

        /// Post-increment operator
        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        /// Compares \c this with \c rhs
        ///
        /// \param rhs The instance against which to test
        /// \retval 0 if the two are equal
        /// \retval <0 if \c this is before \c rhs in the sequence
        /// \retval >0 if \c this is after \c rhs in the sequence
        difference_type compare(class_type const &rhs) const
        {
            // Because the C<Type><Container> containers, e.g. CStringArray
            // work on the basis of get-and-advance, m_pos alone cannot be
            // the sentinel for an ended sequence. Hence, combining the
            // implementation of op++ to set m_c to 0 when m_pos is NULL, we
            // can test both members, which results in the after-the-fact
            // equality evaluating correctly.

            MFCSTL_MESSAGE_ASSERT("invalid comparison between iterators from different ranges", m_c == 0 || rhs.m_c == 0 || m_c == rhs.m_c);

            return m_index - rhs.m_index;
        }

        /// Evaluates whether \c this and \c rhs are equivalent
        ///
        /// \param rhs The instance against which to compare
        /// \retval true If \c this and \c rhs are equivalent
        /// \retval false If \c this and \c rhs are not equivalent
        ms_bool_t operator ==(class_type const &rhs) const
        {
            return compare(rhs) == 0;
        }

        /// Evaluates whether \c this and \c rhs are not equivalent
        ///
        /// \param rhs The instance against which to compare
        /// \retval true If \c this and \c rhs are not equivalent
        /// \retval false If \c this and \c rhs are equivalent
        ms_bool_t operator !=(class_type const &rhs) const
        {
            return compare(rhs) != 0;
        }

        // Bidirectional iterator operations

        /// Pre-decrement operator
        class_type &operator --()
        {
            --m_index;

            return *this;
        }

        /// Post-decrement operator
        class_type operator --(int)
        {
            class_type  ret(*this);

            operator --();

            return ret;
        }

        // Random access operations

        class_type &operator +=(difference_type index)
        {
            m_index += index;

            return *this;
        }

        class_type &operator -=(difference_type index)
        {
            m_index -= index;

            return *this;
        }

        class_type &operator -=(class_type const &rhs)
        {
            index_type  index   =   static_cast<index_type>(m_index) - static_cast<index_type>(rhs.m_index);

            return class_type(m_c, index);
        }

        value_type operator [](difference_type index) const
        {
            return m_c->GetAt(m_index + index);
        }

        /// Calculate the distance between \c this and \c rhs
        difference_type distance(class_type const &rhs) const
        {
            return m_index - rhs.m_index;
        }

    // Members
    protected:
        container_type const    *m_c;
        size_type               m_index;
    };

    /// Iterator class for the list_veneer class
    class iterator
        : public const_iterator
    {
    private:
        friend class array_veneer<C, T>;
    private:
        typedef const_iterator                                      parent_class_type;
        typedef iterator                                            class_type;
        typedef ss_typename_type_k parent_class_type::index_type    index_type;
        typedef container_type::pointer                             pointer;
        typedef container_type::reference                           reference;
    private:
        iterator(container_type *const c, index_type index)
            : parent_class_type(c, index)
        {}
    public:
        /// Default constructor
        iterator()
        {}
        /// Copy constructor
        ///
        /// \param rhs The instance from which to copy construct
        iterator(class_type const &rhs)
            : parent_class_type(rhs)
        {}

        /// Copy assignment operator
        ///
        /// \param rhs The instance from which to copy assign
        iterator const &operator =(class_type const &rhs)
        {
            MFCSTL_MESSAGE_ASSERT("Attempting to assign iterator from another container!", m_c == NULL || rhs.m_c == NULL || m_c == rhs.m_c);

            parent_class_type::operator =(rhs);

            return *this;
        }

        reference operator *()
        {
            MFCSTL_MESSAGE_ASSERT("", m_c != 0);

            return (*const_cast<container_type*>(m_c))[m_index];
        }

        const_reference operator *() const
        {
            return parent_class_type::operator *();
        }

        // Random access operations

        value_type &operator [](difference_type index)
        {
            return const_cast<container_type *>(m_c)->ElementAt(m_index + index);
        }

        value_type operator [](difference_type index) const
        {
            return parent_class_type::operator [](index);
        }

        class_type &operator -=(difference_type index)
        {
            m_index -= index;

            return *this;
        }

        class_type &operator -=(class_type const &rhs)
        {
            index_type  index   =   static_cast<index_type>(m_index) - static_cast<index_type>(rhs.m_index);

            return class_type(m_c, index);
        }
    };

/** \brief The reverse non-mutating (const) iterator type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef stlsoft_ns_qual(const_reverse_bidirectional_iterator_base)< const_iterator,
                                                                        value_type,
                                                                        value_type, // By-Value Temporary reference category
                                                                        void,       // By-Value Temporary reference category
                                                                        difference_type>    const_reverse_iterator;
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */


// Construction
public:
    /// Constructs an instance of the array adaptor
    ss_explicit_k array_veneer()
    {
        stlsoft_constraint_must_be_same_size(C, class_type);
    }

// Operations
public:
    void push_back(value_type const &v)
    {
        Add(v);
    }

// State
public:
    /// Returns the number of elements in the sequence
    size_type size() const
    {
        return static_cast<size_type>(GetSize());
    }
    /// Indicates whether the search sequence is empty
    ms_bool_t empty() const
    {
        return GetSize() == 0;
    }
    /// Returns the maximum number of elements in the sequence
    static size_type max_size()
    {
        return static_cast<size_type>(-1) / sizeof(value_type);
    }

// Iteration
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator begin() const
    {
        return const_iterator(this, 0);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator end() const
    {
        return const_iterator(this, size());
    }

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator begin()
    {
        return iterator(this, 0);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator end()
    {
        return iterator(this, size());
    }

//  const_reverse_iterator
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const
    {
        return const_reverse_iterator(end());
    }
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const
    {
        return const_reverse_iterator(begin());
    }
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Accessors
public:
    /// Returns a mutable reference to the element at the given \c index
    reference operator [](difference_type index)
    {
        return container_type::operator [](index);
    }

    /// Returns a copy of the element at the given \c index
    const_reference operator [](difference_type index) const
    {
        return GetAt(index);
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

// array_veneer<>::const_iterator

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::const_iterator operator +(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::difference_type n)
{
    return ss_typename_type_k array_veneer<C, T>::const_iterator(lhs) += n;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::const_iterator operator -(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::difference_type n)
{
    return ss_typename_type_k array_veneer<C, T>::const_iterator(lhs) -= n;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::const_iterator operator -(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::const_iterator const &rhs)
{
    return ss_typename_type_k array_veneer<C, T>::const_iterator(lhs) -= rhs;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator <(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::const_iterator const &rhs)
{
    return lhs.compare(rhs) < 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator >(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::const_iterator const &rhs)
{
    return lhs.compare(rhs) > 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator <=(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::const_iterator const &rhs)
{
    return lhs.compare(rhs) <= 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator >=(ss_typename_type_k array_veneer<C, T>::const_iterator const &lhs, ss_typename_type_k array_veneer<C, T>::const_iterator const &rhs)
{
    return lhs.compare(rhs) >= 0;
}

// array_veneer<>::iterator

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::iterator operator +(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::difference_type n)
{
    return ss_typename_type_k array_veneer<C, T>::iterator(lhs) += n;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::iterator operator -(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::difference_type n)
{
    return ss_typename_type_k array_veneer<C, T>::iterator(lhs) -= n;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ss_typename_type_k array_veneer<C, T>::iterator operator -(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::iterator const &rhs)
{
    typedef ss_typename_type_k array_veneer<C, T>::iterator iter_t;

    return iter_t(lhs) -= rhs;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator <(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::iterator const &rhs)
{
    return lhs.compare(rhs) < 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator >(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::iterator const &rhs)
{
    return lhs.compare(rhs) > 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator <=(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::iterator const &rhs)
{
    return lhs.compare(rhs) <= 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline ms_bool_t operator >=(ss_typename_type_k array_veneer<C, T>::iterator const &lhs, ss_typename_type_k array_veneer<C, T>::iterator const &rhs)
{
    return lhs.compare(rhs) >= 0;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace mfcstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_H_MFCSTL_ARRAY_VENEER */

/* ////////////////////////////////////////////////////////////////////// */
