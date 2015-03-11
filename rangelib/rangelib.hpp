/* /////////////////////////////////////////////////////////////////////////////
 * File:        rangelib/rangelib.hpp
 *
 * Purpose:     Root header for the STLSoft implementation of RangeLib.
 *
 * Created:     12th October 2004
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGELIB
#define RANGELIB_INCL_RANGELIB_HPP_RANGELIB

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define RANGELIB_VER_RANGELIB_HPP_RANGELIB_MAJOR    1
# define RANGELIB_VER_RANGELIB_HPP_RANGELIB_MINOR    2
# define RANGELIB_VER_RANGELIB_HPP_RANGELIB_REVISION 1
# define RANGELIB_VER_RANGELIB_HPP_RANGELIB_EDIT     12
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file rangelib/rangelib.hpp The root header for the \ref rangelib project */

/** \weakgroup projects STLSoft Projects
 *
 * \brief The Projects that comprise the STLSoft libraries
 */

/** \defgroup rangelib RangeLib
 * \ingroup projects
 *
 * \brief &nbsp;&nbsp;&nbsp;&nbsp;<i>The STLSoft implementation of <a href="http://rangelib.org/">RangeLib</a></i>
 *
 * RangeLib defines a <b>range</b> as an iterable collection of elements, one of
 * Notional, Iterable and Indirect categories.
 *
 * The STLSoft \ref rangelib sub-project is an implementation of RangeLib, including
 * range collection classes, range adaptors, and range algorithms
 *
 * <b>Namespaces</b>
 *
 * The RangeLib namespace <code><b>rangelib</b></code> is actually an alias for the
 * namespace <code><b>stlsoft::rangelib_project</b></code>, and as such all the
 * RangeLib project components actually reside within the
 * <code><b>stlsoft</b></code> namespace. However, there is never any need to
 * use the <code><b>stlsoft::rangelib_project</b></code> namespace in your code,
 * and you should always use the alias <code><b>rangelib</b></code>.
 *
 * <b>Dependencies</b>
 *
 * As with <b><i>all</i></b> parts of the STLSoft libraries, there are no
 * dependencies on RangeLib binary components and no need to compile RangeLib
 * implementation files; RangeLib is <b>100%</b> header-only!
 *
 * As with most of the STLSoft sub-projects, RangeLib depends only on:
 *
 * - Selected headers from the C standard library, such as  <code><b>wchar.h</b></code>
 * - Selected headers from the C++ standard library, such as <code><b>new</b></code>, <code><b>functional</b></code>
 * - Selected header files from the STLSoft main project
 */

/* /////////////////////////////////////////////////////////////////////////////
 * RangeLib version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _RANGELIB_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _RANGELIB_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _RANGELIB_VER_REVISIO preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _RANGELIB_VER_MAJOR,
 * _RANGELIB_VER_MINOR and _RANGELIB_VER_REVISION - a composite symbol _RANGELIB_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _RANGELIB_VER_1_0_1.
 *
 * Thus the symbol _RANGELIB_VER may be compared meaningfully with a specific
 * version symbol, e.g. #if _RANGELIB_VER >= _RANGELIB_VER_1_0_1
 */

/// \def _RANGELIB_VER_MAJOR
/// The major version number of RangeLib

/// \def _RANGELIB_VER_MINOR
/// The minor version number of RangeLib

/// \def _RANGELIB_VER_REVISION
/// The revision version number of RangeLib

/// \def _RANGELIB_VER
/// The current composite version number of RangeLib

#define _RANGELIB_VER_MAJOR     1
#define _RANGELIB_VER_MINOR     0
#define _RANGELIB_VER_REVISION  3
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _RANGELIB_VER_1_0_1    0x00010001  /*!< Version 1.0.1 */
# define _RANGELIB_VER_1_0_2    0x00010002  /*!< Version 1.0.2 */
# define _RANGELIB_VER_1_0_3    0x00010003  /*!< Version 1.0.3 */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _RANGELIB_VER             _RANGELIB_VER_1_0_3

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC:     _MSC_VER < 1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility
 */

#if !defined(_STLSOFT_VER_1_8_3) || \
    _STLSOFT_VER < _STLSOFT_VER_1_8_3
# error RangeLib is only compatible with STLSoft version 1.8.3 and above
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 *
 * Currently the only compilers supported by the RangeLib libraries are
 *
 * Borland C++ 5.6+
 * Comeau 4.3.3+
 * Digital Mars C/C++ 8.42+
 * Metrowerks 3.0+ (CodeWarrior 8.0+)
 * Intel C/C++ 8.0+
 * Visual C++ 6.0+
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
/* Borland C++ */
# if __BORLANDC__ < 0x0560
#  error Versions of Borland C++ prior to 5.6 are not supported by the RangeLib libraries
# elif __BORLANDC__ <= 0x0564
#  if defined(_STLSOFT_COMPILE_VERBOSE)
#   pragma message("RangeLib is only partially supported on Borland C/C++ versions 5.6 and 5.6.4")
#  endif /* _STLSOFT_COMPILE_VERBOSE */
# endif /* __BORLANDC__ */

#elif defined(STLSOFT_COMPILER_IS_COMO)
/* Comeau C++ */
# if __COMO_VERSION__ < 4303
#  error Versions of Comeau C++ prior to 4.3.3 are not supported by the RangeLib libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_DMC)
/* Digital Mars C/C++ */
# if __DMC__ < 0x0842
#  error Versions of Digital Mars C/C++ prior to 8.42 are not supported by the RangeLib libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_GCC)
/* Digital Mars C/C++ */
# if __GNUC__ < 3 || \
     (  __GNUC__ == 3 && \
        __GNUC_MINOR__ < 2)
#  error Versions of GCC prior to 3.2 are not supported by the RangeLib libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_INTEL)
/* Intel C++ */
# if (__INTEL_COMPILER < 700)
#  error Versions of Intel C++ prior to 7.0 are not supported by the RangeLib libraries
# endif /* __INTEL_COMPILER */

#elif defined(STLSOFT_COMPILER_IS_MWERKS)
/* Metrowerks C++ */
# if (__MWERKS__ & 0xFF00) < 0x3000
#  error Versions of Metrowerks CodeWarrior C++ prior to 8.x are not supported by the RangeLib libraries
# endif /* __MWERKS__ */

#elif defined(STLSOFT_COMPILER_IS_MSVC)
/* Visual C++ */
# if _MSC_VER < 1200
#  error Versions of Visual C++ prior to 5.0 are not supported by the RangeLib libraries
# elif _MSC_VER < 1310
#  if defined(_STLSOFT_COMPILE_VERBOSE)
#   pragma message("RangeLib is only partially supported on Visual C++ versions 6.0 and 7.0")
#  endif /* _STLSOFT_COMPILE_VERBOSE */
# endif /* _MSC_VER */

#else /* ? compiler */
/* No recognised compiler */
# ifdef _STLSOFT_FORCE_ANY_COMPILER
#  define _RANGELIB_COMPILER_IS_UNKNOWN
#  ifdef _STLSOFT_COMPILE_VERBOSE
#   pragma message("Compiler is unknown to RangeLib")
#  endif /* _STLSOFT_COMPILE_VERBOSE */
# else /* ? _STLSOFT_FORCE_ANY_COMPILER */
#  error Currently only Borland C++, Digital Mars C/C++, Intel C/C++, Metrowerks CodeWarrior and Visual C++ compilers are supported by the RangeLib libraries
# endif /* _STLSOFT_FORCE_ANY_COMPILER */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::rangelib */
namespace rangelib
{
# else
/* Define stlsoft::rangelib_project */

namespace stlsoft
{

namespace rangelib_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \defgroup rangelib RangeLib
/// \ingroup projects
/// \brief The STLSoft implementation of RangeLib
/// @{

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group rangelib

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace rangelib
# else
} // namespace rangelib_project
} // namespace stlsoft
namespace rangelib = ::stlsoft::rangelib_project;
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGELIB */

/* ////////////////////////////////////////////////////////////////////////// */
