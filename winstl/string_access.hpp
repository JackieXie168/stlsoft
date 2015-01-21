/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/string_access.hpp (formerly winstl_string_access.h)
 *
 * Purpose:     Contains classes and functions for dealing with Win32 strings.
 *
 * Created:     24th May 2002
 * Updated:     10th June 2006
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


/// \file winstl/string_access.hpp
///
/// Contains classes and functions for dealing with Win32 strings.

#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
#define WINSTL_INCL_WINSTL_HPP_STRING_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_STRING_ACCESS_MAJOR      3
# define WINSTL_VER_WINSTL_HPP_STRING_ACCESS_MINOR      3
# define WINSTL_VER_WINSTL_HPP_STRING_ACCESS_REVISION   3
# define WINSTL_VER_WINSTL_HPP_STRING_ACCESS_EDIT       97
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_H_WINDOW_FUNCTIONS
# include <winstl/window_functions.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINDOW_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_HPP_WINDOWS_IDENT
# include <winstl/windows_ident.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOWS_IDENT */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */

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

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline ws_size_t GetWindowTextLength__(HWND hwnd)
{
    WindowIdent ident   =   GetWindowIdent(hwnd);
    int         sel;

    switch(ident)
    {
        case    ListBox:
            if(0 == (GetStyle(hwnd) & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)))
            {
                sel = static_cast<int>(::SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if(LB_ERR != sel)
                {
                    return static_cast<ws_size_t>(::SendMessage(hwnd, LB_GETTEXTLEN, static_cast<WPARAM>(sel), 0L));
                }
                else
                {
                    return 0;
                }
            }
            break;
#if 0
        case    ListBox:
            if(1 == SendMessage(hwnd, LVM_GETSELECTEDCOUNT, 0, 0L))
            {
                sel =
            }
            break;
#endif /* 0 */
        case    Generic:
        case    ComboBox:
        case    ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(::GetWindowTextLength(hwnd));
}

inline ws_size_t GetWindowTextA__(HWND hwnd, ws_char_a_t *buffer, ws_size_t cchBuffer)
{
    WindowIdent ident   =   GetWindowIdent(hwnd);
    int         sel;
    ws_size_t      cch;

    switch(ident)
    {
        case    ListBox:
            if(0 == (GetStyle(hwnd) & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)))
            {
                sel = static_cast<int>(::SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if(LB_ERR != sel)
                {
                    cch =   static_cast<ws_size_t>(::SendMessage(hwnd, LB_GETTEXT, static_cast<WPARAM>(sel), reinterpret_cast<LPARAM>(buffer)));

                    // Some programs using list-boxes do not null-terminate - Visual
                    // SourceSafe Explorer, anyone? - so we must do so here.
                    buffer[cch] = '\0';
                }
                else
                {
                    buffer[0] = '\0';

                    cch = 0;
                }

                WINSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

                return cch;
            }
            break;
        case    Generic:
        case    ComboBox:
        case    ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(::GetWindowTextA(hwnd, buffer, static_cast<int>(cchBuffer)));
}

inline ws_size_t GetWindowTextW__(HWND hwnd, ws_char_w_t *buffer, ws_size_t cchBuffer)
{
    WindowIdent ident   =   GetWindowIdent(hwnd);
    int         sel;

    switch(ident)
    {
        case    ListBox:
            if(0 == (GetStyle(hwnd) & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)))
            {
                ws_size_t  cch;

                sel = static_cast<int>(::SendMessage(hwnd, LB_GETCURSEL, 0, 0l));

                if(LB_ERR != sel)
                {
                    cch =   static_cast<ws_size_t>(::SendMessage(hwnd, LB_GETTEXT, static_cast<WPARAM>(sel), reinterpret_cast<LPARAM>(buffer)));
                }
                else
                {
                    buffer[0] = '\0';

                    cch = 0;
                }

                WINSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

                return cch;
            }
            break;
        case    Generic:
        case    ComboBox:
        case    ListView:
        default:
            break;
    }

    return static_cast<ws_size_t>(::GetWindowTextW(hwnd, buffer, static_cast<int>(cchBuffer)));
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/* HWND */
/// This class provides an intermediary object that may be returned by the
/// c_str_ptr_null() function, such that the window text of a given window may be
/// accessed as a null-terminated string.
template <ss_typename_param_k C>
class c_str_ptr_null_HWND_proxy
{
    typedef cstring_maker<C>                            string_maker_type;
public:
    typedef C                                           char_type;
    typedef c_str_ptr_null_HWND_proxy<C>                class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given HWND
    ///
    /// \param h The HWND from which the text will be retrieved
    ss_explicit_k c_str_ptr_null_HWND_proxy(HWND h)
    {
        ws_size_t length  =   GetWindowTextLength__(h);

        if(length == 0)
        {
            m_buffer = NULL;
        }
        else
        {
            m_buffer = string_maker_type::alloc(length);

            if(NULL != m_buffer)
            {
                get_window_text(h, m_buffer, length + 1);
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
    c_str_ptr_null_HWND_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        move_lhs_from_rhs(rhs).m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_null_HWND_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_null_HWND_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator char_type const *() const
    {
        return m_buffer;
    }

// Implementation
private:
    ws_size_t get_window_text(HWND h, char_type *buffer, ws_size_t cchBuffer);

// Members
private:
    char_type   *m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
inline ws_size_t c_str_ptr_null_HWND_proxy<ws_char_a_t>::get_window_text(HWND h, ws_char_a_t *buffer, ws_size_t cchBuffer)
{
    return GetWindowTextA__(h, buffer, cchBuffer);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ws_size_t c_str_ptr_null_HWND_proxy<ws_char_w_t>::get_window_text(HWND h, ws_char_w_t *buffer, ws_size_t cchBuffer)
{
    return GetWindowTextW__(h, buffer, cchBuffer);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// This class provides an intermediary object that may be returned by the
/// c_str_ptr() function, such that the window text of a given window may be
/// accessed as a null-terminated string.
template <ss_typename_param_k C>
class c_str_ptr_HWND_proxy
{
    typedef cstring_maker<C>                            string_maker_type;
public:
    typedef C                                           char_type;
    typedef c_str_ptr_HWND_proxy<C>                     class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given HWND
    ///
    /// \param h The HWND from which the text will be retrieved
    ss_explicit_k c_str_ptr_HWND_proxy(HWND h)
    {
        ws_size_t length  =   GetWindowTextLength__(h);

        m_buffer = string_maker_type::alloc(length);

        if(NULL != m_buffer)
        {
            get_window_text(h, m_buffer, length + 1);
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
    c_str_ptr_HWND_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        move_lhs_from_rhs(rhs).m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_HWND_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_HWND_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator char_type const *() const
    {
        static char_type    s_ch[1] = { '\0' };

        return (NULL == m_buffer) ? s_ch : m_buffer;
    }

// Implementation
private:
    ws_size_t get_window_text(HWND h, char_type *buffer, ws_size_t cchBuffer);

// Members
private:
    char_type   *m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
inline ws_size_t c_str_ptr_HWND_proxy<ws_char_a_t>::get_window_text(HWND h, ws_char_a_t *buffer, ws_size_t cchBuffer)
{
    return GetWindowTextA__(h, buffer, cchBuffer);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline ws_size_t c_str_ptr_HWND_proxy<ws_char_w_t>::get_window_text(HWND h, ws_char_w_t *buffer, ws_size_t cchBuffer)
{
    return GetWindowTextW__(h, buffer, cchBuffer);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* Windows Policy Management LSA_UNICODE_STRING string */
#ifdef _NTSECAPI_
/// This class provides an intermediary object that may be returned by the
/// c_str_ptr_null() function, such that the text of a given LSA_UNICODE_STRING
/// string may be accessed as a null-terminated string.
class c_str_ptr_LSA_UNICODE_STRING_proxy
{
    typedef cstring_maker<WCHAR>                string_maker_type;
public:
    typedef c_str_ptr_LSA_UNICODE_STRING_proxy  class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given LSA_UNICODE_STRING instance
    ///
    /// \param s The LSA_UNICODE_STRING instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_LSA_UNICODE_STRING_proxy(const LSA_UNICODE_STRING &s)
        : m_buffer(string_maker_type::alloc(s.Length))
    {
        if(NULL != m_buffer)
        {
            wcsncpy(m_buffer, s.Buffer, s.Length);
            m_buffer[s.Length] = L'\0';
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
    c_str_ptr_LSA_UNICODE_STRING_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_LSA_UNICODE_STRING_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_LSA_UNICODE_STRING_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the string contents, or
    /// the empty string "" if the string has no contents.
    operator LPCWSTR () const
    {
        return m_buffer;
    }

// Members
private:
    LPWSTR  m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};
#endif /* _NTSECAPI_ */

#ifdef _NTSECAPI_
/// This class provides an intermediary object that may be returned by the
/// c_str_ptr_null() function, such that the text of a given LSA_UNICODE_STRING
/// string may be accessed as a null-terminated string.
class c_str_ptr_null_LSA_UNICODE_STRING_proxy
{
    typedef cstring_maker<WCHAR>                    string_maker_type;
public:
    typedef c_str_ptr_null_LSA_UNICODE_STRING_proxy class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given LSA_UNICODE_STRING instance
    ///
    /// \param s The LSA_UNICODE_STRING instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_null_LSA_UNICODE_STRING_proxy(const LSA_UNICODE_STRING &s)
        : m_buffer((s.Length != 0) ? string_maker_type::alloc(s.Length) : NULL)
    {
        if(m_buffer != NULL)
        {
            wcsncpy(m_buffer, s.Buffer, s.Length);
            m_buffer[s.Length] = L'\0';
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
    c_str_ptr_null_LSA_UNICODE_STRING_proxy(class_type &rhs)
        : m_buffer(rhs.m_buffer)
    {
        rhs.m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_ptr_null_LSA_UNICODE_STRING_proxy(class_type const &rhs)
        : m_buffer(string_maker_type::dup_null(rhs.m_buffer))
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage aquired by the proxy
    ~c_str_ptr_null_LSA_UNICODE_STRING_proxy() stlsoft_throw_0()
    {
        string_maker_type::free(m_buffer);
    }

// Accessors
public:
    /// Returns a null-terminated string representing the string contents, or
    /// NULL if the string has no contents.
    operator LPCWSTR () const
    {
        return m_buffer;
    }

// Members
private:
    LPWSTR  m_buffer;

// Not to be implemented
private:
    void operator =(class_type const &rhs);
};
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * IOStream compatibility
 */

template<   ss_typename_param_k C
        ,   ss_typename_param_k S
        >
inline S &operator <<(S & s, c_str_ptr_null_HWND_proxy<C> const &shim)
{
    s << static_cast<C const *>(shim);

    return s;
}

template<   ss_typename_param_k C
        ,   ss_typename_param_k S
        >
inline S &operator <<(S & s, c_str_ptr_HWND_proxy<C> const &shim)
{
    s << static_cast<C const *>(shim);

    return s;
}

#ifdef _NTSECAPI_
template<ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_LSA_UNICODE_STRING_proxy const &shim)
{
    s << static_cast<LPCWSTR>(shim);

    return s;
}

template<ss_typename_param_k S>
inline S &operator <<(S & s, c_str_ptr_null_LSA_UNICODE_STRING_proxy const &shim)
{
    s << static_cast<LPCWSTR>(shim);

    return s;
}
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* HWND */
/// \brief Returns the corresponding C-string pointer of the window \c h, or a null pointer
inline c_str_ptr_null_HWND_proxy<ws_char_a_t> c_str_ptr_null_a(HWND h)
{
    return c_str_ptr_null_HWND_proxy<ws_char_a_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h, or a null pointer
inline c_str_ptr_null_HWND_proxy<ws_char_w_t> c_str_ptr_null_w(HWND h)
{
    return c_str_ptr_null_HWND_proxy<ws_char_w_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h, or a null pointer
inline c_str_ptr_null_HWND_proxy<TCHAR> c_str_ptr_null(HWND h)
{
    return c_str_ptr_null_HWND_proxy<TCHAR>(h);
}

/* LSA_UNICODE_STRING */
#ifdef _NTSECAPI_
/// \brief Returns the corresponding C-string pointer of the LSA_UNICODE_STRING \c s, or a null pointer
inline c_str_ptr_null_LSA_UNICODE_STRING_proxy c_str_ptr_null(const LSA_UNICODE_STRING &s)
{
    return c_str_ptr_null_LSA_UNICODE_STRING_proxy(s);
}
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* HWND */
/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<ws_char_a_t> c_str_ptr_a(HWND h)
{
    return c_str_ptr_HWND_proxy<ws_char_a_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<ws_char_w_t> c_str_ptr_w(HWND h)
{
    return c_str_ptr_HWND_proxy<ws_char_w_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<TCHAR> c_str_ptr(HWND h)
{
    return c_str_ptr_HWND_proxy<TCHAR>(h);
}

/* LSA_UNICODE_STRING */
#ifdef _NTSECAPI_
/// \brief Returns the corresponding C-string pointer of the LSA_UNICODE_STRING \c s
inline c_str_ptr_LSA_UNICODE_STRING_proxy c_str_ptr(const LSA_UNICODE_STRING &s)
{
    return c_str_ptr_LSA_UNICODE_STRING_proxy(s);
}
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<ws_char_a_t> c_str_data_a(HWND h)
{
    return c_str_ptr_HWND_proxy<ws_char_a_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<ws_char_w_t> c_str_data_w(HWND h)
{
    return c_str_ptr_HWND_proxy<ws_char_w_t>(h);
}

/// \brief Returns the corresponding C-string pointer of the window \c h
inline c_str_ptr_HWND_proxy<TCHAR> c_str_data(HWND h)
{
    return c_str_ptr_HWND_proxy<TCHAR>(h);
}

/* LSA_UNICODE_STRING */
#ifdef _NTSECAPI_
/// \brief Returns the corresponding potentially unterminated C-string pointer of the LSA_UNICODE_STRING \c s
inline LPCWSTR c_str_data(const LSA_UNICODE_STRING &s)
{
    return s.Buffer;    /
}
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* HWND */
/// \brief Returns the length (in characters) of the string of \c s, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_len(HWND h)
{
    return GetWindowTextLength__(h);
}

/// \brief Returns the length (in characters) of the string of \c s, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_len_a(HWND h)
{
    return c_str_len(h);
}

/// \brief Returns the length (in characters) of the string of \c s, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_len_w(HWND h)
{
    return c_str_len(h);
}

/* LSA_UNICODE_STRING */
#ifdef _NTSECAPI_
/// \brief Returns the length (in characters) of the LSA_UNICODE_STRING \c s, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_len(const LSA_UNICODE_STRING &s)
{
    return s.Length;
}
#endif /* _NTSECAPI_ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_size
 *
 * This can be applied to an expression, and the return value is the number of
 * bytes required to store the character string in the expression, NOT including
 * the null-terminating character.
 */

/* HWND */
#if 0
/// \brief Returns the size (in bytes) of the string of \c h, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_size_a(HWND h)
{
    return c_str_len(h) * sizeof(ws_char_a_t);
}
#endif /* 0 */

#if 0
/// \brief Returns the size (in bytes) of the string of \c h, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_size_w(HWND h)
{
    return c_str_len(h) * sizeof(ws_char_w_t);
}
#endif /* 0 */

#if 0
/// \brief Returns the size (in bytes) of the string of \c h, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_size(HWND h)
{
    return c_str_len(h) * sizeof(TCHAR);
}
#endif /* 0 */

/* LSA_UNICODE_STRING */
#ifdef _NTSECAPI_
#if 0
/// \brief Returns the size (in bytes) of the LSA_UNICODE_STRING \c s, <b><i>not</i></b> including the null-terminating character
inline ws_size_t c_str_size(const LSA_UNICODE_STRING &s)
{
    return c_str_len(s) * sizeof(WCHAR);
}
#endif /* 0 */
#endif /* _NTSECAPI_ */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_access_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace stlsoft::winstl_project
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

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

#if 0
using ::winstl::c_str_size;
using ::winstl::c_str_size_a;
using ::winstl::c_str_size_w;
#endif /* 0 */

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

/* ////////////////////////////////////////////////////////////////////// */
