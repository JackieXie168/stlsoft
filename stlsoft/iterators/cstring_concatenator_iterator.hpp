/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterators/cstring_concatenator_iterator.hpp
 *
 * Purpose:     cstring_concatenator_iterator class template.
 *
 * Created:     20th June 2005
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file stlsoft/iterators/cstring_concatenator_iterator.hpp
///
/// cstring_concatenator_iterator class template.

#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR_MAJOR      2
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR_MINOR      0
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR_REVISION   8
# define STLSOFT_VER_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR_EDIT       19
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
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD
# include <stlsoft/algorithms/pod.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALGORITHMS_POD */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup iterators Iterators
/// \brief STL-compatible iterators

/// \weakgroup iterators_output Output Iterators
/// \brief Classes that provide Output Iteration functionality
/// \ingroup iterators
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// This output iterator adaptor template wraps a C-style string pointer as an
/// output iterator, to enable a C-style string to be built up as a result of the
/// application of an algorithm.
///
/// \param C The character type of the C-string
template <ss_typename_param_k C>
// [[synesis:class:iterator: cstring_concatenator_iterator<T<C>>]]
class cstring_concatenator_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    typedef C                                   char_type;
    typedef ss_size_t                           size_type;
    typedef cstring_concatenator_iterator<C>    class_type;
private:
    typedef cstring_concatenator_iterator<C>    concatenator_iterator_type;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    /// Creates an instance of the cstring_concatenator_iterator from the given
    /// c-string pointer
    ///
    /// \param dest The C-string which in which will be written the results of the
    /// application of the iterator's dereference. May not be NULL
    /// \param pNumWritten An optional paramter to receive a count of how many
    /// bytes were written by the iterator. <b>Note</b>: the variable pointed to
    /// by this parameter is <i>not</i> set to 0 by the concatenator class. It
    /// must be initialised by the caller.
    /// \param pNumWritten Pointer to an unsigned integer that receives the number
    /// of characters written by the iterator, or NULL if not required
    ss_explicit_k cstring_concatenator_iterator(char_type *dest, size_type *pNumWritten = NULL)
        : m_dest(dest)
        , m_numWritten((NULL != pNumWritten) ? pNumWritten : dummy_())
    {
//      *m_numWritten = 0;

        STLSOFT_ASSERT(NULL != m_dest);
    }
/// @}

/// \name Iteration
/// @{
public:
    /// Pre-increment operator
    class_type &operator ++()
    {
        return *this;
    }
    /// Post-increment operator
    class_type &operator ++(int)
    {
        return *this;
    }

    /// Dereference operator
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
/// @}

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(concatenator_iterator_type *it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k S>
        void operator =(S const &s)
        {
            m_it->invoke_(s);
        }

    private:
        concatenator_iterator_type  *const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const &);
    };
/// @}

/// \name Implementation
/// @{
private:
    void concat_(char_type const *s, size_type len)
    {
        pod_copy_n(m_dest, s, len);

        m_dest          +=  len;
        *m_numWritten   +=  len;
    }
    template <ss_typename_param_k S>
    void invoke_(S const &s)
    {
        // 'Fire' the shims, and pass to the proxied iterator instance
        this->concat_(::stlsoft::c_str_data(s), ::stlsoft::c_str_len(s));
    }

    static size_type *dummy_()  // Need this, because VC++ crashes on write to member referent
    {
        static size_type    s_dummy;

        return &s_dummy;
    }
/// @}

/// \name Members
/// @{
private:
    char_type   *m_dest;
    size_type   *m_numWritten;
/// @}
};

#if 0
/// Creates an instance of the cstring_concatenator_iterator from the given
/// c-string pointer
///
/// \param s The C-string which in which will be written the results of the
/// application of the iterator's dereference. May not be NULL
/// \param numWritten An optional paramter to receive a count of how many
/// bytes were written by the iterator. <b>Note</b>: the variable pointed to
/// by this parameter is <i>not</i> set to 0 by the concatenator class. It
/// must be initialised in by the caller
template <ss_typename_param_k C>
inline cstring_concatenator_iterator<C> cstring_concatenator(C *s, ss_size_t &numWritten)
{
    return cstring_concatenator_iterator<C>(s, &numWritten);
}

/// Creates an instance of the cstring_concatenator_iterator from the given
/// c-string pointer
///
/// \param s The C-string which in which will be written the results of the
/// application of the iterator's dereference. May not be NULL
template <ss_typename_param_k C>
inline cstring_concatenator_iterator<C> cstring_concatenator(C *s)
{
    return cstring_concatenator_iterator<C>(s, NULL);
}

#else /* ? 0 */

/// \brief Creator function for cstring_concatenator_iterator
///
/// \param s Pointer to the string buffer into which elements will be concatenated
/// \param pNumWritten Optional pointer to receive the number of characters written to the buffer
///
/// \return An instance of the specialisation cstring_concatenator_iterator&lt;C&gt;
template <ss_typename_param_k C>
inline cstring_concatenator_iterator<C> make_cstring_concatenator_iterator(C *s, ss_size_t *pNumWritten = NULL)
{
    return cstring_concatenator_iterator<C>(s, pNumWritten);
}

/// Creates an instance of the cstring_concatenator_iterator from the given
/// c-string pointer
///
/// \param s The C-string which in which will be written the results of the
/// application of the iterator's dereference. May not be NULL
/// \param pNumWritten An optional paramter to receive a count of how many
/// bytes were written by the iterator. <b>Note</b>: the variable pointed to
/// by this parameter is <i>not</i> set to 0 by the concatenator class. It
/// must be initialised in by the caller
///
/// \note Short-hand for make_cstring_concatenator_iterator()
template <ss_typename_param_k C>
inline cstring_concatenator_iterator<C> cstring_concatenator(C *s, ss_size_t *pNumWritten = NULL)
{
    return make_cstring_concatenator_iterator(s, pNumWritten);
}

#endif /* 0 */

////////////////////////////////////////////////////////////////////////////////

/// @} // end of group

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/cstring_concatenator_iterator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */