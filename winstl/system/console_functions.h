/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/console_functions.h (originally winstl/console_functions.h)
 *
 * Purpose:     Console functions.
 *
 * Created:     3rd December 2005
 * Updated:     18th June 2006
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


/** \file winstl/system/console_functions.h
 *
 * \brief [C++ only] Definition of the winstl::basic_environment_block class
 *  template.
 *  (\ref group__library__system "System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MAJOR		2
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MINOR		0
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_REVISION	2
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_EDIT		9
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

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
 * Functions
 */

/** \brief Evalutes the current width of the console.
 *
 * \ingroup group__library__system
 */
STLSOFT_INLINE ws_size_t winstl__get_console_width(void)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    /* csbi.dwSize = sizeof(csbi); */

    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        return csbi.dwMaximumWindowSize.X;
    }

    return ~(ws_size_t)(0);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ Function Overrides
 */

#if defined(__cplusplus)

/** \brief Evalutes the current width of the console.
 *
 * \ingroup group__library__system
 */
inline ws_size_t get_console_width()
{
    return winstl__get_console_width();
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/console_functions_unittest_.h"
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

#endif /* WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
