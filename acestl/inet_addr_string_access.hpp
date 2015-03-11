/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/inet_addr_string_access.hpp
 *
 * Purpose:     Helper functions for ACE strings.
 *
 * Created:     23rd September 2004
 * Updated:     13th January 2006
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


/// \file acestl/inet_addr_string_access.hpp
///
/// Helper functions for ACE strings.

#ifndef ACESTL_INCL_ACESTL_HPP_INET_ADDR_STRING_ACCESS
#define ACESTL_INCL_ACESTL_HPP_INET_ADDR_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_INET_ADDR_STRING_ACCESS_MAJOR      1
# define ACESTL_VER_ACESTL_HPP_INET_ADDR_STRING_ACCESS_MINOR      5
# define ACESTL_VER_ACESTL_HPP_INET_ADDR_STRING_ACCESS_REVISION   1
# define ACESTL_VER_ACESTL_HPP_INET_ADDR_STRING_ACCESS_EDIT       19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING
# include <stlsoft/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING */
#include <ace/INET_Addr.h>                      // for ACE_INET_Addr

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

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_string String Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing string attributes

/// \defgroup acestl_string_library String Library (ACESTL)
/// \ingroup ACESTL libraries_string
/// \brief This library provides facilities for accessing string attributes for ACE address types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <ss_typename_param_k S>
void stream_insert(S &s, ACE_INET_Addr const &addr)
{
    typedef ::stlsoft::auto_buffer_old< ACE_TCHAR
                                    ,   ::stlsoft::allocator_selector<ACE_TCHAR>::allocator_type
                                    >       buffer_t;

    buffer_t    buffer(buffer_t::internal_size());

    for(;0 != addr.addr_to_string(&buffer[0], buffer.size()); buffer.resize(2 * buffer.size()))
    {}

    buffer.resize(buffer.size() + 1);
    buffer[buffer.size() - 1] = '\0';

    s << &buffer[0];
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// String access shim
inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_ptr(ACE_INET_Addr const &addr)
{
    typedef ::stlsoft::basic_shim_string<ACE_TCHAR>::buffer_type    buffer_t;

    ::stlsoft::basic_shim_string<ACE_TCHAR> retVal(buffer_t::internal_size());
    buffer_t                                &buffer =   retVal.get_buffer();

    for(;0 != addr.addr_to_string(&buffer[0], buffer.size()); buffer.resize((3 * buffer.size()) / 2))
    {}

    buffer.resize(buffer.size() + 1);
    buffer[buffer.size() - 1] = '\0';

    return retVal;
}

inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_data(ACE_INET_Addr const &addr)
{
    return c_str_ptr(addr);
}

inline as_size_t c_str_len(ACE_INET_Addr const &addr)
{
    return c_str_ptr(addr).size();
}

/// An inserter function for ACE_INET_Addr into output streams
template <typename S>
inline S &operator <<(S &s, ACE_INET_Addr const &addr)
{
    stream_insert(s, addr);

    return s;
}

////////////////////////////////////////////////////////////////////////////////

/// @} // acestl_string_library

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/inet_addr_string_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

/// An inserter function for ACE_INET_Addr into output streams
template <typename S>
inline S &operator <<(S &s, ACE_INET_Addr const &addr)
{
    ::acestl::stream_insert(s, addr);

    return s;
}

namespace stlsoft
{

    using ::acestl::c_str_ptr;
    using ::acestl::c_str_data;
    using ::acestl::c_str_len;

} // namespace stlsoft

#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_HPP_INET_ADDR_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
