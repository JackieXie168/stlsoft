/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/zorder_iterator.hpp
 *
 * Purpose:     Z-order iteration.
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


/// \file winstl/zorder_iterator.hpp
///
/// Z-order iteration

#ifndef WINSTL_INCL_WINSTL_HPP_ZORDER_ITERATOR
#define WINSTL_INCL_WINSTL_HPP_ZORDER_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_ZORDER_ITERATOR_MAJOR    1
# define WINSTL_VER_WINSTL_HPP_ZORDER_ITERATOR_MINOR    2
# define WINSTL_VER_WINSTL_HPP_ZORDER_ITERATOR_REVISION 1
# define WINSTL_VER_WINSTL_HPP_ZORDER_ITERATOR_EDIT     9
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
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

/// Iterates over the Z-order of window peers
class zorder_iterator
    : public stlsoft_ns_qual(iterator_base)<winstl_ns_qual_std(bidirectional_iterator_tag)
                                        ,   HWND
                                        ,   ws_ptrdiff_t
                                        ,   void
                                        ,   HWND
                                        >
{
/// \name Types
/// @{
public:
    typedef HWND                value_type;
    typedef ws_size_t           size_type;
    typedef ws_ptrdiff_t        difference_type;
    typedef zorder_iterator     class_type;
/// @}

/// \name Construction
/// @{
public:
    zorder_iterator(HWND hwndRoot, HWND hwndCurrent);
public:
    zorder_iterator();
    ss_explicit_k zorder_iterator(HWND hwndRoot);
    zorder_iterator(class_type const &);
    ~zorder_iterator() stlsoft_throw_0();

    class_type &operator =(class_type const &);
/// @}

/// \name Iteration
/// @{
public:
    /// \name Input Iterator Methods
    /// @{
    class_type  &operator ++();
    class_type  operator ++(int);
    value_type  operator *() const;
    /// @}

    /// \name Bidirectoonal Iterator Methods
    /// @{
    class_type  &operator --();
    class_type  operator --(int);
    /// @}
/// @}

/// \name Comparison
/// @{
public:
    bool equal(class_type const &rhs) const;
/// @}

/// \name Members
/// @{
private:
    HWND    m_hwndRoot;
    HWND    m_hwndCurrent;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline bool operator ==(zorder_iterator const &lhs
                    ,   zorder_iterator const &rhs)
{
    return lhs.equal(rhs);
}
inline bool operator !=(zorder_iterator const &lhs
                    ,   zorder_iterator const &rhs)
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline zorder_iterator::zorder_iterator()
    : m_hwndRoot(NULL)
    , m_hwndCurrent(NULL)
{}

inline zorder_iterator::zorder_iterator(HWND hwndRoot, HWND hwndCurrent)
    : m_hwndRoot(hwndRoot)
    , m_hwndCurrent(hwndCurrent)
{}

inline zorder_iterator::zorder_iterator(HWND hwndRoot)
    : m_hwndRoot(hwndRoot)
    , m_hwndCurrent(hwndRoot)
{}

inline zorder_iterator::zorder_iterator(class_type const &rhs)
    : m_hwndRoot(rhs.m_hwndRoot)
    , m_hwndCurrent(rhs.m_hwndCurrent)
{}

inline zorder_iterator::~zorder_iterator() stlsoft_throw_0()
{}

inline zorder_iterator::class_type &zorder_iterator::operator =(zorder_iterator::class_type const &rhs)
{
    WINSTL_ASSERT(NULL == m_hwndRoot || NULL == rhs.m_hwndRoot || (rhs.m_hwndRoot == m_hwndRoot));

    m_hwndCurrent   =   rhs.m_hwndCurrent;

    return *this;
}

inline zorder_iterator::class_type &zorder_iterator::operator ++()
{
    WINSTL_MESSAGE_ASSERT("Attempt to increment an invalid / out-of-range iterator", NULL != m_hwndCurrent);

    m_hwndCurrent = ::GetNextWindow(m_hwndCurrent, GW_HWNDNEXT);

    return *this;
}

inline zorder_iterator::class_type  zorder_iterator::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

inline zorder_iterator::class_type &zorder_iterator::operator --()
{
    if(NULL != m_hwndCurrent)
    {
        m_hwndCurrent = ::GetNextWindow(m_hwndCurrent, GW_HWNDPREV);
    }
    else
    {
        m_hwndCurrent = ::GetWindow(m_hwndRoot, GW_HWNDLAST);
    }

    return *this;
}

inline zorder_iterator::class_type zorder_iterator::operator --(int)
{
    class_type  ret(*this);

    operator --();

    return ret;
}

inline zorder_iterator::value_type zorder_iterator::operator *() const
{
    return m_hwndCurrent;
}

inline bool zorder_iterator::equal(zorder_iterator::class_type const &rhs) const
{
    WINSTL_ASSERT(NULL == m_hwndRoot || NULL == rhs.m_hwndRoot || (rhs.m_hwndRoot == m_hwndRoot));

    return m_hwndCurrent == rhs.m_hwndCurrent;
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

#endif /* WINSTL_INCL_WINSTL_HPP_ZORDER_ITERATOR */

/* ////////////////////////////////////////////////////////////////////////// */
