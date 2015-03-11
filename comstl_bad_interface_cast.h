/* ////////////////////////////////////////////////////////////////////////////
 * File:        comstl_bad_interface_cast.h
 *
 * Purpose:     Exception thrown when interface casts fail.
 *
 * Created:     22nd December 2003
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/// \file comstl_bad_interface_cast.h
///
/// Exception thrown when interface casts fail.

#ifndef COMSTL_INCL_H_COMSTL_BAD_INTERFACE_CAST
#define COMSTL_INCL_H_COMSTL_BAD_INTERFACE_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_H_COMSTL_BAD_INTERFACE_CAST_MAJOR       3
# define COMSTL_VER_H_COMSTL_BAD_INTERFACE_CAST_MINOR       2
# define COMSTL_VER_H_COMSTL_BAD_INTERFACE_CAST_REVISION    1
# define COMSTL_VER_H_COMSTL_BAD_INTERFACE_CAST_EDIT        18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#include <typeinfo>

#ifdef _STLSOFT_COMPILE_VERBOSE
# pragma message("This file is now obsolete. Instead include comstl/bad_interface_cast.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT && _STLSOFT_COMPILE_VERBOSE */

#ifndef COMSTL_INCL_COMSTL_HPP_BAD_INTERFACE_CAST
# include <comstl/bad_interface_cast.hpp>
#endif /* !COMSTL_INCL_COMSTL_HPP_BAD_INTERFACE_CAST */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_H_COMSTL_BAD_INTERFACE_CAST */

/* ////////////////////////////////////////////////////////////////////////// */
