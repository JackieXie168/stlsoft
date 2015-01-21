/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/reg_key.hpp (formerly winstl_reg_key.h)
 *
 * Purpose:     Contains the basic_reg_key template class, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Created:     19th January 2002
 * Updated:     28th March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/registry/reg_key.hpp
///
/// Contains the basic_reg_key template class, and ANSI and Unicode specialisations thereof.

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_MAJOR       3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_MINOR       3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_REVISION    7
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_EDIT        98
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD
# include <winstl/registry/regfwd.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_DEFS
# include <winstl/registry/defs.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_DEFS */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS
# include <winstl/registry/reg_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_TRAITS */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_EXCEPTIONS
# include <winstl/registry/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_EXCEPTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR
# include <stlsoft/iterators/transform_iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR */
#include <numeric>

#ifdef STLSOFT_UNITTEST
# include <winstl/registry/reg_value.hpp>
#endif /* STLSOFT_UNITTEST */

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

/// \weakgroup winstl_reg_library Registry Library
/// \ingroup WinSTL libraries
/// \brief This library provides facilities for working with the Windows registry
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Represents a registry key
///
/// This class acts as the value type of classes that manipulate registry keys
/// and encapsulates the concept of a registry key.
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments this defaults to reg_traits<C>
/// \param A The allocator type. On translators that support default template arguments this defaults to processheap_allocator<C>
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = reg_traits<C>
        ,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = reg_traits<C> */
        ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_reg_key
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                                           char_type;
    /// The traits type
    typedef T                                           traits_type;
    /// The allocator type
    typedef A                                           allocator_type;
    /// The current parameterisation of the type
    typedef basic_reg_key<C, T, A>                      class_type;
    /// The size type
    typedef ss_typename_type_k traits_type::size_type   size_type;
    /// The string type
    typedef ss_typename_type_k traits_type::string_type string_type;
    /// The key type
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1100
    /* WSCB: VC5 has an internal compiler error if use traits_type::hkey_type */
    typedef HKEY                                        hkey_type;
#else /* ? compiler */
    typedef ss_typename_type_k traits_type::hkey_type   hkey_type;
#endif /* compiler */
    /// The Boolean type
    typedef ws_bool_t                                   bool_type;
    /// The type of the key's values
    typedef basic_reg_value<C, T, A>                    key_value_type;
#if 0
    /// The type of the sub-key collection
    typedef basic_reg_key_sequence<C, T, A>             subkeys_collection_type;
    /// The type of the value collection
    typedef basic_reg_value_sequence<C, T, A>           value_collection_type;
#endif /* 0 */
private:
    /// The results type of the Registry API
    typedef ss_typename_type_k traits_type::result_type result_type;
/// @}

/// \name Construction
/// @{
private:
    friend class basic_reg_value_sequence<C, T, A>;
    friend class basic_reg_key_sequence<C, T, A>;

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    (   _MSC_VER == 1200 || \
        _MSC_VER == 1300)
public:
#endif /* compiler */
    basic_reg_key(hkey_type *hkey, string_type const &key_name, REGSAM accessMask);
public:
    /// Default constructor
    basic_reg_key();
    /// Construct from the named sub-key of the given parent
    basic_reg_key(hkey_type hkeyParent, char_type const *key_name, REGSAM accessMask = KEY_ALL_ACCESS)
        : m_hkey(open_key_(hkeyParent, key_name, accessMask))
        , m_name(key_name)
        , m_accessMask(accessMask)
    {} // Implementation is within class, otherwise VC5 will not link
    /// Construct from the named sub-key of the given parent
    template <ss_typename_param_k S>
    basic_reg_key(hkey_type hkeyParent, S const &key_name, REGSAM accessMask = KEY_ALL_ACCESS)
        : m_hkey(open_key_(hkeyParent, stlsoft_ns_qual(c_str_ptr)(key_name), accessMask))
        , m_name(key_name)
        , m_accessMask(accessMask)
    {} // Implementation is within class, otherwise VC5 will not link
    /// Construct from the named sub-key of the given parent
    basic_reg_key(class_type const &keyParent, char_type const *key_name, REGSAM accessMask = KEY_ALL_ACCESS)
        : m_hkey(open_key_(keyParent.get_key_handle(), key_name, accessMask))
        , m_name(key_name)
        , m_accessMask(accessMask)
    {} // Implementation is within class, otherwise VC5 will not link
    /// Construct from the named sub-key of the given parent
    template <ss_typename_param_k S>
    basic_reg_key(class_type const &keyParent, S const &key_name, REGSAM accessMask = KEY_ALL_ACCESS)
        : m_hkey(open_key_(keyParent.get_key_handle(), stlsoft_ns_qual(c_str_ptr)(key_name), accessMask))
        , m_name(key_name)
        , m_accessMask(accessMask)
    {} // Implementation is within class, otherwise VC5 will not link

    /// Copy constructor
    basic_reg_key(class_type const &rhs);
    /// Copy constructor, with permissions
    ///
    /// \param rhs The key from which to copy
    /// \param accessMask a change of permissions
    basic_reg_key(class_type const &rhs, REGSAM accessMask);

    /// Destructor
    ~basic_reg_key() stlsoft_throw_0();

    /// Copy assignment operator
    class_type &operator =(class_type const &rhs);
/// @}

/// \name Attributes
/// @{
public:
    /// The name of the key
    string_type const       &name() const;
    /// The registry class of the key
    string_type             reg_class() const;
    /// The number of sub-keys
    ///
    /// \note This is not a constant-time operation
    size_type               num_sub_keys() const;
    /// The number of values
    ///
    /// \note This is not a constant-time operation
    size_type               num_values() const;

    /// The key handle
    hkey_type               get_key_handle() const;
    /// The key handle
    hkey_type               get() const;

#if 0
    subkeys_collection_type subkeys() const;
    value_collection_type   values() const;
#endif /* 0 */

    REGSAM                  get_access_mask() const;
/// @}

/// \name Sub-key operations
/// @{
public:
    /// Opens the named sub-key of this key
    class_type  open_sub_key(char_type const *subKeyName, REGSAM accessMask = KEY_ALL_ACCESS);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    class_type  open_sub_key(S const &subKeyName, REGSAM accessMask = KEY_ALL_ACCESS)
    {
        return open_sub_key_(stlsoft_ns_qual(c_str_ptr)(subKeyName), accessMask);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// Creates a named sub-key of this key
    class_type  create_sub_key(char_type const *subKeyName, REGSAM accessMask = KEY_ALL_ACCESS);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    class_type  create_sub_key(S const &subKeyName, REGSAM accessMask = KEY_ALL_ACCESS)
    {
        return create_sub_key_(stlsoft_ns_qual(c_str_ptr)(subKeyName), accessMask);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// Deletes the named sub-key of this key
    bool_type   delete_sub_key(char_type const *subKeyName);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    class_type  delete_sub_key(S const &subKeyName)
    {
        return delete_sub_key_(stlsoft_ns_qual(c_str_ptr)(subKeyName));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
/// @}


    /* The handle returned from this method MUST be closed with RegCloseKey() */
    hkey_type   dup_key_handle(REGSAM accessMask = KEY_ALL_ACCESS);

/// \name Value operations
/// @{
public:
    bool_type   set_value(char_type const *valueName, DWORD value);
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    bool_type   set_value(char_type const *valueName, ws_uint64_t value);
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    bool_type   set_value(char_type const *valueName, char_type const *value, ws_uint_t type = REG_SZ);
    bool_type   set_value(char_type const *valueName, char_type const **values, size_type numValues);
    bool_type   set_value(char_type const *valueName, void const *value, size_type cbValue);

    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, DWORD value)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), value);
    }
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, ws_uint64_t value)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), value);
    }
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, char_type const *value, ws_uint_t type = REG_SZ)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), value, type);
    }
    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, char_type const **values, size_type numValues)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), values, numValues);
    }
    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, void const *value, size_type cbValue)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), value, cbValue);
    }

    /// \brief Inserts the given integer (stored as an unsigned value)
    ///
    /// \note This method is provided solely to disambiguate between the DWORD and ws_uint64_t overloads
    /// when using integer literals.
    bool_type   set_value(char_type const *valueName, int value);
    template <ss_typename_param_k S>
    bool_type   set_value(S const &valueName, int value)
    {
        return set_value_(stlsoft_ns_qual(c_str_ptr)(valueName), value);
    }

    bool_type   delete_value(char_type const *valueName);
    template <ss_typename_param_k S>
    bool_type   delete_value(S const &valueName)
    {
        return this->delete_value_(stlsoft_ns_qual(c_str_ptr)(valueName));
    }


#if 0
    ws_dword_t      get_value_type(char_type const *valueName) const;
    size_type       get_value_data_size(char_type const *valueName) const;
#endif /* 0 */

    key_value_type              get_value(char_type const *valueName) const;
    template <ss_typename_param_k S>
    key_value_type              get_value(S const &valueName) const
    {
        return this->get_value(stlsoft_ns_qual(c_str_ptr)(stlsoft_ns_qual(c_str_ptr)(valueName)));
    }
//  std::list<key_value_type>   get_values(char_type const *valueNames) const;
/// @}

/// \name Implementation
/// @{
private:
    static hkey_type    open_key_(  hkey_type       hkeyParent
                                ,   char_type const *key_name
                                ,   REGSAM          accessMask);
    class_type  open_sub_key_(      char_type const *subKeyName
                                ,   REGSAM          accessMask);
    class_type  create_sub_key_(    char_type const *subKeyName
                                ,   REGSAM          accessMask);
    bool_type   delete_sub_key_(    char_type const *subKeyName);
    static result_type  set_value_( hkey_type       hkey
                                ,   char_type const *valueName
                                ,   ws_uint_t       type
                                ,   void const      *value
                                ,   size_type       cbValue);

    bool_type   set_value_int_(char_type const *valueName, int value, stlsoft_ns_qual(yes_type));
    bool_type   set_value_int_(char_type const *valueName, int value, stlsoft_ns_qual(no_type));

    bool_type   set_value_(char_type const *valueName, DWORD value);
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    bool_type   set_value_(char_type const *valueName, ws_uint64_t value);
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    bool_type   set_value_(char_type const *valueName, char_type const *value, ws_uint_t type);
    bool_type   set_value_(char_type const *valueName, char_type const **values, size_type numValues);
    bool_type   set_value_(char_type const *valueName, void const *value, size_type cbValue);
    bool_type   set_value_(char_type const *valueName, int value);

    bool_type   delete_value_(char_type const *valueName);

    static result_type  get_value_(hkey_type hkey, char_type const *valueName, ws_uint_t type, void *value, size_type *pcbValue);
/// @}

/// \name Operations
/// @{
public:
    void    swap(class_type &rhs) stlsoft_throw_0();
/// @}

/// \name Members
/// @{
private:
    hkey_type   m_hkey;         // The key handle
    string_type m_name;         // The key name
    REGSAM      m_accessMask;   // The security access mask
/// @}
};

/* Typedefs to commonly encountered types. */
/// Instantiation of the basic_reg_key template for the ANSI character type \c char
typedef basic_reg_key<ws_char_a_t, reg_traits<ws_char_a_t>, processheap_allocator<ws_char_a_t> >    reg_key_a;
/// Instantiation of the basic_reg_key template for the Unicode character type \c wchar_t
typedef basic_reg_key<ws_char_w_t, reg_traits<ws_char_w_t>, processheap_allocator<ws_char_w_t> >    reg_key_w;
/// Instantiation of the basic_reg_key template for the Win32 character type \c TCHAR
typedef basic_reg_key<TCHAR, reg_traits<TCHAR>, processheap_allocator<TCHAR> >                      reg_key;

/* ////////////////////////////////////////////////////////////////////////////
 * Handle access shims
 */

/* get_handle */

/// \brief Returns the corresponding registry handle of \c k
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline HKEY get_handle(basic_reg_key<C, T, A> const &key)
{
    return key.get_key_handle();
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/reg_key_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
#if (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1100) || \
    defined(STLSOFT_COMPILER_IS_VECTORC)
inline /* static */ ss_typename_type_k basic_reg_key<C, T, A>::hkey_type basic_reg_key<C, T, A>::open_key_(hkey_type hkeyParent, char_type const *key_name, REGSAM accessMask)
#else /* ? compiler */
inline /* static */ ss_typename_type_k basic_reg_key<C, T, A>::hkey_type basic_reg_key<C, T, A>::open_key_(ss_typename_param_k basic_reg_key<C, T, A>::hkey_type hkeyParent, ss_typename_param_k basic_reg_key<C, T, A>::char_type const *key_name, REGSAM accessMask)
#endif /* compiler */
{
    hkey_type   hkey;
    result_type res = traits_type::reg_open_key(hkeyParent, key_name, &hkey, accessMask);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not open key", static_cast<DWORD>(res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        hkey = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return hkey;
}

// Construction
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key<C, T, A>::basic_reg_key()
    : m_hkey(NULL)
    , m_accessMask(KEY_READ)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key<C, T, A>::basic_reg_key(ss_typename_type_k basic_reg_key<C, T, A>::hkey_type *hkey, ss_typename_type_k basic_reg_key<C, T, A>::string_type const &key_name, REGSAM accessMask)
    : m_hkey(*hkey)
    , m_name(key_name)
    , m_accessMask(accessMask)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key<C, T, A>::basic_reg_key(class_type const &rhs)
    : m_hkey(traits_type::key_dup(rhs.m_hkey, rhs.get_access_mask()))
    , m_name(rhs.m_name)
    , m_accessMask(rhs.m_accessMask)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key<C, T, A>::basic_reg_key(class_type const &rhs, REGSAM accessMask)
    : m_hkey(traits_type::key_dup(rhs.m_hkey, accessMask))
    , m_name(rhs.m_name)
    , m_accessMask(accessMask)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key<C, T, A>::~basic_reg_key() stlsoft_throw_0()
{
    if(m_hkey != NULL)
    {
        ::RegCloseKey(m_hkey);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline void basic_reg_key<C, T, A>::swap(ss_typename_type_k basic_reg_key<C, T, A>::class_type &rhs) stlsoft_throw_0()
{
    std_swap(m_name,        rhs.m_name);
    std_swap(m_hkey,        rhs.m_hkey);
    std_swap(m_accessMask,  rhs.m_accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::class_type &basic_reg_key<C, T, A>::operator =(ss_typename_type_k basic_reg_key<C, T, A>::class_type const &rhs)
{
    class_type  _this(rhs);

    swap(_this);

    return *this;
}

// Attributes
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::string_type const &basic_reg_key<C, T, A>::name() const
{
    return m_name;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::string_type basic_reg_key<C, T, A>::reg_class() const
{
    size_type   cch_key_class   =   0;
    ws_long_t   res             =   traits_type::reg_query_info(m_hkey, NULL, &cch_key_class, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS == res)
    {
        stlsoft_ns_qual(auto_buffer_old)<char_type, allocator_type, CCH_REG_API_AUTO_BUFFER>  p(++cch_key_class);

        res = traits_type::reg_query_info(m_hkey, &p[0], &cch_key_class, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

        if(ERROR_SUCCESS == res)
        {
            return string_type(&p[0], cch_key_class);
        }
    }

    return string_type();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::size_type basic_reg_key<C, T, A>::num_sub_keys() const
{
    size_type   c_sub_keys;
    ws_long_t   res         =   traits_type::reg_query_info(m_hkey, NULL, NULL, &c_sub_keys, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
        c_sub_keys = 0;
    }

    return c_sub_keys;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::size_type basic_reg_key<C, T, A>::num_values() const
{
    size_type   c_values;
    ws_long_t   res         =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, &c_values, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
        c_values = 0;
    }

    return c_values;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::hkey_type basic_reg_key<C, T, A>::get_key_handle() const
{
    return m_hkey;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::hkey_type basic_reg_key<C, T, A>::get() const
{
    return get_key_handle();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline REGSAM basic_reg_key<C, T, A>::get_access_mask() const
{
    return m_accessMask;
}

// Operations
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::class_type basic_reg_key<C, T, A>::open_sub_key(char_type const *subKeyName, REGSAM accessMask /* = KEY_ALL_ACCESS */)
{
    return this->open_sub_key_(subKeyName, accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::class_type basic_reg_key<C, T, A>::create_sub_key(char_type const *subKeyName, REGSAM accessMask /* = KEY_ALL_ACCESS */)
{
    return this->create_sub_key_(subKeyName, accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::class_type basic_reg_key<C, T, A>::open_sub_key_(char_type const *subKeyName, REGSAM accessMask /* = KEY_ALL_ACCESS */)
{
    return class_type(m_hkey, subKeyName, accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::class_type basic_reg_key<C, T, A>::create_sub_key_(char_type const *subKeyName, REGSAM accessMask)
{
    hkey_type   hkey;
    result_type res =   traits_type::reg_create_key(m_hkey, subKeyName, &hkey, accessMask);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not create sub-key", static_cast<DWORD>(res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        return class_type();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return class_type(&hkey, subKeyName, accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::delete_sub_key(char_type const *subKeyName)
{
    return this->delete_sub_key_(subKeyName);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::delete_sub_key_(char_type const *subKeyName)
{
    result_type r   =   traits_type::reg_delete_key(m_hkey, subKeyName);

    if( ERROR_SUCCESS != r &&
        ERROR_FILE_NOT_FOUND != r)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not delete sub-key", r);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        return false;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return ERROR_SUCCESS == r;
}


/* The handle returned from this method MUST be closed with RegCloseKey() */
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::hkey_type basic_reg_key<C, T, A>::dup_key_handle(REGSAM accessMask /* = KEY_ALL_ACCESS */)
{
    return traits_type::key_dup(m_hkey);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// Values

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, DWORD value)
{
    return set_value_(valueName, value);
}

#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, ws_uint64_t value)
{
    return set_value_(valueName, value);
}
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, int value)
{
    return set_value_(valueName, value);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, char_type const *value, ws_uint_t type /* = REG_SZ */)
{
    return set_value_(valueName, value, type);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, ss_typename_type_k basic_reg_key<C, T, A>::char_type const **values, ss_typename_type_k basic_reg_key<C, T, A>::size_type numValues)
{
    return set_value_(valueName, values, numValues);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, void const *value, size_type cbValue)
{
    return set_value_(valueName, value, cbValue);
}



template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */ ss_typename_type_k basic_reg_key<C, T, A>::result_type basic_reg_key<C, T, A>::set_value_(  ss_typename_type_k basic_reg_key<C, T, A>::hkey_type        hkey
                                                                                                            ,   ss_typename_type_k basic_reg_key<C, T, A>::char_type const  *valueName
                                                                                                            ,   ws_uint_t                                                   type
                                                                                                            ,   void const                                                  *value
                                                                                                            ,   ss_typename_type_k basic_reg_key<C, T, A>::size_type        cbValue)
{
    result_type res =   traits_type::reg_set_value(hkey, valueName, type, value, cbValue);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(ERROR_SUCCESS != res)
    {
        throw registry_exception("Could not create value", static_cast<DWORD>(res));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return res;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, DWORD value)
{
    return ERROR_SUCCESS == class_type::set_value_(m_hkey, valueName, REG_DWORD, &value, sizeof(value));
}

#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, ws_uint64_t value)
{
#ifndef REG_QWORD
    const DWORD REG_QWORD   =   11;
#endif /* !REG_QWORD */

    return ERROR_SUCCESS == class_type::set_value_(m_hkey, valueName, REG_QWORD, &value, sizeof(value));
}
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, char_type const *value, ws_uint_t type /* = REG_SZ */)
{
    WINSTL_ASSERT(REG_SZ == type || REG_EXPAND_SZ == type || REG_MULTI_SZ == type);

    return ERROR_SUCCESS == class_type::set_value_(m_hkey, valueName, type, value, traits_type::str_len(value) * sizeof(char_type));
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, ss_typename_type_k basic_reg_key<C, T, A>::char_type const **values, ss_typename_type_k basic_reg_key<C, T, A>::size_type numValues)
{
    const size_type totalLen    =   winstl_ns_qual_std(accumulate)( stlsoft_ns_qual(transformer)(values, std::ptr_fun(traits_type::str_len))
                                                                ,   stlsoft_ns_qual(transformer)(values + numValues, std::ptr_fun(traits_type::str_len))
                                                                ,   size_type(0));

    stlsoft_ns_qual(auto_buffer)<char_type> buff(totalLen + numValues * 1 + 2);

    if(buff.empty())
    {
        ::SetLastError(ERROR_NOT_ENOUGH_MEMORY);

        return false;
    }

    char_type   *p  =   &buff[0];

    for(size_type i = 0; i < numValues; ++i)
    {
        char_type const *s  =   values[i];
        const size_type len =   traits_type::str_len(s);

        traits_type::str_n_copy(p, s, len + 1);
        p += len + 1;
    }
    *p++ = '\0';
    *p++ = '\0';

    return ERROR_SUCCESS == class_type::set_value_(m_hkey, valueName, REG_MULTI_SZ, buff.data(), static_cast<size_type>(p - &buff[0]));
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, void const *value, size_type cbValue)
{
    return ERROR_SUCCESS == class_type::set_value_(m_hkey, valueName, REG_BINARY, value, cbValue);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_int_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, int value, stlsoft_ns_qual(yes_type))
{
    return this->set_value(valueName, static_cast<DWORD>(value));
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_int_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, int value, stlsoft_ns_qual(no_type))
{
    return this->set_value(valueName, static_cast<ws_uint64_t>(value));
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::set_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName, int value)
{
    // Because Borland is quite dense, we must use two typedefs here,
    // rather than just one

#if 0
    typedef ss_typename_type_k stlsoft_ns_qual(value_to_yesno_type)<sizeof(int) <= sizeof(DWORD)>::type yesno_t;
#else /* ? 0 */
    typedef stlsoft_ns_qual(value_to_yesno_type)<sizeof(int) <= sizeof(DWORD)>  value_to_yesno_t;
    typedef ss_typename_type_k value_to_yesno_t::type                           yesno_t;
#endif /* 0 */

    return ERROR_SUCCESS == set_value_int_(valueName, value, yesno_t());
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::delete_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName)
{
    return this->delete_value_(valueName);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key<C, T, A>::bool_type basic_reg_key<C, T, A>::delete_value_(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName)
{
    return ERROR_SUCCESS == traits_type::delete_value(valueName);
}


template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_value<C, T, A> basic_reg_key<C, T, A>::get_value(ss_typename_type_k basic_reg_key<C, T, A>::char_type const *valueName) const
{
    return basic_reg_value<C, T, A>(m_hkey, valueName);
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_reg_library

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

#if defined(STLSOFT_CF_std_NAMESPACE)

namespace std
{
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
    inline void swap(winstl_ns_qual(reg_key_a) &lhs, winstl_ns_qual(reg_key_a) &rhs)
    {
        lhs.swap(rhs);
    }
    inline void swap(winstl_ns_qual(reg_key_w) &lhs, winstl_ns_qual(reg_key_w) &rhs)
    {
        lhs.swap(rhs);
    }
#endif /* compiler */

} // anonymous namespace

#endif /* STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY */

/* ////////////////////////////////////////////////////////////////////////// */
