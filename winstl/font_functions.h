/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/font_functions.h (formerly formerly MWGdi.h / MWWinCmn, ::SynesisWin)
 *
 * Purpose:     Error functions.
 *
 * Created:     20th October 1994
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/font_functions.h
///
/// Error functions.

#ifndef WINSTL_INCL_WINSTL_H_FONT_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FONT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FONT_FUNCTIONS_MAJOR       3
# define WINSTL_VER_WINSTL_H_FONT_FUNCTIONS_MINOR       1
# define WINSTL_VER_WINSTL_H_FONT_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_H_FONT_FUNCTIONS_EDIT        129
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

/// \weakgroup libraries_window Window Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating GUI windows

/// \weakgroup winstl_gdi_library GDI Library (WinSTL)
/// \ingroup WinSTL libraries_window ccompilation
/// \brief This library provides facilities for defining and manipulating GDI objects
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE HFONT winstl__get_window_font(HWND hwnd)
{
    return stlsoft_reinterpret_cast(HFONT, winstl__SendMessage(hwnd, WM_GETFONT, 0, 0L));
}

STLSOFT_INLINE void winstl__set_window_font(HWND hwnd, HFONT hfont, ws_int_t bRedraw)
{
    stlsoft_static_cast(void, winstl__SendMessage(hwnd, WM_SETFONT, stlsoft_reinterpret_cast(WPARAM, hfont), bRedraw));
}

/* /////////////////////////////////////////////////////////////////////////////
 * C++ Function Overrides
 */

#if defined(__cplusplus)

inline HFONT get_window_font(HWND hwnd)
{
    return winstl__get_window_font(hwnd);
}

inline void set_window_font(HWND hwnd, HFONT hfont, ws_bool_t bRedraw = true)
{
    winstl__set_window_font(hwnd, hfont, bRedraw);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_gdi_library

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

#endif /* WINSTL_INCL_WINSTL_H_FONT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
