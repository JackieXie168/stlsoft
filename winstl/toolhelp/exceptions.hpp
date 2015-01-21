/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/toolhelp/exceptions.hpp
 *
 * Purpose:     Exception classes for TOOLHELP components.
 *
 * Created:     21st May 2005
 * Updated:     10th June 2006
 *
 * Thanks:      To Pablo for contributing this great library.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Pablo Aguilar
 * Copyright (c) 2006, Matthew Wilson
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software, nor Pablo
 *   Aguilar, nor the names of any contributors may be used to endorse or
 *   promote products derived from this software without specific prior written
 *   permission.
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


/** \file winstl/toolhelp/exceptions.hpp
 *
 * \brief [C++ only] Exception classes for the
 *  (\ref group__library__windows_toolhelp "Windows ToolHelp" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION
#define WINSTL_INCL_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION_MAJOR    1
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION_MINOR    1
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION_REVISION 1
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION_EDIT     5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */
#ifndef WINSTL_INCL_WINSTL_HPP_WINSTL_EXCEPTIONS
# include <winstl/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_WINSTL_EXCEPTIONS */

#include <tlhelp32.h>

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Root exception thrown by the \ref group__library__windows_toolhelp "ToolHelp" Library.
///
/// \ingroup group__library__windows_toolhelp
struct toolhelp_exception
    : public windows_exception
{
/// \name Member Types
/// @{
public:
    typedef windows_exception                   parent_class_type;
    typedef toolhelp_exception                  class_type;
    typedef parent_class_type::error_code_type  error_code_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs an instance from the given error code
    ///
    /// \param err The error code that is passed to the parent class (winstl::windows_exception) constructor
    ss_explicit_k toolhelp_exception(error_code_type err)
        : parent_class_type(err)
    {}
    /// \brief Constructs an instance from the given message and error code
    ///
    /// \param reason The reason that is passed to the parent class (winstl::windows_exception) constructor
    /// \param err The error code that is passed to the parent class (winstl::windows_exception) constructor
    toolhelp_exception(char const *reason, error_code_type err)
        : parent_class_type(reason, err)
    {}
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif // WINSTL_INCL_WINSTL_TOOLHELP_HPP_SEQUENCE_EXCEPTION

/* ////////////////////////////////////////////////////////////////////// */
