/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl_thread_mutex.h (originally MWCrtSct.h, ::SynesisWin)
 *
 * Purpose:     Intra-process mutex, based on Windows CRITICAL_SECTION.
 *
 * Created:     17th December 1996
 * Updated:     23rd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2004, Matthew Wilson and Synesis Software
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


/// \file winstl_thread_mutex.h
///
/// Intra-process mutex, based on Windows CRITICAL_SECTION.

#ifndef WINSTL_INCL_H_WINSTL_THREAD_MUTEX
#define WINSTL_INCL_H_WINSTL_THREAD_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_H_WINSTL_THREAD_MUTEX_MAJOR     3
# define WINSTL_VER_H_WINSTL_THREAD_MUTEX_MINOR     2
# define WINSTL_VER_H_WINSTL_THREAD_MUTEX_REVISION  1
# define WINSTL_VER_H_WINSTL_THREAD_MUTEX_EDIT      36
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete. Instead include winstl/thread_mutex.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT && _STLSOFT_COMPILE_VERBOSE */

#ifndef WINSTL_INCL_WINSTL_HPP_THREAD_MUTEX
# include <winstl/thread_mutex.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_THREAD_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_H_WINSTL_THREAD_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */
