/* ////////////////////////////////////////////////////////////////////////////
 * File:        event.hpp (formerly winstl_event.h)
 *
 * Purpose:     event class, based on Windows EVENT.
 *
 * Created:     3rd July 2003
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2004, Matthew Wilson and Synesis Software
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


/// \file winstl/event.hpp
///
/// evemt class, based on Windows EVENT.

#ifndef WINSTL_INCL_WINSTL_HPP_EVENT
#define WINSTL_INCL_WINSTL_HPP_EVENT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_EVENT_MAJOR    3
# define WINSTL_VER_WINSTL_HPP_EVENT_MINOR    1
# define WINSTL_VER_WINSTL_HPP_EVENT_REVISION 1
# define WINSTL_VER_WINSTL_HPP_EVENT_EDIT     34
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_HANDLE_ACCESS
# include <winstl/handle_access.hpp>  // get_handle()
#endif /* !WINSTL_INCL_WINSTL_HPP_HANDLE_ACCESS */

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

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This needs to be parameterised with a winstl::system_resource_policy, which would control whether to throw if MX create fails"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/// Class which wraps the Win32 EVENT synchronisation object
class event
{
public:
    typedef event       class_type;

/// \name Construction
/// @{
public:
    /// Creates the event
    event(ws_bool_t bManualReset, ws_bool_t bInitialState) stlsoft_throw_0()
        : m_ev(create_event_(NULL, bManualReset, bInitialState, static_cast<ws_char_a_t const *>(0)))
    {}
    /// Creates the event with the given name
    ss_explicit_k event(ws_char_a_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState) stlsoft_throw_0()
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
    {}
    /// Creates the event with the given name
    ss_explicit_k event(ws_char_w_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState) stlsoft_throw_0()
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
    {}
    /// Creates the event with the given name and security attributes
    ss_explicit_k event(ws_char_a_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa) stlsoft_throw_0()
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
    {}
    /// Creates the event with the given name and security attributes
    ss_explicit_k event(ws_char_w_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa) stlsoft_throw_0()
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
    {}
    /// Destroys the event instance
    ~event() stlsoft_throw_0()
    {
        if(NULL != m_ev)
        {
            ::CloseHandle(m_ev);
        }
    }
/// @}

/// \name Operations
/// @{
public:
    /// Sets the state of the event to signalled
    void set() stlsoft_throw_0()
    {
        ::SetEvent(m_ev);
    }
    /// Sets the state of the event to signalled
    void reset() stlsoft_throw_0()
    {
        ::ResetEvent(m_ev);
    }
/// @}

/// \name Accessors
/// @{
public:
    HANDLE  handle()
    {
        return m_ev;
    }
/// @}

// Implementation
private:
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_a_t const *name)
    {
        return ::CreateEventA(psa, bManualReset, bInitialState, name);
    }
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_w_t const *name)
    {
        return ::CreateEventW(psa, bManualReset, bInitialState, name);
    }

// Members
private:
    HANDLE  m_ev;

// Not to be implemented
private:
    event(class_type const &rhs);
    event &operator =(class_type const &rhs);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Access shims
 */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_sync_control Synchronisation Control Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" control the behaviour of synchronisation objects

/// \defgroup winstl_sync_attribute_shims Synchronisation Access Shims (WinSTL)
/// \ingroup WinSTL concepts_shims_sync_control
/// \brief These \ref concepts_shims "shims" access the characteristics of Win32 synchronisation objects
/// @{

inline HANDLE get_handle(event &ev)
{
    return ev.handle();
}

/// @} // end of group winstl_sync_attribute_shims

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/event_unittest_.h"
#endif /* STLSOFT_UNITTEST */

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

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The handle access shims exist either in the stlsoft namespace, or in the
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

using ::winstl::get_handle;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_HPP_EVENT */

/* ////////////////////////////////////////////////////////////////////////// */
