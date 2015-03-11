/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/window_peer_sequence.hpp
 *
 * Purpose:     Collection of the peers of a given window.
 *
 * Created:     11th July 2005
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


/// \file winstl/window_peer_sequence.hpp
///
/// Collection of the peers of a given window

#ifndef WINSTL_INCL_WINSTL_HPP_WINDOW_PEER_SEQUENCE
#define WINSTL_INCL_WINSTL_HPP_WINDOW_PEER_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_WINDOW_PEER_SEQUENCE_MAJOR       1
# define WINSTL_VER_WINSTL_HPP_WINDOW_PEER_SEQUENCE_MINOR       2
# define WINSTL_VER_WINSTL_HPP_WINDOW_PEER_SEQUENCE_REVISION    1
# define WINSTL_VER_WINSTL_HPP_WINDOW_PEER_SEQUENCE_EDIT        7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_ZORDER_ITERATOR
# include <winstl/zorder_iterator.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_ZORDER_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

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

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Window peer sequence
class window_peer_sequence
{
public:
    /// The mutating (non-const) iterator type
    typedef zorder_iterator                                                 iterator;
    /// The value type
    typedef iterator::value_type                                            value_type;
    /// The size type
    typedef iterator::size_type                                             size_type;
    /// The difference type
    typedef iterator::difference_type                                       difference_type;
    /// The non-mutating (const) iterator type
    typedef zorder_iterator                                                 const_iterator;
    /// This class
    typedef window_peer_sequence                                            class_type;

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    /// The non-mutating (const) reverse iterator type
    typedef stlsoft_ns_qual(reverse_bidirectional_iterator_base)<       iterator
                                                                    ,   value_type
                                                                    ,   iterator::reference
                                                                    ,   iterator::pointer
                                                                    ,   difference_type
                                                                    >       reverse_iterator;

    /// The mutating (non-const) reverse iterator type
    typedef stlsoft_ns_qual(const_reverse_bidirectional_iterator_base)< const_iterator
                                                                    ,   value_type const
                                                                    ,   const_iterator::reference
                                                                    ,   const_iterator::pointer
                                                                    ,   difference_type
                                                                    >       const_reverse_iterator;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

public:
    /// Constructs a sequence of peers of the given window
    ss_explicit_k window_peer_sequence(HWND hwndRoot);

public:
    iterator                begin();
    iterator                end();
    const_iterator          begin() const;
    const_iterator          end() const;
#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    reverse_iterator        rbegin();
    reverse_iterator        rend();
    const_reverse_iterator  rbegin() const;
    const_reverse_iterator  rend() const;
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

public:
    ss_bool_t           empty() const;

private:
    HWND    m_hwndRoot;

private:
    window_peer_sequence(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline /* ss_explicit_k */ window_peer_sequence::window_peer_sequence(HWND hwndRoot)
    : m_hwndRoot(hwndRoot)
{}

inline window_peer_sequence::iterator window_peer_sequence::begin()
{
    return iterator(m_hwndRoot);
}

inline window_peer_sequence::iterator window_peer_sequence::end()
{
    return iterator();
}

inline window_peer_sequence::const_iterator window_peer_sequence::begin() const
{
    return iterator(m_hwndRoot);
}

inline window_peer_sequence::const_iterator window_peer_sequence::end() const
{
    return iterator();
}

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
inline window_peer_sequence::reverse_iterator window_peer_sequence::rbegin()
{
    return reverse_iterator(const_iterator(m_hwndRoot, NULL));
}

inline window_peer_sequence::reverse_iterator window_peer_sequence::rend()
{
    return reverse_iterator(begin());
}

inline window_peer_sequence::const_reverse_iterator window_peer_sequence::rbegin() const
{
    return const_reverse_iterator(const_iterator(m_hwndRoot, NULL));
}

inline window_peer_sequence::const_reverse_iterator window_peer_sequence::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

inline ss_bool_t window_peer_sequence::empty() const
{
    return end() == begin();
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

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

#endif /* WINSTL_INCL_WINSTL_HPP_WINDOW_PEER_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
