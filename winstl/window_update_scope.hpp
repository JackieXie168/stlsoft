/* /////////////////////////////////////////////////////////////////////////////
 * File:        window_update_scope.hpp (formerly winstl_window_update_scope.h)
 *
 * Purpose:     Window update-state scoping class.
 *
 * Created:     5th January 1996
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/window_update_scope.hpp
///
/// Window update-state scoping class.

#ifndef WINSTL_INCL_WINSTL_HPP_WINDOW_UPDATE_SCOPE
#define WINSTL_INCL_WINSTL_HPP_WINDOW_UPDATE_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_WINDOW_UPDATE_SCOPE_MAJOR      4
# define WINSTL_VER_WINSTL_HPP_WINDOW_UPDATE_SCOPE_MINOR      2
# define WINSTL_VER_WINSTL_HPP_WINDOW_UPDATE_SCOPE_REVISION   1
# define WINSTL_VER_WINSTL_HPP_WINDOW_UPDATE_SCOPE_EDIT       64
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_WINDOW_ACCESS
# include <winstl/window_access.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOW_ACCESS */

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

/// \defgroup winstl_window_library Window Library (WinSTL)
/// \ingroup WinSTL libraries_window
/// \brief This library provides facilities for defining and manipulating Win32 GUI windows
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// window_update_scope
/// Provides scoping of the update-status of a window.
///
/// This class provides scoping of the update-status of a window via the Win32
/// function LockWindowUpdate().
class window_update_scope
{
public:
    typedef window_update_scope class_type;

// Construction
public:
    /// Attempts to lock the given window from updates.
    ///
    /// Takes a HWND and changes it's current update-status, which is set back to
    /// the original state in the destructor.
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k W>
    ss_explicit_k window_update_scope(W &wnd)
    {
        HWND    hwnd    =   get_hwnd(wnd);

        m_bIsLocked = (hwnd != NULL) && ::LockWindowUpdate(hwnd);
    }
#else
    ss_explicit_k window_update_scope(HWND wnd)
        : m_bIsLocked(wnd ? (::LockWindowUpdate(wnd) ? true : false) : false)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Releases the lock, if aquired in the constructor
    ~window_update_scope() stlsoft_throw_0()
    {
        if(m_bIsLocked)
        {
            // Lock was successful, so undo here
            ::LockWindowUpdate(NULL);
        }
    }

// Members
private:
    ws_bool_t   m_bIsLocked;

// Not to be implemented
private:
    window_update_scope(window_update_scope const &rhs);
    window_update_scope const &operator =(window_update_scope const &rhs);
};

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

#endif /* WINSTL_INCL_WINSTL_HPP_WINDOW_UPDATE_SCOPE */

/* ////////////////////////////////////////////////////////////////////////// */
