/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry_functions.hpp (formerly MWRegUtl.h, ::SynesisWin)
 *
 * Purpose:     Registry functions.
 *
 * Created:     20th November 1995
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1995-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/registry_functions.hpp
///
/// Registry functions.

#ifndef WINSTL_INCL_WINSTL_HPP_REGISTRY_FUNCTIONS
#define WINSTL_INCL_WINSTL_HPP_REGISTRY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_REGISTRY_FUNCTIONS_MAJOR     2
# define WINSTL_VER_WINSTL_HPP_REGISTRY_FUNCTIONS_MINOR     2
# define WINSTL_VER_WINSTL_HPP_REGISTRY_FUNCTIONS_REVISION  1
# define WINSTL_VER_WINSTL_HPP_REGISTRY_FUNCTIONS_EDIT      35
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_DEFS
# include <winstl/reg_defs.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_DEFS */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_TRAITS
# include <winstl/reg_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_TRAITS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup winstl_reg_library Registry Library
/// \ingroup WinSTL libraries
/// \brief This library provides facilities for working with the Windows registry
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <ss_typename_param_k C>
inline LONG reg_get_string_value(HKEY hkey, C const *name, C *buffer, size_t &cchBuffer)
{
    DWORD       type;
    ws_size_t   cbData  =   sizeof(C) * cchBuffer;
    LONG        res     =   reg_traits<C>::reg_query_value(hkey, name, type, buffer, cbData);

    if(ERROR_SUCCESS == res)
    {
        cchBuffer = cbData / sizeof(C);
    }

    return res;
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_reg_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_HPP_REGISTRY_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */