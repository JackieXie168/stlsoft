/* ////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/unrecoverable.hpp
 *
 * Purpose:     Definition of the \c unrecoverable exception class.
 *
 * Created:     14th October 2004
 * Updated:     12th February 2006
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


/// \file stlsoft/unrecoverable.hpp
///
/// Definition of the \c unrecoverable exception class. Exceptions deriving from
/// this class may be caught, but they result in process termination at the end
/// of the catch clause, or if they're not caught.

#ifndef STLSOFT_INCL_STLSOFT_HPP_UNRECOVERABLE
#define STLSOFT_INCL_STLSOFT_HPP_UNRECOVERABLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_UNRECOVERABLE_MAJOR    2
# define STLSOFT_VER_STLSOFT_HPP_UNRECOVERABLE_MINOR    0
# define STLSOFT_VER_STLSOFT_HPP_UNRECOVERABLE_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_UNRECOVERABLE_EDIT     20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete. Instead include stlsoft/exceptions/unrecoverable.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_UNRECOVERABLE
# include <stlsoft/exceptions/unrecoverable.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_UNRECOVERABLE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_UNRECOVERABLE */

/* ////////////////////////////////////////////////////////////////////////// */
