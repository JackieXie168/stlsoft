/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/reg_value.hpp
 *
 * Purpose:     Contains the basic_reg_value class template, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Notes:       The original implementation of the class had the const_iterator
 *              and value_type as nested classes. Unfortunately, Visual C++ 5 &
 *              6 both had either compilation or linking problems so these are
 *              regretably now implemented as independent classes.
 *
 * Thanks:      To Diego Chanoux for spotting a bug in the value_sz() method.
 *
 * Created:     19th January 2002
 * Updated:     6th December 2007
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


/** \file winstl/registry/reg_value.hpp
 *
 * \brief [C++ only] Definition of the winstl::basic_reg_value class
 *   template
 *   (\ref group__library__windows_registry "Windows Registry" Library).
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_VALUE_MAJOR     3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_VALUE_MINOR     1
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_VALUE_REVISION  2
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_VALUE_EDIT      93
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD
# include <winstl/registry/regfwd.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_UTIL_HPP_DEFS
# include <winstl/registry/util/defs.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_UTIL_HPP_DEFS */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS
# include <winstl/registry/reg_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS
# include <winstl/registry/error/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#include <algorithm>

#ifndef STLSOFT_UNITTEST
# include <winstl/registry/reg_key.hpp>
#endif /* !STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////// */

/** \brief Represents a binary registry value
 *
 * \ingroup group__library__windows_registry
 */
template<ss_typename_param_k A>
class reg_blob
    : protected A
    , public stlsoft_ns_qual(stl_collection_tag)
{
/// \name Member Types
/// @{
    typedef stlsoft_ns_qual(auto_buffer_old)<   ws_byte_t
                                            ,   processheap_allocator<ws_byte_t>
                                            ,   CCH_REG_API_AUTO_BUFFER
                                            >               buffer_type;
public:
    /// \brief The allocator type
    typedef A                                               allocator_type;
    /// \brief The current parameterisation of the type
    typedef reg_blob<A>                                     class_type;
    /// \brief The value type
    typedef ws_byte_t                                       value_type;
    /// \brief The non-mutable (const) reference type
    typedef value_type const                                &const_reference;
    /// \brief The non-mutable (const) pointer type
    typedef value_type const                                *const_pointer;
    /// \brief The non-mutating (const) iterator type
    typedef value_type const                                *const_iterator;
    /// \brief The size type
    typedef ws_size_t                                       size_type;
    /// \brief The difference type
    typedef ws_ptrdiff_t                                    difference_type;
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// \brief The non-mutating (const) reverse iterator type
    typedef const_reverse_iterator_base <   const_iterator
                                        ,   value_type const
                                        ,   const_reference
                                        ,   const_pointer
                                        ,   difference_type
                                        >                   const_reverse_iterator;
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Construction
/// @{
public:
    /// \brief Default constructor
    reg_blob();
    /// \brief Copies the contents of the given pointer.
    ///
    /// \param data Pointer to the bytes to be copied into the instance.
    /// \param n Number of bytes pointed to by \c data.
    reg_blob(value_type const* data, size_type n);
    /// \brief Copy constructor
    reg_blob(class_type const& rhs);
    /// \brief Destructor
    ~reg_blob() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Number of bytes in the blob.
    size_type       size() const;
    /// \brief Pointer to the first byte in the blob.
    const_pointer   data() const;
/// @}

/// \name Iteration
/// @{
public:
    /// \brief Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// \brief Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// \brief Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const;
    /// \brief Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const;
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Members
/// @{
private:
    buffer_type m_buffer;
/// @}

/// \name Not to be implemented
/// @{
private:
    reg_blob& operator =(class_type const& rhs);
/// @}
};

/** \brief Represents a registry value, providing methods for accessing the value in different types.
 *
 * \ingroup group__library__windows_registry
 *
 * This class acts as the value type of classes that manipulate registry values
 * and encapsulates the concept of a registry value.
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments this defaults to reg_traits<C>
 * \param A The allocator type. On translators that support default template arguments this defaults to processheap_allocator<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = reg_traits<C>
        ,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = reg_traits<C> */
        ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_reg_value
{
/// \name Member Types
/// @{
public:
    /// \brief The character type
    typedef C                                                           char_type;
    /// \brief The traits type
    typedef T                                                           traits_type;
    /// \brief The allocator type
    typedef A                                                           allocator_type;
    /// \brief The current parameterisation of the type
    typedef basic_reg_value<C, T, A>                                    class_type;
    /// \brief The size type
    typedef ss_typename_type_k traits_type::size_type                   size_type;
    /// \brief The string type
    typedef ss_typename_type_k traits_type::string_type                 string_type;
    /// \brief The key type
#if defined(STLSOFT_CF_THROW_BAD_ALLOC) && \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1100
    /* WSCB: VC5 has an internal compiler error if use traits_type::hkey_type */
    typedef HKEY                                                        hkey_type;
#else /* ? compiler */
    typedef ss_typename_type_k traits_type::hkey_type                   hkey_type;
#endif /* compiler */
    /// \brief The blob type
    typedef reg_blob<A>                                                 blob_type;
private:
    typedef stlsoft_ns_qual(auto_buffer_old)<   char_type
                                            ,   allocator_type
                                            ,   CCH_REG_API_AUTO_BUFFER
                                            >                           char_buffer_type_;
    typedef stlsoft_ns_qual(auto_buffer_old)<   ws_byte_t
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
                                            ,   ss_typename_type_k allocator_type::ss_template_qual_k rebind<ws_byte_t>::other
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
                                            ,   processheap_allocator<ws_byte_t>
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
                                            ,   CCH_REG_API_AUTO_BUFFER
                                            >                           byte_buffer_type_;
private:
    /// \brief The results type of the Registry API
    typedef ss_typename_type_k traits_type::result_type                 result_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Default constructor
    basic_reg_value();
    /// \brief Copy constructor
    basic_reg_value(class_type const& rhs);
protected:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    friend class basic_reg_value_sequence_iterator<C, T, class_type, A>;
    friend class basic_reg_key<C, T, A>;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// \brief Internal constructor, used by basic_reg_key and basic_reg_value_sequence.
    basic_reg_value(hkey_type hkeyParent, string_type const& value_name)
        : m_hkey(dup_key_(hkeyParent, KEY_READ))
        , m_name(value_name)
        , m_type(REG_NONE)
        , m_bTypeRetrieved(ws_false_v)
    {} // Implementation provided here, as otherwise VC5 will not link
public:
    /// \brief Destructor
    ~basic_reg_value() stlsoft_throw_0();

    /// \brief Copy assignment operator
    class_type& operator =(class_type const& rhs);
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns the type of the value
    ///
    /// \retval REG_NONE No value type
    /// \retval REG_SZ A Unicode nul terminated string
    /// \retval REG_EXPAND_SZ A Unicode nul terminated string (with environment variable references)
    /// \retval REG_BINARY A free form binary
    /// \retval REG_DWORD A 32-bit number
    /// \retval REG_DWORD_LITTLE_ENDIAN A little-endian 32-bit number (same as REG_DWORD)
    /// \retval REG_DWORD_BIG_ENDIAN A big-endian 32-bit number
    /// \retval REG_LINK A symbolic Link (unicode)
    /// \retval REG_MULTI_SZ Multiple Unicode strings
    /// \retval REG_RESOURCE_LIST A resource list in the resource map
    /// \retval REG_FULL_RESOURCE_DESCRIPTOR A resource list in the hardware description
    /// \retval REG_RESOURCE_REQUIREMENTS_LIST
    /// \retval REG_QWORD A 64-bit number
    /// \retval REG_QWORD_LITTLE_ENDIAN A 64-bit number (same as REG_QWORD)
    ws_dword_t  type() const;

    /// \brief The name of the value
    string_type name() const;

    /// \brief The registry value in \c REG_SZ form
    ///
    /// This method does <i>not</i> expand environment strings
    string_type value_sz() const;
    /// \brief The registry value in \c REG_EXPAND_SZ form
    ///
    /// This method <i>does</i> expand environment strings
    string_type value_expand_sz() const;
    /// \brief The registry value as a 32-bit integer
    ws_dword_t  value_dword() const;
    /// \brief The registry value as a translated (from little-endian) 32-bit integer
    ws_dword_t  value_dword_littleendian() const;
    /// \brief The registry value as a translated (from big-endian) 32-bit integer
    ws_dword_t  value_dword_bigendian() const;
    /// \brief The registry value as a binary value
    blob_type   value_binary() const;
/// @}

/// \name Implementation
/// @{
private:
    ws_dword_t          get_type_() const;
    static hkey_type    dup_key_(hkey_type hkey, REGSAM accessMask/* , result_type *res */);
/// @}

/// \name Members
/// @{
private:
    hkey_type               m_hkey;             // The parent key of the value
    string_type             m_name;             // The name of the value
    ss_mutable_k ws_dword_t m_type;             // The type of the value
    ss_mutable_k ws_bool_t  m_bTypeRetrieved;   // Facilitates lazy evaluation of the type
/// @}
};

/* Typedefs to commonly encountered types. */
/** \brief Specialisation of the basic_reg_value template for the ANSI character type \c char
 *
 * \ingroup group__library__windows_registry
 */
typedef basic_reg_value<ws_char_a_t, reg_traits<ws_char_a_t>, processheap_allocator<ws_char_a_t> >  reg_value_a;
/** \brief Specialisation of the basic_reg_value template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__windows_registry
 */
typedef basic_reg_value<ws_char_w_t, reg_traits<ws_char_w_t>, processheap_allocator<ws_char_w_t> >  reg_value_w;
/** \brief Specialisation of the basic_reg_value template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__windows_registry
 */
typedef basic_reg_value<TCHAR, reg_traits<TCHAR>, processheap_allocator<TCHAR> >                    reg_value;

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/reg_value_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_value<C, T, A>::basic_reg_value()
    : m_hkey(NULL)
    , m_type(REG_NONE)
    , m_bTypeRetrieved(ws_false_v)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_value<C, T, A>::basic_reg_value(class_type const& rhs)
    : m_hkey(dup_key_(rhs.m_hkey, KEY_READ))
    , m_name(rhs.m_name)
    , m_type(rhs.m_type)
    , m_bTypeRetrieved(rhs.m_bTypeRetrieved)
{}

#if 0
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_value<C, T, A>::basic_reg_value(basic_reg_value<C, T, A>::hkey_type hkeyParent, basic_reg_value<C, T, A>::string_type const& value_name)
    : m_hkey(dup_key_(hkeyParent))
    , m_name(value_name)
    , m_type(REG_NONE)
    , m_bTypeRetrieved(ws_false_v)
{}
#endif /* 0 */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_value<C, T, A>::~basic_reg_value() stlsoft_throw_0()
{
    if(m_hkey != NULL)
    {
        ::RegCloseKey(m_hkey);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_ret_k basic_reg_value<C, T, A>::class_type& basic_reg_value<C, T, A>::operator =(class_type const& rhs)
{
    m_name              =   rhs.m_name;
    m_type              =   rhs.m_type;
    m_bTypeRetrieved    =   rhs.m_bTypeRetrieved;

    hkey_type   hkey    =   m_hkey;
    m_hkey              =   dup_key_(rhs.m_hkey, KEY_READ);
    if(hkey != NULL)
    {
        ::RegCloseKey(hkey);
    }

    return *this;
}

// Implementation
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_dword_t basic_reg_value<C, T, A>::get_type_() const
{
    if(!m_bTypeRetrieved)
    {
        size_type   data_size;

#ifndef STLSOFT_CF_MUTABLE_KEYWORD_SUPPORT
        /* A little-known trick, but a useful one for dealing with translators
         * lacking mutable support whilst disturbing code to the minimum degree.
         */
        ws_dword_t  &m_type             =   const_cast<ws_dword_t &>(this->m_type);
        ws_bool_t   &m_bTypeRetrieved   =   const_cast<ws_bool_t &>(this->m_bTypeRetrieved);
#endif /* STLSOFT_CF_MUTABLE_KEYWORD_SUPPORT */

        if(0 == traits_type::reg_query_value(m_hkey, m_name.c_str(), m_type, NULL, data_size))
        {
            m_bTypeRetrieved = ws_true_v;
        }
    }

    return m_type;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */ ss_typename_type_ret_k basic_reg_value<C, T, A>::hkey_type basic_reg_value<C, T, A>::dup_key_(ss_typename_type_k basic_reg_value<C, T, A>::hkey_type hkey, REGSAM accessMask/* , ss_typename_type_k basic_reg_value<C, T, A>::result_type *res */)
{
    if(NULL == hkey)
    {
        return NULL;
    }
    else
    {
        result_type res;
        HKEY        hkeyDup =   traits_type::key_dup(hkey, accessMask, &res);

        if(ERROR_SUCCESS != res)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(registry_exception("Could not duplicate key", res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            ::SetLastError(res);
            hkeyDup = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return hkeyDup;
    }
}


// Attributes
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_dword_t basic_reg_value<C, T, A>::type() const
{
    return get_type_();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_ret_k basic_reg_value<C, T, A>::string_type basic_reg_value<C, T, A>::name() const
{
    return m_name;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_ret_k basic_reg_value<C, T, A>::string_type basic_reg_value<C, T, A>::value_sz() const
{
    // Does not expand environment strings
    string_type ret;
    size_type   data_size;
    ws_long_t   res =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &data_size, NULL, NULL);

    if( ERROR_SUCCESS == res &&
        data_size > 0)
    {
        char_buffer_type_   buffer(1 + data_size);
        ws_dword_t          dw;

        data_size = buffer.size();
        res = traits_type::reg_query_value(m_hkey, m_name.c_str(), dw, &buffer[0], data_size);

        if(ERROR_SUCCESS == res)
        {
            buffer[data_size / sizeof(char_type)] = 0; // The site of a former bug. Thanks to Diego Chanoux for spotting this

            ret = buffer.data();
        }
    }

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_ret_k basic_reg_value<C, T, A>::string_type basic_reg_value<C, T, A>::value_expand_sz() const
{
    // Does expand environment strings
    string_type  ret = value_sz();

    if( ret.length() > 0 &&
        REG_EXPAND_SZ == get_type_())
    {
        size_type           size    =   traits_type::expand_env_strings(ret.c_str(), NULL, 0);
        char_buffer_type_   buffer(1 + size);

        if(traits_type::expand_env_strings(ret.c_str(), &buffer[0], size) != 0)
        {
            ret = &buffer[0];
        }
    }

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_dword_t basic_reg_value<C, T, A>::value_dword() const
{
    ws_dword_t  dwValue;
    size_type   cbData  =   sizeof(dwValue);
    ws_dword_t  value_type;
    ws_long_t   res     =   traits_type::reg_query_value(m_hkey, m_name.c_str(), value_type, &dwValue, cbData);

    if(ERROR_SUCCESS != res)
    {
        dwValue = 0;
    }

    return dwValue;
}

#if 0
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_dword_t basic_reg_value<C, T, A>::value_dword_littleendian() const
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_dword_t basic_reg_value<C, T, A>::value_dword_bigendian() const
{}
#endif /* 0 */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_ret_k basic_reg_value<C, T, A>::blob_type basic_reg_value<C, T, A>::value_binary() const
{
    size_type   data_size;
    ws_dword_t  dw;
    ws_long_t   res =   traits_type::reg_query_value(m_hkey, m_name.c_str(), dw, NULL, data_size);

    if(ERROR_SUCCESS == res)
    {
        WINSTL_MESSAGE_ASSERT("queried registry value is not binary", dw == REG_BINARY);

        if(data_size > 0)
        {
            byte_buffer_type_   buffer(data_size);

            data_size = buffer.size();
            res = traits_type::reg_query_value(m_hkey, m_name.c_str(), dw, buffer.data(), data_size);

            if(ERROR_SUCCESS == res)
            {
                return blob_type(buffer.data(), buffer.size());
            }
        }
    }

    return blob_type();
}

// reg_blob

template<ss_typename_param_k A>
inline reg_blob<A>::reg_blob()
    : m_buffer(0)
{}

template<ss_typename_param_k A>
inline reg_blob<A>::reg_blob(ss_typename_type_k reg_blob<A>::value_type const* data, ss_typename_type_k reg_blob<A>::size_type n)
    : m_buffer(n)
{
    winstl_ns_qual_std(copy)(data, data + m_buffer.size(), m_buffer.begin());
}

template<ss_typename_param_k A>
inline reg_blob<A>::reg_blob(ss_typename_type_k reg_blob<A>::class_type const& rhs)
    : m_buffer(rhs.size())
{
    winstl_ns_qual_std(copy)(rhs.data(), rhs.data() + m_buffer.size(), m_buffer.begin());
}

template<ss_typename_param_k A>
inline reg_blob<A>::~reg_blob() stlsoft_throw_0()
{}

template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::size_type reg_blob<A>::size() const
{
    return m_buffer.size();
}

template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::const_pointer reg_blob<A>::data() const
{
    return m_buffer.data();
}

template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::const_iterator reg_blob<A>::begin() const
{
    return m_buffer.begin();
}

template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::const_iterator reg_blob<A>::end() const
{
    return m_buffer.end();
}

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::const_reverse_iterator reg_blob<A>::rbegin() const
{
    return const_reverse_iterator(end());
}

template<ss_typename_param_k A>
inline ss_typename_type_ret_k reg_blob<A>::const_reverse_iterator reg_blob<A>::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */


#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE */

/* ////////////////////////////////////////////////////////////////////// */
