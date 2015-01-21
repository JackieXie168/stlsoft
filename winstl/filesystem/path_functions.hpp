/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path_functions.hpp
 *
 * Purpose:     Helper functions for file handling
 *
 * Created:     6th June 2006
 * Updated:     17th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/path_functions.hpp
 *
 * \brief [C++ only] Helper functions for (text) file handling.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_REVISION   3
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_EDIT       5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
# include <winstl/filesystem/path.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */

# include <stlsoft/string_access.hpp>

#ifdef STLSOFT_UNITTEST
#endif // STLSOFT_UNITTEST

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <ss_typename_param_k C>
ws_size_t path_squeeze_impl(C const *path, ws_size_t pathLen, C *buffer, ws_size_t cchBuffer)
{
    typedef C                       char_t;
    typedef filesystem_traits<C>    traits_t;

    if(NULL != buffer)
    {
        basic_path<char_t>  p(path, pathLen);
        char_t const        *file_ptr   =   p.get_file();
        char_t const        *path_ptr   =   p.c_str();
        const ws_size_t     fileLen     =   p.size() - (file_ptr - path_ptr);

        if(cchBuffer >= pathLen)
        {
            // Room for all

            traits_t::str_n_copy(buffer, path_ptr, cchBuffer);

            cchBuffer = pathLen;
        }
        else
        {
            ws_size_t           rootLen;

            // Need to handle:
            //
            // 1. UNC
            // 2. drive
            // 3. rooted - begins with \ or /
            // 4. non-rooted

            if(p.is_rooted())
            {
                if(p.is_absolute())
                {
                    if(traits_t::is_path_UNC(path_ptr))
                    {
                        // 1. UNC

                        char_t const    *p1 =   traits_t::str_chr(path_ptr + 2, '\\');

                        rootLen = 1 + static_cast<ws_size_t>(p1 - path_ptr);
                    }
                    else
                    {
                        // 2. drive
                        rootLen = 3;
                    }
                }
                else
                {
                    // 3. rooted - begins with \ or /
                    rootLen = 1;
                }
            }
            else
            {
                // 4. non-rooted
                rootLen = 0;
            }

            if(cchBuffer < fileLen + rootLen + 3 + 1)
            {
                // File (name + ext) only

                traits_t::str_n_copy(buffer, file_ptr, cchBuffer);

                if(cchBuffer > fileLen)
                {
                    cchBuffer = fileLen;
                }
            }
            else if(cchBuffer < pathLen)
            {
                // Squeezing
                ws_size_t   rightLen    =   1 + fileLen;
                ws_size_t   leftLen     =   cchBuffer - (3 + rightLen);

                traits_t::str_n_copy(buffer, path_ptr, leftLen);
                buffer[leftLen + 0] = '.';
                buffer[leftLen + 1] = '.';
                buffer[leftLen + 2] = '.';
                traits_t::str_n_copy(buffer + leftLen + 3, file_ptr - 1, rightLen);
            }
        }
    }

    return cchBuffer;
}


template<ss_typename_param_k S>
ws_size_t path_squeeze_impl2(S const &path, ws_char_a_t *buffer, ws_size_t cchBuffer)
{
    return path_squeeze_impl(stlsoft_ns_qual(c_str_ptr_a)(path), stlsoft_ns_qual(c_str_len)(path), buffer, cchBuffer);
}

template<ss_typename_param_k S>
ws_size_t path_squeeze_impl2(S const &path, ws_char_w_t *buffer, ws_size_t cchBuffer)
{
    return path_squeeze_impl(stlsoft_ns_qual(c_str_ptr_w)(path), stlsoft_ns_qual(c_str_len)(path), buffer, cchBuffer);
}

#if 0
template <ss_typename_param_k C>
ws_size_t path_squeeze(C const *path, C *buffer, ws_size_t cchBuffer)
{
    typedef filesystem_traits<C>    traits_t;

    return path_squeeze_impl(path, traits_t::str_len(path), buffer, cchBuffer);
}
#endif /* 0 */

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
ws_size_t path_squeeze(S const &path, C *buffer, ws_size_t cchBuffer)
{
    return path_squeeze_impl2(path, buffer, cchBuffer);
}

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/path_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
