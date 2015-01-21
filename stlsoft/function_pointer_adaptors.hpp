/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/function_pointer_adaptors.hpp (formerly stlsoft/function_adaptors.hpp, comstl_functionals.h; originally ::SynesisStd)
 *
 * Purpose:     Contains the stlsoft::ptr_fun calling convention-aware function adaptors.
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


/// \file stlsoft/function_pointer_adaptors.hpp
///
/// Contains the stlsoft::mem_fun and stlsoft::ptr_fun calling convention-aware function adaptors.

#ifndef STLSOFT_INCL_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS
#define STLSOFT_INCL_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS_MAJOR    3
# define STLSOFT_VER_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS_MINOR    1
# define STLSOFT_VER_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS_EDIT     54
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

/// A unary function adaptor for pointers to functions with CDecl (__cdecl) calling convention
// [[synesis:class:function-class:unary-function: unary_cdecl_function_pointer<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
struct unary_cdecl_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, R>
{
public:
    typedef R                           return_type;
    typedef A                           argument_type;
    typedef return_type (STLSOFT_CDECL  *function_type)(argument_type);
public:
    ss_explicit_k unary_cdecl_function_pointer(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type arg) const
    {
        return (*m_func)(arg);
    }
private:
    function_type m_func;
};

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
/// A unary function adaptor for pointers to functions with FastCall (__fastcall) calling convention
// [[synesis:class:function-class:unary-function: unary_fastcall_function_pointer<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
struct unary_fastcall_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, R>
{
public:
    typedef R                               return_type;
    typedef A                               argument_type;
    typedef return_type (STLSOFT_FASTCALL   *function_type)(argument_type);
public:
    ss_explicit_k unary_fastcall_function_pointer(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type arg) const
    {
        return (*m_func)(arg);
    }
private:
    function_type m_func;
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
/// A unary function adaptor for pointers to functions with StdCall (__stdcall) calling convention
// [[synesis:class:function-class:unary-function: unary_stdcall_function_pointer<T<R>, T<A>>]]
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
struct unary_stdcall_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, R>
{
public:
    typedef R                               return_type;
    typedef A                               argument_type;
    typedef return_type (STLSOFT_STDCALL    *function_type)(argument_type);
public:
    ss_explicit_k unary_stdcall_function_pointer(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type arg) const
    {
        return (*m_func)(arg);
    }
private:
    function_type m_func;
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#if !defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)
/// A unary function adaptor for pointers to functions with CDecl (__cdecl) calling convention that
/// have a void return type
// [[synesis:class:function-class:unary-function: unary_cdecl_void_function_pointer<T<R>, T<A>>]]
template <ss_typename_param_k A>
struct unary_cdecl_void_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, void>
{
public:
    typedef void                        return_type;
    typedef A                           argument_type;
    typedef return_type (STLSOFT_CDECL  *function_type)(argument_type);
public:
    ss_explicit_k unary_cdecl_void_function_pointer(function_type func)
        : m_func(func)
    {}
    void operator ()(argument_type arg) const
    {
        (*m_func)(arg);
    }
private:
    function_type m_func;
};

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
/// A unary function adaptor for pointers to functions with FastCall (__fastcall) calling convention that
/// have a void return type
// [[synesis:class:function-class:unary-function: unary_fastcall_void_function_pointer<T<R>, T<A>>]]
template <ss_typename_param_k A>
struct unary_fastcall_void_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, void>
{
public:
    typedef void                            return_type;
    typedef A                               argument_type;
    typedef return_type (STLSOFT_FASTCALL   *function_type)(argument_type);
public:
    ss_explicit_k unary_fastcall_void_function_pointer(function_type func)
        : m_func(func)
    {}
    void operator ()(argument_type arg) const
    {
        (*m_func)(arg);
    }
private:
    function_type m_func;
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
/// A unary function adaptor for pointers to functions with StdCall (__stdcall) calling convention that
/// have a void return type
// [[synesis:class:function-class:unary-function: unary_stdcall_void_function_pointer<T<R>, T<A>>]]
template <ss_typename_param_k A>
struct unary_stdcall_void_function_pointer
    : public stlsoft_ns_qual_std(unary_function)<A, void>
{
public:
    typedef void                            return_type;
    typedef A                               argument_type;
    typedef return_type (STLSOFT_STDCALL    *function_type)(argument_type);
public:
    ss_explicit_k unary_stdcall_void_function_pointer(function_type func)
        : m_func(func)
    {}
    void operator ()(argument_type arg) const
    {
        (*m_func)(arg);
    }
private:
    function_type m_func;
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

/* /////////////////////////////////////////////////////////////////////////////
 * Creator functions
 */

/// Creator function to adapt pointers to functions with CDecl (__cdecl) calling convention
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
unary_cdecl_function_pointer<R, A> ptr_fun(R (STLSOFT_CDECL *func)(A))
{
    return unary_cdecl_function_pointer<R, A>(func);
}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
/// Creator function to adapt pointers to functions with FastCall (__fastcall) calling convention
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
unary_fastcall_function_pointer<R, A> ptr_fun(R (STLSOFT_FASTCALL *func)(A))
{
    return unary_fastcall_function_pointer<R, A>(func);
}
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
/// Creator function to adapt pointers to functions with StdCall (__stdcall) calling convention
template< ss_typename_param_k R
        , ss_typename_param_k A
        >
unary_stdcall_function_pointer<R, A> ptr_fun(R (STLSOFT_STDCALL *func)(A))
{
    return unary_stdcall_function_pointer<R, A>(func);
}
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */


#if !defined(STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID)
/// Creator function to adapt pointers to functions with CDecl (__cdecl) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_cdecl_void_function_pointer<A> ptr_fun_void(void (STLSOFT_CDECL *func)(A))
{
    return unary_cdecl_void_function_pointer<A>(func);
}
/// Creator function to adapt pointers to functions with CDecl (__cdecl) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_cdecl_void_function_pointer<A> ptr_fun(void (STLSOFT_CDECL *func)(A))
{
    return ptr_fun_void(func);
}

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
/// Creator function to adapt pointers to functions with FastCall (__fastcall) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_fastcall_void_function_pointer<A> ptr_fun_void(void (STLSOFT_FASTCALL *func)(A))
{
    return unary_fastcall_void_function_pointer<A>(func);
}
/// Creator function to adapt pointers to functions with FastCall (__fastcall) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_fastcall_void_function_pointer<A> ptr_fun(void (STLSOFT_FASTCALL *func)(A))
{
    return ptr_fun_void(func);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
/// Creator function to adapt pointers to functions with StdCall (__stdcall) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_stdcall_void_function_pointer<A> ptr_fun_void(void (STLSOFT_STDCALL *func)(A))
{
    return unary_stdcall_void_function_pointer<A>(func);
}
/// Creator function to adapt pointers to functions with StdCall (__stdcall) calling convention that
/// have a void return type
template <ss_typename_param_k A>
unary_stdcall_void_function_pointer<A> ptr_fun(void (STLSOFT_STDCALL *func)(A))
{
    return ptr_fun_void(func);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_FUNCTION_POINTER_ADAPTORS */

/* ////////////////////////////////////////////////////////////////////////// */
