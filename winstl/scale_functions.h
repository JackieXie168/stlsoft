/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/scale_functions.h (formerly winstl_scale_functions.h)
 *
 * Purpose:     Contains scale functions.
 *
 * Created:     7th February 2002
 * Updated:     1st April 2006
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


/// \file winstl/scale_functions.h
///
/// Contains scale functions.

#ifndef WINSTL_INCL_WINSTL_H_SCALE_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_SCALE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_SCALE_FUNCTIONS_MAJOR      3
# define WINSTL_VER_WINSTL_H_SCALE_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_H_SCALE_FUNCTIONS_REVISION   1
# define WINSTL_VER_WINSTL_H_SCALE_FUNCTIONS_EDIT       35
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

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
/// \ingroup WinSTL libraries_window ccompilation functions
/// \brief This library provides facilities for defining and manipulating Win32 windows
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE ws_sint_t winstl__calc_SIZE_width(SIZE const *size)
{
    WINSTL_ASSERT(NULL != size);

    return size->cx;
}

STLSOFT_INLINE ws_sint_t winstl__calc_SIZE_height(SIZE const *size)
{
    WINSTL_ASSERT(NULL != size);

    return size->cy;
}

STLSOFT_INLINE ws_sint_t winstl__calc_RECT_width(RECT const *rect)
{
    WINSTL_ASSERT(NULL != rect);

    return rect->right - rect->left;
}

STLSOFT_INLINE ws_sint_t winstl__calc_RECT_height(RECT const *rect)
{
    WINSTL_ASSERT(NULL != rect);

    return rect->bottom - rect->top;
}

/* /////////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/* /////////////////////////////////////////////////////////////////////////////
 * calc_width()
 *
 * This attribute shim calculates the width of an entity.
 */

/// Calculates the width of a \c SIZE instance
inline ws_sint_t calc_width(SIZE const &size)
{
    return winstl__calc_SIZE_width(&size);
}

/// Calculates the width of a \c RECT instance
inline ws_sint_t calc_width(RECT const &rc)
{
    return winstl__calc_RECT_width(&rc);
}

/* /////////////////////////////////////////////////////////////////////////////
 * calc_height()
 *
 * This attribute shim calculates the height of an entity.
 */

/// Calculates the height of a \c SIZE instance
inline ws_sint_t calc_height(SIZE const &size)
{
    return winstl__calc_SIZE_height(&size);
}

/// Calculates the height of a \c RECT instance
inline ws_sint_t calc_height(RECT const &rc)
{
    return winstl__calc_RECT_height(&rc);
}

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/scale_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* WINSTL_INCL_WINSTL_H_SCALE_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */