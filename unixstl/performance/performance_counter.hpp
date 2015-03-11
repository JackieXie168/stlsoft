/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/performance/performance_counter.hpp (formerly unixstl/performance/performance_counter.hpp; originally unixstl_performance_counter.h)
 *
 * Purpose:     performance_counter class.
 *
 * Created:     16th January 2002
 * Updated:     30th May 2006
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


/** \file unixstl/performance/performance_counter.hpp
 *
 * \brief [C++ only] Definition of the 
 *  \link unixstl::performance_counter performance_counter\endlink class.
 *  (\ref group__library__performance "Performance" Library.)
 */

#ifndef UNIXSTL_INCL_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER
#define UNIXSTL_INCL_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER_MAJOR      4
# define UNIXSTL_VER_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER_MINOR      0
# define UNIXSTL_VER_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER_REVISION   1
# define UNIXSTL_VER_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER_EDIT       50
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */

#include <sys/time.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

/* No STLSoft namespaces means no UNIXSTL namespaces */
#ifdef _STLSOFT_NO_NAMESPACES
# define _UNIXSTL_NO_NAMESPACES
#endif /* _STLSOFT_NO_NAMESPACES */

/* No UNIXSTL namespaces means no unixstl namespace */
#ifdef _UNIXSTL_NO_NAMESPACES
# define _UNIXSTL_NO_NAMESPACE
#endif /* _UNIXSTL_NO_NAMESPACES */

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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief A performance counter using \c gettimeofday()
 *
 * \ingroup group__library__performance
 *
 * This class provides performance monitoring functionality based around the
 * UNIX \c gettimeofday() API.
 */
class performance_counter
{
private:
    typedef us_sint64_t         epoch_type;
public:
    typedef performance_counter class_type;
    /// \brief The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef us_sint64_t         interval_type;

// Construction
public:

// Operations
public:
    /// \brief Starts measurement
    ///
    /// Begins the measurement period
    void start();
    /// \brief Ends measurement
    ///
    /// Ends the measurement period
    void stop();

// Attributes
public:
    /// \brief The elapsed count in the measurement period
    ///
    /// This represents the extent, in arbitrary units, of the measurement period
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

// Members
private:
    typedef struct timeval timeval_t;

    timeval_t   m_start;
    timeval_t   m_end;
};

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/performance_counter_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline void performance_counter::start()
{
    struct timezone tz;

    ::gettimeofday(&m_start, &tz);

    m_end   =   m_start;
}

inline void performance_counter::stop()
{
    struct timezone tz;

    ::gettimeofday(&m_end, &tz);
}

inline performance_counter::interval_type performance_counter::get_period_count() const
{
    return get_microseconds();
}

inline performance_counter::interval_type performance_counter::get_seconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs + usecs / (1000 * 1000);
}

inline performance_counter::interval_type performance_counter::get_milliseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * 1000 + usecs / 1000;
}

inline performance_counter::interval_type performance_counter::get_microseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000) + usecs;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_PERFORMANCE_HPP_PERFORMANCE_COUNTER */

/* ////////////////////////////////////////////////////////////////////// */
