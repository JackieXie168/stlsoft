/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/method_adaptors.hpp (formerly stlsoft/function_adaptors.hpp, comstl_functionals.h; originally ::SynesisStd)
 *
 * Purpose:     Contains the stlsoft::mem_fun calling convention-aware function adaptors.
 *
 * Created:     13th June 1999
 * Updated:     2nd January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/method_adaptors.hpp
///
/// Contains the stlsoft::mem_fun and stlsoft::ptr_fun calling convention-aware function adaptors.

#ifndef STLSOFT_INCL_STLSOFT_HPP_METHOD_ADAPTORS
#define STLSOFT_INCL_STLSOFT_HPP_METHOD_ADAPTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_METHOD_ADAPTORS_MAJOR      3
# define STLSOFT_VER_STLSOFT_HPP_METHOD_ADAPTORS_MINOR      1
# define STLSOFT_VER_STLSOFT_HPP_METHOD_ADAPTORS_REVISION   1
# define STLSOFT_VER_STLSOFT_HPP_METHOD_ADAPTORS_EDIT       53
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#include <functional>

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

#if !defined(STLSOFT_COMPILER_IS_GCC) || \
    (   __GNUC__ > 3 || \
        (   __GNUC__ == 3 && \
            __GNUC_MINOR__ >= 4))

// [[synesis:class:function-class:unary-function: cdecl_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct cdecl_mem_fun_t
    : public stlsoft_ns_qual_std(unary_function)<T*, R>
{
public:
    typedef R                           return_type;
    typedef T                           operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef return_type STLSOFT_CDECL  (T::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef return_type (STLSOFT_CDECL  T::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k cdecl_mem_fun_t(method_type func)
        : m_func(func)
    {}
    return_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

// [[synesis:class:function-class:unary-function: fastcall_mem_fun_t<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct fastcall_mem_fun_t
    : public stlsoft_ns_qual_std(unary_function)<T*, R>
{
public:
    typedef R                               return_type;
    typedef T                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef return_type STLSOFT_FASTCALL   (T::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef return_type (STLSOFT_FASTCALL   T::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k fastcall_mem_fun_t(method_type func)
        : m_func(func)
    {}
    return_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
#ifdef STLSOFT_CF_STDCALL_SUPPORTED

// [[synesis:class:function-class:unary-function: stdcall_mem_fun_t<T<T>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
struct stdcall_mem_fun_t
    : public stlsoft_ns_qual_std(unary_function)<T*, R>
{
public:
    typedef R                               return_type;
    typedef T                               operand_class_type;
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
    typedef return_type STLSOFT_STDCALL    (T::*method_type)();
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
    typedef return_type (STLSOFT_STDCALL    T::*method_type)();
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
public:
    ss_explicit_k stdcall_mem_fun_t(method_type func)
        : m_func(func)
    {}
    return_type operator ()(operand_class_type *pt) const
    {
        return (pt->*m_func)();
    }
private:
    method_type m_func;
};

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
inline cdecl_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_CDECL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
inline cdecl_mem_fun_t<R, T> mem_fun(R (STLSOFT_CDECL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return cdecl_mem_fun_t<R, T>(func);
}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
inline fastcall_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_FASTCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
inline fastcall_mem_fun_t<R, T> mem_fun(R (STLSOFT_FASTCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return fastcall_mem_fun_t<R, T>(func);
}

#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
#ifdef STLSOFT_CF_STDCALL_SUPPORTED

template< ss_typename_param_k R
        , ss_typename_param_k T
        >
#ifdef STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED
inline stdcall_mem_fun_t<R, T> mem_fun(R (T::*STLSOFT_STDCALL func)())
#else /* ? STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
inline stdcall_mem_fun_t<R, T> mem_fun(R (STLSOFT_STDCALL T::*func)())
#endif /* STLSOFT_CF_CALLING_CONVENTION_OUTSIDE_BRACE_REQUIRED */
{
    return stdcall_mem_fun_t<R, T>(func);
}

#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_METHOD_ADAPTORS */

/* ////////////////////////////////////////////////////////////////////////// */
