/* /////////////////////////////////////////////////////////////////////////
 * File:        array_policies.hpp (formerly stlsoft_array_policies.h)
 *
 * Purpose:     Contains the construction policies for the array (fixed and
 *              frame) classes.
 *
 * Created:     1st September 2002
 * Updated:     10th June 2006
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


/// \file stlsoft/array_policies.hpp
///
/// Contains the construction policies for the array (fixed and frame) classes.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ARRAY_POLICIES
#define STLSOFT_INCL_STLSOFT_HPP_ARRAY_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ARRAY_POLICIES_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_ARRAY_POLICIES_MINOR     2
# define STLSOFT_VER_STLSOFT_HPP_ARRAY_POLICIES_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_ARRAY_POLICIES_EDIT      121
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#include <string.h>     // for memcpy()

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Construction policy classes
 */

/// Traits class that controls whether elements in STLSoft arrays are in-place constructed and destroyed
///
/// Defaults to true, indicating that construction and destruction will be
/// performed, but is false for all supported integral and boolean types
///
/// \param T The type
template <ss_typename_param_k T>
struct do_construction
{
    enum
    {
        value = true //!< If \c true the array elements are constructed, otherwise they are not
    };

    typedef yes_type    type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_sint8_t>  { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_uint8_t>  { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_sint16_t> { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_uint16_t> { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_sint32_t> { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_uint32_t> { enum { value = false }; typedef no_type type; };

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_sint64_t> { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_uint64_t> { enum { value = false }; typedef no_type type; };
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<float>       { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<double>      { enum { value = false }; typedef no_type type; };

STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<long double> { enum { value = false }; typedef no_type type; };

#ifdef STLSOFT_CF_NATIVE_BOOL_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct do_construction<ss_bool_t>   { enum { value = false }; typedef no_type type; };
#endif /* STLSOFT_CF_NATIVE_BOOL_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// Stipulates that array elements are always constructed
struct do_construction_always
{
    enum { value = true };

    typedef yes_type    type;
};

/// Stipulates that array elements are never constructed
struct do_construction_never
{
    enum { value = false };

    typedef no_type     type;
};

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_construct_1(A &ator, T *p, ss_size_t n, yes_type)
{
    for(T *e = p + n; p != e; ++p)
    {
        ator.construct(p, T());
    }
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_construct_1(A &/* ator */, T *p, ss_size_t n, no_type)
{
#if 1
    memset(p, 0, n * sizeof(T));
#else /* ? 0 */
    stlsoft_ns_qual_std(fill_n)(p, n, 0);
#endif /* 0 */
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_construct_2(A &ator, T *p, ss_size_t n, T const &value, yes_type)
{
#if 0
    std::uninitialized_fill_n(p, n, value);
#else /* ? 0 */
    for(T *e = p + n; p != e; ++p)
    {
        ator.construct(p, value);
    }
#endif /* 0 */
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_construct_2(A &ator, T *p, ss_size_t n, T const &value, no_type)
{
    for(T *e = p + n; p != e; ++p)
    {
        memcpy(p, &value, sizeof(T));
    }
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_copy_construct_1(A &ator, T *p, T const *src, ss_size_t n, yes_type)
{
    for(T *e = p + n; p != e; ++p, ++src)
    {
        ator.construct(p, *src);
    }
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_copy_construct_1(A &/* ator */, T *p, T const *src, ss_size_t n, no_type)
{
    for(T *e = p + n; p != e; ++p, ++src)
    {
        memcpy(p, src, sizeof(T));
    }
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_destroy_1(A &ator, T *p, ss_size_t n, yes_type)
{
    for(T *e = p + n; p != e; ++p)
    {
        ator.destroy(p);
    }
}

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
void do_destroy_1(A &/* ator */, T * /* p */, ss_size_t /* n */, no_type)
{}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Helper classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        ,   ss_typename_param_k P
        >
struct array_range_initialiser
{
public:
    typedef T       value_type;
    typedef T       *pointer;
    typedef T const *const_pointer;
    typedef A       allocator_type;
    typedef P       initialisation_policy_type;
private:
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310
    typedef initialisation_policy_type::type                    yesno_type;
# else /* ? compiler */
    typedef ss_typename_type_k initialisation_policy_type::type yesno_type;
# endif /* compiler */

public:
    /// \brief Performs in-place default construction of n elements, whose first element
    /// is located at p
    ///
    /// \note If the initialisation policy is 'true', then the value_type is assumed to be
    /// of non-POD type, and therefore constructed. If 'false', then the value_type is
    /// assumed to be POD and the memory is zero-filled (via memset())
    static void construct(allocator_type &ator, pointer p, ss_size_t n)
    {
        do_construct_1(ator, p, n, yesno_type());
    }

    /// \brief Performs in-place copy construction of n elements, whose first element
    /// is located at p, where *(p + n) is set to *(src + n)
    static void copy_construct(allocator_type &ator, pointer p, const_pointer src, ss_size_t n)
    {
        do_copy_construct_1(ator, p, src, n, yesno_type());
    }

    /// \brief Performs in-place copy construction of n elements, whose first element
    /// is located at p, where each element == val
    static void construct(allocator_type &ator, pointer p, ss_size_t n, value_type const &val)
    {
        do_construct_2(ator, p, n, val, yesno_type());
    }

    static void destroy(allocator_type &ator, pointer p, ss_size_t n)
    {
        do_destroy_1(ator, p, n, yesno_type());
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ARRAY_POLICIES */

/* ////////////////////////////////////////////////////////////////////// */
