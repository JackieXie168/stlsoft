/*
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

/*
 * STLport configuration file
 * It is internal STLport header - DO NOT include it directly
 * Purpose of this file : to define STLport settings that depend on
 * compiler flags or can be otherwise missed by "configure"
 *
 */

#ifndef __STL_CONFIX_H
# define __STL_CONFIX_H

// some fixes to configuration, either "configure"d or
// hardcoded. This also includes modifications
// of STLport switches depending on compiler flags 

// sunpro 5.0
# if defined (__SUNPRO_CC)
#  define __STL_NATIVE_INCLUDE_PATH ../CC 
#  if (__SUNPRO_CC >=0x500)
#   undef  __STL_USE_OWN_NAMESPACE
#   define __STL_USE_OWN_NAMESPACE 1
#   ifndef __STL_USE_OWN_NAMESPACE
#    define __STL_USE_SGI_STRING 1
#   endif
#  endif
# endif

// msvc

# if defined(__STL_MSVC)
// fix possible "configure" bugs for VC++
#if __STL_MSVC > 1000
#pragma once				// means include this file only one time.
#pragma warning ( disable : 4355)	// ignore warning "this used in base member initializer list.
#pragma warning ( disable : 4251 )	// ignore template classes being exported in .dll's
#endif
# if (__STL_MSVC < 1100)
#   undef  __STL_DEFAULT_TYPE_PARAM
#   define  __STL_NO_NAMESPACES 1
#   define  __STL_NO_AT_MEMBER_FUNCTION 1
# endif /* (__STL_MSVC < 1100 ) */
# define __STL_MSVC50_COMPATIBILITY   1
# undef __STL_MEMBER_TEMPLATES
# undef __STL_MEMBER_TEMPLATE_CLASSES
# endif /* __STL_MSVC */

// list of compilers to use SGI string
# if (defined (__sgi) || defined (__GNUC__)) 
# if !defined (__STL_USE_SGI_STRING)
#  define __STL_USE_SGI_STRING         1
# endif
#  undef  __STL_USE_OWN_NAMESPACE 
# endif

# if defined(__hpux) && !defined(__GNUC__)
#  define __STL_USING_BASE_MEMBER 
// HP aCC with +noeh
#  ifdef __HPACC_NOEH
#   define __STL_NO_EXCEPTIONS 1
#  endif
# endif

# if defined (__GNUC__)

// strict ANSI prohibits "long long" ( gcc)
#  if defined ( __STRICT_ANSI__ )
#    undef __STL_LONG_LONG
#  endif

#if (__GNUC_MINOR__ < 8)
# define __STL_NATIVE_INCLUDE_PATH ../g++-include
#else
# define __STL_NATIVE_INCLUDE_PATH ../g++
#endif

# endif /* __GNUC */

// common switches for EDG front-end
# if defined (__EDG_SWITCHES)
#   if defined(_TYPENAME) || defined (_TYPENAME_IS_KEYWORD)
#     undef  __STL_TYPENAME
#     define __STL_TYPENAME 1
#   endif
#   if defined(_WCHAR_T_IS_KEYWORD)
#     undef __STL_WCHAR_T 
#     define __STL_WCHAR_T 1
#   endif
#   ifdef _PARTIAL_SPECIALIZATION_OF_CLASS_TEMPLATES
#     undef __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_CLASS_PARTIAL_SPECIALIZATION 1
#   endif
#   ifdef _MEMBER_TEMPLATES
#     undef __STL_MEMBER_TEMPLATES
#     define __STL_MEMBER_TEMPLATES 1
#     undef __STL_MEMBER_TEMPLATE_CLASSES
#     define __STL_MEMBER_TEMPLATE_CLASSES 1
#   endif
#   if defined(_MEMBER_TEMPLATE_KEYWORD)
#     undef  __STL_MEMBER_TEMPLATE_KEYWORD
#     define __STL_MEMBER_TEMPLATE_KEYWORD 1
#   endif
#   ifdef __EXCEPTIONS
#     undef  __STL_USE_EXCEPTIONS
#     define __STL_USE_EXCEPTIONS
#   endif
#   undef __EDG_SWITCHES
# endif /* EDG */
#endif