/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/sap_cast.hpp (formerly stlsoft_sap_cast.h)
 *
 * Purpose:     A cast operator function that casts between non void pointers of
 *              the same cv-qualification.
 *
 * Created:     25th February 2004
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/sap_cast.hpp
///
/// A cast operator function that casts between non void pointers of the same cv-qualification.

#ifndef STLSOFT_INCL_STLSOFT_HPP_SAP_CAST
#define STLSOFT_INCL_STLSOFT_HPP_SAP_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_SAP_CAST_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_SAP_CAST_MINOR     1
# define STLSOFT_VER_STLSOFT_HPP_SAP_CAST_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_SAP_CAST_EDIT      27
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
# ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
#  include <stlsoft/constraints.hpp>   // for stlsoft_constraint_must_be_pod
# endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
# ifndef STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS
#  include <stlsoft/type_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_TYPE_TRAITS */
#endif /* ? compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#if defined(STLSOFT_COMPILER_IS_WATCOM) || \
    (   defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3)
# define    sap_cast    reinterpret_cast
#else /* ? compiler */
template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        >
inline TO sap_cast(FROM from)
{
# if defined(__STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_BORLAND) /* || \
        __BORLANDC__ >= 0x0564 */)
    // Both types must be pointer types
    STLSOFT_STATIC_ASSERT(0 != base_type_traits<FROM>::is_pointer);
    STLSOFT_STATIC_ASSERT(0 != base_type_traits<TO>::is_pointer);

    typedef ss_typename_type_k base_type_traits<FROM>::base_type    from_base_type;
    typedef ss_typename_type_k base_type_traits<TO>::base_type      to_base_type;

    // The intermediate type might be void *, void const *, void volatile * or
    // void const volatile *
    typedef ss_typename_type_k select_first_type_if<void const *
                                                ,   void *
                                                ,   base_type_traits<FROM>::is_const
                                                >::type     non_volatile_type;
    typedef ss_typename_type_k select_first_type_if<void const volatile *
                                                ,   void volatile *
                                                ,   base_type_traits<FROM>::is_const
                                                >::type     volatile_type;
    typedef ss_typename_type_k select_first_type_if<volatile_type
                                                ,   non_volatile_type
                                                ,   base_type_traits<FROM>::is_volatile
                                                >::type     pointer_type;

    // "static_cast" to void (const) (volatile) *
    pointer_type        pv  =   from;
# else /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    void const volatile *p1 =   from;
    void                *pv =   const_cast<void*>(p1);
# endif /* __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    // static_cast to destination type
    return static_cast<TO>(pv);
}
#endif /* compiler */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/sap_cast_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_SAP_CAST */

/* ////////////////////////////////////////////////////////////////////////// */
