/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/creation_functions.hpp
 *
 * Purpose:     COM instance creation helper functions
 *
 * Created:     21st September 2005
 * Updated:     10th August 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/** \file comstl/util/creation_functions.hpp
 *
 * \brief [C++ only; requires COM] COM instance creation helper functions.
 *  (\ref group__library__com_utility "COM Utility" Library.)
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_CREATION_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_HPP_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_HPP_CREATION_FUNCTIONS_MAJOR    2
# define COMSTL_VER_COMSTL_UTIL_HPP_CREATION_FUNCTIONS_MINOR    1
# define COMSTL_VER_COMSTL_UTIL_HPP_CREATION_FUNCTIONS_REVISION 1
# define COMSTL_VER_COMSTL_UTIL_HPP_CREATION_FUNCTIONS_EDIT     9
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS
# include <comstl/interface/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_INTERFACE_HPP_INTERFACE_TRAITS */

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

/** \brief Type-safe creation of a COM object, acquiring the requisite
 *  interface pointer.
 *
 * \ingroup group__library__com_utility
 */
template <ss_typename_param_k I>
inline HRESULT co_create_instance(  REFCLSID    clsid
                                ,   I           **ppi)
{
    return ::CoCreateInstance(clsid, NULL, CLSCTX_ALL, IID_traits<I>::iid(), reinterpret_cast<void**>(ppi));
}

/** \brief Type-safe creation of a COM object from a Programmatic Id,
 *  acquiring the requisite interface pointer.
 *
 * \ingroup group__library__com_utility
 *
 * \param id The Programatic Identifier (ProgId) - e.g.
 *    pantheios.com.LoggerManager - or the string form of the
 *    class id - e.g. {4E7D5C47-8F96-45DE-905D-AA3E9E592DE3}
 * \param Pointer to the interface pointer.
 */
template <ss_typename_param_k I>
inline HRESULT co_create_instance(  LPCOLESTR   id
                                ,   I           **ppi)
{
    CLSID   clsid;
    HRESULT hr  =   ::CLSIDFromProgID(id, &clsid);

    if(FAILED(hr))
    {
        hr = ::CLSIDFromString(const_cast<LPOLESTR>(id), &clsid);
    }

    if(SUCCEEDED(hr))
    {
        hr = co_create_instance(clsid, ppi);
    }

    return hr;
}

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_CREATION_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
