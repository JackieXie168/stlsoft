/* /////////////////////////////////////////////////////////////////////////////
 * File:        platformstl/platformstl.h
 *
 * Purpose:     Root header for the PlatformSTL C/C++ libraries. Performs
 *              platform discriminations, and definitions of types.
 *
 * Created:     20th March 2005
 * Updated:     6th January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
#define PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_H_PLATFORMSTL_MAJOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_H_PLATFORMSTL_MINOR    8
# define PLATFORMSTL_VER_PLATFORMSTL_H_PLATFORMSTL_REVISION 1
# define PLATFORMSTL_VER_PLATFORMSTL_H_PLATFORMSTL_EDIT     13
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file platformstl/platformstl.h Root header for the PlatformSTL C/C++ libraries */

/** \weakgroup projects STLSoft Projects
 *
 * \brief The Projects that comprise the STLSoft libraries
 */

/** \defgroup PlatformSTL PlatformSTL
 * \ingroup projects
 *
 * \brief <img src = "platformstl32x32.jpg">&nbsp;&nbsp;&nbsp;&nbsp;<i>Template Software for the UNIX Operating System</i>
 *
 * The philosophy of PlatformSTL (http://platformstl.org/) is essentially the same as that
 * of the STLSoft (http://stlsoft.org/) organisation: providing robust and
 * lightweight software to the UNIX development
 * community. PlatformSTL provides template-based software that builds on that
 * provided by UNIX and STLSoft in order to reduce programmer effort and increase
 * robustness in the use of the UNIX.
 *
 * <b>Namespaces</b>
 *
 * The PlatformSTL namespace <code><b>platformstl</b></code> is actually an alias for the
 * namespace <code><b>stlsoft::platformstl_project</b></code>, and as such all the
 * PlatformSTL project components actually reside within the
 * <code><b>stlsoft</b></code> namespace. However, there is never any need to
 * use the <code><b>stlsoft::platformstl_project</b></code> namespace in your code,
 * and you should always use the alias <code><b>platformstl</b></code>.
 *
 * <b>Dependencies</b>
 *
 * As with <b><i>all</i></b> parts of the STLSoft libraries, there are no
 * dependencies on PlatformSTL binary components and no need to compile PlatformSTL
 * implementation files; PlatformSTL is <b>100%</b> header-only!
 *
 * As with most of the STLSoft sub-projects, PlatformSTL depends only on:
 *
 * - Selected headers from the C standard library, such as  <code><b>wchar.h</b></code>
 * - Selected headers from the C++ standard library, such as <code><b>new</b></code>, <code><b>functional</b></code>
 * - Selected header files of the STLSoft main project
 * - The header files particular to the technology area, in this case the UNIX library headers, such as <code><b>dirent.h</b></code>
 * - The binary (static and dynamic libraries) components particular to the technology area, in this case the UNIX libraries that ship with the operating system and your compiler(s)
 */

/* /////////////////////////////////////////////////////////////////////////////
 * PlatformSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _PLATFORMSTL_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _PLATFORMSTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _PLATFORMSTL_VER_REVISIO preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _PLATFORMSTL_VER_MAJOR,
 * _PLATFORMSTL_VER_MINOR and _PLATFORMSTL_VER_REVISION - a composite symbol _PLATFORMSTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _PLATFORMSTL_VER_1_0_1.
 *
 * Thus the symbol _PLATFORMSTL_VER may be compared meaningfully with a specific
 * version symbol, e.g.# if _PLATFORMSTL_VER >= _PLATFORMSTL_VER_1_0_1
 */

/// \def _PLATFORMSTL_VER_MAJOR
/// The major version number of PlatformSTL

/// \def _PLATFORMSTL_VER_MINOR
/// The minor version number of PlatformSTL

/// \def _PLATFORMSTL_VER_REVISION
/// The revision version number of PlatformSTL

/// \def _PLATFORMSTL_VER
/// The current composite version number of PlatformSTL

#define _PLATFORMSTL_VER_MAJOR      1
#define _PLATFORMSTL_VER_MINOR      4
#define _PLATFORMSTL_VER_REVISION   1
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _PLATFORMSTL_VER_1_0_1     0x00010001  /*!< Version 1.0.1 */
# define _PLATFORMSTL_VER_1_1_1     0x00010101  /*!< Version 1.1.1 */
# define _PLATFORMSTL_VER_1_1_2     0x00010102  /*!< Version 1.1.2 */
# define _PLATFORMSTL_VER_1_2_1     0x00010201  /*!< Version 1.2.1 */
# define _PLATFORMSTL_VER_1_3_1     0x00010301  /*!< Version 1.3.1 */
# define _PLATFORMSTL_VER_1_4_1     0x00010401  /*!< Version 1.4.1 (12th December 2005) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _PLATFORMSTL_VER            _PLATFORMSTL_VER_1_4_1

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility
 */

#if !defined(_STLSOFT_VER_1_8_9) || \
    _STLSOFT_VER < _STLSOFT_VER_1_8_9
# error This version of the PlatformSTL libraries requires STLSoft version 1.8.9 or later
#endif /* _STLSOFT_VER < _STLSOFT_VER_1_8_9 */

/* /////////////////////////////////////////////////////////////////////////////
 * Operating system identification
 */

#if defined(unix) || \
    defined(UNIX) || \
    defined(__unix__) || \
    defined(__unix)
# define PLATFORMSTL_OS_IS_UNIX
#elif defined(WIN32) || \
      defined(_WIN32) || \
      defined(__WIN32__)
# define PLATFORMSTL_OS_IS_WIN32
#else /* ? operating system */
# error Operating system not discriminated. Only UNIX and Win32 are currently recognised by PlatformSTL
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////////
 * Platform-specific includes
 */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unixstl/unixstl.h>
#elif defined(PLATFORMSTL_OS_IS_WIN32)
# include <winstl/winstl.h>
#else /* ? operating system */
# error Operating system not discriminated. Only UNIX and Win32 are currently recognised by PlatformSTL
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The PLATFORMSTL components are contained within the platformstl namespace. This is
 * usually an alias for stlsoft::platformstl_project,
 *
 * Since STLSoft supports the suspension of namespaces for its main and sub-projects
 * (except PlatformSTL) PlatformSTL must be able to work when STLSoft and/or
 * UNIXSTL and/or WinSTL constructs are defined in the global namespace.
 */

#if defined(__cplusplus)
# if defined(_STLSOFT_NO_NAMESPACES)
#  error PlatformSTL may not be compiled when _STLSOFT_NO_NAMESPACES is defined. Note: it _can_ be compiled in the presence of _STLSOFT_NO_NAMESPACE, or _UNIXSTL_NO_NAMESPACE, or _WINSTL_NO_NAMESPACE
# endif /* _STLSOFT_NO_NAMESPACES */

# if defined(_PLATFORMSTL_NO_NAMESPACES)
#  error Use of namespaces in PlatformSTL may not be suspended; _PLATFORMSTL_NO_NAMESPACES was detected
# endif /* _PLATFORMSTL_NO_NAMESPACES */

# if defined(_PLATFORMSTL_NO_NAMESPACE)
#  error Use of namespaces in PlatformSTL may not be suspended; _PLATFORMSTL_NO_NAMESPACE was detected
# endif /* _PLATFORMSTL_NO_NAMESPACE */
#endif /* __cplusplus */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
/// The PLATFORMSTL namespace - \c platformstl (aliased to \c stlsoft::platformstl_project) - is
/// the namespace for the PLATFORMSTL project.
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{

namespace platformstl_project
{
#endif /* _STLSOFT_NO_NAMESPACE */

/// \def platformstl_ns_qual(x)
/// Qualifies with <b>platformstl::</b> if PlatformSTL is using namespaces or, if not, does not qualify

/// \def platformstl_ns_using(x)
/// Declares a using directive (with respect to <b>platformstl</b>) if PlatformSTL is using namespaces or, if not, does nothing

#ifndef _STLSOFT_NO_NAMESPACE
# define platformstl_ns_qual(x)         ::platformstl::x
# define platformstl_ns_using(x)        using ::platformstl::x;
#else /* ? _STLSOFT_NO_NAMESPACE */
# define platformstl_ns_qual(x)         x
# define platformstl_ns_using(x)
#endif /* !_STLSOFT_NO_NAMESPACE */

/// \def platformstl_ns_qual_std(x)
/// Qualifies with <b>std::</b> if PlatformSTL is being translated in the context of the standard library being within the <b>std</b> namespace or, if not, does not qualify

/// \def platformstl_ns_using_std(x)
/// Declares a using directive (with respect to <b>std</b>) if PlatformSTL is being translated in the context of the standard library being within the <b>std</b> namespace or, if not, does nothing

#ifdef __STLSOFT_CF_std_NAMESPACE
# define platformstl_ns_qual_std(x)     ::std::x
# define platformstl_ns_using_std(x)    using ::std::x;
#else /* ? __STLSOFT_CF_std_NAMESPACE */
# define platformstl_ns_qual_std(x)     x
# define platformstl_ns_using_std(x)
#endif /* !__STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(PLATFORMSTL_OS_IS_UNIX)
typedef unixstl_ns_qual(us_char_a_t)        char_a_t;    //!< Ansi char type
typedef unixstl_ns_qual(us_char_w_t)        char_w_t;    //!< Unicode char type
typedef unixstl_ns_qual(us_sint8_t)         sint8_t;     //!< 8-bit signed integer
typedef unixstl_ns_qual(us_uint8_t)         uint8_t;     //!< 8-bit unsigned integer
typedef unixstl_ns_qual(us_int16_t)         int16_t;     //!< 16-bit integer
typedef unixstl_ns_qual(us_sint16_t)        sint16_t;    //!< 16-bit signed integer
typedef unixstl_ns_qual(us_uint16_t)        uint16_t;    //!< 16-bit unsigned integer
typedef unixstl_ns_qual(us_int32_t)         int32_t;     //!< 32-bit integer
typedef unixstl_ns_qual(us_sint32_t)        sint32_t;    //!< 32-bit signed integer
typedef unixstl_ns_qual(us_uint32_t)        uint32_t;    //!< 32-bit unsigned integer
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef unixstl_ns_qual(us_int64_t)         int64_t;     //!< 64-bit integer
typedef unixstl_ns_qual(us_sint64_t)        sint64_t;    //!< 64-bit signed integer
typedef unixstl_ns_qual(us_uint64_t)        uint64_t;    //!< 64-bit unsigned integer
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef unixstl_ns_qual(us_int_t)           int_t;       //!< integer
typedef unixstl_ns_qual(us_sint_t)          sint_t;      //!< signed integer
typedef unixstl_ns_qual(us_uint_t)          uint_t;      //!< unsigned integer
typedef unixstl_ns_qual(us_long_t)          long_t;      //!< long
typedef unixstl_ns_qual(us_bool_t)          bool_t;      //!< bool
typedef unixstl_ns_qual(us_size_t)          size_t;      //!< size
typedef unixstl_ns_qual(us_ptrdiff_t)       ptrdiff_t;   //!< ptr diff
typedef unixstl_ns_qual(us_streampos_t)     streampos_t; //!< streampos
typedef unixstl_ns_qual(us_streamoff_t)     streamoff_t; //!< streamoff
# elif defined(PLATFORMSTL_OS_IS_WIN32)
typedef winstl_ns_qual(ws_char_a_t)         char_a_t;    //!< Ansi char type
typedef winstl_ns_qual(ws_char_w_t)         char_w_t;    //!< Unicode char type
typedef winstl_ns_qual(ws_sint8_t)          sint8_t;     //!< 8-bit signed integer
typedef winstl_ns_qual(ws_uint8_t)          uint8_t;     //!< 8-bit unsigned integer
typedef winstl_ns_qual(ws_int16_t)          int16_t;     //!< 16-bit integer
typedef winstl_ns_qual(ws_sint16_t)         sint16_t;    //!< 16-bit signed integer
typedef winstl_ns_qual(ws_uint16_t)         uint16_t;    //!< 16-bit unsigned integer
typedef winstl_ns_qual(ws_int32_t)          int32_t;     //!< 32-bit integer
typedef winstl_ns_qual(ws_sint32_t)         sint32_t;    //!< 32-bit signed integer
typedef winstl_ns_qual(ws_uint32_t)         uint32_t;    //!< 32-bit unsigned integer
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef winstl_ns_qual(ws_int64_t)          int64_t;     //!< 64-bit integer
typedef winstl_ns_qual(ws_sint64_t)         sint64_t;    //!< 64-bit signed integer
typedef winstl_ns_qual(ws_uint64_t)         uint64_t;    //!< 64-bit unsigned integer
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef winstl_ns_qual(ws_int_t)            int_t;       //!< integer
typedef winstl_ns_qual(ws_sint_t)           sint_t;      //!< signed integer
typedef winstl_ns_qual(ws_uint_t)           uint_t;      //!< unsigned integer
typedef winstl_ns_qual(ws_long_t)           long_t;      //!< long
#ifdef __cplusplus
typedef winstl_ns_qual(ws_bool_t)           bool_t;      //!< bool
#endif /* __cplusplus */
typedef winstl_ns_qual(ws_size_t)           size_t;      //!< size
typedef winstl_ns_qual(ws_ptrdiff_t)        ptrdiff_t;   //!< ptr diff
typedef winstl_ns_qual(ws_streampos_t)      streampos_t; //!< streampos
typedef winstl_ns_qual(ws_streamoff_t)      streamoff_t; //!< streamoff
# else /* ? operating system */
# error Operating system not discriminated. Only UNIX and Win32 are currently recognised by PlatformSTL
# endif /* operating system */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
namespace platformstl = ::stlsoft::platformstl_project;
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */

/* ////////////////////////////////////////////////////////////////////////// */
