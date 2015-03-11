/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl_functionals.h
 *
 * Purpose:     A number of useful functionals .
 *
 * Created:     19th January 2002
 * Updated:     25th May 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/// \file winstl_functionals.h
///
/// A number of useful functionals .

#ifndef WINSTL_INCL_H_WINSTL_FUNCTIONALS
#define WINSTL_INCL_H_WINSTL_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_H_WINSTL_FUNCTIONALS_MAJOR      2
# define WINSTL_VER_H_WINSTL_FUNCTIONALS_MINOR      4
# define WINSTL_VER_H_WINSTL_FUNCTIONALS_REVISION   1
# define WINSTL_VER_H_WINSTL_FUNCTIONALS_EDIT       63
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
//# error winstl_functionals.h is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete, and will be removed in a future release. Instead include winstl/filesystem_functionals.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_FUNCTIONALS
# include <winstl/filesystem_functionals.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_FUNCTIONALS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Function object that compares two file-system paths
///
/// \param C The character type
template<   ss_typename_param_k C
        ,   ss_typename_param_k A1 = C const *
        ,   ss_typename_param_k A2 = C const *
        >
struct compare_path
    : public path_compare<C, A1, A2>
{
public:
    /// The character type
    typedef C                                                           char_type;
private:
    typedef path_compare<C, A1, A2>                                     parent_class_type;
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

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_H_WINSTL_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////////// */
