/* /////////////////////////////////////////////////////////////////////////
 * File:        unittest/simple_unittester.cpp
 *
 * Purpose:     Simple, command-line unit-testing client.
 *
 * Created:     13th May 2004
 * Updated:     5th January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2007, Matthew Wilson and Synesis Software
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


/** \file unittest/simple_unittester.cpp
 *
 * \brief [C++ only] Implementation of the stlsoft::unittest::simple_unittest_host
 *   class, which is a simple command-line unit-testing host.
 * (\ref group__library__unittest "Unit Test" Library.)
 */

#ifndef _STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_UNITTEST_CPP_SIMPLE_UNITTESTER_MAJOR       2
# define STLSOFT_VER_UNITTEST_CPP_SIMPLE_UNITTESTER_MINOR       6
# define STLSOFT_VER_UNITTEST_CPP_SIMPLE_UNITTESTER_REVISION    2
# define STLSOFT_VER_UNITTEST_CPP_SIMPLE_UNITTESTER_EDIT        23
#endif /* !_STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#if defined(__MWERKS__)
# if defined(_STLSOFT_COMPILE_VERBOSE)
#  undef _STLSOFT_COMPILE_VERBOSE
# endif /* _STLSOFT_COMPILE_VERBOSE */
#endif /* compiler */

#include <stdio.h>
#include <stlsoft/stlsoft.h>
#include <unittest/simple_unittester.h>
#ifdef STLSOFT_CF_std_NAMESPACE
# include <string>
#else /* ? STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)
#  include <string.hpp>
# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* STLSOFT_CF_std_NAMESPACE */

#ifndef STLSOFT_UNITTEST
# error This file cannot be used if STLSOFT_UNITTEST is not defined.
#endif /* !STLSOFT_UNITTEST */

#if defined(__INTEL_COMPILER)
# pragma warning(disable : 444)
#endif /* __INTEL_COMPILER */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{

namespace unittest
{
#endif /* STLSOFT_NO_NAMESPACE */

#ifdef STLSOFT_CF_std_NAMESPACE
typedef stlsoft_ns_qual_std(string)     string_t;
#else /* ? STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)
typedef String                          string_t;
# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class simple_unittest_reporter
    : public unittest_reporter
{
public:
    simple_unittest_reporter(bool bVerbose);
#if defined(STLSOFT_COMPILER_IS_GCC)
    virtual ~simple_unittest_reporter() stlsoft_throw_0();
#else /* ? compiler */
    virtual ~simple_unittest_reporter() stlsoft_throw_0();
#endif /* compiler */

protected:
    virtual void set_project(char const *projectName);
    virtual void set_component(char const *componentName);
    virtual void set_file(char const *fileName);
    virtual void start();
    virtual void report(char const *message, int line, char const *baseFile);
    virtual void start_section(char const *message, int line, char const *baseFile);
    virtual void end_section(char const *message, int line, char const *baseFile);
    virtual void stop();

public:
    char const *get_project() const;
    char const *get_component() const;
    char const *get_file() const;

private:
    void do_section(char const *message, int line, char const *baseFile, bool bEntering);

private:
    string_t    m_projectName;
    string_t    m_componentName;
    string_t    m_fileName;
    bool        m_bVerbose;
};


simple_unittest_reporter::simple_unittest_reporter(bool bVerbose)
    : m_projectName("")
    , m_componentName("")
    , m_fileName("")
    , m_bVerbose(bVerbose)
{}

simple_unittest_reporter::~simple_unittest_reporter() stlsoft_throw_0()
{}

void simple_unittest_reporter::set_project(char const *projectName)
{
    m_projectName = projectName;
}

void simple_unittest_reporter::set_component(char const *componentName)
{
    m_componentName = componentName;
}

void simple_unittest_reporter::set_file(char const *fileName)
{
    m_fileName = fileName;
}

void simple_unittest_reporter::start()
{
    if(m_bVerbose)
    {
        printf("Testing %s:%s (%s)\n", get_project(), get_component(), get_file());
    }
}

void simple_unittest_reporter::report(char const *message, int line, char const *baseFile)
{
    if( NULL != baseFile &&
        '\0' != *baseFile)
    {
        if(line < 0)
        {
            printf("  %s:%s: (in %s): %s\n", m_projectName.c_str(), m_componentName.c_str(), baseFile, message);
        }
        else if(0 != line)
        {
            printf("  %s(%d): (in %s): %s:%s: %s\n", m_fileName.c_str(), line, baseFile, m_projectName.c_str(), m_componentName.c_str(), message);
        }
        else
        {
            printf("  %s:%s (%s) (in %s): %s\n", m_projectName.c_str(), m_componentName.c_str(), m_fileName.c_str(), baseFile, message);
        }
    }
    else
    {
        if(m_bVerbose)
        {
            if(line < 0)
            {
                printf("  %s:%s: %s\n", m_projectName.c_str(), m_componentName.c_str(), message);
            }
            else if(0 != line)
            {
                printf("  %s(%d): %s:%s: %s\n", m_fileName.c_str(), line, m_projectName.c_str(), m_componentName.c_str(), message);
            }
            else
            {
                printf("  %s:%s (%s): %s\n", m_projectName.c_str(), m_componentName.c_str(), m_fileName.c_str(), message);
            }
        }
    }
}

void simple_unittest_reporter::do_section(char const *message, int line, char const *baseFile, bool bEntering)
{
    if( NULL != baseFile &&
        '\0' != *baseFile)
    {
        if(bEntering)
        {
            printf("  Entering: %s; %s(%d) (in %s)\n", message, m_fileName.c_str(), line, baseFile);
        }
        else
        {
            printf("  Exiting:  %s; %s(%d) (in %s)\n", message, m_fileName.c_str(), line, baseFile);
        }
    }
    else
    {
        if(bEntering)
        {
            printf("  Entering: %s; %s(%d)\n", message, m_fileName.c_str(), line);
        }
        else
        {
            printf("  Exiting:  %s; %s(%d)\n", message, m_fileName.c_str(), line);
        }
    }

}

void simple_unittest_reporter::start_section(char const *message, int line, char const *baseFile)
{
    do_section(message, line, baseFile, true);
}

void simple_unittest_reporter::end_section(char const *message, int line, char const *baseFile)
{
    do_section(message, line, baseFile, false);
}


void simple_unittest_reporter::stop()
{
}

char const *simple_unittest_reporter::get_project() const
{
    return m_projectName.c_str();
}

char const *simple_unittest_reporter::get_component() const
{
    return m_componentName.c_str();
}

char const *simple_unittest_reporter::get_file() const
{
    return m_fileName.c_str();
}

/* /////////////////////////////////////////////////////////////////////////
 * simple_unittest_host
 */

ss_size_t simple_unittest_host::size()
{
#ifdef STLSOFT_CF_std_NAMESPACE

    return m_functions.size();

#else /* ? STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)

    return m_functions.length();

# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* STLSOFT_CF_std_NAMESPACE */
}

simple_unittest_host::simple_unittest_host()
{}

simple_unittest_host::~simple_unittest_host() stlsoft_throw_0()
{
    STLSOFT_ASSERT(0 == size());
}

ss_uint32_t simple_unittest_host::register_unittest_fn(unittest_function pfn)
{
#ifdef STLSOFT_CF_std_NAMESPACE

    m_functions.push_back(pfn);

#else /* ? STLSOFT_CF_std_NAMESPACE */
# if defined(STLSOFT_COMPILER_IS_WATCOM)

    m_functions[size()] = pfn;

# else /* ? compiler */
#  error No other non-std compiler is known
# endif /* ? compiler */
#endif /* STLSOFT_CF_std_NAMESPACE */

    return 1;
}

void simple_unittest_host::deregister_unittest_fn(ss_uint32_t unittestId)
{
    STLSOFT_SUPPRESS_UNUSED(unittestId);

    STLSOFT_ASSERT(1 == unittestId);
}

/* static */ simple_unittest_host *simple_unittest_host::get_host()
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because race-conditions are benign here
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

    static simple_unittest_host *host   =   make_host();

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

    return host;
}

bool simple_unittest_host::test(bool bVerbose)
{
    simple_unittest_reporter    rep(bVerbose);

#if 0
    functions_t::const_iterator b   =   m_functions.begin();
    functions_t::const_iterator e   =   m_functions.end();

    for(; b != e; ++b)
    {
        if(!(*b)(&rep))
        {
            return false;
        }
    }
#else /* ? 0 */
    for(ss_size_t i = 0, n = size(); i < n; ++i)
    {
        if(!(*m_functions[i])(&rep))
        {
            return false;
        }
    }
#endif /* 0 */

    return true;
}

/* static */ simple_unittest_host *simple_unittest_host::make_host(void)
{
    return new simple_unittest_host();
}

extern "C" unittest_host *get_unittest_host(void)
{
    return simple_unittest_host::get_host();
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace unittest
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */
