/* ////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/pipe.hpp (formerly unixstl_pipe.h)
 *
 * Purpose:     pipe class, based on Windows anonymous pipe.
 *
 * Created:     19th June 2004
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


/// \file unixstl/pipe.hpp
///
/// pipe class, based on Windows anonymous pipe.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_PIPE
#define UNIXSTL_INCL_UNIXSTL_HPP_PIPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_PIPE_MAJOR     3
# define UNIXSTL_VER_UNIXSTL_HPP_PIPE_MINOR     1
# define UNIXSTL_VER_UNIXSTL_HPP_PIPE_REVISION  1
# define UNIXSTL_VER_UNIXSTL_HPP_PIPE_EDIT      25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
# include <unixstl/exceptions.hpp>    // unix_exception
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */

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

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This needs to be parameterised with a unixstl::system_resource_policy, which would control whether to throw if MX create fails"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/// Class which wraps the UNIX pipe() function
class pipe
{
public:
    /// The class type
    typedef pipe                    class_type;
    /// The exception policy type
    typedef unix_exception_policy   exception_policy_type;

/// \name Construction
/// @{
public:
    pipe()
    {
#if defined(WIN32) && \
    defined(_MSC_VER)
        if(0 != ::_pipe(&m_handles[0], 10240, _O_TEXT))
#else /* ? WIN32 && STLSOFT_COMPILER_IS_MSVC */
        if(0 != ::pipe(&m_handles[0]))
#endif /* WIN32 && STLSOFT_COMPILER_IS_MSVC */
        {
            exception_policy_type()(errno);

            m_handles[0] = -1;
            m_handles[1] = -1;
        }
    }

    ~pipe() stlsoft_throw_0()
    {
        if(-1 != read_handle())
        {
            ::close(m_handles[0]);
        }
        if(-1 != write_handle())
        {
            ::close(m_handles[1]);
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief Returns the read handle of the pipe
    int read_handle() const
    {
        return m_handles[0];
    }
    int write_handle() const
    {
        return m_handles[1];
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Closes the read handle, if not already closed
    void close_read()
    {
        if(-1 != read_handle())
        {
            ::close(m_handles[0]);
            m_handles[0] = -1;
        }
    }
    /// \brief Closes the write handle, if not already closed
    void close_write()
    {
        if(-1 != write_handle())
        {
            ::close(m_handles[1]);
            m_handles[1] = -1;
        }
    }
    /// \brief Closes the read and write handles, if not already closed
    void close()
    {
        close_read();
        close_write();
    }
/// @}

private:
    int m_handles[2];

// Not to be implemented
private:
    pipe(class_type const &);
    class_type &operator =(class_type const &);
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/pipe_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_PIPE */

/* ////////////////////////////////////////////////////////////////////////// */
