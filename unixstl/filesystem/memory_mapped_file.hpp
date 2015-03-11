/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/memory_mapped_file.hpp (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Memory mapped file class.
 *
 * Created:     15th December 1996
 * Updated:     16th July 2006
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


/** \file unixstl/filesystem/memory_mapped_file.hpp
 *
 * \brief [C++ only] Definition of the unixstl::memory_mapped_file class.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MAJOR       4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MINOR       1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_REVISION    1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_EDIT        68
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_UNIXSTL_HPP_ERROR_UNIX_EXCEPTIONS
#  include <unixstl/error/exceptions.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_ERROR_HPP_UNIX_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE
# include <stlsoft/smartptr/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#include <sys/mman.h>
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

/** \brief Facade over the UNIX memory mapped file API.
 *
 * \ingroup group__file_system
 */
class memory_mapped_file
{
/// \name Member Types
/// @{
private:
    /// \brief The character type
    typedef us_char_a_t                     char_type;
    /// \brief The traits type
    typedef filesystem_traits<us_char_a_t>  traits_type;
public:
    /// \brief This type
    typedef memory_mapped_file              class_type;
    /// \brief The size type
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef us_uint64_t                     size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef us_uint32_t                     size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// \brief The error type
    typedef int                             error_type;
/// @}

/// \name Implementation
/// @{
private:
    void open_(char_type const *fileName)
    {
        scoped_handle<int>  hfile(  traits_type::open(  fileName
                                                    ,   O_RDONLY
                                                    ,   PROT_READ)
                                ,   &filesystem_traits<char_type>::close
                                ,   -1);

        if(hfile.empty())
        {
            on_error_("Failed to open file for mapping");
        }
        else
        {
            struct stat st;

            if(0 != ::fstat(::stlsoft::get_handle(hfile), &st))
            {
                on_error_("Failed to determine mapped file size");
            }
            else if(0 == st.st_size)
            {
                m_memory    =   NULL;
                m_cb        =   0;
            }
            else
            {
                void    *memory = ::mmap(NULL, st.st_size, PROT_READ, 0, ::stlsoft::get_handle(hfile), 0);

                if(MAP_FAILED == memory)
                {
                    on_error_("Failed to map view of file");
                }
                else
                {
                    m_memory    =   memory;
                    m_cb        =   st.st_size;
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
        UNIXSTL_ASSERT(NULL != m_memory || 0 == m_cb);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        if(NULL != m_memory)
        {
            ::munmap(m_memory, static_cast<size_t>(m_cb));
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
    void on_error_(char const *message, error_type error = errno)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw unix_exception(message, error);
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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */

/* ////////////////////////////////////////////////////////////////////// */
