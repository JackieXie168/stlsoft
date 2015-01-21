/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/custom_event_handler.hpp
 *
 * Purpose:     Event handler class for custom event notifications.
 *
 * Created:     1st October 2004
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/// \file acestl/custom_event_handler.hpp
///
/// Event handler class for custom event notifications.

#ifndef ACESTL_INCL_ACESTL_HPP_CUSTOM_EVENT_HANDLER
#define ACESTL_INCL_ACESTL_HPP_CUSTOM_EVENT_HANDLER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_CUSTOM_EVENT_HANDLER_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_CUSTOM_EVENT_HANDLER_MINOR     5
# define ACESTL_VER_ACESTL_HPP_CUSTOM_EVENT_HANDLER_REVISION  8
# define ACESTL_VER_ACESTL_HPP_CUSTOM_EVENT_HANDLER_EDIT      38
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#include <ace/Event_Handler.h>              // for ACE_Event_Handler
#include <ace/Reactor.h>                    // for ACE_Reactor

#ifndef STLSOFT_INCL_STLSOFT_HPP_SHARED_PTR
# include <stlsoft/shared_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SHARED_PTR */

#include <map>

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(STLSOFT_COMPILER_IS_INTEL) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER >= 1200)
# define ACESTL_CUSTOM_EVENT_HANDLER_CANCEL_EVENTS_MEMBER_CLEANUP_SUPPORT
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_messaging Messaging Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating messaging constructs

/// \defgroup acestl_messaging_library Messaging Library (ACESTL)
/// \ingroup ACESTL libraries_messaging
/// \brief This library provides facilities for defining and manipulating messaging constructs with ACE
/// @{


/* ////////////////////////////////////////////////////////////////////////// */

/// Utility class that establishes a root type for the cancel_adaptor and the
/// custom_event_handler classes
struct ceh_root
{
private:
    struct event_id_ {};
public:
    typedef event_id_   *event_id;
};

/// Adaptor class that facilitates the
/// custom_event_handler::cancel_custom_events() member function template.
template<ss_typename_param_k C>
struct cancel_adapter
    : public ceh_root
{
    typedef cancel_adapter<C>   class_type;

    cancel_adapter(C *obj, void (C::*pfn)(long code, event_id id, void *arg))
        : m_obj(obj)
        , m_pfn(pfn)
    {}

    static void proc(void *param, long code, event_id id, void *arg)
    {
        class_type  *pThis = static_cast<class_type*>(param);

        ((pThis->m_obj)->*(pThis->m_pfn))(code, id, arg);
    }

private:
    C *const m_obj;
    void (C::*m_pfn)(long code, event_id id, void *arg);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief This class provides custom event notification for the ACE Reactor
/// framework
///
/// It provides the ability to schedule a custom event with a code, an optional
/// delay, and an optional argument
///
/// To use, derive from it as you would from ACE_Event_Handler, and override the
/// handle_custom_event() method, e.g
///
/// \htmlonly
/// <pre>
///
/// class MyHandler
///   : public acestl::custom_event_handler
/// {
/// private:
///   virtual int handle_custom_event(ACE_Time_Value const  &current_time
///                               ,   long                  event_code
///                               ,   void                  *arg)
///   {
///     fprintf(stdout, "Received custom event: %ld, %p\n", event_code, arg);
///
///     return 0;
///   }
/// . . .
/// };
///
/// acestl::custom_event_handler *eh = new MyHandler();
///
/// // Schedule an event with id 100
/// eh->schedule_custom_event(100);
///
/// // Schedule an event for 10 seconds hence, with id 200
/// eh->schedule_custom_event(200, ACE_Time_Value(10));
///
/// // Schedule an event for 10 seconds hence, with id 300, and an argument in a string instance
/// eh->schedule_custom_event(300, ACE_Time_Value(10), new std::string("300"));
///
/// // Start the reactor loop. Events will be dispatched from here on in
/// ACE_Reactor::instance()->run_reactor_event_loop();
///
/// </pre>
/// \endhtmlonly
class custom_event_handler
    : public ACE_Event_Handler
    , public ceh_root
{
/// \name Types
/// @{
private:
    struct event_id_ {};
public:
    typedef ACE_Event_Handler       parent_class_type;
    typedef custom_event_handler    class_type;
    /// The type that represents a pending event instance
//    typedef event_id_               *event_id;
    /// Type of the callback function that may be passed to cancel_custom_events, which will
    /// receive information on each cancelled event instance.
    typedef void (*cancelled_event_code_fn)(void *param, long code, event_id id, void *arg);
/// @}

/// \name Construction
/// @{
protected:
    /// Constructor
    ///
    /// \param reactor The reactor instance with which this event-handler will interact
    /// \param priority The priority for this handler
    ss_explicit_k custom_event_handler( ACE_Reactor *reactor    =   ACE_Reactor::instance()
                                    ,   int         priority    =   ACE_Event_Handler::LO_PRIORITY);
public:
    /// Destructor
    virtual ~custom_event_handler() stlsoft_throw_0();
/// @}

/// \name Operations
/// @{
public:
    /// Registers the custom event.
    ///
    /// \param code The event code that identifies the event for this event
    /// handler instance, and will be passed back to the handle_custom_event() callback
    /// \param delay The interval after which the event callback will be operable
    /// \param arg An optional event parameter, which will be passed back to the
    /// handle_custom_event() callback
    ///
    /// \return NULL on failure, the event id on success
    ///
    /// \note The custom event can be cancelled via cancel_custom_event()
    ///
    /// \note Custom events are "one-shot". When the event delay elapses and the
    /// handle_custom_event() callback is called, the event has been deregistered from
    /// this handler. There is no need to call cancel_custom_event(), and doing so is
    /// semantically wrong, though it has no effect.
    event_id schedule_custom_event(long code, ACE_Time_Value const &delay, void *arg = 0);

    /// Registers the custom event for immediate action.
    ///
    /// \param code The event code that identifies the event for this event
    /// handler instance, and will be passed back to the handle_custom_event() callback
    /// \param arg An optional event parameter, which will be passed back to the
    /// handle_custom_event() callback
    ///
    /// \return NULL on failure, the event id on success
    ///
    /// \note The custom event can be cancelled via cancel_custom_event()
    ///
    /// \note Custom events are "one-shot". When the event delay elapses and the
    /// handle_custom_event() callback is called, the event has been deregistered from
    /// this handler. There is no need to call cancel_custom_event(), and doing so is
    /// semantically wrong, though it has no effect.
    event_id schedule_custom_event(long code, void *arg = 0);

    /// Cancels the event(s) corresponding to the given event code
    ///
    /// \param code The code of the events to be cancelled
    ///
    /// \return -1 on failure, 0 on success
    ///
    /// \note There is no need to call this function if the event handler
    /// callback handle_custom_event() has been called, since the event is
    /// already deregistered at that point.
    int cancel_custom_events(long code);

    /// Cancels the event(s) corresponding to the given event code
    ///
    /// \param code The code of the events to be cancelled
    /// \param pfn Pointer to a function that will be called for each cancelled event
    /// \param param A caller-supplied parameter that will be passed back to the callback function
    ///
    /// \return -1 on failure, 0 on success
    int cancel_custom_events(long code, cancelled_event_code_fn pfn, void *param);

#if defined(ACESTL_CUSTOM_EVENT_HANDLER_CANCEL_EVENTS_MEMBER_CLEANUP_SUPPORT)
#if 0
    /// Some compilers (i.e. VC++ 6) have a big cry here, so we define this out
    /// of the class, and use the private base type trick
    template<ss_typename_param_k C>
    struct cancel_adapter
    {
        typedef cancel_adapter<C>   class_type;

        cancel_adapter(C *obj, void (C::*pfn)(long code, event_id id, void *arg))
            : m_obj(obj)
            , m_pfn(pfn)
        {}

        static void proc(void *param, long code, event_id id, void *arg)
        {
            class_type  *pThis = static_cast<class_type*>(param);

            ((pThis->m_obj)->*(pThis->m_pfn))(code, id, arg);
        }

    private:
        C *const m_obj;
        void (C::*m_pfn)(long code, event_id id, void *arg);
    };
#endif /* 0 */

    template<ss_typename_param_k C>
    int cancel_custom_events(long code, C *obj, void (C::*pfn)(long code, event_id id, void *arg))
    {
        cancel_adapter<C>   adapter(obj, pfn);

        return this->cancel_custom_events(code, &cancel_adapter<C>::proc, &adapter);
    }
#endif /* ACESTL_CUSTOM_EVENT_HANDLER_CANCEL_EVENTS_MEMBER_CLEANUP_SUPPORT */

    /// Cancels the given event
    ///
    /// \param event The event to be cancelled
    /// \param parg Optional pointer to a variable to receive the argument specified when the event was scheduled
    ///
    /// \return -1 on failure, 0 on success
    ///
    /// \note There is no need to call this function if the event handler
    /// callback handle_custom_event() has been called, since the event is
    /// already deregistered at that point.
    int cancel_custom_event(event_id event, void **parg = NULL);
/// @}

/// \name Accessors
/// @{
public:
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Indicates whether the event handler has one or more custom events
    /// registered for the given code.
    ///
    /// \param code The custom event code
    ///
    /// \retval 0 if no events are registered for the given code
    /// \retval 1 if one or more events are registered for the hiven code
    as_int_t has_custom_event(long code) const;

    /// \brief Indicates whether the event handler has the given event registered
    ///
    /// \param event The event id
    ///
    /// \retval 0 if the event id matches an outstanding event instance
    /// \retval 1 if the event id does not match an outstanding event instance
    as_int_t has_custom_event(event_id event) const;
/// @}

// Overrides
private:
    // The callback function, to be implemented by derived classes
    virtual int handle_custom_event(ACE_Time_Value const    &current_time
                                ,   long                    event_code
                                ,   void                    *arg)   =   0;

// Implementation
private:
    class callback_hook
        : public ACE_Event_Handler
    {
    public:
        callback_hook(custom_event_handler *ceh, ACE_Reactor *reactor, int priority)
            : ACE_Event_Handler(reactor, priority)
            , m_ceh(ceh)
        {
            ACESTL_MESSAGE_ASSERT("reactor may not be null", NULL != reactor);
        }
        ~callback_hook() stlsoft_throw_0()
        {
            reactor()->remove_handler(this, ACE_Event_Handler::ALL_EVENTS_MASK | ACE_Event_Handler::DONT_CALL);
        }

    private:
        virtual int handle_timeout( ACE_Time_Value const    &current_time
                                ,   const void              *arg)
        {
            return m_ceh->handle_callback_timeout(current_time, const_cast<void*>(arg));
        }

    private:
        custom_event_handler    *const  m_ceh;

    private:
        callback_hook(callback_hook const &);
        callback_hook &operator =(callback_hook const &);
    };

    friend class callback_hook;

    // Each entry consists of the notification code and the actual arg
    struct event_info
    {
        long        code;   //!< The event code
        void        *arg;   //!< The custom event argument
        event_id    id;     //!< The id of the event registered in the reactor

        event_info(long code_, void *arg_)
            : code(code_)
            , arg(arg_)
            , id(NULL)
        {}
    };

    typedef ::stlsoft::shared_ptr<event_info>    info_ptr;

    // receiver of the callback hook's handle_timeout call,
    int handle_callback_timeout(ACE_Time_Value const    &current_time
                            ,   void                    *arg);

    // This is used to avoid compiler warnings about using 'this' in member
    // initialiser lists
    class_type *get_this_()
    {
        return this;
    }

    // Invariant
    as_bool_t   is_valid() const;

    //
    event_id    schedule_event_(event_info *entry, ACE_Time_Value const &delay);
    as_int_t    cancel_event_(event_id );

// Members
private:
    // There are two maps.
    //
    // 1. The long=>event_info* map is used for registration/deregistration. Because
    // it owns the entries it uses the associative_container_veneer
    //
    // 2. The event_info*=>long map is used

    typedef ::std::map<event_id, info_ptr>      event_map_type;
    typedef ::std::map<long, event_map_type>    event_code_map_type;

    callback_hook       m_callbackHook;
    event_code_map_type m_entries;

// Not to be implemented
private:
    custom_event_handler(class_type const &);
    class_type &operator =(class_type const &);
};

////////////////////////////////////////////////////////////////////////////////

/// @} // acestl_messaging_library

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/custom_event_handler_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#ifdef STLSOFT_COMPILER_IS_MSVC
# if _MSC_VER >= 1200
#  pragma warning(push)
# endif /* compiler */
# pragma warning(disable : 4702)
#endif /* compiler */

inline custom_event_handler::event_id custom_event_handler::schedule_event_(event_info *entry, ACE_Time_Value const &delay)
{
    long    timerId =   m_callbackHook.reactor()->schedule_timer(&m_callbackHook, entry, delay);

    ACESTL_MESSAGE_ASSERT("Unexpected negative value", timerId >= -1 || -1 == timerId);

    return (-1 == timerId) ? NULL : reinterpret_cast<event_id>(static_cast<as_size_t>(1 + timerId));
}

inline as_int_t custom_event_handler::cancel_event_(custom_event_handler::event_id id)
{
    ACESTL_ASSERT(NULL != id);

    return m_callbackHook.reactor()->cancel_timer(static_cast<long>(reinterpret_cast<as_size_t>(id - 1)));
}

inline as_bool_t custom_event_handler::is_valid() const
{
    return true;
}

inline custom_event_handler::custom_event_handler(  ACE_Reactor *reactor    /* =   ACE_Reactor::instance() */
                                                ,   int         priority    /* =   ACE_Event_Handler::LO_PRIORITY */)
    : parent_class_type(reactor, priority)
    , m_callbackHook(get_this_(), reactor, priority)
{
    ACESTL_ASSERT(NULL != reactor);
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());
}

inline custom_event_handler::~custom_event_handler() stlsoft_throw_0()
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    ACESTL_MESSAGE_ASSERT("Custom event handler destroyed with outstanding entries: derived classes should cancel all notifications", m_entries.empty());
}

inline custom_event_handler::event_id custom_event_handler::schedule_custom_event(long code, ACE_Time_Value const &delay, void *arg /* = 0 */)
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    // Create an event, and then schedule it.

    event_info  *entry_;

    ACE_NEW_NORETURN(entry_, event_info(code, arg));

    if(NULL == entry_)
    {
        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        ACE_ERROR_RETURN(   (   LM_ALERT
                            ,   ACE_TEXT("(%P|%t) out of memory"))
                        ,   0);
    }
    else
    {
        info_ptr    entry(entry_);
        event_id    timerId =   schedule_event_(entry.get(), delay);

        if(NULL == timerId)
        {
            ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

            ACE_ERROR_RETURN(   (   LM_ALERT
                                ,   ACE_TEXT("(%P|%t) timer registration failed"))
                            ,   0);
        }
        else
        {
            entry->id = timerId;

            try
            {
                // Benign if leaves code but fails to add event
                m_entries[code][timerId] = entry;
            }
            catch(std::bad_alloc &) // This clause is fine, since if bad_alloc not thrown, no foul
            {
                cancel_event_(timerId);

                ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

                ACE_OS::last_error(ENOMEM);
                ACE_ERROR_RETURN(   (   LM_ALERT
                                    ,   ACE_TEXT("(%P|%t) out of memory"))
                                ,   0);
            }
            catch(std::exception &x)
            {
                cancel_event_(timerId);

                ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

                ACE_ERROR_RETURN(   (   LM_ALERT
                                    ,   ACE_TEXT("(%P|%t) event scheduling failed: %s")
                                    ,   x.what())
                                ,   0);
            }

            ACESTL_MESSAGE_ASSERT("event not in handler", this->has_custom_event(timerId));

            ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

            return timerId;
        }
    }
}

inline custom_event_handler::event_id custom_event_handler::schedule_custom_event(long code, void *arg /* = 0 */)
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    return schedule_custom_event(code, ACE_Time_Value(0), arg);
}

inline int custom_event_handler::cancel_custom_events(long code, custom_event_handler::cancelled_event_code_fn pfn, void *param)
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    event_code_map_type::iterator    it  =   m_entries.find(code);

    if(m_entries.end() == it)
    {
        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        return 0;
    }
    else
    {
        // Now need to cancel the timers for all the events in the code map
        event_map_type              &codes  =   (*it).second;
        event_map_type::iterator    begin   =   codes.begin();
        event_map_type::iterator    end     =   codes.end();
        as_int_t                    n;

        for(n = 0; begin != end; ++begin)
        {
            info_ptr    entry   =   (*begin).second;

            if(NULL != pfn)
            {
                (*pfn)(param, entry->code, entry->id, entry->arg);
            }

            if(cancel_event_(entry->id))
            {
                ++n;
            }
        }

        m_entries.erase(it);

        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        return n;
    }
}

inline int custom_event_handler::cancel_custom_events(long code)
{
    return cancel_custom_events(code, NULL, NULL);
}

inline int custom_event_handler::cancel_custom_event(custom_event_handler::event_id event, void **parg /* = NULL */)
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    /// TODO: Maybe improve the performance of this later, perhaps by having a second map of id=>entry

    event_code_map_type::iterator    be  =   m_entries.begin();
    event_code_map_type::iterator    ee  =   m_entries.end();

    for(; be != ee; ++be)
    {
        event_map_type              &event_map  =   (*be).second;
        event_map_type::iterator    it          =   event_map.find(event);

        if(event_map.end() != it)
        {
            if(NULL != parg)
            {
                *parg = (*it).second->arg;
            }

            event_map.erase(it);

            return cancel_event_(event);
        }
    }

    return 0;
}

inline as_int_t custom_event_handler::has_custom_event(long code) const
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    event_code_map_type::const_iterator  it  =   m_entries.find(code);

    return (m_entries.end() != it) ? static_cast<as_int_t>((*it).second.size()) : 0;
}

inline as_int_t custom_event_handler::has_custom_event(event_id event) const
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    /// TODO: Maybe improve the performance of this later, perhaps by having a second map of id=>entry

    event_code_map_type::const_iterator  be      =   m_entries.begin();
    event_code_map_type::const_iterator  ee      =   m_entries.end();

    for(; be != ee; ++be)
    {
        event_map_type const            &event_map  =   (*be).second;
        event_map_type::const_iterator  it          =   event_map.find(event);

        if(event_map.end() != it)
        {
            return 1;
        }
    }

    return 0;
}

inline int custom_event_handler::handle_callback_timeout(ACE_Time_Value const &current_time, void *arg)
{
    ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

    event_info const                *entry  =   static_cast<event_info const*>(arg);
    event_code_map_type::iterator   itc     =   m_entries.find(entry->code);

    // Is it one of ours?
    if(m_entries.end() == itc)
    {
        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        ACE_ERROR_RETURN(   (   LM_ALERT
                            ,   ACE_TEXT("(%P|%t) could not locate callback entry for that code"))
                        ,   0); // NOTE: returns 0, so as not to cause the event handler to be de-registered
    }
    else
    {
        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        // Yes it is. So ...
        event_map_type              &event_map  =   (*itc).second;
        event_map_type::iterator    ite         =   event_map.find(entry->id);

        ACESTL_ASSERT(event_map.end() != ite);

        // ... keep the entry alive, and ...
        info_ptr    ep = (*ite).second;

        // ... we erase the entry, and ...
        event_map.erase(ite);

        // ... check whether we need to erase the entries map, and ...
        if(event_map.empty())
        {
            m_entries.erase(itc);
        }

        ACESTL_MESSAGE_ASSERT("invariant violation", is_valid());

        // ... then call the handler
        return this->handle_custom_event(current_time, entry->code, entry->arg);
    }
}

#ifdef STLSOFT_COMPILER_IS_MSVC
# if _MSC_VER >= 1200
#  pragma warning(push)
# else /* ? compiler */
#  pragma warning(default : 4702)
# endif /* _MSC_VER */
#endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_HPP_CUSTOM_EVENT_HANDLER */

/* ////////////////////////////////////////////////////////////////////////// */