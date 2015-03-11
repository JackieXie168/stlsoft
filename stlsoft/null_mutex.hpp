/* ////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/null_mutex.hpp (originally stlsoft_null_mutex.h; formerly MLMutex.h, ::SynesisStd)
 *
 * Purpose:     Mutual exclusion model class.
 *
 * Created:     19th December 1997
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/null_mutex.hpp
///
/// Mutual exclusion model class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_NULL_MUTEX
#define STLSOFT_INCL_STLSOFT_HPP_NULL_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_NULL_MUTEX_MAJOR       3
# define STLSOFT_VER_STLSOFT_HPP_NULL_MUTEX_MINOR       1
# define STLSOFT_VER_STLSOFT_HPP_NULL_MUTEX_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_NULL_MUTEX_EDIT        30
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class null_mutex

/// This class provides a null implementation of the mutex model
class null_mutex
{
public:
    typedef null_mutex class_type;

// Construction
public:
    /// Creates an instance of the mutex
    null_mutex() stlsoft_throw_0()
    {}

// Operations
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is aquired
    void lock() stlsoft_throw_0()
    {}
    /// Releases an aquired lock on the mutex
    void unlock() stlsoft_throw_0()
    {}

// Not to be implemented
private:
    null_mutex(class_type const &rhs);
    null_mutex &operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Control shims
 */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_sync_control Synchronisation Control Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" control the behaviour of synchronisation objects

/// \defgroup stlsoft_sync_control_shims Synchronisation Control Shims (STLSoft)
/// \ingroup STLSoft concepts_shims_sync_control
/// \brief These \ref concepts_shims "shims" control the behaviour of synchronisation objects
/// @{

/// This control \ref concepts_shims "shim" aquires a lock on the given mutex
///
/// \param mx The mutex on which to aquire the lock
inline void lock_instance(null_mutex &mx)
{
    STLSOFT_SUPPRESS_UNUSED(mx); // This is used, instead of the preferred omission of parameter, since it upsets the documentation
}

/// This control ref concepts_shims "shim" releases a lock on the given mutex
///
/// \param mx The mutex on which to release the lock
inline void unlock_instance(null_mutex &mx)
{
    STLSOFT_SUPPRESS_UNUSED(mx); // This is used, instead of the preferred omission of parameter, since it upsets the documentation
}

/// @} // end of group stlsoft_sync_control_shims

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/null_mutex_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_NULL_MUTEX */

/* ////////////////////////////////////////////////////////////////////////// */
