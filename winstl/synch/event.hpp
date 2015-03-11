/* ////////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/event.hpp (formerly winstl/event.hpp; originally winstl_event.h)
 *
 * Purpose:     event class, based on Windows EVENT.
 *
 * Created:     3rd July 2003
 * Updated:     3rd June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/event.hpp
 *
 * \brief [C++ only] Definition of the winstl::event class.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT
#define WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_MAJOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_MINOR    0
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_REVISION 1
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_EDIT     43
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
# include <winstl/synch/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */

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

/** \brief Class which wraps the Win32 EVENT synchronisation object
 *
 * \ingroup group__library__synch
 */
class event
    : public stlsoft_ns_qual(synchronisable_object_tag)
{
public:
    typedef event			class_type;
	typedef HANDLE			handle_type;

/// \name Construction
/// @{
public:
    /// \brief Creates the event
    event(ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, static_cast<ws_char_a_t const *>(0)))
        , m_bOwnHandle(true)
    {}
    /// \brief Creates the event with the given name
    ss_explicit_k event(ws_char_a_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// \brief Creates the event with the given name
    ss_explicit_k event(ws_char_w_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// \brief Creates the event with the given name and security attributes
    ss_explicit_k event(ws_char_a_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa)
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// \brief Creates the event with the given name and security attributes
    ss_explicit_k event(ws_char_w_t const *name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa)
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// \brief Destroys the event instance
    ~event() stlsoft_throw_0()
    {
        if( NULL != m_ev &&
            m_bOwnHandle)
        {
            ::CloseHandle(m_ev);
        }
    }
/// @}

/// \name Operations
/// @{
public:
    /// \brief Sets the state of the event to signalled
    void set()
    {
        WINSTL_ASSERT(NULL != m_ev);

        if(!::SetEvent(m_ev))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("event set operation failed", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// \brief Sets the state of the event to signalled
    void reset()
    {
        WINSTL_ASSERT(NULL != m_ev);

        if(!::ResetEvent(m_ev))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("event reset operation failed", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// \brief The underlying kernel object handle
    HANDLE  handle()
    {
        return m_ev;
    }
    /// \brief The underlying kernel object handle
    HANDLE  get()
    {
        return m_ev;
    }
/// @}

// Implementation
private:
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_a_t const *name)
    {
        HANDLE  h = ::CreateEventA(psa, bManualReset, bInitialState, name);

        if(NULL == h)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to create kernel event object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return h;
    }
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_w_t const *name)
    {
        HANDLE h = ::CreateEventW(psa, bManualReset, bInitialState, name);

        if(NULL == h)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw synchronisation_exception("Failed to create kernel event object", ::GetLastError());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return h;
    }

// Members
private:
    HANDLE          m_ev;
    const ws_bool_t m_bOwnHandle;   // Does the instance own the handle?

// Not to be implemented
private:
    event(class_type const &rhs);
    event &operator =(class_type const &rhs);
};

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

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT */

/* ////////////////////////////////////////////////////////////////////////// */
