/* /////////////////////////////////////////////////////////////////////////////
 * File:        atlstl/string_access.hpp (formerly atlstl_string_access.h)
 *
 * Purpose:     Contains classes and functions for dealing with OLE/COM strings.
 *
 * Created:     27th May 2002
 * Updated:     22nd December 2005
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

/// \file atlstl/string_access.hpp
///
/// Contains classes and functions for dealing with OLE/COM strings.

#ifndef ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS
#define ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_HPP_STRING_ACCESS_MAJOR      3
# define ATLSTL_VER_ATLSTL_HPP_STRING_ACCESS_MINOR      1
# define ATLSTL_VER_ATLSTL_HPP_STRING_ACCESS_REVISION   1
# define ATLSTL_VER_ATLSTL_HPP_STRING_ACCESS_EDIT       76
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CSTRING_MAKER
# include <stlsoft/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CSTRING_MAKER */
#ifdef STLSOFT_UNITTEST
# include <wchar.h>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */

namespace stlsoft
{

namespace atlstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_string_access String Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary types

/// \defgroup atlstl_string_access_shims String Access Shims (ATLSTL)
/// \ingroup ATLSTL concepts_shims_string_access
/// \brief These \ref concepts_shims "shims" accessing string attributes for arbitrary ATL types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/* CWindow */

#ifdef __ATLWIN_H__
/// This class provides an intermediary object that may be returned by the
/// c_str_ptr_null() function, such that the window text of a given window
/// may be accessed as a null-terminated string.
class c_str_ptr_null_CWindow_proxy
{
private:
    typedef cstring_maker<TCHAR>            string_maker_type;
    typedef c_str_ptr_null_CWindow_proxy    class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWindow instance
    ///
    /// \param w The CWindow instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_null_CWindow_proxy(CWindow const &w)
    {
        int length  =   (NULL == w.m_hWnd) ? 0 : w.GetWindowTextLength();

        if(length == 0)
        {
            m_buffer = NULL;
        }
        else
        {
            m_buffer = string_maker_type::alloc(length);

            if(NULL != m_buffer)
            {
                w.GetWindowText(m_buffer, length + 1);
            }
        }
    }

#ifdef __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_ptr_null_CWindow_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = 0;
    }
#else /* ? __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_null_CWindow_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_null_CWindow_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// NULL if the window contains no text.
    operator LPCTSTR () const
    {
        return m_buffer;
    }

// Members
private:
    LPTSTR  m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};

/// This class provides an intermediary object that may be returned by the
/// c_str_ptr() function, such that the window text of a given window may be
/// accessed as a null-terminated string.
class c_str_ptr_CWindow_proxy
{
private:
    typedef cstring_maker<TCHAR>        string_maker_type;
    typedef c_str_ptr_CWindow_proxy     class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWindow instance
    ///
    /// \param w The CWindow instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_CWindow_proxy(CWindow const &w)
    {
        int length  =   (NULL == w.m_hWnd) ? 0 : w.GetWindowTextLength();

        if(length == 0)
        {
            m_buffer = string_maker_type::dup("");
        }
        else
        {
            m_buffer = string_maker_type::alloc(length);

            if(NULL != m_buffer)
            {
                w.GetWindowText(m_buffer, length + 1);
            }
        }
    }

#ifdef __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_ptr_CWindow_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = 0;
    }
#else /* ? __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_CWindow_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* __STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_CWindow_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator LPCTSTR () const
    {
        return (NULL == m_buffer) ? "" : m_buffer;
    }

// Members
protected:
    LPTSTR  m_buffer;

// Not to be implemented
protected:
    void operator =(class_type const &rhs);
};
#endif /* __ATLWIN_H__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Equivalence testing
 */

#ifdef __ATLWIN_H__
inline as_bool_t operator ==(LPCTSTR lhs, c_str_ptr_null_CWindow_proxy const &rhs)
{
    return lhs == static_cast<LPCTSTR>(rhs);
}

inline as_bool_t operator ==(c_str_ptr_null_CWindow_proxy const &lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) == rhs;
}

inline as_bool_t operator !=(LPCTSTR lhs, c_str_ptr_null_CWindow_proxy const &rhs)
{
    return lhs != static_cast<LPCTSTR>(rhs);
}

inline as_bool_t operator !=(c_str_ptr_null_CWindow_proxy const &lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) != rhs;
}
#endif /* __ATLWIN_H__ */

/* /////////////////////////////////////////////////////////////////////////////
 * IOStream compatibility
 */

#ifdef __ATLWIN_H__
template<ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_null_CWindow_proxy const &shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

template <ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_CWindow_proxy const &shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}
#endif /* __ATLWIN_H__ */

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* CWindow */
#ifdef __ATLWIN_H__
/// \brief Returns the corresponding C-string pointer of the CWindow \c w, or a null pointer
inline c_str_ptr_null_CWindow_proxy c_str_ptr_null(atlstl_ns_qual_atl(CWindow) const &w)
{
    return c_str_ptr_null_CWindow_proxy(w);
}
#endif /* __ATLWIN_H__ */

/* CComBSTR */
/// \brief Returns the corresponding C-string pointer of the CComBSTR \c s, or a null pointer
inline LPCOLESTR c_str_ptr_null(atlstl_ns_qual_atl(CComBSTR) const &s)
{
    /* NULL is a valid BSTR value, so may return that */
    return s.m_str;
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWindow */
#ifdef __ATLWIN_H__
/// \brief Returns the corresponding C-string pointer of the text of the CWindow \c w
inline c_str_ptr_CWindow_proxy c_str_ptr(atlstl_ns_qual_atl(CWindow) const &w)
{
    return c_str_ptr_CWindow_proxy(w);
}
#endif /* __ATLWIN_H__ */

/* CComBSTR */
/// \brief Returns the corresponding C-string pointer of the CComBSTR \c s
inline LPCOLESTR c_str_ptr(atlstl_ns_qual_atl(CComBSTR) const &s)
{
    /* NULL is a valid BSTR value, so check for that */
    return (s.m_str != 0) ? s.m_str : L"";
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWindow */
#ifdef __ATLWIN_H__
/// \brief Returns the corresponding possibly un-terminated C-string pointer of the text of the CWindow \c w
inline c_str_ptr_CWindow_proxy c_str_data(atlstl_ns_qual_atl(CWindow) const &w)
{
    return c_str_ptr(w);
}
#endif /* __ATLWIN_H__ */

/// \brief Returns the corresponding possibly un-terminated C-string pointer of the CComBSTR \c s
inline LPCOLESTR c_str_data(atlstl_ns_qual_atl(CComBSTR) const &s)
{
    return c_str_ptr(s);
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* CWindow */
#ifdef __ATLWIN_H__
/// \brief Returns the length (in characters) of the contents of the window \c w, <b><i>not</i></b> including the null-terminating character
inline as_size_t c_str_len(atlstl_ns_qual_atl(CWindow) const &w)
{
    return static_cast<as_size_t>(w.GetWindowTextLength());
}
#endif /* __ATLWIN_H__ */

/* CComBSTR */
/// \brief Returns the length (in characters) of the CComBSTR \c s, <b><i>not</i></b> including the null-terminating character
inline as_size_t c_str_len(atlstl_ns_qual_atl(CComBSTR) const &s)
{
    return s.Length();
}

/* /////////////////////////////////////////////////////////////////////////////
 * c_str_size
 *
 * This can be applied to an expression, and the return value is the number of
 * bytes required to store the character string in the expression, NOT including
 * the null-terminating character.
 */

/* CWindow */
#ifdef __ATLWIN_H__
/// \brief Returns the size (in bytes) of the contents of the window \c w, <b><i>not</i></b> including the null-terminating character
inline as_size_t c_str_size(atlstl_ns_qual_atl(CWindow) const &w)
{
    return c_str_len(w) * sizeof(TCHAR);
}
#endif /* __ATLWIN_H__ */

/* CComBSTR */
/// \brief Returns the size (in bytes) of the CComBSTR \c s, <b><i>not</i></b> including the null-terminating character
inline as_size_t c_str_size(atlstl_ns_qual_atl(CComBSTR) const &s)
{
    return c_str_len(s) * sizeof(OLECHAR);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group atlstl_string_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ATLSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace atlstl
# else
} // namespace stlsoft::atlstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _ATLSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::atlstl::c_str_ptr_null;

using ::atlstl::c_str_ptr;

using ::atlstl::c_str_data;

using ::atlstl::c_str_len;

using ::atlstl::c_str_size;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Global namespace shims
 */

#if 0
/* Alas, this one has to die, because CComBSTR has implicit constructors, which result in conflicts. */
template<ss_typename_param_k S>
inline S &operator <<(S &s, CComBSTR const &shim)
{
    s << stlsoft_ns_qual(c_str_ptr)(shim);

    return s;
}
#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
