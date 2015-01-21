/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/resource_string.hpp (was winstl_resource_string.h; formerly MWResStr.h: ::SynesisWin)
 *
 * Purpose:     basic_resource_string class.
 *
 * Created:     1st November 1994
 * Updated:     22nd December 2005
 *
 * Thanks to:   Ryan Ginstrom for suggesting the implementation for handling
 *              Unicode strings on Win9x.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2005, Matthew Wilson and Synesis Software
 * Copyright (c) 2004-2005, Ryan Ginstrom
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


/// \file winstl/resource_string.hpp
///
/// basic_resource_string class.

#ifndef WINSTL_INCL_WINSTL_HPP_RESOURCE_STRING
#define WINSTL_INCL_WINSTL_HPP_RESOURCE_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_RESOURCE_STRING_MAJOR    3
# define WINSTL_VER_WINSTL_HPP_RESOURCE_STRING_MINOR    1
# define WINSTL_VER_WINSTL_HPP_RESOURCE_STRING_REVISION 1
# define WINSTL_VER_WINSTL_HPP_RESOURCE_STRING_EDIT     57
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

//#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_TRAITS
//# include <stlsoft/string_traits.hpp>
//#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
# include <stlsoft/exceptions.hpp>      // for stlsoft::null_exception_policy
#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#ifdef STLSOFT_UNITTEST
# include <iostream>                    // for std::cout, std::endl
# include <string>                      // for std::string, std::wstring
# include <stdio.h>                     // for fprintf(), stdout
#endif /* STLSOFT_UNITTEST */
#include <exception>

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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_string String Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating strings

/// \defgroup winstl_string_library String Library (WinSTL)
/// \ingroup WinSTL libraries_string
/// \brief This library provides facilities for defining and manipulating Win32 string types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class basic_resource_string
/// Instances of this class represent Windows string resources, and are
/// constructed from instance identifiers.
///
/// It is an adaptor template, so is parameterised with the underlying string
/// type. For example, <code>winstl::basic_resource_string&lt;std::string&gt;</code>
/// is parameterised from <code>std::string</code>, and can therefore use its methods
/// and is compatible with its compatible code:
///
/// \htmlonly
/// <pre>
/// winstl::basic_resource_string&lt;std::string&gt;  str(1024);
/// 
/// std::cout << "String with id 1024: " << str << std::endl;
///
/// fprintf(stdout, "String with id 1024: %.*s\n", str.size(), str.data());
/// </pre>
/// \endhtmlonly
///
/// The second template parameter is the exception policy, which determines
/// how the string reacts to a failure to load a string resource corresponding
/// to the given Id. It is defaulted to stlsoft::null_exception_policy, which
/// means that, when a corresponding string resource is not loaded, the
/// resource string instance will be correctly constructed but will contain
/// the empty string, i.e.:
///
/// \htmlonly
/// <pre>
/// // Assuming 9999999 is not a valid string resource identifier in the
/// // module whose instance handle is in hinst ...
/// winstl::basic_resource_string&lt;std::string&gt;  str(hinst, 9999999);
/// 
/// assert(0 == str.size());
/// assert(str == "");
/// </pre>
/// \endhtmlonly
///
/// If you want your parameterisation to throw an exception when the string
/// resource is not found, simply specify a policy that throws an exception
/// to the parameterisation, as in:
///
/// \htmlonly
/// <pre>
/// // Assuming 9999999 is not a valid string resource identifier in the
/// // module whose instance handle is in hinst ...
/// try
/// {
///   winstl::basic_resource_string&lt;std::string, throw_MyX_policy&gt;  str(hinst, 9999999);
/// 
///   std::cerr << "Should never get here!!" << std::endl;
/// }
/// catch(MyX &x)
/// {
///   std::cerr << "This is what's expected" << std::endl;
/// }
/// </pre>
/// \endhtmlonly
///
/// \note The handling of Unicode strings under Windows 9x family operating
/// systems eschews the use of LoadStringW(), instead manipulating the resource
/// information via FindResourceEx() / LoadResource() / LockResource(). This
/// code kindly provided by Ryan Ginstrom.
///
/// \param S The string class, e.g. std::string, stlsoft::simple_string, etc.
/// \param X The exception class
template<   ss_typename_param_k S
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k X = stlsoft_ns_qual(null_exception_policy)
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k X /* = stlsoft_ns_qual(null_exception_policy) */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_resource_string
    : public S
    , protected X
{
private:
    typedef S                                          parent_class_type;
//    typedef C                                          value_type;
public:
    /// The type of the underlying string
    typedef S                                          string_type;
    /// The type of the current parameterisation
    typedef basic_resource_string<S, X>                class_type;
    /// The exception policy type
    typedef X                                          exception_policy_type;
    /// The exception policy type
    ///
    /// \deprecated
    typedef exception_policy_type                      exception_type;
//    typedef stlsoft_ns_qual(string_traits)<S>          string_traits_type;

    typedef ss_typename_type_k string_type::value_type value_type;

/// \name Construction
/// @{
public:
    /// Constructs an around the string loaded from the given \c id
    ss_explicit_k basic_resource_string(ws_int_t id) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        load(::GetModuleHandle(NULL), id);
    }

    /// Constructs an around the string loaded from the given \c id and \c hinst
    basic_resource_string(HINSTANCE hinst, ws_int_t id) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        load(hinst, id);
    }

    /// Copy constructor
    basic_resource_string(const basic_resource_string &rhs)
        : parent_class_type(rhs)
    {}

    /// Copy constructor
    basic_resource_string(const string_type &rhs)
        : parent_class_type(rhs)
    {}

    /// Copy assignment operator
    const basic_resource_string &operator =(const basic_resource_string &rhs)
    {
        parent_class_type::operator =(rhs);

        return *this;
    }
    /// Copy assignment operator
    const basic_resource_string &operator =(const string_type &rhs)
    {
        parent_class_type::operator =(rhs);

        return *this;
    }

/// @}

// Implementation
private:
    ws_int_t LoadString(HINSTANCE hinst, int uID, ws_char_a_t *buffer, ws_size_t cchBuffer)
    {
        return ::LoadStringA(hinst, static_cast<UINT>(uID), buffer, static_cast<int>(cchBuffer));
    }
    ws_int_t LoadString(HINSTANCE hinst, int uID, ws_char_w_t *buffer, ws_size_t cchBuffer)
    {
        if(::GetVersion() & 0x80000000)
        {
            // This block of code kindly provided by Ryan Ginstrom
            int     block   =   (uID >> 4) + 1; // Compute block number.
            int     num     =   uID & 0xf;      // Compute offset into block.
            HRSRC   hRC     =   ::FindResourceEx(   hinst
                                                ,   RT_STRING
                                                ,   MAKEINTRESOURCE(block)
                                                ,   MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL));

            if(NULL != hRC)
            {
                HGLOBAL hgl = ::LoadResource(hinst, hRC);

                if(NULL != hgl)
                {
                    LPWSTR  res_str =   (LPWSTR)::LockResource(hgl);

                    if(NULL != res_str)
                    {
                        for(int i = 0; i < num; ++i)
                        {
                            res_str += *res_str + 1;
                        }

                        const LPCWSTR   ptr =   res_str + 1;
                        const size_t    cch =   static_cast<size_t>(*res_str);

                        if(cch < cchBuffer)
                        {
                            cchBuffer = cch + 1; // This is +1, since lstrcpyn 'uses' a character for the nul character
                            buffer[cch] = L'\0';
                        }

                        ::lstrcpynW(buffer, ptr, static_cast<int>(cchBuffer));

                        return static_cast<ws_int_t>(cchBuffer);
                    }
                }
            }

            return 0;
        }

        return ::LoadStringW(hinst, static_cast<UINT>(uID), buffer, static_cast<int>(cchBuffer));
    }

    void load(HINSTANCE hinst, ws_int_t id) stlsoft_throw_1(ss_typename_type_k exception_policy_type::thrown_type)
    {
        // TODO: Verify that it's not possible to load string resources of >256. If that's
        // wrong, then need to fix this to use auto_buffer
        value_type  sz[1024];

        if(0 == this->LoadString(hinst, id, sz, winstl_num_elements(sz)))
        {
            exception_policy_type()(hinst, id);

//            parent_class_type::operator =(string_traits_type::empty_string());
            parent_class_type::operator =(string_type());
        }
        else
        {
            parent_class_type::operator =(sz);
        }
    }
};

///////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/resource_string_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * String access shims
 */

#if 0
/* c_str_ptr_null */

/// \brief Returns the corresponding C-string pointer of \c s, or a null pointer
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const *c_str_ptr_null(basic_resource_string<S, X> const &s)
{
    return (s.length() == 0) ? 0 : s.c_str();
}

/* c_str_ptr */

/// \brief Returns the corresponding C-string pointer of \c s
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const *c_str_ptr(basic_resource_string<S, X> const &s)
{
    return s.c_str();
}

/* c_str_ptr */

/// \brief Returns the corresponding C-string pointer of \c s
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline C const *c_str_data(basic_resource_string<S, X> const &s)
{
    return s.c_str();
}
#endif /* 0 */

/* c_str_ptr_len */

/// \brief Returns the length (in characters) of \c s, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline ss_size_t c_str_len(basic_resource_string<S, X> const &s)
{
    return s.length();
}

/* c_str_ptr_size */

/// \brief Returns the size (in bytes) of the contents of \c s, <b><i>not</i></b> including the null-terminating character
template<   ss_typename_param_k S
        ,   ss_typename_param_k X
        >
inline ss_size_t c_str_size(basic_resource_string<S, X> const &s)
{
    return c_str_len(s) * sizeof(ss_typename_type_k basic_resource_string<S, X>::value_type);
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_string_library

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

#endif /* !WINSTL_INCL_WINSTL_HPP_RESOURCE_STRING */

/* ////////////////////////////////////////////////////////////////////////// */
