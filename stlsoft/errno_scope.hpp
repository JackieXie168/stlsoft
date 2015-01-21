/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/errno_scope.hpp (formerly MLTErrScp.h, ::SynesisStd)
 *
 * Purpose:     errno scoping class.
 *
 * Created:     28th November 1998
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/errno_scope.hpp
///
/// errno scoping class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ERRNO_SCOPE
#define STLSOFT_INCL_STLSOFT_HPP_ERRNO_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ERRNO_SCOPE_MAJOR      2
# define STLSOFT_VER_STLSOFT_HPP_ERRNO_SCOPE_MINOR      1
# define STLSOFT_VER_STLSOFT_HPP_ERRNO_SCOPE_REVISION   1
# define STLSOFT_VER_STLSOFT_HPP_ERRNO_SCOPE_EDIT       26
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#include <errno.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !_STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing system attributes
/// @{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Scopes the thread's last error
///
///
class errno_scope
{
public:
    typedef errno_scope    class_type;

/// \name Operations
/// @{
public:
    errno_scope() stlsoft_throw_0()
        : m_errno(errno)
    {}
    ss_explicit_k errno_scope(int errno_) stlsoft_throw_0()
        : m_errno(errno_)
    {
        errno = m_errno;
    }
    ~errno_scope() stlsoft_throw_0()
    {
        errno = m_errno;
    }

/// @}

/// \name Operations
/// @{
public:
    operator int () const
    {
        return m_errno;
    }

/// @}

// Members
private:
    int m_errno;

// Not to be implemented
private:
    errno_scope(errno_scope const &);
    errno_scope &operator =(errno_scope const &);
};

/* ////////////////////////////////////////////////////////////////////// */

/// @} // end of group libraries_system

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* !_STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_HPP_ERRNO_SCOPE */

/* ////////////////////////////////////////////////////////////////////// */
