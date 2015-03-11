/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/typefixer/pointer_type.hpp
 *
 * Purpose:     Definition of the fixer_pointer_type and fixer_const_pointer_type types.
 *
 * Created:     17th October 2004
 * Updated:     21st March 2006
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


/// \file stlsoft/typefixer/pointer_type.hpp
///
/// Definition of the fixer_pointer_type and fixer_const_pointer_type types.

#ifndef STLSOFT_INCL_H_STLSOFT_TYPEFIXER_POINTERTYPE
#define STLSOFT_INCL_H_STLSOFT_TYPEFIXER_POINTERTYPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_TYPEFIXER_POINTERTYPE_MAJOR     1
# define STLSOFT_VER_H_STLSOFT_TYPEFIXER_POINTERTYPE_MINOR     3
# define STLSOFT_VER_H_STLSOFT_TYPEFIXER_POINTERTYPE_REVISION  1
# define STLSOFT_VER_H_STLSOFT_TYPEFIXER_POINTERTYPE_EDIT      11
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER < 1310
[Incompatibilies-end]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifndef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
# error stlsoft/typefixer/pointer_type.hpp is only compatible with compilers that support partial template specialisation
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

namespace typefixer
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Type-fixer for \c pointer_type member type
///
/// If type \c T has a \c pointer_type member type, then the type of
/// <code>fixer_pointer_type<T>::pointer_type</code> is
/// <code>T::pointer_type</code>, otherwise it is \c void

template <ss_typename_param_k T, ss_bool_t>
struct fixer_pointer_type
{
    typedef ss_typename_type_k T::pointer_type          pointer_type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// When not present it uses void as a placeholder
template <ss_typename_param_k T>
struct fixer_pointer_type<T, false>
{
    typedef void                                        pointer_type;
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// \brief Type-fixer for \c const_pointer_type member type
///
/// If type \c T has a \c const_pointer_type member type, then the type of
/// <code>fixer_const_pointer_type<T>::const_pointer_type</code> is
/// <code>T::const_pointer_type</code>, otherwise it is \c void

template <ss_typename_param_k T, ss_bool_t>
struct fixer_const_pointer_type
{
    typedef ss_typename_type_k T::const_pointer_type    const_pointer_type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// When not present it uses void as a placeholder
template <ss_typename_param_k T>
struct fixer_const_pointer_type<T, false>
{
    typedef void                                        const_pointer_type;
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace typefixer

} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_TYPEFIXER_POINTERTYPE */

/* ////////////////////////////////////////////////////////////////////////// */
