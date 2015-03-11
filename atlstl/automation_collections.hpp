/* /////////////////////////////////////////////////////////////////////////////
 * File:        atlstl/automation_collections.hpp (formerly MAOleCol.h)
 *
 * Purpose:     Adaptor classes for creating COM collection instances.
 *
 * Created:     16th April 1999
 * Updated:     28th March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2006, Matthew Wilson and Synesis Software
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


/// \file atlstl/automation_collections.hpp
///
/// Adaptor classes for creating COM collection instances.

#ifndef ATLSTL_INCL_ATLSTL_HPP_AUTOMATION_COLLECTIONS
#define ATLSTL_INCL_ATLSTL_HPP_AUTOMATION_COLLECTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_HPP_AUTOMATION_COLLECTIONS_MAJOR     2
# define ATLSTL_VER_ATLSTL_HPP_AUTOMATION_COLLECTIONS_MINOR     0
# define ATLSTL_VER_ATLSTL_HPP_AUTOMATION_COLLECTIONS_REVISION  3
# define ATLSTL_VER_ATLSTL_HPP_AUTOMATION_COLLECTIONS_EDIT      90
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_DMC:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#include <atlcom.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */

namespace stlsoft
{

namespace atlstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \defgroup atlstl_automation_collection_helpers Automation Collection Helpers
/// \ingroup ATLSTL
/// \brief This set of adaptor class templates provide for the definition of automation collections.
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<   ss_typename_param_k D
//      ,   HRESULT (STDMETHODCALLTYPE D::*pfn)(LPUNKNOWN*) =   &D::get__NewEnum
        ,   ss_typename_param_k ThreadModel                 =   CComObjectThreadModel
        >
class generic_collection_base
    : public IDispatch
    , public CComObjectRootEx<ThreadModel>
{
/// \name Member Types
/// @{
public:
    typedef D                                               derived_class_type;
//    typedef generic_collection_base<D, pfn, ThreadModel>  class_type;
    typedef generic_collection_base<D, ThreadModel>         class_type;
/// @}

/// \name Interface map
/// @{
protected:
    BEGIN_COM_MAP(generic_collection_base)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()
/// @}

/// \name IDispatch members
/// @{
protected:
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo)
    {
        *pctinfo = 0;

        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID /* lcid */, ITypeInfo **ppTInfo)
    {
        if(0 != iTInfo)
        {
            return DISP_E_BADINDEX;
        }
        else if(NULL == ppTInfo)
        {
            return E_POINTER;
        }
        else
        {
            *ppTInfo = NULL;

            return S_FALSE;
        }
    }
    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(
        /* [in] */ REFIID riid,
        /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
        /* [in] */ UINT cNames,
        /* [in] */ LCID lcid,
        /* [size_is][out] */ DISPID __RPC_FAR *rgDispId)
    {
        return DISP_E_UNKNOWNNAME;
    }
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke( DISPID      dispidMember
                                                        ,   REFIID      riid
                                                        ,   LCID        lcid
                                                        ,   WORD        wFlags
                                                        ,   DISPPARAMS  *pDispParams
                                                        ,   VARIANT     *pVarResult
                                                        ,   EXCEPINFO   *pExcepInfo
                                                        ,   UINT        *puArgErr)
    {
        if(DISPID_NEWENUM == dispidMember)
        {
            derived_class_type  *pThis  =   static_cast<derived_class_type*>(this);

            if(0 != pDispParams->cArgs)
            {
                return DISP_E_BADPARAMCOUNT;
            }
            else
            {
                LPUNKNOWN   punkEnumerator;
                HRESULT     hr;

                ::VariantInit(pVarResult);

//              hr  =   (pThis->*pfn)(&punkEnumerator);
                hr  =   pThis->get__NewEnum(&punkEnumerator);

                if(SUCCEEDED(hr))
                {
                    pVarResult->vt      =   VT_UNKNOWN;
                    pVarResult->punkVal =   punkEnumerator;
                }

                return hr;
            }
        }
        else
        {
            return DISP_E_MEMBERNOTFOUND;
        }
    }
/// @}
};


template<   ss_typename_param_k I1
        ,   ss_typename_param_k I2
        ,   ss_typename_param_k I3
        >
inline LPUNKNOWN get_clone(I1 *instance, HRESULT (STDAPICALLTYPE I3::*pfn)(I2 **), HRESULT &hr)
{
    I2      *clone;

    hr = (instance->*pfn)(&clone);

    if(FAILED(hr))
    {
        clone = NULL;
    }

    return clone;
}

template <ss_typename_param_k E>    // Enumerator type
class generic_automation_collection
    : public generic_collection_base<generic_automation_collection<E> >
{
public:
    typedef E                                   enumerator_type;
    typedef generic_automation_collection<E>    class_type;

public:
    generic_automation_collection()
        : m_enumerator(NULL)
    {}
    void SetEnumerator(enumerator_type *enumerator, as_bool_t bAddRef)
    {
        ATLSTL_ASSERT(NULL != enumerator);
        ATLSTL_ASSERT(NULL == m_enumerator);

        m_enumerator = enumerator;
        if(bAddRef)
        {
            m_enumerator->AddRef();
        }
    }
    ~generic_automation_collection()
    {
        m_enumerator->Release();
    }

public:
    template<   ss_typename_param_k ITER
            ,   ss_typename_param_k ITF
            ,   ss_typename_param_k N
            >
    HRESULT Init(ITER begin, ITER end, ITF *owner, N flags)
    {
        ATLSTL_ASSERT(NULL != m_enumerator);

        return m_enumerator->Init(begin, end, owner, flags);
    }
    template<   ss_typename_param_k ITER
            ,   ss_typename_param_k ITF
            >
    HRESULT Init(ITER begin, ITER end, ITF *owner)
    {
        ATLSTL_ASSERT(NULL != m_enumerator);

        return m_enumerator->Init(begin, end, owner);
    }

public:
    HRESULT get__NewEnum(LPUNKNOWN *punk)
    {
        ATLSTL_ASSERT(NULL != m_enumerator);

        HRESULT hr;

        *punk = get_clone(m_enumerator, &enumerator_type::Clone, hr);

#if 0
        typedef HRESULT (STDAPICALLTYPE enumerator_type::_CComEnumBase::*pfn_t)(LPUNKNOWN *);
        typedef HRESULT (STDAPICALLTYPE enumerator_type::_CComEnumBase::*pfnv_t)(void*);

        union
        {
            pfn_t   pfn;
            pfnv_t  pfnv;
        } u;

        u.pfnv  =   (pfnv_t)(&enumerator_type::Clone);

        return (m_enumerator->*u.pfn)(punk);
#else /* ? 0 */
        return hr;
#endif /* 0 */
    }

private:
    enumerator_type *m_enumerator;

private:
    generic_automation_collection(class_type const &);
    class_type &operator =(class_type const &);
};

#if 0
template<   ss_typename_param_k C   //!< Collection interface
        ,   ss_typename_param_k E   //!< Enumerator interface
        ,   ss_typename_param_k T   //!< Element type
        ,   ss_typename_param_k XXXXXXXXX
        >
class simple_automation_collection
{
};
#endif /* 0 */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/automation_collections_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace atlstl
# else
} // namespace atlstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ATLSTL_INCL_ATLSTL_HPP_AUTOMATION_COLLECTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
