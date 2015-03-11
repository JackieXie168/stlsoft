/* /////////////////////////////////////////////////////////////////////////////
 * File:        platformstl/atomic_functions.h
 *
 * Purpose:     Platform header for reference-counting functions.
 *
 * Created:     22nd March 2005
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_REFCOUNT_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_H_REFCOUNT_FUNCTIONS

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_H_REFCOUNT_FUNCTIONS_MAJOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_H_REFCOUNT_FUNCTIONS_MINOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_H_REFCOUNT_FUNCTIONS_REVISION 4
# define PLATFORMSTL_VER_PLATFORMSTL_H_REFCOUNT_FUNCTIONS_EDIT     11
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MWERKS: __MWERKS__<0x3000
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_H_ATOMIC_FUNCTIONS
#  include <unixstl/atomic_functions.h>
# endif /* !UNIXSTL_INCL_UNIXSTL_H_ATOMIC_FUNCTIONS */
#elif defined(PLATFORMSTL_OS_IS_WIN32)
# ifndef WINSTL_INCL_WINSTL_H_ATOMIC_FUNCTIONS
#  include <winstl/atomic_functions.h>
# endif /* !WINSTL_INCL_WINSTL_H_ATOMIC_FUNCTIONS */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{

namespace platformstl_project
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#if defined(__cplusplus)
    namespace implementation
    {
# if defined(PLATFORMSTL_OS_IS_UNIX)

        namespace platform_stl_ =   ::unixstl;

# elif defined(PLATFORMSTL_OS_IS_WIN32)

        namespace platform_stl_ =   ::winstl;

# else /* ? operating system */
#  error Operating system not discriminated
# endif /* operating system */
    }

# if (   defined(PLATFORMSTL_OS_IS_UNIX) && \
         defined(_UNIXSTL_NO_NAMESPACE)) || \
     (   defined(PLATFORMSTL_OS_IS_WIN32) && \
         defined(_WINSTL_NO_NAMESPACE))
 /* Source atomic functions are defined within a namespace, either unixstl or winstl. */
#  if defined(PLATFORMSTL_OS_IS_UNIX)
   /* OS: UNIX */
#   if defined(UNIXSTL_OS_IS_LINUX)
    /* OS (flavour): Linux */
#    if defined(UNIXSTL_ARCH_IS_INTEL)
     /* Arch: i386 */
    using atomic_read;
    using atomic_write;
#    else /* ? arch */
#     error Currently only defined for Intel Linuxen; If you would like to contribute for your platform, you would be most welcome.
#    endif /* arch */
#   elif defined(UNIXSTL_ARCH_IS_POWERPC)
    /* Arch: PowerPC */
    using atomic_preincrement;
    using atomic_predecrement;
    using atomic_postincrement;
    using atomic_postdecrement;
    using atomic_increment;
    using atomic_decrement;
    using atomic_read;
    using atomic_preadd;
    using atomic_postadd;
#   else /* ? architecture */
#    error Currently only defined for Intel (Linux-only) and Power-PC architectures; If you would like to contribute for your platform, you would be most welcome.
#   endif /* architecture */
#  elif defined(PLATFORMSTL_OS_IS_WIN32)
   /* OS: Win32 */
#   if defined(_M_IX86) /* TODO: Abstract this for WinSTL as has been done for UNIXSTL */
    /* Arch: i386 */
    using atomic_preincrement_up;
    using atomic_predecrement_up;
    using atomic_postincrement_up;
    using atomic_postdecrement_up;
    using atomic_increment_up;
    using atomic_decrement_up;
    using atomic_write_up;
    using atomic_read_up;
    using atomic_postadd_up;
    using atomic_preadd_up;
    using atomic_preincrement_smp;
    using atomic_predecrement_smp;
    using atomic_postincrement_smp;
    using atomic_postdecrement_smp;
    using atomic_increment_smp;
    using atomic_decrement_smp;
    using atomic_write_smp;
    using atomic_read_smp;
    using atomic_postadd_smp;
    using atomic_preadd_smp;
    using atomic_preincrement;
    using atomic_predecrement;
    using atomic_postincrement;
    using atomic_postdecrement;
    using atomic_increment;
    using atomic_decrement;
    using atomic_write;
    using atomic_read;
    using atomic_postadd;
    using atomic_preadd;
#   else /* ? arch */
#    error Not valid for processors other than Intel
#   endif /* arch */
#  else /* ? operating system */
#   error Operating system not discriminated
#  endif /* operating system */
# else /* ? global */
 /* Source atomic functions are defined within the global namespace. */
#  if defined(PLATFORMSTL_OS_IS_UNIX)
   /* OS: UNIX */
#   if defined(UNIXSTL_OS_IS_LINUX)
    /* OS (flavour): Linux */
#    if defined(UNIXSTL_ARCH_IS_INTEL)
     /* Arch: i386 */
    using implementation::platform_stl_::atomic_read;
    using implementation::platform_stl_::atomic_write;
#    else /* ? arch */
#     error Currently only defined for Intel Linuxen; If you would like to contribute for your platform, you would be most welcome.
#    endif /* arch */
#   elif defined(UNIXSTL_ARCH_IS_POWERPC)
    /* Arch: PowerPC */
    using implementation::platform_stl_::atomic_preincrement;
    using implementation::platform_stl_::atomic_predecrement;
    using implementation::platform_stl_::atomic_postincrement;
    using implementation::platform_stl_::atomic_postdecrement;
    using implementation::platform_stl_::atomic_increment;
    using implementation::platform_stl_::atomic_decrement;
    using implementation::platform_stl_::atomic_read;
    using implementation::platform_stl_::atomic_preadd;
    using implementation::platform_stl_::atomic_postadd;
#   else /* ? architecture */
#    error Currently only defined for Intel (Linux-only) and Power-PC architectures; If you would like to contribute for your platform, you would be most welcome.
#   endif /* architecture */
#  elif defined(PLATFORMSTL_OS_IS_WIN32)
   /* OS: Win32 */
#   if defined(_M_IX86) /* TODO: Abstract this for WinSTL as has been done for UNIXSTL */
    /* Arch: i386 */
    using implementation::platform_stl_::atomic_preincrement_up;
    using implementation::platform_stl_::atomic_predecrement_up;
    using implementation::platform_stl_::atomic_postincrement_up;
    using implementation::platform_stl_::atomic_postdecrement_up;
    using implementation::platform_stl_::atomic_increment_up;
    using implementation::platform_stl_::atomic_decrement_up;
    using implementation::platform_stl_::atomic_write_up;
    using implementation::platform_stl_::atomic_read_up;
    using implementation::platform_stl_::atomic_postadd_up;
    using implementation::platform_stl_::atomic_preadd_up;
    using implementation::platform_stl_::atomic_preincrement_smp;
    using implementation::platform_stl_::atomic_predecrement_smp;
    using implementation::platform_stl_::atomic_postincrement_smp;
    using implementation::platform_stl_::atomic_postdecrement_smp;
    using implementation::platform_stl_::atomic_increment_smp;
    using implementation::platform_stl_::atomic_decrement_smp;
    using implementation::platform_stl_::atomic_write_smp;
    using implementation::platform_stl_::atomic_read_smp;
    using implementation::platform_stl_::atomic_postadd_smp;
    using implementation::platform_stl_::atomic_preadd_smp;
    using implementation::platform_stl_::atomic_preincrement;
    using implementation::platform_stl_::atomic_predecrement;
    using implementation::platform_stl_::atomic_postincrement;
    using implementation::platform_stl_::atomic_postdecrement;
    using implementation::platform_stl_::atomic_increment;
    using implementation::platform_stl_::atomic_decrement;
    using implementation::platform_stl_::atomic_write;
    using implementation::platform_stl_::atomic_read;
    using implementation::platform_stl_::atomic_postadd;
    using implementation::platform_stl_::atomic_preadd;

#   else /* ? arch */
#    error Not valid for processors other than Intel
#   endif /* arch */
#  else /* ? operating system */
#   error Operating system not discriminated
#  endif /* operating system */
# endif /* global */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

#if !defined(__cplusplus)
 /* Nothing defined in C */
#elif defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_REFCOUNT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
