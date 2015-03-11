/* /////////////////////////////////////////////////////////////////////////////
 * File:        simple_unittester.h
 *
 * Purpose:     Simple, command-line unit-testing client.
 *
 * Created:     13th May 2004
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


/// \file simple_unittester.h
///
/// Simple, command-line unit-testing client.

#ifndef STLSOFT_INCL_H_SIMPLE_UNITTESTER
#define STLSOFT_INCL_H_SIMPLE_UNITTESTER

#ifndef _STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_SIMPLE_UNITTESTER_MAJOR      1
# define STLSOFT_VER_H_SIMPLE_UNITTESTER_MINOR      2
# define STLSOFT_VER_H_SIMPLE_UNITTESTER_REVISION   1
# define STLSOFT_VER_H_SIMPLE_UNITTESTER_EDIT       10
#endif /* !_STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft.h>
#ifdef __STLSOFT_CF_std_NAMESPACE
# include <vector>
#else /* ? __STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)
#  include <wcvector.h>
# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* __STLSOFT_CF_std_NAMESPACE */

#ifndef STLSOFT_UNITTEST
# error This file cannot be used if STLSOFT_UNITTEST is not defined.
#endif /* !STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{

namespace unittest
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

class simple_unittest_host
    : public unittest_host
{
public:
    simple_unittest_host();
    virtual ~simple_unittest_host() stlsoft_throw_0();

public:
    virtual ss_uint32_t register_unittest_fn(unittest_function pfn);
    virtual void deregister_unittest_fn(ss_uint32_t unittestId);

public:
    static simple_unittest_host *get_host();
    bool test(bool bVerbose);

private:
    static simple_unittest_host *make_host(void);

private:
    size_t  size();

private:
#ifdef __STLSOFT_CF_std_NAMESPACE
    typedef stlsoft_ns_qual_std(vector)<unittest_function>  functions_t;
#else /* ? __STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)
    typedef WCValVector<unittest_function>                  functions_t;
# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* __STLSOFT_CF_std_NAMESPACE */

    functions_t     m_functions;
};

extern "C" unittest_host *get_unittest_host(void);

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace unittest
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_SIMPLE_UNITTESTER */

/* ////////////////////////////////////////////////////////////////////////// */
