/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/functions.h (originally MWBase.h, ::SynesisWin)
 *
 * Purpose:     Window functions.
 *
 * Created:     7th May 2000
 * Updated:     16th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/window/functions.h
 *
 * \brief [C, C++] Miscellaneous functions.
 * (\ref group__library__windows_window "Windows Window" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_MAJOR     4
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_MINOR     0
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_REVISION  1
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_EDIT      52
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#if defined(__cplusplus)
#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_WINDOWS_TYPE_CONVERSIONS
# include <winstl/conversion/windows_type_conversions.hpp>
#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_WINDOWS_TYPE_CONVERSIONS */
#endif /* __cplusplus */

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
 * C functions
 */

STLSOFT_INLINE ws_long_t winstl__GetStyle(HWND h)
{
    return STLSOFT_NS_GLOBAL(GetWindowLong)(h, GWL_STYLE);
}

/** Gets the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_long_t winstl__GetExStyle(HWND h)
{
    return STLSOFT_NS_GLOBAL(GetWindowLong)(h, GWL_EXSTYLE);
}

/** Sets the style of the window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_long_t winstl__SetStyle(HWND h, ws_long_t s)
{
    return STLSOFT_NS_GLOBAL(SetWindowLong)(h, GWL_STYLE, stlsoft_static_cast(ws_long_t, s));
}

/** Sets the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_long_t winstl__SetExStyle(HWND h, ws_long_t x)
{
    return STLSOFT_NS_GLOBAL(SetWindowLong)(h, GWL_EXSTYLE, stlsoft_static_cast(ws_long_t, x));
}

/** Modifies the style of the window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_long_t winstl__ModifyStyle(HWND h, ws_long_t sRem, ws_long_t sAdd)
{
    return winstl__SetStyle(h, (winstl__GetStyle(h) & ~sRem) | sAdd);
}

/** Modifies the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_long_t winstl__ModifyExStyle(HWND h, ws_long_t sRem, ws_long_t sAdd)
{
    return winstl__SetExStyle(h, (winstl__GetExStyle(h) & ~sRem) | sAdd);
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_int_t winstl__IsWindowClassA(HWND hwnd, ws_char_a_t const *name)
{
    ws_char_a_t szName[256];

    WINSTL_ASSERT(NULL != hwnd);
    WINSTL_ASSERT(NULL != name);

    stlsoft_static_cast(void, STLSOFT_NS_GLOBAL(GetClassNameA)(hwnd, szName, STLSOFT_NUM_ELEMENTS(szName)));

    return 0 == STLSOFT_NS_GLOBAL(lstrcmpiA)(szName, name);
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_int_t winstl__IsWindowClassW(HWND hwnd, ws_char_w_t const *name)
{
    ws_char_w_t szName[256];

    WINSTL_ASSERT(NULL != hwnd);
    WINSTL_ASSERT(NULL != name);

    stlsoft_static_cast(void, STLSOFT_NS_GLOBAL(GetClassNameW)(hwnd, szName, STLSOFT_NUM_ELEMENTS(szName)));

    return 0 == STLSOFT_NS_GLOBAL(lstrcmpiW)(szName, name);
}

/** Enables/disable a dialog item
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE void winstl__EnableDlgItem(HWND hwnd, int id, ws_int_t bEnable)
{
    STLSOFT_NS_GLOBAL(EnableWindow)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id), bEnable);
}

/** Elicits the enable status of a dialog item
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_int_t winstl__IsDlgItemEnabled(HWND hwnd, int id)
{
    return STLSOFT_NS_GLOBAL(IsWindowEnabled)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id));
}

/** Gets the text length of a dialog item's window contents
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE ws_int_t winstl__GetDlgItemTextLength(HWND hwnd, int id)
{
    return STLSOFT_NS_GLOBAL(GetWindowTextLength)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id));
}

/** Gets the HINSTANCE associated with a given window
 *
 * \ingroup group__library__windows_window
 */
STLSOFT_INLINE HINSTANCE winstl__GetWindowInstance(HWND hwnd)
{
    return stlsoft_reinterpret_cast(HINSTANCE, STLSOFT_NS_GLOBAL(GetWindowLong)(hwnd, GWL_HINSTANCE));
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** Gets the style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t GetStyle(HWND h)
{
    return winstl__GetStyle(h);
}

/** Gets the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t GetExStyle(HWND h)
{
    return winstl__GetExStyle(h);
}

/** Sets the style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t SetStyle(HWND h, ws_long_t s)
{
    return winstl__SetStyle(h, s);
}

/** Sets the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t SetExStyle(HWND h, ws_long_t x)
{
    return winstl__SetExStyle(h, x);
}

/** Modifies the style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t ModifyStyle(HWND h, ws_long_t sRem, ws_long_t sAdd)
{
    return winstl__ModifyStyle(h, sRem, sAdd);
}

/** Modifies the extended style of the window
 *
 * \ingroup group__library__windows_window
 */
inline ws_long_t ModifyExStyle(HWND h, ws_long_t sRem, ws_long_t sAdd)
{
    return winstl__ModifyExStyle(h, sRem, sAdd);
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__windows_window
 */
inline ws_bool_t IsWindowClass(HWND hwnd, ws_char_a_t const *name)
{
    return BOOL2bool(winstl__IsWindowClassA(hwnd, name));
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__windows_window
 */
inline ws_bool_t IsWindowClass(HWND hwnd, ws_char_w_t const *name)
{
    return BOOL2bool(winstl__IsWindowClassW(hwnd, name));
}

/** Enables/disable a dialog item
 *
 * \ingroup group__library__windows_window
 */
inline void EnableDlgItem(HWND hwnd, int id, ws_bool_t bEnable)
{
    winstl__EnableDlgItem(hwnd, id, bEnable);
}

/** Elicits the enable status of a dialog item
 *
 * \ingroup group__library__windows_window
 */
inline ws_bool_t IsDlgItemEnabled(HWND hwnd, int id)
{
    return BOOL2bool(winstl__IsDlgItemEnabled(hwnd, id));
}

/** Gets the text length of a dialog item's window contents
 *
 * \ingroup group__library__windows_window
 */
inline ws_int_t GetDlgItemTextLength(HWND hwnd, int id)
{
    return winstl__GetDlgItemTextLength(hwnd, id);
}

/** Gets the HINSTANCE associated with a given window
 *
 * \ingroup group__library__windows_window
 */
#ifdef GetWindowInstance
# undef GetWindowInstance
#endif /* GetWindowInstance */
inline HINSTANCE GetWindowInstance(HWND hwnd)
{
    return winstl__GetWindowInstance(hwnd);
}

inline HICON set_window_icon(HWND hwnd, int iconType, HICON hicon)
{
    WINSTL_ASSERT(ICON_BIG == iconType || ICON_SMALL == iconType);

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    // This is needed here to prevent the Borland compiler from confused it with the winstl one!
    using ::SendMessage;
# endif /* compiler */

    return LONG2HICON(::SendMessage(hwnd, WM_SETICON, static_cast<WPARAM>(iconType), HICON2LPARAM(hicon)));
}

inline HICON set_window_icon(HWND hwnd, int iconType, HINSTANCE hinst, LPCTSTR iconName)
{
    return set_window_icon(hwnd, iconType, ::LoadIcon(hinst, iconName));
}

inline HICON set_window_icon(HWND hwnd, int iconType, HINSTANCE hinst, int iconId)
{
    return set_window_icon(hwnd, iconType, ::LoadIcon(hinst, MAKEINTRESOURCE(iconId)));
}

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1
#elif defined(STLSOFT_COMPILER_IS_BORLAND)
# define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3
#elif defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER > 1200
#  define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3
# else /* ? compiler */
#  define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2
# endif /* compiler */
#else /* ? compiler */
# define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1
#endif /* compiler */

/** \brief Finds the first descendant window with the given id
 *
 * \ingroup group__library__windows_window
 *
 * \param hwndParent The window whose children will be searched
 * \param id The dialog id to search for
 *
 * \return Either the window handle of the first child window (or
 * the parent itself) that matches the id, or NULL if no windows
 * match
 *
 * \note Because several levels of windows may be searched, it's
 * possible for more than one child window to have the given id.
 * This function will return only the first one found. Which one
 * is determined by the internals of the EnumChildWindows() API
 * function.
 *
 * \note \c hwndParent is included in the search, so if it has the
 * given id, it will be returned
 */
#if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1) || \
    defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)

#if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)
/* declare the template function */
template <int N>
inline HWND FindFirstChildById_N(HWND hwndParent, int id);
# endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 */

inline HWND FindFirstChildById(HWND hwndParent, int id)
#if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)
{
    return FindFirstChildById_N<1>(hwndParent, id);
}

template <int N>
inline HWND FindFirstChildById_N(HWND hwndParent, int id)
# endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 */
{
    if(::GetDlgCtrlID(hwndParent) == id)
    {
        return hwndParent;
    }
    else
    {
        class ChildFind
        {
        public:
            ss_explicit_k ChildFind(HWND hwndParent, int id)
                : m_hwndChild(NULL)
                , m_id(id)
            {
                ::EnumChildWindows(hwndParent, (WNDENUMPROC)EnumProc, reinterpret_cast<LPARAM>(this));
            }

        public:
            operator HWND() const
            {
                return m_hwndChild;
            }

        private:
            static BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
            {
                ChildFind &find = *reinterpret_cast<ChildFind*>(lParam);

                return (::GetDlgCtrlID(hwnd) == find.m_id)
                                    ? (find.m_hwndChild = hwnd, false)
                                    : true;
            }

        private:
            HWND        m_hwndChild;
            int const   m_id;

        } find(hwndParent, id);

        return find;
    }
}

#elif defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3)

struct FindFirstChildById_class
{
    class ChildFind
    {
    public:
        ss_explicit_k ChildFind(HWND hwndParent, int id)
            : m_hwndChild(NULL)
            , m_id(id)
        {
            ::EnumChildWindows(hwndParent, EnumProc, reinterpret_cast<LPARAM>(this));
        }

    public:
        operator HWND() const
        {
            return m_hwndChild;
        }

    private:
        static BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
        {
            ChildFind &find = *reinterpret_cast<ChildFind*>(lParam);

            return (::GetDlgCtrlID(hwnd) == find.m_id)
                                ? (find.m_hwndChild = hwnd, false)
                                : true;
        }

    private:
        HWND        m_hwndChild;
        int const   m_id;

    private:
        ChildFind &operator =(ChildFind const &);
    };

    static HWND FindFirstChildById_N(HWND hwndParent, int id)
    {
        if(::GetDlgCtrlID(hwndParent) == id)
        {
            return hwndParent;
        }
        else
        {
            ChildFind find(hwndParent, id);

            return find;
        }
    }
};

inline HWND FindFirstChildById(HWND hwndParent, int id)
{
  return FindFirstChildById_class/* <int> */::FindFirstChildById_N(hwndParent, id);
}

#else /* ? WINSTL_FINDFIRSTCHILDBYID_SLF_FORM?? */
# None of WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1, WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 or WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3 defined
#endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM?? */

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
