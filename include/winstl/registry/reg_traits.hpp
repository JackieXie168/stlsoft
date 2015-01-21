/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/reg_traits.hpp (formerly winstl_reg_traits.h)
 *
 * Purpose:     Contains the reg_traits class template, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Created:     19th January 2002
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


/// \file winstl/registry/reg_traits.hpp
/// \brief [C++ only] Definition of the \link winstl::reg_traits reg_traits\endlink class template used throughout the \ref group__library__windows_registry "Windows Registry" Library.

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_TRAITS_MAJOR    3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_TRAITS_MINOR    2
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_TRAITS_REVISION 3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_TRAITS_EDIT     60
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_DEFS
# include <winstl/registry/defs.hpp>             // The WinSTL reg API standard types
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_DEFS */

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

/* ////////////////////////////////////////////////////////////////////// */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** \brief Traits for accessing the correct registry functions for a given character type
 *
 * \ingroup group__library__windows_registry
 *
 * reg_traits is a traits class for determining the correct registry
 * structures and functions for a given character type.
 *
 * \param C The character type
 */
template <ss_typename_param_k C>
struct reg_traits
{
/// \name Member Types
/// @{
public:
    /// \brief The character type
    typedef C               char_type;
    /// \brief The size type
    typedef ws_size_t       size_type;
    /// \brief The difference type
    typedef ws_ptrdiff_t    difference_type;
    /// \brief The registry key type
    typedef HKEY            hkey_type;
    /// \brief The string type
    typedef reg_string_t    string_type;        // Placeholder only
    /// \brief The time type
    typedef FILETIME        time_type;
    /// \brief The API result type (LONG)
    typedef ws_long_t       result_type;
/// @}

/// \name General string handling
/// @{
public:
    // General string handling
    /// \brief Copies the contents of \c src to \c dest, up to cch \c characters
    static char_type    *str_n_copy(char_type *dest, char_type const *src, size_type cch);
# if 0
    /// \brief Copies the contents of \c src to \c dest
    static char_type    *str_copy(char_type *dest, char_type const *src);
    /// \brief Appends the contents of \c src to \c dest
    static char_type    *str_cat(char_type *dest, char_type const *src);
    /// \brief Comparies the contents of \c src and \c dest
    static ws_int_t     str_compare(char_type *dest, char_type const *src);
# endif /* 0 */
    /// \brief Evaluates the length of \c src
    static size_type    str_len(char_type const *src);
/// @}


    // Registry names

# if 0
    /// \brief Appends a registry path separator to \c path if one does not exist
    static char_type    *ensure_subkey_end(char_type *path);
# endif /* 0 */

    /// \brief Expands environment strings in \c src into \c dest, up to a maximum \c cchDest characters
    static size_type    expand_env_strings(char_type const *src, char_type *dest, size_type cch_dest);

    /// \brief Duplicates a registry key
    static hkey_type    key_dup(        hkey_type       hkey
                                    ,   REGSAM          samDesired  =   KEY_ALL_ACCESS
                                    ,   result_type     *result     =   NULL);
    /// \brief Opens a registry sub-key
    static result_type  reg_open_key(   hkey_type       hkey,
                                        char_type const *sub_key_name,
                                        hkey_type       *hkey_result,
                                        REGSAM          samDesired = KEY_ALL_ACCESS);
    /// \brief Opens a registry sub-key
    static result_type  reg_create_key( hkey_type       hkey,
                                        char_type const *sub_key_name,
                                        hkey_type       *hkey_result,
                                        REGSAM          samDesired = KEY_ALL_ACCESS);
    static result_type  reg_create_key( hkey_type       hkey,
                                        char_type const *sub_key_name,
                                        hkey_type       *hkey_result,
                                        ws_bool_t       &bCreated,
                                        REGSAM          samDesired = KEY_ALL_ACCESS);
    /// \brief Destroys a registry sub-key
    static result_type  reg_delete_key( hkey_type       hkey,
                                        char_type const *sub_key_name);
    /// \brief Queries a registry key value
    static result_type  reg_query_value(hkey_type       hkey,
                                        char_type const *valueName,
                                        ws_dword_t      &valueType,
                                        void            *data,
                                        size_type       &cbData);
    /// \brief Sets the value of the named value.
    static result_type  reg_set_value(  hkey_type       hkey
                                    ,   char_type const *valueName
                                    ,   ws_dword_t      valueType
                                    ,   void const      *data
                                    ,   size_type       cbData);
    /// \brief Deletes the named value.
    static result_type  reg_delete_value(hkey_type      hkey
                                    ,   char_type const *valueName);

    /// \brief Queries a registry key's characteristics
    static result_type  reg_query_info( hkey_type       hkey,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        ws_uint_t       *c_sub_keys,
                                        size_type       *cch_sub_key_max,
                                        size_type       *cch_key_class_max,
                                        ws_uint_t       *c_values,
                                        size_type       *cch_valueName_max,
                                        size_type       *cb_value_data_max,
                                        size_type       *cb_security_descriptor_max,
                                        time_type       *time_last_write);
    /// \brief Enumerates a registry key's sub-keys
    static result_type  reg_enum_key(   hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        time_type       *time_last_write    =   NULL);
    /// \brief [DEPRECATED] Enumerates a registry key's sub-keys
    ///
    /// \deprecated This is deprecated in favour of reg_enum_key(hkey_type, ws_dword_t, char_type*, size_type*, time_type *)
    static result_type  reg_enum_key(   hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        time_type       *time_last_write);
    /// \brief Enumerates a registry key's values
    static result_type  reg_enum_value( hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName,
                                        ws_dword_t      *valueType,
                                        void            *data,
                                        size_type       &cbData);
    /// \brief Enumerates a registry key's values
    static result_type  reg_enum_value( hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName);
}

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct reg_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct reg_traits<ws_char_a_t>
{
public:
    typedef ws_char_a_t         char_type;
    typedef ws_size_t           size_type;
    typedef ws_ptrdiff_t        difference_type;
    typedef HKEY                hkey_type;
    typedef reg_string_a_t      string_type;
    typedef FILETIME            time_type;
    typedef ws_long_t           result_type;

public:
    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::strncpy(dest, src, cch);
    }

#if 0
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyA(dest, src);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::lstrcatA(dest, src);
    }

    static ws_int_t str_compare(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpA(s1, s2);
    }
#endif /* 0 */

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::lstrlenA(src));
    }

#if 0
    static char_type *ensure_subkey_end(char_type *path)
    {
        char_type   *end;

        for(end = path; *end != '\0'; ++end)
        {}

        if( path < end &&
            *(end - 1) != '\\')
        {
            *end        =   '\\';
            *(end + 1)  =   '\0';
        }

        return path;
    }
#endif /* 0 */

    static size_type expand_env_strings(char_type const *src, char_type *dest, size_type cch_dest)
    {
        return static_cast<size_type>(::ExpandEnvironmentStringsA(src, dest, cch_dest));
    }

    static hkey_type key_dup(hkey_type hkey, REGSAM samDesired, result_type *result = NULL)
    {
        hkey_type   hkeyDup;
        result_type res = ::RegOpenKeyExA(hkey, "", 0, samDesired, &hkeyDup);

        if(ERROR_SUCCESS != res)
        {
            hkeyDup = NULL;
        }

        if(NULL != result)
        {
            *result = res;
        }

        return hkeyDup;
    }

    static result_type reg_open_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        return ::RegOpenKeyExA(hkey, sub_key_name, 0, samDesired, hkey_result);
    }

    static result_type reg_create_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        return ::RegCreateKeyExA(hkey, sub_key_name, 0, NULL, 0, samDesired, NULL, hkey_result, NULL);
    }

    static result_type reg_create_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, ws_bool_t &bCreated, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        DWORD       disposition;
        result_type res =   ::RegCreateKeyExA(hkey, sub_key_name, 0, NULL, 0, samDesired, NULL, hkey_result, &disposition);

        bCreated = (ERROR_SUCCESS == res) && (REG_CREATED_NEW_KEY == disposition);

        return res;
    }

    static result_type reg_delete_key(hkey_type hkey, char_type const *sub_key_name)
    {
        return ::RegDeleteKeyA(hkey, sub_key_name);
    }

    static result_type reg_query_value(hkey_type hkey, char_type const *valueName, ws_dword_t &valueType, void *data, size_type &cbData)
    {
        return ::RegQueryValueExA(hkey, valueName, NULL, &valueType, static_cast<LPBYTE>(data), reinterpret_cast<LPDWORD>(&cbData));
    }

    static result_type reg_set_value(hkey_type hkey, char_type const *valueName, ws_dword_t valueType, void const *data, size_type cbData)
    {
        return ::RegSetValueExA(hkey, valueName, 0, valueType, static_cast<BYTE const*>(data), cbData);
    }

    static result_type reg_delete_value(hkey_type hkey, char_type const *valueName)
    {
        return ::RegDeleteValueA(hkey, valueName);
    }

    static result_type reg_query_info(  hkey_type       hkey,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        ws_uint_t       *c_sub_keys,
                                        size_type       *cch_sub_key_max,
                                        size_type       *cch_key_class_max,
                                        ws_uint_t       *c_values,
                                        size_type       *cch_valueName_max,
                                        size_type       *cb_value_data_max,
                                        size_type       *cb_security_descriptor_max,
                                        time_type       *time_last_write)
    {
        return ::RegQueryInfoKeyA(hkey, key_class, reinterpret_cast<LPDWORD>(cch_key_class), NULL, reinterpret_cast<LPDWORD>(c_sub_keys), reinterpret_cast<LPDWORD>(cch_sub_key_max), reinterpret_cast<LPDWORD>(cch_key_class_max), reinterpret_cast<LPDWORD>(c_values), reinterpret_cast<LPDWORD>(cch_valueName_max), reinterpret_cast<LPDWORD>(cb_value_data_max), reinterpret_cast<LPDWORD>(cb_security_descriptor_max), time_last_write);
    }

    static result_type reg_enum_key(    hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        time_type       *time_last_write    =   NULL)
    {
        return ::RegEnumKeyExA(hkey, index, key_name, reinterpret_cast<LPDWORD>(cch_key_name), NULL, NULL, NULL, time_last_write);
    }

    static result_type reg_enum_key(    hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        time_type       *time_last_write)
    {
        return ::RegEnumKeyExA(hkey, index, key_name, reinterpret_cast<LPDWORD>(cch_key_name), NULL, key_class, reinterpret_cast<LPDWORD>(cch_key_class), time_last_write);
    }

    static result_type reg_enum_value(  hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName,
                                        ws_dword_t      *valueType,
                                        void            *data,
                                        size_type       &cbData)
    {
        return ::RegEnumValueA(hkey, index, valueName, reinterpret_cast<LPDWORD>(cch_valueName), NULL, valueType, reinterpret_cast<LPBYTE>(data), reinterpret_cast<LPDWORD>(&cbData));
    }

    static result_type reg_enum_value(  hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName)
    {
        return ::RegEnumValueA(hkey, index, valueName, reinterpret_cast<LPDWORD>(cch_valueName), NULL, NULL, NULL, NULL);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct reg_traits<ws_char_w_t>
{
public:
    typedef ws_char_w_t         char_type;
    typedef ws_size_t           size_type;
    typedef ws_ptrdiff_t        difference_type;
    typedef HKEY                hkey_type;
    typedef reg_string_w_t      string_type;
    typedef FILETIME            time_type;
    typedef ws_long_t           result_type;

public:
    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::wcsncpy(dest, src, cch);
    }

#if 0
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::lstrcpyW(dest, src);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::lstrcatW(dest, src);
    }

    static ws_int_t str_compare(char_type const *s1, char_type const *s2)
    {
        return ::lstrcmpW(s1, s2);
    }
#endif /* 0 */

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::lstrlenW(src));
    }

#if 0
    static char_type *ensure_subkey_end(char_type *path)
    {
        char_type   *end;

        for(end = path; *end != L'\0'; ++end)
        {}

        if( path < end &&
            *(end - 1) != L'\\')
        {
            *end        =   L'\\';
            *(end + 1)  =   L'\0';
        }

        return path;
    }
#endif /* 0 */

    static size_type expand_env_strings(char_type const *src, char_type *dest, size_type cch_dest)
    {
        return static_cast<size_type>(::ExpandEnvironmentStringsW(src, dest, cch_dest));
    }

    static hkey_type key_dup(hkey_type hkey, REGSAM samDesired, result_type *result = NULL)
    {
        hkey_type   hkeyDup;
        result_type res = ::RegOpenKeyExW(hkey, L"", 0, samDesired, &hkeyDup);

        if(ERROR_SUCCESS != res)
        {
            hkeyDup = NULL;
        }

        if(NULL != result)
        {
            *result = res;
        }

        return hkeyDup;
    }

    static result_type reg_open_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        return ::RegOpenKeyExW(hkey, sub_key_name, 0, samDesired, hkey_result);
    }

    static result_type reg_create_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        return ::RegCreateKeyExW(hkey, sub_key_name, 0, NULL, 0, samDesired, NULL, hkey_result, NULL);
    }

    static result_type reg_create_key(hkey_type hkey, char_type const *sub_key_name, hkey_type *hkey_result, ws_bool_t &bCreated, REGSAM samDesired = KEY_ALL_ACCESS)
    {
        DWORD       disposition;
        result_type res =   ::RegCreateKeyExW(hkey, sub_key_name, 0, NULL, 0, samDesired, NULL, hkey_result, &disposition);

        bCreated = (ERROR_SUCCESS == res) && (REG_CREATED_NEW_KEY == disposition);

        return res;
    }

    static result_type reg_delete_key(hkey_type hkey, char_type const *sub_key_name)
    {
        return ::RegDeleteKeyW(hkey, sub_key_name);
    }

    static result_type reg_query_value(hkey_type hkey, char_type const *valueName, ws_dword_t &valueType, void *data, size_type &cbData)
    {
        return ::RegQueryValueExW(hkey, valueName, NULL, &valueType, static_cast<LPBYTE>(data), reinterpret_cast<LPDWORD>(&cbData));
    }

    static result_type reg_set_value(hkey_type hkey, char_type const *valueName, ws_dword_t valueType, void const *data, size_type cbData)
    {
        return ::RegSetValueExW(hkey, valueName, 0, valueType, static_cast<BYTE const*>(data), cbData);
    }

    static result_type reg_delete_value(hkey_type hkey, char_type const *valueName)
    {
        return ::RegDeleteValueW(hkey, valueName);
    }

    static result_type reg_query_info(  hkey_type       hkey,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        ws_uint_t       *c_sub_keys,
                                        size_type       *cch_sub_key_max,
                                        size_type       *cch_key_class_max,
                                        ws_uint_t       *c_values,
                                        size_type       *cch_valueName_max,
                                        size_type       *cb_value_data_max,
                                        size_type       *cb_security_descriptor_max,
                                        time_type       *time_last_write)
    {
        return ::RegQueryInfoKeyW(hkey, key_class, reinterpret_cast<LPDWORD>(cch_key_class), NULL, reinterpret_cast<LPDWORD>(c_sub_keys), reinterpret_cast<LPDWORD>(cch_sub_key_max), reinterpret_cast<LPDWORD>(cch_key_class_max), reinterpret_cast<LPDWORD>(c_values), reinterpret_cast<LPDWORD>(cch_valueName_max), reinterpret_cast<LPDWORD>(cb_value_data_max), reinterpret_cast<LPDWORD>(cb_security_descriptor_max), time_last_write);
    }

    static result_type reg_enum_key(    hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        time_type       *time_last_write    =   NULL)
    {
        return ::RegEnumKeyExW(hkey, index, key_name, reinterpret_cast<LPDWORD>(cch_key_name), NULL, NULL, NULL, time_last_write);
    }

    static result_type reg_enum_key(    hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *key_name,
                                        size_type       *cch_key_name,
                                        char_type       *key_class,
                                        size_type       *cch_key_class,
                                        time_type       *time_last_write)
    {
        return ::RegEnumKeyExW(hkey, index, key_name, reinterpret_cast<LPDWORD>(cch_key_name), NULL, key_class, reinterpret_cast<LPDWORD>(cch_key_class), time_last_write);
    }

    static result_type reg_enum_value(  hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName,
                                        ws_dword_t      *valueType,
                                        void            *data,
                                        size_type       &cbData)
    {
        return ::RegEnumValueW(hkey, index, valueName, reinterpret_cast<LPDWORD>(cch_valueName), NULL, valueType, reinterpret_cast<LPBYTE>(data), reinterpret_cast<LPDWORD>(&cbData));
    }

    static result_type reg_enum_value(  hkey_type       hkey,
                                        ws_dword_t      index,
                                        char_type       *valueName,
                                        size_type       *cch_valueName)
    {
        return ::RegEnumValueW(hkey, index, valueName, reinterpret_cast<LPDWORD>(cch_valueName), NULL, NULL, NULL, NULL);
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS */

/* ////////////////////////////////////////////////////////////////////// */