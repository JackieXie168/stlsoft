/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/windows_type_conversions.hpp (formerly winstl_windows_type_conversions.h; originally MWWinCmn.h, ::SynesisWin)
 *
 * Purpose:     Type conversions for Windows.
 *
 * Created:     1st June 2003
 * Updated:     20th January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/windows_type_conversions.hpp
///
/// Type conversions for Windows.

#ifndef WINSTL_INCL_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS
#define WINSTL_INCL_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS_MAJOR       3
# define WINSTL_VER_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS_MINOR       2
# define WINSTL_VER_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS_REVISION    1
# define WINSTL_VER_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS_EDIT        28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_UNION_CAST
# include <stlsoft/union_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_UNION_CAST */

/* ////////////////////////////////////////////////////////////////////////// */

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

typedef stlsoft_ns_qual(union_cast)<LPARAM, char const *>       StrA2LPARAM;
typedef stlsoft_ns_qual(union_cast)<LPARAM, wchar_t const *>    StrW2LPARAM;
typedef stlsoft_ns_qual(union_cast)<LPARAM, TCHAR const *>      StrT2LPARAM;

typedef stlsoft_ns_qual(union_cast)<HWND, WPARAM, false>        WPARAM2HWND;
typedef stlsoft_ns_qual(union_cast)<HWND, LPARAM, false>        LPARAM2HWND;

typedef stlsoft_ns_qual(union_cast)<WPARAM, HWND, false>        HWND2WPARAM;
typedef stlsoft_ns_qual(union_cast)<LPARAM, HWND, false>        HWND2LPARAM;
typedef stlsoft_ns_qual(union_cast)<UINT, HWND, false>          HWND2UINT;

typedef stlsoft_ns_qual(union_cast)<int, WPARAM, false>         WPARAM2int;
typedef stlsoft_ns_qual(union_cast)<WPARAM, int, false>         int2WPARAM;

#if defined(DragQueryFile) || \
    defined(HDROP_DEFINED) || \
    defined(WINSHELLAPI) || \
    defined(_INC_SHELLAPI)
typedef stlsoft_ns_qual(union_cast)<HDROP, WPARAM, false>       WPARAM2HDROP;
#endif /* HDROP is defined */

typedef stlsoft_ns_qual(union_cast)<WPARAM, void*>              Ptr2WPARAM;
typedef stlsoft_ns_qual(union_cast)<LPARAM, void*>              Ptr2LPARAM;
typedef stlsoft_ns_qual(union_cast)<UINT, void*>                Ptr2UINT;

typedef stlsoft_ns_qual(union_cast)<char const *, int>          Id2StrA;
typedef stlsoft_ns_qual(union_cast)<wchar_t const *, int>       Id2StrW;
typedef stlsoft_ns_qual(union_cast)<TCHAR const *, int>         Id2StrT;

typedef stlsoft_ns_qual(union_cast)<LPARAM, HICON, false>       HICON2LPARAM;
typedef stlsoft_ns_qual(union_cast)<HICON, LONG, false>         LONG2HICON;

#if defined(_INC_COMMCTRL) || \
    defined(_COMMCTRL_H)
 typedef union_cast<LPNMHDR, LPARAM>                            LPARAM2LPNMHDR;
 typedef union_cast<HTREEITEM, LONG, false>                     LONG2HTREEITEM;
#endif /* _INC_COMMCTRL || _COMMCTRL_H */

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

#endif /* WINSTL_INCL_WINSTL_HPP_WINDOWS_TYPE_CONVERSIONS */

/* ////////////////////////////////////////////////////////////////////////// */
