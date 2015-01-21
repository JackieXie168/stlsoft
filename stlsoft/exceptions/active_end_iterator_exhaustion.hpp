/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exceptions/active_end_iterator_exhausation.hpp
 *
 * Purpose:     An exception thrown when an active end iterator is exhausted.
 *
 * Created:     30th November 2005
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/exceptions/active_end_iterator_exhausation.hpp
///
/// An exception thrown when an active end iterator is exhausted.

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION
#define STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION_MAJOR    1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION_MINOR    1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION_REVISION 1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION_EDIT     2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#include <exception>

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

/// An exception thrown when an active end iterator is exhausted
class active_end_iterator_exhaustion
    : public stlsoft_ns_qual_std(runtime_error)
{
/// \name Member Types
/// @{
public:
    typedef std::runtime_error              parent_class_type;
    typedef active_end_iterator_exhaustion  class_type;
/// @}

/// \name Construction
/// @{
public:
    active_end_iterator_exhaustion(char const *message)
        : parent_class_type(message)
    {}

    virtual ~active_end_iterator_exhaustion() throw()
    {}
/// @}

/// \name Accessors
/// @{
public:
    virtual char const *what() const throw()
    {
        char const *message =   parent_class_type::what();

        if( NULL == message ||
            '\0' == *message)
        {
            message = "Active End Iterator exhaustion";
        }

        return message;
    }
/// @}
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/active_end_iterator_exhaustion_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION */

/* ////////////////////////////////////////////////////////////////////////// */
