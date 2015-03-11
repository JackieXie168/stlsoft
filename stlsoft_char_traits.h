/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_char_traits.h (originally MTCTrait.h, ::SynesisStl)
 *
 * Purpose:     char_traits classes.
 *
 * Created:     19th November 1998
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft_char_traits.h
///
/// char_traits classes.

#ifndef STLSOFT_INCL_H_STLSOFT_CHAR_TRAITS
#define STLSOFT_INCL_H_STLSOFT_CHAR_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_CHAR_TRAITS_MAJOR        3
# define STLSOFT_VER_H_STLSOFT_CHAR_TRAITS_MINOR        1
# define STLSOFT_VER_H_STLSOFT_CHAR_TRAITS_REVISION     1
# define STLSOFT_VER_H_STLSOFT_CHAR_TRAITS_EDIT         53
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 *
 * There is a degree of complexity with respect to the definition and use of
 * char_traits in the STLSoft libraries, depending on whether the std and/or
 * stlsoft namespaces are defined.
 *
 * 1. If neither std nor stlsoft namespaces are defined, then the standard
 * library char_traits is visible in the global namespace, and no definition is
 * provided in the stlsoft namespace. This is necessary to avoid a clash.
 *
 * 2. If std is defined, and the stlsoft namespace is not defined, then the
 * STLSoft definition of char_traits is provided, and exists in the global
 * namespace.
 *
 * 3. If std is not defined, and the stlsoft namespace is defined, then the
 * STLSoft definition of char_traits is provided, and exists in the stlsoft
 * namespace.
 *
 * 4. If both std and stlsoft namespaces are not defined, then the
 * STLSoft definition of char_traits is provided, and exists in the stlsoft
 * namespace.
 *
 * Also influencing this is whether the compiler/std-library actually provide
 * a char_traits type. GCC 2.95 does not. Presence of this is indicated by the
 * definition of __STLSOFT_CF_std_char_traits_AVAILABLE
 *
 * Finally, DMC++ has a problem whereby, with the SGI libs, the specialisation
 * of char_traits in the global namespace clashes with stlsoft::char_traits<>.
 * This is a combination compiler/library bug, so the only thing we can do is
 * indicate to the STLSoft libs that ("std::")char_traits is unavailable, and
 * "use" the standard library one.
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef _STLSOFT_COMPILE_VERBOSE
# pragma message("This file is now obsolete. Instead include stlsoft/char_traits.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT && _STLSOFT_COMPILE_VERBOSE */

#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_CHAR_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */
