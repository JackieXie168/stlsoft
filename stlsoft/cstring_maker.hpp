/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/cstring_maker.hpp (formerly stlsoft_cstring_maker.h)
 *
 * Purpose:     Simple utility class for creating (constant) C-strings.
 *
 * Created:     14th May 2004
 * Updated:     18th December 2005
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


/// \file stlsoft/cstring_maker.hpp
///
/// Simple utility class for creating (constant) C-strings.

#ifndef STLSOFT_INCL_STLSOFT_HPP_CSTRING_MAKER
#define STLSOFT_INCL_STLSOFT_HPP_CSTRING_MAKER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_MAKER_MAJOR    3
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_MAKER_MINOR    1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_MAKER_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_MAKER_EDIT     30
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE
# include <stlsoft/allocator_base.hpp>          // feature discrimination
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR
# include <stlsoft/malloc_allocator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp>             // stlsoft::char_traits
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */

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

#ifndef _STLSOFT_NO_NAMESPACE
namespace
{
#endif /* _STLSOFT_NO_NAMESPACE */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
struct char_to_byte__traits_
{
    static ss_size_t byte_size_(ss_size_t cch)
    {
        return cch * sizeof(C);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct char_to_byte__traits_<ss_char_a_t>
{
    static ss_size_t byte_size_(ss_size_t cch)
    {
        return cch;
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef _STLSOFT_NO_NAMESPACE
} // anonymous namespace
#endif /* _STLSOFT_NO_NAMESPACE */

/// Utility class that creates/destroys fixed-size C-strings for other classes
#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) || \
    (   (   !defined(STLSOFT_COMPILER_IS_GCC) || \
        __GNUC__ >= 3) && \
        (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
            _MSC_VER != 1100))
template<   ss_typename_param_k C
        ,   ss_typename_param_k A = malloc_allocator<C>
        ,   ss_typename_param_k T = stlsoft_char_traits<C>
        >
struct cstring_maker
{
    typedef C                       char_type;
    typedef A                       allocator_type;
    typedef T                       traits_type;
    typedef ss_size_t               size_type;
    typedef cstring_maker<C, A, T>  class_type;

private:
    struct block
    {
        size_type   n;
        char_type   data[1];
    };

public:
    /// Allocates uninitialised storage for writing into a string
    ///
    /// \note Includes space for a nul-terminator character
    ///
    /// \param cch The number of characters to allocate
    static char_type *alloc(size_type cch)
    {
#if defined(WIN32) || \
    defined(_WIN32)
        cch = char_to_byte__traits_<char_type>::byte_size_(cch);
#endif /* WIN32 || _WIN32 */

        size_type   cb      =   offsetof(block, data) + sizeof(char_type) * (1 + cch);

#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
        ss_typename_type_k allocator_type::ss_template_qual_k rebind<ss_byte_t>::other  byte_ator;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
        malloc_allocator<ss_byte_t>                                                     byte_ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

        cb = (cb + 31) & ~31;

        block       *pblock =   static_cast<block*>(static_cast<void*>(byte_ator.allocate(cb, NULL)));

        if(NULL == pblock)
        {
            return NULL;
        }
        else
        {
            pblock->n = cch;
            pblock->data[cch] = '\0';

            return &pblock->data[0];
        }
    }
    /// Allocates a new copy of the given string
    ///
    /// \note Includes nul-terminator character
    ///
    /// \param s The string to copy. Cannot be null pointer
    static char_type *dup(char_type const *s)
    {
        STLSOFT_ASSERT(NULL != s);

        size_type   len =   traits_type::length(s);
        char_type   *s_ =   alloc(len);

        if(NULL != s_)
        {
            traits_type::copy(s_, s, 1 + len);
        }

        return s_;
    }
    /// Allocates a new copy of the given string, or returns NULL if given null string
    ///
    /// \note Includes nul-terminator character
    ///
    /// \param s The string to copy. Can be null pointer, in which case NULL is returned
    static char_type *dup_null(char_type const *s)
    {
        return (NULL == s) ? NULL : dup(s);
    }
    /// Releases the storage associated with the string
    ///
    /// \param s The string to free
    static void free(char_type *s)
    {
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
        ss_typename_type_k allocator_type::ss_template_qual_k rebind<ss_byte_t>::other  byte_ator;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
        malloc_allocator<ss_byte_t>                                                     byte_ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

        if(NULL != s)
        {
            union
            {
                ss_byte_t   *py;
                block       *pblock;
            }   u;

            u.py = static_cast<ss_byte_t*>(static_cast<void*>(s)) - offsetof(block, data);

            STLSOFT_ASSERT(u.pblock->data[u.pblock->n] == '\0');

            byte_ator.deallocate(u.py, u.pblock->n);
        }
    }
};
#else /* ? _MSC_VER */
template<   ss_typename_param_k C
        >
struct cstring_maker;


STLSOFT_TEMPLATE_SPECIALISATION
struct cstring_maker<char>
{
public:
    typedef char                        char_type;
    typedef malloc_allocator<char_type> allocator_type;
    typedef char_traits<char_type>      traits_type;
    typedef ss_size_t                   size_type;
    typedef cstring_maker<char_type>    class_type;

public:
    static char_type *alloc(size_type cch)
    {
        return static_cast<char_type*>(malloc((1 + cch) * sizeof(char_type)));
    }
    static char_type *dup(char_type const *s)
    {
        return strdup(s);
    }
    static char_type *dup_null(char_type const *s)
    {
        return (NULL == s) ? NULL : dup(s);
    }
    static void free(char_type *s)
    {
        ::free(s);
    }
};


# if !defined(STLSOFT_COMPILER_IS_GCC)

STLSOFT_TEMPLATE_SPECIALISATION
struct cstring_maker<wchar_t>
{
public:
    typedef wchar_t                     char_type;
    typedef malloc_allocator<char_type> allocator_type;
    typedef char_traits<char_type>      traits_type;
    typedef ss_size_t                   size_type;
    typedef cstring_maker<char_type>    class_type;

public:
    static char_type *alloc(size_type cch)
    {
        return static_cast<char_type*>(malloc((1 + cch) * sizeof(char_type)));
    }
    static char_type *dup(char_type const *s)
    {
        return _wcsdup(s);
    }
    static char_type *dup_null(char_type const *s)
    {
        return (NULL == s) ? NULL : dup(s);
    }
    static void free(char_type *s)
    {
        ::free(s);
    }
};
# endif /* !STLSOFT_COMPILER_IS_GCC */

#endif /* _MSC_VER != 1100 */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/cstring_maker_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_CSTRING_MAKER */

/* ////////////////////////////////////////////////////////////////////////// */
