/* /////////////////////////////////////////////////////////////////////////
 * File:        setfocus_scope.hpp (formerly winstl_setfocus_scope.h)
 *
 * Purpose:     Cursor scoping class.
 *
 * Created:     4th May 2003
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/setfocus_scope.hpp
///
/// Cursor scoping class.

#ifndef WINSTL_INCL_WINSTL_HPP_SETFOCUS_SCOPE
#define WINSTL_INCL_WINSTL_HPP_SETFOCUS_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_SETFOCUS_SCOPE_MAJOR      3
# define WINSTL_VER_WINSTL_HPP_SETFOCUS_SCOPE_MINOR      2
# define WINSTL_VER_WINSTL_HPP_SETFOCUS_SCOPE_REVISION   2
# define WINSTL_VER_WINSTL_HPP_SETFOCUS_SCOPE_EDIT       32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>      // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

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
 * Classes
 */

// setfocus_scope
/// \brief Provides scoping of the focus window.
///
/// This class provides scoping of the focus status of a window via the API
/// function SetFocus().
class setfocus_scope
{
public:
    typedef setfocus_scope class_type;

public:
    /// Changes the owner of the focus to the given window, and records the current owner of the focus, to which it will be restored in the destructor
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k W>
    ss_explicit_k setfocus_scope(W &wnd)
        : m_hwndFocus(::SetFocus(get_hwnd(wnd)))
#else
    ss_explicit_k setfocus_scope(HWND wnd)
        : m_hwndFocus(::SetFocus(wnd))
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    {}
    /// Records the current owner of the focus, to which it will be restored in the destructor
    setfocus_scope()
        : m_hwndFocus(::GetFocus())
    {}
    /// Resets the focus to the original holder
    ~setfocus_scope() stlsoft_throw_0()
    {
        ::SetFocus(m_hwndFocus);
    }

/// Members
private:
    HWND    m_hwndFocus;

/// Not to be implemented
private:
    setfocus_scope(setfocus_scope const &);
    setfocus_scope &operator =(setfocus_scope const &);
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_HPP_SETFOCUS_SCOPE */

/* ////////////////////////////////////////////////////////////////////// */
