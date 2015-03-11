/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/memory_mapped_file.hpp (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Memory mapped file class.
 *
 * Created:     15th December 1996
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/memory_mapped_file.hpp
///
/// Memory mapped file class.

#ifndef WINSTL_INCL_WINSTL_HPP_MEMORY_MAPPED_FILE
#define WINSTL_INCL_WINSTL_HPP_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_MEMORY_MAPPED_FILE_MAJOR     3
# define WINSTL_VER_WINSTL_HPP_MEMORY_MAPPED_FILE_MINOR     2
# define WINSTL_VER_WINSTL_HPP_MEMORY_MAPPED_FILE_REVISION  1
# define WINSTL_VER_WINSTL_HPP_MEMORY_MAPPED_FILE_EDIT      56
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
#  include <winstl/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE
# include <stlsoft/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */

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

/// Facade over the Win32 memory mapped file API
class memory_mapped_file
{
private:
    typedef ws_char_a_t                     char_type;
    typedef filesystem_traits<ws_char_a_t>  traits_type;
public:
    typedef memory_mapped_file              class_type;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ws_uint64_t                     size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef ws_uint32_t                     size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

public:
#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Make this use a create_() method via MUMI"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

    ss_explicit_k memory_mapped_file(char_type const *fileName)
        : m_cb(0)
        , m_memory(NULL)
    {
        scoped_handle<HANDLE>   hfile(  traits_type::create_file(   fileName
                                                                ,   GENERIC_READ
                                                                ,   FILE_SHARE_READ
                                                                ,   NULL
                                                                ,   OPEN_EXISTING
                                                                ,   FILE_FLAG_RANDOM_ACCESS
                                                                ,   NULL)
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
                            ,   (void (*)(HANDLE))&filesystem_traits<char_type>::close_handle
#else /* ? compiler */
                            ,   &filesystem_traits<char_type>::close_handle
#endif /* compiler */
                            ,   INVALID_HANDLE_VALUE);

        if(hfile.empty())
        {
            on_error_("Failed to open file for mapping");
        }
        else
        {
            DWORD   fileSizeHigh;
            DWORD   fileSizeLow =   ::GetFileSize(::stlsoft::get_handle(hfile), &fileSizeHigh);
            DWORD   error       =   ::GetLastError();

            if( INVALID_FILE_SIZE == fileSizeLow &&
                ERROR_SUCCESS != error)
            {
                on_error_("Failed to determine mapped file size", error);
            }
#ifndef STLSOFT_CF_64BIT_INT_SUPPORT
            else if(0 == fileSizeHigh)
            {
                on_error_("Cannot map files with sizes larger than 4GB with compilers that do not support 64-bit integers", ERROR_SUCCESS);
            }
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
            else
            {
                scoped_handle<HANDLE>   hmap(   ::CreateFileMappingA(   ::stlsoft::get_handle(hfile)
                                                                    ,   NULL
                                                                    ,   PAGE_READONLY
                                                                    ,   0
                                                                    ,   0
                                                                    ,   NULL)
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
                                    ,   (void (*)(HANDLE))&filesystem_traits<char_type>::close_handle
#else /* ? compiler */
                                    ,   &filesystem_traits<char_type>::close_handle
#endif /* compiler */
                                    ,   NULL);

                if(hmap.empty())
                {
                    on_error_("Failed to open file mapping");
                }
                else
                {
                    void    *memory = ::MapViewOfFile( ::stlsoft::get_handle(hmap)
                                                    ,   FILE_MAP_READ
                                                    ,   0
                                                    ,   0
                                                    ,   0);

                    if(NULL == memory)
                    {
                        on_error_("Failed to map view of file");
                    }
                    else
                    {
                        m_memory    =   memory;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
                        m_cb        =   (size_type(fileSizeHigh) << 32) | fileSizeLow;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
                        m_cb        =   fileSizeLow;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
                    }
                }
            }
        }
    }
    ~memory_mapped_file() stlsoft_throw_0()
    {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
        WINSTL_ASSERT(NULL != m_memory);
#else /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
        if(NULL != m_memory)
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            ::UnmapViewOfFile(m_memory);
        }
    }

/// \name Accessors
/// @{
public:
    void const  *memory() const
    {
        return m_memory;
    }

    size_type size() const
    {
        return m_cb;
    }

#ifndef __STLSOFT_CF_EXCEPTION_SUPPORT
    ws_dword_t lastError() const
    {
        return m_lastError;
    }
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}

/// \name Implementation
private:
    void on_error_(char const *message, ws_dword_t error = ::GetLastError())
    {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
        // The exception policy is used because VC++ 5 has a cow when it is
        // asked to throw a windows_exception, and this special case is
        // handled by windows_exception_policy
        windows_exception_policy    xp;

        xp(message, error);
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
        m_lastError = error;
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
    }

/// Members
private:
    size_type   m_cb;
    void        *m_memory;
#ifndef __STLSOFT_CF_EXCEPTION_SUPPORT
    ws_dword_t  m_lastError;
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */

// Not to be implemented
private:
    memory_mapped_file(class_type const &);
    class_type &operator =(class_type const &);
};

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

#endif /* !WINSTL_INCL_WINSTL_HPP_MEMORY_MAPPED_FILE */

/* ////////////////////////////////////////////////////////////////////////// */