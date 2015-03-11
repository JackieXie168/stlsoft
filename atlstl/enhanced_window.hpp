/* /////////////////////////////////////////////////////////////////////////////
 * File:        atlstl/enhanced_window.hpp
 *
 * Purpose:     ATL ActiveX control (OCX) container window functions.
 *
 * Created:     30th November 2000
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


/// \file atlstl/enhanced_window.hpp
///
/// ATL ActiveX control (OCX) container window functions

#ifndef ATLSTL_INCL_ATLSTL_HPP_ENHANCED_WINDOW
#define ATLSTL_INCL_ATLSTL_HPP_ENHANCED_WINDOW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_HPP_ENHANCED_WINDOW_MAJOR    3
# define ATLSTL_VER_ATLSTL_HPP_ENHANCED_WINDOW_MINOR    1
# define ATLSTL_VER_ATLSTL_HPP_ENHANCED_WINDOW_REVISION 1
# define ATLSTL_VER_ATLSTL_HPP_ENHANCED_WINDOW_EDIT     19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifndef ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS
# include <atlstl/string_access.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */

namespace stlsoft
{

namespace atlstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// This template is a veneer that provides various useful (and usually missing)
/// member functions of dialogs and parent windows.
template <ss_typename_param_k D>
class EnhancedWindow
{
/// \name Types
/// @{
public:
    typedef D                   dialog_window_type;
    typedef EnhancedWindow<D>   class_type;
/// @}

/// \name Operations
/// @{
public:
    /// Returns the length of the window text of the child window with the given identifier
    int GetDlgItemTextLength(int idChild)
    {
        HWND    hwndChild   =   this_()->GetDlgItem(idChild);

        ATLSTL_ASSERT(::IsWindow(hwndChild));

        return ::GetWindowTextLength(hwndChild);
    }

    /// Changes the enable state of the child window with the given identifier
    BOOL    EnableDlgItem(int idChild, BOOL bEnable)
    {
        HWND    hwndChild   =   this_()->GetDlgItem(idChild);

        ATLSTL_ASSERT(::IsWindow(hwndChild));

        return ::EnableWindow(hwndChild, bEnable);
    }

    /// Indicates whether the child window with the given identifier is enabled
    BOOL    IsDlgItemEnabled(int idChild)
    {
        HWND    hwndChild   =   this_()->GetDlgItem(idChild);

        ATLSTL_ASSERT(::IsWindow(hwndChild));

        return ::IsWindowEnabled(hwndChild);
    }

    /// Changes the visible state of the child window with the given identifier
    BOOL    ShowDlgItem(int idChild, BOOL bShow)
    {
        HWND    hwndChild   =   this_()->GetDlgItem(idChild);

        ATLSTL_ASSERT(::IsWindow(hwndChild));

        return ::ShowWindow(hwndChild, bShow ? SW_SHOW : SW_HIDE);
    }

    /// Changes the enable and visible states of the child window with the given identifier
    BOOL    ShowAndEnableDlgItem(int idChild, BOOL bShowAndEnable, BOOL bHideIfDisabled)
    {
        BOOL    bRet = true;

        if( bShowAndEnable ||
            bHideIfDisabled)
        {
            if(!this_()->ShowDlgItem(idChild, bShowAndEnable))
            {
                bRet = false;
            }
        }

        if(!this_()->EnableDlgItem(idChild, bShowAndEnable))
        {
            bRet = false;
        }

        return bRet;
    }

    /// Sets the focus to the child window with the given identifier
    HWND    SetDlgItemFocus(int idChild)
    {
        HWND    hwndChild   =   this_()->GetDlgItem(idChild);

        ATLSTL_ASSERT(::IsWindow(hwndChild));

        return ::SetFocus(hwndChild);
    }

#if 0
    template <ss_typename_param_k S>
    BOOL SetDlgItemText(int nID, S const &s)
    {
        return this_()->SetDlgItemText(nID, stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif /* 0 */
/// @}

/// Implementation
private:
    dialog_window_type          *this_()
    {
        return static_cast<dialog_window_type*>(this);
    }
    dialog_window_type const    *this_() const
    {
        return static_cast<dialog_window_type const*>(this);
    }
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace atlstl
# else
} // namespace atlstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ATLSTL_INCL_ATLSTL_HPP_ENHANCED_WINDOW */

/* ////////////////////////////////////////////////////////////////////////// */
