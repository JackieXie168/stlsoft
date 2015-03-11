/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/byte_format_functions.hpp
 *
 * Purpose:     Byte formatting functions.
 *
 * Created:     23rd July 2006
 * Updated:     2nd January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/byte_format_functions.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::byte_format() function(s).
 * (\ref group__library__conversion "Conversion" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS_REVISION  3
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS_EDIT      4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#include <string.h>
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

inline ss_size_t format_bytes(  void const  *pv
                            ,   ss_size_t   cb
                            ,   char        *buff
                            ,   ss_size_t   cchBuff
                            ,   unsigned    byteGrouping    //!< Number of bytes in a group
                            ,   char const  *groupSeparator
                            ,   int         groupsPerLine   =   -1
                            ,   char const  *lineSeparator  =   "\n")
{
    STLSOFT_ASSERT( 0 == byteGrouping
                ||  1 == byteGrouping
                ||  2 == byteGrouping
                ||  4 == byteGrouping
                ||  8 == byteGrouping
                ||  16 == byteGrouping
                ||  32 == byteGrouping);

    if(0 == byteGrouping)
    {
        byteGrouping = sizeof(int);
    }

    const ss_size_t cchSeparator        =   (NULL == groupSeparator) ? (groupSeparator = "", 0) : ::strlen(groupSeparator);
    const ss_size_t cchLineSeparator    =   (NULL == lineSeparator) ? 0 : ::strlen(lineSeparator);

    if(0 == cb)
    {
        return 0;
    }
    else
    {
        const ss_size_t numGroups           =   (cb + (byteGrouping - 1)) / byteGrouping;
        const ss_size_t numLines            =   (groupsPerLine < 1) ? 1 : (numGroups + (groupsPerLine - 1)) / groupsPerLine;
        const ss_size_t numLineSeparators   =   numLines - 1;
        ss_size_t       size                =   (numGroups * (cchSeparator + (2 * byteGrouping))) + (numLineSeparators * cchLineSeparator) - (numLines * cchSeparator);

        if(size <= cchBuff)
        {
            byte_t const    *py =   static_cast<byte_t const*>(pv);
            int             cch;
            ss_size_t       lineIndex;
            ss_size_t       groupIndex;

            for(lineIndex = 0, groupIndex = 0; 0 != cb; py += byteGrouping)
            {
                if(cb < byteGrouping)
                {
                    size            -=  2 * (byteGrouping - cb);
                    byteGrouping    =   cb;
                }

#if defined(STLSOFT_COMPILER_IS_GCC)
                typedef unsigned        int8x_t;
#else /* ? compiler */
                typedef uint32_t        int8x_t;
#endif /* compiler */

                switch(byteGrouping)
                {
                    case    1:
                        cch     =   ::sprintf(  buff, "%02x"
                                            ,   *sap_cast<uint8_t const*>(py));
                        buff    +=  cch;
                        cb      -=  1;
                        break;
                    case    2:
                        cch     =   ::sprintf(  buff, "%04x"
                                            ,   *sap_cast<uint16_t const*>(py));
                        buff    +=  cch;
                        cb      -=  2;
                        break;
                    case    4:
                        cch     =   ::sprintf(  buff, "%08x"
                                            ,   *sap_cast<int8x_t const*>(py));
                        buff    +=  cch;
                        cb      -=  4;
                        break;
                    case    8:
                        cch     =   ::sprintf(  buff, "%08x%08x"
                                            ,   *(sap_cast<int8x_t const*>(py) + 1)
                                            ,   *sap_cast<int8x_t const*>(py));
                        buff    +=  cch;
                        cb      -=  8;
                        break;
                    case    16:
                        cch     =   ::sprintf(  buff, "%08x%08x%08x%08x"
                                            ,   *(sap_cast<int8x_t const*>(py) + 3)
                                            ,   *(sap_cast<int8x_t const*>(py) + 2)
                                            ,   *(sap_cast<int8x_t const*>(py) + 1)
                                            ,   *sap_cast<int8x_t const*>(py));
                        buff    +=  cch;
                        cb      -=  16;
                        break;
                    case    32:
                        cch     =   ::sprintf(  buff, "%08x%08x%08x%08x%08x%08x%08x%08x"
                                            ,   *(sap_cast<int8x_t const*>(py) + 7)
                                            ,   *(sap_cast<int8x_t const*>(py) + 6)
                                            ,   *(sap_cast<int8x_t const*>(py) + 5)
                                            ,   *(sap_cast<int8x_t const*>(py) + 4)
                                            ,   *(sap_cast<int8x_t const*>(py) + 3)
                                            ,   *(sap_cast<int8x_t const*>(py) + 2)
                                            ,   *(sap_cast<int8x_t const*>(py) + 1)
                                            ,   *sap_cast<int8x_t const*>(py));
                        buff    +=  cch;
                        cb      -=  32;
                        break;
                }

                if(static_cast<ss_size_t>(groupsPerLine) == ++groupIndex)
                {
                    if(++lineIndex < numLines)
                    {
                        ::strncpy(buff, lineSeparator, cchLineSeparator);
                        buff += cchLineSeparator;
                    }
                    groupIndex = 0;
                }
                else if(0 != cb)
                {
                    ::strncpy(buff, groupSeparator, cchSeparator);
                    buff += cchSeparator;
                }
            }
        }

        return size;
    }
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/byte_format_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
