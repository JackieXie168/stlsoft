/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/combox_sequence.hpp (formerly winstl_combobox_sequence.h)
 *
 * Purpose:     Contains the combobox_sequence class.
 *
 * Created:     13th November 2002
 * Updated:     18th December 2005
 *
 * Thanks:      To Pablo Aguilar for some patches.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/combox_sequence.hpp
///
/// Contains the combobox_sequence class.

#ifndef WINSTL_INCL_WINSTL_HPP_COMBOBOX_SEQUENCE
#define WINSTL_INCL_WINSTL_HPP_COMBOBOX_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_COMBOBOX_SEQUENCE_MAJOR      3
# define WINSTL_VER_WINSTL_HPP_COMBOBOX_SEQUENCE_MINOR      1
# define WINSTL_VER_WINSTL_HPP_COMBOBOX_SEQUENCE_REVISION   1
# define WINSTL_VER_WINSTL_HPP_COMBOBOX_SEQUENCE_EDIT       40
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER
# include <stlsoft/auto_buffer.hpp>           // Include the STLSoft auto_buffer
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/processheap_allocator.hpp>  // processheap_allocator
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef WINSTL_INCL_WINSTL_H_CONTROL_FUNCTIONS
# include <winstl/control_functions.h>      // combobox_addstring, etc.
#endif /* !WINSTL_INCL_WINSTL_H_CONTROL_FUNCTIONS */

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

/// \weakgroup libraries_control Control Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating GUI controls

/// \defgroup winstl_control_library Control Library (WinSTL)
/// \ingroup WinSTL libraries_control
/// \brief This library provides facilities for defining and manipulating Win32 GUI controls
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Iterator for combobox_sequence class
///
/// This class acts as the iterator for the combobox_sequence class, and implements
/// the Random Access Iterator concept
///
/// \param S The string type
template <ss_typename_param_k S>
class combobox_sequence_const_iterator
    : public stlsoft_ns_qual(iterator_base) <   winstl_ns_qual_std(random_access_iterator_tag)
                                            ,   S
                                            ,   ws_ptrdiff_t
                                            ,   void * // Placate Borland C++ (to test, replace with void)
                                            ,   S
                                            >
{
public:
    /// The string type
    typedef S                                           value_type;
    /// The current parameterisation of the type
    typedef combobox_sequence_const_iterator<S>         class_type;
    /// The character type
    typedef TCHAR                                       char_type;
    /// The size type
    typedef ws_size_t                                   size_type;
    /// The difference type
    typedef ws_ptrdiff_t                                difference_type;
    /// The non-mutating (const) reference type
    typedef value_type const                            &const_reference;
    /// The allocator type
    typedef processheap_allocator<char_type>            allocator_type;
    /// The auto-buffer type
    typedef stlsoft_ns_qual(auto_buffer)<   char_type
                                        ,   allocator_type
                                        ,   256
                                        >               buffer_type;

public:
    /// Construct an instance from the combo-box \c hwndComboBox at the given \c index
    combobox_sequence_const_iterator(HWND hwndComboBox, int index)
        : m_hwnd(hwndComboBox)
        , m_index(index)
    {}

public:
    /// Dereferences the iterator and returns the current value
    const_reference operator *() const
    {
        int         len =   combobox_gettextlen(m_hwnd, m_index);
        buffer_type buffer(1 + len);

        combobox_gettext(m_hwnd, m_index, &buffer[0]);

        // PA: -1 to account for the NULL character
        mutable_access(m_value).assign(&buffer[0], buffer.size() - 1);

        return m_value;
    }

public:
    /// Pre-increment operator
    class_type &operator ++()
    {
        ++m_index;

        return *this;
    }

    /// Post-increment operator
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }

    /// Compares \c this and \c rhs for equivalence
    difference_type compare(class_type const &rhs) const
    {
        WINSTL_MESSAGE_ASSERT("invalid comparison between iterators from different ranges", m_hwnd == rhs.m_hwnd);

        return m_index - rhs.m_index;
    }

    /// Indicates whether \c this and \c rhs are equivalent
    bool operator == (class_type const &rhs) const
    {
        return compare(rhs) == 0;
    }

    /// Indicates whether \c this and \c rhs are not equivalent
    bool operator != (class_type const &rhs) const
    {
        return compare(rhs) != 0;
    }

    // Bidirectional iterator operations

    /// Pre-decrement operator
    class_type &operator --()
    {
        --m_index;

        return *this;
    }

    /// Post-decrement operator
    class_type operator --(int)
    {
        class_type  ret(*this);

        operator --();

        return ret;
    }

    // Random access operations

    /// Offset
    class_type &operator +=(difference_type index)
    {
        m_index += index;

        return *this;
    }

    /// Offset
    class_type &operator -=(difference_type index)
    {
        m_index -= index;

        return *this;
    }

    /// Indexing operator
    value_type operator [](difference_type index) const
    {
        // PA: Emulate pointer-like operation where it[0] returns the current item's value
        return get_value_at_(m_hwnd, m_index + index);
    }

    /// Calculate the distance between \c this and \c rhs
    difference_type distance(class_type const &rhs) const
    {
        return m_index - rhs.m_index;
    }

    /// Pointer subtraction
    class_type operator -(difference_type n) const
    {
        return class_type(*this) -= n;
    }

    /// Pointer addition
    class_type operator +(difference_type n) const
    {
        return class_type(*this) += n;
    }

    /// Pointer difference
    difference_type operator -(class_type const &rhs) const
    {
        return distance(rhs);
    }

    /// Indicates whether \c this is less than \c rhs
    ws_bool_t operator <(class_type const &rhs) const
    {
        return compare(rhs) < 0;
    }

    /// Indicates whether \c this is greater than \c rhs
    ws_bool_t operator >(class_type const &rhs) const
    {
        return compare(rhs) > 0;
    }

    /// Indicates whether \c this is less than or equal \c rhs
    ws_bool_t operator <=(class_type const &rhs) const
    {
        return compare(rhs) <= 0;
    }

    /// Indicates whether \c this is greater than or equal \c rhs
    ws_bool_t operator >=(class_type const &rhs) const
    {
        return compare(rhs) >= 0;
    }

// Implementation
private:
    static value_type get_value_at_(HWND hwnd, difference_type index)
    {
        int         len =   combobox_gettextlen(hwnd, index);
        buffer_type buffer(1 + len);

        combobox_gettext(hwnd, index, &buffer[0]);

        return value_type(&buffer[0], buffer.size());
    }

// Members
private:
    HWND                    m_hwnd;
    int                     m_index;
    ss_mutable_k value_type m_value;
};

/// STL-like sequence for combo-box contents
///
/// This class presents an STL-like sequence interface to a combo-box
///
/// \param S The string type
template <ss_typename_param_k S>
class combobox_sequence
{
public:
    /// The current parameterisation of the type
    typedef combobox_sequence<S>                                class_type;
    /// The non-mutating (const) iterator type
    typedef combobox_sequence_const_iterator<S>                 const_iterator;
    /// The character type
    typedef ss_typename_type_k const_iterator::char_type        char_type;
    /// The value type
    typedef ss_typename_type_k const_iterator::value_type       value_type;
    /// The size type
    typedef ss_typename_type_k const_iterator::size_type        size_type;
    /// The difference type
    typedef ss_typename_type_k const_iterator::difference_type  difference_type;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k const_iterator::const_reference  const_reference;
#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The non-mutating (const) reverse iterator type
    typedef stlsoft_ns_qual(const_reverse_iterator_base)<   const_iterator
                                                        ,   value_type
                                                        ,   value_type // Return by value!
                                                        ,   void*
                                                        ,   difference_type
                                                        >       const_reverse_iterator;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

protected:
    typedef ss_typename_type_k const_iterator::allocator_type   allocator_type;
    typedef ss_typename_type_k const_iterator::buffer_type      buffer_type;

// Construction
public:
    /// Constructs from the given combo-box
    ss_explicit_k combobox_sequence(HWND hwndComboBox)
        : m_hwnd(hwndComboBox)
    {}

// State
public:
    /// Returns the number of elements in the combo-box
    size_type size() const
    {
        return static_cast<size_type>(combobox_getcount(m_hwnd));
    }
    /// Indicates whether the combo-box is empty
    ws_bool_t empty() const
    {
        return size() == 0;
    }
    /// Returns the maximum number of items that the combo-box can contain
    static size_type max_size()
    {
        return static_cast<size_type>(-1) / sizeof(LPCTSTR);
    }

// Iteration
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const
    {
        return const_iterator(m_hwnd, 0);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const
    {
        return const_iterator(m_hwnd, static_cast<int>(combobox_getcount(m_hwnd)));
    }

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Accessors
public:
    /// Returns the item at the given index
    value_type operator [](difference_type index) const
    {
        int         len =   combobox_gettextlen(m_hwnd, index);
        buffer_type buffer(1 + len);

        combobox_gettext(m_hwnd, index, &buffer[0]);

        // PA: -1 to account for the NULL character which should be taken care of automatically by the string_type
        return value_type(&buffer[0], buffer.size() - 1);
    }

// Members
private:
    HWND    m_hwnd;
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/combobox_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_control_library

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

#endif /* WINSTL_INCL_WINSTL_HPP_COMBOBOX_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
