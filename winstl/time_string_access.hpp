/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/time_string_access.hpp
 *
 * Purpose:     Helper functions for the SYSTEMTIME and FILETIME structures.
 *
 * Created:     2nd December 2004
 * Updated:     18th December 2005
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


/// \file winstl/time_string_access.hpp
///
/// Helper functions for the SYSTEMTIME and FILETIME structures.

#ifndef WINSTL_INCL_WINSTL_HPP_TIME_STRING_ACCESS
#define WINSTL_INCL_WINSTL_HPP_TIME_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_TIME_STRING_ACCESS_MAJOR     1
# define WINSTL_VER_WINSTL_HPP_TIME_STRING_ACCESS_MINOR     3
# define WINSTL_VER_WINSTL_HPP_TIME_STRING_ACCESS_REVISION  1
# define WINSTL_VER_WINSTL_HPP_TIME_STRING_ACCESS_EDIT      19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS
# include <winstl/time_format_functions.h>
#endif /* !WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING
# include <stlsoft/shim_string.hpp>           // basic_shim_string
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHIM_STRING */

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
 * Helper Functions
 */

inline SYSTEMTIME FILETIME2SYSTEMTIME(FILETIME const &ft)
{
    SYSTEMTIME  st;

    FileTimeToSystemTime(&ft, &st);

    return st;
}

template <ss_typename_param_k S>
inline void stream_insert(S &stm, SYSTEMTIME const &t)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>     string_t;

    const int       cchDate     =   ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const int       cchTime     =   ::GetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const size_t    cchTotal    =   static_cast<size_t>((cchDate - 1) + 1 + (cchTime - 1));  // GetDateFormat() + space + GetTimeFormat() (subtracting 1 for terminating NUL in each count returned)
    string_t        s(cchTotal);

    if(cchTotal != s.size())
    {
        ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        ::GetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    stm << s;
}

template <ss_typename_param_k S>
inline void stream_insert(S &s, FILETIME const &ft)
{
    stream_insert(s, FILETIME2SYSTEMTIME(ft));
}

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_string_access String Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types

/// \defgroup winstl_string_access_shims String Access Shims (WinSTL)
/// \ingroup WinSTL concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for Win32 time types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>     string_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatA)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msA : ::GetTimeFormatA;

    const int       cchDate     =   ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const int       cchTime     =   pfnGetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const size_t    cchTotal    =   static_cast<size_t>((cchDate - 1) + 1 + (cchTime - 1));  // GetDateFormat() + space + GetTimeFormat() (subtracting 1 for terminating NUL in each count returned)
    string_t        s(cchTotal);

    if(cchTotal != s.size())
    {
        ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    return s;
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>     string_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatW)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msW : ::GetTimeFormatW;

    const int       cchDate     =   ::GetDateFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const int       cchTime     =   pfnGetTimeFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const size_t    cchTotal    =   static_cast<size_t>((cchDate - 1) + 1 + (cchTime - 1));  // GetDateFormat() + space + GetTimeFormat() (subtracting 1 for terminating NUL in each count returned)
    string_t        s(cchTotal);

    if(cchTotal != s.size())
    {
        ::GetDateFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    return s;
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
#ifdef UNICODE
    return c_str_ptr_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_ptr_a(t, bMilliseconds);
#endif /* UNICODD */
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
#ifdef UNICODE
    return c_str_ptr_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_ptr_a(t, bMilliseconds);
#endif /* UNICODD */
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a_null(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_a(t, bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w_null(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_w(t, bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr(t, bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a_null(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_a_null(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w_null(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_w_null(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_ptr_null(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_len
 */

inline ws_size_t c_str_len_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    int (STLSOFT_STDCALL *pfnGetTimeFormatA)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msA : ::GetTimeFormatA;

    const int       cchDate     =   ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const int       cchTime     =   pfnGetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const size_t    cchTotal    =   static_cast<size_t>((cchDate - 1) + 1 + (cchTime - 1));  // GetDateFormat() + space + GetTimeFormat() (subtracting 1 for terminating NUL in each count returned)

    return cchTotal;
}

inline ws_size_t c_str_len_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    int (STLSOFT_STDCALL *pfnGetTimeFormatW)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msW : ::GetTimeFormatW;

    const int       cchDate     =   ::GetDateFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const int       cchTime     =   pfnGetTimeFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0);
    const size_t    cchTotal    =   static_cast<size_t>((cchDate - 1) + 1 + (cchTime - 1));  // GetDateFormat() + space + GetTimeFormat() (subtracting 1 for terminating NUL in each count returned)

    return cchTotal;
}

inline ws_size_t c_str_len(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
#ifdef UNICODE
    return c_str_len_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_len_a(t, bMilliseconds);
#endif /* UNICODD */
}

inline ws_size_t c_str_len_a(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_len_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline ws_size_t c_str_len_w(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_len_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline ws_size_t c_str_len(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_len(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_size
 */

inline ws_size_t c_str_size_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return sizeof(ws_char_a_t) * c_str_len(t, bMilliseconds);
}

inline ws_size_t c_str_size_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return sizeof(ws_char_w_t) * c_str_len(t, bMilliseconds);
}

inline ws_size_t c_str_size(SYSTEMTIME const &t, ws_bool_t bMilliseconds = false)
{
    return sizeof(TCHAR) * c_str_len(t, bMilliseconds);
}

inline ws_size_t c_str_size_a(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_size_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline ws_size_t c_str_size_w(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_size_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

inline ws_size_t c_str_size(FILETIME const &t, ws_bool_t bMilliseconds = false)
{
    return c_str_size(FILETIME2SYSTEMTIME(t), bMilliseconds);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Stream inserter
 */

/// An inserter function for SYSTEMTIME into output streams
template <typename S>
inline S &operator <<(S &s, SYSTEMTIME const &addr)
{
    stream_insert(s, addr);

    return s;
}

/// An inserter function for SYSTEMTIME into output streams
template <typename S>
inline S &operator <<(S &s, FILETIME const &addr)
{
    stream_insert(s, addr);

    return s;
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_string_access_shims

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_time_string_access(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "time_string_access", __FILE__);

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

        unittest_registrar    unittest_winstl_time_string_access(test_winstl_time_string_access);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

/// An inserter function for SYSTEMTIME into output streams
template <typename S>
inline S &operator <<(S &s, SYSTEMTIME const &st)
{
    ::winstl::stream_insert(s, st);

    return s;
}

/// An inserter function for FILETIME into output streams
template <typename S>
inline S &operator <<(S &s, FILETIME const &st)
{
    ::winstl::stream_insert(s, st);

    return s;
}

namespace stlsoft
{

    using ::winstl::c_str_ptr;
    using ::winstl::c_str_data;
    using ::winstl::c_str_ptr_null;
    using ::winstl::c_str_len;
    using ::winstl::c_str_size;

} // namespace stlsoft

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_HPP_TIME_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
