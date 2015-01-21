/* /////////////////////////////////////////////////////////////////////////////
 * File:        argument_proxies.hpp (formerly stlsoft_argument_proxies.h, originally MLRefPrx.h, ::SynesisStd)
 *
 * Purpose:     Const and non-const reference & pointer proxy classes.
 *
 * Created:     28th April 2000
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/argument_proxies.hpp
///
/// Const and non-const reference & pointer proxy classes.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ARGUMENT_PROXIES
#define STLSOFT_INCL_STLSOFT_HPP_ARGUMENT_PROXIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ARGUMENT_PROXIES_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_ARGUMENT_PROXIES_MINOR     1
# define STLSOFT_VER_STLSOFT_HPP_ARGUMENT_PROXIES_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_ARGUMENT_PROXIES_EDIT      118
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

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

/// Acts as a proxy for a pointer
// pointer_proxy
template <ss_typename_param_k A>
class pointer_proxy
{
public:
    typedef A                   argument_type;
    typedef argument_type       *argument_pointer_type;
    typedef pointer_proxy<A>    class_type;

// const_ruction
public:
    ss_explicit_k pointer_proxy(argument_pointer_type a)
        : m_a(a)
    {}
    pointer_proxy(class_type const &rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_pointer_type() const
    {
        return m_a;
    }

// Members
protected:
    argument_pointer_type   m_a;

// Not to be implemented
private:
    class_type const &operator =(class_type const &);
};

/// Acts as a proxy for a pointer-to-const
// const_pointer_proxy
template <ss_typename_param_k A>
class const_pointer_proxy
{
public:
    typedef A                       argument_type;
    typedef argument_type const     *argument_pointer_type;
    typedef const_pointer_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k const_pointer_proxy(argument_pointer_type a)
        : m_a(a)
    {}
    const_pointer_proxy(class_type const &rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_pointer_type() const
    {
        return m_a;
    }

// Members
protected:
    argument_pointer_type   m_a;

// Not to be implemented
private:
    class_type const &operator =(class_type const &);
};


/// Acts as a proxy for a reference
// reference_proxy
template <ss_typename_param_k A>
class reference_proxy
{
public:
    typedef A                   argument_type;
    typedef argument_type       &argument_reference_type;
    typedef reference_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k reference_proxy(argument_reference_type a)
        : m_a(a)
    {}
    reference_proxy(class_type const &rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_reference_type() const
    {
        return m_a;
    }

// Members
protected:
    argument_reference_type m_a;

// Not to be implemented
private:
    class_type const &operator =(class_type const &);
};


/// Acts as a proxy for a reference-to-const
// const_reference_proxy
template <ss_typename_param_k A>
class const_reference_proxy
{
public:
    typedef A                           argument_type;
    typedef argument_type const         &argument_reference_type;
    typedef const_reference_proxy<A>    class_type;

// const_ruction
public:
    ss_explicit_k const_reference_proxy(argument_reference_type a)
        : m_a(a)
    {}
    const_reference_proxy(class_type const &rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_reference_type() const
    {
        return m_a;
    }

// Members
protected:
    argument_reference_type m_a;

// Not to be implemented
private:
    class_type const &operator =(class_type const &);
};


/// Acts as a proxy for a value
// value_proxy
template <ss_typename_param_k A>
class value_proxy
{
public:
    typedef A               argument_type;
    typedef value_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k value_proxy(argument_type a)
        : m_a(a)
    {}
    value_proxy(class_type const &rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_type() const
    {
        return m_a;
    }

// Members
protected:
    argument_type   m_a;

// Not to be implemented
private:
    class_type const &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Forwarding functions
 */

/// Creator function for the pointer_proxy
template <ss_typename_param_k A>
inline pointer_proxy<A> ptr_proxy(A *a)
{
    return pointer_proxy<A>(a);
}

/// Creator function for the const_pointer_proxy
template <ss_typename_param_k A>
inline const_pointer_proxy<A> const_ptr_proxy(A const *a)
{
    return const_pointer_proxy<A>(a);
}

/// Creator function for the reference_proxy
template <ss_typename_param_k A>
inline reference_proxy<A> ref_proxy(A &a)
{
    return reference_proxy<A>(a);
}

/// Creator function for the const_reference_proxy
template <ss_typename_param_k A>
inline const_reference_proxy<A> const_ref_proxy(A &a)
{
    return const_reference_proxy<A>(a);
}

/// Creator function for the value_proxy
template <ss_typename_param_k A>
inline value_proxy<A> val_proxy(A a)
{
    return value_proxy<A>(a);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/argument_proxies_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ARGUMENT_PROXIES */

/* ////////////////////////////////////////////////////////////////////////// */
