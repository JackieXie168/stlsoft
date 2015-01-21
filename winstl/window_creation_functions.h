/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/window_creation_functions.h (formerly winstl_functions.h; formerly MWBase.h, ::SynesisWin)
 *
 * Purpose:     Window creation functions.
 *
 * Created:     7th May 2000
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/window_creation_functions.h
///
/// Control creation functions.

#ifndef WINSTL_INCL_WINSTL_H_WINDOW_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_WINDOW_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_WINDOW_CREATION_FUNCTIONS_MAJOR    1
# define WINSTL_VER_WINSTL_H_WINDOW_CREATION_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_H_WINDOW_CREATION_FUNCTIONS_REVISION 1
# define WINSTL_VER_WINSTL_H_WINDOW_CREATION_FUNCTIONS_EDIT     7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD
#  include <stlsoft/string_access_fwd.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD */
#endif /* __cplusplus */

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

/// \weakgroup winstl_window_library Window Library (WinSTL)
/// \ingroup WinSTL libraries_window ccompilation
/// \brief This library provides facilities for defining and manipulating Win32 windows
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE HWND winstl__CreateWindowA(  LPCSTR      lpClassName
                                        ,   LPCSTR      lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowA)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowW(  LPCWSTR     lpClassName
                                        ,   LPCWSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowW)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindow(   LPCTSTR     lpClassName
                                        ,   LPCTSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindow)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowExA(DWORD       dwExStyle
                                        ,   LPCSTR      lpClassName
                                        ,   LPCSTR      lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowExA)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowExW(DWORD       dwExStyle
                                        ,   LPCWSTR     lpClassName
                                        ,   LPCWSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowExW)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowEx( DWORD       dwExStyle
                                        ,   LPCTSTR     lpClassName
                                        ,   LPCTSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowEx)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

/* /////////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus
# ifndef _WINSTL_NO_NAMESPACE

//inline HWND CreateWindowA(  LPCSTR      lpClassName
//                        ,   LPCSTR      lpWindowName
//                        ,   DWORD       dwStyle
//                        ,   int         X
//                        ,   int         Y
//                        ,   int         nWidth
//                        ,   int         nHeight
//                        ,   HWND        hWndParent
//                        ,   HMENU       hMenu
//                        ,   HINSTANCE   hInstance
//                        ,   LPVOID      lpParam)
//{
//    return winstl__CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
//}

//inline HWND CreateWindowW(  LPCWSTR     lpClassName
//                        ,   LPCWSTR     lpWindowName
//                        ,   DWORD       dwStyle
//                        ,   int         X
//                        ,   int         Y
//                        ,   int         nWidth
//                        ,   int         nHeight
//                        ,   HWND        hWndParent
//                        ,   HMENU       hMenu
//                        ,   HINSTANCE   hInstance
//                        ,   LPVOID      lpParam)
//{
//    return winstl__CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
//}

//inline HWND CreateWindow(   LPCTSTR     lpClassName
//                        ,   LPCTSTR     lpWindowName
//                        ,   DWORD       dwStyle
//                        ,   int         X
//                        ,   int         Y
//                        ,   int         nWidth
//                        ,   int         nHeight
//                        ,   HWND        hWndParent
//                        ,   HMENU       hMenu
//                        ,   HINSTANCE   hInstance
//                        ,   LPVOID      lpParam)
//{
//    return winstl__CreateWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
//}

inline HWND CreateWindowExA(DWORD       dwExStyle
                        ,   LPCSTR      lpClassName
                        ,   LPCSTR      lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

inline HWND CreateWindowExW(DWORD       dwExStyle
                        ,   LPCWSTR     lpClassName
                        ,   LPCWSTR     lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

//inline HWND CreateWindowEx( DWORD       dwExStyle
//                        ,   LPCTSTR     lpClassName
//                        ,   LPCTSTR     lpWindowName
//                        ,   DWORD       dwStyle
//                        ,   int         X
//                        ,   int         Y
//                        ,   int         nWidth
//                        ,   int         nHeight
//                        ,   HWND        hWndParent
//                        ,   HMENU       hMenu
//                        ,   HINSTANCE   hInstance
//                        ,   LPVOID      lpParam)
//{
//    return winstl__CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
//}
# endif /* !_WINSTL_NO_NAMESPACE */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_window_library

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

#endif /* WINSTL_INCL_WINSTL_H_WINDOW_CREATION_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */