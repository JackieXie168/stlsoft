/* ////////////////////////////////////////////////////////////////////////////
 * File:        comstl/interface_ptr.hpp (formerly comstl_interface_ptr.h; originally MLRelItf.h; ::SynesisCom)
 *
 * Purpose:     Interface management helper classes.
 *
 * Created:     2nd November 1994
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2005, Matthew Wilson and Synesis Software
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


/// \file comstl/interface_ptr.hpp
///
/// Interface management helper classes.

#ifndef COMSTL_INCL_COMSTL_HPP_INTERFACE_PTR
#define COMSTL_INCL_COMSTL_HPP_INTERFACE_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_INTERFACE_PTR_MAJOR      5
# define COMSTL_VER_COMSTL_HPP_INTERFACE_PTR_MINOR      1
# define COMSTL_VER_COMSTL_HPP_INTERFACE_PTR_REVISION   1
# define COMSTL_VER_COMSTL_HPP_INTERFACE_PTR_EDIT       470
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS
# include <comstl/refcount_functions.h> // for addref(), release(), etc.
#endif /* !COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL
# include <stlsoft/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

/* ////////////////////////////////////////////////////////////////////////////
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

/// \weakgroup comstl_refcount_functions COM Reference Management Functions
/// \ingroup COMSTL
/// \brief These functions assist in the management of object reference counts
/// @{

/* ////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Manages a COM interface pointer, ensuring that it is released
template <ss_typename_param_k T>
class interface_ptr
{
/// \name Types
/// @{
public:
    typedef interface_ptr<T>        class_type;

    typedef T                       value_type;
    typedef value_type              *pointer;
    typedef value_type const        *const_pointer;
    typedef value_type              &reference;
    typedef value_type const        &const_reference;
/// @}

/// \name Construction
/// @{
public:
     interface_ptr();
     interface_ptr(pointer p, cs_bool_t bAddRef);
     interface_ptr(reference r, cs_bool_t bAddRef);
     interface_ptr(class_type const &rhs);
    ~interface_ptr() stlsoft_throw_0();

    class_type &operator =(class_type const &rhs);
/// @}

/// \name Operations
/// @{
public:
    void    set(pointer p, cs_bool_t bAddRef);
    void    set(reference r, cs_bool_t bAddRef);
    void    release();
    void    release(cs_bool_t bDecRef /* = true */);
    pointer detach();
    void    swap(class_type &rhs);
/// @}

/// \name Comparison
/// @{
public:
    cs_bool_t operator ==(class_type const &rhs) const;
    cs_bool_t operator !=(class_type const &rhs) const;
/// @}

/// \name State
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    operator operator_bool_type() const;

//    cs_bool_t operator !() const;
/// @}

/// \name Accessors
/// @{
public:
    const_pointer   operator ->() const;
    pointer         operator ->();
    const_reference operator *() const;
    reference       operator *();

    const_pointer   get_interface_ptr() const;
    pointer         get_interface_ptr();
/// @}

private:
    pointer m_p;
};

/* /////////////////////////////////////////////////////////////////////////////
 * swapping
 */

template <ss_typename_param_k T>
inline void swap(interface_ptr<T> &lhs, interface_ptr<T> &rhs)
{
    lhs.swap(rhs);
}

////////////////////////////////////////////////////////////////////////////////
// Shims

template <ss_typename_param_k T>
inline cs_bool_t is_empty(interface_ptr<T> const &p)
{
    return NULL == p.get_interface_ptr();
}

template <ss_typename_param_k T>
inline T const *get_ptr(interface_ptr<T> const &p)
{
    return p.get_interface_ptr();
}

template <ss_typename_param_k T>
inline T *get_ptr(interface_ptr<T> &p)
{
    return p.get_interface_ptr();
}

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/interface_ptr_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

// interface_ptr

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline void interface_ptr<T>::swap(interface_ptr<T> &rhs)
{
    std_swap(m_p, rhs.m_p);
}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr()
    : m_p(NULL)
{}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::pointer p, cs_bool_t bAddRef)
    : m_p(p)
{
    if( bAddRef &&
        NULL != m_p)
    {
        addref(m_p);
    }
}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::reference r, cs_bool_t bAddRef)
    : m_p(&r)
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", NULL != m_p);

    if(bAddRef)
    {
        addref(m_p);
    }
}

template <ss_typename_param_k T>
inline interface_ptr<T>::interface_ptr(ss_typename_type_k interface_ptr<T>::class_type const &rhs)
    : m_p(rhs.m_p)
{
    safe_addref(m_p);
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::release()
{
    release_set_null(m_p);
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::release(cs_bool_t bDecRef /* = true */)
{
    if(NULL != m_p)
    {
        if(bDecRef)
        {
            comstl__release(m_p);
        }

        m_p = NULL;
    }
}

template <ss_typename_param_k T>
inline interface_ptr<T>::~interface_ptr() stlsoft_throw_0()
{
    release();
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::class_type &interface_ptr<T>::operator =(ss_typename_type_k interface_ptr<T>::class_type const &rhs)
{
    class_type   t(const_cast<class_type&>(rhs).m_p, true);

    swap(t);

    return *this;
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::set(ss_typename_type_k interface_ptr<T>::pointer p, cs_bool_t bAddRef)
{
    class_type   t(p, bAddRef);

    swap(t);
}

template <ss_typename_param_k T>
inline void interface_ptr<T>::set(ss_typename_type_k interface_ptr<T>::reference r, cs_bool_t bAddRef)
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", &r != NULL);

    class_type   t(&r, bAddRef);

    swap(t);
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::pointer interface_ptr<T>::detach()
{
    pointer p = m_p;

    m_p = NULL;

    return p;
}

template <ss_typename_param_k T>
inline cs_bool_t interface_ptr<T>::operator ==(ss_typename_type_k interface_ptr<T>::class_type const &rhs) const
{
    return m_p == rhs.m_p;
}

template <ss_typename_param_k T>
inline cs_bool_t interface_ptr<T>::operator !=(ss_typename_type_k interface_ptr<T>::class_type const &rhs) const
{
    return m_p != rhs.m_p;
}

template <ss_typename_param_k T>
inline interface_ptr<T>::operator ss_typename_type_k interface_ptr<T>::operator_bool_type() const
{
    return operator_bool_generator_type::translate(NULL != m_p);
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::pointer interface_ptr<T>::get_interface_ptr()
{
    return m_p;
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::const_pointer interface_ptr<T>::get_interface_ptr() const
{
    return m_p;
}

#if 0
template <ss_typename_param_k T>
inline cs_bool_t interface_ptr<T>::operator !() const
{
    return NULL == m_p;
}
#endif /* 0 */

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::const_pointer interface_ptr<T>::operator ->() const
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", NULL != m_p);

    return m_p;
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::pointer interface_ptr<T>::operator ->()
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", NULL != m_p);

    return m_p;
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::const_reference interface_ptr<T>::operator *() const
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", NULL != m_p);

    return *m_p;
}

template <ss_typename_param_k T>
inline ss_typename_type_k interface_ptr<T>::reference interface_ptr<T>::operator *()
{
    COMSTL_MESSAGE_ASSERT("Attempting to dereference a null pointer", NULL != m_p);

    return *m_p;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_refcount_functions

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _COMSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::comstl::get_ptr;

using ::comstl::is_empty;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we 
 * illegally insert into the std namespace.
 */
#if defined(__STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template <ss_typename_param_k T>
    inline void swap(comstl_ns_qual(interface_ptr)<T> &lhs, comstl_ns_qual(interface_ptr)<T> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* __STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_INTERFACE_PTR */

/* ////////////////////////////////////////////////////////////////////////// */
