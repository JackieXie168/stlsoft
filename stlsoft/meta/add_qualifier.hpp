/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/add_qualifier.hpp
 *
 * Purpose:     Adds a const or volatile qualifier to a type.
 *
 * Created:     30th December 2005
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/meta/add_qualifier.hpp
///
/// Adds a const or volatile qualifier to a type.

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_ADD_QUALIFIER
#define STLSOFT_INCL_STLSOFT_META_HPP_ADD_QUALIFIER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_ADD_QUALIFIER_MAJOR       1
# define STLSOFT_VER_STLSOFT_META_HPP_ADD_QUALIFIER_MINOR       1
# define STLSOFT_VER_STLSOFT_META_HPP_ADD_QUALIFIER_REVISION    2
# define STLSOFT_VER_STLSOFT_META_HPP_ADD_QUALIFIER_EDIT        4
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

template <ss_typename_param_k T>
struct add_const
{
    typedef const T     type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct add_const<void>
{
    typedef void        type;
};

template <ss_typename_param_k T>
struct add_volatile
{
    typedef volatile T  type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct add_volatile<void>
{
    typedef void        type;
};


template <ss_typename_param_k T>
struct add_const_ref
{
    typedef const T     &type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct add_const_ref<void>
{
    typedef void        type;
};

template <ss_typename_param_k T>
struct add_volatile_ref
{
    typedef volatile T  &type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct add_volatile_ref<void>
{
    typedef void        type;
};


/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_ADD_QUALIFIER */

/* ////////////////////////////////////////////////////////////////////////// */
