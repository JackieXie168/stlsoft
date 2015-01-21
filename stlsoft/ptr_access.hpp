/* /////////////////////////////////////////////////////////////////////////////
 * File:        ptr_access.hpp (formerly stlsoft_ptr_access.h)
 *
 * Purpose:     Contains the get_ptr access shim.
 *
 * Created:     10th January 2002
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/ptr_access.hpp
///
/// Contains the get_ptr access shim.

#ifndef STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_PTR_ACCESS_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_PTR_ACCESS_MINOR     1
# define STLSOFT_VER_STLSOFT_HPP_PTR_ACCESS_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_PTR_ACCESS_EDIT      33
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#if defined(STLSOFT_COMPILER_IS_WATCOM)
# define _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
#endif /* compiler */

#ifndef _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
# include <memory>                  // for std::auto_ptr
#endif /* _STLSOFT_PTR_ACCESS_NO_AUTO_PTR */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_pointer_access Pointer Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" retrieve the pointer for arbitrary pointer types

/// \defgroup stlsoft_pointer_access_shims Pointer Access Shims (STLSoft)
/// \ingroup STLSoft concepts_shims_pointer_access
/// \brief These \ref concepts_shims "shims" retrieve the pointer for arbitrary pointer types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * get_ptr functions
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER != 1200
/* pointer to const. */
template <ss_typename_param_k T>
inline T const *get_ptr(T const *p)
{
    return p;
}

/* pointer to const volatile. */
template <ss_typename_param_k T>
inline T const volatile *get_ptr(T const volatile *p)
{
    return p;
}

/* pointer to volatile. */
template <ss_typename_param_k T>
inline T volatile *get_ptr(T volatile *p)
{
    return p;
}
#endif /* VC++ 6.0  */

/* pointer to non-const. */
template <ss_typename_param_k T>
inline T *get_ptr(T *p)
{
    return p;
}

#ifndef _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
/* std::auto_ptr */
template <ss_typename_param_k T>
inline T *get_ptr(stlsoft_ns_qual_std(auto_ptr)<T> &p)
{
    return p.get();
}

template <ss_typename_param_k T>
inline T const *get_ptr(stlsoft_ns_qual_std(auto_ptr)<T> const &p)
{
    return p.get();
}
#endif /* _STLSOFT_PTR_ACCESS_NO_AUTO_PTR */

/* pointer to non-const. */
template <ss_typename_param_k T>
inline ss_bool_t is_empty(T *p)
{
    return NULL == get_ptr(p);
}

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER != 1200
/* pointer to non-const. */
template <ss_typename_param_k T>
inline ss_bool_t is_empty(T const *p)
{
    return NULL == get_ptr(p);
}

/* pointer to non-const. */
template <ss_typename_param_k T>
inline ss_bool_t is_empty(T volatile *p)
{
    return NULL == get_ptr(p);
}

/* pointer to non-const. */
template <ss_typename_param_k T>
inline ss_bool_t is_empty(T const volatile *p)
{
    return NULL == get_ptr(p);
}
#endif /* VC++ 6.0  */

#ifndef _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
/* std::auto_ptr */
template <ss_typename_param_k T>
inline ss_bool_t is_empty(stlsoft_ns_qual_std(auto_ptr)<T> &p)
{
    return is_empty(get_ptr(p));
}

template <ss_typename_param_k T>
inline ss_bool_t is_empty(stlsoft_ns_qual_std(auto_ptr)<T> const &p)
{
    return is_empty(get_ptr(p));
}
#endif /* _STLSOFT_PTR_ACCESS_NO_AUTO_PTR */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/ptr_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_pointer_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
