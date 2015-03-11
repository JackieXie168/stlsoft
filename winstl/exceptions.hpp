/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/exceptions.hpp (formerly winstl_exceptions.h)
 *
 * Purpose:     windows_exception class, and its policy class
 *
 * Created:     19th June 2004
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2004, Matthew Wilson and Synesis Software
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


/// \file winstl/exceptions.hpp
///
/// windows_exception class, and its policy class

#ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_EXCEPTIONS_MAJOR     3
# define WINSTL_VER_WINSTL_HPP_EXCEPTIONS_MINOR     1
# define WINSTL_VER_WINSTL_HPP_EXCEPTIONS_REVISION  1
# define WINSTL_VER_WINSTL_HPP_EXCEPTIONS_EDIT      28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
# include <stlsoft/exceptions.hpp>    // os_exception
#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_H_ERROR_FUNCTIONS
# include <winstl/error_functions.h>    // FormatMessage
#endif /* !WINSTL_INCL_WINSTL_H_ERROR_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
# include <stlsoft/simple_string.hpp> // stlsoft::simple_string
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */

/* /////////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Exception class for general Windows operating system failures
class windows_exception
    : public os_exception
{
/// \name Types
/// @{
protected:
    typedef stlsoft_ns_qual(simple_string)  string_type;
public:
    typedef os_exception                    parent_class_type;
    typedef ws_dword_t                      error_code_type;
    typedef windows_exception               class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k windows_exception(error_code_type err)
        : m_reason()
        , m_strerror(NULL)
        , m_errorCode(err)
    {}
    windows_exception(class_type const &rhs)
        : m_reason(rhs.m_reason)
        , m_strerror(NULL)
        , m_errorCode(rhs.m_errorCode)
    {}
    windows_exception(char const *reason, error_code_type err)
        : m_reason(class_type::create_reason_(reason, err))
        , m_strerror(NULL)
        , m_errorCode(err)
    {}
protected:
    windows_exception(string_type const &reason, error_code_type err)
        : m_reason(reason)
        , m_strerror(NULL)
        , m_errorCode(err)
    {}
public:
    virtual ~windows_exception() stlsoft_throw_0()
    {
        if( NULL != m_strerror &&
            m_reason.c_str() != m_strerror)
        {
            format_message_free_buff(m_strerror);
        }
    }
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
            return this->strerror();
        }
    }

    error_code_type get_error_code() const
    {
        return m_errorCode;
    }

    error_code_type last_error() const
    {
        return m_errorCode;
    }

    char const *strerror() const
    {
        if(NULL == m_strerror)
        {
            if( m_errorCode == static_cast<error_code_type>(E_OUTOFMEMORY) ||
                m_errorCode == static_cast<error_code_type>(ERROR_OUTOFMEMORY))
            {
                return "Out of memory";
            }
            else
            {
                char    *&s =   stlsoft_ns_qual(remove_const)(this->m_strerror);

                if(0 == format_message(m_errorCode, NULL, &s))
                {
                    return "Windows system error";
                }
            }
        }

        return m_strerror;
    }
/// @}

// Implementation
private:
    static string_type create_reason_(char const *reason, error_code_type err)
    {
        if( err == static_cast<error_code_type>(E_OUTOFMEMORY) ||
            err == static_cast<error_code_type>(ERROR_OUTOFMEMORY) ||
            NULL == reason ||
            '\0' == reason[0])
        {
            return string_type();
        }
        else
        {
            string_type r(reason);
            char        *s;

            if(0 != format_message(err, NULL, &s))
            {
                r += ": ";
                r += s;

                format_message_free_buff(s);
            }

            return r;
        }
    }

// Members
private:
    const string_type   m_reason;
    char                *m_strerror;
    error_code_type     m_errorCode;

// Not to be implemented
private:
    class_type &operator =(class_type const &);
};

/* ////////////////////////////////////////////////////////////////////////////
 * Policies
 */

/// The policy class, which throws a windows_exception class.
// [[synesis:class:exception-policy: windows_exception_policy]]
struct windows_exception_policy
{
public:
    /// The thrown type
    typedef windows_exception   thrown_type;
    typedef ws_dword_t          error_code_type;

public:
    /// Function call operator, taking no parameters
    void operator ()()
    {
        throw_exception_(thrown_type(::GetLastError()));
    }
    /// Function call operator, taking one parameter
    void operator ()(error_code_type err) const
    {
        throw_exception_(thrown_type(err));
    }
    /// Function call operator, taking two parameters
    void operator ()(char const *reason, error_code_type err) const
    {
        throw_exception_(thrown_type(reason, err));
    }

private:
#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    template <ss_typename_param_k X>
    static void throw_exception_(X const &x)
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER < 1200
    static void throw_exception_(std::exception const &x)
#else /* ? feature / compiler */
    static void throw_exception_(thrown_type const &x)
#endif /* feature / compiler */
    {
        throw x;
    }
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/exceptions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

#endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
