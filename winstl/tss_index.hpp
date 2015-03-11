/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/tss_index.hpp (formerly winstl_tss_index.h; originally in MWTlsFns.h, ::SynesisWin)
 *
 * Purpose:     Win32 TLS slot index.
 *
 * Created:     20th January 1999
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/tss_index.hpp
///
/// Win32 TLS slot index.

#ifndef WINSTL_INCL_WINSTL_HPP_TSS_INDEX
#define WINSTL_INCL_WINSTL_HPP_TSS_INDEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_TSS_INDEX_MAJOR      3
# define WINSTL_VER_WINSTL_HPP_TSS_INDEX_MINOR      1
# define WINSTL_VER_WINSTL_HPP_TSS_INDEX_REVISION   1
# define WINSTL_VER_WINSTL_HPP_TSS_INDEX_EDIT       20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
#  include <winstl/exceptions.hpp>        // windows_exception
# endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */

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

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for accessing system attributes

/// \defgroup winstl_system_library System Library (WinSTL)
/// \ingroup WinSTL libraries_system
/// \brief This library provides facilities for accessing Win32 system attributes
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
class tss_exception
    : public windows_exception
{
/// \name Types
/// @{
public:
    typedef windows_exception   parent_class_type;
    typedef tss_exception       class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k tss_exception(ws_dword_t err)
        : parent_class_type(err)
    {}
/// @}

/// \name Accessors
/// @{
public:
    virtual char const *what() const stlsoft_throw_0()
    {
        return "Failed to allocate a TLS index";
    }
/// @}
};
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */


/// A TLS index
///
///
class tss_index
{
/// \name Types
/// @{
public:
    typedef tss_index   class_type;
    typedef ws_dword_t  index_type;
    typedef void        *value_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k tss_index()
        : m_index(index_create_())
    {}
    ~tss_index() stlsoft_throw_0()
    {
        index_destroy_(m_index);
    }
/// @}

/// \name Operations
/// @{
public:
    void        set_value(value_type value)
    {
        class_type::set_slot_value_(m_index, value);
    }
    value_type  get_value() const
    {
        return class_type::get_slot_value_(m_index);
    }
/// @}

/// \name Accessors
/// @{
public:
    operator index_type () const
    {
        return m_index;
    }
/// @}

/// \name Implementation
/// @{
private:
    static index_type index_create_()
    {
        index_type  index   =   ::TlsAlloc();

        if(0xFFFFFFFF == index)
        {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
            throw_exception_(tss_exception(::GetLastError()));
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
            ::RaiseException(STATUS_NO_MEMORY, EXCEPTION_NONCONTINUABLE, 0, 0);
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return index;
    }

    static void index_destroy_(index_type index)
    {
        ::TlsFree(index);
    }

    static void set_slot_value_(index_type index, value_type value)
    {
        ::TlsSetValue(index, value);
    }

    static value_type get_slot_value_(index_type index)
    {
        return ::TlsGetValue(index);
    }
/// @}

// Members
private:
    index_type  m_index;


private:
#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    template <ss_typename_param_k X>
    static void throw_exception_(X const &x)
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER < 1200
    static void throw_exception_(std::exception const &x)
#else /* ? feature / compiler */
    static void throw_exception_(thrown_type const &x)
#endif /* feature / compiler */
    {
        throw x;
    }

// Not to be implemented
private:
    tss_index(tss_index const &);
    tss_index &operator =(tss_index const &);
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_system_library

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

#endif /* WINSTL_INCL_WINSTL_HPP_TSS_INDEX */

/* ////////////////////////////////////////////////////////////////////////// */
