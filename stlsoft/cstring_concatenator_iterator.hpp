/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/cstring_concatenator_iterator.hpp
 *
 * Purpose:     cstring_concatenator_iterator class template.
 *
 * Created:     20th June 2005
 * Updated:     18th December 2005
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


/// \file stlsoft/cstring_concatenator_iterator.hpp
///
/// cstring_concatenator_iterator class template.

#ifndef STLSOFT_INCL_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR
#define STLSOFT_INCL_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR_MAJOR    1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR_MINOR    1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR_EDIT     8
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
#ifndef STLSOFT_INCL_STLSOFT_HPP_POD_ALGORITHMS
# include <stlsoft/algorithms/pod.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_POD_ALGORITHMS */

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

/// This output iterator adaptor template wraps a C-string pointer as an output
/// iterator, to enable a c-string to be built up as a result of the application
/// of an algorithm
///
/// \param C The character type of the C-string
template <ss_typename_param_k C>
class cstring_concatenator_iterator
{
public:
    typedef C                                           value_type;
    typedef ss_ptrdiff_t                                difference_type;
    typedef void                                        reference;
    typedef void                                        pointer;
    typedef stlsoft_ns_qual_std(output_iterator_tag)    iterator_category;
    typedef cstring_concatenator_iterator<C>            class_type;
private:
    typedef cstring_concatenator_iterator<C>            concatenator_iterator_type;
private:
    class deref_proxy;
    friend class deref_proxy;

/// \name Construction
/// @{
public:
    /// Creates an instance of the cstring_concatenator_iterator from the given 
    /// c-string pointer
    ///
    /// \param s The C-string which in which will be written the results of the 
    /// application of the iterator's dereference. May not be NULL
    /// \param pnWritten An optional paramter to receive a count of how many
    /// bytes were written by the iterator. <b>Note</b>: the variable pointed to
    /// by this parameter is <i>not</i> set to 0 by the concatenator class. It
    /// must be initialised in by the caller
    cstring_concatenator_iterator(value_type *s, size_t *pnWritten = NULL)
        : m_s(s)
        , m_nWritten((NULL != pnWritten) ? *pnWritten : m_nWrittenDummy)
//      , m_nWrittenDummy(0)    // There is no need to initialise this!
    {
        STLSOFT_ASSERT(NULL != s);
    }
/// @}

/// \name Iteration
/// @{
public:
    class_type &operator ++()
    {
        return *this;
    }

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
            // 'Fire' the shims, and pass to the proxied iterator instance
            m_it->concat_(::stlsoft::c_str_data(s), ::stlsoft::c_str_len(s));
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
    void concat_(value_type const *s, size_t len)
    {
        pod_copy_n(m_s, s, len);

        m_s         += len;
        m_nWritten  += len;
    }
/// @}

/// \name Members
/// @{
private:
    value_type  *m_s;
    size_t      &m_nWritten;
    size_t      m_nWrittenDummy;    // Dummy member here, so test is only carried out once
/// @}

// Not to be implemented
private:
    class_type operator ++(int);    // This should never be called!

private:
    class_type &operator =(class_type const &);
};

/// Creates an instance of the cstring_concatenator_iterator from the given 
/// c-string pointer
///
/// \param s The C-string which in which will be written the results of the 
/// application of the iterator's dereference. May not be NULL
/// \param pnWritten An optional paramter to receive a count of how many
/// bytes were written by the iterator. <b>Note</b>: the variable pointed to
/// by this parameter is <i>not</i> set to 0 by the concatenator class. It
/// must be initialised in by the caller
template <ss_typename_param_k C>
inline cstring_concatenator_iterator<C> cstring_concatenator(C *s, size_t *pnWritten)
{
    return cstring_concatenator_iterator<C>(s, pnWritten);
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

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_CSTRING_CONCATENATOR_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
