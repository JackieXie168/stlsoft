/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/cccap/intel.h
 *
 * Purpose:     Compiler feature discrimination for Intel C/C++.
 *
 * Created:     7th February 2003
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error This file must not be included independently of stlsoft/stlsoft.h
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/// \file stlsoft/internal/cccap/intel.h
///
/// Compiler feature discrimination for Intel C/C++.

#ifdef STLSOFT_INCL_H_STLSOFT_CCCAP_INTEL
# error This file cannot be included more than once in any compilation unit
#endif /* STLSOFT_INCL_H_STLSOFT_CCCAP_INTEL */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define  STLSOFT_VER_H_STLSOFT_CCCAP_INTEL_MAJOR       3
# define  STLSOFT_VER_H_STLSOFT_CCCAP_INTEL_MINOR       0
# define  STLSOFT_VER_H_STLSOFT_CCCAP_INTEL_REVISION    1
# define  STLSOFT_VER_H_STLSOFT_CCCAP_INTEL_EDIT        46
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler features
 */

/* For this to work, -Qvc7.1 must be defined. */
#if __INTEL_COMPILER == 700 && \
    _MSC_VER == 1310
# define STLSOFT_INCL_H_STLSOFT_CCCAP_INTEL_7_1
#endif /* __INTEL_COMPILER == 700 && _MSC_VER == 1310 */


/* Messaging
 */

#define STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT

/* Types:
 */

/* bool */
#if !defined(_MSC_VER) || \
    defined(__BOOL_DEFINED)
# define __STLSOFT_CF_NATIVE_BOOL_SUPPORT
#else
 /* Not defined */
#endif /* __BOOL_DEFINED */

/* wchar_t */
//#define __STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT

/* 8-bit integer */
#define STLSOFT_CF_8BIT_INT_SUPPORT
#define STLSOFT_CF_8BIT_INT_IS_EXTENDED_TYPE
#if _MSC_VER == 1200
# define STLSOFT_CF_8BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#endif /* _MSC_VER */
#define STLSOFT_CF_EXTENDED_INT8_T              __int8
#define STLSOFT_CF_EXTENDED_SINT8_T      signed __int8
#define STLSOFT_CF_EXTENDED_UINT8_T    unsigned __int8
#define STLSOFT_CF_STANDART_INT8_IS_char
#define STLSOFT_CF_STANDARD_INT8_T              char
#define STLSOFT_CF_STANDARD_SINT8_T      signed char
#define STLSOFT_CF_STANDARD_UINT8_T    unsigned char

/* 16-bit integer */
#define STLSOFT_CF_16BIT_INT_SUPPORT
#define STLSOFT_CF_16BIT_INT_IS_EXTENDED_TYPE
#if _MSC_VER == 1200
# define STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#endif /* _MSC_VER */
#define STLSOFT_CF_EXTENDED_INT16_T             __int16
#define STLSOFT_CF_EXTENDED_SINT16_T     signed __int16
#define STLSOFT_CF_EXTENDED_UINT16_T   unsigned __int16
#define STLSOFT_CF_STANDARD_INT16_IS_short
#define STLSOFT_CF_STANDARD_INT16_T             short
#define STLSOFT_CF_STANDARD_SINT16_T     signed short
#define STLSOFT_CF_STANDARD_UINT16_T   unsigned short

/* 32-bit integer */
#define STLSOFT_CF_32BIT_INT_SUPPORT
#define STLSOFT_CF_32BIT_INT_IS_EXTENDED_TYPE
#if _MSC_VER == 1200
# define STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#endif /* _MSC_VER */
#define STLSOFT_CF_EXTENDED_INT32_T            __int32
#define STLSOFT_CF_EXTENDED_SINT32_T    signed __int32
#define STLSOFT_CF_EXTENDED_UINT32_T  unsigned __int32
#define STLSOFT_CF_STANDARD_INT32_IS_long
#define STLSOFT_CF_STANDARD_INT32_T            long
#define STLSOFT_CF_STANDARD_SINT32_T    signed long
#define STLSOFT_CF_STANDARD_UINT32_T  unsigned long

/* 64-bit integer */
#define STLSOFT_CF_64BIT_INT_SUPPORT
#define STLSOFT_CF_64BIT_INT_IS_EXTENDED_TYPE
#define STLSOFT_CF_64BIT_INT_IS___int64
#define STLSOFT_CF_EXTENDED_INT64_T             __int64
#define STLSOFT_CF_EXTENDED_SINT64_T     signed __int64
#define STLSOFT_CF_EXTENDED_UINT64_T   unsigned __int64


/* Are integers a unique type (i.e. not int8/16/32/64)? */
#if _MSC_VER == 1200
# define __STLSOFT_CF_INT_DISTINCT_TYPE
#endif /* _MSC_VER == 1200 */

/* Member constants */
#define STLSOFT_CF_MEMBER_CONSTANT_SUPPORT

/* Static assertions */
#define __STLSOFT_CF_STATIC_ASSERT_SUPPORT

#define __STLSOFT_CF_STATIC_ASSERT_RELEASE_OPTIMISATION_SUPPORT

/* Exception support */
#ifdef _CPPUNWIND
# define __STLSOFT_CF_EXCEPTION_SUPPORT
#else
 /* Not defined */
#endif /* _CPPUNWIND */

/*  */
#define __STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED

/* Namespace support */
//#define _STLSOFT_NO_NAMESPACES

#define __STLSOFT_CF_NAMESPACE_SUPPORT

#define STLSOFT_CF_ANONYMOUS_UNION_SUPPORT

#define STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

/* Template support */
#define __STLSOFT_CF_TEMPLATE_SUPPORT

//#define STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS

#define __STLSOFT_CF_EXCEPTION_SIGNATURE_SUPPORT

//#define STLSOFT_CF_EXCEPTION_SPEC_EXPENSIVE


//# define __STLSOFT_CF_THROW_BAD_ALLOC

#define __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT

#define __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT

#define STLSOFT_CF_MEM_FUNC_AS_TEMPLATE_PARAM_SUPPORT

#define __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT

#define STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED

#define __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT

#define STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED

#define __STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT

#define __STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT

#define __STLSOFT_CF_TEMPLATE_SPECIALISATION_SYNTAX

#define __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

#define __STLSOFT_CF_TEMPLATE_OUTOFCLASSFN_QUALIFIED_TYPE_SUPPORT

#define __STLSOFT_CF_std_NAMESPACE

#define __STLSOFT_CF_std_char_traits_AVAILABLE

/* This is no longer supported here. Include stlsoft/allocator_base.hpp
#define __STLSOFT_CF_ALLOCATOR_ALLOCATE_HAS_HINT
 */

/* This is no longer supported here. Include stlsoft/allocator_base.hpp
#define __STLSOFT_CF_ALLOCATOR_DEALLOCATE_HAS_OBJECTCOUNT
 */

/* This is no longer supported here. Include stlsoft/util/std/library_discriminator.hpp
#define STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
 */

#define __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT

#define __STLSOFT_CF_EXPLICIT_KEYWORD_SUPPORT

#define __STLSOFT_CF_MUTABLE_KEYWORD_SUPPORT

#define __STLSOFT_CF_TYPENAME_PARAM_KEYWORD_SUPPORT

#define __STLSOFT_CF_TYPENAME_TYPE_KEYWORD_SUPPORT

#define __STLSOFT_CF_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT

#define __STLSOFT_CF_TYPENAME_TYPE_MIL_KEYWORD_SUPPORT

//#define STLSOFT_CF_TEMPLATE_QUALIFIER_KEYWORD_SUPPORT

#ifdef _MSC_EXTENSIONS
# define __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
#endif /* _MSC_EXTENSIONS */

#if defined(STLSOFT_INCL_H_STLSOFT_CCCAP_INTEL_7_1) || \
    __INTEL_COMPILER >= 800
# define __STLSOFT_CF_KOENIG_LOOKUP_SUPPORT
#endif /* STLSOFT_INCL_H_STLSOFT_CCCAP_INTEL_7_1  || __INTEL_COMPILER >= 800 */

#define __STLSOFT_CF_TEMPLATE_TEMPLATE_SUPPORT

#define __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

#define __STLSOFT_CF_VENEER_SUPPORT

#if !defined(_ATL_MIN_CRT)
# define STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE
#endif /* !_ATL_MIN_CRT */

//#define STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR

// Shims are supported
//# define __STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

#define __STLSOFT_CF_NEGATIVE_MODULUS_POSITIVE_GIVES_NEGATIVE_RESULT

#if !defined(_MSC_VER) || \
    _MSC_VER >= 1300
# define STLSOFT_CF_OPERATOR_BOOL_AS_OPERATOR_POINTER_TO_MEMBER_SUPPORT
# define STLSOFT_CF_OPERATOR_NOT_VIA_OPERATOR_POINTER_TO_MEMBER_SUPPORT
#endif /* !_MSC_VER || _MSC_VER >= 1300 */

#if defined(_STLSOFT_CUSTOM_ASSERT)
 /* You have defined the pre-processor symbol _STLSOFT_CUSTOM_ASSERT,
  * which stipulates that you will be providing your own assert. This
  * requires that you have defined _STLSOFT_CUSTOM_ASSERT() as a macro
  * taking 1 parameter (the condition to assert).
  *
  * Suppose you have a function _DisplayAssert(), which has the
  * following signature:
  *
  *   void _DisplayAssert(char const *file, int line, char const *expression);
  *
  * Presumably you would also have your own assert macro, say MY_ASSERT(),
  * defined as:
  *
  *   #define MY_ASSERT(_x) ((void)((!(_x)) ? ((void)(_DisplayAssert(__FILE__, __LINE__, #_x))) : ((void)0)))
  *
  * so you would simply need to define _STLSOFT_CUSTOM_ASSERT() in terms of
  * MY_ASSERT(), as in:
  *
  *  #define _STLSOFT_CUSTOM_ASSERT(_x)    MY_ASSERT(_x)
  *
  * where
  */
# define __STLSOFT_CF_ASSERT_SUPPORT
# define stlsoft_assert(_x)                     _STLSOFT_CUSTOM_ASSERT(_x)
# if defined(_STLSOFT_CUSTOM_ASSERT_INCLUDE)
#  define   __STLSOFT_CF_ASSERT_INCLUDE_NAME    _STLSOFT_CUSTOM_ASSERT_INCLUDE
# else
#  error You must define _STLSOFT_CUSTOM_ASSERT_INCLUDE along with _STLSOFT_CUSTOM_ASSERT()
# endif /* !_STLSOFT_CUSTOM_ASSERT_INCLUDE */
#else
# define __STLSOFT_CF_ASSERT_SUPPORT
 //#define   __STLSOFT_CF_USE_cassert
# ifdef _MSC_VER
#  if defined(__cplusplus) && \
      _MSC_VER >= 1200
#   include <new> /* Used to ensure that the headers don't get confused between <new> and
                   * <crtdbg.h>, which results in balking on exception specifications on op new
                   */
#  endif /* C++ && _MSC_VER >= 1300 */
#  define __STLSOFT_CF_ASSERT_INCLUDE_NAME       <crtdbg.h>
#  define stlsoft_assert(_x)                     _ASSERTE(_x)
# else /* _MSC_VER */
#  define __STLSOFT_CF_ASSERT_INCLUDE_NAME       <assert.h>
#  define stlsoft_assert(_x)                     assert(_x)
# endif /* _MSC_VER */
#endif /* _STLSOFT_CUSTOM_ASSERT */

/* /////////////////////////////////////////////////////////////////////////////
 * Calling convention
 */

#if !defined(unix) && \
    !defined(__unix__)

# define STLSOFT_CF_FASTCALL_SUPPORTED
# define STLSOFT_CF_STDCALL_SUPPORTED

# define    STLSOFT_CDECL               __cdecl
# define    STLSOFT_FASTCALL            __fastcall
# define    STLSOFT_STDCALL             __stdcall

#endif /* !unix && !__unix__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Inline assembler
 */

#define STSLSOFT_INLINE_ASM_SUPPORTED
#define STSLSOFT_ASM_IN_INLINE_SUPPORTED

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warning suppression
 */

#ifdef _DEBUG
/* Suppresses: "expression has no effect" */
# pragma warning(disable : 174)
#endif /* _DEBUG */

/* Suppresses: "controlling expression is constant" */
#pragma warning(disable : 279)

#ifdef _DEBUG
/* Suppresses: "value copied to temporary, reference to temporary used" */
# pragma warning(disable : 383)
#endif /* _DEBUG */

/* Suppresses: "operands are evaluated in unspecified order" */
#pragma warning(disable : 981)

/* ////////////////////////////////////////////////////////////////////////// */
