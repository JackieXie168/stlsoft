/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/variant.hpp (originally MOVriant.h/.cpp, ::SynesisCom)
 *
 * Purpose:     variant class.
 *
 * Created:     12th December 1996
 * Updated:     13th September 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2006, Matthew Wilson and Synesis Software
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


/** \file comstl/util/variant.hpp
 *
 * \brief [C++ only; requires COM] Definition of the comstl::variant class.
 *  (\ref group__library__com_utility "COM Utility" Library.)
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_VARIANT
#define COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_VARIANT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_VARIANT_MAJOR      2
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_VARIANT_MINOR      1
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_VARIANT_REVISION   3
# define _COMSTL_VER_COMSTL_UTIL_HPP_COMSTL_VARIANT_EDIT       135
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS
# include <comstl/string/bstr_functions.h>
#endif /* !COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING
# include <comstl/shims/access/string.hpp>
#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS
#  include <comstl/error/exceptions.hpp>
# endif /* !COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS */
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS
# include <comstl/interface/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS
# include <stlsoft/util/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS */

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

/** \brief Facade for the COM VARIANT type
 *
 * \ingroup group__library__com_utility
 */
class variant
    : public VARIANT
{
public:
    typedef variant         class_type;
    typedef cs_bool_t       bool_type;
    typedef cs_size_t       size_type;

public:
    variant();
    variant(VARIANT const &rhs);
    variant(class_type const &rhs);

    class_type &operator =(class_type const &rhs);

    variant(bool b);
    variant(short i);
    variant(int i);
    variant(long i);
    variant(float r);
    variant(double r);
    variant(CY cy);
    variant(LPUNKNOWN punk, bool_type bAddRef);
    variant(LPDISPATCH pdisp, bool_type bAddRef);
    variant(cs_char_a_t const *s, int len = -1);
    variant(cs_char_w_t const *s, int len = -1);

    ~variant() stlsoft_throw_0()
    {
        stlsoft_constraint_must_be_same_size(class_type, VARIANT);

        ::VariantClear(this);
    }

    void    clear();

public:
    HRESULT     try_conversion_copy(VARIANT const &var, VARTYPE vt);
    HRESULT     try_convert(VARTYPE vt);
    class_type  &convert(VARTYPE vt);

    HRESULT     QueryInterface(REFIID riid, void **ppv) const;

    template <ss_typename_param_k I>
    HRESULT QueryInterfaceValue(I **ppi)
    {
        return QueryUnknownValue(IID_traits<I>::iid(), reinterpret_cast<void**>(ppi));
    }

public:
    void        swap(class_type &rhs);

public:
    bool_type   equal(class_type const &rhs) const;
    bool_type   equal(VARIANT const &rhs) const;

private:
    static void swap_(VARIANT &lhs, VARIANT &rhs);
    void handle_error_(char const *message, HRESULT hr);
};

/* /////////////////////////////////////////////////////////////////////////
 * String access shims
 */

// No string access shims are defined, because there're already a set
// defined for VARIANT, in comstl/shims/access/string.hpp, which is included
// by this file.

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline cs_bool_t operator ==(variant const &lhs, variant const &rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(variant const &lhs, variant const &rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(variant const &lhs, VARIANT const &rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(variant const &lhs, VARIANT const &rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(VARIANT const &lhs, variant const &rhs)
{
    return rhs.equal(lhs);
}

inline cs_bool_t operator !=(VARIANT const &lhs, variant const &rhs)
{
    return !operator ==(lhs, rhs);
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/variant_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline void variant::handle_error_(char const *message, HRESULT hr)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    throw com_exception(message, hr);
    
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

    STLSOFT_SUPPRESS_UNUSED(message);

    ::VariantClear(this);

    this->vt    =   VT_ERROR;
    this->scode =   hr;

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline /* static */ void variant::swap_(VARIANT &lhs, VARIANT &rhs)
{
    VARIANT t;

    ::memcpy(&t, &lhs, sizeof(VARIANT));
    ::memcpy(&lhs, &rhs, sizeof(VARIANT));
    ::memcpy(&rhs, &t, sizeof(VARIANT));
}




inline variant::variant()
{
    ::VariantInit(this);
}

inline variant::variant(class_type const &rhs)
{
    ::VariantInit(this);

    class_type  &rhs_   =   const_cast<class_type&>(rhs);
    HRESULT     hr      =   ::VariantCopy(this, &rhs_);

    if(FAILED(hr))
    {
        handle_error_("failed to copy variant", hr);
    }
}

inline variant::variant(VARIANT const &rhs)
{
    ::VariantInit(this);

    HRESULT     hr      =   ::VariantCopy(this, const_cast<VARIANT*>(&rhs));

    if(FAILED(hr))
    {
        handle_error_("failed to copy variant", hr);
    }
}

inline variant::class_type &variant::operator =(variant::class_type const &rhs)
{
    class_type  r(rhs);

    r.swap(*this);

    return *this;
}

inline variant::variant(bool b)
{
    ::VariantInit(this);

    this->vt        =   VT_BOOL;
    this->boolVal   =   b ? VARIANT_TRUE : VARIANT_FALSE;
}

inline variant::variant(short i)
{
    ::VariantInit(this);

    this->vt    =   VT_I2;
    this->iVal  =   i;
}

inline variant::variant(int i)
{
    ::VariantInit(this);

    this->vt    =   VT_I4;
    this->lVal  =   i;
}

inline variant::variant(long i)
{
    ::VariantInit(this);

    this->vt    =   VT_I4;
    this->lVal  =   i;
}

inline variant::variant(float r)
{
    ::VariantInit(this);

    this->vt        =   VT_R4;
    this->fltVal    =   r;
}

inline variant::variant(double r)
{
    ::VariantInit(this);

    this->vt        =   VT_R8;
    this->dblVal    =   r;
}

inline variant::variant(CY cy)
{
    ::VariantInit(this);

    this->vt    =   VT_CY;
    this->cyVal =   cy;
}

inline variant::variant(LPUNKNOWN punk, bool_type bAddRef)
{
    ::VariantInit(this);

    this->vt        =   VT_UNKNOWN;
    this->punkVal   =   punk;

    if( bAddRef &&
        NULL != punk)
    {
        punk->AddRef();
    }
}

inline variant::variant(LPDISPATCH pdisp, bool_type bAddRef)
{
    ::VariantInit(this);

    this->vt        =   VT_DISPATCH;
    this->pdispVal  =   pdisp;

    if( bAddRef &&
        NULL != pdisp)
    {
        pdisp->AddRef();
    }
}

inline variant::variant(cs_char_a_t const *s, int len /* = -1 */)
{
    ::VariantInit(this);

    this->vt        =   VT_BSTR;
    this->bstrVal   =   (len < 0) ? bstr_create(s) : bstr_create(s, static_cast<size_type>(len));

    if(NULL == this->bstrVal)
    {
        if( NULL != s &&
            '\0' != 0[s])
        {
            handle_error_("could not initialise from string", E_OUTOFMEMORY);
        }
    }
}

inline variant::variant(cs_char_w_t const *s, int len /* = -1 */)
{
    ::VariantInit(this);

    this->vt        =   VT_BSTR;
    this->bstrVal   =   (len < 0) ? bstr_create(s) : bstr_create(s, static_cast<size_type>(len));

    if(NULL == this->bstrVal)
    {
        if( NULL != s &&
            '\0' != 0[s])
        {
            handle_error_("could not initialise from string", E_OUTOFMEMORY);
        }
    }
}

inline void variant::clear()
{
    ::VariantClear(this);
}

inline HRESULT variant::try_conversion_copy(VARIANT const &var, VARTYPE vt)
{
    HRESULT hr;

    if(vt == this->vt)
    {
        hr = S_FALSE;
    }
    else
    {
        class_type  copy;

        hr  =   ::VariantChangeType(&copy, const_cast<VARIANT*>(&var), 0, vt);

        if(SUCCEEDED(hr))
        {
            copy.swap(*this);
        }
    }

    return hr;
}

inline HRESULT variant::try_convert(VARTYPE vt)
{
    return try_conversion_copy(*this, vt);
}

inline variant::class_type &variant::convert(VARTYPE vt)
{
    HRESULT hr  =   try_convert(vt);

    if(FAILED(hr))
    {
        handle_error_("could not convert variant to requested type", hr);
    }

    return *this;
}

inline void variant::swap(variant::class_type &rhs)
{
    swap_(*this, rhs);
}

#if 0
inline variant::bool_type variant::equal(variant::class_type const &rhs) const
{
    ;
}

inline variant::bool_type variant::equal(VARIANT const &rhs) const
{
    ;
}
#endif /* 0 */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_VARIANT */

/* ////////////////////////////////////////////////////////////////////// */
