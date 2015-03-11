/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/ref_ptr.hpp (originally MLRelItf.h, ::SynesisStd)
 *
 * Purpose:     Contains the ref_ptr template class.
 *
 * Created:     2nd November 1994
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/ref_ptr.hpp
///
/// Contains the ref_ptr template class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_REF_PTR
#define STLSOFT_INCL_STLSOFT_HPP_REF_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_REF_PTR_MAJOR      4
# define STLSOFT_VER_STLSOFT_HPP_REF_PTR_MINOR      6
# define STLSOFT_VER_STLSOFT_HPP_REF_PTR_REVISION   1
# define STLSOFT_VER_STLSOFT_HPP_REF_PTR_EDIT       472
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
 * Helper shims
 */

/// \brief Control shim for adding a reference on an RCI
///
/// \note The generic shim expects the RCI to have a method named AddRef(), which
/// has either no parameters, or has all default parameters
///
/// \note The behaviour of the ref_ptr is undefined if this method throws an
/// exception
template<ss_typename_param_k I>
inline void add_reference(I *pi)
{
    STLSOFT_ASSERT(NULL != pi);

    pi->AddRef();
}

/// \brief Control shim for releasing a reference on an RCI
///
/// \note The generic shim expects the RCI to have a method named Release(), which
/// has either no parameters, or has all default parameters
///
/// \note The behaviour of the ref_ptr is undefined if this method throws an
/// exception
template<ss_typename_param_k I>
inline void release_reference(I *pi)
{
    STLSOFT_ASSERT(NULL != pi);

    pi->Release();
}

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// This class provides RAII-safe handling of reference-counted interfaces. Its
/// notable feature is that it supports forward declaration of the leaf interface
/// so long as the base counting interface is visible in the scope of the
/// template parameterisation
///
/// \param T The value type
template<   ss_typename_param_k T
        ,   ss_typename_param_k I = T
        >
class ref_ptr
{
/// \name Types
/// @{
public:
    /// \brief The interface type: the type of the RCI (Reference-Counted Interface)
    typedef I               interface_type;
    /// \brief The counted type: the concrete type of the objects whose instances will be managed
    typedef T               counted_type;
    /// \brief The current instantiation of the type
    typedef ref_ptr<T, I>   class_type;
/// @}

/// \name Implementation
/// @{
private:
    /// \brief Helper function to effect downcast from interface type to counted type
    static counted_type *c_from_i(interface_type *i)
    {
        return static_cast<counted_type*>(i);
    }
    /// \brief Helper function to effect downcast from interface type to counted type
    static counted_type const *c_from_i(interface_type const *i)
    {
        return static_cast<counted_type*>(i);
    }
    /// \brief Helper function to effect upcast from counted type to interface type
    static interface_type *i_from_c(counted_type *c)
    {
        return c;
    }

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1300
    /// \brief Helper function to effect upcast from const counted type to interface type
    static interface_type *i_from_const_c(counted_type const *cc)
    {
        counted_type    *c  =   const_cast<counted_type *>(cc);

        return c;
    }
#endif /* compiler */

/// @}

/// \name Construction
/// @{
public:
    /// \brief Default constructor
    ref_ptr()
        : m_pi(NULL)
    {}
    /// \brief Construct from a raw pointer to the counted type, and a boolean that
    /// indicates whether a reference should be taken on the instance.
    ///
    /// \note It is usual that ref_ptr is used to "sink" an instance, i.e. to take
    /// ownership of it. In such a case, \c false should be specified as the second
    /// parameter. If, however, a reference is being "borrowed", then \c true should
    /// be specified.
    ref_ptr(counted_type *c, ss_bool_t bAddRef)
        : m_pi(i_from_c(c))
    {
        if( bAddRef &&
            NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }

    /// \brief Creates a copy of the given ref_ptr instance, and increments the 
    /// reference count on its referent object, if any
    ///
    /// \param rhs The instance to copy
    ref_ptr(class_type const &rhs)
        : m_pi(rhs.m_pi)
    {
        if(NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }

    template <ss_typename_param_k T2, ss_typename_param_k I2>
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1300
    ref_ptr(ref_ptr<T2, I2> const &rhs)
# if 0
        // We cannot use this form, as it would lead to instances with different
        // counted_type being cross cast invisibly. This would be a *very bad thing*
        : m_pi(rhs.m_pi)
# else /* ? 0 */
        : m_pi(i_from_const_c(rhs.get()))
# endif /* 0 */
    {
        if(NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }
#else /* ? compiler */
    ref_ptr(ref_ptr<T2, I2> &rhs)
# if 0
        // We cannot use this form, as it would lead to instances with different
        // counted_type being cross cast invisibly. This would be a *very bad thing*
        : m_pi(rhs.m_pi)
# else /* ? 0 */
        : m_pi(i_from_c(rhs.get()))
# endif /* 0 */
    {
        if(NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }
#endif /* compiler */

#if !defined(STLSOFT_COMPILER_IS_INTEL) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    0
    template <ss_typename_param_k I2>
    explicit ref_ptr(ref_ptr<T, I2> &rhs)
        : m_pi(rhs.m_pi)
    {
        if(NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }
#endif /* compiler */

    /// \brief Destructor. If the ref_ptr instance is still holding a pointer to a
    /// managed instance, it will be released.
    ~ref_ptr() stlsoft_throw_0()
    {
        if(NULL != m_pi)
        {
            release_reference(m_pi);
        }
    }

    /// \brief Copy assignment from a ref_ptr instance of the same type
    ///
    /// \note It is strongly exception-safe, as long as the implementations of the
    /// add-ref and release functions - as utilised in the \c add_reference() and
    /// \c release_reference() control shims - do not throw (which they must not).
    class_type &operator =(class_type const &rhs)
    {
        class_type  t(rhs);

        t.swap(*this);

        return *this;
    }

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER != 1300
    /// \brief Copy assignment from an instance of ref_ptr with a different counted_type (but
    /// the same interface type).
    ///
    /// \note This function template uses the copy constructor template, and has the same
    /// instantiation restrictions
    ///
    /// \note It is strongly exception-safe, as long as the implementations of the
    /// add-ref and release functions - as utilised in the \c add_reference() and
    /// \c release_reference() control shims - do not throw (which they must not).
    template <ss_typename_param_k T2>
    class_type &operator =(ref_ptr<T2, I> &rhs)
    {
        class_type  t(rhs);

        t.swap(*this);

        return *this;
    }
#endif /* compiler */

#if !defined(STLSOFT_COMPILER_IS_INTEL) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    0
    template <ss_typename_param_k I2>
    class_type &operator =(ref_ptr<T, I2> &rhs)
    {
        class_type  t(rhs);

        t.swap(*this);

        return *this;
    }
#endif /* compiler */
/// @}

/// \name Operations
/// @{
public:
    /// \brief Swaps the managed instance of \c this with \c rhs
    ///
    /// \note It provides the no-throw guarantee
    void swap(class_type &rhs)
    {
        interface_type  *t          =   rhs.m_pi;
                        rhs.m_pi    =   m_pi;
                        m_pi        =   t;
    }

    /// Closes the pointer
    ///
    /// \note Calling this method more than once has no effect.
    void close()
    {
        if(NULL != m_pi)
        {
            release_reference(m_pi);
            m_pi = NULL;
        }
    }

    /// \brief Detaches the managed instance, and returns it to the caller, which
    /// takes responsibility for ensuring that the resource is not leaked
    counted_type *detach()
    {
        counted_type    *r  =   class_type::c_from_i(m_pi);

        m_pi = NULL;

        return r;
    }
/// @}

/// \name Equality Comparison
/// @{
public:
    ss_bool_t equal(class_type const &rhs) const
    {
        return m_pi == rhs.m_pi;
    }
/// @}

/// \name Accessors
/// @{
public:
    ss_bool_t operator !() const
    {
        return NULL == m_pi;
    }

    /// \brief Provides raw-pointer access to the instance
    counted_type *get()
    {
        return class_type::c_from_i(m_pi);
    }

    /// \brief Provides raw-pointer access to the instance
    counted_type const *get() const
    {
        return class_type::c_from_i(m_pi);
    }

    counted_type *operator ->()
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return class_type::c_from_i(m_pi);
    }

    counted_type const *operator ->() const
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return class_type::c_from_i(m_pi);
    }

    counted_type &operator *()
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return *class_type::c_from_i(m_pi);
    }

    counted_type const &operator *() const
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return *class_type::c_from_i(m_pi);
    }
/// @}

/// \name Members
/// @{
private:
    interface_type  *m_pi;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

template<   ss_typename_param_k T
        ,   ss_typename_param_k I
        >
inline ss_bool_t operator ==(ref_ptr<T, I> const &lhs, ref_ptr<T, I> const &rhs)
{
    return lhs.equal(rhs);
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k I
        >
inline ss_bool_t operator !=(ref_ptr<T, I> const &lhs, ref_ptr<T, I> const &rhs)
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<   ss_typename_param_k T
        ,   ss_typename_param_k I
        >
inline void swap(ref_ptr<T, I> &lhs, ref_ptr<T, I> &rhs)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// is_empty shim
template<   ss_typename_param_k T
        ,   ss_typename_param_k I /* = T */
        >
inline ss_bool_t is_empty(ref_ptr<T, I> const &p)
{
    return NULL == p.get();
}

/// get_ptr shim
template<   ss_typename_param_k T
        ,   ss_typename_param_k I /* = T */
        >
inline T *get_ptr(ref_ptr<T, I> &p)
{
    return p.get();
}

/// get_ptr shim
template<   ss_typename_param_k T
        ,   ss_typename_param_k I /* = T */
        >
inline T const *get_ptr(ref_ptr<T, I> const &p)
{
    return p.get();
}

/// Insertion operator shim
template<   ss_typename_param_k S
        ,   ss_typename_param_k T
        ,   ss_typename_param_k I /* = T */
        >
inline S &operator <<(S &s, ref_ptr<T, I> const &p)
{
    return s << *p;
}

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/ref_ptr_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we 
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k T
            ,   ss_typename_param_k I
            >
    inline void swap(stlsoft_ns_qual(ref_ptr)<T, I> &lhs, stlsoft_ns_qual(ref_ptr)<T, I> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_REF_PTR */

/* ////////////////////////////////////////////////////////////////////// */
