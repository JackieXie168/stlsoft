/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/collections/collection_sequence.hpp (originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose:     STL sequence for COM collection interfaces.
 *
 * Created:     17th September 1998
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file comstl/collections/collection_sequence.hpp
///
/// STL sequence for COM collection interfaces.

#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE
#define COMSTL_INCL_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE_MAJOR    6
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE_MINOR    0
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE_REVISION 2
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE_EDIT     81
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

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS
# include <comstl/util/refcount_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES
# include <comstl/collections/enumeration_policies.hpp>
#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES */
#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS
# include <comstl/interface/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_HPP_EXCEPTIONS
#  include <comstl/exceptions.hpp>
# endif /* !COMSTL_INCL_COMSTL_HPP_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE
# include <comstl/collections/enumerator_sequence.hpp>
#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATOR_SEQUENCE */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#include <algorithm>

#ifdef STLSOFT_UNITTEST
# include <comstl/util/value_policies.hpp>
# if !defined(STLSOFT_COMPILER_IS_DMC)
#  include "./unittest/_recls_COM_decl_.h"
# endif /* compiler */
# include <stdio.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief A template for adapting COM enumeration to STL-compatible sequence iteration
 *
 * \ingroup group__library__collections
 *
 * \param I Interface
 * \param V Value type
 * \param VP Value policy type
 * \param R Reference type
 * \param CP Cloning policy type
 * \param Q Quanta
 *
 * The various parameterising types are used to stipulate the interface and the
 * value type, and how they are to be handled.
 *
 * For example, the following parameterisation defines a sequence operating
 * over a notional <b>IGUIDCollection</b> collection instance.
 *
 * \htmlonly
 * <table border = 0 cellspacing = 0 cellpadding = 0 >
 *  <tr><td>&nbsp;&nbsp;</td><td><code>typedef collection_sequence</code></td><td><code>&lt;&nbsp;IGUIDCollection</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;IEnumGUID</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID_policy</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID const &</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;forward_cloning_policy&lt;IEnumGUID&gt;</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;5</code></td></tr>
 *  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>&gt;&nbsp;&nbsp;&nbsp;collection_sequence_t;</code></td></tr>
 * </table>
 * \endhtmlonly
 *
 * The value type is <b>GUID</b> and it is returned as a reference, as
 * the <b>GUID const &</b> in fact.
 *
 * The \ref COMSTL type <b>GUID_policy</b> controls how the <b>GUID</b>
 * instances are initialised, copied and destroyed.
 *
 * The \ref COMSTL type forward_cloning_policy allows the sequence to provide
 * <a href = "http://sgi.com/tech/stl/ForwardIterator.html">Forward Iterator</a>
 * semantics.
 *
 * And the <b>5</b> indicates that the sequence should grab 5 values at a time,
 * to save round trips to the enumerator.
 *
 * So this would be used like the following:
 *
 * \htmlonly
 * <code>
 * &nbsp;&nbsp;void dump_GUID(GUID const &);
 * <br>
 *
 * <br>
 * &nbsp;&nbsp;IGUIDCollection&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*penGUIDs = . . .;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// Create an instance from wherever
 * <br>
 * &nbsp;&nbsp;collection_sequence_t&nbsp;&nbsp;&nbsp;guids(penGUIDs, false); // Eat the reference
 * <br>
 *
 * <br>
 * &nbsp;&nbsp;std::for_each(guids.begin(), guids.end(), dump_GUID);
 * <br>
 * </code>
 * \endhtmlonly
 *
 * \note The iterator instances returned by begin() and end() are valid outside
 * the lifetime of the collection instance from which they are obtained
 */
template<   ss_typename_param_k CI                                      /* Collection interface */
        ,   ss_typename_param_k EI                                      /* Enumerator interface */
        ,   ss_typename_param_k V                                       /* Value type */
        ,   ss_typename_param_k VP                                      /* Value policy type */
        ,   ss_typename_param_k R   =   V const &                       /* Reference type */
        ,   ss_typename_param_k CP  =   input_cloning_policy<EI>        /* Cloning policy type */
        ,   cs_size_t           Q   =   8                               /* Quanta */
        ,   ss_typename_param_k EAP =   new_enum_property_policy<CI>    /* Policy for acquiring the enumerator from the collection */
        >
class collection_sequence
    : public stlsoft_ns_qual(stl_collection_tag)
{
/// \name Member Types
/// @{
private:
    typedef enumerator_sequence<EI, V, VP, R, CP, Q>                            enumerator_sequence_type;
public:
    /// \brief Collection interface type
    typedef CI                                                                  collection_interface_type;
    /// \brief Enumerator interface type
    typedef ss_typename_type_k enumerator_sequence_type::interface_type         enumerator_interface_type;
    /// \brief Value type
    typedef ss_typename_type_k enumerator_sequence_type::value_type             value_type;
    /// \brief Value policy type
    typedef ss_typename_type_k enumerator_sequence_type::value_policy_type      value_policy_type;
    /// \brief Reference type
    typedef ss_typename_type_k enumerator_sequence_type::reference              reference;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef ss_typename_type_k enumerator_sequence_type::reference_type         reference_type; // For backwards compatiblity
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// \brief The pointer type
    typedef ss_typename_type_k enumerator_sequence_type::pointer                pointer;
    /// \brief The iterator type
    typedef ss_typename_type_k enumerator_sequence_type::iterator               iterator;
    /// \brief Cloning policy type
    typedef ss_typename_type_k enumerator_sequence_type::cloning_policy_type    cloning_policy_type;
    /// \brief Iterator tag type
    typedef ss_typename_type_k enumerator_sequence_type::iterator_tag_type      iterator_tag_type;
    /// \brief Retrieval quanta
    enum                                                                      { retrievalQuanta = enumerator_sequence_type::retrievalQuanta };
    /// \brief The policy for acquiring the enumerator from the collection
    typedef EAP                                                                 enumerator_acquisition_policy_type;
    /// \brief Type of the current parameterisation
    typedef collection_sequence<CI, EI, V, VP, R, CP, Q, EAP>                   class_type;
    /// \brief The size type
    typedef ss_typename_type_k enumerator_sequence_type::size_type              size_type;
    /// \brief The difference type
    typedef ss_typename_type_k enumerator_sequence_type::difference_type        difference_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructor
    ///
    /// \param i The enumeration interface pointer to adapt
    /// \param bAddRef Causes a reference to be added if \c true, otherwise the sequence is deemed to <i>sink</i>, or consume, the interface pointer
    /// \param quanta The actual quanta required for this instance. Must be <= Q
    ///
    /// \note This does not throw an exception, so it is safe to be used to "eat" the
    /// reference. The only possible exception to this is if COMSTL_ASSERT(), which is
    /// used to validate that the given quanta size is within the limit specified in
    /// the specialisation, has been redefined to throw an exception. But since
    /// precondition violations are no more recoverable than any others (see the article
    /// "The Nuclear Reactor and the Deep Space Probe"), this does not represent
    /// a concerning contradiction to the no-throw status of the constructor.
    collection_sequence(collection_interface_type *i, cs_bool_t bAddRef, size_type quanta = 0)
        : m_i(i)
        , m_quanta(validate_quanta_(quanta))
    {
        COMSTL_ASSERT(NULL != i);
        COMSTL_MESSAGE_ASSERT("Cannot set a quantum that exceeds the value specified in the template specialisation", quanta <= retrievalQuanta); // Could have named these things better!

        if(bAddRef)
        {
            m_i->AddRef();
        }

        COMSTL_ASSERT(is_valid());
    }
    /// \brief Releases the adapted interface pointer
    ~collection_sequence() stlsoft_throw_0()
    {
        COMSTL_ASSERT(is_valid());

        m_i->Release();
    }
/// @}

/// \name Iteration
/// @{
public:
    /// \brief Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator begin() const
    {
        COMSTL_ASSERT(is_valid());

        LPUNKNOWN   punkEnum;
        HRESULT     hr  =   enumerator_acquisition_policy_type::acquire(m_i, &punkEnum);

        if(SUCCEEDED(hr))
        {
            enumerator_interface_type   *ei;

            hr = punkEnum->QueryInterface(IID_traits<enumerator_interface_type>::iid(), reinterpret_cast<void**>(&ei));

            punkEnum->Release();

            if(SUCCEEDED(hr))
            {
                COMSTL_ASSERT(is_valid());

                return enumerator_sequence_type(ei, false, m_quanta).begin();
            }
            else
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                COMSTL_ASSERT(is_valid());

                throw com_exception("the enumerator does not provide the requested interface", hr);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
        else
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            COMSTL_ASSERT(is_valid());

            throw com_exception("enumerator could not be elicited from the collection", hr);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER < 1310)
        COMSTL_ASSERT(is_valid());

        return iterator();
#endif /* compiler */
    }
    /// \brief Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator end() const
    {
        COMSTL_ASSERT(is_valid());

        return iterator();
    }
/// @}

/// \name Capacity
/// @{
    /// \brief Returns the number of items in the collection
    ///
    /// \note This method will not compile for collection interfaces
    /// that do not contain the get_Count method
    size_type size() const
    {
        COMSTL_ASSERT(is_valid());

        ULONG   count;
        HRESULT hr  =   m_i->get_Count(&count);

        COMSTL_ASSERT(is_valid());

        return SUCCEEDED(hr) ? count : 0;
    }
/// @}

/// \name Invariant
/// @{
private:
    cs_bool_t is_valid() const
    {
        if(NULL == m_i)
        {
            return false;
        }

        return true;
    }
/// @}

// Implementation
private:
    static size_type validate_quanta_(size_type quanta)
    {
        COMSTL_MESSAGE_ASSERT("Cannot set a quantum that exceeds the value specified in the template specialisation", quanta <= retrievalQuanta); // Could have named these things better!

        if( 0 == quanta ||
            quanta > retrievalQuanta)
        {
            quanta = retrievalQuanta;
        }

        return quanta;
    }

// Members
private:
    collection_interface_type   *m_i;
    size_type const             m_quanta;

// Not to be implemented
private:
    collection_sequence(class_type const &);
    class_type const &operator =(class_type const &);
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/collection_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////// */
