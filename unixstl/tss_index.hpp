/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/tss_index.hpp (formerly in MUTlsFns.h, ::SynesisUnix)
 *
 * Purpose:     UNIX TSS slot index.
 *
 * Created:     21st January 1999
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2005, Matthew Wilson and Synesis Software
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


/// \file unixstl/tss_index.hpp
///
/// UNIX TSS slot index.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_TSS_INDEX
#define UNIXSTL_INCL_UNIXSTL_HPP_TSS_INDEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_TSS_INDEX_MAJOR    2
# define UNIXSTL_VER_UNIXSTL_HPP_TSS_INDEX_MINOR    2
# define UNIXSTL_VER_UNIXSTL_HPP_TSS_INDEX_REVISION 1
# define UNIXSTL_VER_UNIXSTL_HPP_TSS_INDEX_EDIT     30
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
# include <unixstl/exceptions.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */
#if !defined(_REENTRANT)
# error unixstl/tss_index.hpp cannot be included in non-multithreaded compilation. _REENTRANT must be defined
#endif /* !_REENTRANT */
#include <pthread.h>

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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing system attributes

/// \defgroup unixstl_system_library System Library (UNIXSTL)
/// \ingroup UNIXSTL libraries_system
/// \brief This library provides facilities for accessing UNIX system attributes
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Exception thrown by the tss_index class
class tss_exception
    : public unix_exception
{
/// \name Types
/// @{
public:
    typedef unix_exception  parent_class_type;
    typedef tss_exception   class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k tss_exception(int err)
        : parent_class_type(err)
    {}
/// @}
};


/// A TSS index
///
///
class tss_index
{
/// \name Types
/// @{
public:
    typedef tss_index       class_type;
    typedef pthread_key_t   index_type;
    typedef void            *value_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k tss_index()
        : m_index(index_create_())
    {}
    ~tss_index() stlsoft_throw_0()
    {
        index_destroy_(m_index);
    }
/// @}

/// \name Operations
/// @{
public:
    void        set_value(value_type value)
    {
        class_type::set_slot_value_(m_index, value);
    }
    value_type  get_value() const
    {
        return class_type::get_slot_value_(m_index);
    }
/// @}

/// \name Accessors
/// @{
public:
    operator index_type () const
    {
        return m_index;
    }
/// @}

/// \name Implementation
/// @{
private:
    static index_type index_create_()
    {
        index_type  index;
        int         res =   ::pthread_key_create(&index, NULL);

        if(0 != res)
        {
            throw tss_exception(res);
        }

        return index;
    }

    static void index_destroy_(index_type index)
    {
        ::pthread_key_delete(index);
    }

    static void set_slot_value_(index_type index, value_type value)
    {
        ::pthread_setspecific(index, value);
    }

    static value_type get_slot_value_(index_type index)
    {
        return ::pthread_getspecific(index);
    }
/// @}

// Members
private:
    index_type  m_index;

// Not to be implemented
private:
    tss_index(tss_index const &);
    tss_index &operator =(tss_index const &);
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group unixstl_system_library

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

#endif /* UNIXSTL_INCL_UNIXSTL_HPP_TSS_INDEX */

/* ////////////////////////////////////////////////////////////////////////// */
