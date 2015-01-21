/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/reg_key_sequence.hpp (formerly winstl_reg_key_sequence.h)
 *
 * Purpose:     Contains the basic_reg_key_sequence class template, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Notes:       The original implementation of the class had the iterator
 *              and value_type as nested classes. Unfortunately, Visual C++ 5 &
 *              6 both had either compilation or linking problems so these are
 *              regretably now implemented as independent classes.
 *
 * Thanks:      To Allan McLellan, for pointing out some inadequacies in the
 *              basic_reg_key_sequence class interface.
 *
 * Created:     19th January 2002
 * Updated:     31st May 2006
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


/// \file winstl/registry/reg_key_sequence.hpp
/// \brief [C++ only] Definition of the \link winstl::basic_reg_key_sequence basic_reg_key_sequence\endlink class template. (\ref group__library__windows_registry "Windows Registry" Library.)

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE_MAJOR      3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE_MINOR      6
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE_REVISION   2
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE_EDIT       108
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
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY
# include <winstl/registry/reg_key.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_SHARED_HANDLES
# include <winstl/registry/shared_handles.hpp>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_SHARED_HANDLES */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_REF_PTR
# include <stlsoft/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_REF_PTR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE
# include <stlsoft/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */

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

// class basic_reg_key_sequence
/// \brief Presents an STL-like sequence interface over the sub-keys of a given registry key
///
/// \ingroup group__library__windows_registry
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
class basic_reg_key_sequence
    : public stlsoft_ns_qual(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// \brief The character type
    typedef C                                                                   char_type;
    /// \brief The traits type
    typedef T                                                                   traits_type;
    /// \brief The allocator type
    typedef A                                                                   allocator_type;
    /// \brief The current parameterisation of the type
    typedef basic_reg_key_sequence<C, T, A>                                     class_type;
    /// \brief The key type
    typedef basic_reg_key<C, T, A>                                              key_type;
    /// \brief The value type
    typedef key_type                                                            value_type;
    /// \brief The size type
    typedef ss_typename_type_k traits_type::size_type                           size_type;
    /// \brief The reg key type
    typedef basic_reg_key<C, T, A>                                              reg_key_type;
    /// \brief The mutating (non-const) iterator type
    typedef basic_reg_key_sequence_iterator<C, T, value_type, A>                iterator;
    /// \brief The non-mutating (const) iterator type
    ///
    /// \note This is retained for backwards compatibility
    typedef iterator                                                            const_iterator;
    /// \brief The reference type
    typedef key_type                                                            &reference;
    /// \brief The non-mutable (const) reference type
    typedef key_type const                                                      &const_reference;
    /// \brief The hkey type
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1100
    /* WSCB: VC5 has an unresolved external linker error if use traits_type::hkey_type */
    typedef HKEY                                                                hkey_type;
#else /* ? compiler */
    typedef ss_typename_type_k traits_type::hkey_type                           hkey_type;
#endif /* compiler */
    /// \brief The difference type
    typedef ws_ptrdiff_t                                                        difference_type;
    /// \brief The non-mutating (const) reverse iterator type
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef stlsoft_ns_qual(reverse_bidirectional_iterator_base)  <   iterator
                                                                  ,   value_type
                                                                  ,   value_type  // By-Value Temporary reference category
                                                                  ,   void        // By-Value Temporary reference category
                                                                  ,   difference_type
                                                                  >             reverse_iterator;
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    /// \brief The Boolean type
    typedef ws_bool_t                                                           bool_type;
private:
    /// \brief The results type of the Registry API
    typedef ss_typename_type_k traits_type::result_type                         result_type;
private:
    typedef stlsoft_ns_qual(auto_buffer_old)<   char_type
                                            ,   allocator_type
                                            ,   CCH_REG_API_AUTO_BUFFER
                                            >                                   buffer_type_;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Creates an instance which provides access to the sub-keys of the named sub-key of \c hkey
    ///
    /// \param hkey A registry key handle representing the parent of \c sub_key_name
    /// \param sub_key_name The name of the sub-key whose sub-keys will be enumerated. If sub_key_name is NULL or the empty string, then
    /// the sub-keys of \c hkey will be enumerated
    /// \param accessMask The security access mask with which the key (hkey + sub_key_name) will be opened. Defaults to KEY_READ.
    ///
    /// \note If accessMask contains KEY_NOTIFY, this method will construct a sequence whose iterators monitor for external iterator
    /// interruption. Use the alternative (four-parameter) constructor form to explicitly suppress monitoring.
    basic_reg_key_sequence( hkey_type           hkey
                        ,   char_type const     *sub_key_name
                        ,   REGSAM              accessMask                      =   KEY_READ);
    /// \brief Creates an instance which provides access to the sub-keys of the named sub-key of \c hkey
    ///
    /// \param hkey A registry key handle representing the parent of \c sub_key_name
    /// \param sub_key_name The name of the sub-key whose sub-keys will be enumerated. If sub_key_name is NULL or the empty string, then
    /// the sub-keys of \c hkey will be enumerated
    /// \param accessMask The security access mask with which the key (hkey + sub_key_name) will be opened. Defaults to KEY_READ
    /// \param bMonitorExternalInterruption If non-zero, the iterators will monitor for external iterator interruption, throwing
    /// an instance of registry_exception (or a derived class) when any sub-keys are added or removed
    ///
    /// \note The bMonitorExternalInterruption parameter overrides the accessMask parameter. i.e. if bMonitorExternalInterruption is
    /// non-zero then accessMask is combined with KEY_NOTIFY. If not, then KEY_NOTIFY is stripped from accessMask.
    basic_reg_key_sequence( hkey_type           hkey
                        ,   char_type const     *sub_key_name
                        ,   REGSAM              accessMask
                        ,   bool_type           bMonitorExternalInterruption);
    /// \brief Creates an instance which provides access to the sub-keys of of \c key
    ///
    /// \param key A registry key handle representing the parent of \c sub_key_name
    ///
    /// \note If the key's access mask contains KEY_NOTIFY, this method will construct a sequence whose iterators monitor for external iterator
    /// interruption. Use the alternative (three-parameter) constructor form to explicitly suppress monitoring.
    ss_explicit_k basic_reg_key_sequence(reg_key_type const &key);
    /// \brief Creates an instance which provides access to the sub-keys of of \c key
    ///
    /// \param key A registry key handle representing the parent of \c sub_key_name
    /// \param accessMask The security access mask with which the key will be used. Defaults to KEY_READ
    ///
    /// \note If accessMask contains KEY_NOTIFY, this method will construct a sequence whose iterators monitor for external iterator
    /// interruption. Use the alternative (three-parameter) constructor form to explicitly suppress monitoring.
    basic_reg_key_sequence( reg_key_type const  &key
                        ,   REGSAM              accessMask);
    /// \brief Creates an instance which provides access to the sub-keys of of \c key
    ///
    /// \param key A registry key handle representing the parent of \c sub_key_name
    /// \param accessMask The security access mask with which the key will be used. Defaults to KEY_READ
    /// \param bMonitorExternalInterruption If non-zero, the iterators will monitor for external iterator interruption, throwing
    /// an instance of registry_exception (or a derived class) when any sub-keys are added or removed
    ///
    /// \note The bMonitorExternalInterruption parameter overrides the accessMask parameter. i.e. if bMonitorExternalInterruption is
    /// non-zero then accessMask is combined with KEY_NOTIFY. If not, then KEY_NOTIFY is stripped from accessMask.
    basic_reg_key_sequence( reg_key_type const  &key
                        ,   REGSAM              accessMask
                        ,   bool_type           bMonitorExternalInterruption);
    /// \brief Destructor
    ~basic_reg_key_sequence() stlsoft_throw_0();
/// @}

/// \name Iteration
/// @{
public:
    /// \brief Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    iterator          begin();
    /// \brief Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    iterator          end();

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// \brief Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    reverse_iterator  rbegin();
    /// \brief Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    reverse_iterator  rend();
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns the number of sub-keys
    ///
    /// \note This gives a result valid only at the epoch of the call. A
    /// subsequent call may return a different result.
    size_type               current_size() const;
    /// \brief Returns the number of sub-keys
    ///
    /// \deprecated This is equivalent to current_size()
    size_type               size() const;
    /// \brief Evalulates whether there are no sub-keys
    ws_bool_t               empty() const;

    /// \brief The key handle
    hkey_type               get_key_handle() const;
    /// \brief The key handle
    hkey_type               get() const;
/// @}

/// \name Implementation
/// @{
private:
    registry_util::shared_handle    *create_shared_handle_(result_type &res);
    static REGSAM                   validate_access_mask_(REGSAM accessMask, bool_type bMonitorExternalInterruption);
    static hkey_type                dup_key_(hkey_type hkey, REGSAM accessMask/* , result_type *result */);
/// @}

/// \name Members
/// @{
private:
    hkey_type       m_hkey;
    const REGSAM    m_accessMask;
    const bool_type m_bMonitorExternalInterruption;
/// @}

/// \name Not to be implemented
/// @{
private:
    basic_reg_key_sequence(class_type const &);
    class_type &operator =(class_type const &);
/// @}
};

/* Typedefs to commonly encountered types. */
/// Instantiation of the basic_reg_key_sequence template for the ANSI character type \c char
typedef basic_reg_key_sequence<ws_char_a_t, reg_traits<ws_char_a_t>, processheap_allocator<ws_char_a_t> > reg_key_sequence_a;
/// Instantiation of the basic_reg_key_sequence template for the Unicode character type \c wchar_t
typedef basic_reg_key_sequence<ws_char_w_t, reg_traits<ws_char_w_t>, processheap_allocator<ws_char_w_t> > reg_key_sequence_w;
/// Instantiation of the basic_reg_key_sequence template for the Win32 character type \c TCHAR
typedef basic_reg_key_sequence<TCHAR, reg_traits<TCHAR>, processheap_allocator<TCHAR> >                   reg_key_sequence;

// class basic_reg_key_sequence_iterator
/// \brief Iterator for the basic_reg_key_sequence class
///
/// \ingroup group__library__windows_registry
///
/// \param C The character type
/// \param T The traits type
/// \param V The value type
/// \param A The allocator type
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
class basic_reg_key_sequence_iterator
    : public stlsoft_ns_qual(iterator_base)<winstl_ns_qual_std(bidirectional_iterator_tag)
                                        ,   V
                                        ,   ws_ptrdiff_t
                                        ,   void    // By-Value Temporary reference
                                        ,   V       // By-Value Temporary reference
                                        >
{
/// \name Member Types
/// @{
public:
    /// \brief The character type
    typedef C                                                           char_type;
    /// \brief The traits type
    typedef T                                                           traits_type;
    /// \brief The value type
    typedef V                                                           value_type;
    /// \brief The allocator type
    typedef A                                                           allocator_type;
    /// \brief The current parameterisation of the type
    typedef basic_reg_key_sequence_iterator<C, T, V, A>                 class_type;
    /// \brief The size type
    typedef ss_typename_type_k traits_type::size_type                   size_type;
    /// \brief The difference type
    typedef ss_typename_type_k traits_type::difference_type             difference_type;
    /// \brief The string type
    typedef ss_typename_type_k traits_type::string_type                 string_type;
    /// \brief The index type
    typedef ws_sint32_t                                                 index_type;
    /// \brief The hkey type
    typedef ss_typename_type_k traits_type::hkey_type                   hkey_type;
private:
    /// \brief The results type of the Registry API
    typedef ss_typename_type_k traits_type::result_type                 result_type;
    /// \brief The Boolean type
    typedef ws_bool_t                                                   bool_type;
private:
    typedef stlsoft_ns_qual(auto_buffer_old)<   char_type
                                            ,   allocator_type
                                            ,   CCH_REG_API_AUTO_BUFFER
                                            >                           buffer_type_;
/// @}

/// \name Construction
/// @{
private:
    friend class basic_reg_key_sequence<C, T, A>;

    /// \note Eats the key, rather than taking a copy
    basic_reg_key_sequence_iterator(registry_util::shared_handle *handle, char_type const *name, size_type cchName, index_type index, REGSAM accessMask)
        : m_handle(handle)
        , m_index(index)
        , m_name(name, cchName)
        , m_accessMask(accessMask)
    {
        WINSTL_ASSERT(NULL != m_handle);
        m_handle->test_reset_and_throw();
        m_handle->AddRef();
    }
public:
    /// \brief Default constructor
    basic_reg_key_sequence_iterator();
    /// \brief Copy constructor
    basic_reg_key_sequence_iterator(class_type const &rhs);
    /// \brief Destructor
    ~basic_reg_key_sequence_iterator() stlsoft_throw_0();

    /// \brief Copy assignment operator
    class_type &operator =(class_type const &rhs);
/// @}

/// \name Accessors
/// @{
public:
    const string_type   &get_key_name() const;
/// @}

/// \name Operators
/// @{
public:
    /// \brief Pre-increment operator
    class_type &operator ++();
    /// \brief Pre-decrement operator
    class_type &operator --();
    /// \brief Post-increment operator
    const class_type operator ++(int);
    /// \brief Post-decrement operator
    const class_type operator --(int);
    /// \brief Dereference to return the value representing the current position
    const value_type operator *() const;
    /// \brief Evaluates whether \c this and \c rhs are equivalent
    ws_bool_t equal(class_type const &rhs) const;
    /// \brief Evaluates whether \c this and \c rhs are equivalent
    ws_bool_t operator ==(class_type const &rhs) const;
    /// \brief Evaluates whether \c this and \c rhs are not equivalent
    ws_bool_t operator !=(class_type const &rhs) const;
/// @}

/// \name Implementation
/// @{
private:
    static index_type sentinel_() stlsoft_throw_0();
/// @}

/// \name Members
/// @{
private:
    registry_util::shared_handle    *m_handle;      // Shared context for registry key and event object
    index_type                      m_index;        // Current iteration index
    string_type                     m_name;         // The value name
    REGSAM                          m_accessMask;   // Security access mask
/// @}
};

///////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/reg_key_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// basic_reg_key_sequence

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline registry_util::shared_handle *basic_reg_key_sequence<C, T, A>::create_shared_handle_(result_type &res)
{
    // 1. Duplicate the registry handle
    //
    // 2. create the shared_handle

    hkey_type   hkey2   =   traits_type::key_dup(m_hkey, m_accessMask, &res);

    if(NULL == hkey2)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Failed to take duplicate of key", static_cast<DWORD>(res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    ; // This will fall through to the end() call at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        // Pop it in a scoped handle for RAII
        scoped_handle<HKEY>             sh(hkey2, ::RegCloseKey);
        registry_util::shared_handle    *handle =   registry_util::create_shared_handle(hkey2, m_bMonitorExternalInterruption, REG_NOTIFY_CHANGE_NAME);

        if(NULL == handle)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw registry_exception("Failed to create shared enumeration context", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            ; // This will fall through to the end() call at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            sh.detach();

            return handle;
        }
    }

#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    defined(STLSOFT_CF_REQUIRE_RETURN_ALWAYS)
    return NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT || STLSOFT_CF_REQUIRE_RETURN_ALWAYS */
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */ REGSAM basic_reg_key_sequence<C, T, A>::validate_access_mask_(REGSAM accessMask, ss_typename_type_k basic_reg_key_sequence<C, T, A>::bool_type bMonitorExternalInterruption)
{
    if(bMonitorExternalInterruption)
    {
        return accessMask | KEY_NOTIFY;
    }
    else
    {
        return accessMask & ~(KEY_NOTIFY);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */ ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type basic_reg_key_sequence<C, T, A>::dup_key_(ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type hkey, REGSAM accessMask/* , ss_typename_type_k basic_reg_key_sequence<C, T, A>::result_type *result */)
{
    result_type result;
    HKEY        hkeyDup =   traits_type::key_dup(hkey, accessMask, &result);

    if(ERROR_SUCCESS != result)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not duplicate key", result);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        hkeyDup = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return hkeyDup;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::basic_reg_key_sequence( ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type       hkey
                                                            ,   ss_typename_type_k basic_reg_key_sequence<C, T, A>::char_type const *sub_key_name
                                                            ,   REGSAM                                                              accessMask /* = KEY_READ */)
    : m_hkey(NULL)
    , m_accessMask(accessMask)
    , m_bMonitorExternalInterruption(0 != (KEY_NOTIFY & accessMask))
{
    result_type result;

    if(ERROR_SUCCESS != (result = traits_type::reg_open_key(hkey, sub_key_name, &m_hkey, accessMask)))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not open key", result);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_hkey = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::basic_reg_key_sequence( ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type       hkey
                                                            ,   ss_typename_type_k basic_reg_key_sequence<C, T, A>::char_type const *sub_key_name
                                                            ,   REGSAM                                                              accessMask
                                                            ,   ss_typename_type_k basic_reg_key_sequence<C, T, A>::bool_type       bMonitorExternalInterruption)
    : m_hkey(NULL)
    , m_accessMask(validate_access_mask_(accessMask, bMonitorExternalInterruption))
    , m_bMonitorExternalInterruption(bMonitorExternalInterruption)
{
    result_type result;

    if(ERROR_SUCCESS != (result = traits_type::reg_open_key(hkey, sub_key_name, &m_hkey, accessMask)))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Could not open key", result);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_hkey = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::basic_reg_key_sequence(ss_typename_type_k basic_reg_key_sequence<C, T, A>::reg_key_type const &key)
    : m_hkey(dup_key_(key.m_hkey, key.get_access_mask()))
    , m_accessMask(key.get_access_mask())
    , m_bMonitorExternalInterruption(0 != (KEY_NOTIFY & key.get_access_mask()))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hkey)
    {
        throw registry_exception("Failed to take duplicate of key", ::GetLastError());
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::basic_reg_key_sequence( ss_typename_type_k basic_reg_key_sequence<C, T, A>::reg_key_type const  &key
                                                            ,   REGSAM                                                                  accessMask)
    : m_hkey(dup_key_(key.m_hkey, accessMask))
    , m_accessMask(accessMask)
    , m_bMonitorExternalInterruption(0 != (KEY_NOTIFY & accessMask))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hkey)
    {
        throw registry_exception("Failed to take duplicate of key", ::GetLastError());
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::basic_reg_key_sequence( ss_typename_type_k basic_reg_key_sequence<C, T, A>::reg_key_type const  &key
                                                            ,   REGSAM                                                                  accessMask
                                                            ,   bool_type                                                               bMonitorExternalInterruption)
    : m_hkey(dup_key_(key.m_hkey, validate_access_mask_(accessMask, bMonitorExternalInterruption)))
    , m_accessMask(validate_access_mask_(accessMask, bMonitorExternalInterruption))
    , m_bMonitorExternalInterruption(bMonitorExternalInterruption)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hkey)
    {
        throw registry_exception("Failed to take duplicate of key", ::GetLastError());
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline basic_reg_key_sequence<C, T, A>::~basic_reg_key_sequence() stlsoft_throw_0()
{
    if(m_hkey != NULL)
    {
        ::RegCloseKey(m_hkey);
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::iterator basic_reg_key_sequence<C, T, A>::begin()
{
    // 1. Check that there are some items
    //
    // 2. Duplicate the registry key handle & Create the shared handle
    //
    // 4. Loop to get the full name
    //
    // 5. Create the iterator and return


    // 1. Check that there are some items

    // Grab enough for the first item
    size_type   cchName     =   0;
    size_type   numEntries  =   0;
    result_type res         =   traits_type::reg_query_info(m_hkey, NULL, NULL, &numEntries, &cchName, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(ERROR_ACCESS_DENIED == res)
        {
            throw access_denied_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
        else
        {
            throw registry_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        ; // This will fall through to the end() call at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        if(0 != numEntries)
        {
            // 2. Duplicate the registry key handle & create the shared handle
            registry_util::shared_handle    *handle =   create_shared_handle_(res);
            ws_sint32_t                     index   =   0;

            if(NULL == handle)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                throw registry_exception("Failed to create shared enumeration context", static_cast<DWORD>(res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                ; // This will fall through to the end() call at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                ref_ptr<registry_util::shared_handle>   ref(handle, false); // Eat the reference here. The iterator will take another

                // 4. Loop to get the full name
                buffer_type_    buffer(++cchName);   // This is increased so that the call to reg_enum_key is likely to succeed

                for(; !buffer.empty(); )    // Need to loop because sub-keys can change, when we're not monitoring
                {
                    cchName  =   buffer.size();

                    res = traits_type::reg_enum_key(m_hkey, 0, &buffer[0], &cchName);

                    if(ERROR_MORE_DATA == res)
                    {
                        if(!buffer.resize(2 * buffer.size())) // Throws, or returns false
                        {
                            cchName =   0;
                            index   =   const_iterator::sentinel_();
                            break;
                        }

                        continue; // "Let's go round again"
                    }
                    else if(ERROR_SUCCESS != res)
                    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                        if(ERROR_ACCESS_DENIED == res)
                        {
                            throw access_denied_exception("Could not enumerate sub-keys", static_cast<DWORD>(res));
                        }
                        else
                        {
                            throw registry_exception("Could not enumerate sub-keys", static_cast<DWORD>(res));
                        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                        cchName = 0;
                        index   =   const_iterator::sentinel_();
                        break; // This will fall through to the end() call at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                    }
                    else
                    {
                        break;
                    }
                }

                // 5. Create the iterator and return
                return iterator(handle, buffer.data(), cchName, index, m_accessMask);
            }
        }
    }

    return end();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::iterator basic_reg_key_sequence<C, T, A>::end()
{
    result_type                             res;
    registry_util::shared_handle            *handle =   create_shared_handle_(res);
    ref_ptr<registry_util::shared_handle>   ref(handle, false); // Eat the reference here. The iterator will take another
    ws_sint32_t                             index   =   const_iterator::sentinel_();

    if(NULL == handle)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw registry_exception("Failed to take duplicate of key", static_cast<DWORD>(res));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        index = 0; // This will fall through to the constructor at the end of the function
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return iterator(handle, NULL, 0, index, m_accessMask);
}

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::reverse_iterator basic_reg_key_sequence<C, T, A>::rbegin()
{
    return reverse_iterator(end());
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::reverse_iterator basic_reg_key_sequence<C, T, A>::rend()
{
    return reverse_iterator(begin());
}
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::size_type basic_reg_key_sequence<C, T, A>::size() const
{
    return current_size();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::size_type basic_reg_key_sequence<C, T, A>::current_size() const
{
    ws_uint_t   numEntries;
    result_type res = traits_type::reg_query_info(m_hkey, NULL, NULL, &numEntries, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(ERROR_ACCESS_DENIED == res)
        {
            throw access_denied_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
        else
        {
            throw registry_exception("Could not elicit number of sub-keys", static_cast<DWORD>(res));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        numEntries = 0;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return static_cast<size_type>(numEntries);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ws_bool_t basic_reg_key_sequence<C, T, A>::empty() const
{
    return 0 == size();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type basic_reg_key_sequence<C, T, A>::get_key_handle() const
{
    return m_hkey;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence<C, T, A>::hkey_type basic_reg_key_sequence<C, T, A>::get() const
{
    return get_key_handle();
}


// basic_reg_key_sequence_iterator

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline /* static */ ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::index_type basic_reg_key_sequence_iterator<C, T, V, A>::sentinel_() stlsoft_throw_0()
{
    return 0x7fffffff;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline basic_reg_key_sequence_iterator<C, T, V, A>::basic_reg_key_sequence_iterator()
    : m_handle(NULL)
    , m_index(sentinel_())
    , m_name()
    , m_accessMask(KEY_READ)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline basic_reg_key_sequence_iterator<C, T, V, A>::basic_reg_key_sequence_iterator(class_type const &rhs)
    : m_handle(rhs.m_handle)
    , m_index(rhs.m_index)
    , m_name(rhs.m_name)
    , m_accessMask(rhs.m_accessMask)
{
    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type &basic_reg_key_sequence_iterator<C, T, V, A>::operator =(ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type const &rhs)
{
    registry_util::shared_handle   *this_handle;

    m_index         =   rhs.m_index;
    m_name          =   rhs.m_name;

    this_handle     =   m_handle;
    m_handle        =   rhs.m_handle;
    m_accessMask    =   rhs.m_accessMask;

    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }

    if(NULL != this_handle)
    {
        this_handle->Release();
    }

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline basic_reg_key_sequence_iterator<C, T, V, A>::~basic_reg_key_sequence_iterator() stlsoft_throw_0()
{
    if(NULL != m_handle)
    {
        m_handle->Release();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline const ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::string_type &basic_reg_key_sequence_iterator<C, T, V, A>::get_key_name() const
{
    return m_name;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type &basic_reg_key_sequence_iterator<C, T, V, A>::operator ++()
{
    WINSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator!", NULL != m_handle);
    WINSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator!", sentinel_() != m_index);

    // Grab enough for the first item
    size_type   cchName =   0;
    result_type res     =   traits_type::reg_query_info(m_handle->m_hkey, NULL, NULL, NULL, &cchName, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(ERROR_ACCESS_DENIED == res)
        {
            throw access_denied_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
        else
        {
            throw registry_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_index = sentinel_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        buffer_type_    buffer(++cchName);   // This is increased so that the call to reg_enum_key is likely to succeed

        for(; !buffer.empty(); buffer.resize(2 * buffer.size()))    // Need to loop because sub-keys can change, when we're not monitoring
        {
            cchName  =   buffer.size();

            res = traits_type::reg_enum_key(m_handle->m_hkey, static_cast<ws_dword_t>(1 + m_index), &buffer[0], &cchName);

            if(ERROR_MORE_DATA == res)
            {
                continue; // "Let's go round again"
            }
            else if(ERROR_NO_MORE_ITEMS == res)
            {
                m_index = sentinel_();
                break;
            }
            else if(ERROR_SUCCESS != res)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                if(ERROR_ACCESS_DENIED == res)
                {
                    throw access_denied_exception("Could not enumerate sub-keys", static_cast<DWORD>(res));
                }
                else
                {
                    throw registry_exception("Could not enumerate sub-keys", static_cast<DWORD>(res));
                }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                m_index = sentinel_();
                break;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                m_name.assign(buffer.data(), cchName);

                ++m_index;

                break;
            }
        }
    }

    m_handle->test_reset_and_throw();

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type &basic_reg_key_sequence_iterator<C, T, V, A>::operator --()
{
    WINSTL_MESSAGE_ASSERT("Attempting to decrement an invalid iterator", NULL != m_handle);

    // Grab enough for the first item
    size_type   cchName     =   0;
    size_type   numEntries  =   0;
    result_type res         =   traits_type::reg_query_info(m_handle->m_hkey, NULL, NULL, &numEntries, &cchName, NULL, NULL, NULL, NULL, NULL, NULL);

    if(ERROR_SUCCESS != res)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(ERROR_ACCESS_DENIED == res)
        {
            throw access_denied_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
        else
        {
            throw registry_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_index = sentinel_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        buffer_type_    buffer(++cchName);   // This is increased so that the call to reg_enum_key is likely to succeed
        ws_dword_t      index;

        // If the iterator is currently at the "end()", ...
        if(m_index == sentinel_())
        {
            // ... then set the index to be one past the end
            index = numEntries - 1;
        }
        else
        {
            // ... otherwise just go back one from current
            index = m_index - 1;
        }

        for(; !buffer.empty(); buffer.resize(2 * buffer.size()))    // Need to loop because sub-keys can change, when we're not monitoring
        {
            cchName  =   buffer.size();

            res = traits_type::reg_enum_key(m_handle->m_hkey, index, &buffer[0], &cchName);

            if(ERROR_MORE_DATA == res)
            {
                continue; // "Let's go round again"
            }
            else if(ERROR_SUCCESS != res)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                if(ERROR_ACCESS_DENIED == res)
                {
                    throw access_denied_exception("Could not elicit sub-key information", static_cast<DWORD>(res));
                }
                else
                {
                    throw registry_exception("Could not enumerate sub-keys", static_cast<DWORD>(res));
                }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                m_index = sentinel_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                m_name.assign(buffer.data(), cchName);

                m_index = index;

                break;
            }
        }
    }

    m_handle->test_reset_and_throw();

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline const ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type basic_reg_key_sequence_iterator<C, T, V, A>::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline const ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::class_type basic_reg_key_sequence_iterator<C, T, V, A>::operator --(int)
{
    class_type  ret(*this);

    operator --();

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline const ss_typename_type_k basic_reg_key_sequence_iterator<C, T, V, A>::value_type basic_reg_key_sequence_iterator<C, T, V, A>::operator *() const
{
    WINSTL_MESSAGE_ASSERT("Attempting to dereference an invalid iterator", NULL != m_handle);

    m_handle->test_reset_and_throw();

    return value_type(m_handle->m_hkey, m_name, m_accessMask);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ws_bool_t basic_reg_key_sequence_iterator<C, T, V, A>::equal(class_type const &rhs) const
{
    return m_index == rhs.m_index;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ws_bool_t basic_reg_key_sequence_iterator<C, T, V, A>::operator ==(class_type const &rhs) const
{
    return equal(rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V, ss_typename_param_k A>
inline ws_bool_t basic_reg_key_sequence_iterator<C, T, V, A>::operator !=(class_type const &rhs) const
{
    return !equal(rhs);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */