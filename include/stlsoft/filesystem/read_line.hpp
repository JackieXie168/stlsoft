/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/filesystem/read_line.hpp
 *
 * Purpose:     Definition of stlsoft::read_line() function template.
 *
 * Created:     2nd January 2007
 * Updated:     10th August 2009
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2007-2009, Matthew Wilson and Synesis Software
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


/** \file stlsoft/filesystem/read_line.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::read_line() function
 *   template
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_READ_LINE
#define STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_READ_LINE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_READ_LINE_MAJOR     2
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_READ_LINE_MINOR     0
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_READ_LINE_REVISION  2
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_READ_LINE_EDIT      10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>
#endif /* !STLSOFT_INCL_STDEXCEPT */

#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Flags that moderate the behaviour of the stlsoft::read_line() function
 *
 * Each flag causes the stlsoft::read_line() function to recognise exactly
 * one character sequence as a new line. To recognise combinations, they
 * must be combined. For example, to recognise both '\n' and "\r\n" as
 * end-of-line sequences, both recogniseLfAsEOL and recogniseCrLfAsEOL
 * must be specified.
 */
struct read_line_flags
{
    enum flags_t
    {
        recogniseCrAsEOL    =   0x0001, /*!< Recognises a sole carriage return ('\r') character as a line feed */
        recogniseLfAsEOL    =   0x0002,
        recogniseCrLfAsEOL  =   0x0004,
        recogniseAll        =   (recogniseCrAsEOL | recogniseLfAsEOL | recogniseCrLfAsEOL),

        mask                =   0x0007
    };
};

inline read_line_flags::flags_t operator |(read_line_flags::flags_t const& lhs, read_line_flags::flags_t const& rhs)
{
    return static_cast<read_line_flags::flags_t>(int(lhs) | int(rhs));
}

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct read_line_impl
{
    class read_from_FILE
    {
    public: /// Member Types
        typedef read_from_FILE  class_type;

    public:
        ss_explicit_k read_from_FILE(FILE* stm)
            : m_stm(stm)
        {}
        read_from_FILE(class_type const& rhs)
            : m_stm(rhs.m_stm)
        {}
    private:
        class_type &operator =(class_type const&);

    public: /// Operations
        int read_char()
        {
            return ::fgetc(m_stm);
        }

        int peek_next_char()
        {
            int ch = ::fgetc(m_stm);

            if(EOF != ch)
            {
                ::ungetc(ch, m_stm);
            }

            return ch;
        }

    private:
        FILE* const m_stm;
    };

    class read_from_char_buffer
    {
    public: /// Member Types
        typedef read_from_char_buffer   class_type;

    public:
        ss_explicit_k read_from_char_buffer(char const* buffer, int size)
            : m_buffer(buffer)
            , m_size(calc_length_(buffer, size))
            , m_current(0)
        {}
        read_from_char_buffer(class_type const& rhs)
            : m_buffer(rhs.m_buffer)
            , m_size(rhs.m_size)
            , m_current(rhs.m_current)
        {}
    private:
        static ss_size_t calc_length_(char const* buffer, int size)
        {
            if(size < 0)
            {
                size_t len = 0;

                if(NULL != buffer)
                {
                    for(; '\0' != *buffer; ++len, ++buffer)
                    {}
                }

                return len;
            }
            else
            {
                return static_cast<ss_size_t>(size);
            }
        }
        class_type &operator =(class_type const&);

    public: /// Operations
        int read_char()
        {
            if(m_current == m_size)
            {
                return -1;
            }
            else
            {
                return m_buffer[m_current++];
            }
        }

        int peek_next_char()
        {
            if(m_current == m_size)
            {
                return -1;
            }
            else
            {
                return m_buffer[m_current];
            }
        }

    private:
        char const* const   m_buffer;
        const ss_size_t     m_size;
        ss_size_t           m_current;
    };

    template<   ss_typename_param_k S
            ,   ss_typename_param_k P
            >
    static ss_bool_t read_line(P& policy, S& line, read_line_flags::flags_t flags)
    {
        ss_size_t numCr = 0;

        if(0 == (read_line_flags::mask & flags))
        {
            flags = read_line_flags::recogniseAll;
        }

        S().swap(line);

        { for (int ch; EOF != (ch = policy.read_char()); )
        {
            switch(ch)
            {
                case    '\r':
                    // Options:
                    //
                    // - recognising CR     -   handle
                    // - recognising CRLF   -   handle

                    // If we're recognising either

                    if(0 != ((read_line_flags::recogniseCrAsEOL | read_line_flags::recogniseCrLfAsEOL) & flags))
                    {
                        if(read_line_flags::recogniseCrLfAsEOL & flags)
                        {
                            // We need to look ahead in order to work out whether
                            // this might be the start of a \r\n pair
                            int ch2 = policy.peek_next_char();

                            if('\n' == ch2)
                            {
                                policy.read_char();

                                line.append(numCr, '\r');

                                return true;
                            }
                        }

                        if(read_line_flags::recogniseCrAsEOL & flags)
                        {
                            return true;
                        }
                    }

                    ++numCr;
                    continue;
                case    '\n':
                    // Options:
                    //
                    // - recognising CR     -   ignore
                    // - recognising LF     -   handle
                    // - recognising CRLF   -   handle
                    //
                    //  We check CRLF first

                    if( numCr > 0 &&
                        (read_line_flags::recogniseCrLfAsEOL & flags))
                    {
                        // Here we will digest any excess CRs as literal
                        // characters in the line, and then return the
                        // line

                        line.append(numCr - 1, '\r');

                        return true;
                    }
                    else if(read_line_flags::recogniseLfAsEOL & flags)
                    {
                        line.append(numCr, '\r');

                        return true;
                    }
                    break;
                default:
                    if(numCr > 0)
                    {
                        line.append(numCr, '\r');
                        numCr = 0;
                    }
                    break;
            }

            line.append(1, static_cast<char>(ch));
        }}

        return !line.empty();
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Reads a line from a C stream
 *
 * \param stm The stream to read from
 * \param line The line to read into. Must be an instance of a type that
 *   is structurally conformant to std::string in the following ways: it
 *   has a default constructor, it has a swap() method, and it has a block
 *   append method (taking repeat count and character to add)
 * \param flags The flags that control what line-termination sequences are
 *   recognised
 *
 * \return An indication of whether there is more to parse
 * \retval true The parsing is not complete
 * \retval false The parsing is complete
 *
 * \remarks The function can any or all of the following as line-termination
 *   sequences: carriage-return ('\r'), line-feed ('\n'), or
 *   carriage-return+line-feed ("\r\n").
 */
template <ss_typename_param_k S>
ss_bool_t read_line(FILE* stm, S& line, read_line_flags::flags_t flags = read_line_flags::recogniseAll)
{
    read_line_impl::read_from_FILE  policy(stm);

    return read_line_impl::read_line(policy, line, flags);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_READ_LINE */

/* ///////////////////////////// end of file //////////////////////////// */
