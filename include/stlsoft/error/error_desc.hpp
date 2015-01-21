/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/error_desc.hpp
 *
 * Purpose:     Converts a standard rerror code (errno) to a printable string.
 *
 * Created:     18th July 2006
 * Updated:     18th December 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/** \file stlsoft/error/error_desc.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::basic_error_desc class
 *  template.
 *  (\ref group__library__error "Error" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_MAJOR     1
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_MINOR     0
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_REVISION  2
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_EDIT      5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS
# include <stlsoft/string/cstring_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#include <string.h>     // for strerror()

#ifdef STLSOFT_UNITTEST
# include <errno.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !_STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Utility class that loads the system string representation
 *   corresponding to a given error code.
 *
 * \ingroup group__library__error
 *
 * Consider the following example:
\htmlonly
<pre>
  stlsoft::error_desc_a  ed1(ENOMEM);
  stlsoft::error_desc    ed3(ENOMEM);

  assert(0 == ::strcmp("Access is denied", ed1.c_str()));
  assert(0 == ::wcscmp(L"Access is denied", ed2.c_str()));
  assert(0 == ::_tcscmp(_T("Access is denied"), ed3.c_str()));
</pre>
\endhtmlonly
 *
 * By default, the strings are looked up from the Windows system DLLs. To
 * use a specific message-string DLL, simply specify this as the second
 * argument to the constructor, as in (assuming <b>MyCustomDll.DLL</b> maps
 * <code>ERROR_ACCESS_DENIED</code> to <code>"No Access!"</code>):
 *
\htmlonly
<pre>
  stlsoft::error_desc_a  ed1(ERROR_ACCESS_DENIED, "MyCustomDll.DLL");

  assert(0 == ::strcmp("No Access!", ed1.c_str()));
</pre>
\endhtmlonly
 *
 * \note Naturally, \ref group__concept__shim__string_access "String Access
 *  Shim" functions <b>c_str_ptr</b>, <b>c_str_data</b>, <b>c_str_len</b>
 *  are defined for the class template, so it may be manipulated
 *  generically. (This is very handy when used with the
 *  <a href = "http://pantheios.org/">Pantheios</a> logging library.)
 */
template <ss_typename_param_k C>
class basic_error_desc
#if defined(STLSOFT_COMPILER_IS_DMC)
    : protected allocator_selector<C>::allocator_type
#else /* ? compiler */
    : private allocator_selector<C>::allocator_type
#endif /* compiler */
{
/// \name Types
/// @{
private:
    typedef ss_typename_type_k allocator_selector<C>::allocator_type    parent_class_type;
    typedef ss_typename_type_k allocator_selector<C>::allocator_type    allocator_type;
public:
    /// \brief The character type
    typedef C                                                           char_type;
    /// \brief The current parameterisation of the type
    typedef basic_error_desc<C>                                         class_type;
    /// \brief The error type
    typedef int                                                         error_type;
    /// \brief The size type
    typedef ss_size_t                                                   size_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Loads the error string associated with the given code.
    ///
    /// \param error The errno value whose string equivalent will be searched
    ss_explicit_k basic_error_desc(error_type error = errno);
    /// \brief Releases any resources.
    ~basic_error_desc() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// \brief The error description
    char_type const *get_description() const;
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The error description
    char_type const *c_str() const;
    /// \brief The length of the error description
    size_type       length() const stlsoft_throw_0();
    /// \brief The length of the error description
    size_type       size() const stlsoft_throw_0();
/// @}

/// \name Implementation
/// @{
private:
    allocator_type &get_allocator_();
/// @}

/// \name Members
/// @{
private:
    char_type   *m_str;
    size_type   m_length;
/// @}

/// \name Not to be implemented
/// @{
private:
    basic_error_desc(class_type const &);
    basic_error_desc &operator =(class_type const &);
/// @}
};

/* Typedefs to commonly encountered types. */
/** \brief Specialisation of the basic_error_desc template for the ANSI character type \c char
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<ss_char_a_t>   error_desc_a;
/** \brief Specialisation of the basic_error_desc template for the character type \c char
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<char>         error_desc;

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
inline ss_typename_type_k basic_error_desc<C>::allocator_type &basic_error_desc<C>::get_allocator_()
{
    return *this;
}

template <ss_typename_param_k C>
inline basic_error_desc<C>::basic_error_desc(ss_typename_type_k basic_error_desc<C>::error_type error /* = errno */)
    : m_str(string_dup(::strerror(error), get_allocator_(), &m_length))
{}

template <ss_typename_param_k C>
inline basic_error_desc<C>::~basic_error_desc() stlsoft_throw_0()
{
    get_allocator_().deallocate(m_str, m_length);
}

template <ss_typename_param_k C>
inline ss_typename_type_k basic_error_desc<C>::char_type const *basic_error_desc<C>::get_description() const
{
    static const char_type s_nullMessage[1] = { '\0' };

    return (NULL != m_str) ? m_str : s_nullMessage;
}

template <ss_typename_param_k C>
inline ss_typename_type_k basic_error_desc<C>::char_type const *basic_error_desc<C>::c_str() const
{
    return get_description();
}

template <ss_typename_param_k C>
inline ss_typename_type_k basic_error_desc<C>::size_type basic_error_desc<C>::length() const stlsoft_throw_0()
{
    return m_length;
}

template <ss_typename_param_k C>
inline ss_typename_type_k basic_error_desc<C>::size_type basic_error_desc<C>::size() const stlsoft_throw_0()
{
    return length();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * String access shims
 */

#ifndef STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

/** \brief \ref group__concept__shim__string_access__c_str_ptr_null for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template <ss_typename_param_k C>
inline C const *c_str_ptr_null(stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    return (0 != e.length()) ? e.c_str() : NULL;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline ss_char_a_t const *c_str_ptr_null_a(stlsoft_ns_qual(basic_error_desc)<ss_char_a_t> const &e)
{
    return (0 != e.length()) ? e.c_str() : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_ptr for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template <ss_typename_param_k C>
inline C const *c_str_ptr(stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline ss_char_a_t const *c_str_ptr_a(stlsoft_ns_qual(basic_error_desc)<ss_char_a_t> const &e)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_data for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template <ss_typename_param_k C>
inline C const *c_str_data(stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline ss_char_a_t const *c_str_data_a(stlsoft_ns_qual(basic_error_desc)<ss_char_a_t> const &e)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref group__concept__shim__string_access__c_str_len for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__string_access
 */
template <ss_typename_param_k C>
inline ss_size_t c_str_len(stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    return e.length();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline ss_size_t c_str_len_a(stlsoft_ns_qual(basic_error_desc)<ss_char_a_t> const &e)
{
    return e.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief \ref group__concept__shim__pointer_attribute__get_ptr for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__pointer_attribute__get_ptr
 */
template <ss_typename_param_k C>
inline C const *get_ptr(stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    return e;
}


/** \brief \ref group__concept__shim__stream_insertion "stream insertion shim" for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__shim__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
inline S &operator <<(S &s, stlsoft_ns_qual(basic_error_desc)<C> const &e)
{
    s << e.get_description();

    return s;
}

#endif /* !STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/error_desc_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC */

/* ////////////////////////////////////////////////////////////////////// */
