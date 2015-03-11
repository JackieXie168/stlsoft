/* ////////////////////////////////////////////////////////////////////////////
 * File:        comstl/exceptions.hpp (formerly comstl_exceptions.h)
 *
 * Purpose:     COM-related exception classes, and their policy classes
 *
 * Created:     8th December 2004
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


/// \file comstl/exceptions.hpp (formerly comstl_exceptions.h)
///
/// COM-related exception classes, and their policy classes

#ifndef COMSTL_INCL_H_COMSTL_EXCEPTIONS
#define COMSTL_INCL_H_COMSTL_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_H_COMSTL_EXCEPTIONS_MAJOR       1
# define COMSTL_VER_H_COMSTL_EXCEPTIONS_MINOR       1
# define COMSTL_VER_H_COMSTL_EXCEPTIONS_REVISION    1
# define COMSTL_VER_H_COMSTL_EXCEPTIONS_EDIT        18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
# include <stlsoft/exceptions.hpp>      // os_exception
#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
# include <stlsoft/simple_string.hpp>   // stlsoft::simple_string
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Exception class for general COM-related failures
class com_exception
    : public os_exception
{
/// \name Types
/// @{
private:
    typedef stlsoft_ns_qual(simple_string)  string_type;
public:
    typedef com_exception                   class_type;
    typedef os_exception                    parent_class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k com_exception(HRESULT hr)
        : m_reason()
        , m_hr(hr)
    {}
    com_exception(char const *reason, HRESULT hr)
        : m_reason((NULL == reason) ? "" : reason)
        , m_hr(hr)
    {}
#if defined(STLSOFT_COMPILER_IS_COMO) || \
    defined(STLSOFT_COMPILER_IS_GCC)
    ~com_exception() stlsoft_throw_0()
    {}
#endif /* compiler */
/// @}

/// \name Accessors
/// @{
public:
    virtual char const *what() const stlsoft_throw_0()
    {
        return m_reason.empty() ? this->real_what_(): m_reason.c_str();
    }

    HRESULT hr() const
    {
        return m_hr;
    }
/// @}

/// \name Implementation
/// @{
private:
    virtual char const *real_what_() const throw()
    {
        return "COM system exception";
    }
/// @}

// Members
private:
    string_type m_reason;
    HRESULT     m_hr;
};

/// The exception type thrown by safearray_sequence on variant type mismatches
class variant_type_exception
    : public com_exception
{
public:
    typedef com_exception           parent_class_type;
    typedef variant_type_exception  class_type;

/// \name Construction
/// @{
public:
    ss_explicit_k variant_type_exception(HRESULT hr)
        : parent_class_type(hr)
    {}
    variant_type_exception(char const *reason, HRESULT hr)
        : parent_class_type(reason, hr)
    {}
#if defined(STLSOFT_COMPILER_IS_COMO) || \
    defined(STLSOFT_COMPILER_IS_GCC)
    ~variant_type_exception() stlsoft_throw_0()
    {}
#endif /* compiler */
/// @}

/// \name Implementation
/// @{
private:
    virtual char const *real_what_() const throw()
    {
        return "VARIANT type exception";
    }
/// @}
};

/* ////////////////////////////////////////////////////////////////////////////
 * Policies
 */

/// Policy adaptor template for exception throwing
template <ss_typename_param_k X>
// [[synesis:class:exception-policy: exception_policy_base]]
struct exception_policy_base
{
public:
    /// The thrown type
    typedef X       thrown_type;

public:
    /// Function call operator, taking no parameters
    void operator ()()
    {
        throw thrown_type(::GetLastError());
    }
    /// Function call operator, taking one parameter
    void operator ()(HRESULT hr) const
    {
        throw thrown_type(hr);
    }
    /// Function call operator, taking two parameters
    void operator ()(char const *reason, HRESULT hr) const
    {
        throw thrown_type(reason, hr);
    }
};

/// The policy class, which throws a com_exception class.
typedef exception_policy_base<com_exception>            com_exception_policy;

/// The policy class, which throws a com_exception class.
typedef exception_policy_base<variant_type_exception>   variant_type_exception_policy;

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_exceptions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "exceptions", __FILE__);

    #if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_exceptions(test_comstl_exceptions);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_H_COMSTL_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
