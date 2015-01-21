/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/file_functions.hpp
 *
 * Purpose:     Helper functions for file handling
 *
 * Created:     1st January 2005
 * Updated:     26th December 2005
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


/// \file winstl/file_functions.hpp
///
/// Helper functions for file handling.

#ifndef WINSTL_INCL_WINSTL_HPP_FILE_FUNCTIONS
#define WINSTL_INCL_WINSTL_HPP_FILE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_FILE_FUNCTIONS_MAJOR     1
# define WINSTL_VER_WINSTL_HPP_FILE_FUNCTIONS_MINOR     4
# define WINSTL_VER_WINSTL_HPP_FILE_FUNCTIONS_REVISION  1
# define WINSTL_VER_WINSTL_HPP_FILE_FUNCTIONS_EDIT      20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
# include <winstl/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE
# include <stlsoft/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_TRAITS
# include <stlsoft/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_TOKENISER_FUNCTIONS
# include <stlsoft/tokeniser_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_TOKENISER_FUNCTIONS */

#ifdef STLSOFT_UNITTEST
# include <stlsoft/simple_string.hpp>
#endif // STLSOFT_UNITTEST

/* /////////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file_impl(S1 const &fileName, S2 &contents);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// \brief Loads a text file into a string
///
/// \param fileName The name/path of the text file to load. Can be nul-terminated 
///                  C-style string, or a string object
/// \param contents A reference to a string instance into which the contents will
///                  be loaded (with the assign() method)
///
/// \return The number of bytes read from the file
///
/// \note The character type of the text file is assumed (and controlled) to be
/// that of the \c contents parameter. For example, if \c contents is of type
/// \c std::wstring then the file will be processed as if it contains \c wchar_t.
template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file(S1 const &fileName, S2 &contents)
{
    return load_text_file_impl<S1, S2>(fileName, contents);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file_impl(S1 const &fileName, S2 &contents)
{
    typedef string_traits<S1>                               string_traits_t;

    STLSOFT_STATIC_ASSERT(sizeof(string_traits_t));     // Fires if S1 does not have a traits specialisation defined

    typedef string_traits<S2>                               string_traits2_t;

    STLSOFT_STATIC_ASSERT(sizeof(string_traits2_t));    // Fires if S2 does not have a traits specialisation defined

    typedef ss_typename_type_k string_traits_t::char_type   C;

    STLSOFT_STATIC_ASSERT(sizeof(C));                   // Fires if the traits is not correctly defined

    typedef ss_typename_type_k string_traits2_t::char_type  char_2_type;

    STLSOFT_STATIC_ASSERT(sizeof(char_2_type));         // Fires if the traits is not correctly defined

    typedef filesystem_traits<C>                            filesys_traits_t;

    STLSOFT_STATIC_ASSERT(sizeof(filesys_traits_t));    // Fires if no corresponding filesystem_traits defined

    scoped_handle<HANDLE>   h(  filesys_traits_t::create_file(  stlsoft_ns_qual(c_str_ptr)(fileName)
                                                            ,   GENERIC_READ
                                                            ,   FILE_SHARE_READ
                                                            ,   NULL
                                                            ,   OPEN_EXISTING
                                                            ,   0
                                                            ,   NULL)
                            ,   (void (__cdecl *)(HANDLE))&filesys_traits_t::close_handle
                            ,   INVALID_HANDLE_VALUE);

    ws_uint64_t             size    =   filesys_traits_t::get_file_size(::stlsoft::get_handle(h));

    if( 0 != size &&
        static_cast<ws_uint64_t>(~0) != size)
    {
        if(size > 0xFFFFFFFF)
        {
            throw std::out_of_range("Cannot read in files larger than 4GB");
        }
        else
        {
// TODO: Catch the out-of-memory exception and translate to a std::out_of_range()

            typedef ::stlsoft::auto_buffer< char_2_type
                                        ,   processheap_allocator<char_2_type>
                                        ,   1024
                                        >                   buffer_t;

            buffer_t    buffer(static_cast<ss_typename_type_k buffer_t::size_type>(size));
            DWORD       dw;

            if(!::ReadFile(::stlsoft::get_handle(h), &buffer[0], buffer.size(), &dw, NULL))
            {
                throw winstl::windows_exception("Read operation failed", ::GetLastError());
            }
            else
            {
                contents.assign(&buffer[0], dw);

                return size;
            }
        }
    }

    return 0;
}

#if !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER != 1300)

template<   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file(ws_char_a_t const *fileName, S2 &contents)
{
    return load_text_file_impl<ws_char_a_t const*, S2>(fileName, contents);
}

template<   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file(ws_char_w_t const *fileName, S2 &contents)
{
    return load_text_file_impl<ws_char_w_t const*, S2>(fileName, contents);
}

#if 0
template<   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file(char fileName[], S2 &contents)
{
    return load_text_file_impl<ws_char_a_t const*, S2>(fileName, contents);
}

template<   ss_typename_param_k S2
        >
inline ws_uint64_t load_text_file(ws_char_w_t *fileName, S2 &contents)
{
    return load_text_file_impl<ws_char_w_t const*, S2>(fileName, contents);
}
#endif /* 0 */

#endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

















#if 0
template<   ss_typename_param_k S
        >
struct trim_trailing_carriage_return
{
public:
    S operator ()(S const &s)
    {
        ss_size_t   len =   stlsoft_ns_qual(c_str_len)(s);

        if( len > 0 &&
            '\r' == s[len])
        {
            return s;
        }

        return S(stlsoft_ns_qual(c_str_ptr)(s), len - 1);
    }
};
#endif /* 0 */

template<   ss_typename_param_k CH
        ,   ss_typename_param_k C
        >
void readlines_impl(CH const *p, ss_size_t len, C &container)
{
    typedef CH                                  char_t;
    typedef ss_typename_type_k C::value_type    value_t;

    char_t const *p0     =   p;
    char_t const *p1     =   p0;
    char_t const *end    =   p + len;

    while(end != stlsoft_ns_qual(find_next_token)(p0, p1, end, '\n'))
    {
        if( p1 > p0 &&
            '\r' == p1[-1])
        {
            --p1;
        }

        container.push_back(value_t(p0, static_cast<size_t>(p1 - p0)));

        if('\r' == *p1)
        {
            ++p1;
        }
    }
}

/// \brief Reads the lines of a text-file into a sequence container
///
/// \param fileName The name of the text-file to load
/// \param container Reference to the sequence container to which each line read from \c fileName will be appended (via its push_back() method)
///
/// \returns The \c container reference
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
C &readlines(S const &fileName, C &container)
{
    S   contents;
    S   delim;

    // NOTE: doing these as characters skips the issue of ANSI vs Unicode
    delim.append(1, '\n');

    load_text_file(fileName, contents);

#if 0
    stlsoft::string_tokeniser<  S /* stlsoft::basic_string_view<ss_typename_type_k stlsoft::string_traits<S>::char_type> */
                            ,   S
                            ,   stlsoft::string_tokeniser_ignore_blanks<false>
                            >           tokens(contents, delim);

    std::transform(tokens.begin(), tokens.end(), std::back_inserter(container), trim_trailing_carriage_return</* ss_typename_type_k */ C::value_type>());
#else 

    readlines_impl(contents.c_str(), contents.size(), container);
#endif /* 0 */

    return container;
}


/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/file_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_HPP_FILE_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
