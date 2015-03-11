/* /////////////////////////////////////////////////////////////////////////
 * File:        functions.h (formerly winstl_functions.h, originally MWBase.h, ::SynesisWin)
 *
 * Purpose:     A number of useful functions.
 *
 * Created:     7th May 2000
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file winstl/functions.h
///
/// A number of useful functions.

#ifndef WINSTL_INCL_WINSTL_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FUNCTIONS_MAJOR    3
# define WINSTL_VER_WINSTL_H_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_H_FUNCTIONS_REVISION 1
# define WINSTL_VER_WINSTL_H_FUNCTIONS_EDIT     51
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_H_ERROR_FUNCTIONS
# include <winstl/error_functions.h>    // for format_message_***() functions
#endif /* !WINSTL_INCL_WINSTL_H_ERROR_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** Closes a handle, and sets its value to NULL
 */
STLSOFT_INLINE ws_int_t winstl__CloseHandleSetNull(HANDLE *h)
{
    WINSTL_ASSERT(NULL != h);

    return STLSOFT_NS_GLOBAL(CloseHandle)(*h) ? (*h = NULL, TRUE) : FALSE;
}

/** Indicates whether the given handle is signalled.
 *
 * \note There is no error return
 */
STLSOFT_INLINE ws_int_t winstl__IsWaitObjectSignalled(HANDLE h)
{
    return WAIT_OBJECT_0 == STLSOFT_NS_GLOBAL(WaitForSingleObject)(h, 0);
}

/** Duplicates a handle. Both the handle and the duplicate are within the context of the current process.
 */
STLSOFT_INLINE ws_int_t winstl__DuplicateLocalHandle(HANDLE h, HANDLE *hDup)
{
    return STLSOFT_NS_GLOBAL(DuplicateHandle)(STLSOFT_NS_GLOBAL(GetCurrentProcess)(), h, STLSOFT_NS_GLOBAL(GetCurrentProcess)(), hDup, 0, FALSE, DUPLICATE_SAME_ACCESS);
}

/** Elicits asynchronous key state
 */
STLSOFT_INLINE ws_int_t winstl__IsKeyPressedAsync(int key)
{
    return 0 != (STLSOFT_NS_GLOBAL(GetAsyncKeyState)(key) & 0x8000);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** CloseHandleSetNull
 *
 * Closes a handle, and sets its value to NULL
 */
inline ws_bool_t CloseHandleSetNull(HANDLE &h)
{
    return BOOL2bool(winstl__CloseHandleSetNull(&h));
}

/** IsWaitObjectSignalled
 *
 * Indicates whether the given handle is signalled.
 *
 * \note There is no error return
 */
inline ws_bool_t IsWaitObjectSignalled(HANDLE h)
{
    return BOOL2bool(winstl__IsWaitObjectSignalled(h));
}

/** HasOverlappedIoCompleted
 *
 * Indicates whether the I/O operation has completed
 *
 * \note There is no error return
 */
#undef HasOverlappedIoCompleted
inline BOOL HasOverlappedIoCompleted(LPOVERLAPPED lpOverlapped)
{
    return STATUS_PENDING != lpOverlapped->Internal;
}
#define HasOverlappedIoCompleted    HasOverlappedIoCompleted

/** DuplicateLocalHandle()
 *
 * Duplicates a handle. Both the handle and the duplicate are within the context
 * of the current process.
 */
inline ws_bool_t DuplicateLocalHandle(HANDLE h, HANDLE &hDup)
{
    return BOOL2bool(winstl__DuplicateLocalHandle(h, &hDup));
}


#if !defined(_WIN32_WINNT) || \
    (_WIN32_WINNT < 0x0500)

/** GetConsoleWindow
 *
 * Returns the window handle of the current console, or NULL if it cannot be found
 *
 * \note This only works on Windows 2000, or later, operating systems
 */
inline HWND GetConsoleWindow()
{
    typedef HWND (WINAPI *GCW_t)();

    HMODULE Kernel32    =   ::LoadLibraryA("KERNEL32");
    GCW_t   pfn         =   stlsoft_reinterpret_cast(GCW_t, ::GetProcAddress(Kernel32, "GetConsoleWindow"));

    if(NULL == pfn)
    {
        return NULL;
    }
    else
    {
        HWND    hwnd    =   (*pfn)();

        ::FreeLibrary(Kernel32);

        return hwnd;
    }
}

#endif /* _WIN32_WINNT */


/** FormatMessage()
 *
 */

inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_a_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, hinst, buffer, cchBuffer);
}

inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_w_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, hinst, buffer, cchBuffer);
}

inline ws_dword_t FormatMessage(DWORD error, ws_char_a_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, NULL, buffer, cchBuffer);
}

inline ws_dword_t FormatMessage(DWORD error, ws_char_w_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, NULL, buffer, cchBuffer);
}

inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_a_t **buffer)
{
    return format_message(error, hinst, buffer);
}

inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_w_t **buffer)
{
    return format_message(error, hinst, buffer);
}

inline void FormatMessage_BufferFree(ws_char_a_t *buffer)
{
    format_message_free_buff(buffer);
}

inline void FormatMessage_BufferFree(ws_char_w_t *buffer)
{
    format_message_free_buff(buffer);
}



/** Elicits asynchronous key state
 */
inline ws_bool_t IsKeyPressedAsync(int key)
{
    return BOOL2bool(winstl__IsKeyPressedAsync(key));
}

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

namespace winstl_helper
{
#if !defined(_WIN32_WINNT) || \
    (_WIN32_WINNT < 0x0500)

    winstl_ns_using(GetConsoleWindow)

#endif /* _WIN32_WINNT */
}

using namespace winstl_helper;

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_H_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
