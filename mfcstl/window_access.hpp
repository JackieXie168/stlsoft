/* /////////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/window_access.hpp (formerly mfcstl_window_access.h)
 *
 * Purpose:     Contains access shims for windows.
 *
 * Created:     10th January 2003
 * Updated:     15th December 2005
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


/// \file mfcstl/window_access.hpp
///
/// Contains access shims for windows.

#ifndef MFCSTL_INCL_MFCSTL_HPP_WINDOW_ACCESS
#define MFCSTL_INCL_MFCSTL_HPP_WINDOW_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_HPP_WINDOW_ACCESS_MAJOR      3
# define MFCSTL_VER_MFCSTL_HPP_WINDOW_ACCESS_MINOR      1
# define MFCSTL_VER_MFCSTL_HPP_WINDOW_ACCESS_REVISION   1
# define MFCSTL_VER_MFCSTL_HPP_WINDOW_ACCESS_EDIT       28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */

namespace stlsoft
{

namespace mfcstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_window_access Window Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" retrieve the HWND for arbitrary types

/// \defgroup mfcstl_window_access_shims Window Access Shims (MFCSTL)
/// \ingroup MFCSTL concepts_shims_window_access
/// \brief These \ref concepts_shims "shims" retrieve the HWND for arbitrary types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * get_hwnd
 *
 * This can be applied to an expression, and the return value is the
 * corresponding HWND.
 */

/* HWND */

/// \brief Access the HWND of the given CWnd instance
///
/// This access <a href = "http://stlsoft.org/white_papers.html#shims">shim</a> retrieves the
/// HWND window handle for the given CWnd instance.
///
/// \param w A reference to the CWnd instance whose HWND will be retrieved
/// \return The HWND corresponding to the given CWnd instance \c w
inline HWND get_hwnd(CWnd const &w)
{
    return w.m_hWnd;
}

/// \brief Access the HWND of the given CWnd instance
///
/// This access <a href = "http://stlsoft.org/white_papers.html#shims">shim</a> retrieves the
/// HWND window handle for the given CWnd instance.
///
/// \param w A pointer to the CWnd instance whose HWND will be retrieved
/// \return The HWND corresponding to the given CWnd instance \c w
inline HWND get_hwnd(CWnd const *w)
{
    return w->GetSafeHwnd();
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/window_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group mfcstl_window_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace mfcstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#else  /* ? _MFCSTL_NO_NAMESPACE */
# if !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
#  if !defined(_WINSTL_NO_NAMESPACE)
#   if defined(_STLSOFT_NO_NAMESPACE)
namespace winstl
{
    using ::mfcstl::get_hwnd;
} // namespace winstl
#   else /* ? _STLSOFT_NO_NAMESPACE */
namespace stlsoft
{
namespace winstl_project
{
    using ::mfcstl::get_hwnd;
} // namespace winstl_project
} // namespace stlsoft
#   endif /* _STLSOFT_NO_NAMESPACE */
#  endif /* !_WINSTL_NO_NAMESPACE */
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* MFCSTL_INCL_MFCSTL_HPP_WINDOW_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */