/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/commandline_parser.hpp (formerly MLCmdArg.h, ::SynesisStd)
 *
 * Purpose:     commandline_parser class.
 *
 * Created:     20th May 2000
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/commandline_parser.hpp
///
/// commandline_parser class.

#ifndef WINSTL_INCL_H_WINSTL_COMMANDLINE_PARSER
#define WINSTL_INCL_H_WINSTL_COMMANDLINE_PARSER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_H_WINSTL_COMMANDLINE_PARSER_MAJOR       1
# define WINSTL_VER_H_WINSTL_COMMANDLINE_PARSER_MINOR       2
# define WINSTL_VER_H_WINSTL_COMMANDLINE_PARSER_REVISION    1
# define WINSTL_VER_H_WINSTL_COMMANDLINE_PARSER_EDIT        14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */

#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>           // auto_buffer
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS
# include <stlsoft/char_traits.hpp> // stlsoft::char_traits
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CHAR_TRAITS */
# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
     _MSC_VER == 1200
# ifndef STLSOFT_INCL_STLSOFT_HPP_POD_VECTOR
#  include <stlsoft/pod_vector.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_POD_VECTOR */
#else
# include <vector>
#endif /* compiler */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Parses a command line into parts, and provides array semantics for their access
template<   ss_typename_param_k C
        ,   ss_typename_param_k T = stlsoft_char_traits<C>
        >
class basic_commandline_parser
{
public:
    typedef C                                                           char_type;
    typedef T                                                           traits_type;
    typedef basic_commandline_parser<C, T>                              class_type;
private:
    typedef processheap_allocator<C>                                    allocator_type;
    typedef processheap_allocator<C*>                                   pointers_allocator_type;
    typedef stlsoft_ns_qual(auto_buffer)<C, allocator_type>             buffer_type;
//#include <stlsoft/char_traits.hpp>
# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
     _MSC_VER == 1200
    typedef stlsoft_ns_qual(pod_vector)<C*, pointers_allocator_type>    pointers_type;
#else
    typedef stlsoft_ns_qual_std(vector)<C*, pointers_allocator_type>    pointers_type;
#endif /* compiler */
    typedef ss_typename_type_k buffer_type::iterator                    iterator;
public:
    typedef ss_typename_type_k pointers_type::value_type                value_type;
    typedef ss_typename_type_k pointers_type::const_iterator            const_iterator;
    typedef ss_size_t                                                   size_type;

public:
    ss_explicit_k basic_commandline_parser(char_type const *cmdLine)
        : m_buffer(1 + stlsoft_ns_qual(c_str_len)(cmdLine))
    {
        traits_type::copy(&m_buffer[0], cmdLine, m_buffer.size());

        iterator        b           =   m_buffer.begin();
        const iterator  e           =   m_buffer.end() - 1;
        iterator        n           =   e;
        bool            bInQuote    =   false;
        bool            bInSpace    =   false;

        for(; b != e; ++b)
        {
            const char_type ch  =   *b;

            WINSTL_ASSERT('\0' != ch);

            if('"' == ch)
            {
                if(bInQuote)
                {
                    // This is the closing quote, so pop the first
                    WINSTL_ASSERT(e != n);
                    m_pointers.push_back(n);

                    *b = '\0';

                    n = e;

                    bInSpace = true;
                }
                else
                {
                    n = b + 1;
                }

                bInQuote = !bInQuote;
            }
#if 0
            else if(0x20 == ch ||
                    (   ch >= 0x09 &&
                        ch <= 0X20))
#else /* ? 0 */
            else if(isspace(ch))
#endif /* 0 */
            {
                if( !bInQuote &&
                    !bInSpace)
                {
                    WINSTL_ASSERT(e != n);
                    m_pointers.push_back(n);

                    *b = '\0';

                    n = e;
                }

                bInSpace = true;
            }
            else
            {
                if(bInSpace)
                {
                    n = b;
                }

                bInSpace = false;
            }
        }

        if(e != n)
        {
            m_pointers.push_back(n);
        }
    }

public:
    size_type           size() const
    {
        return m_pointers.size();
    }

    value_type const    &operator [](size_type index) const
    {
        return m_pointers[index];
    }

private:
    buffer_type     m_buffer;
    pointers_type   m_pointers;
};


typedef basic_commandline_parser<ws_char_a_t>                   commandline_parser_a;

typedef basic_commandline_parser<ws_char_w_t>                   commandline_parser_w;

typedef basic_commandline_parser<TCHAR>                         commandline_parser;

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

#endif /* WINSTL_INCL_H_WINSTL_COMMANDLINE_PARSER */

/* ////////////////////////////////////////////////////////////////////////// */
