/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/obsolete/functions.h
 *
 * Purpose:     A number of useful functions.
 *
 * Created:     7th May 2000
 * Updated:     2nd January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2007, Matthew Wilson and Synesis Software
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


/** \file winstl/obsolete/functions.h
 *
 * \brief [C, C++; OBSOLETE] A number of useful functions.
 * (\ref group__library__utility__windows "Windows Utility" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_OBSOLETE_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_OBSOLETE_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_OBSOLETE_H_FUNCTIONS_MAJOR       4
# define WINSTL_VER_WINSTL_OBSOLETE_H_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_OBSOLETE_H_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_OBSOLETE_H_FUNCTIONS_EDIT        59
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS
# include <winstl/error/error_functions.h>
#endif /* !WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS
# include <winstl/system/console_functions.h>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

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

/** [DEPRECTATED] Closes a handle, and sets its value to NULL
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 */
STLSOFT_INLINE ws_int_t winstl__CloseHandleSetNull(HANDLE *h)
{
    WINSTL_ASSERT(NULL != h);

    return STLSOFT_NS_GLOBAL(CloseHandle)(*h) ? (*h = NULL, TRUE) : FALSE;
}

/** [DEPRECTATED] Indicates whether the given handle is signalled.
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 *
 * \note There is no error return
 */
STLSOFT_INLINE ws_int_t winstl__IsWaitObjectSignalled(HANDLE h)
{
    return WAIT_OBJECT_0 == STLSOFT_NS_GLOBAL(WaitForSingleObject)(h, 0);
}

/** [DEPRECTATED] Duplicates a handle. Both the handle and the duplicate are within the context of the current process.
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 */
STLSOFT_INLINE ws_int_t winstl__DuplicateLocalHandle(HANDLE h, HANDLE *hDup)
{
    return STLSOFT_NS_GLOBAL(DuplicateHandle)(STLSOFT_NS_GLOBAL(GetCurrentProcess)(), h, STLSOFT_NS_GLOBAL(GetCurrentProcess)(), hDup, 0, FALSE, DUPLICATE_SAME_ACCESS);
}

/** [DEPRECTATED] Elicits asynchronous key state
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 */
STLSOFT_INLINE ws_int_t winstl__IsKeyPressedAsync(int key)
{
    return 0 != (STLSOFT_NS_GLOBAL(GetAsyncKeyState)(key) & 0x8000);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** [DEPRECTATED] CloseHandleSetNull
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 *
 * Closes a handle, and sets its value to NULL
 */
inline ws_bool_t CloseHandleSetNull(HANDLE &h)
{
    return BOOL2bool(winstl__CloseHandleSetNull(&h));
}

/** [DEPRECTATED] IsWaitObjectSignalled
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 *
 * Indicates whether the given handle is signalled.
 *
 * \note There is no error return
 */
inline ws_bool_t IsWaitObjectSignalled(HANDLE h)
{
    return BOOL2bool(winstl__IsWaitObjectSignalled(h));
}

/** [DEPRECTATED] HasOverlappedIoCompleted
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
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

/** [DEPRECTATED] DuplicateLocalHandle()
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
 *
 * Duplicates a handle. Both the handle and the duplicate are within the context
 * of the current process.
 */
inline ws_bool_t DuplicateLocalHandle(HANDLE h, HANDLE &hDup)
{
    return BOOL2bool(winstl__DuplicateLocalHandle(h, &hDup));
}



/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_a_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, hinst, buffer, cchBuffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_w_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, hinst, buffer, cchBuffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, ws_char_a_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, NULL, buffer, cchBuffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, ws_char_w_t *buffer, ws_uint_t cchBuffer)
{
    return format_message(error, NULL, buffer, cchBuffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_a_t **buffer)
{
    return format_message(error, hinst, buffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline ws_dword_t FormatMessage(DWORD error, HINSTANCE hinst, ws_char_w_t **buffer)
{
    return format_message(error, hinst, buffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline void FormatMessage_BufferFree(ws_char_a_t *buffer)
{
    format_message_free_buff(buffer);
}

/** [DEPRECTATED] FormatMessage()
 *
 * \deprecated Instead use winstl::format_message()
 *
 * \ingroup group__library__utility__windows
 */
inline void FormatMessage_BufferFree(ws_char_w_t *buffer)
{
    format_message_free_buff(buffer);
}



/** [DEPRECTATED] Elicits asynchronous key state
 *
 * \deprecated
 *
 * \ingroup group__library__utility__windows
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
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_OBSOLETE_H_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
