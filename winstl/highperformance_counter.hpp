/* /////////////////////////////////////////////////////////////////////////////
 * File:        highperformance_counter.hpp (formerly winstl_highperformance_counter.h, originally MWPrfCnt.h, ::SynesisWin)
 *
 * Purpose:     WinSTL high performance counter class.
 *
 * Created:     19th October 1998
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2005, Matthew Wilson and Synesis Software
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


/// \file winstl/highperformance_counter.hpp
///
/// WinSTL high performance counter class.

#ifndef WINSTL_INCL_WINSTL_HPP_HIGHPERFORMANCE_COUNTER
#define WINSTL_INCL_WINSTL_HPP_HIGHPERFORMANCE_COUNTER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_HIGHPERFORMANCE_COUNTER_MAJOR      3
# define WINSTL_VER_WINSTL_HPP_HIGHPERFORMANCE_COUNTER_MINOR      1
# define WINSTL_VER_WINSTL_HPP_HIGHPERFORMANCE_COUNTER_REVISION   1
# define WINSTL_VER_WINSTL_HPP_HIGHPERFORMANCE_COUNTER_EDIT       67
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error winstl_highperformance_counter.h is not compatible with Visual C++ 5.0 or earlier
#endif /* _MSC_VER < 1200 */

#ifndef STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS
# include <stlsoft/limit_traits.h>          // for stlsoft::limit_traits<ss_uint64_t>::maximum()
#endif /* !STLSOFT_INCL_STLSOFT_H_LIMIT_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STATIC_INITIALISERS
# include <stlsoft/static_initialisers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STATIC_INITIALISERS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SAP_CAST
# include <stlsoft/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SAP_CAST */

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

/// \weakgroup libraries_performance Performance Library
/// \ingroup libraries
/// \brief This library provides performance measuring facilities

/// \weakgroup winstl_perf_library Performance Library (WinSTL)
/// \ingroup WinSTL libraries_performance
/// \brief This library provides performance measuring facilities for the Win32 API
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class highperformance_counter
/// \brief A performance counter that uses the high performance hardware counter on the host machine
///
/// This class provides high-resolution performance monitoring using the host machine's high performance
/// hardware counter. This class does not provide meaningful timing information on operating systems
/// that do not provide a high performance hardware counter.
class highperformance_counter
{
public:
    typedef highperformance_counter     class_type;

private:
    typedef ws_sint64_t                 epoch_type;
public:
    /// \brief The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef ws_sint64_t                 interval_type;

/// \name Construction
/// @{
public:
    static void class_init()
    {
        class_type().start();
    }
    static void class_uninit()
    {}
/// @}

// Operations
public:
    /// \brief Starts measurement
    ///
    /// Begins the measurement period
    void        start();
    /// \brief Ends measurement
    ///
    /// Ends the measurement period
    void        stop();

// Attributes
public:
    /// \brief The elapsed count in the measurement period
    ///
    /// This represents the extent, in machine-specific increments, of the measurement period
    interval_type   get_period_count() const;
    /// \brief The number of whole seconds in the measurement period
    ///
    /// This represents the extent, in whole seconds, of the measurement period
    interval_type   get_seconds() const;
    /// \brief The number of whole milliseconds in the measurement period
    ///
    /// This represents the extent, in whole milliseconds, of the measurement period
    interval_type   get_milliseconds() const;
    /// \brief The number of whole microseconds in the measurement period
    ///
    /// This represents the extent, in whole microseconds, of the measurement period
    interval_type   get_microseconds() const;

// Implementation
private:
    static interval_type    frequency_();
    static interval_type    query_frequency_();

// Members
private:
    epoch_type  m_start;    // start of measurement period
    epoch_type  m_end;      // End of measurement period
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if !defined(STLSOFT_COMPILER_IS_DMC) && \
     (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
         _MSC_VER >= 1200)
static stlsoft_ns_qual(class_constructor)<highperformance_counter>  s_highperformance_counter_class_constructor(&highperformance_counter::class_init, NULL);
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/highperformance_counter_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline /* static */ highperformance_counter::interval_type highperformance_counter::query_frequency_()
{
    interval_type   frequency;

    // If no high-performance counter is available ...
    if( !::QueryPerformanceFrequency(sap_cast<LARGE_INTEGER*>(&frequency)) ||
        frequency == 0)
    {
        // ... then set the divisor to be the maximum value, guaranteeing that
        // the timed periods will always evaluate to 0.
        frequency = stlsoft_ns_qual(limit_traits)<interval_type>::maximum();
    }

    return frequency;
}

inline /* static */ highperformance_counter::interval_type highperformance_counter::frequency_()
{
#if !defined(STLSOFT_STRICT) && \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(push)
# pragma warning(disable : 4640)   /* "construction of local static object is not thread-safe" - since it is here! (As long as one uses a 'conformant' allocator) - maybe use a spin_mutex in future */
#endif /* _MSC_VER >= 1310 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
    interval_type           s_frequency = query_frequency_();
#else /* ? STLSOFT_COMPILER_IS_BORLAND */
    static interval_type    s_frequency = query_frequency_();
#endif /* STLSOFT_COMPILER_IS_BORLAND */

#if !defined(STLSOFT_STRICT) && \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* _MSC_VER >= 1310 */

    WINSTL_ASSERT(0 != s_frequency);

    return s_frequency;
}

// Operations
inline void highperformance_counter::start()
{
    ::QueryPerformanceCounter(sap_cast<LARGE_INTEGER*>(&m_start));
}

inline void highperformance_counter::stop()
{
    ::QueryPerformanceCounter(sap_cast<LARGE_INTEGER*>(&m_end));
}

// Attributes
inline highperformance_counter::interval_type highperformance_counter::get_period_count() const
{
    return static_cast<interval_type>(m_end - m_start);
}

inline highperformance_counter::interval_type highperformance_counter::get_seconds() const
{
    return get_period_count() / frequency_();
}

inline highperformance_counter::interval_type highperformance_counter::get_milliseconds() const
{
    highperformance_counter::interval_type  result;
    highperformance_counter::interval_type  count   =   get_period_count();

    if(count < __STLSOFT_GEN_SINT64_SUFFIX(0x20C49BA5E353F7))
    {
        result = (count * interval_type(1000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000);
    }

    return result;
}

inline highperformance_counter::interval_type highperformance_counter::get_microseconds() const
{
    highperformance_counter::interval_type  result;
    highperformance_counter::interval_type  count   =   get_period_count();

    if(count < __STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
    {
        result = (count * interval_type(1000000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000000);
    }

    return result;
}

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_perf_library

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

#endif /* !WINSTL_INCL_WINSTL_HPP_HIGHPERFORMANCE_COUNTER */

/* ////////////////////////////////////////////////////////////////////////// */