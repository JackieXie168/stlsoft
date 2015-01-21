/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/type_traits.hpp (formerly stlsoft_type_traits.h)
 *
 * Purpose:     type traits classes.
 *
 * Created:     24th August 2003
 * Updated:     20th December 2005
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


/// \file stlsoft/type_traits.hpp
///
/// type traits classes.

#ifndef STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS
#define STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_TYPE_TRAITS_MAJOR      3
# define STLSOFT_VER_STLSOFT_HPP_TYPE_TRAITS_MINOR      1
# define STLSOFT_VER_STLSOFT_HPP_TYPE_TRAITS_REVISION   2
# define STLSOFT_VER_STLSOFT_HPP_TYPE_TRAITS_EDIT       23
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

# if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
template <typename T>
struct base_type_traits_array_detector
{
    enum { value            =   0 };
};

template<   typename    T
        ,   ss_size_t   N
        >
struct base_type_traits_array_detector<T[N]>
{
    enum { value            =   1 };
};
# endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

template <typename T>
struct base_type_traits_pointer_detector
{
    enum { value            =   0 };
};

template <typename T>
struct base_type_traits_pointer_detector<T*>
{
    enum { value            =   1 };
};
template <typename T>
struct base_type_traits_pointer_detector<T const*>
{
    enum { value            =   1 };
};
template <typename T>
struct base_type_traits_pointer_detector<T volatile*>
{
    enum { value            =   1 };
};
template <typename T>
struct base_type_traits_pointer_detector<T const volatile*>
{
    enum { value            =   1 };
};



/// \brief Deduces the base type
template <typename T>
struct base_type_traits
{
    enum { is_pointer           =   base_type_traits_pointer_detector<T>::value };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// instance

# if !defined(STLSOFT_COMPILER_IS_BORLAND) || \
     __BORLANDC__ >= 0x0564

template <typename T>
struct base_type_traits<const T>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T>
struct base_type_traits<volatile T>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T>
struct base_type_traits<const volatile T>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

# endif /* compiler */

// pointers

template <typename T>
struct base_type_traits<T*>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T>
struct base_type_traits<T const*>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T       base_type;
    typedef T const cv_type;
};

template <typename T>
struct base_type_traits<T volatile*>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T           base_type;
    typedef T volatile  cv_type;
};

template <typename T>
struct base_type_traits<T const volatile*>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T                   base_type;
    typedef T const volatile    cv_type;
};

// arrays

#  if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)

#if 0
template <typename T, ss_size_t N>
struct base_type_traits<T[N]>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   0 };
    enum { is_array             =   1 };
    enum { is_array_or_pointer  =   1 };

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T, ss_size_t N>
struct base_type_traits<T const[N]>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   0 };
    enum { is_array             =   1 };
    enum { is_array_or_pointer  =   1 };

    typedef T       base_type;
    typedef T const cv_type;
};

template <typename T, ss_size_t N>
struct base_type_traits<T volatile[N]>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   0 };
    enum { is_volatile          =   1 };
    enum { is_array             =   1 };
    enum { is_array_or_pointer  =   1 };

    typedef T           base_type;
    typedef T volatile  cv_type;
};

template <typename T, ss_size_t N>
struct base_type_traits<T const volatile[N]>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   0 };
    enum { is_const             =   1 };
    enum { is_volatile          =   1 };
    enum { is_array             =   1 };
    enum { is_array_or_pointer  =   1 };

    typedef T                   base_type;
    typedef T const volatile    cv_type;
};
#endif /* 0 */

#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

// references

template <typename T>
struct base_type_traits<T&>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   1 };
    enum { is_const             =   0 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T>
struct base_type_traits<T const&>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   1 };
    enum { is_const             =   1 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T       base_type;
    typedef T const cv_type;
};

template <typename T>
struct base_type_traits<T volatile&>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   1 };
    enum { is_const             =   0 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T           base_type;
    typedef T volatile  cv_type;
};

template <typename T>
struct base_type_traits<T const volatile&>
{
    enum { is_pointer           =   0 };
    enum { is_reference         =   1 };
    enum { is_const             =   1 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   0 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   base_type_traits_array_detector<T>::value   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T                   base_type;
    typedef T const volatile    cv_type;
};

// references to pointers

template <typename T>
struct base_type_traits<T*&>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   1 };
    enum { is_const             =   0 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T   base_type;
    typedef T   cv_type;
};

template <typename T>
struct base_type_traits<T const*&>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   1 };
    enum { is_const             =   1 };
    enum { is_volatile          =   0 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T       base_type;
    typedef T const cv_type;
};

template <typename T>
struct base_type_traits<T volatile*&>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   1 };
    enum { is_const             =   0 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T           base_type;
    typedef T volatile  cv_type;
};

template <typename T>
struct base_type_traits<T const volatile*&>
{
    enum { is_pointer           =   1 };
    enum { is_reference         =   1 };
    enum { is_const             =   1 };
    enum { is_volatile          =   1 };
    enum { is_array_or_pointer  =   1 };
#if defined(__STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
    enum { is_array             =   0   };
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

    typedef T                   base_type;
    typedef T const volatile    cv_type;
};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/type_traits_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */
