/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/clipboard/clipboard_scope.hpp (originally winstl/clipboard_scope.hpp)
 *
 * Purpose:     Clipboard scoping and facade class.
 *
 * Created:     26th May 2005
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/clipboard/clipboard_scope.hpp
 *
 * \brief [C++ only] Definition of the winstl::clipboard_scope class.
 *  (\ref group__library__windows_clipboard "Windows Clipboard" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE
#define WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_MAJOR      2
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_MINOR      0
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_REVISION   1
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE_EDIT       18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_CLIPBOARD_HPP_EXCEPTIONS
# include <winstl/clipboard/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_CLIPBOARD_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_GLOBAL_ALLOCATOR
# include <winstl/memory/global_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_GLOBAL_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS
# include <stlsoft/string/cstring_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS */

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
 * Classes
 */

/** \brief Exception thrown by the clipboard_scope class
 *
 * \ingroup group__library__windows_clipboard
 */
class clipboard_scope_exception
    : public clipboard_exception
{
/// \name Member Types
/// @{
public:
    typedef clipboard_exception         parent_class_type;
    typedef clipboard_scope_exception   class_type;
/// @}

/// \name Construction
/// @{
public:
    clipboard_scope_exception(char const *reason, error_code_type err)
        : clipboard_exception(reason, err)
    {}
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}

};

/** \brief This class acquires access to the Win32 clipboard, and acts as
 *   a facade over the clipboard API.
 *
 * \ingroup group__library__windows_clipboard
 *
 * The class provides a simple and straightforward facade to the clipboard,
 * while at the same time acquiring and releasing ownership of the
 * clipboard. The following code acquires access to the clipboard, and sets
 * a string on to it:
\htmlonly
<pre>
  // 1. Set the data on the clipboard
  {
    winstl::clipboard_scope     scope;

    scope.set_data("The data");
  }
</pre>
\endhtmlonly
 *
 * As long as no other thread/process changes the clipboard contents in the
 * meanwhile, this can then be read back, as follows:
 *
\htmlonly
<pre>
  // 2. Get the data from the clipboard
  {
    winstl::clipboard_scope     scope;
    char const                  *str;

    scope.get_data(str);

    std::cout << "Clipboard data: " << str << std::endl;

    scope.get_allocator().deallocate(str);
  }
</pre>
\endhtmlonly
 *
 * In each case, the lifetime of the
 * \link winstl::clipboard_scope clipboard_scope\endlink is scoped with a
 * block - <code>{ }</code> - in order to release ownership of the
 * clipboard.
 *
 * \note All the methods throw an instance of
 *  \link winstl::clipboard_scope_exception clipboard_scope_exception\endlink
 *  if they fail.
 */
class clipboard_scope
#if defined(STLSOFT_COMPILER_IS_DMC)
    : protected global_allocator<void>
#else /* ? compiler */
    : private global_allocator<void>
#endif /* compiler */
{
/// \name Types
/// @{
private:
    typedef global_allocator<void>  parent_class_type;
public:
    typedef clipboard_scope         class_type;
    typedef global_allocator<void>  allocator_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Takes ownership of the clipboard
    ///
    /// \param hwndOwner Window to be associated as owner of the clipboard.
    ///  May be NULL, in which case the current thread owns the clipboard.
    ss_explicit_k clipboard_scope(HWND hwndOwner = NULL) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Gives up ownership of the clipboard.
    ~clipboard_scope() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Returns a copy of the allocator used by the class.
    allocator_type  get_allocator() const;
/// @}

/// \name Operations
/// @{
public:
    /// \brief Empties the clipboard.
    void    clear() stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Returns the current owner of the clipboard.
    HWND    owner() const;

    /// \brief Indicates whether a given format is available.
    ws_bool_t   is_fmt_available(UINT fmt) const;

    /// \brief Sets the given data with the given format into the clipboard.
    void    set_data(UINT fmt, HANDLE hData) stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Sets the given text to the clipboard with CF_TEXT format.
    void    set_data(char const *str) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Sets the given text to the clipboard with CF_TEXT format.
    void    set_data(char const *str, size_t n) stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Sets the given text to the clipboard with CF_UNICODETEXT format.
    void    set_data(wchar_t const *str) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Sets the given text to the clipboard with CF_UNICODETEXT format.
    void    set_data(wchar_t const *str, size_t n) stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Sets the bitmap to the clipboard with CF_BITMAP format.
    void    set_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Sets the bitmap to the clipboard with CF_HDROP format.
    void    set_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Sets the bitmap to the clipboard with CF_ENHMETAFILE format.
    void    set_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Sets the bitmap to the clipboard with CF_PALETTE format.
    void    set_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Gets the data with the requested format from the clipboard
    HANDLE  get_data(UINT fmt) const stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Gets the clipboard data with the CF_TEXT format.
    void    get_data(char const *&str) const stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Gets the clipboard data with the CF_UNICODETEXT format.
    void    get_data(wchar_t const *&str) const stlsoft_throw_1(clipboard_scope_exception );

    /// \brief Gets the clipboard data with the CF_BITMAP format.
    void    get_data(HBITMAP &hBmp) const stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Gets the clipboard data with the CF_HDROP format.
    void    get_data(HDROP &hDrop) const stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Gets the clipboard data with the CF_ENHMETAFILE format.
    void    get_data(HENHMETAFILE &hEmf) const stlsoft_throw_1(clipboard_scope_exception );
    /// \brief Gets the clipboard data with the CF_PALETTE format.
    void    get_data(HPALETTE &hPal) const stlsoft_throw_1(clipboard_scope_exception );
/// @}

/// \name Members
/// @{
private:
    clipboard_scope(class_type const &);
    class_type &operator =(class_type const &);
/// @}
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/clipboard_scope_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */



/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline clipboard_scope::clipboard_scope(HWND hwndOwner /* = NULL */) stlsoft_throw_1(clipboard_scope_exception )
{
    if(!::OpenClipboard(hwndOwner))
    {
        throw clipboard_scope_exception("Cannot open clipboard", ::GetLastError());
    }
}

inline clipboard_scope::~clipboard_scope() stlsoft_throw_0()
{
    ::CloseClipboard();
}

inline clipboard_scope::allocator_type clipboard_scope::get_allocator() const
{
    const allocator_type    &ator   =   *this;

    return ator;
}

inline void clipboard_scope::clear() stlsoft_throw_1(clipboard_scope_exception )
{
    if(!::EmptyClipboard())
    {
        throw clipboard_scope_exception("Cannot empty clipboard", ::GetLastError());
    }
}

inline HWND clipboard_scope::owner() const
{
    HWND    hwnd    =   ::GetClipboardOwner();

    if( NULL == hwnd &&
        ERROR_SUCCESS != ::GetLastError())
    {
        throw clipboard_scope_exception("Cannot get clipboard owner", ::GetLastError());
    }

    return hwnd;
}

inline ws_bool_t clipboard_scope::is_fmt_available(UINT fmt) const
{
    return BOOL2bool(::IsClipboardFormatAvailable(fmt));
}

inline void clipboard_scope::set_data(UINT fmt, HANDLE hData) stlsoft_throw_1(clipboard_scope_exception )
{
    if(NULL == ::SetClipboardData(fmt, hData))
    {
        throw clipboard_scope_exception("Cannot set clipboard data", ::GetLastError());
    }
}

inline void clipboard_scope::set_data(char const *str) stlsoft_throw_1(clipboard_scope_exception )
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<char>::other     ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<char>                  ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    set_data(CF_TEXT, stlsoft_ns_qual(string_dup)(str, ator));
}

inline void clipboard_scope::set_data(char const *str, size_t n) stlsoft_throw_1(clipboard_scope_exception )
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<char>::other     ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<char>                  ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    set_data(CF_TEXT, stlsoft_ns_qual(string_dup)(str, n, ator));
}

inline void clipboard_scope::set_data(wchar_t const *str) stlsoft_throw_1(clipboard_scope_exception )
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<wchar_t>::other  ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<wchar_t>               ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    set_data(CF_UNICODETEXT, stlsoft_ns_qual(string_dup)(str, ator));
}

inline void clipboard_scope::set_data(wchar_t const *str, size_t n) stlsoft_throw_1(clipboard_scope_exception )
{
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    allocator_type::rebind<wchar_t>::other  ator(*this);
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    global_allocator<wchar_t>               ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    set_data(CF_UNICODETEXT, stlsoft_ns_qual(string_dup)(str, n, ator));
}

inline void clipboard_scope::set_data(HBITMAP hBmp) stlsoft_throw_1(clipboard_scope_exception )
{
    set_data(CF_BITMAP, hBmp);
}

inline void clipboard_scope::set_data(HDROP hDrop) stlsoft_throw_1(clipboard_scope_exception )
{
    set_data(CF_HDROP, hDrop);
}

inline void clipboard_scope::set_data(HENHMETAFILE hEmf) stlsoft_throw_1(clipboard_scope_exception )
{
    set_data(CF_ENHMETAFILE, hEmf);
}

inline void clipboard_scope::set_data(HPALETTE hPal) stlsoft_throw_1(clipboard_scope_exception )
{
    set_data(CF_PALETTE, hPal);
}

inline HANDLE clipboard_scope::get_data(UINT fmt) const stlsoft_throw_1(clipboard_scope_exception )
{
    HANDLE  hData   =   ::GetClipboardData(fmt);

    if( NULL == hData &&
        ERROR_SUCCESS != ::GetLastError())
    {
        throw clipboard_scope_exception("Cannot get clipboard data", ::GetLastError());
    }

    return hData;
}

inline void clipboard_scope::get_data(char const *&str) const stlsoft_throw_1(clipboard_scope_exception )
{
    str = static_cast<char const*>(get_data(CF_TEXT));
}

inline void clipboard_scope::get_data(wchar_t const *&str) const stlsoft_throw_1(clipboard_scope_exception )
{
    str = static_cast<wchar_t const*>(get_data(CF_UNICODETEXT));
}

inline void clipboard_scope::get_data(HBITMAP &hBmp) const stlsoft_throw_1(clipboard_scope_exception )
{
    hBmp = static_cast<HBITMAP>(get_data(CF_BITMAP));
}

inline void clipboard_scope::get_data(HDROP &hDrop) const stlsoft_throw_1(clipboard_scope_exception )
{
    hDrop = static_cast<HDROP>(get_data(CF_HDROP));
}

inline void clipboard_scope::get_data(HENHMETAFILE &hEmf) const stlsoft_throw_1(clipboard_scope_exception )
{
    hEmf = static_cast<HENHMETAFILE>(get_data(CF_ENHMETAFILE));
}

inline void clipboard_scope::get_data(HPALETTE &hPal) const stlsoft_throw_1(clipboard_scope_exception )
{
    hPal = static_cast<HPALETTE>(get_data(CF_PALETTE));
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE */

/* ////////////////////////////////////////////////////////////////////// */