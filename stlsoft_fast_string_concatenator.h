/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_fast_string_concatenator.h
 *
 * Purpose:     Fast string concatenator.
 *
 * Created:     4th November 2003 (the time added to STLSoft libraries)
 * Updated:     23rd December 2005
 *
 * Thanks to:   Sean Kelly for picking up on my gratuitous use of pointers
 *              in the first implementation.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft_fast_string_concatenator.h
///
/// Fast string concatenator.

#ifndef STLSOFT_INCL_H_STLSOFT_FAST_STRING_CONCATENATOR
#define STLSOFT_INCL_H_STLSOFT_FAST_STRING_CONCATENATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_FAST_STRING_CONCATENATOR_MAJOR       3
# define STLSOFT_VER_H_STLSOFT_FAST_STRING_CONCATENATOR_MINOR       2
# define STLSOFT_VER_H_STLSOFT_FAST_STRING_CONCATENATOR_REVISION    1
# define STLSOFT_VER_H_STLSOFT_FAST_STRING_CONCATENATOR_EDIT        120
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete. Instead include stlsoft/fast_string_concatenator.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT && _STLSOFT_COMPILE_VERBOSE */

#ifndef STLSOFT_INCL_STLSOFT_HPP_FAST_STRING_CONCATENATOR
# include <stlsoft/fast_string_concatenator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_FAST_STRING_CONCATENATOR */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_FAST_STRING_CONCATENATOR */

/* ////////////////////////////////////////////////////////////////////////// */