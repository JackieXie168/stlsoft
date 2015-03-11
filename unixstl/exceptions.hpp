/* ////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/exceptions.hpp (formerly unixstl_exceptions.h)
 *
 * Purpose:     unix_exception class, and its policy class
 *
 * Created:     19th June 2004
 * Updated:     15th December 2005
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


/// \file unixstl/exceptions.hpp
///
/// unix_exception class, and its policy class

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
#define UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_EXCEPTIONS_MAJOR       3
# define UNIXSTL_VER_UNIXSTL_HPP_EXCEPTIONS_MINOR       2
# define UNIXSTL_VER_UNIXSTL_HPP_EXCEPTIONS_REVISION    1
# define UNIXSTL_VER_UNIXSTL_HPP_EXCEPTIONS_EDIT        28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
# include <stlsoft/exceptions.hpp>    // os_exception
#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
# include <stlsoft/simple_string.hpp> // stlsoft::simple_string
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */
#include <errno.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Exception class for general Windows operating system failures
class unix_exception
    : public os_exception
{
/// \name Types
/// @{
protected:
    typedef stlsoft_ns_qual(simple_string)  string_type;
public:
    typedef os_exception                    parent_class_type;
    typedef int                             error_code_type;
    typedef unix_exception                  class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k unix_exception(error_code_type err)
        : m_reason()
        , m_errorCode(err)
    {}
    unix_exception(char const *reason, error_code_type err)
        : m_reason(class_type::create_reason_(reason, err))
        , m_errorCode(err)
    {}
protected:
    unix_exception(string_type const &reason, error_code_type err)
        : m_reason(reason)
        , m_errorCode(err)
    {}
public:
#if defined(STLSOFT_COMPILER_IS_COMO) || \
    defined(STLSOFT_COMPILER_IS_GCC)
    virtual ~unix_exception() stlsoft_throw_0()
    {}
#endif /* compiler */
/// @}

/// \name Accessors
/// @{
public:
    virtual char const *what() const stlsoft_throw_0()
    {
        if(!m_reason.empty())
        {
            return m_reason.c_str();
        }
        else
        {
            char const  *s  =   this->strerror();

            UNIXSTL_ASSERT(NULL != s);

            return (*s != '\0') ? s : "UNIX system error";
        }
    }

    error_code_type get_error_code() const
    {
        return m_errorCode;
    }

    error_code_type get_errno() const
    {
        return m_errorCode;
    }

    char const *strerror() const
    {
        return ::strerror(m_errorCode);
    }
/// @}

/// \name Implementation
/// @{
private:
    static string_type create_reason_(char const *reason, error_code_type err)
    {
        if( err == ENOMEM ||
            NULL == reason ||
            '\0' == reason[0])
        {
            return string_type();
        }
        else
        {
            ::strerror(0);  // need to flush the errno

            string_type r(reason);
            char const  *s  =   ::strerror(err);

            UNIXSTL_ASSERT(NULL != s);

            if(*s != '\0')
            {
                r += ": ";
                r += s;
            }

            return r;
        }
    }
/// @}

/// \name Members
/// @{
private:
    const string_type   m_reason;
    error_code_type     m_errorCode;
/// @}
};

/* ////////////////////////////////////////////////////////////////////////////
 * Policies
 */

/// The NULL exception type. It does not throw, and its throw type is empty.
// [[synesis:class:exception-policy: unix_exception_policy]]
struct unix_exception_policy
{
public:
    /// The thrown type
    typedef unix_exception   thrown_type;
    typedef int              error_code_type;

public:
    /// Function call operator, taking no parameters
    void operator ()()
    {
        throw thrown_type(errno);
    }
    /// Function call operator, taking one parameter
    void operator ()(error_code_type err) const
    {
        throw thrown_type(err);
    }
    /// Function call operator, taking two parameters
    void operator ()(char const *reason, error_code_type err) const
    {
        throw thrown_type(reason, err);
    }
#if 0
    /// Function call operator, taking three parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            >
    void operator ()(T1 const &/* t1 */, T2 const &/* t2 */, T3 const &/* t3 */) const
    {
        // Do nothing
    }
    /// Function call operator, taking four parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            ,   ss_typename_param_k T4
            >
    void operator ()(T1 const &/* t1 */, T2 const &/* t2 */, T3 const &/* t3 */, T4 const &/* t4 */) const
    {
        // Do nothing
    }
#endif /* 0 */
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/exceptions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
