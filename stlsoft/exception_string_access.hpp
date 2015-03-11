/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception_string_access.hpp
 *
 * Purpose:     Contains the string access shims for std::exception.
 *
 * Created:     2nd May 2003
 * Updated:     12th May 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file stlsoft/exception_string_access.hpp
///
/// Contains the string access shims for std::exception.

#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTION_STRING_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_EXCEPTION_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _STLSOFT_VER_STLSOFT_HPP_EXCEPTION_STRING_ACCESS_MAJOR     1
# define _STLSOFT_VER_STLSOFT_HPP_EXCEPTION_STRING_ACCESS_MINOR     3
# define _STLSOFT_VER_STLSOFT_HPP_EXCEPTION_STRING_ACCESS_REVISION  2
# define _STLSOFT_VER_STLSOFT_HPP_EXCEPTION_STRING_ACCESS_EDIT      19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#include <exception>                // for std::exception

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

/// \weakgroup concepts_shims_string_access String Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types

/// \defgroup stlsoft_string_access_shims String Access Shims (STLSoft)
/// \ingroup STLSoft concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for exception types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* std::exception */

/// \brief Returns the corresponding C-string pointer of \c x, or a null pointer
inline ss_char_a_t const *c_str_ptr_null_a(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_null_a(x.what());
}

/// \brief Returns the corresponding C-string pointer of \c x, or a null pointer
inline ss_char_a_t const *c_str_ptr_null(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_null_a(x);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* std::exception */
/// \brief Returns the corresponding C-string pointer of \c x
inline ss_char_a_t const *c_str_ptr_a(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_a(x.what());
}

/// \brief Returns the corresponding C-string pointer of \c x
inline ss_char_a_t const *c_str_ptr(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_a(x);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* std::exception */
/// \brief Returns the corresponding C-string pointer of \c x
inline ss_char_a_t const *c_str_data_a(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_a(x);
}

/* std::exception */
/// \brief Returns the corresponding C-string pointer of \c x
inline ss_char_a_t const *c_str_data(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_ptr_a(x);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* std::exception */
/// \brief Returns the length (in characters) of \c x, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len_a(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_len_a(x.what());
}

/// \brief Returns the length (in characters) of \c x, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_len(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_len_a(x);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_size
 *
 * This can be applied to an expression, and the return value is the number of
 * bytes required to store the character string in the expression, NOT including
 * the null-terminating character.
 */

/* std::exception */
/// \brief Returns the size (in bytes) of the contents of \c x, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size_a(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_size_a(x.what());
}

/// \brief Returns the size (in bytes) of the contents of \c x, <b><i>not</i></b> including the null-terminating character
inline ss_size_t c_str_size(stlsoft_ns_qual_std(exception) const &x)
{
    return c_str_size_a(x);
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_string_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTION_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
