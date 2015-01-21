/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exceptions.hpp (formerly stlsoft_exceptions.h)
 *
 * Purpose:     Basic exception classes.
 *
 * Created:     19th January 2002
 * Updated:     10th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
 * Copyright (c) 2006, Pablo Aguilar
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software, nor Pablo
 *   Aguilar, nor the names of any contributors may be used to endorse or
 *   promote products derived from this software without specific prior written
 *   permission.
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


/// \file stlsoft/exceptions.hpp
///
/// Basic exception classes and policies.

#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
#define STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_EXCEPTIONS_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_EXCEPTIONS_MINOR     2
# define STLSOFT_VER_STLSOFT_HPP_EXCEPTIONS_REVISION  2
# define STLSOFT_VER_STLSOFT_HPP_EXCEPTIONS_EDIT      39
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#include <exception>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_exceptions Exceptions Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating exceptions
/// @{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Root exception class for sub-project platform-specific exceptions
class os_exception
#if defined(STLSOFT_COMPILER_IS_DMC)
    : public std::exception
#else /* ? compiler */
    : public stlsoft_ns_qual_std(exception)
#endif /* compiler */
{
/// \name Types
/// @{
public:
    /// The type of the current instantiation
    typedef os_exception                    class_type;
    /// The parent type
#if defined(STLSOFT_COMPILER_IS_DMC)
    typedef std::exception                  parent_class_type;
#else /* ? compiler */
    typedef stlsoft_ns_qual_std(exception)  parent_class_type;
#endif /* compiler */
/// @}

/// \name Construction
/// @{
public:
    /// Default constructor
    os_exception()
    {}
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a human-readable string describing the exception condition
    virtual char const *what() const stlsoft_throw_0()
    {
        return "operating system exception";
    }
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries_exceptions_policies Exception Policies
/// \ingroup libraries_exceptions
/// \brief Exception policy classes
/// @{

/* /////////////////////////////////////////////////////////////////////////
 * Policies
 */

/// The no-throwing exception policy. It does not throw, and its throw type is empty.
// [[synesis:class:exception-policy: null_exception_policy]]
struct null_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    struct thrown_type
    {
    };
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking no parameters
    void operator ()() const
    {}
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator, taking one parameter
    template <ss_typename_param_k T>
    void operator ()(T const &/* t */) const stlsoft_throw_0()
    {
        // Do nothing
    }
    /// Function call operator, taking two parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            >
    void operator ()(T1 const &/* t1 */, T2 const &/* t2 */) const stlsoft_throw_0()
    {
        // Do nothing
    }
    /// Function call operator, taking three parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            >
    void operator ()(T1 const &/* t1 */, T2 const &/* t2 */, T3 const &/* t3 */) const stlsoft_throw_0()
    {
        // Do nothing
    }
    /// Function call operator, taking four parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            ,   ss_typename_param_k T4
            >
    void operator ()(T1 const &/* t1 */, T2 const &/* t2 */, T3 const &/* t3 */, T4 const &/* t4 */) const stlsoft_throw_0()
    {
        // Do nothing
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
/// @}
};

/// Alternative typedef for null_exception_policy
typedef null_exception_policy   nothrow_exception_policy;

/// The throwing exception policy. It throws instances of its parameterising type.
template<ss_typename_param_k E>
// [[synesis:class:exception-policy: throw_exception_policy]]
struct throw_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef E               thrown_type;
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking no parameters
    void operator ()() const
    {
        throw thrown_type();
    }
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator, taking one parameter
    template <ss_typename_param_k T>
    void operator ()(T const &t) const
    {
        throw_exception_(thrown_type(t));
    }
    /// Function call operator, taking two parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2>
    void operator ()(T1 const &t1, T2 const &t2) const
    {
        throw_exception_(thrown_type(t1, t2));
    }
    /// Function call operator, taking three parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2, ss_typename_param_k T3>
    void operator ()(T1 const &t1, T2 const &t2, T3 const &t3) const
    {
        throw_exception_(thrown_type(t1, t2, t3));
    }
    /// Function call operator, taking four parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2, ss_typename_param_k T3, ss_typename_param_k T4>
    void operator ()(T1 const &t1, T2 const &t2, T3 const &t3, T4 const &t4) const
    {
        throw_exception_(thrown_type(t1, t2, t3, t4));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
/// @}

/// \name Implementation
/// @{
private:
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
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
/// @}
};


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef null_exception_policy   null_exception;
typedef null_exception_policy   nothrow_exception;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

/// @} // end of group libraries_exceptions_policies

/* ////////////////////////////////////////////////////////////////////// */

/// @} // end of group libraries_exceptions

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////// */
