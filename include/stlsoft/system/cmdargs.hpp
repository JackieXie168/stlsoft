/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/system/cmdargs.hpp
 *
 * Purpose:     Command-line sequences class.
 *
 * Created:     25th June 2005
 * Updated:     10th January 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/system/cmdargs.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::cmdargs class
 *   (\ref group__library__system "System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS
#define STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_MAJOR       2
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_MINOR       0
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_REVISION    1
# define STLSOFT_VER_STLSOFT_SYSTEM_HPP_CMDARGS_EDIT        20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
# include <stlsoft/string/simple_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS
# include <stlsoft/string/split_functions.hpp>
#endif /* STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
# include <stlsoft/string/string_view.hpp>
#endif /* STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */
#include <utility>
#include <vector>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Facade class that presents argc+argv command line parameters as two separate
 * sequences of options (those arguments with - or -- prefixes) and values
 * (those without)
 *
 * \ingroup group__library__system
 *
 * \note The cmdargs instance maintains views onto the actual arguments in
 *   the argv array. Therefore, the behaviour is undefined if any code modifies
 *   the strings pointed to by the elements in the argv array, or repoints any
 *   of the argv elements to different strings.
 */
class cmdargs
{
public:
    typedef simple_string           string_type;
    typedef basic_string_view<char> string_view_type;

    enum
    {
            singleDash  =   1
        ,   doubleDash  =   2
    };

    struct option
    {
        string_type         m_name;
        string_type         m_value;
        int                 m_type;
        int                 m_index;
        string_view_type    m_original;

        option(string_type const &n, string_type const &v, int t, int i, string_view_type const &o)
            : m_name(n)
            , m_value(v)
            , m_type(t)
            , m_index(i)
            , m_original(o)
        {}
    };
    struct value
    {
        string_view_type    m_value;
        int                 m_index;

        value(string_view_type const &v, int i)
            : m_value(v)
            , m_index(i)
        {}
    };

    typedef option                                          options_value_type;
    typedef value                                           values_value_type;

    typedef stlsoft_ns_qual_std(vector)<options_value_type> options_type;
    typedef stlsoft_ns_qual_std(vector)<values_value_type>  values_type;

    typedef options_type::const_iterator                    const_options_iterator;
    typedef values_type::const_iterator                     const_values_iterator;

/// \name Construction
/// @{
public:
    /// \brief Constructs from argc/argv
    cmdargs(int argc, char /*const*/ **argv);
    /// \brief Releases any resources
    ~cmdargs() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// \brief non-mutating reference to the options
    options_type const      &options() const;
    /// \brief non-mutating reference to the values
    values_type const       &values() const;

    const_options_iterator  options_begin() const;
    const_options_iterator  options_end() const;

    const_values_iterator   values_begin() const;
    const_values_iterator   values_end() const;

    /// \brief The number of options
    ss_size_t   options_size() const;
    /// \brief The number of values
    ss_size_t   values_size() const;
    /// \brief The numbers options and values
    ss_size_t   size() const;
    /// \brief Indicates whether there are any options and/or values
    ss_bool_t   empty() const;
/// @}

/// \name Members
/// @{
private:
    options_type    m_options;
    values_type     m_values;
/// @}
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/cmdargs_unittest_.h"
#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline cmdargs::cmdargs(int argc, char /*const*/ **argv)
{
    for(int i = 1; i < argc; ++i)
    {
        char const  *arg    =   argv[i];

        if('-' == arg[0])
        {
            ++arg;

            const int       type    =   ('-' != arg[0]) ? singleDash : (++arg, doubleDash);
            simple_string   s0;
            simple_string   s1;

            split(arg, '=', s0, s1);

            m_options.push_back(option(s0, s1, type, i, argv[i]));
        }
        else
        {
            m_values.push_back(value(arg, i));
        }
    }
}

inline cmdargs::~cmdargs() stlsoft_throw_0()
{
}

inline cmdargs::options_type const &cmdargs::options() const
{
    return m_options;
}

inline cmdargs::values_type const &cmdargs::values() const
{
    return m_values;
}

inline cmdargs::const_options_iterator cmdargs::options_begin() const
{
    return m_options.begin();
}

inline cmdargs::const_options_iterator cmdargs::options_end() const
{
    return m_options.end();
}

inline cmdargs::const_values_iterator cmdargs::values_begin() const
{
    return m_values.begin();
}

inline cmdargs::const_values_iterator cmdargs::values_end() const
{
    return m_values.end();
}

inline ss_size_t cmdargs::options_size() const
{
    return m_options.size();
}

ss_size_t cmdargs::values_size() const
{
    return m_values.size();
}

ss_size_t cmdargs::size() const
{
    return options_size() + values_size();
}

ss_bool_t cmdargs::empty() const
{
    return 0 == size();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k S>
inline S &operator <<(S &stm, cmdargs::option const &option)
{
    static const char   s_dashes[] =
    {
            '-'
        ,   '-'
        ,   '\0'
    };
    char const      *dashes =   &s_dashes[(option.m_type == cmdargs::singleDash)];

    if(option.m_value.empty())
    {
        stm << dashes << option.m_name;
    }
    else
    {
        stm << dashes << option.m_name << '=' << option.m_value;
    }

    return stm;
}

template <ss_typename_param_k S>
inline S &operator <<(S &stm, cmdargs::value const &value)
{
    stm << value.m_value;

    return stm;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_SYSTEM_HPP_CMDARGS */

/* ////////////////////////////////////////////////////////////////////// */
