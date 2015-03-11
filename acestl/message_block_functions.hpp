/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/message_block_functions.hpp
 *
 * Purpose:     Helper functions for ACE_Message_Block (and ACE_Data_Block) classes.
 *
 * Created:     23rd September 2004
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file acestl/message_block_functions.hpp
///
/// Helper functions for ACE_Message_Block (and ACE_Data_Block) classes.

#ifndef ACESTL_INCL_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS
#define ACESTL_INCL_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS_MAJOR      1
# define ACESTL_VER_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS_MINOR      2
# define ACESTL_VER_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS_REVISION   1
# define ACESTL_VER_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS_EDIT       17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#include <ace/Message_Block.h>      // for ACE_Message_Block
#include <ace/OS_Memory.h>          // for ACE_bad_alloc, ACE_NEW_THROWS_EXCEPTIONS

/* /////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_messaging Messaging Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating messaging constructs

/// \defgroup acestl_messaging_library Messaging Library (ACESTL)
/// \ingroup ACESTL libraries_messaging functions
/// \brief This library provides facilities for defining and manipulating messaging constructs with ACE
/// @{

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/// \brief Creates a new ACE_Message_Block instance whose contents are copied
/// from the given memory.
///
/// \param p Pointer to the memory to copy into the new message block. Can be NULL
/// \param n Number of bytes to copy into the new message block
///
/// Usage is extremely simple. Just specify the source (pointer and length), and
/// test for NULL (allocation failure):
///
/// \htmlonly
/// <pre>
///
/// ACE_Message_Block *newBlock = acestl::make_copied_Message_Block("Contents", 7);
///
/// if(NULL == newBlock)
/// {
///   fprintf(stderr, "Allocation failed!\n");
/// }
///
/// </pre>
/// \endhtmlonly
inline ACE_Message_Block *make_copied_Message_Block(char const *p, size_t n)
{
#if defined(ACE_NEW_THROWS_EXCEPTIONS)
    try
    {
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
        ACE_Message_Block *pmb = new ACE_Message_Block(n);

        if(NULL == pmb)
        {
            errno = ENOMEM;
        }
        else
        {
            pmb->wr_ptr(n);

            if(NULL != p)
            {
                ::memcpy(pmb->base(), p, n);
            }
        }

        return pmb;
#if defined(ACE_NEW_THROWS_EXCEPTIONS)
    }
    catch(ACE_bad_alloc) // TODO: This should be a reference, surely??
    {
        return NULL;
    }
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
}

#if defined(STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)

template <ss_size_t N>
inline ACE_Message_Block *make_copied_Message_Block(const char (&ar)[N])
{
    return make_copied_Message_Block(&ar[0], N);
}

#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

////////////////////////////////////////////////////////////////////////////

/// @} // acestl_messaging_library

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/message_block_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
