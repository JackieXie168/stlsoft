/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/time.hpp (originally winstl/time_string_access.hpp)
 *
 * Purpose:     Helper functions for the SYSTEMTIME and FILETIME structures.
 *
 * Created:     2nd December 2004
 * Updated:     18th December 2006
 *
 * Thanks to:   David Wang, for spotting an error in one of the shim
 *              functions.
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
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/shims/access/string/time.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>FILETIME</code> and <code>SYSTEMTIME</code>.
 *  (\ref group__concept__shim__string_access "String Access Shims" Concept.)
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_MAJOR       2
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_MINOR       0
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_REVISION    2
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_EDIT        36
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifndef WINSTL_INCL_WINSTL_TIME_H_FORMAT_FUNCTIONS
# include <winstl/time/format_functions.h>
#endif /* !WINSTL_INCL_WINSTL_TIME_H_FORMAT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

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
 * Helper Functions
 */

/** \brief Converts a <code>FILETIME</code> value to a
 *   <code>SYSTEMTIME</code> value.
 *
 * \ingroup group__library__shims__string_access
 *
 * \param ft The <code>FILETIME</code> instance whose value is to be converted
 *
 * \note If <code>ft</code> does not represent a valid time value, the
 *  return value is undefined. The caller may check
 *  <code>GetLastError()</code> to determine whether the conversion has been
 *  successful.
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

    if(cchTotal == s.size())
    {
        ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        ::GetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    stm << s.data();
}

template <ss_typename_param_k S>
inline void stream_insert(S &s, FILETIME const &ft)
{
    stream_insert(s, FILETIME2SYSTEMTIME(ft));
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
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

    if(cchTotal == s.size())
    {
        ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    return s;
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(SYSTEMTIME const &t)
{
    return c_str_ptr_a(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
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

    if(cchTotal == s.size())
    {
        ::GetDateFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], cchDate);
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, cchTime);
    }

    return s;
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(SYSTEMTIME const &t)
{
    return c_str_ptr_w(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
#ifdef UNICODE
    return c_str_ptr_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_ptr_a(t, bMilliseconds);
#endif /* UNICODD */
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(SYSTEMTIME const &t)
{
    return c_str_ptr(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_a(FILETIME const &t)
{
    return c_str_ptr_a(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_w(FILETIME const &t)
{
    return c_str_ptr_w(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr(FILETIME const &t)
{
    return c_str_ptr(t, ws_false_v);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_data_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_a(t, bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_data_a(SYSTEMTIME const &t)
{
    return c_str_data_a(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_data_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_w(t, bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_data_w(SYSTEMTIME const &t)
{
    return c_str_data_w(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
#ifdef UNICODE
    return c_str_data_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_data_a(t, bMilliseconds);
#endif /* UNICODD */
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(SYSTEMTIME const &t)
{
    return c_str_data(t, ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_data_a(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_data_a(FILETIME const &t)
{
    return c_str_data_a(FILETIME2SYSTEMTIME(t), ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_data_w(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_data_w(FILETIME const &t)
{
    return c_str_data_w(FILETIME2SYSTEMTIME(t), ws_false_v);
}

inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_data(FILETIME const &t)
{
    return c_str_data(FILETIME2SYSTEMTIME(t), ws_false_v);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_null_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_a(t, bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_null_a(SYSTEMTIME const &t)
{
    return c_str_ptr_null_a(t, ws_false_v);
}


inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_null_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_w(t, bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_null_w(SYSTEMTIME const &t)
{
    return c_str_ptr_null_w(t, ws_false_v);
}


inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr(t, bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(SYSTEMTIME const &t)
{
    return c_str_ptr_null(t, ws_false_v);
}


inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_null_a(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_null_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_a_t> c_str_ptr_null_a(FILETIME const &t)
{
    return c_str_ptr_null_a(FILETIME2SYSTEMTIME(t), ws_false_v);
}


inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_null_w(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_null_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<ws_char_w_t> c_str_ptr_null_w(FILETIME const &t)
{
    return c_str_ptr_null_w(FILETIME2SYSTEMTIME(t), ws_false_v);
}


inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_ptr_null(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline stlsoft_ns_qual(basic_shim_string)<TCHAR> c_str_ptr_null(FILETIME const &t)
{
    return c_str_ptr_null(FILETIME2SYSTEMTIME(t), ws_false_v);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * NOTE: The following are provided as function overloads, rather than, as
 * originally implemented, with defaulted bMilliseconds argument, because
 * DMC++ gives "ambiguous reference to symbol" errors. (And I didn't have
 * time to investigate further.)
 */

inline ws_size_t c_str_len_a(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
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
inline ws_size_t c_str_len_a(SYSTEMTIME const &t)
{
    return c_str_len_a(t, ws_false_v);
}

inline ws_size_t c_str_len_w(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
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
inline ws_size_t c_str_len_w(SYSTEMTIME const &t)
{
    return c_str_len_w(t, ws_false_v);
}

inline ws_size_t c_str_len(SYSTEMTIME const &t, ws_bool_t bMilliseconds)
{
#ifdef UNICODE
    return c_str_len_w(t, bMilliseconds);
#else /* ? UNICODD */
    return c_str_len_a(t, bMilliseconds);
#endif /* UNICODD */
}
inline ws_size_t c_str_len(SYSTEMTIME const &t)
{
    return c_str_len(t, ws_false_v);
}

inline ws_size_t c_str_len_a(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_len_a(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline ws_size_t c_str_len_a(FILETIME const &t)
{
    return c_str_len_a(FILETIME2SYSTEMTIME(t), ws_false_v);
}

inline ws_size_t c_str_len_w(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_len_w(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline ws_size_t c_str_len_w(FILETIME const &t)
{
    return c_str_len_w(FILETIME2SYSTEMTIME(t), ws_false_v);
}


inline ws_size_t c_str_len(FILETIME const &t, ws_bool_t bMilliseconds)
{
    return c_str_len(FILETIME2SYSTEMTIME(t), bMilliseconds);
}
inline ws_size_t c_str_len(FILETIME const &t)
{
    return c_str_len(FILETIME2SYSTEMTIME(t), ws_false_v);
}

/* /////////////////////////////////////////////////////////////////////////
 * Stream inserter
 */

/** \brief An inserter function for SYSTEMTIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline S &operator <<(S &s, SYSTEMTIME const &addr)
{
    stream_insert(s, addr);

    return s;
}

/** \brief An inserter function for SYSTEMTIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline S &operator <<(S &s, FILETIME const &addr)
{
    stream_insert(s, addr);

    return s;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

/** \brief An inserter function for SYSTEMTIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline S &operator <<(S &s, SYSTEMTIME const &st)
{
    ::winstl::stream_insert(s, st);

    return s;
}

/** \brief An inserter function for FILETIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline S &operator <<(S &s, FILETIME const &st)
{
    ::winstl::stream_insert(s, st);

    return s;
}

namespace stlsoft
{
    using ::winstl::c_str_ptr_null;
    using ::winstl::c_str_ptr_null_a;
    using ::winstl::c_str_ptr_null_w;

    using ::winstl::c_str_ptr;
    using ::winstl::c_str_ptr_a;
    using ::winstl::c_str_ptr_w;

    using ::winstl::c_str_data;
    using ::winstl::c_str_data_a;
    using ::winstl::c_str_data_w;

    using ::winstl::c_str_len;

    using ::winstl::c_str_len_a;
    using ::winstl::c_str_len_w;

} // namespace stlsoft

#endif /* !_WINSTL_NO_NAMESPACE */

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

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/time_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME */

/* ////////////////////////////////////////////////////////////////////// */
