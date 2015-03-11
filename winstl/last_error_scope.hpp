/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/last_error_scope.hpp (formerly winstl_last_error_scope.h; originally MWTErrScp.h, ::SynesisWin)
 *
 * Purpose:     Win32 last error scoping class.
 *
 * Created:     27th November 1998
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/last_error_scope.hpp
///
/// Win32 last error scoping class.

#ifndef WINSTL_INCL_WINSTL_HPP_LAST_ERROR_SCOPE
#define WINSTL_INCL_WINSTL_HPP_LAST_ERROR_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_LAST_ERROR_SCOPE_MAJOR       3
# define WINSTL_VER_WINSTL_HPP_LAST_ERROR_SCOPE_MINOR       1
# define WINSTL_VER_WINSTL_HPP_LAST_ERROR_SCOPE_REVISION    1
# define WINSTL_VER_WINSTL_HPP_LAST_ERROR_SCOPE_EDIT        32
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

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing system attributes

/// \defgroup winstl_system_library System Library (WinSTL)
/// \ingroup WinSTL libraries_system
/// \brief This library provides facilities for accessing Win32 system attributes
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Scopes the thread's last error
///
///
class last_error_scope
{
/// \name Types
/// @{
public:
    typedef last_error_scope    class_type;
/// @}

/// \name Operations
/// @{
public:
    /// Takes a copy of the current thread error, which will be reset
    /// on destruction of this instance
    last_error_scope() stlsoft_throw_0()
        : m_dwErr(::GetLastError())
    {}
    /// Takes a copy of the current thread error, which will be reset
    /// on destruction of this instance. The current thread error is
    /// set to the given value.
    ///
    /// \param dwErr The value to which the current thread error is set
    ss_explicit_k last_error_scope(ws_dword_t dwErr) stlsoft_throw_0()
        : m_dwErr(::GetLastError())
    {
        ::SetLastError(dwErr);
    }
    /// Resets the thread error value current at the epoque of
    /// construction of this instance
    ~last_error_scope() stlsoft_throw_0()
    {
        ::SetLastError(m_dwErr);
    }
/// @}

/// \name Operations
/// @{
public:
    /// Returns the value of the recorded thread error, which will be
    /// reset on destruction of this instance
    operator ws_dword_t() const
    {
        return m_dwErr;
    }
/// @}

// Members
private:
    ws_dword_t  m_dwErr;

// Not to be implemented
private:
    last_error_scope(last_error_scope const &);
    last_error_scope &operator =(last_error_scope const &);
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_system_library

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

#endif /* WINSTL_INCL_WINSTL_HPP_LAST_ERROR_SCOPE */

/* ////////////////////////////////////////////////////////////////////////// */
