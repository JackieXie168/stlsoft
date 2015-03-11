/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/interface_functions.h (formerly MOComFns.h)
 *
 * Purpose:     Reference-counting helper functions.
 *
 * Created:     2nd March 1996
 * Updated:     18th June 2006
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


/// \file comstl/interface_functions.h
///
/// Reference-counting helper functions.

#ifndef COMSTL_INCL_COMSTL_H_INTERFACE_FUNCTIONS
#define COMSTL_INCL_COMSTL_H_INTERFACE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_H_INTERFACE_FUNCTIONS_MAJOR      2
# define COMSTL_VER_COMSTL_H_INTERFACE_FUNCTIONS_MINOR      1
# define COMSTL_VER_COMSTL_H_INTERFACE_FUNCTIONS_REVISION   1
# define COMSTL_VER_COMSTL_H_INTERFACE_FUNCTIONS_EDIT       59
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

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
 * C functions
 */

/** \brief Evaluates the an object identity
 *
 * \param p The pointer to the object whose identity will be evaluated
 * \param identity
 *
 * \return A status code indicating whether the identity was retrieved
 * \retval S_OK The pointers refer to the same object
 * \retval E_POINTER If p is null
 * \retval E_INVALIDARG If identity is null
 * \retval any-other-code Indicates an error from the call to QueryInterface()
 *
 * \note If the function success, the caller must release the reference count
 *        associated with the interface pointer in *identity.        
 */
STLSOFT_INLINE HRESULT comstl__get_object_identity(/* [in] */ LPUNKNOWN p, /* [in] */ LPUNKNOWN *identity)
{
    HRESULT hr;

    if(NULL == identity)
    {
        hr = E_INVALIDARG;
    }
    else if(NULL == p)
    {
        hr = E_POINTER;
    }
    else
    {
        hr = COMSTL_ITF_CALL(p)->QueryInterface(COMSTL_ITF_THIS(p) COMSTL_IID_2_REF(IID_IUnknown), stlsoft_reinterpret_cast(void**, identity));
    }

    return hr;
}

/** \brief Determines whether two interfaces refer to the same object
 *
 * \return A status code indicating whether the two pointers refer to the same
 *          object
 * \retval S_OK The pointers refer to the same object
 * \retval S_FALSE The pointers refer to different objects
 * \retval E_POINTER If either/both pointers are null
 * \retval any-other-code Indicates an error from one of the calls to QueryInterface()
 */
STLSOFT_INLINE HRESULT comstl__is_same_object(/* [in] */ LPUNKNOWN p1, /* [in] */ LPUNKNOWN p2)
{
    LPUNKNOWN   punk1   =   NULL;
    LPUNKNOWN   punk2   =   NULL;
    HRESULT     hr      =   S_OK;

    if( NULL == p1 ||
        NULL == p2)
    {
        hr = E_POINTER;
    }

    if(SUCCEEDED(hr))
    {
        hr = COMSTL_ITF_CALL(p1)->QueryInterface(COMSTL_ITF_THIS(p1) COMSTL_IID_2_REF(IID_IUnknown), stlsoft_reinterpret_cast(void**, &punk1));
    }
    if(SUCCEEDED(hr))
    {
        hr = COMSTL_ITF_CALL(p2)->QueryInterface(COMSTL_ITF_THIS(p2) COMSTL_IID_2_REF(IID_IUnknown), stlsoft_reinterpret_cast(void**, &punk2));
    }

    if(SUCCEEDED(hr))
    {
        if( NULL == punk1 ||
            NULL == punk2 ||
            punk1 != punk2)
        {
            hr = S_FALSE;
        }
    }

    if(NULL != punk1)
    {
        COMSTL_ITF_CALL(punk1)->Release(COMSTL_ITF_THIS0(punk1));
    }
    if(NULL != punk2)
    {
        COMSTL_ITF_CALL(punk2)->Release(COMSTL_ITF_THIS0(punk2));
    }

    return hr;
}

/** \brief Determines whether an object implements a given interface without adding a reference count
 *
 * \return A status code indicating whether the given interface is implemented
 * \retval S_OK The interface is implemented and accessible
 * \retval E_NOINTERFACE The interface is not implemented
 * \retval any-other-code Indicates an error from the call to QueryInterface()
 */
STLSOFT_INLINE HRESULT comstl__is_interface_implemented(/* [in] */ LPUNKNOWN p, /* [in] */ REFIID riid)
{
    LPUNKNOWN   punk    =   NULL;
    HRESULT     hr      =   COMSTL_ITF_CALL(p)->QueryInterface(COMSTL_ITF_THIS(p) riid, stlsoft_reinterpret_cast(void**, &punk));

    if(NULL != punk)
    {
        COMSTL_ITF_CALL(punk)->Release(COMSTL_ITF_THIS0(punk));
    }

    return hr;
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** \brief Evaluates the an object identity
 *
 * \param p The pointer to the object whose identity will be evaluated
 * \param identity
 *
 * \return A status code indicating whether the identity was retrieved
 * \retval S_OK The pointers refer to the same object
 * \retval E_POINTER If p is null
 * \retval E_INVALIDARG If identity is null
 * \retval any-other-code Indicates an error from the call to QueryInterface()
 *
 * \note If the function success, the caller must release the reference count
 *        associated with the interface pointer in *identity.        
 */
inline HRESULT get_object_identity(/* [in] */ LPUNKNOWN p, /* [in] */ LPUNKNOWN *identity)
{
    return comstl__get_object_identity(p, identity);
}

/** \brief Determines whether two interfaces refer to the same object
 *
 * \return A status code indicating whether the two pointers refer to the same
 *          object
 * \retval S_OK The pointers refer to the same object
 * \retval S_FALSE The pointers refer to different objects
 * \retval any-other-code Indicates an error from one of the calls to QueryInterface()
 */
inline HRESULT is_same_object(/* [in] */ LPUNKNOWN p1, /* [in] */ LPUNKNOWN p2)
{
    return comstl__is_same_object(p1, p2);
}

/** \brief Determines whether an object implements a given interface without adding a reference count
 *
 * \return A status code indicating whether the given interface is implemented
 * \retval S_OK The interface is implemented and accessible
 * \retval E_NOINTERFACE The interface is not implemented
 * \retval any-other-code Indicates an error from the call to QueryInterface()
 */
inline HRESULT is_interface_implemented(/* [in] */ LPUNKNOWN p, /* [in] */ REFIID riid)
{
    return comstl__is_interface_implemented(p, riid);
}

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/interface_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_H_INTERFACE_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
