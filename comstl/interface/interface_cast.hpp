/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/interface/interface_cast.hpp (originally comstl_interface_cast.h)
 *
 * Purpose:     Safe interface casting functions.
 *
 * Created:     25th June 2002
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/** \file comstl/interface/interface_cast.hpp
 *
 * \brief [C++ only] Definition of the comstl::interface_cast_addref,
 *  comstl::interface_cast_noaddref and comstl::interface_cast_test cast
 *  classes.
 *  (\ref group__library__com_interface "COM Interface" Library.)
 */

#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_CAST
#define COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_INTERFACE_HPP_INTERFACE_CAST_MAJOR     4
# define COMSTL_VER_COMSTL_INTERFACE_HPP_INTERFACE_CAST_MINOR     0
# define COMSTL_VER_COMSTL_INTERFACE_HPP_INTERFACE_CAST_REVISION  3
# define COMSTL_VER_COMSTL_INTERFACE_HPP_INTERFACE_CAST_EDIT      92
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error comstl/interface/interface_cast.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS
# include <comstl/util/refcount_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS
# include <comstl/interface/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS */
#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_BAD_INTERFACE_CAST
# include <comstl/interface/bad_interface_cast.hpp>
#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_BAD_INTERFACE_CAST */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL
# include <stlsoft/util/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL */

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
 * Functions
 */

// This helper converts from an interface pointer to itself.
//
// It explicitly takes and returns pointer so that it disambiguates from any
// overload that takes an interface wrapper instance by value/reference.
template <ss_typename_param_k I>
inline I *simple_interface_cast(I *pi)
{
    return pi;
}

/* /////////////////////////////////////////////////////////////////////////
 * Functionals
 */

/** \brief A null exception generating type
 *
 * \ingroup group__library__com_interface
 */
// [[synesis:class:exception-policy: ignore_interface_cast_exception]]
struct ignore_interface_cast_exception
{
public:
    /// The exception type
    struct thrown_type
    {
    };

public:
    /// The function call operator, which does not throw an exception
    ///
    /// \param hr The HRESULT that caused the error
    /// \param riid The REFIID that could not be acquired
    void operator ()(HRESULT hr, REFIID riid) stlsoft_throw_0()
    {
        STLSOFT_SUPPRESS_UNUSED(hr);
        STLSOFT_SUPPRESS_UNUSED(riid);

        // Do nothing
    }
};

/** \brief A null exception generating type
 *
 * \ingroup group__library__com_interface
 */
// [[synesis:class:exception-policy: throw_bad_interface_cast_exception]]
struct throw_bad_interface_cast_exception
{
public:
    /// The exception type
    typedef bad_interface_cast  thrown_type;

public:
    /// The function call operator, which throws the exception
    ///
    /// \param hr The HRESULT that caused the error
    /// \param riid The REFIID that could not be acquired
    void operator ()(HRESULT hr, REFIID riid) stlsoft_throw_1(bad_interface_cast)
    {
        throw bad_interface_cast(riid, hr);
    }
};

/** \brief A function object that calls Release() on the interface
 *
 * \ingroup group__library__com_interface
 */
template <ss_typename_param_k I>
struct noaddref_release
{
public:
    /// The function call operator, that calls Release() on the interface
    ///
    /// \param pi The interface pointer
    void operator ()(I pi)
    {
        release(pi);
    }
};

/** \brief A function object that does not call Release() on the interface
 *
 * \ingroup group__library__com_interface
 */
template <ss_typename_param_k I>
struct addref_release
{
public:
    /// The function call operator, which does not call Release() on the interface
    ///
    /// \param pi The interface pointer
    void operator ()(I pi)
    {
        STLSOFT_SUPPRESS_UNUSED(pi);
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Raw-pointer safety
 *
 * Alas this requires partial template specialisation, so is not available in
 * all environments.
 */

#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

/** \brief Interface pointer traits
 *
 * \ingroup group__library__com_interface
 *
 * \param I The interface type
 */
template <ss_typename_param_k I>
struct interface_pointer_traits;

/** \brief A specialisation for pointers only
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k I>
struct interface_pointer_traits<I*>
{
    typedef I   interface_type;
};

/** \brief A veneer interface that hides the AddRef() and Release() methods
 *
 * \ingroup group__library__com_interface
 */
template <ss_typename_param_k I>
interface protect_refcount
    : public I
{
private:
    STDMETHOD_(ULONG, AddRef)()
    {
        I   *pi = static_cast<I*>(this);

        return pi->AddRef();
    }
    STDMETHOD_(ULONG, Release)()
    {
        I   *pi = static_cast<I*>(this);

        return pi->Release();
    }
};

#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Base class for the interface cast classes
 *
 * \ingroup group__library__com_interface
 *
 * This class serves only as a base, and cannot be used in isolation
 *
 * \param I The interface pointer type
 * \param R The release type
 * \param X The exception type
 */
// [[synesis:class:implementation: comstl::interface_cast_base]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k R
        ,   ss_typename_param_k X
        >
class interface_cast_base
{
public:
    /// The interface pointer type
    typedef I                                                               interface_pointer_type;
#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
    /// The interface type
    typedef ss_typename_type_k interface_pointer_traits<I>::interface_type  interface_type;
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    /// The release type
    typedef R                                                               release_type;
    /// The exception type
    typedef X                                                               exception_policy_type;
    /// The thrown type
    typedef ss_typename_type_k exception_policy_type::thrown_type           thrown_type;
    /// The type of the current parameterisation
    typedef interface_cast_base<I, R, X>                                    class_type;

// Construction
protected:
    /// Constructor that attempts the speculative cast
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k J>
    ss_explicit_k interface_cast_base(J &j)
        : m_pi(do_cast(simple_interface_cast(j)))
    {}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    ss_explicit_k interface_cast_base(LPUNKNOWN punk)
        : m_pi(do_cast(punk))
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Constructor that directly casts (without calling QueryInterface())
    ss_explicit_k interface_cast_base(interface_pointer_type pi)
        : m_pi(pi)
    {
        addref(m_pi);
    }

protected:
    /// Releases the acquired interface pointer according to the \c release_type policy
    ~interface_cast_base() stlsoft_throw_0()
    {
        if(NULL != m_pi)
        {
            release_type()(m_pi);
        }
    }

// Implementation
protected:
    /// Perform the cast, throwing the \c exception_policy_type's \c thrown_type if the
    /// requested interface cannot be acquired.
    ///
    /// \param punk The interface pointer to cast
    /// \return The converted interface pointer
    static interface_pointer_type do_cast(LPUNKNOWN punk) stlsoft_throw_1(thrown_type)
    {
        interface_pointer_type  pi;

        if(NULL == punk)
        {
            pi = NULL;
        }
        else
        {
            REFIID  iid =   IID_traits<interface_pointer_type>().iid();
            HRESULT hr  =   punk->QueryInterface(iid, reinterpret_cast<void**>(&pi));

            if(FAILED(hr))
            {
                exception_policy_type()(hr, iid);

                pi = NULL;
            }
        }

        return pi;
    }

    /// Returns a non-mutating reference to the acquired interface pointer
    interface_pointer_type const &get_pointer_()
    {
        return m_pi;
    }

    /// Returns a copy of the acquired interface pointer
    interface_pointer_type get_pointer_() const
    {
        return m_pi;
    }

// Members
private:
    interface_pointer_type const    m_pi;

// Not to be implemented
public:
    interface_cast_base(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);
};


/** \brief Interface cast that does not add a net reference count
 *
 * \ingroup group__library__com_interface
 *
 * This class provides a cast between interface pointers, but does not add a net reference count
 *
 * \param I The interface pointer type
 * \param X The exception type
 */
// [[synesis:class:cast: comstl::interface_cast_noaddref]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k X = throw_bad_interface_cast_exception
        >
class interface_cast_noaddref
    : protected interface_cast_base<I, noaddref_release<I>, X>
{
private:
    typedef interface_cast_base<I, noaddref_release<I>, X>                  parent_class_type;
public:
    /// The type of the current parameterisation
    typedef interface_cast_noaddref<I, X>                                   class_type;
    /// The interface pointer type
    typedef ss_typename_type_k parent_class_type::interface_pointer_type    interface_pointer_type;
#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
    /// The interface type
    typedef ss_typename_type_k parent_class_type::interface_type            interface_type;
    typedef protect_refcount<interface_type>                                *protected_interface_pointer_type;
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    typedef interface_pointer_type                                          protected_interface_pointer_type;
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

// Construction
public:
    /// Constructor that attempts the speculative cast
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k J>
    ss_explicit_k interface_cast_noaddref(J &j)
        : parent_class_type(j)
    {}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    ss_explicit_k interface_cast_noaddref(LPUNKNOWN punk)
        : parent_class_type(punk)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Constructor that directly casts (without calling QueryInterface())
    ss_explicit_k interface_cast_noaddref(interface_pointer_type pi)
        : parent_class_type(pi)
    {}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ~interface_cast_noaddref() stlsoft_throw_0()
    {} // We need to provide this to persuade VC6 to call the parent class dtor
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// Accessors
public:
    /// Access the members of the interface
    protected_interface_pointer_type operator -> () const
    {
        COMSTL_MESSAGE_ASSERT("Attempting to dereference null pointer. Exception model should not be null", NULL != this->parent_class_type::get_pointer_());

        return static_cast<protected_interface_pointer_type>(this->parent_class_type::get_pointer_());
    }

// Not to be implemented
private:
    interface_cast_noaddref(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);

    // These are defined to placate Borland C/C++
    void *operator new(cs_size_t /* si */) { return 0; }
    void operator delete(void * /* pv */) {}
};

/** \brief Interface cast that does add a net reference count
 *
 * \ingroup group__library__com_interface
 *
 * This class provides a cast between interface pointers, that adds a net reference count
 *
 * \param I The interface pointer type
 * \param X The exception type, defaulted to ignore_interface_cast_exception
 */
// [[synesis:class:cast: comstl::interface_cast_addref]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k X = ignore_interface_cast_exception
        >
class interface_cast_addref
    : protected interface_cast_base<I, addref_release<I>, X>
{
private:
    typedef interface_cast_base<I, addref_release<I>, X>                    parent_class_type;
public:
    /// The type of the current parameterisation
    typedef interface_cast_addref<I, X>                                     class_type;
    /// The interface pointer type
    typedef ss_typename_type_k parent_class_type::interface_pointer_type    interface_pointer_type;

// Construction
public:
    /// Constructor that attempts the speculative cast
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k J>
    ss_explicit_k interface_cast_addref(J j)
        : parent_class_type(j)
    {}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    ss_explicit_k interface_cast_addref(LPUNKNOWN punk)
        : parent_class_type(punk)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Constructor that directly casts (without calling QueryInterface())
    ss_explicit_k interface_cast_addref(interface_pointer_type pi)
        : parent_class_type(pi)
    {}

// Accessors
public:
    /// A pointer to the acquired interface
    operator interface_pointer_type ()
    {
        return this->parent_class_type::get_pointer_();
    }

// Not to be implemented
private:
    interface_cast_addref(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);

    // These are defined to placate Borland C/C++
    void *operator new(cs_size_t /* si */) { return 0; }
    void operator delete(void * /* pv */) {}
};


/** \brief Interface cast that tests whether a given interface pointer can be successfully queried
 *
 * \ingroup group__library__com_interface
 *
 * This class performs a cast to ascertain whether the requested interface is available, but
 * then releases the resultant interface, so no net changes are made to the reference count
 * on the tested object.
 *
 * \param I The interface pointer type
 */
// [[synesis:class:cast: comstl::interface_cast_test]]
template<   ss_typename_param_k I
        >
class interface_cast_test
    : protected interface_cast_base<I, noaddref_release<I>, ignore_interface_cast_exception>
{
private:
    typedef interface_cast_base<I, noaddref_release<I>, ignore_interface_cast_exception>    parent_class_type;
public:
    /// The type of the current parameterisation
    typedef interface_cast_test<I>                                                          class_type;
    /// The interface pointer type
    typedef ss_typename_type_k parent_class_type::interface_pointer_type                    interface_pointer_type;
#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
    /// The interface type
    typedef ss_typename_type_k parent_class_type::interface_type                            interface_type;
    typedef protect_refcount<interface_type>                                                *protected_interface_pointer_type;
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    typedef interface_pointer_type                                                          protected_interface_pointer_type;
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

// Construction
public:
    /// Constructor that attempts the speculative cast
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k J>
    ss_explicit_k interface_cast_test(J &j)
        : parent_class_type(j)
    {}
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    ss_explicit_k interface_cast_test(LPUNKNOWN punk)
        : parent_class_type(punk)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Constructor that directly casts (without calling QueryInterface())
    ss_explicit_k interface_cast_test(interface_pointer_type pi)
        : parent_class_type(pi)
    {}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ~interface_cast_test() stlsoft_throw_0()
    {} // We need to provide this to persuade VC6 to call the parent class dtor
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// \name State
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    /// Represents whether the cast succeeded
    ///
    /// \retval true The interface cast succeeded
    /// \retval false The interface cast failed
    operator operator_bool_type() const
    {
        return operator_bool_generator_type::translate(NULL != this->parent_class_type::get_pointer_());
    }
    /// Represents whether the cast failed
    ///
    /// \retval true The interface cast failed
    /// \retval false The interface cast succeeded
    cs_bool_t operator !() const
    {
        return NULL == this->parent_class_type::get_pointer_();
    }
/// @}

// Not to be implemented
private:
    interface_cast_test(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);

    // These are defined to placate Borland C/C++
    void *operator new(cs_size_t /* si */) { return 0; }
    void operator delete(void * /* pv */) {}
};

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_GCC)
/** \brief Attribute shim to retrieve the interface pointer of the given cast instance
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline I get_ptr(comstl_ns_qual(interface_cast_noaddref)<I, X> &p)
{
    return p.operator -> ();
}
#endif /* compiler */

/** \brief Attribute shim to retrieve the interface pointer of the given cast instance
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline I get_ptr(comstl_ns_qual(interface_cast_noaddref)<I, X> const &p)
{
    return p.operator -> ();
}

/** \brief Attribute shim to retrieve the interface pointer of the given cast instance
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline I get_ptr(comstl_ns_qual(interface_cast_addref)<I, X> &p)
{
    return p;
}

/** \brief Attribute shim to retrieve the interface pointer of the given cast instance
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline I const get_ptr(comstl_ns_qual(interface_cast_addref)<I, X> const &p)
{
    return p;
}

/** \brief Attribute shim to determine whether the interface pointer is empty, or not
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline cs_bool_t is_empty(comstl_ns_qual(interface_cast_noaddref)<I, X> const &p)
{
    return NULL != get_ptr(p);
}

/** \brief Attribute shim to determine whether the interface pointer is empty, or not
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param p The cast instance
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k X
        >
inline cs_bool_t is_empty(comstl_ns_qual(interface_cast_addref)<I, X> const &p)
{
    return NULL != get_ptr(p);
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/interface_cast_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_CAST */

/* ////////////////////////////////////////////////////////////////////// */
