/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/must_init.hpp
 *
 * Purpose:     Simple class that .
 *
 * Created:     18th June 2006
 * Updated:     18th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/must_init.hpp
 *
 * \brief [C++ only] Definition of stlsoft::must_init class template.
 *  (\reg group__library__utility "Utility" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MUST_INIT_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MUST_INIT_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MUST_INIT_REVISION    1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MUST_INIT_EDIT        1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Algorithms
 */

/** \brief Class template that forces an instance of a (fundamental) type to
 *    be initialised.
 *
 * \ingroup group__library__utility
 */
template <typename T>
class must_init
{
/// \name Member Types
/// @{
public:
    /// \brief The wrapped type
    typedef T               value_type;
    /// \brief The current instantiation of the type
    typedef must_init<T>    class_type;
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructor
    ss_explicit_k must_init(T t)
        : value(t)
    {}

    /// \brief Implicit conversion to the wrapped type
    operator value_type const &() const
    {
        return value;
    }

    /// \brief Implicit conversion to the wrapped type
    operator value_type &()
    {
        return value;
    }
/// @}

/// \name Members
/// @{
public:
    /// \brief The underlying value
    ///
    ///  \remarks Since the purpose of must_init is to guard against a
    ///   forgotten initialisation in composition involving fundamental
    ///   types, rather than encapsulation in any wider sense, the member
    ///   value is public, to simplify manipulation of the actual value by
    ///   its encapsulating class, thereby avoiding all the
    ///   (compiler-dependent) hassles attendant with implicit conversion to
    ///   reference types.
    value_type  value;
/// @}
};

////////////////////////////////////////////////////////////////////////////////
// Specialisations

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>bool</code>.
typedef must_init<bool>                 bool_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>char</code>.
typedef must_init<char>                 char_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>wchar_t</code>.
typedef must_init<wchar_t>              wchar_t_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>signed char</code>.
typedef must_init<signed char>          signed_char_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>unsigned char</code>.
typedef must_init<unsigned char>        unsigned_char_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>short</code>.
typedef must_init<short>                short_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>unsigned short</code>.
typedef must_init<unsigned short>       unsigned_short_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>int</code>.
typedef must_init<int>                  int_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>unsigned int</code>.
typedef must_init<unsigned int>         unsigned_int_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>long</code>.
typedef must_init<long>                 long_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>unsigned long</code>.
typedef must_init<unsigned long>        unsigned_long_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>float</code>.
typedef must_init<float>                float_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>double</code>.
typedef must_init<double>               double_init_t;

/// \brief Specialisation of \link stlsoft::must_init must_init\endlink for <code>long double</code>.
typedef must_init<long double>          long_double_init_t;



inline bool operator !(bool_init_t const &b)
{
    return !b.value;
}


////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/must_init_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */

/* ////////////////////////////////////////////////////////////////////////// */
