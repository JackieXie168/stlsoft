/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/memory_mapped_file.hpp (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Memory mapped file class.
 *
 * Created:     15th December 1996
 * Updated:     14th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/memory_mapped_file.hpp
 *
 * \brief [C++ only] Definition of the winstl::memory_mapped_file class.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MAJOR     4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MINOR     0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_REVISION  2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_EDIT      67
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
#  include <winstl/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE
# include <stlsoft/smartptr/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

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

/** \brief Facade over the Win32 memory mapped file API.
 *
 * \ingroup group__file_system
 */
class memory_mapped_file
{
/// \name Member Types
/// @{
private:
    /// \brief The character type
    typedef ws_char_a_t                     char_type;
    /// \brief The traits type
    typedef filesystem_traits<ws_char_a_t>  traits_type;
public:
    /// \brief This type
    typedef memory_mapped_file              class_type;
    /// \brief The size type
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ws_uint64_t                     size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef ws_uint32_t                     size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// \brief The error type
    typedef ws_dword_t                      error_type;
/// @}

/// \name Implementation
/// @{
private:
    void open_(char_type const *fileName)
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
            else if(0 != fileSizeHigh)
            {
                on_error_("Cannot map files with sizes larger than 4GB with compilers that do not support 64-bit integers", ERROR_SUCCESS);
            }
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
            else if(0 == fileSizeHigh &&
                    0 == fileSizeLow)
            {
                m_memory    =   NULL;
                m_cb        =   0;
            }
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
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k memory_mapped_file(char_type const *fileName)
        : m_cb(0)
        , m_memory(NULL)
    {
        open_(fileName);
    }
    template <ss_typename_param_k S>
    ss_explicit_k memory_mapped_file(S const &fileName)
        : m_cb(0)
        , m_memory(NULL)
    {
        open_(stlsoft_ns_qual(c_str_ptr)(fileName));
    }
    ~memory_mapped_file() stlsoft_throw_0()
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        WINSTL_ASSERT(NULL != m_memory || 0 == m_cb);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        if(NULL != m_memory)
        {
            ::UnmapViewOfFile(m_memory);
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief Non-mutating (const) pointer to the start of the mapped
    ///  region.
    void const  *memory() const
    {
        return m_memory;
    }
    /// \brief The number of bytes in the mapped region
    size_type size() const
    {
        return m_cb;
    }

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    error_type lastError() const
    {
        return m_lastError;
    }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}

/// \name Implementation
/// @{
private:
    void on_error_(char const *message, error_type error = ::GetLastError())
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        // The exception policy is used because VC++ 5 has a cow when it is
        // asked to throw a windows_exception, and this special case is
        // handled by windows_exception_policy
        windows_exception_policy    xp;

        xp(message, error);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_lastError = error;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
/// @}

/// \name Members
/// @{
private:
    size_type   m_cb;
    void        *m_memory;
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    error_type  m_lastError;
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}

/// \name Not to be implemented
/// @{
private:
    memory_mapped_file(class_type const &);
    class_type &operator =(class_type const &);
/// @}
};

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */

/* ////////////////////////////////////////////////////////////////////// */
