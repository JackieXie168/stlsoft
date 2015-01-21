/* /////////////////////////////////////////////////////////////////////////////
 * File:        commctrl_functions.h (formerly winstl_commctrl_functions.h)
 *
 * Purpose:     Various Windows common control functions.
 *
 * Created:     13th November 2002
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file winstl/commctrl_functions.h
///
/// Various Windows common control functions.

#ifndef WINSTL_INCL_WINSTL_H_COMMCTRL_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_COMMCTRL_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_COMMCTRL_FUNCTIONS_MAJOR       3
# define WINSTL_VER_WINSTL_H_COMMCTRL_FUNCTIONS_MINOR       1
# define WINSTL_VER_WINSTL_H_COMMCTRL_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_H_COMMCTRL_FUNCTIONS_EDIT        32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_H_MESSAGE_FUNCTIONS
# include <winstl/message_functions.h>
#endif /* !WINSTL_INCL_WINSTL_H_MESSAGE_FUNCTIONS */
#include <commctrl.h>

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

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_control Control Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating GUI controls

/// \defgroup winstl_control_library Control Library (WinSTL)
/// \ingroup WinSTL libraries_control ccompilation
/// \ingroup functions
/// \brief This library provides facilities for defining and manipulating Win32 GUI controls
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * C functions
 */

/// Gets the next item in the tree view
///
/// \param hwnd The tree view window handle
/// \param hitem The tree view item
/// \param flag One of the <b>TVGN_*</b> search flags
STLSOFT_INLINE HTREEITEM winstl__treeview_getnextitem(HWND hwnd, HTREEITEM hitem, UINT flag)
{
    return stlsoft_reinterpret_cast(HTREEITEM, winstl__SendMessage(hwnd, TVM_GETNEXTITEM, stlsoft_static_cast(WPARAM, flag), stlsoft_reinterpret_cast(LPARAM, hitem)));
}

/// Gets the tree view child item
///
/// \param hwnd The tree view window handle
/// \param hitem The tree view item whose child is to be retrieved
STLSOFT_INLINE HTREEITEM winstl__treeview_getchilditem(HWND hwnd, HTREEITEM hitem)
{
    return winstl__treeview_getnextitem(hwnd, hitem, TVGN_CHILD);
}

/// Gets the tree view root item
///
/// \param hwnd The tree view window handle
STLSOFT_INLINE HTREEITEM winstl__treeview_getrootitem(HWND hwnd)
{
    return winstl__treeview_getnextitem(hwnd, 0, TVGN_ROOT);
}

/// Gets the tree view caret item
///
/// \param hwnd The tree view window handle
STLSOFT_INLINE HTREEITEM winstl__treeview_getcaretitem(HWND hwnd)
{
    return winstl__treeview_getnextitem(hwnd, 0, TVGN_CARET);
}

/* /////////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/// Gets the next item in the tree view
///
/// \param hwnd The tree view window handle
/// \param hitem The tree view item
/// \param flag One of the <b>TVGN_*</b> search flags
inline HTREEITEM treeview_getnextitem(HWND hwnd, HTREEITEM hitem, UINT flag)
{
    return winstl__treeview_getnextitem(hwnd, hitem, flag);
}

/// Gets the tree view child item
///
/// \param hwnd The tree view window handle
/// \param hitem The tree view item whose child is to be retrieved
inline HTREEITEM treeview_getchilditem(HWND hwnd, HTREEITEM hitem)
{
    return winstl__treeview_getnextitem(hwnd, hitem, TVGN_CHILD);
}

/// Gets the tree view root item
///
/// \param hwnd The tree view window handle
inline HTREEITEM treeview_getrootitem(HWND hwnd)
{
    return winstl__treeview_getnextitem(hwnd, 0, TVGN_ROOT);
}

/// Gets the tree view caret item
///
/// \param hwnd The tree view window handle
inline HTREEITEM treeview_getcaretitem(HWND hwnd)
{
    return winstl__treeview_getnextitem(hwnd, 0, TVGN_CARET);
}
#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/commctrl_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_control_library

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

#endif /* WINSTL_INCL_WINSTL_H_COMMCTRL_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
