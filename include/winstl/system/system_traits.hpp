/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/system_traits.hpp (originally winstl_filesystem_traits.h)
 *
 * Purpose:     Contains the system_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/system/system_traits.hpp
 *
 * \brief [C++ only] Definition of the winstl::system_traits traits
 *  class.
 *  (\ref group__library__system "System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_MAJOR       5
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_MINOR       1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_REVISION    1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_EDIT        96
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#include <string.h>
#include <wchar.h>

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

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** \brief Traits for accessing the correct system functions for a given
 *   character type.
 *
 * \ingroup group__library__system
 *
 * system_traits is a traits class for determining the correct system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct system_traits
{
/// \name Types
/// @{
public:
    /// \brief The character type
    typedef C                                       char_type;
    /// \brief The size type
    typedef ws_size_t                               size_type;
    /// \brief The difference type
    typedef ws_ptrdiff_t                            difference_type;
    /// \brief The current instantion of the type
    typedef system_traits<C>                        class_type;
    /// \brief The (signed) integer type
    typedef ws_int_t                                int_type;
    /// \brief The Boolean type
    typedef ws_bool_t                               bool_type;
    /// \brief The type of a handle to a dynamically loaded module
    typedef HINSTANCE                               module_type;
    /// \brief The type of a handle to a kernel object
    typedef HANDLE                                  handle_type;
    /// \brief The type of system error codes
    typedef DWORD                                   error_type;
/// @}

/// \name General string handling
/// @{
public:
    /// \brief Copies the contents of \c src to \c dest
    static char_type    *str_copy(char_type *dest, char_type const *src);
    /// \brief Copies the contents of \c src to \c dest, up to cch \c characters
    static char_type    *str_n_copy(char_type *dest, char_type const *src, size_type cch);
    /// \brief Appends the contents of \c src to \c dest
    static char_type    *str_cat(char_type *dest, char_type const *src);
    /// \brief Appends the contents of \c src to \c dest, up to cch \c characters
    static char_type    *str_n_cat(char_type *dest, char_type const *src, size_type cch);
    /// \brief Comparies the contents of \c src and \c dest
    static int_type     str_compare(char_type const *s1, char_type const *s2);
    /// \brief Comparies the contents of \c src and \c dest in a case-insensitive fashion
    static int_type     str_compare_no_case(char_type const *s1, char_type const *s2);
    /// \brief Comparies the contents of \c src and \c dest up to \c cch characters
    static int_type     str_n_compare(char_type const *s1, char_type const *s2, size_type cch);
    /// \brief Evaluates the length of \c src
    static size_type    str_len(char_type const *src);
    /// \brief Finds the given character \c ch in \c s
    static char_type    *str_chr(char_type const *s, char_type ch);
    /// \brief Finds the rightmost instance \c ch in \c s
    static char_type    *str_rchr(char_type const *s, char_type ch);
    /// \brief Finds the given substring \c sub in \c s
    static char_type    *str_str(char_type const *s, char_type const *sub);
    /// \brief Finds one of a set of characters in \c s
    static char_type    *str_pbrk(char_type const *s, char_type const *charSet);
    /// \brief \brief Returns a pointer to the end of the string
    static char_type    *str_end(char_type const *s);
/// @}

/// \name Locale management
/// @{
public:
    /// \brief Returns the locale information
    static int_type     get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData);
/// @}

/// \name Module Paths
/// @{
public:
    /// \brief Gets the full path name of the given module
    static size_type    get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer);
    /// \brief Gets the full path name of the directory of the given module
    static size_type    get_module_directory(HINSTANCE hModule, char_type *buffer, size_type cchBuffer);
    /// \brief Gets the full path name of the system directory
    static size_type    get_system_directory(char_type *buffer, size_type cchBuffer);
    /// \brief Gets the full path name of the windows directory
    static size_type    get_windows_directory(char_type *buffer, size_type cchBuffer);
/// @}

/// \name Dynamic Loading
/// @{
public:
    /// \brief Loads the given executable module
    static module_type  load_library(char_type const *name);
    /// \brief Closes the given executable module
    static bool_type    free_library(module_type hModule);
    /// \brief Retrieves the given symbol from the library
    static FARPROC      find_symbol(module_type hModule, char const *symbolName);
/// @}

/// \name Kernel object control
/// @{
public:
    /// \brief Closes the given operating system handle
    static bool_type    close_handle(handle_type h);
/// @}

/// \name Error
/// @{
public:
    /// \brief Gives the last error
    static error_type   get_last_error();
    /// \brief Sets the last error
    static void         set_last_error(error_type er = error_type());
/// @}

/// \name Environment
/// @{
public:
    /// \brief Gets an environment variable into the given buffer
    ///
    /// \param name The name of the variable to find
    /// \param buffer The buffer in which to write the variable. If this is NULL, then the required length is returned
    /// \param cchBuffer The size of the buffer, in characters
    static size_type    get_environment_variable(char_type const *name, char_type *buffer, size_type cchBuffer);
    /// Expands environment strings in \c src into \c buffer, up to a maximum \c cchDest characters
    static size_type    expand_environment_strings(char_type const *src, char_type *buffer, size_type cchBuffer);
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct system_traits;

struct system_traits_
{
public:
    typedef ws_size_t                   size_type;
    typedef ws_ptrdiff_t                difference_type;
    typedef system_traits_              class_type;
    typedef ws_int_t                    int_type;
    typedef ws_bool_t                   bool_type;
    typedef HINSTANCE                   module_type;
    typedef HANDLE                      handle_type;
    typedef DWORD                       error_type;

public:
    static bool_type close_handle(handle_type h)
    {
        return FALSE != ::CloseHandle(h);
    }

public:
    static bool_type free_library(module_type hModule)
    {
        return FALSE != ::FreeLibrary(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return ::GetProcAddress(hModule, symbolName);
    }

public:
    static error_type get_last_error()
    {
        return ::GetLastError();
    }

    static void set_last_error(error_type er)
    {
        ::SetLastError(er);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<ws_char_a_t>
{
public:
    typedef ws_char_a_t                 char_type;
    typedef ws_size_t                   size_type;
    typedef ws_ptrdiff_t                difference_type;
    typedef system_traits<char_type>    class_type;
    typedef ws_int_t                    int_type;
    typedef ws_bool_t                   bool_type;
    typedef HINSTANCE                   module_type;
    typedef HANDLE                      handle_type;
    typedef DWORD                       error_type;

public:
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyA(dest, src);
    }

    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::strncpy(dest, src, cch);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::lstrcatA(dest, src);
    }

    static char_type *str_n_cat(char_type *dest, char_type const *src, size_type cch)
    {
        return ::strncat(dest, src, cch);
    }

    static int_type str_compare(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpA(s1, s2);
    }

    static int_type str_compare_no_case(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpiA(s1, s2);
    }

    static int_type str_n_compare(char_type const *s1, char_type const *s2, size_type cch)
    {
        return ::strncmp(s1, s2, cch);
    }

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::lstrlenA(src));
    }

    static char_type *str_chr(char_type const *s, char_type ch)
    {
        return const_cast<char_type*>(::strchr(s, ch));
    }

    static char_type *str_rchr(char_type const *s, char_type ch)
    {
        return const_cast<char_type*>(::strrchr(s, ch));
    }

    static char_type *str_str(char_type const *s, char_type const *sub)
    {
        return const_cast<char_type*>(::strstr(s, sub));
    }

    static char_type *str_pbrk(char_type const *s, char_type const *charSet)
    {
        return const_cast<char_type*>(::strpbrk(s, charSet));
    }

    static char_type *str_end(char_type const *s)
    {
        WINSTL_ASSERT(NULL != s);

        for(; *s != '\0'; ++s)
        {}

        return const_cast<char_type*>(s);
    }

public:
    static int_type get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData)
    {
        return ::GetLocaleInfoA(locale, type, data, cchData);
    }

public:
    static size_type get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        if(0 == cchBuffer)
        {
            char_type   buff[1 + _MAX_PATH];

            return get_module_filename(hModule, &buff[0], STLSOFT_NUM_ELEMENTS(buff));
        }

        return ::GetModuleFileNameA(hModule, buffer, cchBuffer);
    }

    static size_type get_module_directory(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        size_type   cch =   get_module_filename(hModule, buffer, cchBuffer);

        if( 0 != cch &&
            cch < cchBuffer)
        {
            buffer[cch] = '\0';

            char_type   *s  =   str_rchr(buffer, '\\');

            if(NULL != s)
            {
                *s = '\0';

                cch = static_cast<size_type>(s - buffer);
            }
        }

        return cch;
    }

    static size_type get_system_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetSystemDirectoryA(buffer, cchBuffer);
    }

    static size_type get_windows_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetWindowsDirectoryA(buffer, cchBuffer);
    }

public:
    static module_type load_library(char_type const *name)
    {
        return ::LoadLibraryA(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return system_traits_::free_library(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return system_traits_::find_symbol(hModule, symbolName);
    }

    static bool_type close_handle(handle_type h)
    {
        return system_traits_::close_handle(h);
    }

public:
    static error_type get_last_error()
    {
        return system_traits_::get_last_error();
    }

    static void set_last_error(error_type er = error_type())
    {
        system_traits_::set_last_error(er);
    }

public:
    static size_type get_environment_variable(char_type const *name, char_type *buffer, size_type cchBuffer)
    {
        return ::GetEnvironmentVariableA(name, buffer, cchBuffer);
    }

    static size_type expand_environment_strings(char_type const *src, char_type *dest, size_type cch_dest)
    {
        return static_cast<size_type>(::ExpandEnvironmentStringsA(src, dest, cch_dest));
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<ws_char_w_t>
{
public:
    typedef ws_char_w_t                 char_type;
    typedef ws_size_t                   size_type;
    typedef ws_ptrdiff_t                difference_type;
    typedef system_traits<char_type>    class_type;
    typedef ws_int_t                    int_type;
    typedef ws_bool_t                   bool_type;
    typedef HINSTANCE                   module_type;
    typedef HANDLE                      handle_type;
    typedef DWORD                       error_type;

public:
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyW(dest, src);
    }

    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::wcsncpy(dest, src, cch);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::lstrcatW(dest, src);
    }

    static char_type *str_n_cat(char_type *dest, char_type const *src, size_type cch)
    {
        return ::wcsncat(dest, src, cch);
    }

    static int_type str_compare(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpW(s1, s2);
    }

    static int_type str_compare_no_case(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpiW(s1, s2);
    }

    static int_type str_n_compare(char_type const *s1, char_type const *s2, size_type cch)
    {
        return ::wcsncmp(s1, s2, cch);
    }

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::lstrlenW(src));
    }

    static char_type *str_chr(char_type const *s, char_type ch)
    {
        return const_cast<char_type*>(::wcschr(s, ch));
    }

    static char_type *str_rchr(char_type const *s, char_type ch)
    {
        return const_cast<char_type*>(::wcsrchr(s, ch));
    }

    static char_type *str_str(char_type const *s, char_type const *sub)
    {
        return const_cast<char_type*>(::wcsstr(s, sub));
    }

    static char_type *str_pbrk(char_type const *s, char_type const *charSet)
    {
        return const_cast<char_type*>(::wcspbrk(s, charSet));
    }

    static char_type *str_end(char_type const *s)
    {
        WINSTL_ASSERT(NULL != s);

        for(; *s != L'\0'; ++s)
        {}

        return const_cast<char_type*>(s);
    }

public:
    static int_type get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData)
    {
        return ::GetLocaleInfoW(locale, type, data, cchData);
    }
    
public:
    static size_type get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        if(0 == cchBuffer)
        {
            char_type   buff[1 + _MAX_PATH];
            size_type   cch =   get_module_filename(hModule, &buff[0], STLSOFT_NUM_ELEMENTS(buff));

            if(0 == str_compare(L"\\\\?\\", buff))
            {
                return 1 + CONST_NT_MAX_PATH;
            }
            else
            {
                return cch;
            }
        }

        return ::GetModuleFileNameW(hModule, buffer, cchBuffer);
    }

    static size_type get_module_directory(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        size_type   cch =   get_module_filename(hModule, buffer, cchBuffer);

        if( 0 != cch &&
            cch < cchBuffer)
        {
            buffer[cch] = '\0';

            char_type   *s  =   str_rchr(buffer, '\\');

            if(NULL != s)
            {
                *s = '\0';

                cch = static_cast<size_type>(s - buffer);
            }
        }

        return cch;
    }

    static size_type get_system_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetSystemDirectoryW(buffer, cchBuffer);
    }

    static size_type get_windows_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetWindowsDirectoryW(buffer, cchBuffer);
    }

public:
    static module_type load_library(char_type const *name)
    {
        return ::LoadLibraryW(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return system_traits_::free_library(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return system_traits_::find_symbol(hModule, symbolName);
    }

public:
    static bool_type close_handle(handle_type h)
    {
        return system_traits_::close_handle(h);
    }

public:
    static error_type get_last_error()
    {
        return system_traits_::get_last_error();
    }

    static void set_last_error(error_type er = error_type())
    {
        system_traits_::set_last_error(er);
    }

public:
    static size_type get_environment_variable(char_type const *name, char_type *buffer, size_type cchBuffer)
    {
        return ::GetEnvironmentVariableW(name, buffer, cchBuffer);
    }

    static size_type expand_environment_strings(char_type const *src, char_type *dest, size_type cch_dest)
    {
        return static_cast<size_type>(::ExpandEnvironmentStringsW(src, dest, cch_dest));
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/system_traits_unittest_.h"
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

#endif /* WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

/* ////////////////////////////////////////////////////////////////////// */