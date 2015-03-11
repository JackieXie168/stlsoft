/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/conversion/char_conversions.hpp (originally MLStrCnv.h, ::SynesisStd)
 *
 * Purpose:     Type conversions for Windows.
 *
 * Created:     31st May 2003
 * Updated:     31st October 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/conversion/char_conversions.hpp
 *
 * \brief [C++ only] Definition of the winstl::multibyte2wide and
 *  winstl::wide2multibyte class templates.
 *  (\ref group__library__conversion "Conversion" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS
#define WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_MAJOR    5
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_MINOR    0
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_REVISION 2
# define WINSTL_VER_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS_EDIT     75
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_GCC:  __GNUC__<3
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
# error winstl/conversion/char_conversions.hpp is not compatible with GNU C++ prior to 3.0
#endif /* compiler */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error winstl/conversion/char_conversions.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS
#  include <winstl/error/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS */
# include <errno.h>
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_UNITTEST
# include <wchar.h>
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Converts a multibyte (<code>char</code>-based) string to a wide
 *   (<code>whar_t</code>-based) string.
 *
 * \ingroup group__library__conversion
 */
template <ws_size_t CCH>
class multibyte2wide
    : public auto_buffer_old<ws_char_w_t, processheap_allocator<ws_char_w_t>, CCH>
{
/// \name Member Types
/// @{
private:
    typedef auto_buffer_old<ws_char_w_t, processheap_allocator<ws_char_w_t>, CCH>   parent_class_type;
public:
    /// \brief The character type
    typedef ws_char_w_t                                                             char_type;
    /// \brief The alternate character type
    typedef ws_char_a_t                                                             alt_char_type;
    /// \brief The size type
    typedef ss_typename_type_k parent_class_type::size_type                         size_type;
    /// \brief The pointer type
    typedef ss_typename_type_k parent_class_type::pointer                           pointer;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k S>
    ss_explicit_k multibyte2wide(S const &s)
#else
    ss_explicit_k multibyte2wide(alt_char_type const *s)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(stlsoft_ns_qual(c_str_len)(s) + 1)
    {
        prepare_(stlsoft_ns_qual(c_str_ptr_a)(s));
    }

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k S>
    multibyte2wide(S const &s, size_type cch)
#else
    multibyte2wide(alt_char_type const *s, size_type cch)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(cch + 1)
    {
        prepare_(stlsoft_ns_qual(c_str_ptr_a)(s));
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/// @}

/// \name Implementation
/// @{
private:
    void prepare_(alt_char_type const *s)
    {
        const size_type size    =   parent_class_type::size();
        const pointer   data    =   parent_class_type::data();

        // If the auto_buffer failed to allocate the required memory, and
        // we're not in an exception-environment, then size() will be zero
        if(0 == size)
        {
            // Since we know that auto_buffer's parameterising size must
            // always be greater that 0, then
            data[0] = '\0';
        }
        else
        {
            // Note: cannot use -1 for length, since s might be a type that
            // could change length
            if(0 == ::MultiByteToWideChar(0, 0, s, static_cast<int>(size), data, static_cast<int>(size)))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
// TODO:        throw conversion_exception("failed to convert multibyte string to wide string", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                data[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                data[size - 1] = '\0';
            }
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    char_type const *c_str() const
    {
        return parent_class_type::data();
    }
/// @}

/// \name Operators
/// @{
public:
    operator char_type const *() const
    {
        return parent_class_type::data();
    }
/// @}

/// \name Not to be implemented
/// @{
private:
    multibyte2wide(multibyte2wide const &);
    multibyte2wide &operator =(multibyte2wide const &);

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}
};

/** \brief Converts a wide (<code>whar_t</code>-based) string to a
 *    multibyte (<code>char</code>-based) string.
 *
 * \ingroup group__library__conversion
 */
template <ws_size_t CCH>
class wide2multibyte
    : public auto_buffer_old<ws_char_a_t, processheap_allocator<ws_char_a_t>, CCH>
{
/// \name Member Types
/// @{
private:
    typedef auto_buffer_old<ws_char_a_t, processheap_allocator<ws_char_a_t>, CCH>   parent_class_type;
public:
    /// \brief The character type
    typedef ws_char_a_t                                                             char_type;
    /// \brief The alternate character type
    typedef ws_char_w_t                                                             alt_char_type;
    /// \brief The size type
    typedef ss_typename_type_k parent_class_type::size_type                         size_type;
    /// \brief The pointer type
    typedef ss_typename_type_k parent_class_type::pointer                           pointer;
/// @}

/// \name Construction
/// @{
public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k S>
    ss_explicit_k wide2multibyte(S const &s)
#else
    ss_explicit_k wide2multibyte(alt_char_type const *s)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(stlsoft_ns_qual(c_str_len)(s) + 1)
    {
        prepare_(stlsoft_ns_qual(c_str_ptr_w)(s));
    }

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    template <ss_typename_param_k S>
    ss_explicit_k wide2multibyte(S const &s, size_type cch)
#else
    ss_explicit_k wide2multibyte(alt_char_type const *s, size_type cch)
#endif // STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        : parent_class_type(cch + 1)
    {
        prepare_(stlsoft_ns_qual(c_str_ptr_w)(s));
    }
/// @}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Implementation
private:
    void prepare_(alt_char_type const *s)
    {
        const size_type size    =   parent_class_type::size();
        const pointer   data    =   parent_class_type::data();

        // If the auto_buffer failed to allocate the required memory, and
        // we're not in an exception-environment, then size() will be zero
        if(0 == size)
        {
            // Since we know that auto_buffer's parameterising size must
            // always be greater that 0, then
            data[0] = '\0';
        }
        else
        {
            // Note: cannot use -1 for length, since s might be a type that
            // could change length
            if(0 == ::WideCharToMultiByte(0, 0, s, static_cast<int>(size), data, static_cast<int>(size), NULL, NULL))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
// TODO:        throw conversion_exception("failed to convert multibyte string to wide string", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                data[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                data[size - 1] = '\0';
            }
        }
    }

/// \name Accessors
/// @{
public:
    char_type const *c_str() const
    {
        return parent_class_type::data();
    }
/// @}

/// \name Operators
/// @{
public:
    operator char_type const *() const
    {
        return parent_class_type::data();
    }
/// @}

// Not to be implemented
private:
    wide2multibyte(wide2multibyte const &);
    wide2multibyte &operator =(wide2multibyte const &);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template <ss_typename_param_k C>
class encoding2encoding
{
public:
    encoding2encoding(C const *s)
        : m_s(s)
    {}
    encoding2encoding(C *s)
        : m_s(s)
    {}
    template <ss_typename_param_k S>
    encoding2encoding(S const &s)
        : m_s(s.c_str())
    {}

public:
    C const *c_str() const
    {
        return m_s;
    }
    operator C const *() const
    {
        return m_s;
    }

private:
    C const *m_s;
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

/** \brief Type that converts a multibyte string to a wide string.
 *
 * \ingroup group__library__conversion
 */
typedef multibyte2wide<256>               a2w;
/** \brief Type that converts a wide string to a multibyte string.
 *
 * \ingroup group__library__conversion
 */
typedef wide2multibyte<256>               w2a;

#if defined(UNICODE)
typedef encoding2encoding<ws_char_w_t>  t2w;
typedef encoding2encoding<ws_char_w_t>  w2t;
typedef w2a                             t2a;
typedef a2w                             a2t;
#else /* ? UNICODE */
typedef encoding2encoding<ws_char_a_t>  t2a;
typedef encoding2encoding<ws_char_a_t>  a2t;
typedef a2w                             t2w;
typedef w2a                             w2t;
#endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** \brief \ref section__concept__shims__string_access__c_str_ptr_null for winstl::multibyte2wide
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_ptr_null(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_ptr_null_w(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief \ref section__concept__shims__string_access__c_str_ptr for winstl::multibyte2wide
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_ptr(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_ptr_w(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_data for winstl::multibyte2wide
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_data(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_w_t const *c_str_data_w(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_len for winstl::multibyte2wide
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_size_t c_str_len(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_size_t c_str_len_w(winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_len_w)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/** \brief \ref section__concept__shims__string_access__c_str_ptr_null for winstl::wide2multibyte
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_ptr_null(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_ptr_null_a(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_ptr_null)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_ptr for winstl::wide2multibyte
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_ptr(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_ptr_a(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_data for winstl::wide2multibyte
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_data(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_char_a_t const *c_str_data_a(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief \ref section__concept__shims__string_access__c_str_len for winstl::wide2multibyte
 *
 * \ingroup group__concept__shims__string_access
 */
template<   ws_size_t   CCH
        >
inline ws_size_t c_str_len(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_len)(b.c_str());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ws_size_t   CCH
        >
inline ws_size_t c_str_len_a(winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return stlsoft_ns_qual(c_str_len_a)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */




/** \brief \ref group__concept__shims__stream_insertion "stream insertion shim" for winstl::multibyte2wide
 *
 * \ingroup group__concept__shims__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ws_size_t   CCH
        >
inline S &operator <<(S & s, winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    s << b.c_str();

    return s;
}

/** \brief \ref group__concept__shims__stream_insertion "stream insertion shim" for winstl::wide2multibyte
 *
 * \ingroup group__concept__shims__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ws_size_t   CCH
        >
inline S &operator <<(S & s, winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    s << b.c_str();

    return s;
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/char_conversions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _WINSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Global namespace shims
 */

/* This defines stream inserter shim function templates for the converters
 * for use with the Visual C++ <7.1 standard library.
 */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1

# include <iosfwd>

template <size_t CCH>
inline winstl_ns_qual_std(basic_ostream)<char> &operator <<(winstl_ns_qual_std(basic_ostream)<char> &stm, winstl_ns_qual(wide2multibyte)<CCH> const &b)
{
    return stm << b.c_str();
}

template <size_t CCH>
inline winstl_ns_qual_std(basic_ostream)<wchar_t> &operator <<(winstl_ns_qual_std(basic_ostream)<wchar_t> &stm, winstl_ns_qual(multibyte2wide)<CCH> const &b)
{
    return stm << b.c_str();
}

#endif /* library */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS */

/* ////////////////////////////////////////////////////////////////////// */
