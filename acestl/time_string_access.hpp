/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/time_string_access.hpp
 *
 * Purpose:     Helper functions for the ACE_Time_Value class.
 *
 * Created:     2nd December 2004
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


/// \file acestl/time_string_access.hpp
///
/// Helper functions for the ACE_Time_Value class.

#ifndef ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS
#define ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_MINOR     2
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_REVISION  2
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_EDIT      16
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
#ifndef STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING
# include <stlsoft/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING */
#include <ace/Time_Value.h>                 // for ACE_Time_Value

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
/// \brief These \ref concepts_shims "shims" retrieve the C-string for ACE time types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <ss_typename_param_k S>
void stream_insert(S &s, ACE_Time_Value const &t)
{
    ACE_TEXT        s1[20];
    ACE_TEXT        s2[24];

    const long          s   =   t.sec();
    const long          us  =   t.usec();
    struct tm   *const  tm  =   ACE_OS::localtime(&static_cast<time_t const&>(s));
    size_t              len =   ACE_OS::strftime(s1, stlsoft_num_elements(s1), "%Y-%m-%d %H:%M:%S", tm);

    ACESTL_ASSERT(len == 1 + stlsoft_num_elements(s1));

    len = ACE_OS::snprintf(s2, stlsoft_num_elements(s2), ACE_TEXT("%s.%03ld"), s1, us / 1000);

    ACESTL_ASSERT(len == 1 + stlsoft_num_elements(s2));

    s.write(&s2[0], len);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// String access shim
inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_ptr(ACE_Time_Value const &t)
{
    ACE_TCHAR           s1[20];
    ACE_TCHAR           s2[24];
    const long          s   =   t.sec();
    const long          us  =   t.usec();
    struct tm   *const  tm  =   ACE_OS::localtime(&static_cast<time_t const&>(s));
    size_t              len =   ACE_OS::strftime(s1, stlsoft_num_elements(s1), "%Y-%m-%d %H:%M:%S", tm);

    ACESTL_ASSERT(1 + len == stlsoft_num_elements(s1));

    len = ACE_OS::snprintf(s2, stlsoft_num_elements(s2), ACE_TEXT("%s.%03ld"), s1, us / 1000);

    ACESTL_ASSERT(1 + len == stlsoft_num_elements(s2));

    return ::stlsoft::basic_shim_string<ACE_TCHAR>(&s2[0], len);
}

inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_data(ACE_Time_Value const &t)
{
    return c_str_ptr(t);
}

inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_ptr_null(ACE_Time_Value const &t)
{
    return c_str_ptr(t);
}

inline as_size_t c_str_len(ACE_Time_Value const &/* t */)
{
    return 23;
}

inline as_size_t c_str_size(ACE_Time_Value const &t)
{
    return sizeof(ACE_TCHAR) * c_str_len(t);
}

/// An inserter function for ACE_Time_Value into output streams
template <typename S>
inline S &operator <<(S &s, ACE_Time_Value const &addr)
{
    stream_insert(s, addr);

    return s;
}

/// @} // end of group winstl_sync_control_shims

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_acestl_time_string_access(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "ACESTL", "time_string_access", __FILE__);

#if 0
            typedef message_queue_sequence<char>    env_var_t;

            env_var_t   path("PATH");

            if(0 != strcmp(getenv("PATH"), path))
            {
                r->report("message_queue_sequence<char> failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_acestl_time_string_access(test_acestl_time_string_access);
    } // anonymous namespace

} // namespace unittest

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

/// An inserter function for ACE_Time_Value into output streams
template <typename S>
inline S &operator <<(S &s, ACE_Time_Value const &addr)
{
    ::acestl::stream_insert(s, addr);

    return s;
}

namespace stlsoft
{

    using ::acestl::c_str_ptr;
    using ::acestl::c_str_data;

} // namespace stlsoft

#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */