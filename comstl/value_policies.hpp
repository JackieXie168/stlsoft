/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/value_policies.hpp (formerly comstl_value_policies.h; originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose:     Value policies that work with STL sequence types for IEnumXXXX
 *              enumerator interfaces.
 *
 * Created:     17th September 1998
 * Updated:     25th January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file comstl/value_policies.hpp (formerly comstl_value_policies.h; originally MOEnSeq.h, ::SynesisCom)
///
/// Value policies that work with STL sequence types for IEnumXXXX enumerator interfaces.

#ifndef COMSTL_INCL_COMSTL_HPP_VALUE_POLICIES
#define COMSTL_INCL_COMSTL_HPP_VALUE_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_VALUE_POLICIES_MAJOR     4
# define COMSTL_VER_COMSTL_HPP_VALUE_POLICIES_MINOR     2
# define COMSTL_VER_COMSTL_HPP_VALUE_POLICIES_REVISION  1
# define COMSTL_VER_COMSTL_HPP_VALUE_POLICIES_EDIT      151
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_H_OLESTRING_FUNCTIONS
# include <comstl/olestring_functions.h>   // for olestring_dup(), etc.
#endif /* !COMSTL_INCL_COMSTL_H_OLESTRING_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SAP_CAST
# include <stlsoft/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SAP_CAST */

/* /////////////////////////////////////////////////////////////////////////////
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

/// \defgroup comstl_value_policies Value Policies
/// \ingroup COMSTL
/// \brief These functions objects define the policies for manipulating various COM types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Value policy for GUID
struct GUID_policy
{
public:
    typedef GUID        value_type;

public:
    /// Initialises an instance
    static void init(value_type *) stlsoft_throw_0()
    {}
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = *src;
    }
    /// Releases an instance
    static void clear(value_type *) stlsoft_throw_0()
    {}
};


/// Value policy for BSTR
struct BSTR_policy
{
public:
    typedef BSTR    value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = ::SysAllocString(*src);
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        ::SysFreeString(*p);
    }
};


/// Value policy for LPOLESTR
struct LPOLESTR_policy
{
public:
    typedef LPOLESTR    value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = olestring_dup(*src);
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        olestring_destroy(*p);
    }
};


/// Value policy for VARIANT
struct VARIANT_policy
{
public:
    typedef VARIANT value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        ::VariantInit(p);
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        ::VariantCopy(dest, const_cast<VARIANT*>(src));
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        ::VariantClear(p);
    }
};


/// Value policy for interface
///
/// \param I The interface
template <ss_typename_param_k I>
struct interface_policy
{
public:
    typedef I               interface_type;
    typedef interface_type  *value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = *src;
        if(NULL != *dest)
        {
            (*dest)->AddRef();
        }
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        if(NULL != *p)
        {
            (*p)->Release();
            *p = NULL;
        }
    }
};


/// Value policy for LPUNKNOWN
struct LPUNKNOWN_policy
{
public:
    typedef LPUNKNOWN   value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = *src;
        if(NULL != *dest)
        {
            (*dest)->AddRef();
        }
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        if(NULL != *p)
        {
            (*p)->Release();
            *p = NULL;
        }
    }
};


/// Value policy for STATSTG
struct STATSTG_policy
{
public:
    typedef STATSTG value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        p->pwcsName = NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = *src;
        if(NULL != src->pwcsName)
        {
            dest->pwcsName = olestring_dup(src->pwcsName);
        };
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        olestring_destroy(p->pwcsName);
    }
};


/// Value policy for FORMATETC
struct FORMATETC_policy
{
public:
    typedef FORMATETC   value_type;

public:
    /// Initialises an instance
    static void init(value_type *p) stlsoft_throw_0()
    {
        p->ptd  =   NULL;
    }
    /// Initialises an instance from another
    static void copy(value_type *dest, value_type const *src)
    {
        *dest = *src;
        if(NULL != dest->ptd)
        {
            dest->ptd = static_cast<DVTARGETDEVICE*>(::CoTaskMemAlloc(src->ptd->tdSize));

            if(NULL != dest->ptd)
            {
                BYTE const  *src_begin  =   stlsoft_ns_qual(sap_cast)<BYTE const*>(&src->ptd);
                BYTE const  *src_end    =   src_begin + src->ptd->tdSize;
                BYTE        *dest_begin =   stlsoft_ns_qual(sap_cast)<BYTE*>(&dest->ptd);

                for(; src_begin != src_end; ++src_begin, ++dest_begin)
                {
                    *dest_begin = *src_begin;
                }
            }
        }
    }
    /// Releases an instance
    static void clear(value_type *p) stlsoft_throw_0()
    {
        ::CoTaskMemFree(p->ptd);
    }
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_value_policies

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_VALUE_POLICIES */

/* ////////////////////////////////////////////////////////////////////////// */
