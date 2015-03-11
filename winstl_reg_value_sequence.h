/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl_reg_value_sequence.h
 *
 * Purpose:     Contains the basic_reg_value_sequence template class, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Notes:       The original implementation of the class had the const_iterator
 *              and value_type as nested classes. Unfortunately, Visual C++ 5 &
 *              6 both had either compilation or linking problems so these are
 *              regretably now implemented as independent classes.
 *
 * Created:     19th January 2002
 * Updated:     18th January 2006
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


/// \file winstl_reg_value_sequence.h
///
/// Contains the basic_reg_value_sequence template class, and ANSI and Unicode specialisations thereof.

#ifndef WINSTL_INCL_H_WINSTL_REG_VALUE_SEQUENCE
#define WINSTL_INCL_H_WINSTL_REG_VALUE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_H_WINSTL_REG_VALUE_SEQUENCE_MAJOR       2
# define WINSTL_VER_H_WINSTL_REG_VALUE_SEQUENCE_MINOR       5
# define WINSTL_VER_H_WINSTL_REG_VALUE_SEQUENCE_REVISION    2
# define WINSTL_VER_H_WINSTL_REG_VALUE_SEQUENCE_EDIT        77
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_DEFS
# include <winstl/reg_defs.hpp>                 // The WinSTL reg API standard types
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_DEFS */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_TRAITS
# include <winstl/reg_traits.hpp>               // The WinSTL reg API reg_traits class
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_TRAITS */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_KEY
# include <winstl/reg_key.hpp>                  // The WinSTL reg API reg_key class
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_KEY */
#ifndef WINSTL_INCL_WINSTL_HPP_REG_VALUE
# include <winstl/reg_value.hpp>                // The WinSTL reg API reg_value class
#endif /* !WINSTL_INCL_WINSTL_HPP_REG_VALUE */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef WINSTL_INCL_WINSTL_HPP_EVENT
# include <winstl/event.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_EVENT */
#ifndef WINSTL_INCL_WINSTL_H_FUNCTIONS
# include <winstl/functions.h>
#endif /* !WINSTL_INCL_WINSTL_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_HPP_DL_CALL
# include <winstl/dl_call.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_DL_CALL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_EXTERNAL_ITERATOR_INVALIDATION
# include <stlsoft/exceptions/external_iterator_invalidation.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_EXTERNAL_ITERATOR_INVALIDATION */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT
//# include <stlsoft/util/must_init.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */

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
 * Forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
class basic_reg_value_sequence_const_iterator;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class basic_reg_value_sequence
/// Presents an STL-like sequence interface over the values of a given registry key
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments this defaults to reg_traits<C>
/// \param A The allocator type. On translators that support default template arguments this defaults to processheap_allocator<C>
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = reg_traits<C>
        ,   ss_typename_param_k A = processheap_allocator<C>
#else
        ,   ss_typename_param_k T /* = reg_traits<C> */
        ,   ss_typename_param_k A /* = processheap_allocator<C> */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_reg_value_sequence
    : public stl_collection_tag
{
public:
    /// The character type
    typedef C                                                                       char_type;
    /// The traits type
    typedef T                                                                       traits_type;
    /// The allocator type
    typedef A                                                                       allocator_type;
    /// The current parameterisation of the type
    typedef basic_reg_value_sequence<C, T, A>                                       class_type;
    /// The value type
    typedef basic_reg_value<C, T, A>                                                value_type;
    /// The size type
    typedef ss_typename_type_k traits_type::size_type                               size_type;
    /// The get key type
    typedef basic_reg_key<C, T, A>                                                  reg_key_type;
    /// The non-mutating (const) iterator type
    typedef basic_reg_value_sequence_const_iterator<C, T, value_type, A>            const_iterator;
    /// The reference type
    typedef value_type                                                              &reference;
    /// The non-mutable (const) reference type
    typedef value_type const                                                        &const_reference;
    /// The hkey type
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1100
    /* WSCB: VC5 has an unresolved external linker error if use traits_type::hkey_type */
    typedef HKEY                                                                    hkey_type;
#else
    typedef ss_typename_type_k traits_type::hkey_type                               hkey_type;
#endif /* 0 */
    /// The difference type
    typedef ws_ptrdiff_t                                                            difference_type;
    /// The non-mutating (const) reverse iterator type
#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef stlsoft_ns_qual(const_reverse_bidirectional_iterator_base)  <   const_iterator
                                                                        ,   value_type
                                                                        ,   value_type  // By-Value Temporary reference category
                                                                        ,   void        // By-Value Temporary reference category
                                                                        ,   difference_type
                                                                        >           const_reverse_iterator;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Construction
public:
    /// Creates an instance on the named sub-key of \c hkey
    basic_reg_value_sequence(hkey_type hkey, char_type const *sub_key_name);
    /// Creates an instance on the given \c key
    basic_reg_value_sequence(reg_key_type const &key);
    /// Destructor
    ~basic_reg_value_sequence() stlsoft_throw_0();

// Iteration
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator          begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator          end() const;

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// State
public:
    /// Returns the number of values
    size_type               size() const;
    /// Evalulates whether there are no values
    ws_bool_t               empty() const;
    /// Returns the maximum number of values
    static size_type        max_size();

// Members
private:
    ss_typename_type_k traits_type::hkey_type   m_hkey;

// Not to be implemented
private:
    basic_reg_value_sequence(class_type const &);
    basic_reg_value_sequence const &operator =(class_type const &);
};

/* Typedefs to commonly encountered types. */
/// Instantiation of the basic_reg_value_sequence template for the ANSI character type \c char
typedef basic_reg_value_sequence<ws_char_a_t, reg_traits<ws_char_a_t>, processheap_allocator<ws_char_a_t> >     reg_value_sequence_a;
/// Instantiation of the basic_reg_value_sequence template for the Unicode character type \c wchar_t
typedef basic_reg_value_sequence<ws_char_w_t, reg_traits<ws_char_w_t>, processheap_allocator<ws_char_w_t> >     reg_value_sequence_w;
/// Instantiation of the basic_reg_value_sequence template for the Win32 character type \c TCHAR
typedef basic_reg_value_sequence<TCHAR, reg_traits<TCHAR>, processheap_allocator<TCHAR> >                       reg_value_sequence;

// class basic_reg_value_sequence_const_iterator
/// Iterator for the basic_reg_value_sequence class
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
class basic_reg_value_sequence_const_iterator
    : public stlsoft_ns_qual(iterator_base)<winstl_ns_qual_std(bidirectional_iterator_tag)
                                        ,   V
                                        ,   ws_ptrdiff_t
                                        ,   void    // By-Value Temporary reference
                                        ,   V       // By-Value Temporary reference
                                        >
{
public:
    /// The character type
    typedef C                                                   char_type;
    /// The traits type
    typedef T                                                   traits_type;
    /// The value type
    typedef V                                                   value_type;
    /// The allocator type
    typedef A                                                   allocator_type;
    /// The current parameterisation of the type
    typedef basic_reg_value_sequence_const_iterator<C, T, V, A> class_type;
    /// The size type
    typedef ss_typename_type_k traits_type::size_type           size_type;
    /// The difference type
    typedef ss_typename_type_k traits_type::difference_type     difference_type;
    /// The string type
    typedef ss_typename_type_k traits_type::string_type         string_type;
    /// The index type
    typedef ws_sint32_t                                         index_type;
    /// The hkey type
    typedef ss_typename_type_k traits_type::hkey_type           hkey_type;

// Construction
private:
    basic_reg_value_sequence_const_iterator(hkey_type hkey, index_type index, string_type const &value_name)
        : m_hkey(traits_type::key_dup(hkey))
        , m_index(index)
        , m_name(value_name)
        , m_monitor(true, false)
    {
        dl_call<LONG>("ADVAPI32.DLL", "S:RegNotifyChangeKeyValue", m_hkey, false, (int)REG_NOTIFY_CHANGE_LAST_SET, m_monitor.handle(), true);
    } // Implementation is within class, otherwise VC5 will not link
    ss_explicit_k basic_reg_value_sequence_const_iterator(hkey_type hkey)
        : m_hkey(traits_type::key_dup(hkey))
        , m_index(sentinel_())
        , m_monitor(true, false)
    {
        dl_call<LONG>("ADVAPI32.DLL", "S:RegNotifyChangeKeyValue", m_hkey, false, (int)REG_NOTIFY_CHANGE_LAST_SET, m_monitor.handle(), true);
    } // Implementation is within class, otherwise VC5 will not link
public:
    /// Default constructor
    basic_reg_value_sequence_const_iterator();
    /// Copy constructor
    basic_reg_value_sequence_const_iterator(class_type const &rhs);
    /// Destructor
    ~basic_reg_value_sequence_const_iterator() stlsoft_throw_0();

    /// Copy assignment operator
    basic_reg_value_sequence_const_iterator &operator =(class_type const &rhs);

// Operators
public:
    /// Pre-increment operator
    class_type &operator ++();
    /// Pre-decrement operator
    class_type &operator --();
    /// Post-increment operator
    const class_type operator ++(int);
    /// Post-decrement operator
    const class_type operator --(int);
    /// Dereference to return the value representing the current position
    const value_type operator *() const;
    /// Evaluates whether \c this and \c rhs are equivalent
    ws_bool_t operator ==(class_type const &rhs) const;
    /// Evaluates whether \c this and \c rhs are not equivalent
    ws_bool_t operator !=(class_type const &rhs) const;

// Implementation
private:
    static index_type sentinel_();

// Members
private:
    friend class basic_reg_value_sequence<C, T, A>;

    typedef basic_reg_value_sequence<C, T, A>      list_type;

    hkey_type           m_hkey;     // Parent container
    index_type          m_index;    // Iteration index
    string_type         m_name;     // The value name
    event               m_monitor;  // The event that will monitor changes to the API.
};

///////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_reg_value_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "reg_value_sequence", __FILE__);

            reg_value_sequence_a    seq_a(HKEY_CURRENT_USER, "SOFTWARE");

            reg_value_sequence_a::const_iterator    b   =   seq_a.begin();
            reg_value_sequence_a::const_iterator    e   =   seq_a.end();

            for(; b != e; ++b)
            {
                reg_value_sequence_a::value_type    v   =   *b;
            }

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_reg_value_sequence(test_winstl_reg_value_sequence);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// basic_reg_value_sequence

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence<C, T, A>::basic_reg_value_sequence(ss_typename_type_k basic_reg_value_sequence<C, T, A>::hkey_type hkey, ss_typename_type_k basic_reg_value_sequence<C, T, A>::char_type const * sub_key_name)
    : m_hkey(NULL)
{
    if(0 != traits_type::reg_open_key(hkey, sub_key_name, &m_hkey))
    {
        m_hkey = NULL;
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence<C, T, A>::basic_reg_value_sequence(reg_key_type const &key)
    : m_hkey(traits_type::key_dup(key.m_hkey))
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence<C, T, A>::~basic_reg_value_sequence() stlsoft_throw_0()
{
    if(m_hkey != NULL)
    {
        ::RegCloseKey(m_hkey);
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence<C, T, A>::const_iterator basic_reg_value_sequence<C, T, A>::begin() const
{
    // Grab enough for the first item
    size_type   cch_value_name  =   0;
    ws_long_t   res             =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, NULL, &cch_value_name, NULL, NULL, NULL);

    if(res == 0)
    {
        stlsoft_ns_qual(auto_buffer_old)<char_type, allocator_type, CCH_REG_API_AUTO_BUFFER>    buffer(++cch_value_name);
        size_type                                                                               cb_data = 0;

        res = traits_type::reg_enum_value(m_hkey, 0, &buffer[0], &cch_value_name, NULL, NULL, cb_data);

        if(res == 0)
        {
            buffer[cch_value_name] = 0;

            return const_iterator(m_hkey, 0, &buffer[0]);
        }
    }

    return end();
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence<C, T, A>::const_iterator basic_reg_value_sequence<C, T, A>::end() const
{
    return const_iterator(m_hkey);
}

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence<C, T, A>::const_reverse_iterator basic_reg_value_sequence<C, T, A>::rbegin() const
{
    return const_reverse_iterator(end());
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence<C, T, A>::const_reverse_iterator basic_reg_value_sequence<C, T, A>::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence<C, T, A>::size_type basic_reg_value_sequence<C, T, A>::size() const
{
    ws_uint_t   c_values;
    ws_long_t   res         =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, &c_values, NULL, NULL, NULL, NULL);

    if(res != 0)
    {
        c_values = 0;
    }

    return static_cast<size_type>(c_values);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_reg_value_sequence<C, T, A>::empty() const
{
    return size() == 0;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_type_k basic_reg_value_sequence<C, T, A>::size_type basic_reg_value_sequence<C, T, A>::max_size()
{
    return static_cast<size_type>(-1);
}

// basic_reg_value_sequence_const_iterator

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline /* static */ ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::index_type basic_reg_value_sequence_const_iterator<C, T, V, A>::sentinel_()
{
    return 0x7fffffff;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence_const_iterator<C, T, V, A>::basic_reg_value_sequence_const_iterator()
    : m_hkey(NULL)
    , m_index(sentinel_())
    , m_monitor(true, false)
{}

#if 0
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence_const_iterator<C, T, V, A>::basic_reg_value_sequence_const_iterator(basic_reg_value_sequence_const_iterator<C, T, V, A>::hkey_type hkey, basic_reg_value_sequence_const_iterator<C, T, V, A>::index_type index, basic_reg_value_sequence_const_iterator<C, T, V, A>::string_type const &value_name)
    : m_hkey(traits_type::key_dup(hkey))
    , m_index(index)
    , m_name(value_name)
    , m_monitor(true, false)
{}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence_const_iterator<C, T, V, A>::basic_reg_value_sequence_const_iterator(basic_reg_value_sequence_const_iterator<C, T, V, A>::hkey_type hkey)
    : m_hkey(traits_type::key_dup(hkey))
    , m_index(sentinel_())
    , m_monitor(true, false)
{}
#endif /* 0 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence_const_iterator<C, T, V, A>::basic_reg_value_sequence_const_iterator(class_type const &rhs)
    : m_hkey(traits_type::key_dup(rhs.m_hkey))
    , m_index(rhs.m_index)
    , m_name(rhs.m_name)
    , m_monitor(true, rhs.m_monitor.is_signalled())
{
    dl_call<LONG>("ADVAPI32.DLL", "S:RegNotifyChangeKeyValue", m_hkey, false, (int)REG_NOTIFY_CHANGE_LAST_SET, m_monitor.handle(), true);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type &basic_reg_value_sequence_const_iterator<C, T, V, A>::operator =(ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type const &rhs)
{
    // For efficiency, we don't do self-assignment test, and assume (reasonably)
    // that m_name will be self-protecting

    m_hkey      =   traits_type::key_dup(rhs.m_hkey);
    m_index     =   rhs.m_index;
    m_name      =   rhs.m_name;

#if 0
#if 0
    if(&rhs != this)
    {
        HANDLE  hCopy;

        // TODO: Should throw an exception here

        if(ERROR_SUCCESS != winstl__DuplicateLocalHandle(rhs.m_hMonitor, &hCopy))
        {
            hCopy = NULL;
        }

        winstl__CloseHandleSetNull(m_hEvent);

        m_hEvent = hCopy;
    }
#else
    m_hEvent    =   rhs.m_hEvent;
#endif /* 0 */
#endif /* 0 */

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline basic_reg_value_sequence_const_iterator<C, T, V, A>::~basic_reg_value_sequence_const_iterator() stlsoft_throw_0()
{
    if(NULL != m_hkey)
    {
        ::RegCloseKey(m_hkey);
    }
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type &basic_reg_value_sequence_const_iterator<C, T, V, A>::operator ++()
{
    // Grab enough for the first item
    size_type   cch_value_name  =   0;
    ws_long_t   res             =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, NULL, &cch_value_name, NULL, NULL, NULL);

    if(res == 0)
    {
        stlsoft_ns_qual(auto_buffer_old)<char_type, allocator_type, CCH_REG_API_AUTO_BUFFER>    buffer(++cch_value_name);
        size_type                                                                               cb_data = 0;

        res = traits_type::reg_enum_value(m_hkey, static_cast<ws_dword_t>(++m_index), &buffer[0], &cch_value_name, NULL, NULL, cb_data);

        if(res == 0)
        {
            buffer[cch_value_name] = 0;

            m_name = buffer.data();
        }
        else
        {
            m_index = sentinel_();
        }
    }
    else
    {
        m_index = sentinel_();
    }

    if(IsWaitObjectSignalled(m_monitor.handle()))
    {
        // Must set to watch again here, because several iterators from the same
        // same reg_value_sequence could be open simultaneously

        dl_call<LONG>("ADVAPI32.DLL", "S:RegNotifyChangeKeyValue", m_hkey, false, (int)REG_NOTIFY_CHANGE_LAST_SET, m_monitor.handle(), true);

        throw stlsoft_ns_qual(external_iterator_invalidation)("registry value(s) changed");
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type &basic_reg_value_sequence_const_iterator<C, T, V, A>::operator --()
{
    // Grab enough for the first item
    size_type   cch_value_name  =   0;
    ws_uint_t   c_values;
    ws_long_t   res             =   traits_type::reg_query_info(m_hkey, NULL, NULL, NULL, NULL, NULL, &c_values, &cch_value_name, NULL, NULL, NULL);

    if(res == 0)
    {
        stlsoft_ns_qual(auto_buffer_old)<char_type, allocator_type, CCH_REG_API_AUTO_BUFFER>    buffer(++cch_value_name);
        size_type                                                                               cb_data = 0;

        // If the iterator is currently at the "end()", ...
        if(m_index == sentinel_())
        {
            // ... then set the index to be one past the end
            m_index = c_values;
        }

        // Move back one position, and get the key name
        res = traits_type::reg_enum_value(m_hkey, static_cast<ws_dword_t>(--m_index), &buffer[0], &cch_value_name, NULL, NULL, cb_data);

        if(res == 0)
        {
            buffer[cch_value_name] = 0;

            m_name = buffer.data();
        }
        else
        {
            m_index = sentinel_();
        }
    }
    else
    {
        m_index = sentinel_();
    }

    if(IsWaitObjectSignalled(m_monitor.handle()))
    {
        // Must set to watch again here, because several iterators from the same
        // same reg_value_sequence could be open simultaneously

        dl_call<LONG>("ADVAPI32.DLL", "S:RegNotifyChangeKeyValue", m_hkey, false, (int)REG_NOTIFY_CHANGE_LAST_SET, m_monitor.handle(), true);

        throw stlsoft_ns_qual(external_iterator_invalidation)("registry value(s) changed");
    }

    return *this;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline const ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type basic_reg_value_sequence_const_iterator<C, T, V, A>::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline const ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::class_type basic_reg_value_sequence_const_iterator<C, T, V, A>::operator --(int)
{
    class_type  ret(*this);

    operator --();

    return ret;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline const ss_typename_type_k basic_reg_value_sequence_const_iterator<C, T, V, A>::value_type basic_reg_value_sequence_const_iterator<C, T, V, A>::operator *() const
{
    return value_type(m_hkey, m_name);
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_reg_value_sequence_const_iterator<C, T, V, A>::operator ==(class_type const &rhs) const
{
//    WINSTL_MESSAGE_ASSERT("Comparing reg_value_sequence iterators from different sequences!", m_hkey == rhs.m_hkey);

    return m_index == rhs.m_index;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        ,   ss_typename_param_k V
        ,   ss_typename_param_k A
        >
inline ws_bool_t basic_reg_value_sequence_const_iterator<C, T, V, A>::operator !=(class_type const &rhs) const
{
    return ! operator ==(rhs);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_H_WINSTL_REG_VALUE_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
