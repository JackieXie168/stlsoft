/* ////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/memory/allocator_features.hpp (formerly stlsoft/memory/allocator_base.hpp, stlsoft/allocator_base.hpp; originally stlsoft_allocator_base.h)
 *
 * Purpose:     Allocator commmon features.
 *
 * Created:     20th August 2003
 * Updated:     27th March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file stlsoft/memory/allocator_features.hpp
///
/// Allocator commmon features.

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES
#define STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES_MAJOR    5
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES_MINOR    0
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES_REVISION 1
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES_EDIT     30
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */

/* ////////////////////////////////////////////////////////////////////////////
 * Allocator compatibilities
 */

/* stl-like allocator classes need deallocate to use void *
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
 *
 * Note: this should be resolving on the library, not the compiler
 */
#define STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER   /* This is standard behaviour */

/* stl-like allocator classes need a _Charalloc method
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
 *
 * Note: this should be resolving on the library, not the compiler
 */
#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# undef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD           /* This is NOT standard behaviour */
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */


#if defined(STLSOFT_COMPILER_IS_DMC)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#elif (   defined(STLSOFT_COMPILER_IS_INTEL) || \
          defined(STLSOFT_COMPILER_IS_MSVC)) && \
      (   _MSC_VER >= 1100 && \
          _MSC_VER < 1300)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
# define STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#endif /* compiler */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#  undef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* stl-like allocator classes' allocate() method takes a second "hint" parameter
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
 *
 * Note: this should be resolving solely on the library (and version), and not involving the compiler
 */
#define STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT  /* This is standard behaviour */

#if defined(STLSOFT_COMPILER_IS_DMC)
# if defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
#  undef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
# endif /* std library */
#endif /* compiler */


/* stl-like allocator classes' deallocate() method takes a second "count" parameter
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
 *
 * Note: this should be resolving solely on the library (and version), and not involving the compiler
 */
#define STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT   /* This is standard behaviour */

#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER < 1100
# undef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
#endif /* compiler */


/* stl-like allocator classes use the rebind mechanism
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
 *
 * Use this symbol when determining whether to provide rebind for an allocator
 */

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT
# define STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT     /* This is standard behaviour */
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT */

#if (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ < 0x0836) || \
    (   (   defined(STLSOFT_COMPILER_IS_INTEL) || \
            defined(STLSOFT_COMPILER_IS_MSVC)) && \
        _MSC_VER < 1300) || \
    defined(STLSOFT_COMPILER_IS_WATCOM)
# undef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
#endif /* _MSC_VER */

/* std::allocator defines a rebind
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
 *
 * Note: Effectively, this can be determines whether _any_ allocator supports rebind.
 *
 * Use this symbol when determining whether to use rebind on an allocator
 */

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
# define STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT    /* This is standard behaviour */
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

#if defined(STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT)
 /* Now work out which libs _don't_ have it */
# if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC)
#  if STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_0
#   undef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#  endif /* STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION */
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_MSL)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI_GNU)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_RW)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_WATCOM_PATCH
# else /* ? library */
#  error Standard library not recognised
# endif /* library */
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Obsolete forwarding #defines
 */

#ifdef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
# define __STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#endif /* STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */

#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# define __STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */

#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
# define __STLSOFT_CF_ALLOCATOR_ALLOCATE_HAS_HINT
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
# define __STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
# define __STLSOFT_CF_ALLOCATOR_DEALLOCATE_HAS_OBJECTCOUNT
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */


// TODO: This needs to be moved to stlsoft_cccap_*.h

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
# define STLSOFT_CF_COMPILER_SUPPORTS_CRTP
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_allocator Allocator Library
/// \ingroup libraries
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types

/// \weakgroup stlsoft_allocator_library Allocator Library (STLSoft)
/// \ingroup STLSoft libraries_allocator
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types
/// @{

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_allocator_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_FEATURES */

/* ////////////////////////////////////////////////////////////////////////// */
