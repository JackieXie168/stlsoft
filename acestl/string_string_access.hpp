/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/string_string_access.hpp
 *
 * Purpose:     Helper functions for the ACE_String_XXXX classes.
 *
 * Created:     2nd December 2004
 * Updated:     6th June 2006
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


/// \file acestl/string_string_access.hpp
///
/// Helper functions for the ACE_String_XXXX classes.

#ifndef ACESTL_INCL_ACESTL_HPP_STRING_STRING_ACCESS
#define ACESTL_INCL_ACESTL_HPP_STRING_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_STRING_STRING_ACCESS_MAJOR       1
# define ACESTL_VER_ACESTL_HPP_STRING_STRING_ACCESS_MINOR       2
# define ACESTL_VER_ACESTL_HPP_STRING_STRING_ACCESS_REVISION    4
# define ACESTL_VER_ACESTL_HPP_STRING_STRING_ACCESS_EDIT        16
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#include <ace/String_Base.h>                // for ACE_String_Base
#ifdef STLSOFT_UNITTEST
# include <string.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_string_access String Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types

/// \defgroup acestl_string_access_shims String Access Shims (ACESTL)
/// \ingroup ACESTL concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for ACE string types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// Returns a non-NULL nul-terminated c-string pointer from the given string instance
template <ss_typename_param_k C>
inline C const *c_str_ptr(ACE_String_Base<C> const &s)
{
    return s.c_str();
}
inline as_char_a_t const *c_str_ptr_a(ACE_String_Base<as_char_a_t> const &s)
{
    return s.c_str();
}
inline as_char_w_t const *c_str_ptr_w(ACE_String_Base<as_char_w_t> const &s)
{
    return s.c_str();
}

/// Returns a non-NULL optionally non-nul-terminated c-string pointer from the given string instance
template <ss_typename_param_k C>
inline C const *c_str_data(ACE_String_Base<C> const &s)
{
    return s.c_str();
}
inline as_char_a_t const *c_str_data_a(ACE_String_Base<as_char_a_t> const &s)
{
    return s.c_str();
}
inline as_char_w_t const *c_str_data_a(ACE_String_Base<as_char_w_t> const &s)
{
    return s.c_str();
}

/// Returns a possibly NULL nul-terminated c-string pointer from the given string instance
template <ss_typename_param_k C>
inline C const *c_str_ptr_null(ACE_String_Base<C> const &s)
{
    return (0 == s.length()) ? NULL : s.c_str();
}

/// Evaluates the length (in characters) of the string
template <ss_typename_param_k C>
inline as_size_t c_str_len(ACE_String_Base<C> const &s)
{
    return s.length();
}

#if 0
/// Evaluates the size (in bytes) of the string
template <ss_typename_param_k C>
inline as_size_t c_str_size(ACE_String_Base<C> const &s)
{
    return sizeof(C) * s.length();
}
#endif /* 0 */

/// An inserter function for ACE_Time_Value into output streams
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &operator <<(S &s, ACE_String_Base<C> const &str)
{
    s.write(str.fast_rep(), str.length());

    return s;
}

/// @} // end of group acestl_string_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

/// An inserter function for ACE_Time_Value into output streams
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S &operator <<(S &s, ACE_String_Base<C> const &str)
{
    s.write(str.fast_rep(), str.length());

    return s;
}

namespace stlsoft
{

    using ::acestl::c_str_ptr;
    using ::acestl::c_str_ptr_a;
    using ::acestl::c_str_ptr_w;

    using ::acestl::c_str_data;
    using ::acestl::c_str_data_a;
    using ::acestl::c_str_data_w;

    using ::acestl::c_str_len;

#if 0
    using ::acestl::c_str_size;
#endif /* 0 */

} // namespace stlsoft

#endif /* !_ACESTL_NO_NAMESPACE */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

# ifndef _ACESTL_NO_NAMESPACE
#  if defined(_STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
#  else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

#  endif /* _STLSOFT_NO_NAMESPACE */
# endif /* !_ACESTL_NO_NAMESPACE */

# include "./unittest/string_string_access_unittest_.h"

# ifndef _ACESTL_NO_NAMESPACE
#  if defined(_STLSOFT_NO_NAMESPACE)
} // namespace acestl
#  else
} // namespace acestl_project
} // namespace stlsoft
#  endif /* _STLSOFT_NO_NAMESPACE */
# endif /* !_ACESTL_NO_NAMESPACE */

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ACESTL_INCL_ACESTL_HPP_STRING_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
