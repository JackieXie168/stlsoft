/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/acestl.hpp
 *
 * Purpose:     Root header for the ACESTL libraries. Performs various compiler
 *              and platform discriminations, and definitions of types.
 *
 * Created:     15th September 2004
 * Updated:     6th January 2006
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


#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
#define ACESTL_INCL_ACESTL_HPP_ACESTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_ACESTL_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_ACESTL_MINOR     5
# define ACESTL_VER_ACESTL_HPP_ACESTL_REVISION  1
# define ACESTL_VER_ACESTL_HPP_ACESTL_EDIT      19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file acestl/acestl.hpp The root header for the \ref ACESTL project */

/** \weakgroup projects STLSoft Projects
 *
 * \brief The Projects that comprise the STLSoft libraries
 */

/** \defgroup ACESTL ACESTL
 * \ingroup projects
 *
 * \brief <img src = "acestl32x32.jpg">&nbsp;&nbsp;&nbsp;&nbsp;<i>Template Software for the UNIX Operating System</i>
 *
 * The ACESTL sub-project provides STL abstractions and utility components for
 * use with the Adaptive Communications Environment (ACE; http://www.cs.wustl.edu/~schmidt/ACE.html),
 * the leading open-source C++ network programming toolkit.
 *
 * <b>Namespaces</b>
 *
 * The ACESTL namespace <code><b>acestl</b></code> is actually an alias for the
 * namespace <code><b>stlsoft::acestl_project</b></code>, and as such all the
 * ACESTL project components actually reside within the
 * <code><b>stlsoft</b></code> namespace. However, there is never any need to
 * use the <code><b>stlsoft::acestl_project</b></code> namespace in your code,
 * and you should always use the alias <code><b>acestl</b></code>.
 *
 * <b>Dependencies</b>
 *
 * As with <b><i>all</i></b> parts of the STLSoft libraries, there are no
 * dependencies on ACESTL binary components and no need to compile ACESTL
 * implementation files; ACESTL is <b>100%</b> header-only!
 *
 * As with most of the STLSoft sub-projects, ACESTL depends only on:
 *
 * - Selected headers from the C standard library, such as  <code><b>wchar.h</b></code>
 * - Selected headers from the C++ standard library, such as <code><b>new</b></code>, <code><b>functional</b></code>
 * - Selected header files of the STLSoft main project
 * - The header files particular to the technology area, in this case the ACE library headers, such as <code><b>ace/Log_Msg.h</b></code>
 * - The binary (static and dynamic libraries) components particular to the technology area, in this case the UNIX libraries that ship with the operating system and your compiler(s)
 */

/* /////////////////////////////////////////////////////////////////////////////
 * ACESTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _ACESTL_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _ACESTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _ACESTL_VER_REVISIO preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _ACESTL_VER_MAJOR,
 * _ACESTL_VER_MINOR and _ACESTL_VER_REVISION - a composite symbol _ACESTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _ACESTL_VER_1_0_1.
 *
 * Thus the symbol _ACESTL_VER may be compared meaningfully with a specific
 * version symbol, e.g.# if _ACESTL_VER >= _ACESTL_VER_1_0_1
 */

/// \def _ACESTL_VER_MAJOR
/// The major version number of ACESTL

/// \def _ACESTL_VER_MINOR
/// The minor version number of ACESTL

/// \def _ACESTL_VER_REVISION
/// The revision version number of ACESTL

/// \def _ACESTL_VER
/// The current composite version number of ACESTL

#define _ACESTL_VER_MAJOR      1
#define _ACESTL_VER_MINOR      0
#define _ACESTL_VER_REVISION   3
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _ACESTL_VER_0_9_1     0x00000901  /*!< Version 0.9.1 */
# define _ACESTL_VER_1_0_1     0x00010001  /*!< Version 1.0.1 */
# define _ACESTL_VER_1_0_2     0x00010002  /*!< Version 1.0.2 */
# define _ACESTL_VER_1_0_3     0x00010003  /*!< Version 1.0.3 */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _ACESTL_VER            _ACESTL_VER_1_0_3

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#include <ace/Log_Msg.h>

/* Intel is super pernickety about conversions, so we need to bring out the union_cast. */
#if defined(STLSOFT_COMPILER_IS_INTEL)
# ifndef STLSOFT_INCL_STLSOFT_HPP_UNION_CAST
#  include <stlsoft/union_cast.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_UNION_CAST */
#endif /* STLSOFT_COMPILER_IS_INTEL */

/* /////////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility
 */

#if !defined(_STLSOFT_VER_1_8_3) || \
    _STLSOFT_VER < _STLSOFT_VER_1_8_3
# error This version of the ACESTL libraries requires STLSoft version 1.8.3 or later
#endif /* _STLSOFT_VER < _STLSOFT_VER_1_8_3 */

/* /////////////////////////////////////////////////////////////////////////////
 * Proper C++ casting
 */

#ifdef __cplusplus
# ifdef ACE_WIN32
#  undef     ACE_INVALID_HANDLE
#  if defined(STLSOFT_COMPILER_IS_INTEL)
#   define    ACE_INVALID_HANDLE            stlsoft_ns_qual(make_union_cast)<HANDLE>(-1)
#  else /* ? STLSOFT_COMPILER_IS_INTEL */
#   define    ACE_INVALID_HANDLE            reinterpret_cast<HANDLE>(-1)
#  endif /* STLSOFT_COMPILER_IS_INTEL */
# endif /* ACE_WIN32 */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 *
 * Currently the only compilers supported by the ACESTL libraries are
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Debugging
 *
 * The macro acestl_assert provides standard debug-mode assert functionality.
 */

/// Defines a runtime assertion
///
/// \param expr Must be non-zero, or an assertion will be fired
#define ACESTL_ASSERT(expr)                STLSOFT_ASSERT(expr)

/// Defines a runtime assertion, with message
///
/// \param expr Must be non-zero, or an assertion will be fired
/// \param msg The literal character string message to be included in the assertion
#define ACESTL_MESSAGE_ASSERT(msg, expr)   STLSOFT_MESSAGE_ASSERT(msg, expr)

/// Defines a compile-time assertion
///
/// \param expr Must be non-zero, or compilation will fail
#define ACESTL_STATIC_ASSERT(expr)         STLSOFT_STATIC_ASSERT(expr)



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define acestl_assert(expr)                ACESTL_ASSERT(expr)
# define acestl_message_assert(msg, expr)   ACESTL_MESSAGE_ASSERT(msg, expr)
# define acestl_static_assert(expr)         ACESTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The ACESTL components are contained within the acestl namespace. This is
 * usually an alias for stlsoft::acestl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If _STLSOFT_NO_NAMESPACES is defined, then _ACESTL_NO_NAMESPACES is defined.
 *
 * If _ACESTL_NO_NAMESPACES is defined, then _ACESTL_NO_NAMESPACE is defined.
 *
 * If _ACESTL_NO_NAMESPACE is defined, then the ACESTL constructs are defined
 * in the global scope.
 *
 * If _STLSOFT_NO_NAMESPACES, _ACESTL_NO_NAMESPACES and _ACESTL_NO_NAMESPACE are
 * all undefined but the symbol _STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the ACESTL constructs are defined
 * within the acestl namespace. The definition matrix is as follows:
 *
 * _STLSOFT_NO_NAMESPACE    _ACESTL_NO_NAMESPACE   acestl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::acestl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             acestl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro acestl_ns_qual() macro can be used to refer to elements in the
 * ACESTL libraries irrespective of whether they are in the
 * stlsoft::acestl_project (or acestl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the acestl_ns_qual_std() macro can be used to refer to elements
 * in the ACESTL libraries irrespective of whether they are in the std namespace
 * or in the global namespace.
 */

/* No STLSoft namespaces means no ACESTL namespaces */
#ifdef _STLSOFT_NO_NAMESPACES
# define _ACESTL_NO_NAMESPACES
#endif /* _STLSOFT_NO_NAMESPACES */

/* No ACESTL namespaces means no acestl namespace */
#ifdef _ACESTL_NO_NAMESPACES
# define _ACESTL_NO_NAMESPACE
#endif /* _ACESTL_NO_NAMESPACES */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
/// The ACESTL namespace - \c acestl (aliased to \c stlsoft::acestl_project) - is
/// the namespace for the ACESTL project.
namespace acestl
{
# else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#else
stlsoft_ns_using(move_lhs_from_rhs)
#endif /* !_ACESTL_NO_NAMESPACE */

/// \def acestl_ns_qual(x)
/// Qualifies with <b>acestl::</b> if ACESTL is using namespaces or, if not, does not qualify

/// \def acestl_ns_using(x)
/// Declares a using directive (with respect to <b>acestl</b>) if ACESTL is using namespaces or, if not, does nothing

#ifndef _ACESTL_NO_NAMESPACE
# define acestl_ns_qual(x)             ::acestl::x
# define acestl_ns_using(x)            using ::acestl::x;
#else
# define acestl_ns_qual(x)             x
# define acestl_ns_using(x)
#endif /* !_ACESTL_NO_NAMESPACE */

/// \def acestl_ns_qual_std(x)
/// Qualifies with <b>std::</b> if ACESTL is being translated in the context of the standard library being within the <b>std</b> namespace or, if not, does not qualify

/// \def acestl_ns_using_std(x)
/// Declares a using directive (with respect to <b>std</b>) if ACESTL is being translated in the context of the standard library being within the <b>std</b> namespace or, if not, does nothing

#ifdef __STLSOFT_CF_std_NAMESPACE
# define acestl_ns_qual_std(x)         ::std::x
# define acestl_ns_using_std(x)        using ::std::x;
#else
# define acestl_ns_qual_std(x)         x
# define acestl_ns_using_std(x)
#endif /* !__STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 *
 * The ACESTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef stlsoft_ns_qual(ss_char_a_t)        as_char_a_t;    //!< Ansi char type
typedef stlsoft_ns_qual(ss_char_w_t)        as_char_w_t;    //!< Unicode char type
typedef stlsoft_ns_qual(ss_sint8_t)         as_sint8_t;     //!< 8-bit signed integer
typedef stlsoft_ns_qual(ss_uint8_t)         as_uint8_t;     //!< 8-bit unsigned integer
typedef stlsoft_ns_qual(ss_int16_t)         as_int16_t;     //!< 16-bit integer
typedef stlsoft_ns_qual(ss_sint16_t)        as_sint16_t;    //!< 16-bit signed integer
typedef stlsoft_ns_qual(ss_uint16_t)        as_uint16_t;    //!< 16-bit unsigned integer
typedef stlsoft_ns_qual(ss_int32_t)         as_int32_t;     //!< 32-bit integer
typedef stlsoft_ns_qual(ss_sint32_t)        as_sint32_t;    //!< 32-bit signed integer
typedef stlsoft_ns_qual(ss_uint32_t)        as_uint32_t;    //!< 32-bit unsigned integer
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef stlsoft_ns_qual(ss_int64_t)         as_int64_t;     //!< 64-bit integer
typedef stlsoft_ns_qual(ss_sint64_t)        as_sint64_t;    //!< 64-bit signed integer
typedef stlsoft_ns_qual(ss_uint64_t)        as_uint64_t;    //!< 64-bit unsigned integer
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef stlsoft_ns_qual(ss_int_t)           as_int_t;       //!< integer
typedef stlsoft_ns_qual(ss_sint_t)          as_sint_t;      //!< signed integer
typedef stlsoft_ns_qual(ss_uint_t)          as_uint_t;      //!< unsigned integer
typedef stlsoft_ns_qual(ss_long_t)          as_long_t;      //!< long
typedef stlsoft_ns_qual(ss_bool_t)          as_bool_t;      //!< bool
typedef stlsoft_ns_qual(ss_size_t)          as_size_t;      //!< size
typedef stlsoft_ns_qual(ss_ptrdiff_t)       as_ptrdiff_t;   //!< ptr diff
typedef stlsoft_ns_qual(ss_streampos_t)     as_streampos_t; //!< streampos
typedef stlsoft_ns_qual(ss_streamoff_t)     as_streamoff_t; //!< streamoff

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef _ACESTL_NO_NAMESPACE
typedef as_char_a_t         char_a_t;           //!< Ansi char type
typedef as_char_w_t         char_w_t;           //!< Unicode char type
//typedef as_int8_t           int8_t;             //!< 8-bit integer
typedef as_sint8_t          sint8_t;            //!< 8-bit signed integer
typedef as_uint8_t          uint8_t;            //!< 8-bit unsigned integer
typedef as_int16_t          int16_t;            //!< 16-bit integer
typedef as_sint16_t         sint16_t;           //!< 16-bit signed integer
typedef as_uint16_t         uint16_t;           //!< 16-bit unsigned integer
typedef as_int32_t          int32_t;            //!< 32-bit integer
typedef as_sint32_t         sint32_t;           //!< 32-bit signed integer
typedef as_uint32_t         uint32_t;           //!< 32-bit unsigned integer
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
 typedef as_int64_t         int64_t;            //!< 64-bit integer
 typedef as_sint64_t        sint64_t;           //!< 64-bit signed integer
 typedef as_uint64_t        uint64_t;           //!< 64-bit unsigned integer
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
//typedef as_short_t          short_t;            //!< short integer
typedef as_int_t            int_t;              //!< integer
typedef as_sint_t           sint_t;             //!< signed integer
typedef as_uint_t           uint_t;             //!< unsigned integer
typedef as_long_t           long_t;             //!< long integer
//typedef as_byte_t           byte_t;             //!< Byte
typedef as_bool_t           bool_t;             //!< bool
# if !defined(STLSOFT_COMPILER_IS_DMC)
typedef as_size_t           size_t;             //!< size
typedef as_ptrdiff_t        ptrdiff_t;          //!< ptr diff
typedef as_streampos_t      streampos_t;        //!< streampos
typedef as_streamoff_t      streamoff_t;        //!< streamoff
# endif /* compiler */
#endif /* !_ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * as_true_v and as_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define as_true_v       ss_true_v
#define as_false_v      ss_false_v

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/* /////////////////////////////////////////////////////////////////////////////
 * Code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
# define acestl_throw_0()                               stlsoft_throw_0()
# define acestl_throw_1(x1)                             stlsoft_throw_1(x1)
# define acestl_throw_2(x1, x2)                         stlsoft_throw_2(x1, x2)
# define acestl_throw_3(x1, x2, x3)                     stlsoft_throw_3(x1, x2, x3)
# define acestl_throw_4(x1, x2, x3, x4)                 stlsoft_throw_4(x1, x2, x3, x4)
# define acestl_throw_5(x1, x2, x3, x4, x5)             stlsoft_throw_5(x1, x2, x3, x4, x5)
# define acestl_throw_6(x1, x2, x3, x4, x5, x6)         stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
# define acestl_throw_7(x1, x2, x3, x4, x5, x6, x7)     stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
# define acestl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8) stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// Evaluates, at compile time, to the number of elements within the given vector entity
#define acestl_num_elements(ar)                        stlsoft_num_elements(ar)

/// Destroys the given instance \c p of the given type (\c t and \c _type)
///
/// \deprecated
#define acestl_destroy_instance(t, _type, p)           STLSOFT_DESTROY_INSTANCE(t, _type, p)

/// Generates an opaque type with the name \c _htype
///
/// \deprecated
#define acestl_gen_opaque(_htype)                      STLSOFT_GEN_OPAQUE(_htype)

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
namespace acestl = ::stlsoft::acestl_project;
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */

/* ////////////////////////////////////////////////////////////////////////// */