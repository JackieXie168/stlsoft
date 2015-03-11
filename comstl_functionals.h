/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl_functionals.h
 *
 * Purpose:     Contains COM specific predicates and functionals.
 *
 * Created:     14th June 2002
 * Updated:     25th May 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/// \file comstl_functionals.h
///
/// Contains COM specific predicates and functionals.

#ifndef COMSTL_INCL_H_COMSTL_FUNCTIONALS
#define COMSTL_INCL_H_COMSTL_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_H_COMSTL_FUNCTIONALS_MAJOR      3
# define COMSTL_VER_H_COMSTL_FUNCTIONALS_MINOR      2
# define COMSTL_VER_H_COMSTL_FUNCTIONALS_REVISION   1
# define COMSTL_VER_H_COMSTL_FUNCTIONALS_EDIT       55
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_DMC:
STLSOFT_COMPILER_IS_GCC:     __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 4)
[Incompatibilies-end]
 */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */


#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete, and will be removed in a future release. Instead include comstl/interface_functionals.hpp and/or comstl/type_functionals.hpp and/or stlsoft/method_adaptors.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_HPP_FUNCTION_ADAPTORS
# include <stlsoft/method_adaptors.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_FUNCTION_ADAPTORS */
#ifndef COMSTL_INCL_COMSTL_HPP_INTERFACE_FUNCTIONALS
# include <comstl/interface_functionals.hpp>
#endif /* !COMSTL_INCL_COMSTL_HPP_INTERFACE_FUNCTIONALS */
#ifndef COMSTL_INCL_COMSTL_HPP_TYPE_FUNCTIONALS
# include <comstl/type_functionals.hpp>
#endif /* !COMSTL_INCL_COMSTL_HPP_TYPE_FUNCTIONALS */

#include <functional>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Functionals
 */

/// \brief Helper function for std_mem_fun_t
///
/// \deprecated Users should now use stlsoft::mem_fun()
template <class R, class T>
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    (   __GNUC__ < 3 || \
        (   __GNUC__ == 3 && \
            __GNUC_MINOR__ < 4))
inline stlsoft_ns_qual(stdcall_mem_fun_t)<R, T> std_mem_fun(R STDAPICALLTYPE (T::*f)())
#else /* ? compiler */
inline stlsoft_ns_qual(stdcall_mem_fun_t)<R, T> std_mem_fun(R (STDAPICALLTYPE T::*f)())
#endif /* compiler */
{
    return stlsoft_ns_qual(mem_fun)(f);
}



/// \brief An adaptor for member functions of COM interfaces
///
/// This function object calls a COM STDAPI (__stdcall) function on an object.
///
/// \param T The object class on which the function will be applied
/// \param R The return type of the function to be applied
// [[synesis:class:unary-functor: std_mem_fun_ref_t]]
template< ss_typename_param_k R
        , ss_typename_param_k T
        >
class std_mem_fun_ref_t
    : public comstl_ns_qual_std(unary_function)<T&, R>
{
public:
    typedef R                               return_type;
    typedef T                               operand_class_type;
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    (   __GNUC__ < 3 || \
        (   __GNUC__ == 3 && \
            __GNUC_MINOR__ < 4))
    typedef return_type STDAPICALLTYPE (T::*method_type)();
#else /* ? compiler */
    typedef return_type (STDAPICALLTYPE T::*method_type)();
#endif /* compiler */

public:
    /// \brief Constructor
    ///
    /// \param f The function (pointer to member of T, returning R) which will be applied to the objects
    ss_explicit_k std_mem_fun_ref_t(method_type f)
        : m_f(f)
    {}

    /// \brief Function call operator
    ///
    /// \param t The object on which to apply the function
    return_type operator ()(operand_class_type &t) const
    {
        return (t.*m_f)();
    }

private:
    method_type m_f;
};

/// \brief Helper function for std_mem_fun_ref_t
template <class R, class T>
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    (   __GNUC__ < 3 || \
        (   __GNUC__ == 3 && \
            __GNUC_MINOR__ < 4))
inline std_mem_fun_ref_t<R, T> std_mem_fun_ref(R /* STDAPICALLTYPE */ (T::*f)())
#else /* ? compiler */
inline std_mem_fun_ref_t<R, T> std_mem_fun_ref(R (STDAPICALLTYPE T::*f)())
#endif /* compiler */
{
    return std_mem_fun_ref_t<R, T>(f);
}

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_H_COMSTL_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////////// */
