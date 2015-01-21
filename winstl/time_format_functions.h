/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/time_format_functions.h (formerly winstl_time_functions.h)
 *
 * Purpose:     Comparison functions for Windows time structures.
 *
 * Created:     21st November 2003
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/time_format_functions.h
///
/// Comparison functions for Windows time structures.

#ifndef WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_TIME_FORMAT_FUNCTIONS_MAJOR    3
# define WINSTL_VER_WINSTL_H_TIME_FORMAT_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_H_TIME_FORMAT_FUNCTIONS_REVISION 1
# define WINSTL_VER_WINSTL_H_TIME_FORMAT_FUNCTIONS_EDIT     32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_INTEGER_TO_STRING
# include <stlsoft/integer_to_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_INTEGER_TO_STRING */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>  // processheap_allocator
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef WINSTL_INCL_WINSTL_HPP_REGISTRY_FUNCTIONS
# include <winstl/registry_functions.hpp>   // reg_get_string_value
#endif /* !WINSTL_INCL_WINSTL_HPP_REGISTRY_FUNCTIONS */

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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_time Time Library
/// \ingroup libraries
/// \brief This library provides facilities for representing and manipulating time

/// \weakgroup winstl_time_library Time Library (WinSTL)
/// \ingroup WinSTL libraries_time
/// \brief This library provides facilities for representing and manipulating time for the Win32 API
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Helper classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
struct time_format_functions_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct time_format_functions_traits<ws_char_a_t>
{
    typedef ws_char_a_t char_type;

    static int GetTimeFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, char_type const *lpFormat, char_type *lpTimeStr, int cchTime)
    {
        return ::GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }
    static int GetLocaleInfo(LCID Locale, LCTYPE LCType, char_type *lpLCData, int cchData)
    {
        return ::GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
    }
    static ss_size_t lstrlen(char_type const *s)
    {
        return static_cast<ss_size_t>(::lstrlenA(s));
    }
    static char_type *lstrcpy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyA(dest, src);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct time_format_functions_traits<ws_char_w_t>
{
    typedef ws_char_w_t char_type;

    static int GetTimeFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, char_type const *lpFormat, char_type *lpTimeStr, int cchTime)
    {
        return ::GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }
    static int GetLocaleInfo(LCID Locale, LCTYPE LCType, char_type *lpLCData, int cchData)
    {
        return ::GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
    }
    static ss_size_t lstrlen(char_type const *s)
    {
        return static_cast<ss_size_t>(::lstrlenW(s));
    }
    static char_type *lstrcpy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyW(dest, src);
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <ss_typename_param_k C>
inline int STLSOFT_STDCALL GetTimeFormat_ms_(   LCID                locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   C const             *lpFormat   // time format string
                                            ,   C                   *lpTimeStr  // formatted string buffer
                                            ,   const int           cchTime)    // size of string buffer
{
    typedef C                                                                       char_t;
    typedef time_format_functions_traits<char_t>                                    traits_t;
    typedef stlsoft_ns_qual(auto_buffer)<char_t, processheap_allocator<char_t> >    buffer_t;

    if(dwFlags & (TIME_NOMINUTESORSECONDS | TIME_NOSECONDS))
    {
        return traits_t::GetTimeFormat(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }

    if(dwFlags & LOCALE_NOUSEROVERRIDE)
    {
        locale = LOCALE_SYSTEM_DEFAULT;
    }

    buffer_t            timePicture(1 + ((NULL == lpFormat) ? static_cast<ss_size_t>(::GetLocaleInfoA(locale, LOCALE_STIMEFORMAT, NULL, 0)) : 0));

    if(NULL == lpFormat)
    {
        ss_size_t   n = static_cast<ss_size_t>(traits_t::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_STIMEFORMAT, &timePicture[0], static_cast<int>(timePicture.size())));
        lpFormat = &timePicture[0];
        if(n < timePicture.size())
        {
            timePicture[n] = static_cast<C>('\0');
        }
    }

    const ss_size_t     cchPicture  =   1 + traits_t::lstrlenA(lpFormat);

    char_t         hours_[]    =   { '0', '0', '\0' };                      // "00"
    char_t         minutes_[]  =   { '0', '0', '\0' };                      // "00"
    char_t         seconds_[]  =   { '0', '0', '.', '0', '0', '0', '\0' };  // "00.000"

    char_t const   *hours      =   stlsoft_ns_qual(integer_to_string)(&hours_[0], stlsoft_num_elements(hours_), lpTime->wHour);
    char_t const   *minutes    =   stlsoft_ns_qual(integer_to_string)(&minutes_[0], stlsoft_num_elements(minutes_), lpTime->wMinute);
                                   stlsoft_ns_qual(integer_to_string)(&seconds_[3], 4, lpTime->wMilliseconds);
    char_t const   *seconds    =   stlsoft_ns_qual(integer_to_string)(&seconds_[0], 3, lpTime->wSecond);

    seconds_[2] = '.';

    // Get the time markers
    HKEY        hkey;
    LONG        res =   ::RegOpenKey(HKEY_CURRENT_USER, "Control Panel\\International", &hkey);
    buffer_t    am(0);
    buffer_t    pm(0);

    if(ERROR_SUCCESS == res)
    {
        static const char_t s1159[] =   { 's', '1', '1', '5', '9', '\0' };
        static const char_t s2359[] =   { 's', '2', '3', '5', '9', '\0' };
        size_t              cchAM   =   0;
        size_t              cchPM   =   0;
        LONG                r;

        if( ERROR_SUCCESS != (r = reg_get_string_value(hkey, s1159, static_cast<char_t*>(NULL), cchAM)) ||
            ERROR_SUCCESS != (r = (am.resize(cchAM), cchAM = am.size(), reg_get_string_value(hkey, s1159, &am[0], cchAM))))
        {
            res = r;
        }
        else if(ERROR_SUCCESS != (r = reg_get_string_value(hkey, s2359, static_cast<char_t*>(NULL), cchPM)) ||
                ERROR_SUCCESS != (r = (pm.resize(cchPM), cchPM = pm.size(), reg_get_string_value(hkey, s2359, &pm[0], cchPM))))
        {
            res = r;
        }

        ::RegCloseKey(hkey);
    }

    if(ERROR_SUCCESS != res)
    {
        static const char_t AM[]    =   { 'A', 'M', '\0' };
        static const char_t PM[]    =   { 'P', 'M', '\0' };

        am.resize(3);
        pm.resize(3);

        traits_t::lstrcpy(&am[0], AM);
        traits_t::lstrcpy(&pm[0], PM);
    }

    char_t const    *timeMarker =   (lpTime->wHour < 12) ? &am[0] : &pm[0];
    const size_t    cchMarker   =   (am.size() < pm.size()) ? pm.size() : am.size();
    const size_t    cchTimeMax  =   (cchPicture - 1) + (2 - 1) + (2 - 1) + (6 - 1) + 1 + cchMarker;
    buffer_t        buffer(1 + cchTimeMax);
    size_t          len         =   0;

    if(!buffer.empty())
    {
        char_t const    *r;
        char_t          *w          =   &buffer[0];
        char_t          prev        =   '\0';
        ws_bool_t       bMarker1    =   true;

        for(r = lpFormat; r != lpFormat + cchPicture; ++r)
        {
            const char_t    ch  =   *r;

            switch(ch)
            {
                case    'h':
                    if( 'h' == prev &&
                        hours != &hours_[0])
                    {
                        --hours;
                    }
                    break;
                case    'm':
                    if( 'm' == prev &&
                        minutes != &minutes_[0])
                    {
                        --minutes;
                    }
                    break;
                case    's':
                    if( 's' == prev &&
                        seconds != &seconds_[0])
                    {
                        --seconds;
                    }
                    break;
                case    't':
                    if('t' == prev)
                    {
                        bMarker1 = false;
                    }
                    break;
                default:
                    {
                        static const char_t EMPTY_STRING[] = { '\0' };
                        char_t const        *p;

                        switch(prev)
                        {
                            case    'h':    p = hours;          break;
                            case    'm':    p = minutes;        break;
                            case    's':    p = seconds;        break;
                            case    't':
                                if(0 == (dwFlags & TIME_NOTIMEMARKER))
                                {
                                    if(!bMarker1)
                                    {
                                        p = timeMarker;
                                        break;
                                    }
                                    else
                                    {
                                        // Fall through
                                        *w++ = *timeMarker;
                                        ++len;
                                    }
                                }
                                // Fall through
                            default:        p = EMPTY_STRING;   break;
                        }

                        for(; '\0' != *p; *w++ = *p++, ++len)
                        {}
                    }
                    *w++ = ch;
                    ++len;
                    break;
            }

            if('\0' == ch)
            {
                break;
            }

            prev = ch;
        }
    }

    // If 0 was specified, or 

    if( 0 == cchTime ||
        len <= size_t(cchTime))
    {
        if(0 != cchTime)
        {
            traits_t::lstrcpy(lpTimeStr, &buffer[0]);
        }

        return static_cast<int>(len);
    }
    else
    {
        return 0;
    }
}

#if 0
inline int STLSOFT_STDCALL GetTimeFormat_msA_(  LCID                locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   const int           cchTime)    // size of string buffer
{
    typedef stlsoft_ns_qual(auto_buffer)<ws_char_a_t, processheap_allocator<ws_char_a_t> >  buffer_t;

    if(dwFlags & (TIME_NOMINUTESORSECONDS | TIME_NOSECONDS))
    {
        return ::GetTimeFormatA(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }

    if(dwFlags & LOCALE_NOUSEROVERRIDE)
    {
        locale = LOCALE_SYSTEM_DEFAULT;
    }

    buffer_t            timePicture(1 + ((NULL == lpFormat) ? static_cast<ss_size_t>(::GetLocaleInfoA(locale, LOCALE_STIMEFORMAT, NULL, 0)) : 0));

    if(NULL == lpFormat)
    {
        int n = ::GetLocaleInfoA(LOCALE_USER_DEFAULT, LOCALE_STIMEFORMAT, &timePicture[0], static_cast<int>(timePicture.size()));
        lpFormat = &timePicture[0];
        if(n < timePicture.size())
        {
            timePicture[n] = '\0';
        }
    }

    const ss_size_t     cchPicture  =   1 + static_cast<ss_size_t>(::lstrlenA(lpFormat));

    ws_char_a_t         hours_[]    =   "00";
    ws_char_a_t         minutes_[]  =   "00";
    ws_char_a_t         seconds_[]  =   "00.000";

    ws_char_a_t const   *hours      =   stlsoft_ns_qual(integer_to_string)(&hours_[0], stlsoft_num_elements(hours_), lpTime->wHour);
    ws_char_a_t const   *minutes    =   stlsoft_ns_qual(integer_to_string)(&minutes_[0], stlsoft_num_elements(minutes_), lpTime->wMinute);
                                        stlsoft_ns_qual(integer_to_string)(&seconds_[3], 4, lpTime->wMilliseconds);
    ws_char_a_t const   *seconds    =   stlsoft_ns_qual(integer_to_string)(&seconds_[0], 3, lpTime->wSecond);

    seconds_[2] = '.';

    // Get the time markers
    HKEY        hkey;
    LONG        res =   ::RegOpenKey(HKEY_CURRENT_USER, "Control Panel\\International", &hkey);
    buffer_t    am(0);
    buffer_t    pm(0);

    if(ERROR_SUCCESS == res)
    {
        size_t  cchAM   =   0;
        size_t  cchPM   =   0;
        LONG    r;

        if( ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s1159", static_cast<ws_char_a_t*>(NULL), cchAM)) ||
            ERROR_SUCCESS != (r = (am.resize(cchAM), cchAM = am.size(), reg_get_string_value(hkey, "s1159", &am[0], cchAM))))
        {
            res = r;
        }
        else if(ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s2359", static_cast<ws_char_a_t*>(NULL), cchPM)) ||
                ERROR_SUCCESS != (r = (pm.resize(cchPM), cchPM = pm.size(), reg_get_string_value(hkey, "s2359", &pm[0], cchPM))))
        {
            res = r;
        }

        ::RegCloseKey(hkey);
    }

    if(ERROR_SUCCESS != res)
    {
        am.resize(3);
        pm.resize(3);

        ::lstrcpyA(&am[0], "AM");
        ::lstrcpyA(&pm[0], "PM");
    }

    ws_char_a_t const   *timeMarker =   (lpTime->wHour < 12) ? &am[0] : &pm[0];
    const size_t        cchMarker   =   (am.size() < pm.size()) ? pm.size() : am.size();
    const size_t        cchTimeMax  =   (cchPicture - 1) + (2 - 1) + (2 - 1) + (6 - 1) + 1 + cchMarker;
    buffer_t            buffer(1 + cchTimeMax);
    size_t              len         =   0;

    if(!buffer.empty())
    {
        ws_char_a_t const   *r;
        ws_char_a_t         *w          =   &buffer[0];
        ws_char_a_t         prev        =   '\0';
        ws_bool_t           bMarker1    =   true;

        for(r = lpFormat; r != lpFormat + cchPicture; ++r)
        {
            const ws_char_a_t   ch  =   *r;

            switch(ch)
            {
                case    'h':
                    if( 'h' == prev &&
                        hours != &hours_[0])
                    {
                        --hours;
                    }
                    break;
                case    'm':
                    if( 'm' == prev &&
                        minutes != &minutes_[0])
                    {
                        --minutes;
                    }
                    break;
                case    's':
                    if( 's' == prev &&
                        seconds != &seconds_[0])
                    {
                        --seconds;
                    }
                    break;
                case    't':
                    if('t' == prev)
                    {
                        bMarker1 = false;
                    }
                    break;
                default:
                    {
                        ws_char_a_t const *p;

                        switch(prev)
                        {
                            case    'h':    p = hours;          break;
                            case    'm':    p = minutes;        break;
                            case    's':    p = seconds;        break;
                            case    't':
                                if(0 == (dwFlags & TIME_NOTIMEMARKER))
                                {
                                    if(!bMarker1)
                                    {
                                        p = timeMarker;
                                        break;
                                    }
                                    else
                                    {
                                        // Fall through
                                        *w++ = *timeMarker;
                                        ++len;
                                    }
                                }
                                // Fall through
                            default:        p = "";             break;
                        }

                        for(; '\0' != *p; *w++ = *p++, ++len)
                        {}
                    }
                    *w++ = ch;
                    ++len;
                    break;
            }

            if('\0' == ch)
            {
                break;
            }

            prev = ch;
        }
    }

    // If 0 was specified, or 

    if( 0 == cchTime ||
        len <= size_t(cchTime))
    {
        if(0 != cchTime)
        {
            ::lstrcpyA(lpTimeStr, &buffer[0]);
        }

        return static_cast<int>(len);
    }
    else
    {
        return 0;
    }
}

inline int STLSOFT_STDCALL GetTimeFormat_msW_(  LCID                locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   const int           cchTime)    // size of string buffer
{
    typedef stlsoft_ns_qual(auto_buffer)<ws_char_w_t, processheap_allocator<ws_char_w_t> >  buffer_t;

    if(dwFlags & (TIME_NOMINUTESORSECONDS | TIME_NOSECONDS))
    {
        return ::GetTimeFormatW(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }

    if(dwFlags & LOCALE_NOUSEROVERRIDE)
    {
        locale = LOCALE_SYSTEM_DEFAULT;
    }

    buffer_t            timePicture(1 + (NULL == lpFormat ? static_cast<ss_size_t>(::GetLocaleInfoW(locale, LOCALE_STIMEFORMAT, NULL, 0)) : 0));
    ss_size_t           cchPicture;

    if(NULL == lpFormat)
    {
        ::GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_STIMEFORMAT, &timePicture[0], static_cast<int>(timePicture.size()));
        lpFormat = &timePicture[0];
        cchPicture = timePicture.size() - 1;
    }
    else
    {
        cchPicture = static_cast<ss_size_t>(::lstrlenW(lpFormat));
    }

    ws_char_w_t         hours_[]    =   L"00";
    ws_char_w_t         minutes_[]  =   L"00";
    ws_char_w_t         seconds_[]  =   L"00.000";

    ws_char_w_t const   *hours      =   stlsoft_ns_qual(integer_to_string)(&hours_[0], stlsoft_num_elements(hours_), lpTime->wHour);
    ws_char_w_t const   *minutes    =   stlsoft_ns_qual(integer_to_string)(&minutes_[0], stlsoft_num_elements(minutes_), lpTime->wMinute);
                                        stlsoft_ns_qual(integer_to_string)(&seconds_[3], 4, lpTime->wMilliseconds);
    ws_char_w_t const   *seconds    =   stlsoft_ns_qual(integer_to_string)(&seconds_[0], 3, lpTime->wSecond);

    seconds_[2] = '.';

    // Get the time markers
    HKEY        hkey;
    LONG        res =   ::RegOpenKey(HKEY_CURRENT_USER, "Control Panel\\International", &hkey);
    buffer_t    am(0);
    buffer_t    pm(0);

    if(ERROR_SUCCESS == res)
    {
        size_t  cchAM;
        size_t  cchPM;
        LONG    r;

        if( ERROR_SUCCESS != (r = reg_get_string_value(hkey, L"s1159", static_cast<ws_char_w_t*>(NULL), cchAM)) ||
            ERROR_SUCCESS != (r = (am.resize(cchAM), cchAM = am.size(), reg_get_string_value(hkey, L"s1159", &am[0], cchAM))))
        {
            res = r;
        }
        else if(ERROR_SUCCESS != (r = reg_get_string_value(hkey, L"s2359", static_cast<ws_char_w_t*>(NULL), cchPM)) ||
                ERROR_SUCCESS != (r = (pm.resize(cchPM), cchPM = pm.size(), reg_get_string_value(hkey, L"s2359", &pm[0], cchPM))))
        {
            res = r;
        }

        ::RegCloseKey(hkey);
    }

    if(ERROR_SUCCESS != res)
    {
        am.resize(3);
        pm.resize(3);

        ::lstrcpyW(&am[0], L"AM");
        ::lstrcpyW(&pm[0], L"PM");
    }

    ws_char_w_t const   *timeMarker =   (lpTime->wHour < 12) ? &am[0] : &pm[0];
    const size_t        cchMarker   =   (am.size() < pm.size()) ? pm.size() : am.size();
    const size_t        cchTimeMax  =   (cchPicture - 1) + (2 - 1) + (2 - 1) + (6 - 1) + 1 + cchMarker;
    buffer_t            buffer(1 + cchTimeMax);

    if(!buffer.empty())
    {
        ws_char_w_t const   *r;
        ws_char_w_t         *w          =   &buffer[0];
        ws_char_w_t         prev        =   '\0';
        ws_bool_t           bMarker1    =   true;

        for(r = lpFormat; r != lpFormat + cchPicture; ++r)
        {
            const ws_char_w_t   ch  =   *r;

            switch(ch)
            {
                case    'h':
                    if( 'h' == prev &&
                        hours != &hours_[0])
                    {
                        --hours;
                    }
                    break;
                case    'm':
                    if( 'm' == prev &&
                        minutes != &minutes_[0])
                    {
                        --minutes;
                    }
                    break;
                case    's':
                    if( 's' == prev &&
                        seconds != &seconds_[0])
                    {
                        --seconds;
                    }
                    break;
                case    't':
                    if('t' == prev)
                    {
                        bMarker1 = false;
                    }
                    break;
                default:
                    {
                        ws_char_w_t const *p;

                        switch(prev)
                        {
                            case    'h':    p = hours;          break;
                            case    'm':    p = minutes;        break;
                            case    's':    p = seconds;        break;
                            case    't':
                                if(0 == (dwFlags & TIME_NOTIMEMARKER))
                                {
                                    if(!bMarker1)
                                    {
                                        p = timeMarker;
                                        break;
                                    }
                                    else
                                    {
                                        // Fall through
                                        *w++ = *timeMarker;
                                    }
                                }
                                // Fall through
                            default:        p = L"";             break;
                        }

                        for(; '\0' != *p; *w++ = *p++)
                        {}
                    }
                    *w++ = ch;
                    break;
            }

            if('\0' == ch)
            {
                break;
            }

            prev = ch;
        }
    }

    const size_t    len =   static_cast<ss_size_t>(::lstrlenW(&buffer[0]));

    if( 0 == cchTime ||
        size_t(cchTime) <= len + 1)
    {
        if(0 != cchTime)
        {
            ::lstrcpyW(lpTimeStr, &buffer[0]);
        }

        return static_cast<int>(len + 1);
    }
    else
    {
        return 0;
    }
}
#endif /* 0 */

inline int STLSOFT_STDCALL GetTimeFormat_msA(   LCID                locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer
{
#if 0
    return GetTimeFormat_msA_(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
#else /* ? 0 */
    return GetTimeFormat_ms_<ws_char_a_t>(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
#endif /* 0 */
}

inline int STLSOFT_STDCALL GetTimeFormat_msW(   LCID                locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer
{
#if 0
    return GetTimeFormat_msW_(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
#else /* ? 0 */
    return GetTimeFormat_ms_<ws_char_w_t>(locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
#endif /* 0 */
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_time_format_functions_withPicture(unittest_reporter   *r
                                                            ,   SYSTEMTIME const    &t
                                                            ,   ws_char_a_t const   *picture
                                                            ,   ws_char_a_t const   *result)
        {
            ss_bool_t               bSuccess    =   true;
            ws_char_a_t             sz[201];

            if(0 == GetTimeFormat_msA(LOCALE_USER_DEFAULT, 0, &t, picture, &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msA() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else if(0 != ::lstrcmpA(&sz[0], result))
            {
                r->report("GetTimeFormat_msA() failed: wrongly formatted", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }
        ss_bool_t test_winstl_time_format_functions_withPicture(unittest_reporter   *r
                                                            ,   SYSTEMTIME const    &t
                                                            ,   ws_char_w_t const   *picture
                                                            ,   ws_char_w_t const   *result)
        {
            ss_bool_t               bSuccess    =   true;
            ws_char_w_t             sz[201];

            if(0 == GetTimeFormat_msW(LOCALE_USER_DEFAULT, 0, &t, picture, &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msW() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else if(0 != ::lstrcmpW(&sz[0], result))
            {
                r->report("GetTimeFormat_msW() failed: wrongly formatted", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_winstl_time_format_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            typedef stlsoft_ns_qual(auto_buffer)<char, processheap_allocator<char> >    buffer_a_t;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "time_format_functions", __FILE__);

            char                    sz[201];
            SYSTEMTIME              st;

            st.wYear            =   2005;
            st.wMonth           =   4;
            st.wDayOfWeek       =   3;
            st.wDay             =   27;
            st.wHour            =   12;
            st.wMinute          =   46;
            st.wSecond          =   01;
            st.wMilliseconds    =   333;

            HKEY        hkey;
            LONG        res =   ::RegOpenKey(HKEY_CURRENT_USER, "Control Panel\\International", &hkey);
            buffer_a_t  am(0);
            buffer_a_t  pm(0);

            if(ERROR_SUCCESS == res)
            {
                size_t  cchAM   =   0;
                size_t  cchPM   =   0;
                LONG    r;

                if( ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s1159", static_cast<char*>(NULL), cchAM)) ||
                    ERROR_SUCCESS != (r = (am.resize(cchAM), cchAM = am.size(), reg_get_string_value(hkey, "s1159", &am[0], cchAM))))
                {
                    res = r;
                }
                else if(ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s2359", static_cast<char*>(NULL), cchPM)) ||
                        ERROR_SUCCESS != (r = (pm.resize(cchPM), cchPM = pm.size(), reg_get_string_value(hkey, "s2359", &pm[0], cchPM))))
                {
                    res = r;
                }

                ::RegCloseKey(hkey);
            }

            if(ERROR_SUCCESS != res)
            {
                am.resize(3);
                pm.resize(3);

                ::lstrcpyA(&am[0], "AM");
                ::lstrcpyA(&pm[0], "PM");
            }


            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh/mm", "12/46");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh/mm", L"12/46");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh/mm/ss", "12/46/01.333");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh/mm/ss", L"12/46/01.333");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh:mm", "12:46");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh:mm", L"12:46");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh:mm:ss", "12:46:01.333");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh:mm:ss", L"12:46:01.333");
            }

            if(0 == GetTimeFormat_msA(LOCALE_USER_DEFAULT, 0, &st, "hh:mm:ss tt", &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msA() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else
            {
                char    result[101] = "12:46:01.333 ";

                ::lstrcatA(&result[0], &pm[0]);

                if(0 != ::lstrcmpA(&sz[0], result))
                {
                    r->report("GetTimeFormat_msA() failed: wrongly formatted", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_time_format_functions(test_winstl_time_format_functions);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_time_library

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

#endif /* !WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
