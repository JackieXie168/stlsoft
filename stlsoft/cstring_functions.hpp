/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/cstring_functions.hpp
 *
 * Purpose:     String duplication functions.
 *
 * Created:     26th May 2005
 * Updated:     25th March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/cstring_functions.hpp
///
/// String duplication functions.

#ifndef STLSOFT_INCL_STLSOFT_HPP_CSTRING_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_HPP_CSTRING_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_FUNCTIONS_MAJOR    1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_FUNCTIONS_MINOR    3
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_FUNCTIONS_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_CSTRING_FUNCTIONS_EDIT     15
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>	// for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */

#ifdef STLSOFT_UNITTEST
# include <stlsoft/memory/malloc_allocator.hpp>
# include <stlsoft/memory/new_allocator.hpp>
# include <string.h>
#endif /* STLSOFT_UNITTEST */

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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// \brief Allocates a copy of the string, using the given allocator
///
/// \param str The string to copy
/// \param cch The number of elements in str to copy
/// \param ator The allocator to use to allocate the memory
///
/// \note The caller is responsible for the allocated memory, and should free it
/// with ator (or a compatible allocator or memory function).
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C *string_dup_impl(C const *str, size_t cch, A &ator)
{
    C   *r  =   ator.allocate(1 + cch);

    char_traits<C>::copy(r, str, cch);
    r[cch] = '\0';

    return r;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// \brief Allocates a copy of the string, using the given allocator
///
/// \param str The string to copy
/// \param cch The number of elements in str to copy
/// \param ator The allocator to use to allocate the memory
///
/// \note The caller is responsible for the allocated memory, and should free it
/// with ator (or a compatible allocator or memory function).
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C *string_dup(C const *str, size_t cch, A &ator)
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    typedef C                                                           char_t;
    typedef ss_typename_type_k A::ss_template_qual_k rebind<C>::other   ator_t;

    ator_t  ator_;

    STLSOFT_SUPPRESS_UNUSED(ator);

    return string_dup_impl(str, cch, ator_);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    return string_dup_impl(str, cch, ator);
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
}

/// \brief Allocates a copy of the string, using the given allocator
///
/// \param str The string to copy
/// \param ator The allocator to use to allocate the memory
///
/// \note The caller is responsible for the allocated memory, and should free it
/// with ator (or a compatible allocator or memory function).
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C *string_dup(C const *str, A &ator)
{
    return string_dup(str, c_str_len(str), ator);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_cstring_functions(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "cstring_functions", __FILE__);

            static const char       sz1[]       =   "";
            static const char       sz2[]       =   "string 1";

            char                    *ds1;
            char                    *ds2;

# ifdef STLSOFT_CF_THROW_BAD_ALLOC
            try
            {
# endif /* STLSOFT_CF_THROW_BAD_ALLOC */
                {
                    malloc_allocator<char>  ator;

                    ds1 = string_dup(sz1, ator);
                }
# ifdef STLSOFT_CF_THROW_BAD_ALLOC
            }
            catch(stlsoft_ns_qual_std(bad_alloc) &)
            {
                ds1 = NULL;
            }
# endif /* STLSOFT_CF_THROW_BAD_ALLOC */

# ifdef STLSOFT_CF_THROW_BAD_ALLOC
            try
            {
# endif /* STLSOFT_CF_THROW_BAD_ALLOC */
                {
                    new_allocator<char>     ator;

                    ds2 = string_dup(sz2, ator);
                }
# ifdef STLSOFT_CF_THROW_BAD_ALLOC
            }
            catch(stlsoft_ns_qual_std(bad_alloc) &)
            {
                ds2 = NULL;
            }
# endif /* STLSOFT_CF_THROW_BAD_ALLOC */

            if( NULL != ds1 &&
                0 != ::strcmp(sz1, ds1))
            {
                r->report("string_dup() (with non-empty string) failed", __LINE__);
                bSuccess = false;
            }

            if( NULL != ds2 &&
                0 != ::strcmp(sz2, ds2))
            {
                r->report("string_dup() (with empty string) failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_cstring_functions(test_stlsoft_cstring_functions);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_CSTRING_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
