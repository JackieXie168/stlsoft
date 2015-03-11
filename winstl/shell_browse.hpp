/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/shell_browse.hpp (formerly winstl_shell_browse.h)
 *
 * Purpose:     Shell browsing functions.
 *
 * Created:     2nd March 2002
 * Updated:     21st January 2006
 *
 * Thanks:      To Pablo Aguilar for default folder enhancements.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
 * Copyright (c) 2005, Pablo Aguilar
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


/// \file winstl/shell_browse.hpp
///
/// Shell browsing functions.

#ifndef WINSTL_INCL_WINSTL_HPP_SHELL_BROWSE
#define WINSTL_INCL_WINSTL_HPP_SHELL_BROWSE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_SHELL_BROWSE_MAJOR       4
# define WINSTL_VER_WINSTL_HPP_SHELL_BROWSE_MINOR       0
# define WINSTL_VER_WINSTL_HPP_SHELL_BROWSE_REVISION    1
# define WINSTL_VER_WINSTL_HPP_SHELL_BROWSE_EDIT        46
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:OBSOLETE]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* ////////////////////////////////////////////////////////////////////////////
 * Includes.
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if !defined(STLSOFT_OBSOLETE)
# error winstl::shell_browse is now obsolete. Please include winstl/shell/browse_for_folder.hpp, and use winstl::browse_for_folder
#endif /* !STLSOFT_OBSOLETE */

#ifndef WINSTL_INCL_WINSTL_SHELL_HPP_BROWSE_FOR_FOLDER
# include <winstl/shell/browse_for_folder.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHELL_HPP_BROWSE_FOR_FOLDER */

#ifdef STLSOFT_UNITTEST
# include <string>
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

// function shell_browse
/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
/// \param hwndOwner The parent of the browse dialog. May be null
/// \param pidlRoot Pointer to an ITEMIDLIST structure (PIDL) specifying the location of the root folder from which to start browsing. May be null
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline ws_bool_t shell_browse(const S &title, C *displayName, UINT flags, HWND hwndOwner, LPCITEMIDLIST pidlRoot)
{
    return browse_for_folder(title, displayName, flags, hwndOwner, pidlRoot);
}

/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
/// \param hwndOwner The parent of the browse dialog. May be null
/// \param pidlRoot Pointer to an ITEMIDLIST structure (PIDL) specifying the location of the root folder from which to start browsing. May be null
/// \param defaultFolder The default folder to select when the browse window opens
template<   ss_typename_param_k S0
        ,   ss_typename_param_k C
        ,   ss_typename_param_k S1
        >
inline ws_bool_t shell_browse(const S0 &title, C *displayName, UINT flags, HWND hwndOwner, LPCITEMIDLIST pidlRoot, S1 const &defaultFolder)
{
    return browse_for_folder(title, displayName, flags, hwndOwner, pidlRoot, defaultFolder);
}

/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
/// \param hwndOwner The parent of the browse dialog. May be null
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline ws_bool_t shell_browse(const S &title, C *displayName, UINT flags, HWND hwndOwner)
{
    return browse_for_folder(title, displayName, flags, hwndOwner);
}

/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
/// \param pidlRoot Pointer to an ITEMIDLIST structure (PIDL) specifying the location of the root folder from which to start browsing. May be null
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline ws_bool_t shell_browse(const S &title, C *displayName, UINT flags, LPCITEMIDLIST pidlRoot)
{
    return browse_for_folder(title, displayName, flags, pidlRoot);
}

/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline ws_bool_t shell_browse(const S &title, C *displayName, UINT flags)
{
    return browse_for_folder(title, displayName, flags);
}

#if !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER != 1300)
/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
/// \param flags Combination of the <b>BIF_*</b> flags for the Win32 \c SHBrowseForFolder() function
/// \param defaultFolder The default folder to select when the browse window opens
template<   ss_typename_param_k S0
        ,   ss_typename_param_k C
        ,   ss_typename_param_k S1
        >
inline ws_bool_t shell_browse(  const S0    &title
                            ,   C           *displayName
                            ,   UINT        flags
                            ,   const S1    &defaultFolder
                            )
{
    return browse_for_folder(title, displayName, flags, defaultFolder);
}
#endif /* compiler */

/// Browses the shell namespace according to the given parameters
///
/// \param title The title for the browse dialog
/// \param displayName Buffer to receive the display name
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline ws_bool_t shell_browse(const S &title, C *displayName)
{
    return browse_for_folder(title, displayName);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/shell_browse_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* WINSTL_INCL_WINSTL_HPP_SHELL_BROWSE */

/* ////////////////////////////////////////////////////////////////////////// */
