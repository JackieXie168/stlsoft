/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/module.hpp (formerly winstl_module.h; originally MWModule.h, ::SynesisWin)
 *
 * Purpose:     Contains the module class.
 *
 * Created:     30th October 1997
 * Updated:     10th June 2006
 *
 * Thanks to:   Pablo Aguilar for the idea of a template-based get_symbol().
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2006, Matthew Wilson and Synesis Software
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


/// \file winstl/module.hpp
///
/// Contains the module class.

#ifndef WINSTL_INCL_WINSTL_HPP_MODULE
#define WINSTL_INCL_WINSTL_HPP_MODULE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_MODULE_MAJOR     5
# define WINSTL_VER_WINSTL_HPP_MODULE_MINOR     4
# define WINSTL_VER_WINSTL_HPP_MODULE_REVISION  2
# define WINSTL_VER_WINSTL_HPP_MODULE_EDIT      209
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
*/

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
# include <winstl/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_HPP_STRING_ACCESS
# include <winstl/string_access.hpp>          // for string access shims
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
#  include <winstl/filesystem/file_path_buffer.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

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

/// Class for manipulating dynamically loaded libraries
class module
{
public:
    /// \brief The handle type
    typedef HINSTANCE   module_handle_type;
    /// \brief The handle type
    ///
    /// \note This member type is required to make it compatible with
    ///  the STLSoft get_handle access shim
    typedef HINSTANCE   handle_type;
    /// \brief The class type
    typedef module      class_type;
    /// \brief The entry point type
    typedef void        (*proc_pointer)();

/// \name Construction
/// @{
public:
    /// \brief Constructs by loading the named module
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c windows_exception if the module cannot be loaded
    ss_explicit_k module(ws_char_a_t const *modName);
    /// \brief Constructs by loading the named module
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c windows_exception if the module cannot be loaded
    ss_explicit_k module(ws_char_w_t const *modName);
    /// \brief Constructs by loading the named module
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c windows_exception if the module cannot be loaded
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    template <ss_typename_param_k S>
    ss_explicit_k module(S const &modName)
        : m_hmodule(load(modName))
    {
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(NULL == m_hmodule)
        {
            throw_x(windows_exception("Cannot load module", ::GetLastError()));
        }
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    /// \brief Constructs by taking ownership of the given handle
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c windows_exception if the module handle is NULL
    ss_explicit_k module(module_handle_type hmodule);
    /// \brief Copy constructor
    ///
    /// \note Both copies hold independent handles to the underlying link unit
    module(class_type const &rhs);
    /// \brief Closes the module handle
    ~module() stlsoft_throw_0();
/// @}

/// \name Static operations
/// @{
public:
    static module_handle_type   load(ws_char_a_t const *modName);
    static module_handle_type   load(ws_char_w_t const *modName);
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    template <ss_typename_param_k S>
    static module_handle_type   load(S const &modName)
    {
        return class_type::load(stlsoft_ns_qual(c_str_ptr)(modName));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    static void                 unload(module_handle_type hmodule) stlsoft_throw_0();
    static proc_pointer         get_symbol(module_handle_type hmodule, ws_char_a_t const *symbolName);
    static proc_pointer         get_symbol(module_handle_type hmodule, ws_uint32_t symbolOrdinal);

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    template <ss_typename_param_k F>
    static proc_pointer         get_symbol(module_handle_type hmodule, ws_char_a_t const *symbolName, F &f)
    {
        proc_pointer    proc  =   class_type::get_symbol(hmodule, symbolName);

        f = reinterpret_cast<F>(proc);

        return proc;
    }
    template <ss_typename_param_k F>
    static proc_pointer         get_symbol(module_handle_type hmodule, ws_uint32_t symbolOrdinal, F &f)
    {
        proc_pointer    proc  =   class_type::get_symbol(hmodule, symbolOrdinal);

        f = reinterpret_cast<F>(proc);

        return proc;
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
/// @}

/// \name Operations
/// @{
public:
    /// \brief Closes the module handle
    void unload() stlsoft_throw_0();

    /// \brief Yields the module handle to the caller
    module_handle_type detach();
/// @}

/// \name Lookup Operations
/// @{
public:
    proc_pointer    get_symbol(ws_char_a_t const *symbolName);
    proc_pointer    get_symbol(ws_uint32_t symbolOrdinal);

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    template <ss_typename_param_k F>
    proc_pointer    get_symbol(ws_char_a_t const *symbolName, F &f)
    {
        return class_type::get_symbol(m_hmodule, symbolName, f);
    }
    template <ss_typename_param_k F>
    proc_pointer    get_symbol(ws_uint32_t symbolOrdinal, F &f)
    {
        return class_type::get_symbol(m_hmodule, symbolOrdinal, f);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
/// @}

/// \name Accessors
/// @{
public:
    /// \brief Provides access to the underlying module handle
    module_handle_type  get_handle() const;

    /// \brief Provides access to the underlying module handle
    module_handle_type  get() const;
/// @}

// Members
private:
    module_handle_type  m_hmodule;

// Not to be implemented
private:
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////
 * Access shims
 */

/// Returns the handle for the given module
inline HINSTANCE get_handle(module const &m)
{
    return m.get_handle();
}

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/module_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline module::module(ws_char_a_t const *modName)
    : m_hmodule(load(modName))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw_x(windows_exception("Cannot load module", ::GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(ws_char_w_t const *modName)
    : m_hmodule(load(modName))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw_x(windows_exception("Cannot load module", ::GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(module::module_handle_type hmodule)
    : m_hmodule(hmodule)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw_x(windows_exception("Cannot load module", ::GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(module const &rhs)
{
    if(NULL == rhs.get_handle())
    {
        m_hmodule = NULL;
    }
    else
    {
        basic_file_path_buffer<ws_char_a_t> buffer;
        ws_size_t                           cch =   filesystem_traits<ws_char_a_t>::get_module_filename(rhs.get_handle(), &buffer[0], buffer.size());

        if(0 == cch)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw_x(windows_exception("Cannot get module path", ::GetLastError()));
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
            m_hmodule = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            m_hmodule = load(&buffer[0]);
        }
    }
}

inline module::~module() stlsoft_throw_0()
{
    unload(m_hmodule);
}

inline void module::unload() stlsoft_throw_0()
{
    if(NULL != m_hmodule)
    {
        class_type::unload(m_hmodule);
        m_hmodule = NULL;
    }
}

inline module::module_handle_type module::detach()
{
    module_handle_type  h;

    h = m_hmodule;
    m_hmodule = NULL;

    return h;
}

inline /* static */ module::module_handle_type module::load(ws_char_a_t const *modName)
{
    return ::LoadLibraryA(modName);
}

inline /* static */ module::module_handle_type module::load(ws_char_w_t const *modName)
{
    return ::LoadLibraryW(modName);
}

inline /* static */ void module::unload(module::module_handle_type hmodule) stlsoft_throw_0()
{
    if(NULL != hmodule)
    {
        ::FreeLibrary(hmodule);
    }
}

inline /* static */ module::proc_pointer module::get_symbol(module::module_handle_type hmodule, ws_char_a_t const *symbolName)
{
    return reinterpret_cast<proc_pointer>(GetProcAddress(hmodule, symbolName));
}

inline /* static */ module::proc_pointer module::get_symbol(module::module_handle_type hmodule, ws_uint32_t symbolOrdinal)
{
    ws_char_a_t const *s    =   MAKEINTRESOURCEA(symbolOrdinal);

    return get_symbol(hmodule, s);
}

inline module::proc_pointer module::get_symbol(ws_char_a_t const *symbolName)
{
    return get_symbol(m_hmodule, symbolName);
}

inline module::proc_pointer module::get_symbol(ws_uint32_t symbolOrdinal)
{
    return get_symbol(m_hmodule, symbolOrdinal);
}

inline module::module_handle_type module::get_handle() const
{
    return m_hmodule;
}

inline module::module_handle_type module::get() const
{
    return m_hmodule;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* WINSTL_INCL_WINSTL_HPP_MODULE */

/* ////////////////////////////////////////////////////////////////////// */
