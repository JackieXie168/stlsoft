/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/string/bstr.hpp (originally MOBStr.h/.cpp, ::SynesisCom)
 *
 * Purpose:     bstr class.
 *
 * Created:     20th December 1996
 * Updated:     3rd December 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/** \file comstl/string/bstr.hpp
 *
 * \brief [C++ only; requires COM] Definition of the comstl::bstr class.
 *  (\ref group__library__com_utility "COM Utility" Library.)
 */

#ifndef COMSTL_INCL_COMSTL_STRING_HPP_BSTR
#define COMSTL_INCL_COMSTL_STRING_HPP_BSTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _COMSTL_VER_COMSTL_STRING_HPP_BSTR_MAJOR       2
# define _COMSTL_VER_COMSTL_STRING_HPP_BSTR_MINOR       1
# define _COMSTL_VER_COMSTL_STRING_HPP_BSTR_REVISION    4
# define _COMSTL_VER_COMSTL_STRING_HPP_BSTR_EDIT        37
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
//#ifndef COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING
//# include <comstl/shims/access/string.hpp>
//#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_HPP_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS
#  include <comstl/error/exceptions.hpp>
# endif /* !COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS */
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS
# include <comstl/string/bstr_functions.h>
#endif /* !COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Facade for the COM BSTR type
 *
 * \ingroup group__library__com_utility
 */
class bstr
{
/// \name Member Types
/// @{
public:
    typedef bstr                class_type;
    typedef cs_char_o_t         char_type;
    typedef char_type           *pointer;
    typedef char_type const     *const_pointer;
    typedef char_type           &reference;
    typedef char_type const     &const_reference;
    typedef cs_ptrdiff_t        difference_type;
    typedef cs_size_t           size_type;
    typedef cs_bool_t           bool_type;
/// @}

/// \name Construction
/// @{
public:
    bstr();
    ss_explicit_k bstr(cs_char_a_t const *s, int len = -1);
    ss_explicit_k bstr(cs_char_w_t const *s, int len = -1);
    bstr(size_type n, char_type ch);
    /// \brief Copy constructor
    bstr(class_type const &rhs);
    ~bstr() stlsoft_throw_0();

    /// \brief Copies the given instance
    class_type  &operator =(class_type const &rhs);

    class_type  &assign(cs_char_a_t const *s, int len = -1);
    class_type  &assign(cs_char_w_t const *s, int len = -1);

    class_type  &operator =(cs_char_a_t const *s);
    class_type  &operator =(cs_char_w_t const *s);

    void        clear();
/// @}

/// \name Operations
/// @{
public:
/// @}

/// \name Accessors
/// @{
public:
    const_pointer   data() const;
    const_pointer   c_str() const;
    size_type       length() const;
    size_type       size() const;
    bool_type       empty() const;
    BSTR            get() const;

    const_pointer   *NonDestructiveAddress() const;
    BSTR            *NonDestructiveAddress();
    BSTR            *DestructiveAddress();
/// @}

/// \name Comparison
/// @{
public:
    /// \brief Evaluates whether the value is equivalent to the given argument
    bool_type equal(class_type const &rhs) const;
    /// \brief Evaluates whether the value is equivalent to the given argument
    bool_type equal(BSTR const &rhs) const;
/// @}

/// \name Operations
/// @{
public:
    /// \brief Swaps the contents with the given instance
    void swap(class_type &rhs) stlsoft_throw_0();
/// @}

/// \name Members
/// @{
private:
    BSTR    m_bstr;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * String access shims
 */

/** \brief \ref section__concept__shims__string_access__c_str_data for comstl::bstr
 *
 * \ingroup group__concept__shims__string_access
 */
inline bstr::const_pointer c_str_data(comstl_ns_qual(bstr) const &b)
{
    return b.data();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline bstr::const_pointer c_str_data_w(comstl_ns_qual(bstr) const &b)
{
    return b.data();
}

inline bstr::const_pointer c_str_data_o(comstl_ns_qual(bstr) const &b)
{
    return b.data();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_len for comstl::bstr
 *
 * \ingroup group__concept__shims__string_access
 */
inline size_t c_str_len(comstl_ns_qual(bstr) const &b)
{
    return b.length();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline size_t c_str_len_w(comstl_ns_qual(bstr) const &b)
{
    return b.length();
}

inline size_t c_str_len_o(comstl_ns_qual(bstr) const &b)
{
    return b.length();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_ptr for comstl::bstr
 *
 * \ingroup group__concept__shims__string_access
 */
inline bstr::const_pointer c_str_ptr(comstl_ns_qual(bstr) const &b)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline bstr::const_pointer c_str_ptr_w(comstl_ns_qual(bstr) const &b)
{
    return b.c_str();
}

inline bstr::const_pointer c_str_ptr_o(comstl_ns_qual(bstr) const &b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_ptr_null for comstl::bstr
 *
 * \ingroup group__concept__shims__string_access
 */
inline bstr::const_pointer c_str_ptr_null(comstl_ns_qual(bstr) const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline bstr::const_pointer c_str_ptr_null_w(comstl_ns_qual(bstr) const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null_w)(b.c_str());
}

inline bstr::const_pointer c_str_ptr_null_o(comstl_ns_qual(bstr) const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline cs_bool_t operator ==(bstr const &lhs, bstr const &rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(bstr const &lhs, bstr const &rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(bstr const &lhs, BSTR const &rhs)
{
    return lhs.equal(rhs);
}

inline cs_bool_t operator !=(bstr const &lhs, BSTR const &rhs)
{
    return !operator ==(lhs, rhs);
}

inline cs_bool_t operator ==(BSTR const &lhs, bstr const &rhs)
{
    return rhs.equal(lhs);
}

inline cs_bool_t operator !=(BSTR const &lhs, bstr const &rhs)
{
    return !operator ==(lhs, rhs);
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/bstr_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Construction
inline bstr::bstr()
    : m_bstr(NULL)
{}

inline /* explicit */ bstr::bstr(cs_char_a_t const *s, int len /* = -1 */)
{
    if(len < 0)
    {
        len = (NULL == s) ? 0 : static_cast<int>(::strlen(s));
    }

    m_bstr = bstr_create(s, static_cast<cs_size_t>(len));

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if( NULL == m_bstr &&
        NULL != s &&
        0 != len &&
        '\0' != 0[s])
    {
        throw_x(com_exception("failed to allocate string", HRESULT_FROM_WIN32(::GetLastError())));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline /* explicit */ bstr::bstr(cs_char_w_t const *s, int len /* = -1 */)
{
    if(len < 0)
    {
        len = (NULL == s) ? 0 : static_cast<int>(::wcslen(s));
    }

    m_bstr = bstr_create(s, static_cast<cs_size_t>(len));

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if( NULL == m_bstr &&
        NULL != s &&
        0 != len &&
        '\0' != 0[s])
    {
        throw_x(com_exception("failed to allocate string", HRESULT_FROM_WIN32(::GetLastError())));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline bstr::bstr(bstr::size_type n, bstr::char_type ch)
    : m_bstr(bstr_create_w(NULL, n))
{
    if(NULL == m_bstr)
    {
        if(0 != n)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw_x(com_exception("failed to allocate string", HRESULT_FROM_WIN32(::GetLastError())));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    else
    {
        { for(size_type i = 0; i < n; ++i)
        {
            m_bstr[i] = ch;
        }}
    }
}

inline bstr::bstr(bstr::class_type const &rhs)
    : m_bstr(bstr_dup(rhs.m_bstr))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if( NULL == m_bstr &&
        !rhs.empty())
    {
        throw_x(com_exception("failed to allocate string", HRESULT_FROM_WIN32(::GetLastError())));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline bstr::~bstr() stlsoft_throw_0()
{
    ::SysFreeString(m_bstr);
}

inline bstr::class_type &bstr::operator =(bstr::class_type const &rhs)
{
    class_type  t(rhs);

    t.swap(*this);

    return *this;
}

inline bstr::class_type &bstr::assign(cs_char_a_t const *s, int len /* = -1 */)
{
    class_type  t(s, len);

    t.swap(*this);

    return *this;
}

inline bstr::class_type &bstr::assign(cs_char_w_t const *s, int len /* = -1 */)
{
    class_type  t(s, len);

    t.swap(*this);

    return *this;
}

inline bstr::class_type &bstr::operator =(cs_char_a_t const *s)
{
    return assign(s);
}

inline bstr::class_type &bstr::operator =(cs_char_w_t const *s)
{
    return assign(s);
}

inline void bstr::clear()
{
    ::SysFreeString(m_bstr);

    m_bstr = NULL;
}

// Operations

// Accessors
inline bstr::const_pointer bstr::data() const
{
    return this->c_str();
}

inline bstr::const_pointer bstr::c_str() const
{
    return (NULL == m_bstr) ? L"" : m_bstr;
}

inline bstr::size_type bstr::length() const
{
    return static_cast<size_type>(::SysStringLen(m_bstr));
}

inline bstr::size_type bstr::size() const
{
    return this->length();
}

inline bstr::bool_type bstr::empty() const
{
    return 0 == this->size();
}

inline BSTR bstr::get() const
{
    return m_bstr;
}

inline bstr::const_pointer *bstr::NonDestructiveAddress() const
{
    return const_cast<const_pointer*>(&m_bstr);
}

inline BSTR *bstr::NonDestructiveAddress()
{
    return &m_bstr;
}

inline BSTR *bstr::DestructiveAddress()
{
    clear();

    return &m_bstr;
}

inline bstr::bool_type bstr::equal(bstr::class_type const &rhs) const
{
    return 0 == bstr_compare(this->get(), rhs.get());
}

inline bstr::bool_type bstr::equal(BSTR const &rhs) const
{
    return 0 == bstr_compare(this->get(), rhs);
}

// Operations

inline void bstr::swap(bstr::class_type &rhs) stlsoft_throw_0()
{
    std_swap(m_bstr, rhs.m_bstr);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _COMSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::comstl::c_str_data;
using ::comstl::c_str_data_w;
using ::comstl::c_str_data_o;

using ::comstl::c_str_len;
using ::comstl::c_str_len_w;
using ::comstl::c_str_len_o;

using ::comstl::c_str_ptr;
using ::comstl::c_str_ptr_w;
using ::comstl::c_str_ptr_o;

using ::comstl::c_str_ptr_null;
using ::comstl::c_str_ptr_null_w;
using ::comstl::c_str_ptr_null_o;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_STRING_HPP_BSTR */

/* ////////////////////////////////////////////////////////////////////// */
