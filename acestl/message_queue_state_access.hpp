/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/message_queue_state_access.hpp
 *
 * Purpose:     Helper functions for ACE_Message_Queue class.
 *
 * Created:     16th December 2004
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/// \file acestl/message_queue_state_access.hpp
///
/// Helper functions for ACE_Message_Queue class.

#ifndef ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS
#define ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS_MINOR     0
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS_REVISION  3
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS_EDIT      10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#include <ace/Message_Queue.h>              // for ACE_Message_Queue<>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_messaging Messaging Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating messaging constructs

/// \defgroup acestl_messaging_library Messaging Library (ACESTL)
/// \ingroup ACESTL libraries_messaging
/// \brief This library provides facilities for defining and manipulating messaging constructs with ACE
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

/// State access shim
template <ACE_SYNCH_DECL>
inline as_bool_t is_empty(ACE_Message_Queue<ACE_SYNCH_USE> const &q)
{
    // Have to cast this, as ACE is not const-correct with is_empty().

    return 0 != const_cast<ACE_Message_Queue<ACE_SYNCH_USE>&>(q).is_empty();
}

////////////////////////////////////////////////////////////////////////////////

/// @} // acestl_messaging_library

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_acestl_message_queue_state_access(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "ACESTL", "message_queue_state_access", __FILE__);

#if 0
            typedef message_queue_sequence<char>    env_var_t;

            env_var_t   path("PATH");

            if(0 != strcmp(getenv("PATH"), path))
            {
                r->report("message_queue_sequence<char> failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_acestl_message_queue_state_access(test_acestl_message_queue_state_access);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

namespace stlsoft
{

    using ::acestl::is_empty;

} // namespace stlsoft

#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_STATE_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
