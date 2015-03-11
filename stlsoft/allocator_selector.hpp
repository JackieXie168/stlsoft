/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/allocator_selector.hpp
 *
 * Purpose:     Selects the most appropriate allocator.
 *
 * Created:     20th August 2005
 * Updated:     24th December 2005
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


/// \file stlsoft/allocator_selector.hpp
///
/// Selects the most appropriate allocator.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR
#define STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_SELECTOR_MAJOR       1
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_SELECTOR_MINOR       3
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_SELECTOR_REVISION    2
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_SELECTOR_EDIT        10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* Chosen allocator
 *
 * 
 */

#if defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_MALLOC_ALLOCATOR) && \
    defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR)
  /* Prevent use of malloc_allocator. */
# undef STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR
#endif /* allocator */

#if defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_NEW_ALLOCATOR) && \
    defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR)
  /* Prevent use of new_allocator. */
# undef STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR
#endif /* allocator */

#if defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STD_ALLOCATOR) && \
    defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR)
  /* Prevent use of std::allocator. */
# undef STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR
#endif /* allocator */



#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ < 0x0845) || \
    (   defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3)
 // Something's wrong with Borland - big shock! - that causes crashes in deallocation
 //
 // Same for GCC 2.95
 //
 // With DMC++, it crashes the compiler!! ;-(
# define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR
#elif defined(STLSOFT_COMPILER_IS_WATCOM)
 // Watcom's got major problems, so we use malloc_allocator
# define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR
#else
 // Now we work out which to select by default for each 
# if !defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR) && \
     !defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR) && \
     !defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR)
#  if !defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STD_ALLOCATOR)
#   define STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR
#  elif !defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_NEW_ALLOCATOR)
#   define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR
#  elif !defined(STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_MALLOC_ALLOCATOR)
#   define STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR
#  else
#   error All allocator types disabled. You must enable one or more, by disabling one or more of the 
#   error symbols STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STD_ALLOCATOR, 
#   error STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_NEW_ALLOCATOR
#   error or STLSOFT_ALLOCATOR_SELECTOR_NO_USE_STLSOFT_MALLOC_ALLOCATOR.
#  endif
# endif
#endif /* allocator */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#if defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR)
# ifndef STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR
#  include <stlsoft/malloc_allocator.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR */
#elif defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR)
# ifndef STLSOFT_INCL_STLSOFT_HPP_NEW_ALLOCATOR
#  include <stlsoft/new_allocator.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_NEW_ALLOCATOR */
#elif defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR)
# include <memory>
#else
# error Error in discrimination. allocator_selector must select either std::allocator, stlsoft::malloc_allocator or stlsoft::new_allocator
#endif /* STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR */

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

template <ss_typename_param_k T>
struct allocator_selector
{
#if defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_MALLOC_ALLOCATOR)
    typedef malloc_allocator<T>                 allocator_type;
#elif defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STLSOFT_NEW_ALLOCATOR)
    typedef new_allocator<T>                    allocator_type;
#elif defined(STLSOFT_ALLOCATOR_SELECTOR_USE_STD_ALLOCATOR)
    typedef stlsoft_ns_qual_std(allocator)<T>   allocator_type;
#else
# error Error in discrimination. allocator_selector must select either std::allocator, stlsoft::malloc_allocator or stlsoft::new_allocator
#endif /* allocator */
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_SELECTOR */

/* ////////////////////////////////////////////////////////////////////////// */