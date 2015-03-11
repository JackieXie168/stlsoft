/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/ptr_proxy.hpp
 *
 * Purpose:     Contains the ptr_proxy template class.
 *
 * Created:     17th January 1999
 * Updated:     12th March 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/ptr_proxy.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::ptr_proxy smart
 *   pointer class template
 *   (\ref group__library__smart_pointers "Smart Pointers" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PTR_PROXY
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PTR_PROXY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PTR_PROXY_MAJOR       4
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PTR_PROXY_MINOR       0
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PTR_PROXY_REVISION    1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PTR_PROXY_EDIT        66
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
class ptr_proxy;

template <ss_typename_param_k T>
class proxy_ptr;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class ptr_proxy
/** \brief This class emulates a pointer in all respects, and is useful as
 *    a generic code testing tool, and is simply an aid to
 *    self-documentation.
 *
 * \ingroup group__library__smart_pointers
 *
 * \param T The value type
 */
template <ss_typename_param_k T>
class ptr_proxy
{
public:
    /// The value type
    typedef T                       value_type;
    /// The current parameterisation of the type
    typedef ptr_proxy<T>            class_type;

// Construction
public:
    /// Construct from a pointer to "borrow"
    ss_explicit_k ptr_proxy(value_type *t)
        : m_value(t)
    {}
    /// Assignment from a new pointer
    ptr_proxy &operator =(value_type *t)
    {
        m_value = t;

        return *this;
    }

// Conversion
public:
    /// Implicit conversion to pointer to the underlying pointer
    operator value_type *()
    {
        return m_value;
    }
    /// Implicit conversion to pointer-to-const to the underlying pointer
    operator value_type const* () const
    {
        return m_value;
    }

    /// Indirection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type& operator *() // indirection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return *m_value;
    }
    /// Indirection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type const& operator *() const // indirection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return *m_value;
    }
    /// Member-selection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type* operator ->() // member-selection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return m_value;
    }
    /// Member-selection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type const* operator ->() const // member-selection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return m_value;
    }

    /// Returns the underlying pointer value
    value_type* get_ptr()
    {
        return m_value;
    }
    /// Returns the underlying pointer value
    value_type const* get_ptr() const
    {
        return m_value;
    }

    /// Returns the underlying pointer value
    value_type* get()
    {
        return m_value;
    }
    /// Returns the underlying pointer value
    value_type const* get() const
    {
        return m_value;
    }

    /// Returns the underlying pointer value
    ///
    /// \deprecated
    value_type* GetPointer()
    {
        return m_value;
    }
    /// Returns the underlying pointer value
    ///
    /// \deprecated
    value_type const* GetPointer() const
    {
        return m_value;
    }

    /// Sets the underlying pointer value to null
    void clear()
    {
        m_value = NULL;
    }

// Members
private:
    value_type  *m_value;
};


// class proxy_ptr
/** \brief This is the old form of ptr_proxy.
 *
 * \ingroup group__library__smart_pointers
 *
 * \deprecated Users should use ptr_proxy
 */
template <ss_typename_param_k T>
class proxy_ptr
    : public ptr_proxy<T>
{
private:
    typedef ptr_proxy<T>            parent_class_type;
public:
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type    value_type;
    /// The current parameterisation of the type
    typedef proxy_ptr<T>                                        class_type;

// Construction
public:
    /// Construct from a pointer to "borrow"
    ss_explicit_k proxy_ptr(value_type *t)
        : parent_class_type(t)
    {}
    /// Assignment from a new pointer
    proxy_ptr &operator =(value_type *t)
    {
        parent_class_type::operator =(t);

        return *this;
    }
};


/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** \brief get_ptr shim
 *
 * \ingroup group__library__smart_pointers
 */
template <ss_typename_param_k T>
inline T* get_ptr(ptr_proxy<T>& p)
{
    return p.get();
}

/** \brief get_ptr shim
 *
 * \ingroup group__library__smart_pointers
 */
template <ss_typename_param_k T>
inline T const* get_ptr(ptr_proxy<T> const& p)
{
    return p.get();
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/ptr_proxy_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PTR_PROXY */

/* ////////////////////////////////////////////////////////////////////// */
