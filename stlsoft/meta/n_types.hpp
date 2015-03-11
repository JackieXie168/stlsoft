/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/n_types.hpp (formerly part of stlsoft_meta.h)
 *
 * Purpose:     Basic support meta types.
 *
 * Created:     19th November 1998
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/meta/n_types.hpp
///
/// Options verification.

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES
#define STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_N_TYPES_MAJOR     4
# define STLSOFT_VER_STLSOFT_META_HPP_N_TYPES_MINOR     2
# define STLSOFT_VER_STLSOFT_META_HPP_N_TYPES_REVISION  1
# define STLSOFT_VER_STLSOFT_META_HPP_N_TYPES_EDIT      109
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

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

typedef struct { ss_byte_t ar[1]; }     one_type;
typedef struct { ss_byte_t ar[2]; }     two_type;
typedef struct { ss_byte_t ar[3]; }     three_type;
typedef struct { ss_byte_t ar[4]; }     four_type;
typedef struct { ss_byte_t ar[5]; }     five_type;
typedef struct { ss_byte_t ar[6]; }     six_type;
typedef struct { ss_byte_t ar[7]; }     seven_type;
typedef struct { ss_byte_t ar[8]; }     eight_type;
typedef struct { ss_byte_t ar[9]; }     nine_type;
typedef struct { ss_byte_t ar[10]; }    ten_type;
typedef struct { ss_byte_t ar[11]; }    eleven_type;
typedef struct { ss_byte_t ar[12]; }    twelve_type;
typedef struct { ss_byte_t ar[13]; }    thirteen_type;
typedef struct { ss_byte_t ar[14]; }    fourteen_type;
typedef struct { ss_byte_t ar[15]; }    fifteen_type;
typedef struct { ss_byte_t ar[16]; }    sixteen_type;
typedef struct { ss_byte_t ar[17]; }    seventeen_type;
typedef struct { ss_byte_t ar[18]; }    eighteen_type;

// Backwards compatiblity
typedef one_type                        one_t;
typedef two_type                        two_t;
typedef three_type                      three_t;
typedef four_type                       four_t;
typedef five_type                       five_t;
typedef six_type                        six_t;
typedef seven_type                      seven_t;
typedef eight_type                      eight_t;
typedef nine_type                       nine_t;
typedef ten_type                        ten_t;
typedef eleven_type                     eleven_t;
typedef twelve_type                     twelve_t;
typedef thirteen_type                   thirteen_t;
typedef fourteen_type                   fourteen_t;
typedef fifteen_type                    fifteen_t;
typedef sixteen_type                    sixteen_t;
typedef seventeen_type                  seventeen_t;
typedef eighteen_type                   eighteen_t;

/** \brief This template is used to synthesise types with specific sizes
 */
template <ss_size_t N>
struct size_type
{
    ss_byte_t ar[N];
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES */

/* ////////////////////////////////////////////////////////////////////////// */
