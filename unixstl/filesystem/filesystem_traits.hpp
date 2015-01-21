/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/filesystem_traits.hpp (formerly unixstl_filesystem_traits.h)
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     10th June 2006
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


/** \file unixstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++ only] Definition of the unixstl::filesystem_traits class
 *  template.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR     0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION  2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT      87
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifdef WIN32
# include <ctype.h>
#endif /* WIN32 */
#include <errno.h>
#include <fcntl.h>
#ifdef WIN32
# include <io.h>
# if defined(STLSOFT_COMPILER_IS_INTEL)
#  include <direct.h>
# endif /* os && compiler */
#endif /* WIN32 */
#include <dlfcn.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <sys/types.h>
#include <sys/stat.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** \brief Traits class for file-system operations
 *
 * \ingroup group__library__file_system
 *
 * filesystem_traits is a traits class for determining the correct file-system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct filesystem_traits
{
/// \name Types
/// @{
public:
    /// \brief The character type
    typedef C                                       char_type;
    /// \brief The size type
    typedef us_size_t                               size_type;
    /// \brief The difference type
    typedef us_ptrdiff_t                            difference_type;
    /// \brief The stat data type
    typedef struct stat                             stat_data_type;
    /// \brief The fstat data type
    typedef struct stat                             fstat_data_type;
    /// \brief The current instantion of the type
    typedef filesystem_traits<C>                    class_type;
    /// \brief The (signed) integer type
    typedef us_int_t                                int_type;
    /// \brief The Boolean type
    typedef us_bool_t                               bool_type;
    /// \brief The type of a system file handle
    typedef int                                     file_handle_type;
    /// \brief The type of a handle to a dynamically loaded module
    typedef void                                    *module_type;
    /// \brief The type of system error codes
    typedef int                                     error_type;
    /// \brief The mode type
#ifdef WIN32
    typedef unsigned short                          mode_type;
#else /* ? WIN32 */
    typedef mode_t                                  mode_type;
#endif /* WIN32 */
/// @}

#ifdef PATH_MAX
/// \name Constants
/// @{
public:
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };
/// @}
#endif /* PATH_MAX */

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
/// @}

/// \name File-system entry names
/// @{
public:
    /// \brief Appends a path name separator to \c dir if one does not exist
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type    *ensure_dir_end(char_type *dir);
    /// \brief Removes the path name separator from the end of \c dir, if it has it
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type    *remove_dir_end(char_type *dir);
    /// \brief Returns \c true if \c dir has trailing path name separator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static bool_type    has_dir_end(char_type const *dir);

    /// \brief Returns \c true if dir is \c "." or \c ".."
    static bool_type    is_dots(char_type const *dir);
    /// \brief Returns \c true if path is rooted
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// root character sequence(s).
    static bool_type    is_path_rooted(char_type const *path);
    /// \brief Returns \c true if path is an absolute path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// absolute path character sequence(s).
    static bool_type    is_path_absolute(char_type const *path);
    /// \brief Returns \c true if path is a UNC path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the UNC character sequence(s).
    static bool_type    is_path_UNC(char_type const *path);
    /// \brief Returns \c true if the character is a path-name separator
    static bool_type    is_path_name_separator(char_type ch);

    /// \brief Returns the path separator
    ///
    /// This is the separator that is used to separate multiple paths on the operating system. On UNIX it is ':'
    static char_type    path_separator();
    /// \brief Returns the path name separator
    ///
    /// This is the separator that is used to separate parts of a path on the operating system. On UNIX it is '/'
    static char_type    path_name_separator();
    /// \brief Returns the wildcard pattern that represents all possible matches
    ///
    /// \note On UNIX it is '*'
    static char_type const *pattern_all();
    /// \brief The maximum length of a path on the file-system
    ///
    /// \note Because not all systems support fixed maximum path lengths, the value of this function is notionally dynamic
    static size_type    path_max();
    /// \brief Gets the full path name into the given buffer, returning a pointer to the file-part
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile);
    /// \brief Gets the full path name into the given buffer
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
    /// \brief Gets the short path name into the given buffer
    static size_type    get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
/// @}

/// \name File-system enumeration
/// @{
public:
    // opendir/readdir API

    /// \brief Initiate a file-system search
    static DIR                  *open_dir(char_type const *dir);
    /// \brief Read an entry from the file-system search
    static struct dirent const  *read_dir(DIR *h);
    /// \brief Closes the handle of the file-system search
    static void                 close_dir(DIR *h);

/// @}

/// \name Dynamic Loading
/// @{
public:
    /// \brief Loads the given executable module
    static module_type  load_library(char_type const *name);
    /// \brief Closes the given executable module
    static bool_type    free_library(module_type hModule);
    /// \brief Retrieves the given symbol from the library
    static void         *find_symbol(module_type hModule, char const *symbolName);
/// @}

/// \name File-system control
/// @{
public:
    /// \brief Sets the current directory to \c dir
    static bool_type    set_current_directory(char_type const *dir);
    /// \brief Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    static size_type    get_current_directory(size_type cchBuffer, char_type *buffer);
/// @}

/// \name File-system state
/// @{
public:
    /// \brief Returns whether a file exists or not
    static bool_type    file_exists(char_type const *path);
    /// \brief Returns whether the given path represents a file
    static bool_type    is_file(char_type const *path);
    /// \brief Returns whether the given path represents a directory
    static bool_type    is_directory(char_type const *path);
    /// \brief Gets the information for a particular file system entry
    static bool_type    stat(char_type const *path, stat_data_type *stat_data);
    /// \brief Gets the information for a particular file system entry
    static bool_type    lstat(char_type const *path, stat_data_type *stat_data);
    /// \brief Gets the information for a particular open file
    static bool_type    fstat(file_handle_type fd, fstat_data_type *fstat_data);

    /// \brief Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const *stat_data);
    /// \brief Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const *stat_data);
    /// \brief Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const *stat_data);
    /// \brief Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const *stat_data);
/// @}

/// \name File-system control
/// @{
public:
    /// \brief Creates a directory
    static bool_type    create_directory(char_type const *dir);
    /// \brief Deletes a directory
    static bool_type    remove_directory(char_type const *dir);

    /// \brief Delete a file
    static bool_type    unlink_file(char_type const *file);
    /// \brief Delete a file
    ///
    /// \deprecated Users should use unlink_file()
    static bool_type    delete_file(char_type const *file);
    /// \brief Rename a file
    static bool_type    rename_file(char_type const *currentName, char_type const *newName);
    /// \brief Copy a file
//    static bool_type    copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false);

    /// \brief Create / open a file
    static file_handle_type open_file(char_type const *fileName, int oflag, int pmode);
    /// \brief Closes the given operating system handle
    static bool_type        close_file(file_handle_type fd);
    /// \brief Create / open a file
    ///
    /// \deprecated Users should use open_file()
    static file_handle_type open(char_type const *fileName, int oflag, int pmode);
    /// \brief Closes the given operating system handle
    ///
    /// \deprecated Users should use close_file()
    static bool_type        close(file_handle_type fd);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// \brief Gets the size of the file
    static us_uint64_t      get_file_size(file_handle_type fd);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
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
    /// \brief Expands environment strings in \c src into \c buffer, up to a maximum \c cchDest characters
    static size_type    expand_environment_strings(char_type const *src, char_type *buffer, size_type cchBuffer);
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct filesystem_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_a_t>
{
public:
    typedef us_char_a_t                                 char_type;
    typedef us_size_t                                   size_type;
    typedef us_ptrdiff_t                                difference_type;
    typedef struct stat                                 stat_data_type;
    typedef struct stat                                 fstat_data_type;
    typedef filesystem_traits<us_char_a_t>              class_type;
    /// \brief The (signed) integer type
    typedef us_int_t                                    int_type;
    /// \brief The Boolean type
    typedef us_bool_t                                   bool_type;
    /// \brief The type of a system file handle
    typedef int                                         file_handle_type;
    /// \brief The type of a handle to a dynamically loaded module
    typedef void                                        *module_type;
    /// \brief The type of system error codes
    typedef int                                         error_type;
    /// \brief The mode type
#ifdef WIN32
    typedef unsigned short                              mode_type;
#else /* ? WIN32 */
    typedef mode_t                                      mode_type;
#endif /* WIN32 */
private:
    typedef stlsoft_ns_qual(auto_buffer_old)<char_type> buffer_type_;
public:


#ifdef PATH_MAX
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

public:
    // General string handling
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::strcpy(dest, src);
    }

    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::strncpy(dest, src, cch);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::strcat(dest, src);
    }

    static char_type *str_n_cat(char_type *dest, char_type const *src, size_type cch)
    {
        return ::strncat(dest, src, cch);
    }

    static int_type str_compare(char_type const *s1, char_type const *s2)
    {
        return ::strcmp(s1, s2);
    }

    static int_type str_compare_no_case(char_type const *s1, char_type const *s2);

    static int_type str_n_compare(char_type const *s1, char_type const *s2, size_type cch)
    {
        return ::strncmp(s1, s2, cch);
    }

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::strlen(src));
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

    // File-system entry names
    static char_type *ensure_dir_end(char_type *dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

        char_type   *end;

#ifdef WIN32
        if( isalpha(dir[0]) &&
            ':' == dir[1] &&
            is_path_name_separator(dir[2]) &&
            '\0' == dir[3])
        {
            return dir;
        }
#endif /* WIN32 */

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
        UNIXSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const *dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == '\0' ||
                    (    dir[1] == '.' &&
                        dir[2] == '\0'));
    }

    static bool_type is_path_rooted(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        // It might be a UNC path. This is handled by the second test below, but
        // this is a bit clearer, and since this is a debug kind of thing, we're
        // not worried about the cost
        if( '\\' == path[0] &&
            '\\' == path[1])
        {
            return true;
        }

        // If it's really on Windows, then we need to skip the drive, if present
        if( isalpha(path[0]) &&
            ':' == path[1])
        {
            path += 2;
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards, but that's taken care of for us by
        // is_path_name_separator()
#endif /* WIN32 */

        return is_path_name_separator(*path);
    }

    static bool_type is_path_absolute(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if(is_path_UNC(path))
        {
            return true;
        }
        // ... it's got drive + root slash, or
        if( isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return true;
        }
        // ... it's got root forward slash
        if('/' == path[0])
        {
            return true;
        }

        return false;
#else /* ? WIN32 */
        return is_path_rooted(path);
#endif /* WIN32 */
    }

    static bool_type is_path_UNC(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        return ('\\' == path[0] && '\\' == path[1]);
#else /* ? WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#endif /* WIN32 */
    }

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef WIN32
        return '\\' == ch || '/' == ch;
#else /* ? WIN32 */
        return '/' == ch;
#endif /* WIN32 */
    }

    static char_type path_separator()
    {
        return ':';
    }

    static char_type path_name_separator()
    {
        return '/';
    }

    static char_type const *pattern_all()
    {
        return "*";
    }

    static size_type path_max()
    {
#if defined(PATH_MAX)
        return 1 + PATH_MAX;
#else /* ? PATH_MAX */
        return 1 + pathconf("/", _PC_PATH_MAX);
#endif /* PATH_MAX */
    }

private:
    static size_type get_full_path_name_impl2(char_type const *fileName, us_size_t len, char_type *buffer, size_type cchBuffer)
    {
        // The next thing to so is determine whether the path is absolute, in
        // which case we'll just copy it into the buffer
        if(is_path_rooted(fileName))
        {
            // Given path is absolute, so simply copy into buffer
            if(NULL == buffer)
            {
                len = len;
            }
            else if(cchBuffer < len)
            {
                str_n_copy(&buffer[0], fileName, cchBuffer);
                len = cchBuffer;
            }
            else
            {
                // Given buffer is large enough, so copy
                str_copy(buffer, fileName);
            }
        }
        else
        {
            // Given path is relative, so get the current directory, and then concatenate
            buffer_type_    directory(1 + path_max());

            if(0 == directory.size())
            {
                set_last_error(ENOMEM);

                return 0;
            }
            else if(NULL != buffer &&
                    0 == cchBuffer)
            {
                return 0;
            }
            else
            {
                size_type lenDir = get_current_directory(directory.size(), &directory[0]);

                if(0 == lenDir)
                {
                    // The call failed, so indicate that to caller
                    len = 0;
                }
                else
                {
                    if( 1 == len  &&
                        '.' == fileName[0])
                    {
                        if(NULL == buffer)
                        {
                            len = lenDir;
                        }
                        else
                        {
                            if(cchBuffer < lenDir)
                            {
                                str_n_copy(&buffer[0], directory.data(), cchBuffer);
                                len = cchBuffer;
                            }
                            else
                            {
                                // Given buffer is large enough, so copy
                                str_copy(buffer, directory.data());
                                len = lenDir;
                            }
                        }
                    }
                    else
                    {
                        if(!has_dir_end(&directory[0] + (lenDir - 1)))
                        {
                            ++lenDir;
                        }
                        ensure_dir_end(&directory[0]);

                        len += lenDir;

                        if(NULL != buffer)
                        {
                            str_n_copy(&buffer[0], directory.data(), cchBuffer);

                            if(cchBuffer > lenDir)
                            {
                                str_n_copy(&buffer[0] + lenDir, fileName, cchBuffer - lenDir);
                            }

                            if(cchBuffer < len)
                            {
                                len = cchBuffer;
                            }
                        }
                    }
                }
            }
        }

        return len;
    }

    static size_type get_full_path_name_impl(char_type const *fileName, us_size_t len, char_type *buffer, size_type cchBuffer)
    {
        UNIXSTL_ASSERT(len > 0);

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
                set_last_error(ENOMEM);

                return 0;
            }
            else
            {
                fileName_[len] = '\0';

                return get_full_path_name_impl2(str_n_copy(&fileName_[0], fileName, len)
                                            ,   len
                                            ,   buffer
                                            ,   cchBuffer);
            }
        }
        else
        {
            return get_full_path_name_impl2(fileName, len, buffer, cchBuffer);
        }
    }

public:
    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile)
    {
        UNIXSTL_ASSERT(NULL != ppFile);

        size_type   r =   get_full_path_name(fileName, cchBuffer, buffer);

        *ppFile = NULL;

        if( NULL != buffer &&
            0 != r &&
            r <= cchBuffer)
        {
            size_type   cchRequired =   get_full_path_name(fileName, 0, NULL);

            if(r == cchRequired)
            {
                // Now search for the file separator
                char_type *pFile        =   str_rchr(buffer, path_name_separator());
#if defined(WIN32)
                char_type *pFile2       =   str_rchr(buffer, '\\');

                if(NULL == pFile)
                {
                    pFile = pFile2;
                }
                else if(NULL != pFile2)
                {
                    if(pFile2 > pFile)
                    {
                        pFile = pFile2;
                    }
                }
#endif /* WIN32 */

                if(NULL != (*ppFile = pFile))
                {
                    (*ppFile)++;
                }
            }
        }

        return r;
    }

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        UNIXSTL_ASSERT(NULL != fileName);
        UNIXSTL_ASSERT(0 == cchBuffer || NULL != buffer);

#if 1
        // Can't call realpath(), since that requires that the file exists
        return get_full_path_name_impl(fileName, str_len(fileName), buffer, cchBuffer);
#else /* ? 0 */
        buffer_type_    directory(1 + path_max());

        if( 0 == directory.size() ||
            NULL == ::realpath(fileName, &directory[0]))
        {
            return 0;
        }
        else
        {
            const size_type len =   str_len(directory.data());

            if(NULL == buffer)
            {
                return len;
            }
            else if(0 == cchBuffer)
            {
                return 0;
            }
            else
            {
                if(len < cchBuffer)
                {
                    str_copy(&buffer[0], directory.data());

                    return len;
                }
                else
                {
                    str_n_copy(&buffer[0], directory.data(), cchBuffer);

                    return cchBuffer;
                }
            }
        }
#endif /* 0 */
    }

    static size_type get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        return get_full_path_name(fileName, cchBuffer, buffer);
    }

    // File-system enumeration

    static DIR *open_dir(char_type const *dir)
    {
        return ::opendir(dir);
    }
    static struct dirent const *read_dir(DIR *h)
    {
        return ::readdir(h);
    }
    static void close_dir(DIR *h)
    {
        ::closedir(h);
    }

/// @}

    // Dynamic Loading

    static module_type load_library(char_type const *name)
    {
        return ::dlopen(name, RTLD_NOW);
    }

    static bool_type free_library(module_type hModule)
    {
        return 0 == ::dlclose(hModule);
    }

    static void *find_symbol(module_type hModule, char const *symbolName)
    {
        return ::dlsym(hModule, symbolName);
    }

    // File-system state
    static bool_type set_current_directory(char_type const *dir)
    {
        return chdir(dir) == 0;
    }

    static size_type get_current_directory(size_type cchBuffer, char_type *buffer)
    {
        char_type const *dir    =   ::getcwd(buffer, cchBuffer);

        return (NULL == dir) ? 0 : str_len(dir);
    }

    static bool_type file_exists(char_type const *fileName)
    {
        stat_data_type  sd;

        return class_type::stat(fileName, &sd) /* || errno != ENOENT */;
    }

    static bool_type is_file(char_type const *path)
    {
        stat_data_type  sd;

        return class_type::stat(path, &sd) && S_IFREG == (sd.st_mode & S_IFMT);
    }

    static bool_type is_directory(char_type const *path)
    {
        stat_data_type  sd;

        return class_type::stat(path, &sd) && S_IFDIR == (sd.st_mode & S_IFMT);
    }

    static bool_type stat(char_type const *path, stat_data_type *stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef WIN32
        if( NULL != str_chr(path, '?') ||
            NULL != str_chr(path, '*'))
        {
            // Sometimes the VC6 CRT libs crash with a wildcard stat
            set_last_error(EBADF);

            return false;
        }

        if(has_dir_end(path))
        {
            // Win32 impl does not like a trailing slash
            size_type   len =   str_len(path);

            if( len > 3 ||
                (   is_path_name_separator(*path) &&
                    len > 2))
            {
                buffer_type_    directory(1 + len);

                if(0 == directory.size())
                {
                    set_last_error(ENOMEM);

                    return false;
                }
                else
                {
                    str_copy(&directory[0], path);

                    class_type::remove_dir_end(&directory[0]);

                    return class_type::stat(&directory[0], stat_data);
                }
            }
        }
#endif /* WIN32 */

        return 0 == ::stat(path, stat_data);
    }

    static bool_type lstat(char_type const *path, stat_data_type *stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef WIN32
        return 0 == class_type::stat(path, stat_data);
#else /* ? WIN32 */
        return 0 == ::lstat(path, stat_data);
#endif /* WIN32 */
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type *fstat_data)
    {
        UNIXSTL_ASSERT(-1 != fd);
        UNIXSTL_ASSERT(NULL != fstat_data);

        return 0 == ::fstat(fd, fstat_data);
    }

    static bool_type is_file(stat_data_type const *stat_data)
    {
        return S_IFREG == (stat_data->st_mode & S_IFREG);
    }
    static bool_type is_directory(stat_data_type const *stat_data)
    {
        return S_IFDIR == (stat_data->st_mode & S_IFDIR);
    }
    static bool_type is_link(stat_data_type const *stat_data)
    {
#ifdef WIN32
        STLSOFT_SUPPRESS_UNUSED(stat_data);

        return false;
#else /* ? WIN32 */
        return S_IFLNK == (stat_data->st_mode & S_IFLNK);
#endif /* WIN32 */
    }
    static bool_type is_readonly(stat_data_type const *stat_data)
    {
#ifdef WIN32
        return S_IREAD == (stat_data->st_mode & (S_IREAD | S_IWRITE));
#else /* ? WIN32 */
        return S_IRUSR == (stat_data->st_mode & (S_IRUSR | S_IWUSR));
#endif /* WIN32 */
    }

    // File-system control

    static bool_type    create_directory(char_type const *dir)
    {
        mode_type   mode = 0;

#ifdef WIN32
        mode    =   S_IREAD | S_IWRITE | S_IEXEC;
#else /* ? WIN32 */
        mode    =   S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
#endif /* WIN32 */

        return create_directory(dir, 0);
    }

    static bool_type create_directory(char_type const *dir, mode_type permissions)
    {
        return 0 == ::mkdir(dir, permissions);
    }

    static bool_type remove_directory(char_type const *dir)
    {
        return 0 == ::rmdir(dir);
    }

    static bool_type unlink_file(char_type const *file)
    {
        return 0 == ::remove(file);
    }

    static bool_type    delete_file(char_type const *file)
    {
        return unlink_file(file);
    }

    static bool_type rename_file(char_type const *currentName, char_type const *newName)
    {
        return 0 == ::rename(currentName, newName);
    }

    // File functions

    static file_handle_type open_file(char_type const *fileName, int oflag, int pmode)
    {
        return ::open(fileName, oflag, pmode);
    }

    static bool_type close_file(file_handle_type fd)
    {
        return 0 == ::close(fd);
    }

    static file_handle_type open(char_type const *fileName, int oflag, int pmode)
    {
        return class_type::open_file(fileName, oflag, pmode);
    }

    static bool_type close(file_handle_type fd)
    {
        return class_type::close_file(fd);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static us_uint64_t get_file_size(file_handle_type fd)
    {
        struct stat st;

        return class_type::fstat(fd, &st) ? st.st_size : 0;
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

    // Error

    static error_type get_last_error()
    {
        return errno;
    }

    static void set_last_error(error_type er = error_type())
    {
        errno = er;
    }

    // Environment

    static size_type get_environment_variable(char_type const *name, char_type *buffer, size_type cchBuffer)
    {
        char const  *var = ::getenv(name);

        if(NULL == var)
        {
            return 0;
        }
        else
        {
            us_size_t   var_len = ::strlen(var);

            if(NULL == buffer)
            {
                return var_len;
            }
            else
            {
                ::strncpy(buffer, var, cchBuffer);

                return (var_len < cchBuffer) ? var_len : cchBuffer;
            }
        }
    }

    static size_type expand_environment_strings(char_type const *src, char_type *buffer, size_type cchBuffer);
};

#if 0
STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_w_t>
{
public:
    typedef us_char_w_t char_type;
    typedef us_size_t   size_type;

#ifdef PATH_MAX
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

public:
    // General string handling
    static char_type *str_copy(char_type *dest, char_type const *src)
    {
        return ::wcscpy(dest, src);
    }

    static char_type *str_n_copy(char_type *dest, char_type const *src, size_type cch)
    {
        return ::wcsncpy(dest, src, cch);
    }

    static char_type *str_cat(char_type *dest, char_type const *src)
    {
        return ::wcscat(dest, src);
    }

    static int_type str_compare(char_type const *s1, char_type const *s2)
    {
        return ::wcscmp(s1, s2);
    }

    static int_type str_compare_no_case(char_type const *s1, char_type const *s2);

    static int_type str_n_compare(char_type const *s1, char_type const *s2, size_type cch)
    {
        return ::wcsncmp(s1, s2, cch);
    }

    static size_type str_len(char_type const *src)
    {
        return static_cast<size_type>(::wcslen(src));
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

    // File-system entry names
    static char_type *ensure_dir_end(char_type *dir)
    {
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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const *dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == L'\0' ||
                    (    dir[1] == L'.' &&
                        dir[2] == L'\0'));
    }

    static bool_type is_path_rooted(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        // If it's really on Windows, then we need to skip the drive, if present
        if( isalpha(path[0]) &&
            ':' == path[1])
        {
            path += 2;
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards
        if('\\' == *path)
        {
            return true;
        }
#endif /* WIN32 */

        return '/' == *path;
    }

    static bool_type is_path_absolute(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if(is_path_UNC(path))
        {
            return true;
        }
        // ... it's got drive + root slash, or
        if( isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return true;
        }
        // ... it's got root forward slash
        if('/' == path[0])
        {
            return true;
        }

        return false;
#else /* ? WIN32 */
        return is_path_rooted(path);
#endif /* WIN32 */
    }

    static bool_type is_path_UNC(char_type const *path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef WIN32
        return (L'\\' == path[0] && L'\\' == path[1]);
#else /* ? WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#endif /* WIN32 */
    }

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef WIN32
        return L'\\' == ch || L'/' == ch;
#else /* ? WIN32 */
        return L'/' == ch;
#endif /* WIN32 */
    }

    static char_type path_separator()
    {
        return L':';
    }

    static char_type path_name_separator()
    {
        return L'/';
    }

    static char_type const *pattern_all()
    {
        return L"*";
    }

    static size_type path_max()
    {
#if defined(PATH_MAX)
        return 1 + PATH_MAX;
#else /* ? PATH_MAX */
        return 1 + pathconf("/", _PC_PATH_MAX);
#endif /* PATH_MAX */
    }

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile);

    static size_type get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer)
    {
        char_type *pFile;

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    // File-system state
    static bool_type set_current_directory(char_type const *dir);

    static size_type get_current_directory(size_type cchBuffer, char_type *buffer);
};
#endif /* 0 */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/filesystem_traits_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ////////////////////////////////////////////////////////////////////// */
