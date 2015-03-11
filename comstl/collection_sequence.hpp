/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/collection_sequence.hpp (formerly comstl/coll_sequence.hpp, comstl_collection_sequence.h; originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose:     STL sequence for COM collection interfaces.
 *
 * Created:     17th September 1998
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2005, Matthew Wilson and Synesis Software
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


/// \file comstl/collection_sequence.hpp
///
/// STL sequence for COM collection interfaces.

#ifndef COMSTL_INCL_COMSTL_HPP_COLLECTION_SEQUENCE
#define COMSTL_INCL_COMSTL_HPP_COLLECTION_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_COLLECTION_SEQUENCE_MAJOR    5
# define COMSTL_VER_COMSTL_HPP_COLLECTION_SEQUENCE_MINOR    0
# define COMSTL_VER_COMSTL_HPP_COLLECTION_SEQUENCE_REVISION 1
# define COMSTL_VER_COMSTL_HPP_COLLECTION_SEQUENCE_EDIT     66
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

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS
# include <comstl/refcount_functions.h> // safe_release, release_set_null
#endif /* !COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_HPP_ENUMERATION_POLICIES
# include <comstl/enumeration_policies.hpp> // input_cloning_policy
#endif /* !COMSTL_INCL_COMSTL_HPP_ENUMERATION_POLICIES */
#ifndef COMSTL_INCL_COMSTL_HPP_INTERFACE_TRAITS
# include <comstl/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_HPP_INTERFACE_TRAITS */
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_HPP_EXCEPTIONS
#  include <comstl/exceptions.hpp>
# endif /* !COMSTL_INCL_COMSTL_HPP_EXCEPTIONS */
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#include <algorithm>

#ifdef STLSOFT_UNITTEST
# include <comstl/value_policies.hpp>
# if !defined(STLSOFT_COMPILER_IS_DMC)
#  include "./unittest/_recls_COM_decl_.h"
# endif /* compiler */
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup comstl_itf_library Interface Library
/// \ingroup COMSTL libraries
/// \brief This library provides facilities for manipulating COM interfaces
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// A template for adapting COM enumeration to STL-compatible sequence iteration
///
/// \param I Interface
/// \param V Value type
/// \param VP Value policy type
/// \param R Reference type
/// \param CP Cloning policy type
/// \param Q Quanta
///
/// The various parameterising types are used to stipulate the interface and the
/// value type, and how they are to be handled.
///
/// For example, the following parameterisation defines a sequence operating
/// over a notional <b>IGUIDCollection</b> collection instance.
///
/// \htmlonly
/// <table border = 0 cellspacing = 0 cellpadding = 0 >
///  <tr><td>&nbsp;&nbsp;</td><td><code>typedef collection_sequence</code></td><td><code>&lt;&nbsp;IGUIDCollection</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;IEnumGUID</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID_policy</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;GUID const &</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;forward_cloning_policy&lt;IEnumGUID&gt;</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>,&nbsp;5</code></td></tr>
///  <tr><td>&nbsp;&nbsp;</td><td><code>&nbsp;</code></td><td><code>&gt;&nbsp;&nbsp;&nbsp;collection_sequence_t;</code></td></tr>
/// </table>
/// \endhtmlonly
///
/// The value type is <b>GUID</b> and it is returned as a reference, as
/// the <b>GUID const &</b> in fact.
///
/// The \ref COMSTL type <b>GUID_policy</b> controls how the <b>GUID</b>
/// instances are initialised, copied and destroyed.
///
/// The \ref COMSTL type forward_cloning_policy allows the sequence to provide
/// <a href = "http://sgi.com/tech/stl/ForwardIterator.html">Forward Iterator</a>
/// semantics.
///
/// And the <b>5</b> indicates that the sequence should grab 5 values at a time,
/// to save round trips to the enumerator.
///
/// So this would be used like the following:
///
/// \htmlonly
/// <code>
/// &nbsp;&nbsp;void dump_GUID(GUID const &);
/// <br>
///
/// <br>
/// &nbsp;&nbsp;IGUIDCollection&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*penGUIDs = . . .;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// Create an instance from wherever
/// <br>
/// &nbsp;&nbsp;collection_sequence_t&nbsp;&nbsp;&nbsp;guids(penGUIDs, false); // Eat the reference
/// <br>
///
/// <br>
/// &nbsp;&nbsp;std::for_each(guids.begin(), guids.end(), dump_GUID);
/// <br>
/// </code>
/// \endhtmlonly
///
template<   ss_typename_param_k CI                                      /* Collection interface */
        ,   ss_typename_param_k EI                                      /* Enumerator interface */
        ,   ss_typename_param_k V                                       /* Value type */
        ,   ss_typename_param_k VP                                      /* Value policy type */
        ,   ss_typename_param_k R   =   V const &                       /* Reference type */
        ,   ss_typename_param_k CP  =   degenerate_cloning_policy<EI>   /* Cloning policy type */
        ,   cs_size_t           Q   =   8                               /* Quanta */
        >
class collection_sequence
{
public:
    /// Colleciton interface type
    typedef CI                                                          collection_interface_type;
    /// Enumerator interface type
    typedef EI                                                          enumerator_interface_type;
    /// Value type
    typedef V                                                           value_type;
    /// Value policy type
    typedef policy_adaptor<VP>                                          value_policy_type;
    /// Reference type
    typedef R                                                           reference;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef R                                                           reference_type; // For backwards compatiblity
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The pointer type
    typedef value_type                                                  *pointer;
    /// Cloning policy type
    typedef CP                                                          cloning_policy_type;
    /// Iterator tag type
    typedef ss_typename_type_k cloning_policy_type::iterator_tag_type   iterator_tag_type;
    /// Retrieval quanta
    enum                                                                { retrievalQuanta = Q };
    /// Type of the current parameterisation
    typedef collection_sequence<CI, EI, V, VP, R, CP, Q>                class_type;
    /// Type of the current parameterisation
    typedef class_type                                                  sequence_type;
    /// The size type
    typedef cs_size_t                                                   size_type;
    /// The difference type
    typedef cs_ptrdiff_t                                                difference_type;

public:
    /// Constructor
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
        if(bAddRef)
        {
            m_i->AddRef();
        }
    }
    /// Releases the adapted interface pointer
    ~collection_sequence() stlsoft_throw_0()
    {
        m_i->Release();
    }

public:
    /// Iterator for the collection_sequence class
    class iterator
        : public stlsoft_ns_qual(iterator_base)<iterator_tag_type
                                            ,   value_type
                                            ,   cs_ptrdiff_t
                                            ,   value_type*
                                            ,   value_type&>
    {
    public:
        typedef iterator                                                    class_type;
#if defined(STLSOFT_COMPILER_IS_GCC)
        typedef ss_typename_type_k sequence_type::enumerator_interface_type enumerator_interface_type;
        typedef ss_typename_type_k sequence_type::cloning_policy_type       cloning_policy_type;
        typedef ss_typename_type_k sequence_type::reference_type            reference_type;
        typedef ss_typename_type_k sequence_type::value_type                value_type;
#endif /* compiler */

    private:
        friend class collection_sequence<CI, EI, V, VP, R, CP, Q>;

        /// Value constructor
        iterator(enumerator_interface_type *i, size_type quanta)
            : m_i(i)
            , m_acquired(0)
            , m_current(0)
            , m_quanta(quanta)
        {
            init_elements_(m_quanta);

            // Note: We don't add a reference here, because get__NewEnum() has acquired a reference.

            operator ++();
        }
    public:
        /// Default constructor
        iterator()
            : m_i(0)
            , m_acquired(0)
            , m_current(0)
            , m_quanta(0)
        {
//            init_elements_(retrievalQuanta);
        }
        /// Copy constructor
        ///
        /// \note If the cloning policy is not forward iterator, or does not support forward iterator, then this
        /// becomes a Move Constructor (see <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">Move constructor</a>)
        iterator(class_type const &rhs)
            : m_i(cloning_policy_type::clone(const_cast<enumerator_interface_type*>(rhs.m_i)))
            , m_acquired(rhs.m_acquired)
            , m_current(rhs.m_current)
            , m_quanta(rhs.m_quanta)
        {
            COMSTL_ASSERT(rhs.m_acquired <= m_quanta);

            value_type          *begin      =   &m_values[0];
            value_type          *end        =   &m_values[0] + m_quanta;
            value_type const    *src_begin  =   &rhs.m_values[0];
            value_type const    *src_end    =   &rhs.m_values[0] + rhs.m_acquired;

            // Initialise and then copy each element up to the common extent ...
            for(; src_begin != src_end; ++begin, ++src_begin)
            {
                value_policy_type::init(begin);
                value_policy_type::copy(begin, src_begin);
            }

            // ... and then initialise the remainder, if any
            for(; begin != end; ++begin)
            {
                value_policy_type::init(begin);
            }
        }
        /// Releases any internal storage
        ~iterator() stlsoft_throw_0()
        {
            clear_elements_();

            safe_release(m_i);
        }

    public:
        /// Pre-increment operator
        iterator &operator ++()
        {
            if(++m_current < m_acquired)
            {
                // Do nothing
            }
            else if(NULL == m_i)
            {
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator", 0 < m_acquired && m_acquired < m_quanta && m_current == m_acquired);

                clear_elements_();

                m_acquired = 0;
            }
            else
            {
                COMSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator", NULL != m_i);

                clear_elements_();

                // Reset enumeration
                m_current = 0;

                ULONG   cFetched    =   0;
                HRESULT hr          =   m_i->Next(m_quanta, &m_values[0], &cFetched);

                // We no longer checked for a FAILED(hr), since some iterators
                // return invalid results. We rely on cFetched, which is the
                // only reliable guide when marshalling anyway

                m_acquired = cFetched;

                if( hr == S_FALSE ||
                    0 == m_acquired)
                {
                    release_set_null(m_i);
                }
            }

            return *this;
        }

        class_type operator ++(int)
        {
            class_type  r(*this);

            operator ++();

            return r;
        }

    public:
        /// Returns the value represented by the current iteration position
        reference operator *()
        {
            return m_values[m_current];
        }

        /// Returns the value represented by the current iteration position
        pointer operator ->()
        {
            return m_values + m_current;
        }

    public:
        /// Evaluates whether \c this and \c rhs are equivalent
        cs_bool_t equal(iterator const &rhs) const
        {
            // The only valid comparison is when they both represent the end
            // values.

            // NOTE: This is somewhere between Input and Forward!

            return m_acquired == 0 && m_i == 0 && rhs.m_acquired == 0 && rhs.m_i == 0;
        }
        /// Evaluates whether \c this and \c rhs are equivalent
        cs_bool_t operator == (iterator const &rhs) const
        {
            return this->equal(rhs);
        }
        /// Evaluates whether \c this and \c rhs are not equivalent
        cs_bool_t operator != (iterator const &rhs) const
        {
            return !this->equal(rhs);
        }

    /// \name Implementation
    /// @{
    private:
        void clear_elements_()
        {
            comstl_ns_qual_std(for_each)(   &m_values[0], &m_values[0] + m_acquired
                                        ,   
#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_DMC) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1300)
                                            ss_typename_type_k 
#endif /* compiler */
                                                value_policy_type::clear_element());
        }

        void init_elements_(size_type n)
        {
            comstl_ns_qual_std(for_each)(   &m_values[0], &m_values[0] + n
                                        ,   
#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_DMC) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1300)
                                            ss_typename_type_k 
#endif /* compiler */
                                                value_policy_type::init_element());
        }
    /// @}

    /// \name Members
    /// @{
    private:
        enumerator_interface_type   *m_i;
        size_type                   m_acquired;
        size_type                   m_current;
        size_type const             m_quanta;
        value_type                  m_values[retrievalQuanta];
    /// @}

    // Not to be implemented
    private:
        class_type &operator =(class_type const&);
    };

public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator begin() const
    {
        LPUNKNOWN   punkEnum;
        HRESULT     hr  =   m_i->get__NewEnum(&punkEnum);

        if(SUCCEEDED(hr))
        {
            enumerator_interface_type   *ei;

            hr = punkEnum->QueryInterface(IID_traits<enumerator_interface_type>::iid(), reinterpret_cast<void**>(&ei));

            punkEnum->Release();

            if(SUCCEEDED(hr))
            {
                return iterator(ei, m_quanta);
            }
            else
            {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
                throw com_exception("the enumerator does not provide the requested interface", hr);
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
        else
        {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
            throw com_exception("enumerator could not be elicited from the collection", hr);
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
        }

#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER < 1310)
        return iterator();
#endif /* compiler */
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator end() const
    {
        return iterator();
    }

    /// Returns the number of items in the collection
    ///
    /// \note This method will not compile for collection interfaces
    /// that do not contain the get_Count method
    size_type size() const
    {
        ULONG   count;
        HRESULT hr  =   m_i->get_Count(&count);

        return SUCCEEDED(hr) ? count : 0;
    }

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

// Implementation
private:
    collection_sequence(class_type const &);
    class_type const &operator =(class_type const &);
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/collection_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_itf_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_COLLECTION_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
