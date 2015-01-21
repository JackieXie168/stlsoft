/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl_functionals.h
 *
 * Purpose:     A number of useful functionals .
 *
 * Created:     2nd November 2003
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file unixstl_functionals.h
///
/// A number of useful functionals .

#ifndef UNIXSTL_INCL_H_UNIXSTL_FUNCTIONALS
#define UNIXSTL_INCL_H_UNIXSTL_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_H_UNIXSTL_FUNCTIONALS_MAJOR    2
# define UNIXSTL_VER_H_UNIXSTL_FUNCTIONALS_MINOR    3
# define UNIXSTL_VER_H_UNIXSTL_FUNCTIONALS_REVISION 1
# define UNIXSTL_VER_H_UNIXSTL_FUNCTIONALS_EDIT     32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete, and will be removed in a future release. Instead include unixstl/filesystem/functionals.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FUNCTIONALS
# include <unixstl/filesystem/functionals.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FUNCTIONALS */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Function object that compares two file-system paths
///
/// \param C The character type
template<   ss_typename_param_k C
        >
struct compare_path
    : public path_compare<C>
{
public:
    /// The character type
    typedef C                                                           char_type;
private:
    typedef path_compare<C>                                             parent_class_type;
public:
    /// The first argument type
    typedef ss_typename_type_k parent_class_type::first_argument_type   first_argument_type;
    /// The second argument type
    typedef ss_typename_type_k parent_class_type::second_argument_type  second_argument_type;
    /// The result type
    typedef ss_typename_type_k parent_class_type::result_type           result_type;
    /// The current parameterisation of the type
    typedef compare_path<C>                                             class_type;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_H_UNIXSTL_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////// */
