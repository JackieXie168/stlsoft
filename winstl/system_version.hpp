/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/system_version.hpp (formerly winstl_system_version.h)
 *
 * Purpose:     Contains the system_version class, which provides
 *              information about the host system version.
 *
 * Created:     10th February 2002
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/system_version.hpp
///
/// Contains the system_version class, which provides information about the host system version.

#ifndef WINSTL_INCL_WINSTL_HPP_SYSTEM_VERSION
#define WINSTL_INCL_WINSTL_HPP_SYSTEM_VERSION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_SYSTEM_VERSION_MAJOR     3
# define WINSTL_VER_WINSTL_HPP_SYSTEM_VERSION_MINOR     1
# define WINSTL_VER_WINSTL_HPP_SYSTEM_VERSION_REVISION  1
# define WINSTL_VER_WINSTL_HPP_SYSTEM_VERSION_EDIT      41
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

/// Provides system version information
///
/// This class wraps the GetSystemInfo() API function. Since the information that
/// this function provides is constant for any particular active system for its
/// lifetime, the function is called only once, as implemented via the
/// get_versioninfo_() method.
class system_version
{
public:
    typedef system_version class_type;

// Operations
public:

    // Operating system type

    /// Returns \c true if the operating system is one of the NT family (NT, 2000, XP, .NET)
    static ws_bool_t winnt();

    /// Returns \c true if the operating system is one of the 95 family (95, 98, ME)
    static ws_bool_t win9x();

    /// Returns \c true if the operating system is Win32s
    static ws_bool_t win32s();

    // Operating system version

    /// Returns the operating system major version
    static ws_uint_t major();

    /// Returns the operating system minor version
    static ws_uint_t minor();

    //  Build number

    /// Returns the operating system build number
    static ws_uint32_t build_number();

    // Structure access

    /// Provides a non-mutable (const) reference to the \c OSVERSIONINFO instance
    static OSVERSIONINFO const &get_versioninfo();

// Implementation
private:
    static OSVERSIONINFO &get_versioninfo_();
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/system_version_unittest_.h"
#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////////
// Implementation


inline /* static */ OSVERSIONINFO &system_version::get_versioninfo_()
{
    /// Unfortunately, something in this technique scares the Borland compilers (5.5
    /// and 5.51) into Internal compiler errors so the s_init variable in
    /// get_versioninfo_() is int rather than bool when compiling for borland.

#if !defined(STLSOFT_STRICT) && \
defined(STLSOFT_COMPILER_IS_MSVC) && \
_MSC_VER >= 1310
# pragma warning(push)
# pragma warning(disable : 4640)   /* "construction of local static object is not thread-safe" - since it is here! (As long as one uses a 'conformant' allocator) - maybe use a spin_mutex in future */
#endif /* _MSC_VER >= 1310 */

    static OSVERSIONINFO    s_versioninfo;
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    /* WSCB: Borland has an internal compiler error if use ws_bool_t */
    static ws_int_t         s_init = (s_versioninfo.dwOSVersionInfoSize = sizeof(s_versioninfo), ::GetVersionEx(&s_versioninfo), ws_true_v);
#else /* ? compiler */
    static ws_bool_t        s_init = (s_versioninfo.dwOSVersionInfoSize = sizeof(s_versioninfo), ::GetVersionEx(&s_versioninfo), ws_true_v);
#endif /* compiler */

#if !defined(STLSOFT_STRICT) && \
defined(STLSOFT_COMPILER_IS_MSVC) && \
_MSC_VER >= 1310
# pragma warning(pop)
#endif /* _MSC_VER >= 1310 */

    STLSOFT_SUPPRESS_UNUSED(s_init); // Placate GCC

    return s_versioninfo;
}

inline /* static */ ws_bool_t system_version::winnt()
{
    return get_versioninfo_().dwPlatformId == VER_PLATFORM_WIN32_NT;
}

inline /* static */ ws_bool_t system_version::win9x()
{
    return get_versioninfo_().dwPlatformId == VER_PLATFORM_WIN32_WINDOWS;
}

inline /* static */ ws_bool_t system_version::win32s()
{
    return get_versioninfo_().dwPlatformId == VER_PLATFORM_WIN32s;
}

inline /* static */ ws_uint_t system_version::major()
{
    return get_versioninfo_().dwMajorVersion;
}

inline /* static */ ws_uint_t system_version::minor()
{
    return get_versioninfo_().dwMinorVersion;
}

inline /* static */ ws_uint32_t system_version::build_number()
{
    return winnt() ? get_versioninfo_().dwBuildNumber : LOWORD(get_versioninfo_().dwBuildNumber);
}

inline /* static */ OSVERSIONINFO const &system_version::get_versioninfo()
{
    return get_versioninfo_();
}

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

#endif /* WINSTL_INCL_WINSTL_HPP_SYSTEM_VERSION */

/* ////////////////////////////////////////////////////////////////////////// */