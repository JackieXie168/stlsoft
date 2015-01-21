/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/util/features.h
 *
 * Purpose:     Discrimination of synchronisation features.
 *
 * Created:     23rd October 1997
 * Updated:     15th January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2007, Matthew Wilson and Synesis Software
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


/** \file unixstl/synch/util/features.h
 *
 * \brief [C++ only] Discrimination of synchronisation features
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES
#define UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_FEATURES_MAJOR    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_FEATURES_MINOR    0
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_FEATURES_REVISION 1
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_FEATURES_EDIT     1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */

/* /////////////////////////////////////////////////////////////////////////
 * Features
 *
 * 1. UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS
 * 2. UNIXSTL_USING_PTHREADS
 */

/* 1. UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** \def UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS
 *
 * \brief If defined, indicates that the operating system supports atomic
 *   integer operations, and that they're safe for use outside the kernel.
 *
 * Atomic integer operations are assumed on the following "UNIX" platforms:
 *
 * - 1. Mac OS-X (via OSAtomicIncrement32Barrier(), etc; &lt;libkern/OSAtomic.h>)
 * - 2. Win32 (via InterlockedIncrement(), etc; &lt;windows.h>)
 *
 * or:
 *
 * - 3. the symbol UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS is defined. In this
 *      case, you must also define UNIXSTL_FORCED_ATOMIC_INT_T (as the atomic
 *      integer type, e.g. int) and UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS
 *      (as the file to be included _inside_ the unixstl namespace in
 *      unixstl/synch/atomic_functions.h)
 */
# define UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

# ifdef UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS
#  undef UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS
# endif /* UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

# if defined(UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS) || \
	 defined(_WIN32) || \
	 defined(UNIXSTL_OS_IS_MACOSX)
#  define UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS
# endif

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* 1. UNIXSTL_USING_PTHREADS */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** \def UNIXSTL_USING_PTHREADS
 *
 * \brief If defined, indicates that PThreads is selected.
 *
 * PThreads is selected if:
 *
 * - _REENTRANT is defined, or 
 * - _POSIX_THREADS is defined, or
 * - UNIXSTL_FORCE_PTHREADS is defined, which causes &lt;pthread.h> to be
 *    included, and the symbols _REENTRANT and/or _POSIX_THREADS to be
 *    defined if they are not already.
 */
# define UNIXSTL_USING_PTHREADS

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

# ifdef UNIXSTL_USING_PTHREADS
#  undef UNIXSTL_USING_PTHREADS
# endif /* UNIXSTL_USING_PTHREADS */

# if defined(UNIXSTL_FORCE_PTHREADS)
#  ifndef _REENTRANT
#   define _REENTRANT
#  endif /* !_REENTRANT */
#  ifndef _POSIX_THREADS
#   define _POSIX_THREADS
#  endif /* !_POSIX_THREADS */
#  include <pthread.h>
# endif /* UNIXSTL_FORCE_PTHREADS */

# if defined(_REENTRANT) || \
     defined(_POSIX_THREADS)
#  define UNIXSTL_USING_PTHREADS
# endif

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES */

/* ////////////////////////////////////////////////////////////////////// */