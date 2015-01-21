/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/string_access.hpp (formerly mfcstl_string_access.h)
 *
 * Purpose:     Contains classes and functions for dealing with MFC strings.
 *
 * Created:     24th May 2002
 * Updated:     7th July 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file mfcstl/string_access.hpp
///
/// Contains classes and functions for dealing with MFC strings.

#ifndef MFCSTL_INCL_MFCSTL_HPP_STRING_ACCESS
#define MFCSTL_INCL_MFCSTL_HPP_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_HPP_STRING_ACCESS_MAJOR      3
# define MFCSTL_VER_MFCSTL_HPP_STRING_ACCESS_MINOR      3
# define MFCSTL_VER_MFCSTL_HPP_STRING_ACCESS_REVISION   4
# define MFCSTL_VER_MFCSTL_HPP_STRING_ACCESS_EDIT       76
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
# include <stlsoft/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn -8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

#include <afxwin.h>     // for CWnd, CListBox
#if !defined(__AFXCMN_H__) && \
    !defined(MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN)
# include <afxcmn.h>    // for CListCtrl
#endif /* !__AFXCMN_H__ && !MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN */
#if !defined(__AFXCVIEW_H__) && \
    !defined(MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCVIEW)
# include <afxcview.h> // for CListView
#endif /* !__AFXCVIEW_H__ && !MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn .8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */

namespace stlsoft
{

namespace mfcstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline ms_size_t GetWindowTextLength__(CWnd const &w)
{
    return (NULL != w.m_hWnd) ? static_cast<ms_size_t>(w.GetWindowTextLength()) : 0;
}

inline ms_size_t GetWindowText__(CWnd const &w, LPTSTR buffer, ms_size_t cchBuffer)
{
    MFCSTL_ASSERT(NULL != w.m_hWnd);

    return static_cast<ms_size_t>(w.GetWindowText(buffer, cchBuffer));
}


inline ms_size_t GetWindowTextLength__(CListBox const &w)
{
    int sel;

    if( 0 == (w.GetStyle() & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)) &&
        LB_ERR != (sel = w.GetCurSel()))
    {
        return static_cast<ms_size_t>(w.GetTextLen(sel));
    }
    else
    {
        return static_cast<ms_size_t>(w.GetWindowTextLength());
    }
}

inline ms_size_t GetWindowText__(CListBox const &w, LPTSTR buffer, ms_size_t cchBuffer)
{
    int sel = -1;

    if( 0 == (w.GetStyle() & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)) &&
        LB_ERR != (sel = w.GetCurSel()))
    {
        ms_size_t cch = static_cast<ms_size_t>(w.GetText(sel, buffer));

        MFCSTL_MESSAGE_ASSERT("Invalid item", LB_ERR != cch);
        MFCSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

        return static_cast<ms_size_t>(cch);
    }
    else
    {
        return w.GetWindowText(buffer, cchBuffer);
    }
}

#ifdef __AFXCMN_H__
# if _MFC_VER >= 0x0600
inline ms_size_t GetWindowTextLength__(CListCtrl const &w)
{
    if(1 == w.GetSelectedCount())
    {
        POSITION    pos =   w.GetFirstSelectedItemPosition();
        int         sel =   w.GetNextSelectedItem(pos);

        return static_cast<ms_size_t>(w.GetItemText(sel, 0).GetLength());
    }
    else
    {
        return static_cast<ms_size_t>(w.GetWindowTextLength());
    }
}

inline ms_size_t GetWindowText__(CListCtrl const &w, LPTSTR buffer, ms_size_t cchBuffer)
{
    if(1 == w.GetSelectedCount())
    {
        POSITION    pos =   w.GetFirstSelectedItemPosition();
        int         sel =   w.GetNextSelectedItem(pos);

        return static_cast<ms_size_t>(w.GetItemText(sel, 0, buffer, cchBuffer));
    }
    else
    {
        return w.GetWindowText(buffer, cchBuffer);
    }
}

#  ifdef __AFXCVIEW_H__
inline ms_size_t GetWindowTextLength__(CListView const &w)
{
    return GetWindowTextLength__(w.GetListCtrl());
}

inline ms_size_t GetWindowText__(CListView const &w, LPTSTR buffer, ms_size_t cchBuffer)
{
    return GetWindowText__(w.GetListCtrl(), buffer, cchBuffer);
}
#  endif /* __AFXCVIEW_H__ */
# endif /* _MFC_VER >= 0x0600 */
#endif /* __AFXCMN_H__ */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/* CWnd */

/** \brief This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the window text of a given window
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
class c_str_ptr_null_CWnd_proxy
{
    typedef TCHAR                       char_type;
    typedef cstring_maker<TCHAR>        string_maker_type;
public:
    typedef c_str_ptr_null_CWnd_proxy   class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWnd instance
    ///
    /// \param w The CWnd instance from which the text will be retrieved
    template<ss_typename_param_k W>
    c_str_ptr_null_CWnd_proxy(const W &w)
    {
        stlsoft_constraint_must_have_base(W, CWnd);

        ms_size_t length = GetWindowTextLength__(w);

        if(length == 0)
        {
            m_buffer = NULL;
        }
        else
        {
            m_buffer = string_maker_type::alloc(length);

            if(NULL != m_buffer)
            {
                GetWindowText__(w, m_buffer, length + 1);
            }
        }
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_ptr_null_CWnd_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_null_CWnd_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_null_CWnd_proxy() stlsoft_throw_0()
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

/** \brief This class provides an intermediary object that may be returned by the
 * c_str_ptr() function, such that the window text of a given window may be
 * accessed as a null-terminated string.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
class c_str_ptr_CWnd_proxy
{
    typedef TCHAR                   char_type;
    typedef cstring_maker<TCHAR>    string_maker_type;
private:
    typedef c_str_ptr_CWnd_proxy    class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWnd instance
    ///
    /// \param w The CWnd instance from which the text will be retrieved
    template<ss_typename_param_k W>
    c_str_ptr_CWnd_proxy(const W &w)
    {
        stlsoft_constraint_must_have_base(W, CWnd);

        ms_size_t length = GetWindowTextLength__(w);

        if(length == 0)
        {
            m_buffer = string_maker_type::dup(_T(""));
        }
        else
        {
            m_buffer = string_maker_type::alloc(length);

            if(NULL != m_buffer)
            {
                GetWindowText__(w, m_buffer, length + 1);
            }
        }
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_ptr_CWnd_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_CWnd_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_CWnd_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator LPCTSTR () const
    {
        static char_type    s_ch[1] = { '\0' };

        return (NULL == m_buffer) ? s_ch : m_buffer;
    }

// Implementation
private:
    // \note Does not need to worry about operator new() returning NULL
    static LPTSTR dup_(LPCTSTR s)
    {
        return lstrcpy(new TCHAR[1 + lstrlen(s)], s);
    }

// Members
private:
    LPTSTR  m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////
 * Equivalence testing
 */

inline ms_bool_t operator ==(LPCTSTR lhs, c_str_ptr_null_CWnd_proxy const &rhs)
{
    return lhs == static_cast<LPCTSTR>(rhs);
}

inline ms_bool_t operator ==(c_str_ptr_null_CWnd_proxy const &lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) == rhs;
}

inline ms_bool_t operator !=(LPCTSTR lhs, c_str_ptr_null_CWnd_proxy const &rhs)
{
    return lhs != static_cast<LPCTSTR>(rhs);
}

inline ms_bool_t operator !=(c_str_ptr_null_CWnd_proxy const &lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) != rhs;
}

/* /////////////////////////////////////////////////////////////////////////
 * IOStream compatibility
 */

template<ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_null_CWnd_proxy const &shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

template <ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_CWnd_proxy const &shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* CWnd */
/** \brief Returns the corresponding C-string pointer of the CWnd \c w, or a null pointer
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(const CWnd &w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(const CWnd &w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(const CWnd &w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(const CListBox &w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(const CListBox &w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(const CListBox &w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

#ifdef __AFXCMN_H__
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(const CListCtrl &w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(const CListCtrl &w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(const CListCtrl &w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

# ifdef __AFXCVIEW_H__
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(const CListView &w)
{
    return c_str_ptr_null(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(const CListView &w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(const CListView &w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* CString */
/** \brief Returns the corresponding C-string pointer of the CString \c s, or a null pointer
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline LPCTSTR c_str_ptr_null(const CString &s)
{
    /* CString always points to valid memory, whether its own
     * CStringData or afxEmptyString.m_pchData
     */
    return s.IsEmpty() ? NULL : (LPCTSTR)s;
}
#if defined(UNICODE)
inline LPCTSTR c_str_ptr_null_w(const CString &s)
#else /* ? UNICODE */
inline LPCTSTR c_str_ptr_null_w(const CString &s)
#endif /* UNICODE */
{
    return c_str_ptr_null(s);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWnd */
/** \brief Returns the corresponding C-string pointer of the CWnd \c w
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline c_str_ptr_CWnd_proxy c_str_ptr(const CWnd &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(const CWnd &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(const CWnd &w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

inline c_str_ptr_CWnd_proxy c_str_ptr(const CListBox &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(const CListBox &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(const CListBox &w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

#ifdef __AFXCMN_H__
inline c_str_ptr_CWnd_proxy c_str_ptr(const CListCtrl &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(const CListCtrl &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(const CListCtrl &w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

# ifdef __AFXCVIEW_H__
inline c_str_ptr_CWnd_proxy c_str_ptr(const CListView &w)
{
    return c_str_ptr(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(const CListView &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(const CListView &w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* CString */
/** \brief Returns the corresponding C-string pointer of the CString \c s
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline LPCTSTR c_str_ptr(const CString &s)
{
    /* CString always points to valid memory, whether its own
     * CStringData or afxEmptyString.m_pchData
     */
    return s;
}
#if defined(UNICODE)
inline LPCTSTR c_str_ptr_w(const CString &s)
#else /* ? UNICODE */
inline LPCTSTR c_str_ptr_a(const CString &s)
#endif /* UNICODE */
{
    return c_str_ptr(s);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWnd */
/** \brief Returns the corresponding C-string pointer of the CWnd \c w
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline c_str_ptr_CWnd_proxy c_str_data(const CWnd &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(const CWnd &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(const CWnd &w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

inline c_str_ptr_CWnd_proxy c_str_data(const CListBox &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(const CListBox &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(const CListBox &w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

#ifdef __AFXCMN_H__
inline c_str_ptr_CWnd_proxy c_str_data(const CListCtrl &w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(const CListCtrl &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(const CListCtrl &w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

# ifdef __AFXCVIEW_H__
inline c_str_ptr_CWnd_proxy c_str_data(const CListView &w)
{
    return c_str_data(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(const CListView &w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(const CListView &w)
#endif /* UNICODE */
{
    return c_str_data(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* CString */
/** \brief Returns the corresponding C-string pointer of the CString \c s
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline LPCTSTR c_str_data(const CString &s)
{
    /* CString always points to valid memory, whether its own
     * CStringData or afxEmptyString.m_pchData
     */
    return s;
}
#if defined(UNICODE)
inline LPCTSTR c_str_data_w(const CString &s)
#else /* ? UNICODE */
inline LPCTSTR c_str_data_a(const CString &s)
#endif /* UNICODE */
{
    return c_str_data(s);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* CWnd */
/** \brief Returns the length (in characters) of the contents of the window \c w, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline ms_size_t c_str_len(const CWnd &w)
{
    return GetWindowTextLength__(w);
}

inline ms_size_t c_str_len(const CListBox &w)
{
    return GetWindowTextLength__(w);
}

#ifdef __AFXCMN_H__
inline ms_size_t c_str_len(const CListCtrl &w)
{
    return GetWindowTextLength__(w);
}

# ifdef __AFXCVIEW_H__
inline ms_size_t c_str_len(const CListView &w)
{
    return c_str_len(w.GetListCtrl());
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* CString */
/** \brief Returns the length (in characters) of the CString \c s, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
inline ms_size_t c_str_len(const CString &s)
{
    return s.GetLength();
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _MFCSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace mfcstl
# else
} // namespace stlsoft::mfcstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _MFCSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::mfcstl::c_str_ptr_null;
#if defined(UNICODE)
using ::mfcstl::c_str_ptr_null_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_ptr_null_a;
#endif /* UNICODE */

using ::mfcstl::c_str_ptr;
#if defined(UNICODE)
using ::mfcstl::c_str_ptr_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_ptr_a;
#endif /* UNICODE */

using ::mfcstl::c_str_data;
#if defined(UNICODE)
using ::mfcstl::c_str_data_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_data_a;
#endif /* UNICODE */

using ::mfcstl::c_str_len;


# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Global namespace shims
 */

/* This defines an inserter function template for CString for use with the
 * Visual C++ <7.1 standard library.
 *
 * It cannot be defined as a template because that conflicts with operator << (CArchive &, CString const &)
 */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1

# include <iosfwd>

/* Has to be like this otherwise it conflicts with operator <<(class CArchive &,const class CString &) (at least with VC++ <7.1). */
inline mfcstl_ns_qual_std(basic_ostream)<TCHAR> &operator <<(mfcstl_ns_qual_std(basic_ostream)<TCHAR> &stm, CString const &shim)
{
    return stm << static_cast<LPCTSTR>(shim);
}

#endif /* library */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_MFCSTL_HPP_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////// */
