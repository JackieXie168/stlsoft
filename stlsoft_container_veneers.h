/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_container_veneers.h
 *
 * Purpose:     RAII veneers for sequence containers.
 *
 * Created:     19th August 2002
 * Updated:     18th December 2005
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


/// \file stlsoft_container_veneers.h
///
/// RAII veneers for sequence containers.

#ifndef STLSOFT_INCL_H_STLSOFT_CONTAINER_VENEERS
#define STLSOFT_INCL_H_STLSOFT_CONTAINER_VENEERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_CONTAINER_VENEERS_MAJOR      3
# define STLSOFT_VER_H_STLSOFT_CONTAINER_VENEERS_MINOR      2
# define STLSOFT_VER_H_STLSOFT_CONTAINER_VENEERS_REVISION   1
# define STLSOFT_VER_H_STLSOFT_CONTAINER_VENEERS_EDIT       28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_BORLAND:
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef _STLSOFT_COMPILE_VERBOSE
# pragma message("This file is now obsolete. Instead include stlsoft/container_veneers.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT && _STLSOFT_COMPILE_VERBOSE */

#ifndef STLSOFT_INCL_STLSOFT_HPP_CONTAINER_VENEERS
# include <stlsoft/container_veneers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONTAINER_VENEERS */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_CONTAINER_VENEERS */

/* ////////////////////////////////////////////////////////////////////////// */
