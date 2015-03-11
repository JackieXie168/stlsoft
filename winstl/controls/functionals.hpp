/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/controls/functionals.hpp (formerly winstl/control_functionals.hpp; originally winstl_control_functionals.h)
 *
 * Purpose:     Functionals for application to controls.
 *
 * Created:     8th October 2002
 * Updated:     14th June 2006
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


/** \file winstl/controls/functionals.hpp
 *
 * \brief [C++] Functionals for application to controls.
 *  (\ref group__library__windows_controls "Windows Controls" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS
#define WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_MAJOR    4
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_MINOR    0
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_REVISION 2
# define WINSTL_VER_WINSTL_CONTROL_HPP_FUNCTIONALS_EDIT     63
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_GCC:  __GNUC__<3
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1100
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
# error winstl_control_functionals.h is not compatible with GNU C++ prior to 3.0
#endif /* compiler */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error winstl_control_functionals.h is not compatible with Visual C++ 4.2 or earlier
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_UNARY_FUNCTION_OUTPUT_ITERATOR_ADAPTOR
# include <stlsoft/unary_function_output_iterator_adaptor.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_UNARY_FUNCTION_OUTPUT_ITERATOR_ADAPTOR */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>        // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */
#ifndef WINSTL_INCL_WINSTL_HPP_WINDOW_ACCESS
# include <winstl/window_access.hpp>        // for get_hwnd()
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOW_ACCESS */
#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS
# include <winstl/conversion/char_conversions.hpp>  // for winstl::a2w, w2a
#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_CHAR_CONVERSIONS */
#ifndef WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS
# include <winstl/controls/functions.h>     // for winstl::listbox_add_string, ...
#endif /* !WINSTL_INCL_WINSTL_CONTROLS_H_FUNCTIONS */
#ifndef _WINSTL_CONTROL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _WINSTL_CONTROL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _WINSTL_CONTROL_FUNCTIONALS_NO_STD */

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

/** \brief Functor used to (un)check buttons
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: button_check]]
class button_check
    : public stlsoft_ns_qual_std(unary_function)<HWND, void>
{
public:
    typedef button_check    class_type;
public:
    ss_explicit_k button_check(int nCheck = BST_CHECKED)
        : m_nCheck(nCheck)
    {}
    button_check(button_check const &rhs)
        : m_nCheck(rhs.m_nCheck)
    {}

public:
    void operator ()(HWND hwnd) const
    {
        check_(hwnd, m_nCheck);
    }
    template <ss_typename_param_k W>
    void operator ()(W &wnd) const
    {
        check_(winstl_ns_qual(get_hwnd)(wnd), m_nCheck);
    }
private:
    static void check_(HWND hwnd, int nCheck)
    {
        ::SendMessage(hwnd, BM_SETCHECK, static_cast<WPARAM>(nCheck), 0L);
    }

private:
    const int   m_nCheck;

private:
    class_type &operator =(class_type const&);
};


/** \brief Predicate used to indicate the check-state of buttons
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-predicate: is_checked]]
class is_checked
    : public stlsoft_ns_qual_std(unary_function)<HWND, BOOL>
{
public:
    typedef is_checked  class_type;

public:
    is_checked(int nCheckType = -1)
        : m_nCheckType(nCheckType)
    {
        WINSTL_ASSERT((-1 == nCheckType) || (BST_UNCHECKED == nCheckType) || (BST_CHECKED == nCheckType) || (BST_INDETERMINATE == nCheckType));
    }

public:
    BOOL operator ()(HWND hwnd) const
    {
        return is_checked_(hwnd);
    }
    template <ss_typename_param_k W>
    BOOL operator ()(W &wnd) const
    {
        return is_checked_(winstl_ns_qual(get_hwnd)(wnd));
    }
private:
    BOOL is_checked_(HWND hwnd) const
    {
        int nCheck  =   static_cast<int>(::SendMessage(hwnd, BM_GETCHECK, 0, 0L));

        if(-1 == m_nCheckType)
        {
            return nCheck;
        }
        else
        {
            return m_nCheckType == nCheck;
        }
    }

private:
    class_type &operator =(class_type const&);

private:
    const int   m_nCheckType;
};


/** \brief Predicate used to detect whether the window is of a given class
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-predicate: is_class]]
class is_class
    : public stlsoft_ns_qual_std(unary_function)<HWND, BOOL>
{
public:
    typedef is_class  class_type;

public:
    ss_explicit_k is_class(ws_char_a_t const *windowClass)
        : m_bUnicode(false)
    {
        WINSTL_ASSERT(NULL != windowClass);

        lstrcpynA(&m_name.sza[0], windowClass, STLSOFT_NUM_ELEMENTS(m_name.sza));
    }
    ss_explicit_k is_class(ws_char_w_t const *windowClass)
        : m_bUnicode(true)
    {
        WINSTL_ASSERT(NULL != windowClass);

        lstrcpynW(&m_name.szw[0], windowClass, STLSOFT_NUM_ELEMENTS(m_name.sza));
    }

public:
    BOOL operator ()(HWND hwnd) const
    {
        return is_class_(hwnd);
    }
    template <ss_typename_param_k W>
    BOOL operator ()(W &wnd) const
    {
        return is_class_(winstl_ns_qual(get_hwnd)(wnd));
    }
private:
    BOOL is_class_(HWND hwnd) const
    {
        return m_bUnicode ? is_class_w_(hwnd) : is_class_a_(hwnd);
    }
    BOOL is_class_w_(HWND hwnd) const
    {
        ws_char_w_t szw[256];

        return  ::GetClassNameW(hwnd, &szw[0], STLSOFT_NUM_ELEMENTS(szw)) &&
                0 == ::lstrcmpiW(&szw[0], &m_name.szw[0]);
    }
    BOOL is_class_a_(HWND hwnd) const
    {
        ws_char_a_t sza[256];

        return  ::GetClassNameA(hwnd, &sza[0], STLSOFT_NUM_ELEMENTS(sza)) &&
                0 == ::lstrcmpiA(&sza[0], &m_name.sza[0]);
    }

private:
    union
    {
        ws_char_a_t sza[256];
        ws_char_w_t szw[256];
    }           m_name;
    const int   m_bUnicode;

// Not to be implemented
private:
    class_type &operator =(class_type const&);
};


/** \brief Function object used to insert items at the front of list-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: listbox_front_inserter]]
struct listbox_front_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<listbox_front_inserter>
{
public:
    typedef listbox_front_inserter  class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k listbox_front_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_front_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        insert(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, a2w(s), 0);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, s, 0);
        }
    }
    void insert(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, s, 0);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, w2a(s), 0);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** \brief Function object used to add items to a list-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: listbox_add_inserter]]
struct listbox_add_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<listbox_add_inserter>
{
public:
    typedef listbox_add_inserter    class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k listbox_add_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_add_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        add(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        add(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        add(s);
    }

// Implementation
private:
    void add(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_addstring_w(m_hwndListbox, a2w(s));
        }
        else
        {
            listbox_addstring_a(m_hwndListbox, s);
        }
    }
    void add(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_addstring_w(m_hwndListbox, s);
        }
        else
        {
            listbox_addstring_a(m_hwndListbox, w2a(s));
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** \brief Function object used to insert items to the back of a list-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: listbox_back_inserter]]
struct listbox_back_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<listbox_back_inserter>
{
public:
    typedef listbox_back_inserter   class_type;

public:
    /// Construct with the target list-box window
    ss_explicit_k listbox_back_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    listbox_back_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        insert(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, a2w(s), -1);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, s, -1);
        }
    }
    void insert(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            listbox_insertstring_w(m_hwndListbox, s, -1);
        }
        else
        {
            listbox_insertstring_a(m_hwndListbox, w2a(s), -1);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};



/** \brief Function object used to insert items at the front of combo-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: combobox_front_inserter]]
struct combobox_front_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<combobox_front_inserter>
{
public:
    typedef combobox_front_inserter class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k combobox_front_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_front_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        insert(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, a2w(s), 0);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, s, 0);
        }
    }
    void insert(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, s, 0);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, w2a(s), 0);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** \brief Function object used to add items to a combo-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: combobox_add_inserter]]
struct combobox_add_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<combobox_add_inserter>
{
public:
    typedef combobox_add_inserter   class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k combobox_add_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_add_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        add(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        add(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        add(s);
    }

// Implementation
private:
    void add(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_addstring_w(m_hwndListbox, a2w(s));
        }
        else
        {
            combobox_addstring_a(m_hwndListbox, s);
        }
    }
    void add(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_addstring_w(m_hwndListbox, s);
        }
        else
        {
            combobox_addstring_a(m_hwndListbox, w2a(s));
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

/** \brief Function object used to insert items to the back of a combo-box
 *
 * \ingroup group__library__windows_controls
 */
// [[synesis:class:unary-functor: combobox_back_inserter]]
struct combobox_back_inserter
    : public stlsoft_ns_qual(unary_function_output_iterator_adaptor)<combobox_back_inserter>
{
public:
    typedef combobox_back_inserter  class_type;

public:
    /// Construct with the target combo-box window
    ss_explicit_k combobox_back_inserter(HWND hwndListbox)
        : m_hwndListbox(hwndListbox)
        , m_bUnicode(::IsWindowUnicode(hwndListbox))
    {}

    combobox_back_inserter(class_type const &rhs)
        : m_hwndListbox(rhs.m_hwndListbox)
        , m_bUnicode(rhs.m_bUnicode)
    {}

#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    template <ss_typename_param_k S>
    void operator ()(S const &s)
    {
        insert(stlsoft_ns_qual(c_str_ptr)(s));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator taking the item string
    void operator ()(ws_char_a_t const *s)
    {
        insert(s);
    }
    /// Function call operator taking the item string
    void operator ()(ws_char_w_t const *s)
    {
        insert(s);
    }

// Implementation
private:
    void insert(ws_char_a_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, a2w(s), -1);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, s, -1);
        }
    }
    void insert(ws_char_w_t const *s)
    {
        if(m_bUnicode)
        {
            combobox_insertstring_w(m_hwndListbox, s, -1);
        }
        else
        {
            combobox_insertstring_a(m_hwndListbox, w2a(s), -1);
        }
    }

private:
    HWND        m_hwndListbox;
    ws_int32_t  m_bUnicode;
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/functionals_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////// */
