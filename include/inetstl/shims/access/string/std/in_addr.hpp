/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/shims/access/string/std/in_addr.hpp
 *
 * Purpose:     .
 *
 * Created:     
 * Updated:     21st October 2006
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




#include <inetstl/inetstl.h>

#include <inetstl/includes/std/in_addr.h>

#include <stlsoft/string/shim_string.hpp>

namespace stlsoft
{
namespace inetstl_project
{

    inline stlsoft::basic_shim_string<is_char_a_t, 16> c_str_data_a(struct in_addr const &addr)
    {
        stlsoft::basic_shim_string<is_char_a_t, 16>    s(15);

        unsigned    b0  =   (addr.s_addr & 0x000000ff) >> 0;
        unsigned    b1  =   (addr.s_addr & 0x0000ff00) >> 8;
        unsigned    b2  =   (addr.s_addr & 0x00ff0000) >> 16;
        unsigned    b3  =   (addr.s_addr & 0xff000000) >> 24;
        int         cch =   ::sprintf(s.data(), "%u.%u.%u.%u", b0, b1, b2, b3);

        if(cch < 0)
        {
            cch = 0;
        }

        s.truncate(static_cast<is_size_t>(cch));

        return s;
    }
    inline ss_size_t c_str_len_a(struct in_addr const &addr)
    {
        unsigned    b0  =   (addr.s_addr & 0x000000ff) >> 0;
        unsigned    b1  =   (addr.s_addr & 0x0000ff00) >> 8;
        unsigned    b2  =   (addr.s_addr & 0x00ff0000) >> 16;
        unsigned    b3  =   (addr.s_addr & 0xff000000) >> 24;

        int         cch =   3   // The dot separators
                        +   1 + (b0 > 9) + (b0 > 99)
                        +   1 + (b1 > 9) + (b1 > 99)
                        +   1 + (b2 > 9) + (b2 > 99)
                        +   1 + (b3 > 9) + (b3 > 99)
                        ;

        return static_cast<is_size_t>(cch);
    }
    inline stlsoft::basic_shim_string<is_char_a_t, 16> c_str_ptr_a(struct in_addr const &addr)
    {
        return c_str_data_a(addr);
    }

    inline stlsoft::basic_shim_string<is_char_a_t, 16> c_str_data_a(struct in_addr const *addr)
    {
        return (NULL != addr) ? c_str_data_a(*addr) : stlsoft::basic_shim_string<is_char_a_t, 16>(is_size_t(0));
    }
    inline ss_size_t c_str_len_a(struct in_addr const *addr)
    {
        return (NULL != addr) ? c_str_len_a(*addr) : stlsoft::basic_shim_string<is_char_a_t, 16>(is_size_t(0));
    }
    inline stlsoft::basic_shim_string<is_char_a_t, 16> c_str_ptr_a(struct in_addr const *addr)
    {
        return c_str_data_a(addr);
    }


} // namespace inetstl_project

using ::inetstl::c_str_data_a;
using ::inetstl::c_str_len_a;
using ::inetstl::c_str_ptr_a;

} // namespace stlsoft
