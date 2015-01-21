/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/access_predicates.hpp
 *
 * Purpose:     Predicates that use access shims to generalise use.
 *
 * Created:     7th November 2004
 * Updated:     5th February 2006
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


/// \file stlsoft/access_predicates.hpp
///
/// Predicates that use access shims to generalise use.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ACCESS_PREDICATES
#define STLSOFT_INCL_STLSOFT_HPP_ACCESS_PREDICATES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ACCESS_PREDICATES_MAJOR    1
# define STLSOFT_VER_STLSOFT_HPP_ACCESS_PREDICATES_MINOR    3
# define STLSOFT_VER_STLSOFT_HPP_ACCESS_PREDICATES_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_ACCESS_PREDICATES_EDIT     14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS
# include <stlsoft/ptr_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_HANDLE_ACCESS
# include <stlsoft/handle_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_HANDLE_ACCESS */

#ifdef STLSOFT_CF_std_NAMESPACE
# include <functional>
#endif /* STLSOFT_CF_std_NAMESPACE */

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

/// Predicate used to test the equivalence of pointers
///
template<   ss_typename_param_k P
        ,   ss_typename_param_k A = P const &
        >
// [[synesis:class:function-class:unary-predicate: equal_ptr]]
struct equal_ptr
#ifdef STLSOFT_CF_std_NAMESPACE
    : public stlsoft_ns_qual_std(unary_function)<A, ss_bool_t>
#endif /* STLSOFT_CF_std_NAMESPACE */
{
public:
    equal_ptr(P t)
        : m_p(t)
    {}

public:
    ss_bool_t operator ()(A p) const
    {
        return stlsoft_ns_qual(get_ptr)(p) == stlsoft_ns_qual(get_ptr)(m_p);
    }

private:
    P   m_p;
};


/// Predicate used to test the equivalence of handles
///
template<   ss_typename_param_k H
        ,   ss_typename_param_k A = H const &
        >
// [[synesis:class:function-class:unary-predicate: equal_handle]]
struct equal_handle
#ifdef STLSOFT_CF_std_NAMESPACE
    : public stlsoft_ns_qual_std(unary_function)<A, ss_bool_t>
#endif /* STLSOFT_CF_std_NAMESPACE */
{
public:
    equal_handle(H t)
        : m_h(t)
    {}

public:
    ss_bool_t operator ()(A const &h) const
    {
        return stlsoft_ns_qual(get_handle)(h) == stlsoft_ns_qual(get_handle)(m_h);
    }

private:
    H   m_h;
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ACCESS_PREDICATES */

/* ////////////////////////////////////////////////////////////////////////// */
