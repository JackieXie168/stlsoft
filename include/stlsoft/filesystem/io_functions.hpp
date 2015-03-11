/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/filesystem/io_functions.hpp
 *
 * Purpose:     File-system functions.
 *
 * Created:     2nd January 2007
 * Updated:     2nd January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/filesystem/io_functions.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::read_line() function
 *   template.
 * (\ref group__library__file_system "File System" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS_MAJOR      1
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS_MINOR      0
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS_REVISION   1
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS_EDIT       1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#include <stdexcept>
#include <stdio.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <typename S>
size_t read_line(FILE *stm, S &str)
{
    const char  CH      =   '~';
#ifdef _DEBUG
    char        buff[10];
#else /* ? _DEBUG */
    char        buff[100];
#endif /* _DEBUG */
    size_t      total   =   0;

    for(str.assign("");;)
    {
        buff[STLSOFT_NUM_ELEMENTS(buff) - 1] = CH;

        if(NULL == ::fgets(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stm))
        {
            return 0;
        }
        else
        {
            if('\0' == buff[STLSOFT_NUM_ELEMENTS(buff) - 1])
            {
                // If we've a full buffer, it might still be the last
                // get, if the last character is \n

                if('\n' == buff[STLSOFT_NUM_ELEMENTS(buff) - 2])
                {
                    str.append(buff, STLSOFT_NUM_ELEMENTS(buff) - 2);

                    break;
                }
                else
                {
                    str.append(buff);
                }
            }
            else
            {
                // Less than a full buffer.
                size_t  len =   ::strlen(buff);

                if(len > 0)
                {
                    if('\n' == buff[len - 1])
                    {
                        --len;
                    }
                }

                str.append(buff, len);

                break;
            }
        }
    }

    return 1 + str.length();
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_IO_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
