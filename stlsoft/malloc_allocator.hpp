/* ////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/malloc_allocator.hpp (formerly stlsoft_malloc_allocator.h; originally MRAtors.h; ::SynesisCrt)
 *
 * Purpose:     stlsoft_malloc_allocator class - uses malloc()/free().
 *
 * Created:     2nd January 2001
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2001-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/malloc_allocator.hpp
///
/// stlsoft_malloc_allocator class - uses malloc()/free().

#ifndef STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR
#define STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_MALLOC_ALLOCATOR_MAJOR       3
# define STLSOFT_VER_STLSOFT_HPP_MALLOC_ALLOCATOR_MINOR       2
# define STLSOFT_VER_STLSOFT_HPP_MALLOC_ALLOCATOR_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_MALLOC_ALLOCATOR_EDIT        65
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE
# include <stlsoft/allocator_base.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
# include <stlsoft/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#include <stdlib.h>                     // malloc, free

/* ////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_allocator Allocator Library
/// \libraries_allocator
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types

/// \weakgroup stlsoft_allocator_library Allocator Library (STLSoft)
/// \ingroup STLSoft libraries_allocator
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// STL Allocator based on the C runtime \c malloc() & \c free() functions
///
/// \param T The value_type of the allocator
template <ss_typename_param_k T>
class malloc_allocator
    : public allocator_base<T, malloc_allocator<T> >
{
private:
    typedef allocator_base<T, malloc_allocator<T> >                 parent_class_type;
public:
    /// The parameterisation of the class
    typedef malloc_allocator<T>                                     class_type;
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    /// The pointer type
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k parent_class_type::const_pointer     const_pointer;
    /// The reference type
    typedef ss_typename_type_k parent_class_type::reference         reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
    /// The difference type
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type         size_type;

public:
#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    /// The allocator's <b><code>rebind</code></b> structure
    template <ss_typename_param_k U>
    struct rebind
    {
        typedef malloc_allocator<U>                                 other;
    };
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

/// \name Construction
/// @{
public:
    /// Default constructor
    malloc_allocator() stlsoft_throw_0()
    {}
    /// Copy constructor
#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    template <typename U>
    malloc_allocator(malloc_allocator<U> const &)
    {}
#else /* ? STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
    malloc_allocator(class_type const &)
    {}
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
/// @}

/// \name Allocation
/// @{
public:
    pointer reallocate(pointer p, size_type n, void const *hint = NULL)
    {
        STLSOFT_SUPPRESS_UNUSED(hint);

        stlsoft_constraint_must_be_pod_or_void(value_type); // Can't reallocate non-POD!

        void    *pNew   =   ::realloc(p, n * sizeof(value_type));

#ifdef __STLSOFT_CF_THROW_BAD_ALLOC
        if(pNew == NULL)
        {
            throw stlsoft_ns_qual_std(bad_alloc)();
        }
#endif /* __STLSOFT_CF_THROW_BAD_ALLOC */

        return static_cast<pointer>(pNew);
    }
/// @}

private:
    friend class allocator_base<T, malloc_allocator<T> >;

    void *do_allocate(size_type n, void const *hint)
    {
        STLSOFT_SUPPRESS_UNUSED(hint);

        return ::malloc(n * sizeof(value_type));
    }
    void do_deallocate(void *pv, size_type n)
    {
        STLSOFT_SUPPRESS_UNUSED(n);

        ::free(pv);
    }
    void do_deallocate(void *pv)
    {
        ::free(pv);
    }
};



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Specialisation for void
STLSOFT_TEMPLATE_SPECIALISATION
class malloc_allocator<void>
{
public:
    typedef void                        value_type;
    typedef malloc_allocator<void>      class_type;
    typedef void                        *pointer;
    typedef void const                  *const_pointer;
    typedef ptrdiff_t                   difference_type;
    typedef ss_size_t                   size_type;

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    /// The allocator <b><code>rebind</code></b> structure
    template <ss_typename_param_k U>
    struct rebind
    {
        typedef malloc_allocator<U>     other;
    };
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline ss_bool_t operator ==(const malloc_allocator<T> &/* lhs */, const malloc_allocator<T> &/* rhs */)
{
    return ss_true_v;
}

template <ss_typename_param_k T>
inline ss_bool_t operator !=(const malloc_allocator<T> &/* lhs */, const malloc_allocator<T> &/* rhs */)
{
    return ss_false_v;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/malloc_allocator_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_allocator_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_MALLOC_ALLOCATOR */

/* ////////////////////////////////////////////////////////////////////////// */
