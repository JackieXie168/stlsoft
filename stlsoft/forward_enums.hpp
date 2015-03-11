/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/forward_enums.hpp (originally MLFwdEnm.h)
 *
 * Purpose:     Contains macros for forward declaring enums.
 *
 * Created:     3rd November 2000
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/forward_enums.hpp
///
/// Contains macros for forward declaring enums.

#ifndef STLSOFT_INCL_STLSOFT_HPP_FORWARD_ENUM
#define STLSOFT_INCL_STLSOFT_HPP_FORWARD_ENUM

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_FORWARD_ENUM_MAJOR      2
# define STLSOFT_VER_STLSOFT_HPP_FORWARD_ENUM_MINOR      4
# define STLSOFT_VER_STLSOFT_HPP_FORWARD_ENUM_REVISION   1
# define STLSOFT_VER_STLSOFT_HPP_FORWARD_ENUM_EDIT       40
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
 * Macros
 */


#define STLSOFT_DECLARE_FWD_ENUM(X)                             \
                                                                \
    struct X ## __type;                                         \
                                                                \
    typedef X ## __type X

#define STLSOFT_DEFINE_FWD_ENUM_BEGIN(X)                        \
                                                                \
    enum X ## __enum                                            \
    {


#define STLSOFT_DEFINE_FWD_ENUM_END(X)                          \
                                                                \
    };                                                          \
                                                                \
    STLSOFT_DECLARE_FWD_ENUM(X);                                \
                                                                \
    struct X ## __type                                          \
    {                                                           \
    public:                                                     \
        typedef X ## __enum     enum_type;                      \
    public:                                                     \
        static X ## __type cast(long l)                         \
        {                                                       \
            return X ## __type (static_cast<X ## __enum>(l));   \
        }                                                       \
                                                                \
    public:                                                     \
        X ## __type(X ## __enum e)                              \
            : m_e(e)                                            \
        {}                                                      \
                                                                \
        operator X ## __enum () const                           \
        {                                                       \
            return m_e;                                         \
        }                                                       \
                                                                \
        int to_int() const                                      \
        {                                                       \
            return m_e;                                         \
        }                                                       \
                                                                \
    private:                                                    \
        X ## __enum m_e;                                        \
    };

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_FORWARD_ENUM */

/* ////////////////////////////////////////////////////////////////////////// */
