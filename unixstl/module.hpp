/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/module.hpp (formerly unixstl_module.h; originally MXModule.h, ::SynesisUnix)
 *
 * Purpose:     Contains the module class.
 *
 * Created:     30th October 1997
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2005, Matthew Wilson and Synesis Software
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


/// \file unixstl/module.hpp
///
/// Contains the module class.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_MODULE
#define UNIXSTL_INCL_UNIXSTL_HPP_MODULE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_MODULE_MAJOR       5
# define UNIXSTL_VER_UNIXSTL_HPP_MODULE_MINOR       1
# define UNIXSTL_VER_UNIXSTL_HPP_MODULE_REVISION    1
# define UNIXSTL_VER_UNIXSTL_HPP_MODULE_EDIT        195
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
# include <unixstl/exceptions.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */
#include <dlfcn.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_system System Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating operating-system specific constructs

/// \weakgroup unixstl_system_library System Library (UNIXSTL)
/// \ingroup UNIXSTL libraries_system
/// \brief This library provides facilities for defining and manipulating operating-system specific constructs for UNIX
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Class for manipulating dynamically loaded libraries
class module
{
public:
    typedef void        *module_handle_type;
    typedef module      class_type;

/// \name Construction
/// @{
public:
    /// \brief Constructs by loading the named module
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c unix_exception if the module cannot be loaded
    ss_explicit_k module(us_char_a_t const *modName, int mode = RTLD_NOW);
    /// \brief Constructs by loading the named module
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c unix_exception if the module cannot be loaded
    ss_explicit_k module(us_char_w_t const *modName, int mode = RTLD_NOW);
    /// \brief Constructs by taking ownership of the given handle
    ///
    /// \note If exception-handling is being used, then this throws a
    /// \c unix_exception if the module handle is NULL
    ss_explicit_k module(module_handle_type hmodule);
    /// \brief Closes the module handle
    ~module() stlsoft_throw_0();
/// @}

/// \name Static operations
/// @{
public:
    static module_handle_type   load(us_char_a_t const *modName, int mode = RTLD_NOW);
    static module_handle_type   load(us_char_w_t const *modName, int mode = RTLD_NOW);
    static void                 unload(module_handle_type hmodule);
    static void                 *get_symbol(module_handle_type hmodule, us_char_a_t const *symbolName);
/// @}

/// \name Operations
/// @{
public:
    /// \brief Closes the module handle
    void unload();

    /// \brief Yields the module handle to the caller
    module_handle_type detach();
/// @}

/// \name Lookup Operations
/// @{
public:
    void *get_symbol(us_char_a_t const *symbolName);
/// @}

// \name Accessors
/// @{
public:
    /// \brief Provides access to the underlying module handle
    module_handle_type  get_handle() const;
/// @}

// Members
private:
    module_handle_type  m_hmodule;

// Not to be implemented
private:
    // TODO: These can be implemented later

};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group unixstl_system_library

/* /////////////////////////////////////////////////////////////////////////////
 * Access shims
 */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_handle_access Handle Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" retrieve the "handle" for arbitrary types

/// \defgroup unixstl_handle_access_shims Handle Access Shims (UNIXSTL)
/// \ingroup UNIXSTL concepts_shims_handle_access
/// \brief These \ref concepts_shims "shims" retrieve the "handle" for arbitrary UNIX types
/// @{

/// Returns the handle for the given module
inline void *get_handle(module const &m)
{
    return m.get_handle();
}

/// @} // end of group winstl_module_attribute_shims

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/module_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline module::module(us_char_a_t const *modName, int mode)
    : m_hmodule(load(modName, mode))
{
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw unix_exception("Cannot load module", errno);
    }
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(us_char_w_t const *modName, int mode)
    : m_hmodule(load(modName, mode))
{
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw unix_exception("Cannot load module", errno);
    }
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(module::module_handle_type hmodule)
    : m_hmodule(hmodule)
{
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
    if(NULL == m_hmodule)
    {
        throw unix_exception("Cannot load module", errno);
    }
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::~module() stlsoft_throw_0()
{
    unload(m_hmodule);
}

inline void module::unload()
{
    if(NULL != m_hmodule)
    {
        unload(m_hmodule);
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

inline /* static */ module::module_handle_type module::load(us_char_a_t const *modName, int mode)
{
    return ::dlopen(modName, mode);
}

inline /* static */ void module::unload(module::module_handle_type hmodule)
{
    if(NULL != hmodule)
    {
        ::dlclose(hmodule);
    }
}

inline /* static */ void *module::get_symbol(module::module_handle_type hmodule, us_char_a_t const *symbolName)
{
    return ::dlsym(hmodule, symbolName);
}

inline void *module::get_symbol(us_char_a_t const *symbolName)
{
    return get_symbol(m_hmodule, symbolName);
}

inline module::module_handle_type module::get_handle() const
{
    return m_hmodule;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_HPP_MODULE */

/* ////////////////////////////////////////////////////////////////////////// */
