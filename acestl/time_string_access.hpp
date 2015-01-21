/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/time_string_access.hpp
 *
 * Purpose:     Helper functions for the ACE_Time_Value class.
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


/// \file acestl/time_string_access.hpp
///
/// Helper functions for the ACE_Time_Value class.

#ifndef ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS
#define ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_MINOR     3
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_REVISION  2
# define ACESTL_VER_ACESTL_HPP_TIME_STRING_ACCESS_EDIT      20
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
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#include <ace/Time_Value.h>                 // for ACE_Time_Value
#include <ace/ace_wchar.h>                  // for ACE_Wide_To_Ascii, ACE_Ascii_To_Wide

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
    char                s1[20];
    ACE_TCHAR           s2[24];

    const long          s   =   t.sec();
    const long          us  =   t.usec();
    struct tm   *const  tm  =   ACE_OS::localtime(&static_cast<time_t const&>(s));
    size_t              len =   ACE_OS::strftime(s1, STLSOFT_NUM_ELEMENTS(s1), "%Y-%m-%d %H:%M:%S", tm);

    ACESTL_ASSERT(len == 1 + STLSOFT_NUM_ELEMENTS(s1));

    len = ACE_OS::snprintf(s2, STLSOFT_NUM_ELEMENTS(s2), ACE_TEXT("%s.%03ld"), ACE_TEXT_CHAR_TO_TCHAR(s1), us / 1000);

    ACESTL_ASSERT(len == 1 + STLSOFT_NUM_ELEMENTS(s2));

    s.write(&s2[0], len);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace access_string_util
{

    inline int invoke_ACE_OS_snprintf(ACE_TCHAR s2[], as_size_t size, ACE_TCHAR const *fmt, as_char_a_t const *s1, long ms)
    {
        return ACE_OS::snprintf(s2, size, fmt, ACE_TEXT_CHAR_TO_TCHAR(s1), ms);
    }

# ifdef ACE_USES_WCHAR
    inline int invoke_ACE_OS_snprintf(as_char_a_t s2[], as_size_t size, as_char_w_t const *fmt, as_char_a_t const *s1, long ms)
    {
        return ACE_OS::snprintf(s2, size, ACE_TEXT_ALWAYS_CHAR(fmt), s1, ms);
    }
# else /* ? ACE_USES_WCHAR */
    inline int invoke_ACE_OS_snprintf(as_char_w_t s2[], as_size_t size, as_char_a_t const *fmt, as_char_a_t const *s1, long ms)
    {
        stlsoft::auto_buffer<as_char_a_t>   buff(1 + size);
        int                                 res;

        s2[0] = '\0';

        res = ACE_OS::snprintf(&buff[0], buff.size(), ACE_TEXT_ALWAYS_CHAR(fmt), s1, ms);

        if(0 < res)
        {
            ACESTL_ASSERT(static_cast<ss_size_t>(res) < buff.size());

            ::mbstowcs(&s2[2], buff.data(), res);
            s2[res] = '\0';
        }

        return res;
    }
# endif /* ACE_USES_WCHAR */


} // namespace access_string_util
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// String access shim
template <ss_typename_param_k C>
inline ::stlsoft::basic_shim_string<C> c_str_ptr_(ACE_Time_Value const &t)
{
    typedef C                       char_t;

    as_char_a_t         s1[20];
    char_t              s2[24];
    const long          s   =   t.sec();
    const long          us  =   t.usec();
    struct tm   *const  tm  =   ACE_OS::localtime(&static_cast<time_t const&>(s));
    size_t              len =   ACE_OS::strftime(s1, STLSOFT_NUM_ELEMENTS(s1), "%Y-%m-%d %H:%M:%S", tm);

    ACESTL_ASSERT(1 + len == STLSOFT_NUM_ELEMENTS(s1));

    len = access_string_util::invoke_ACE_OS_snprintf(s2, STLSOFT_NUM_ELEMENTS(s2), ACE_TEXT("%s.%03ld"), s1, us / 1000);

    ACESTL_ASSERT(1 + len == STLSOFT_NUM_ELEMENTS(s2));

    return ::stlsoft::basic_shim_string<char_t>(&s2[0], len);
}

inline ::stlsoft::basic_shim_string<as_char_a_t> c_str_ptr_a(ACE_Time_Value const &t)
{
    return c_str_ptr_<as_char_a_t>(t);
}
inline ::stlsoft::basic_shim_string<as_char_w_t> c_str_ptr_w(ACE_Time_Value const &t)
{
    return c_str_ptr_<as_char_w_t>(t);
}
inline ::stlsoft::basic_shim_string<ACE_TCHAR> c_str_ptr(ACE_Time_Value const &t)
{
    return c_str_ptr_<ACE_TCHAR>(t);
}

inline ::stlsoft::basic_shim_string<as_char_a_t> c_str_data_a(ACE_Time_Value const &t)
{
    return c_str_ptr_a(t);
}
inline ::stlsoft::basic_shim_string<as_char_w_t> c_str_data_w(ACE_Time_Value const &t)
{
    return c_str_ptr_w(t);
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

#if 0
inline as_size_t c_str_size(ACE_Time_Value const &t)
{
    return sizeof(ACE_TCHAR) * c_str_len(t);
}
#endif /* 0 */

/// An inserter function for ACE_Time_Value into output streams
template <ss_typename_param_k S>
inline S &operator <<(S &s, ACE_Time_Value const &t)
{
    stream_insert(s, t);

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
            typedef message_queue_sequence<as_char_a_t>    env_var_t;

            env_var_t   path("PATH");

            if(0 != strcmp(getenv("PATH"), path))
            {
                r->report("message_queue_sequence<as_char_a_t> failed ", __LINE__);
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
template <ss_typename_param_k S>
inline S &operator <<(S &s, ACE_Time_Value const &t)
{
    ::acestl::stream_insert(s, t);

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

} // namespace stlsoft

#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ACESTL_INCL_ACESTL_HPP_TIME_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
