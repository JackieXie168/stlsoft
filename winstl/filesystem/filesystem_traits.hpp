/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/filesystem_traits.hpp (originally winstl_filesystem_traits.h)
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     1st June 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/** \file winstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++ only] Definition of the winstl::filesystem_traits traits
 *  class.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR       4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION    1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT        90
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_MEMORY_AUTO_BUFFER */
#include <string.h>
#include <wchar.h>

/* /////////////////////////////////////////////////////////////////////////////
 * FindVolume API declarations
 *
 * The FindVolume API is not visible in the Windows headers unless _WIN32_WINNT
 * is defined as 0x0500 or greater. Where this definition is not present, the
 * functions are declared here, unless _WINSTL_NO_FINDVOLUME_API is defined.
 *
 * Where _WINSTL_NO_FINDVOLUME_API is defined, the requisite members of the
 * traits classes are undeclared.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#if !defined(_WINSTL_NO_FINDVOLUME_API)
# if !defined(_WIN32_WINNT) || \
     (_WIN32_WINNT < 0x0500) || \
     !defined(FindFirstVolume) || \
     !defined(FindNextVolume)

#  define WINSTL_FINDVOLUME_API_NOT_DECLARED

HANDLE WINAPI FindFirstVolumeA(
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

HANDLE WINAPI FindFirstVolumeW(
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindNextVolumeA(
  HANDLE hFindVolume,      // volume search handle
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindNextVolumeW(
  HANDLE hFindVolume,      // volume search handle
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindVolumeClose(
    HANDLE hFindVolume
    );

#  endif
# endif /* !_WINSTL_NO_FINDVOLUME_API */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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
 * Classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// \brief Traits for accessing the correct file-system functions for a given character type
///
/// \ingroup group__library__file_system
///
/// filesystem_traits is a traits class for determining the correct file-system
/// structures and functions for a given character type.
///
/// \param C The character type
template <ss_typename_param_k C>
struct filesystem_traits
{
/// \name Types
/// @{
public:
    /// The character type
    typedef C                                       char_type;
    /// The size type
    typedef ws_size_t                               size_type;
    /// The difference type
    typedef ws_ptrdiff_t                            difference_type;
    /// The find data type
    typedef WIN32_FIND_DATA                         find_data_type;     // Placeholder only
    /// The stat data type
    typedef WIN32_FIND_DATA                         stat_data_type;
    /// The fstat data type
    typedef BY_HANDLE_FILE_INFORMATION              fstat_data_type;
    /// The current instantion of the type
    typedef filesystem_traits<C>                    class_type;

    /// The (signed) integer type
    typedef ws_int_t                                int_type;
    /// The Boolean type
    typedef ws_bool_t                               bool_type;
    /// The type of a system file handle
    typedef HANDLE                                  file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef HINSTANCE                               module_type;
    /// The type of system error codes
    typedef DWORD                                   error_type;
/// @}

/// \name Constants
/// @{
public:
    enum
    {
        maxPathLength   =   1 + _MAX_PATH       //!< The maximum length of a path for the current file system
    };
/// @}

/// \name General string handling
/// @{
public:
    /// Copies the contents of \c src to \c dest
    static char_type    *str_copy(char_type *dest, char_type const *src);
    /// Copies the contents of \c src to \c dest, up to cch \c characters
    static char_type    *str_n_copy(char_type *dest, char_type const *src, size_type cch);
    /// Appends the contents of \c src to \c dest
    static char_type    *str_cat(char_type *dest, char_type const *src);
    /// Appends the contents of \c src to \c dest, up to cch \c characters
    static char_type    *str_n_cat(char_type *dest, char_type const *src, size_type cch);
    /// Comparies the contents of \c src and \c dest
    static int_type     str_compare(char_type const *s1, char_type const *s2);
    /// Comparies the contents of \c src and \c dest in a case-insensitive fashion
    static int_type     str_compare_no_case(char_type const *s1, char_type const *s2);
    /// Comparies the contents of \c src and \c dest up to \c cch characters
    static int_type     str_n_compare(char_type const *s1, char_type const *s2, size_type cch);
    /// Evaluates the length of \c src
    static size_type    str_len(char_type const *src);
    /// Finds the given character \c ch in \c s
    static char_type    *str_chr(char_type const *s, char_type ch);
    /// Finds the rightmost instance \c ch in \c s
    static char_type    *str_rchr(char_type const *s, char_type ch);
    /// Finds the given substring \c sub in \c s
    static char_type    *str_str(char_type const *s, char_type const *sub);
    /// Finds one of a set of characters in \c s
    static char_type    *str_pbrk(char_type const *s, char_type const *charSet);
/// @}

/// \name Locale management
/// @{
public:
    static int_type     get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData);
/// @}

/// \name File-system entry names
/// @{
public:
    /// Appends a path name separator to \c dir if one does not exist
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type    *ensure_dir_end(char_type *dir);
    /// Removes the path name separator from the end of \c dir, if it has it
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type    *remove_dir_end(char_type *dir);
    /// Returns \c true if \c dir has trailing path name separator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static bool_type    has_dir_end(char_type const *dir);

    /// Returns \c true if dir is \c "." or \c ".."
    static bool_type    is_dots(char_type const *dir);
    /// Returns \c true if path is rooted, i.e. it begins with root directory
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// root character sequence(s).
    static bool_type    is_path_rooted(char_type const *path);
    /// Returns \c true if path is an absolute path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// absolute path character sequence(s).
    static bool_type    is_path_absolute(char_type const *path);
    /// Returns \c true if path is a UNC path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the UNC character sequence(s).
    static bool_type    is_path_UNC(char_type const *path);
    /// Returns \c true if the character is a path-name separator
    ///
    /// \note Both \c / and \c \\ are interpreted as a path name separator
    static bool_type    is_path_name_separator(char_type ch);

    /// Returns the path separator
    ///
    /// This is the separator that is used to separate multiple paths on the operating system. On UNIX it is ':'
    static char_type    path_separator();
    /// Returns the path name separator
    ///
    /// This is the separator that is used to separate parts of a path on the operating system. On UNIX it is '/'
    static char_type    path_name_separator();
    /// Returns the wildcard pattern that represents all possible matches
    ///
    /// \note On Win32 it is '*.*'
    static char_type const *pattern_all();
    /// The maximum length of a path on the file-system
    ///
    /// \note Because not all systems support fixed maximum path lengths, the value of this function is notionally dynamic
    static size_type    path_max();
    /// Gets the full path name into the given buffer, returning a pointer to the file-part
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile);
    /// Gets the full path name into the given buffer
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
    /// Gets the short path name into the given buffer
    static size_type    get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
    /// Gets the short path name into the given buffer
    ///
    /// \deprecated The other overload is now the preferred form
    static size_type    get_short_path_name(char_type const *fileName, char_type *buffer, size_type cchBuffer);
/// @}

/// \name File-system enumeration
/// @{
public:
    // FindFirstFile/FindNextFile API

    /// Initiate a file-system search
    static HANDLE       find_first_file(char_type const *spec, find_data_type *findData);
#if _WIN32_WINNT >= 0x0400
    /// Initiate a file-system search - NT4+-only
    static HANDLE       find_first_file_ex(char_type const *spec, FINDEX_SEARCH_OPS flags, find_data_type *findData);
#endif /* _WIN32_WINNT >= 0x0400 */
    /// Advance a given file-system search
    static bool_type    find_next_file(HANDLE h, find_data_type *findData);
    /// Closes the handle of the file-system search
    static void         find_file_close(HANDLE h);

    // FindFirstVolume/FindNextVolume API

#ifndef _WINSTL_NO_FINDVOLUME_API
    /// Initiate a file-system volume search
    static HANDLE       find_first_volume(char_type *volume_name, size_type cch_volume_name);
    /// Advance a given file-system volume search
    static bool_type    find_next_volume(HANDLE h, char_type *volume_name, size_type cch_volume_name);
    /// Closes the handle of the file-volume search
    static void         find_volume_close(HANDLE h);
#endif // !_WINSTL_NO_FINDVOLUME_API
/// @}

/// \name Module Paths
/// @{
public:
    /// Gets the full path name of the given module
    static size_type    get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer);
    /// Gets the full path name of the system directory
    static size_type    get_system_directory(char_type *buffer, size_type cchBuffer);
    /// Gets the full path name of the windows directory
    static size_type    get_windows_directory(char_type *buffer, size_type cchBuffer);
/// @}

/// \name Dynamic Loading
/// @{
public:
    /// Loads the given executable module
    static module_type  load_library(char_type const *name);
    /// Closes the given executable module
    static bool_type    free_library(module_type hModule);
    /// Retrieves the given symbol from the library
    static FARPROC      find_symbol(module_type hModule, char const *symbolName);
/// @}

/// \name File-system control
/// @{
public:
    /// Sets the current directory to \c dir
    static bool_type    set_current_directory(char_type const *dir);
    /// Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    static size_type    get_current_directory(size_type cchBuffer, char_type *buffer);
/// @}

/// \name File-system state
/// @{
public:
    /// Returns whether a file exists or not
    static bool_type    file_exists(char_type const *path);
    /// Returns whether the given path represents a file
    static bool_type    is_file(char_type const *path);
    /// Returns whether the given path represents a directory
    static bool_type    is_directory(char_type const *path);
    /// Gets the information for a particular file system entry
    static bool_type    stat(char_type const *path, stat_data_type *stat_data);
    /// Gets the information for a particular open file
    static bool_type    fstat(file_handle_type fd, fstat_data_type *fstat_data);

    /// Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const *stat_data);
    static bool_type    is_file(fstat_data_type const *stat_data);
    /// Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const *stat_data);
    static bool_type    is_directory(fstat_data_type const *stat_data);
    /// Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const *stat_data);
    static bool_type    is_link(fstat_data_type const *stat_data);
    /// Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const *stat_data);
    static bool_type    is_readonly(fstat_data_type const *stat_data);

    /// Indicates whether the given drive currently exists on the system
    static bool_type    drive_exists(char_type driveLetter);
    /// Returns a status code denoting the type of the drive
    ///
    /// \return One of the return codes of the GetDriveType() API function
    static DWORD        get_drive_type(char_type driveLetter);
/// @}

/// \name File-system control
/// @{
public:
    /// Creates a directory
    static bool_type    create_directory(char_type const *dir);
    /// Creates a directory, with the given security attributes
    static bool_type    create_directory(char_type const *dir, LPSECURITY_ATTRIBUTES lpsa);
    /// Deletes a directory
    static bool_type    remove_directory(char_type const *dir);

    /// Delete a file
    static bool_type    unlink_file(char_type const *file);
    /// Delete a file
    ///
    /// \deprecated Users should use unlink_file()
    static bool_type    delete_file(char_type const *file);
    /// Rename a file
    static bool_type    rename_file(char_type const *currentName, char_type const *newName);
    /// Copy a file
    static bool_type    copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false);

    /// Create / open a file
    static file_handle_type create_file(char_type const *fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, HANDLE hTemplateFile);
    /// Closes the given operating system handle
    static bool_type        close_handle(HANDLE h);
    /// Closes the given file handle
    static bool_type        close_file(file_handle_type h);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// Gets the size of the file
    static ws_uint64_t      get_file_size(file_handle_type h);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
/// @}

/// \name Error
/// @{
public:
    /// Gives the last error
    static error_type   get_last_error();
    /// Sets the last error
    static void         set_last_error(error_type er = error_type());
/// @}

/// \name Environment
/// @{
public:
    /// Gets an environment variable into the given buffer
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
struct filesystem_traits;

struct filesystem_traits_
{
public:
    /// The size type
    typedef ws_size_t                   size_type;
    /// The difference type
    typedef ws_ptrdiff_t                difference_type;
    // The current instantion of the type
    typedef filesystem_traits_          class_type;
    /// The fstat data type
    typedef BY_HANDLE_FILE_INFORMATION  fstat_data_type;

    /// The (signed) integer type
    typedef ws_int_t                    int_type;
    /// The Boolean type
    typedef ws_bool_t                   bool_type;
    /// The type of a system file handle
    typedef HANDLE                      file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef HINSTANCE                   module_type;
    /// The type of system error codes
    typedef DWORD                       error_type;

    enum
    {
        maxPathLength   =   1 + _MAX_PATH       //!< The maximum length of a path for the current file system
    };

public:
    static bool_type close_handle(HANDLE h)
    {
        return FALSE != ::CloseHandle(h);
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type *fstat_data)
    {
        return FALSE != ::GetFileInformationByHandle(fd, fstat_data);
    }

    static bool_type is_file(fstat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(fstat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(fstat_data_type const * /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(fstat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    static bool_type free_library(module_type hModule)
    {
        return FALSE != ::FreeLibrary(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return ::GetProcAddress(hModule, symbolName);
    }


#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static ws_uint64_t  get_file_size(file_handle_type h)
    {
        DWORD   dwHigh;
        DWORD   dwLow   =   ::GetFileSize(h, &dwHigh);

        if( 0xFFFFFFFF == dwLow &&
            ERROR_SUCCESS != ::GetLastError())
        {
            dwHigh = 0xFFFFFFFF;
        }

        return (static_cast<ws_uint64_t>(dwHigh) << 32) | dwLow;
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

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
struct filesystem_traits<ws_char_a_t>
{
public:
    typedef ws_char_a_t                             char_type;
    typedef ws_size_t                               size_type;
    typedef ws_ptrdiff_t                            difference_type;
    typedef WIN32_FIND_DATAA                        find_data_type;
    typedef WIN32_FIND_DATAA                        stat_data_type;
    typedef BY_HANDLE_FILE_INFORMATION              fstat_data_type;
    typedef filesystem_traits<char_type>            class_type;
    /// The (signed) integer type
    typedef ws_int_t                                int_type;
    /// The Boolean type
    typedef ws_bool_t                               bool_type;
    /// The type of a system file handle
    typedef HANDLE                                  file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef HINSTANCE                               module_type;
    /// The type of system error codes
    typedef DWORD                                   error_type;
private:
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200
    typedef stlsoft_ns_qual(auto_buffer)<char_type> buffer_type_;
#endif /* compiler */
public:

    enum
    {
        maxPathLength   =   1 + _MAX_PATH       //!< The maximum length of a path for the current file system
    };

public:
    // General string handling
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

    // Locale management
    static int_type get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData)
    {
        return GetLocaleInfoA(locale, type, data, cchData);
    }

    // File-system entry names
    static char_type *ensure_dir_end(char_type *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        char_type   *end;

        for(end = dir; *end != '\0'; ++end)
        {}

        if( dir < end &&
            !is_path_name_separator(*(end - 1)))
        {
            *end        =   path_name_separator();
            *(end + 1)  =   '\0';
        }

        return dir;
    }

    static char_type *remove_dir_end(char_type *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        char_type   *end;

        for(end = dir; *end != '\0'; ++end)
        {}

        if( dir < end &&
            is_path_name_separator(*(end - 1)))
        {
            *(end - 1)  =   '\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == '\0' ||
                    (    dir[1] == '.' &&
                        dir[2] == '\0'));
    }

    static bool_type is_path_rooted(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_name_separator(*path) || is_path_absolute(path);
    }

    static bool_type is_path_absolute(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        size_type len = str_len(path);

        return  is_path_UNC(path) ||
                (   (2 < len) &&
                    (':' == path[1]) &&
                    is_path_name_separator(path[2]));
    }

    static bool_type is_path_UNC(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        return ('\\' == path[0] && '\\' == path[1]);
    }

    static bool_type is_path_name_separator(char_type ch)
    {
        return '\\' == ch || '/' == ch;
    }

    static char_type path_separator()
    {
        return ';';
    }

    static char_type path_name_separator()
    {
        return '\\';
    }

    static char_type const *pattern_all()
    {
        return "*.*";
    }

    static size_type path_max()
    {
        return 1 + _MAX_PATH;
    }

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
    static ws_dword_t get_full_path_name(char_type const *fileName, ws_dword_t cchBuffer, char_type *buffer, char_type **ppFile)
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same, so it's not a good idea to do this for ANSI compilation", fileName != buffer);

        if('"' == *fileName)
        {
            // This can only work if ...
            const size_type         len     =   class_type::str_len(fileName);
            char_type const *const  closing =   class_type::str_chr(fileName + 1, '"');

            // ... 1. the only other double quote is at the end of the string, and ...
            if( NULL != closing &&
                closing - fileName == static_cast<ptrdiff_t>(len - 1))
            {
                ws_dword_t  res = class_type::get_full_path_name(fileName + 1, cchBuffer, buffer, ppFile);

                // ... 2. the front-quote skipped string can be converted, and ...
                if( 0 != res &&
                    res < cchBuffer)
                {
                    WINSTL_ASSERT('\0' == buffer[res]);

                    char_type *const    closing2    =   class_type::str_chr(buffer, '"');

                    // ... 3. the front-quote skipped converted string contains a single trailing quote
                    if( NULL != closing2 &&
                        closing2 - buffer == static_cast<ptrdiff_t>(res - 1))
                    {
                        buffer[res-- - 1] = '\0';

                        return res;
                    }
                }
            }
        }

        return ::GetFullPathNameA(fileName, cchBuffer, buffer, ppFile);
    }
#else /* ? compiler */
private:
    static size_type get_full_path_name_impl2(char_type const *fileName, size_type len, char_type *buffer, size_type cchBuffer, char_type **ppFile)
    {
        size_type   r   =   ::GetFullPathNameA(fileName, cchBuffer, buffer, ppFile);

        if( 0 != r &&
            NULL != buffer &&
            r > cchBuffer)
        {
            buffer_type_    buffer_(1 + r);

            if(0 == buffer_.size())
            {
                *ppFile = NULL;

                return 0;
            }
            else
            {
                char_type   *pFile2;
                size_type   r2  =   get_full_path_name_impl2(fileName, len, &buffer_[0], buffer_.size(), &pFile2);

                if(0 == r2)
                {
                    return 0;
                }
                else
                {
                    if(r2 > cchBuffer)
                    {
                        r2 = cchBuffer;
                    }

                    str_n_copy(&buffer[0], &buffer_[0], r2);
                    if( NULL != pFile2 &&
                        r2 == (r - 1) &&
                        static_cast<size_type>(pFile2 - &buffer_[0]) < r2)
                    {
                        *ppFile = &buffer[0] + (pFile2 - &buffer_[0]);
                    }
                    else
                    {
                        *ppFile = NULL;
                    }

                    return r2;
                }
            }
        }
        else
        {
            return r;
        }
    }

    static size_type get_full_path_name_impl(char_type const *fileName, size_type len, char_type *buffer, size_type cchBuffer, char_type **ppFile)
    {
        WINSTL_ASSERT(len > 0);

        if('\0' != fileName[len])
        {
            buffer_type_    fileName_(1 + (len - 1));

            // May be being compiled absent exception support, so need to check the
            // file path buffers. (This _could_ be done with a compile-time #ifdef,
            // but it's best not, since some translators support exceptions but yet
            // don't throw on mem exhaustion, and in any case a user could change
            // ::new)
            if(0 == fileName_.size())
            {
                set_last_error(ERROR_OUTOFMEMORY);

                return 0;
            }
            else
            {
                fileName_[len] = '\0';

                return get_full_path_name_impl( str_n_copy(&fileName_[0], fileName, len)
                                            ,   len
                                            ,   buffer
                                            ,   cchBuffer
                                            ,   ppFile);
            }
        }
        else
        {
            return get_full_path_name_impl2(fileName, len, buffer, cchBuffer, ppFile);
        }
    }

public:
    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile)
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same, so it's not a good idea to do this for ANSI compilation", fileName != buffer);

        size_type       n   =   0;
        const size_type len =   class_type::str_len(fileName);

        if(NULL != class_type::str_pbrk(fileName, "<>|*?"))
        {
            ::SetLastError(ERROR_INVALID_NAME);

            return 0;
        }

        if('"' == *fileName)
        {
            // This can only work if:
            //
            // - the only other double-quote is at the end of the string
            // - the unquoted form successfully converts
            char_type const *const  closing =   class_type::str_chr(fileName + 1, '"');

            if( NULL == closing ||
                static_cast<size_type>(closing - fileName) != len - 1)
            {
                set_last_error(ERROR_INVALID_DATA);
            }
            else
            {
                size_type   r;

                if(NULL == buffer)
                {
                    r = get_full_path_name_impl(fileName, len, NULL, 0, ppFile);

                    if(0 != r)
                    {
                        n = 2 + r;
                    }
                }
                else if(cchBuffer == 0)
                {
                    n = 0;
                    *ppFile = NULL;
                }
                else if(cchBuffer == 1)
                {
                    // Have to check it's valid
                    r = get_full_path_name_impl(fileName, len, NULL, 0, ppFile);

                    if(0 != r)
                    {
                        buffer[0] = '"';
                        n = 1;
                        *ppFile = NULL;
                    }
                }
                else
                {
                    r = get_full_path_name_impl(fileName + 1, len - 2, buffer + 1, cchBuffer - 1, ppFile);

                    if(0 != r)
                    {
                        // Write the first quote character into the buffer
                        buffer[0] = '"';

                        if(r + 1 < cchBuffer)
                        {
                            // There's enough space for the result and the closing quote
                            buffer[r + 1] = '"';

                            if(r + 2 < cchBuffer)
                            {
                                // There's enough space for the result and the closing quote and the nul-terminator
                                buffer[r + 2] = '\0';

                                n = r + 2;
                            }
                            else
                            {
                                n = r + 2;
                            }
                        }
                        else
                        {
                            n = r + 1;
                        }
                    }
                }
            }
        }
        else
        {
            n = get_full_path_name_impl(fileName, len, buffer, cchBuffer, ppFile);
        }

        // Paths that exceed _MAX_PATH cause GetFullPathNameA() to fail, but it
        // does not (appear to) call SetLastError()
        if( 0 == n &&
            0 == ::GetLastError() &&
            str_len(fileName) > _MAX_PATH)
        {
            ::SetLastError(ERROR_FILENAME_EXCED_RANGE);
        }

        return n;
    }
#endif /* compiler */

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        char_type *pFile;

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    static size_type get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        return ::GetShortPathNameA(fileName, buffer, cchBuffer);
    }
    static size_type get_short_path_name(char_type const *fileName, char_type *buffer, size_type cchBuffer)
    {
        return ::GetShortPathNameA(fileName, buffer, cchBuffer);
    }

    // File-system enumeration

    static HANDLE find_first_file(char_type const *spec, find_data_type *findData)
    {
        return ::FindFirstFileA(spec, findData);
    }

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0400
    static HANDLE find_first_file_ex(char_type const *spec, FINDEX_SEARCH_OPS flags, find_data_type *findData)
    {
        return ::FindFirstFileExA(spec, FindExInfoStandard, findData, flags, NULL, 0);
    }
#endif /* _WIN32_WINNT >= 0x0400 */

    static bool_type find_next_file(HANDLE h, find_data_type *findData)
    {
        return ::FindNextFileA(h, findData) != FALSE;
    }

    static void find_file_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        ::FindClose(h);
    }

#ifndef _WINSTL_NO_FINDVOLUME_API
    static HANDLE find_first_volume(char_type *volume_name, size_type cch_volume_name)
    {
        return ::FindFirstVolumeA(volume_name, cch_volume_name);
    }

    static bool_type find_next_volume(HANDLE h, char_type *volume_name, size_type cch_volume_name)
    {
        return ::FindNextVolumeA(h, volume_name, cch_volume_name) != FALSE;
    }

    static void find_volume_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        ::FindVolumeClose(h);
    }
#endif // !_WINSTL_NO_FINDVOLUME_API

    // Modules

    static size_type get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        return ::GetModuleFileNameA(hModule, buffer, cchBuffer);
    }

    static size_type get_system_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetSystemDirectoryA(buffer, cchBuffer);
    }

    static size_type get_windows_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetWindowsDirectoryA(buffer, cchBuffer);
    }

    // Dynamic Loading

    static module_type load_library(char_type const *name)
    {
        return ::LoadLibraryA(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return filesystem_traits_::free_library(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return filesystem_traits_::find_symbol(hModule, symbolName);
    }

    // File-system state
    static bool_type set_current_directory(char_type const *dir)
    {
        return ::SetCurrentDirectoryA(dir) != FALSE;
    }

    static size_type get_current_directory(size_type cchBuffer, char_type *buffer)
    {
        return ::GetCurrentDirectoryA(cchBuffer, buffer);
    }

    static bool_type file_exists(char_type const *fileName)
    {
        return 0xFFFFFFFF != ::GetFileAttributesA(fileName);
    }

    static bool_type is_file(char_type const *path)
    {
        DWORD   attr = ::GetFileAttributesA(path);

        return 0xFFFFFFFF != attr && 0 == (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

    static bool_type is_directory(char_type const *path)
    {
        DWORD   attr = ::GetFileAttributesA(path);

        return 0xFFFFFFFF != attr && 0 != (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

#if 0
private:
    static void root_stat_(char_type drive, stat_data_type *stat_data)
    {
        stat_data->dwFileAttributes                 =   FILE_ATTRIBUTE_DIRECTORY;
        stat_data->ftCreationTime.dwLowDateTime     =   0;
        stat_data->ftCreationTime.dwHighDateTime    =   0;
        stat_data->ftLastAccessTime.dwLowDateTime   =   0;
        stat_data->ftLastAccessTime.dwHighDateTime  =   0;
        stat_data->ftLastWriteTime.dwLowDateTime    =   0;
        stat_data->ftLastWriteTime.dwHighDateTime   =   0;
        stat_data->nFileSizeHigh                    =   0;
        stat_data->nFileSizeLow                     =   0;
        stat_data->dwReserved0                      =   0;
        stat_data->dwReserved1                      =   0;
        stat_data->cFileName[0]                     =   /* drive;
        stat_data->cFileName[1]                     =   ':';
        stat_data->cFileName[2]                     =   '\\';
        stat_data->cFileName[3]                     = */    '\0';
        stat_data->cAlternateFileName[0]            =   0;
    }

public:
#endif /* 0 */

private:
    static bool_type stat_direct_(char_type const *path, stat_data_type *stat_data)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != stat_data);

        HANDLE  h   =   find_first_file(path, stat_data);

        return (INVALID_HANDLE_VALUE == h) ? false : (find_file_close(h), true);
    }
public:
    static bool_type stat(char_type const *path, stat_data_type *stat_data)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != stat_data);

        size_type   len         =   class_type::str_len(path);
        bool_type   bTryEndTest =   false;

        if( is_path_absolute(path) &&
            len > 4)
        {
            bTryEndTest = true;
        }
        else if(is_path_rooted(path) &&
                len > 3)
        {
            bTryEndTest = true;
        }
        else if(len > 2)
        {
            bTryEndTest = true;
        }

        if( bTryEndTest &&
            class_type::has_dir_end(path + len - 2))
        {
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200
    typedef stlsoft_ns_qual(auto_buffer)<char_type> buffer_type_;
            WINSTL_ASSERT(len > 2);

            buffer_type_    buffer(1 + len);

            if(0 == buffer.size())
            {
                return false;
            }
            else
            {
                WINSTL_ASSERT(len > 0);

                class_type::str_copy(&buffer[0], path);

                buffer[len - 1] = '\0';

                return class_type::stat_direct_(buffer.data(), stat_data);
            }
#else /* ? compiler */
            return class_type::stat_direct_(path, stat_data);
#endif /* compiler */
        }
        else
        {
            return stat_direct_(path, stat_data);
        }
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type *fstat_data)
    {
        return filesystem_traits_::fstat(fd, fstat_data);
    }

    static bool_type is_file(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(stat_data_type const * /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    static bool_type is_file(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_file(stat_data);
    }
    static bool_type is_directory(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_directory(stat_data);
    }
    static bool_type is_link(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_link(stat_data);
    }
    static bool_type is_readonly(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_readonly(stat_data);
    }

    static bool_type drive_exists(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaA(driveLetter));

        const DWORD drivesBitmap    =   ::GetLogicalDrives();
        const int   driveOrdinal    =   (driveLetter - (IsCharUpperA(driveLetter) ? 'A' : 'a'));

        return 0 != ((0x01 << driveOrdinal) & drivesBitmap);
    }

    static DWORD get_drive_type(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaA(driveLetter));

        char_type   drive[] = { '?', ':', '\\', '\0' };

        return (drive[0] = driveLetter, ::GetDriveTypeA(drive));
    }

    // File-system control

    static bool_type    create_directory(char_type const *dir)
    {
        return FALSE != ::CreateDirectoryA(dir, NULL);
    }

    static bool_type    create_directory(char_type const *dir, LPSECURITY_ATTRIBUTES lpsa)
    {
        return FALSE != ::CreateDirectoryA(dir, lpsa);
    }

    static bool_type    remove_directory(char_type const *dir)
    {
        return FALSE != ::RemoveDirectoryA(dir);
    }

    static bool_type    unlink_file(char_type const *file)
    {
        return FALSE != ::DeleteFileA(file);
    }

    static bool_type    delete_file(char_type const *file)
    {
        return unlink_file(file);
    }

    static bool_type    rename_file(char_type const *currentName, char_type const *newName)
    {
        return FALSE != ::MoveFileA(currentName, newName);
    }

    static bool_type    copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false)
    {
        return FALSE != ::CopyFileA(sourceName, newName, bFailIfExists);
    }

    // File functions

    static file_handle_type create_file(char_type const *fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, file_handle_type hTemplateFile)
    {
        return ::CreateFileA(fileName, desiredAccess, shareMode, sa, creationDisposition, flagAndAttributes, hTemplateFile);
    }

    static bool_type close_handle(HANDLE h)
    {
        return filesystem_traits_::close_handle(h);
    }

    static bool_type close_file(file_handle_type h)
    {
        return filesystem_traits_::close_handle(h);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static ws_uint64_t  get_file_size(file_handle_type h)
    {
        return filesystem_traits_::get_file_size(h);
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

    // Error

    static error_type get_last_error()
    {
        return filesystem_traits_::get_last_error();
    }

    static void set_last_error(error_type er = error_type())
    {
        filesystem_traits_::set_last_error(er);
    }

    // Environment

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
struct filesystem_traits<ws_char_w_t>
{
public:
    typedef ws_char_w_t                             char_type;
    typedef ws_size_t                               size_type;
    typedef ws_ptrdiff_t                            difference_type;
    typedef WIN32_FIND_DATAW                        find_data_type;
    typedef WIN32_FIND_DATAW                        stat_data_type;
    typedef BY_HANDLE_FILE_INFORMATION              fstat_data_type;
    typedef filesystem_traits<char_type>            class_type;
    /// The (signed) integer type
    typedef ws_int_t                                int_type;
    /// The Boolean type
    typedef ws_bool_t                               bool_type;
    /// The type of a system file handle
    typedef HANDLE                                  file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef HINSTANCE                               module_type;
    /// The type of system error codes
    typedef DWORD                                   error_type;
private:
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200
    typedef stlsoft_ns_qual(auto_buffer)<char_type> buffer_type_;
#endif /* compiler */
public:

    enum
    {
        maxPathLength   =   1 + _MAX_PATH       //!< The maximum length of a path for the current file system
    };

public:
    // General string handling
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

    // Locale management
    static int_type get_locale_info(LCID locale, LCTYPE type, char_type *data, int_type cchData)
    {
        return ::GetLocaleInfoW(locale, type, data, cchData);
    }

    // File-system entry names
    static char_type *ensure_dir_end(char_type *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        char_type   *end;

        for(end = dir; *end != L'\0'; ++end)
        {}

        if( dir < end &&
            !is_path_name_separator(*(end - 1)))
        {
            *end        =   path_name_separator();
            *(end + 1)  =   L'\0';
        }

        return dir;
    }

    static char_type *remove_dir_end(char_type *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        char_type   *end;

        for(end = dir; *end != L'\0'; ++end)
        {}

        if( dir < end &&
            is_path_name_separator(*(end - 1)))
        {
            *(end - 1)  =   L'\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const *dir)
    {
        WINSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == L'\0' ||
                    (    dir[1] == L'.' &&
                        dir[2] == L'\0'));
    }

    static bool_type is_path_rooted(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_name_separator(*path) || is_path_absolute(path);
    }

    static bool_type is_path_absolute(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        size_type len = str_len(path);

        return  is_path_UNC(path) ||
                (   (2 < len) &&
                    (L':' == path[1]) &&
                    is_path_name_separator(path[2]));
    }

    static bool_type is_path_UNC(char_type const *path)
    {
        WINSTL_ASSERT(NULL != path);

        return (L'\\' == path[0] && L'\\' == path[1]);
    }

    static bool_type is_path_name_separator(char_type ch)
    {
        return L'\\' == ch || L'/' == ch;
    }

    static char_type path_separator()
    {
        return L';';
    }

    static char_type path_name_separator()
    {
        return L'\\';
    }

    static char_type const *pattern_all()
    {
        return L"*.*";
    }

    static size_type path_max()
    {
        return (::GetVersion() & 0x80000000) ? (1 + _MAX_PATH) : (1 + CONST_NT_MAX_PATH);
    }

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile)
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same", fileName != buffer);

        return ::GetFullPathNameW(fileName, cchBuffer, buffer, ppFile);
    }

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        char_type *pFile;

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    static size_type get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        return ::GetShortPathNameW(fileName, buffer, cchBuffer);
    }
    static size_type get_short_path_name(char_type const *fileName, char_type *buffer, size_type cchBuffer)
    {
        return ::GetShortPathNameW(fileName, buffer, cchBuffer);
    }

    // FindFile() API
    static HANDLE find_first_file(char_type const *spec, find_data_type *findData)
    {
        return ::FindFirstFileW(spec, findData);
    }

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0400
    static HANDLE find_first_file_ex(char_type const *spec, FINDEX_SEARCH_OPS flags, find_data_type *findData)
    {
        return ::FindFirstFileExW(spec, FindExInfoStandard, findData, flags, NULL, 0);
    }
#endif /* _WIN32_WINNT >= 0x0400 */

    static bool_type find_next_file(HANDLE h, find_data_type *findData)
    {
        return ::FindNextFileW(h, findData) != FALSE;
    }

    static void find_file_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        ::FindClose(h);
    }

    // FindVolume() API
#ifndef _WINSTL_NO_FINDVOLUME_API
    static HANDLE find_first_volume(char_type *volume_name, size_type cch_volume_name)
    {
        return ::FindFirstVolumeW(volume_name, cch_volume_name);
    }

    static bool_type find_next_volume(HANDLE h, char_type *volume_name, size_type cch_volume_name)
    {
        return ::FindNextVolumeW(h, volume_name, cch_volume_name) != FALSE;
    }

    static void find_volume_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        ::FindVolumeClose(h);
    }
#endif // !_WINSTL_NO_FINDVOLUME_API

    // Modules
    static size_type get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer)
    {
        return ::GetModuleFileNameW(hModule, buffer, cchBuffer);
    }

    static size_type get_system_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetSystemDirectoryW(buffer, cchBuffer);
    }

    static size_type get_windows_directory(char_type *buffer, size_type cchBuffer)
    {
        return ::GetWindowsDirectoryW(buffer, cchBuffer);
    }

    // Dynamic Loading

    static module_type load_library(char_type const *name)
    {
        return ::LoadLibraryW(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return filesystem_traits_::free_library(hModule);
    }

    static FARPROC find_symbol(module_type hModule, char const *symbolName)
    {
        return filesystem_traits_::find_symbol(hModule, symbolName);
    }

    // File-system state
    static bool_type set_current_directory(char_type const *dir)
    {
        return ::SetCurrentDirectoryW(dir) != FALSE;
    }

    static size_type get_current_directory(size_type cchBuffer, char_type *buffer)
    {
        return ::GetCurrentDirectoryW(cchBuffer, buffer);
    }

    /// Returns whether a file exists or not
    static bool_type file_exists(char_type const *fileName)
    {
        return 0xFFFFFFFF != ::GetFileAttributesW(fileName);
    }

    static bool_type is_file(char_type const *path)
    {
        DWORD   attr = ::GetFileAttributesW(path);

        return 0xFFFFFFFF != attr && 0 == (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

    static bool_type is_directory(char_type const *path)
    {
        DWORD   attr = ::GetFileAttributesW(path);

        return 0xFFFFFFFF != attr && 0 != (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

    static bool_type stat(char_type const *path, stat_data_type *stat_data)
    {
        HANDLE  h   =   find_first_file(path, stat_data);

        return (INVALID_HANDLE_VALUE == h) ? false : (find_file_close(h), true);
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type *fstat_data)
    {
        return filesystem_traits_::fstat(fd, fstat_data);
    }

    static bool_type is_file(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(stat_data_type const * /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(stat_data_type const *stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    static bool_type is_file(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_file(stat_data);
    }
    static bool_type is_directory(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_directory(stat_data);
    }
    static bool_type is_link(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_link(stat_data);
    }
    static bool_type is_readonly(fstat_data_type const *stat_data)
    {
        return filesystem_traits_::is_readonly(stat_data);
    }

    static bool_type drive_exists(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaW(driveLetter));

        const DWORD drivesBitmap    =   ::GetLogicalDrives();
        const int   driveOrdinal    =   (driveLetter - (IsCharUpperW(driveLetter) ? L'A' : L'a'));

        return 0 != ((0x01 << driveOrdinal) & drivesBitmap);
    }

    static DWORD get_drive_type(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaW(driveLetter));

        char_type   drive[] = { L'?', L':', L'\\', L'\0' };

        return (drive[0] = driveLetter, ::GetDriveTypeW(drive));
    }

    // File-system control

    static bool_type    create_directory(char_type const *dir)
    {
        return FALSE != ::CreateDirectoryW(dir, NULL);
    }

    static bool_type    create_directory(char_type const *dir, LPSECURITY_ATTRIBUTES lpsa)
    {
        return FALSE != ::CreateDirectoryW(dir, lpsa);
    }

    static bool_type    remove_directory(char_type const *dir)
    {
        return FALSE != ::RemoveDirectoryW(dir);
    }

    static bool_type    unlink_file(char_type const *file)
    {
        return FALSE != ::DeleteFileW(file);
    }

    static bool_type    delete_file(char_type const *file)
    {
        return unlink_file(file);
    }

    static bool_type    rename_file(char_type const *currentName, char_type const *newName)
    {
        return FALSE != ::MoveFileW(currentName, newName);
    }

    static bool_type    copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false)
    {
        return FALSE != ::CopyFileW(sourceName, newName, bFailIfExists);
    }

    // File functions

    static file_handle_type create_file(char_type const *fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, file_handle_type hTemplateFile)
    {
        return ::CreateFileW(fileName, desiredAccess, shareMode, sa, creationDisposition, flagAndAttributes, hTemplateFile);
    }

    static bool_type close_handle(HANDLE h)
    {
        return filesystem_traits_::close_handle(h);
    }
    static bool_type close_file(file_handle_type h)
    {
        return filesystem_traits_::close_handle(h);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static ws_uint64_t  get_file_size(file_handle_type h)
    {
        return filesystem_traits_::get_file_size(h);
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

    // Error

    static error_type get_last_error()
    {
        return filesystem_traits_::get_last_error();
    }

    static void set_last_error(error_type er = error_type())
    {
        filesystem_traits_::set_last_error(er);
    }

    // Environment

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

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/filesystem_traits_unittest_.h"
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
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ////////////////////////////////////////////////////////////////////////// */