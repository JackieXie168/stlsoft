/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/time_string_access.hpp
 *
 * Purpose:     String shims for standard time structures.
 *
 * Created:     25th July 2005
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/time_string_access.hpp
///
/// String shims for standard time structures.

#ifndef STLSOFT_INCL_STLSOFT_HPP_TIME_STRING_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_TIME_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_TIME_STRING_ACCESS_MAJOR       1
# define STLSOFT_VER_STLSOFT_HPP_TIME_STRING_ACCESS_MINOR       1
# define STLSOFT_VER_STLSOFT_HPP_TIME_STRING_ACCESS_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_TIME_STRING_ACCESS_EDIT        3
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
#ifndef STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING
# include <stlsoft/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING */
#include <time.h>

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

/// \defgroup stlsoft_string_access_shims String Access Shims (WinSTL)
/// \ingroup WinSTL concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for Win32 time types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 *
 * All the struct tm-related conversions assume a format of 20 characters
 */

inline basic_shim_string<ss_char_a_t> c_str_ptr_a(struct tm const *t)
{
    basic_shim_string<ss_char_a_t>  s(100);
    const ss_size_t                 cch =   ::strftime(s.data(), s.size(), "%b %d %H:%M:%S %Y", t);

    STLSOFT_ASSERT(20 == cch);

    s.truncate(cch);

    return s;
}

inline basic_shim_string<ss_char_a_t> c_str_ptr(struct tm const *t)
{
    return c_str_ptr_a(t);
}

inline basic_shim_string<ss_char_a_t> c_str_data(struct tm const *t)
{
    return c_str_ptr_a(t);
}

inline ss_size_t c_str_len(struct tm const *t)
{
    return static_cast<ss_size_t>((NULL != t) ? 20 : 0);
}



inline basic_shim_string<ss_char_a_t> c_str_ptr_a(struct tm const &t)
{
    return c_str_ptr_a(&t);
}

inline basic_shim_string<ss_char_a_t> c_str_ptr(struct tm const &t)
{
    return c_str_ptr(&t);
}

inline basic_shim_string<ss_char_a_t> c_str_data(struct tm const &t)
{
    return c_str_data(&t);
}

inline ss_size_t c_str_len(struct tm const &/* t */)
{
    return 20;
}


/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_string_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_TIME_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
