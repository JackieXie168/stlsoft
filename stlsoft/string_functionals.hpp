/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string_functionals.hpp
 *
 * Purpose:     String function objects
 *
 * Created:     
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/string_functionals.hpp
///
/// String function objects

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_FUNCTIONALS
#define STLSOFT_INCL_STLSOFT_HPP_STRING_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_STRING_FUNCTIONALS_MAJOR       1
# define STLSOFT_VER_STLSOFT_HPP_STRING_FUNCTIONALS_MINOR       3
# define STLSOFT_VER_STLSOFT_HPP_STRING_FUNCTIONALS_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_STRING_FUNCTIONALS_EDIT        16
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_COMO:
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef _STLSOFT_STRING_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _STLSOFT_STRING_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _STLSOFT_STRING_FUNCTIONALS_NO_STD */
#include <string.h>

#ifdef STLSOFT_UNITTEST
# include <algorithm>
# include <string>
# include <vector>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("TODO: Need a function that can do quoting (or anything else)"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/* /////////////////////////////////////////////////////////////////////////////
 * Functors
 */


#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This should be moved to stlsoft/string/iterators.hpp"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        >
struct string_concatenation_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, ss_ptrdiff_t, void, void>
{
public:
    typedef S1                                      first_string_type;
    typedef S2                                      second_string_type;
    typedef string_concatenation_iterator<S1, S2>   class_type;

public:
    string_concatenation_iterator(S1 &s, S2 const &delim)
        : m_s(s)
        , m_delim(delim)
        , m_delimCopy()
    {}
    string_concatenation_iterator(int, S1 &s, S2 const &delim)
        : m_s(s)
        , m_delim(m_delimCopy)
        , m_delimCopy(delim)
    {}
#if 0
    string_concatenation_iterator(class_type const &rhs)
        : m_s(m_s)
        , m_delim(m_delimCopy)
        , m_delimCopy(m_delimCopy)
    {}
#endif /* 0 */

public:
    template <ss_typename_param_k S3>
    void operator =(S3 const &value)
    {
        if(0 != c_str_len(m_s))
        {
            m_s.append(m_delim);
        }
        m_s.append(c_str_ptr(value));
    }

    string_concatenation_iterator &operator *()
    {
        return *this;
    }

    string_concatenation_iterator &operator ++()
    {
        return *this;
    }

    string_concatenation_iterator operator ++(int)
    {
        if(&m_delim == &m_delimCopy)
        {
            return class_type(-1, m_s, m_delim);
        }
        else
        {
            return class_type(m_s, m_delim);
        }
    }

private:
    S1          &m_s;
    S2 const    &m_delim;
    S1          m_delimCopy;

private:
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED) && \
    !defined(STLSOFT_COMPILER_IS_COMO)

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This needs to be changed, and to make the class properly copy assignable"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */


    /// \note This has have void return type, otherwise VC++ 7.0 has a cow
    void operator =(class_type const &);
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */
};

template<   ss_typename_param_k S1
        ,   ss_typename_param_k S2
        >
inline string_concatenation_iterator<S1, S2> string_concatenator(S1 &s, S2 const &delim)
{
    return string_concatenation_iterator<S1, S2>(s, delim);
}

#if (   !defined(STLSOFT_COMPILER_IS_GCC) || \
        __GNUC__ >= 3) && \
    (   !defined(STLSOFT_COMPILER_IS_INTEL) || \
        !defined(_WIN32) || \
        _MSC_VER > 1300) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1300)
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline string_concatenation_iterator<S, S> string_concatenator(S &s, C const *delim)
{
    return string_concatenation_iterator<S, S>(-1, s, delim);
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline string_concatenation_iterator<S, S> string_concatenator(S &s, C *delim)
{
    return string_concatenation_iterator<S, S>(-1, s, delim);
}
#endif /* compiler */

#ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORTx
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_size_t           N
        >
inline string_concatenation_iterator<S, S> string_concatenator(S &s, C (&delim)[N])
{
    return string_concatenation_iterator<S, S>(-1, s, delim);
}
#endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/// Unary function object that returns a quoted form of its argument, if
/// the argument contains spaces
template <ss_typename_param_k S>
struct quoter
    : public stlsoft_ns_qual_std(unary_function)<char const*, void>
{
public:
    S operator()(S const &s) const
    {
        if(NULL != ::strpbrk(c_str_ptr(s), " \t\""))
        {
            // Check whether it has quotes. If it does, we'll just assume it's ok
            if(NULL != ::strchr(c_str_ptr(s), '"'))
            {
                return s;
            }
            else
            {
                return '"' + s + '"';
            }
        }
        else
        {
            return s;
        }
    }
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/// \note This is a work-in-progress, and is subject to change in a later release
template <ss_typename_param_k C>
struct string_begins_with_function
    : public stlsoft_ns_qual_std(unary_function)<C const*, ss_bool_t>
{
public:

public:
    string_begins_with_function(C const *prefix)
        : m_prefix(prefix)
        , m_prefixLen(::strlen(m_prefix))
    {}

public:
    ss_bool_t operator ()(C const *line) const
    {
        return 0 == ::strncmp(line, m_prefix, m_prefixLen);
    }
    template <ss_typename_param_k S>
    ss_bool_t operator ()(S const &line) const
    {
        return operator ()(c_str_ptr(line));
    }

private:
    C const *const  m_prefix;
    const ss_size_t m_prefixLen;
};

/// \note This is a work-in-progress, and is subject to change in a later release
template <ss_typename_param_k C>
inline string_begins_with_function<C> string_begins_with(C const *prefix)
{
    return string_begins_with_function<C>(prefix);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_functionals_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////////// */
