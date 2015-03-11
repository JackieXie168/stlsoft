/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/memory_mapped_file.hpp (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Memory mapped file class.
 *
 * Created:     15th December 1996
 * Updated:     15th December 2005
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


/// \file unixstl/memory_mapped_file.hpp
///
/// Memory mapped file class.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_MEMORY_MAPPED_FILE
#define UNIXSTL_INCL_UNIXSTL_HPP_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_MEMORY_MAPPED_FILE_MAJOR       3
# define UNIXSTL_VER_UNIXSTL_HPP_MEMORY_MAPPED_FILE_MINOR       2
# define UNIXSTL_VER_UNIXSTL_HPP_MEMORY_MAPPED_FILE_REVISION    1
# define UNIXSTL_VER_UNIXSTL_HPP_MEMORY_MAPPED_FILE_EDIT        58
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS */
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
#  include <unixstl/exceptions.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE
# include <stlsoft/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */
#include <sys/mman.h>
#include <sys/stat.h>

/* /////////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Facade over the UNIX memory mapped file API
class memory_mapped_file
{
private:
    typedef us_char_a_t                     char_type;
    typedef filesystem_traits<us_char_a_t>  traits_type;
public:
    typedef memory_mapped_file              class_type;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef us_uint64_t                     size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef us_uint32_t                     size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

public:
#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Make this use a create_() method via MUMI"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

    ss_explicit_k memory_mapped_file(char_type const *fileName)
        : m_cb(0)
        , m_memory(NULL)
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
#ifndef STLSOFT_CF_64BIT_INT_SUPPORT
            else if(0 == fileSizeHigh)
            {
                on_error_("Cannot map files with sizes larger than 4GB with compilers that do not support 64-bit integers", ETOBIG);
            }
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
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
    ~memory_mapped_file() stlsoft_throw_0()
    {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
        UNIXSTL_ASSERT(NULL != m_memory);
#else /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
        if(NULL != m_memory)
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            ::munmap(m_memory, static_cast<size_t>(m_cb));
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
    int lastError() const
    {
        return m_lastError;
    }
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}

/// \name Implementation
private:
    void on_error_(char const *message, int error = errno)
    {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
        throw unix_exception(message, error);
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
        m_lastError = error;
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
    }

/// Members
private:
    size_type   m_cb;
    void        *m_memory;
#ifndef __STLSOFT_CF_EXCEPTION_SUPPORT
    int         m_lastError;
#endif /* !__STLSOFT_CF_EXCEPTION_SUPPORT */

// Not to be implemented
private:
    memory_mapped_file(class_type const &);
    class_type &operator =(class_type const &);
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_MEMORY_MAPPED_FILE */

/* ////////////////////////////////////////////////////////////////////////// */
