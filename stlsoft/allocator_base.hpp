/* ////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/allocator_base.hpp (formerly stlsoft_allocator_base.h)
 *
 * Purpose:     Allocator commmon features.
 *
 * Created:     20th August 2003
 * Updated:     21st January 2006
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


/// \file stlsoft/allocator_base.hpp
///
/// Allocator commmon features.

#ifndef STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE
#define STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_BASE_MAJOR       3
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_BASE_MINOR       4
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_BASE_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_ALLOCATOR_BASE_EDIT        24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SAP_CAST
# include <stlsoft/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SAP_CAST */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */
#if defined(__STLSOFT_CF_THROW_BAD_ALLOC) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1100)
# include <new>         // for placement new, std::bad_alloc
#endif /* __STLSOFT_CF_THROW_BAD_ALLOC || _MSC_VER < 1100) */

/* ////////////////////////////////////////////////////////////////////////////
 * Allocator compatibilities
 */

/* stl-like allocator classes need deallocate to use void *
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
 *
 * Note: this should be resolving on the library, not the compiler
 */
#define STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER   /* This is standard behaviour */

/* stl-like allocator classes need a _Charalloc method
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
 *
 * Note: this should be resolving on the library, not the compiler
 */
#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# undef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD           /* This is NOT standard behaviour */
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */


#if defined(STLSOFT_COMPILER_IS_DMC)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#elif (   defined(STLSOFT_COMPILER_IS_INTEL) || \
          defined(STLSOFT_COMPILER_IS_MSVC)) && \
      (   _MSC_VER >= 1100 && \
          _MSC_VER < 1300)
# undef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
# define STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#endif /* compiler */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#  undef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* stl-like allocator classes' allocate() method takes a second "hint" parameter
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
 *
 * Note: this should be resolving solely on the library (and version), and not involving the compiler
 */
#define STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT  /* This is standard behaviour */

#if defined(STLSOFT_COMPILER_IS_DMC)
# if defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
#  undef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
# endif /* std library */
#endif /* compiler */


/* stl-like allocator classes' deallocate() method takes a second "count" parameter
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
 *
 * Note: this should be resolving solely on the library (and version), and not involving the compiler
 */
#define STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT   /* This is standard behaviour */

#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER < 1100
# undef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
#endif /* compiler */


/* stl-like allocator classes use the rebind mechanism
 *
 * Discriminated symbol is STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
 *
 * Use this symbol when determining whether to provide rebind for an allocator
 */

#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT
# define STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT     /* This is standard behaviour */
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT */

#if (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ < 0x0836) || \
    (   (   defined(STLSOFT_COMPILER_IS_INTEL) || \
            defined(STLSOFT_COMPILER_IS_MSVC)) && \
        _MSC_VER < 1300) || \
    defined(STLSOFT_COMPILER_IS_WATCOM)
# undef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
#endif /* _MSC_VER */

/* std::allocator defines a rebind
 *
 * Discriminated symbol is STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
 *
 * Note: Effectively, this can be determines whether _any_ allocator supports rebind.
 *
 * Use this symbol when determining whether to use rebind on an allocator
 */

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
# define STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT    /* This is standard behaviour */
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

#if defined(STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT)
 /* Now work out which libs _don't_ have it */
# if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC)
#  if STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_0
#   undef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#  endif /* STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION */
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_MSL)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI_GNU)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_RW)
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_WATCOM_PATCH
# else /* ? library */
#  error Standard library not recognised
# endif /* library */
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Obsolete forwarding #defines
 */

#ifdef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
# define __STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
#endif /* STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */

#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# define __STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */

#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
# define __STLSOFT_CF_ALLOCATOR_ALLOCATE_HAS_HINT
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
# define __STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
# define __STLSOFT_CF_ALLOCATOR_DEALLOCATE_HAS_OBJECTCOUNT
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */


// TODO: This needs to be moved to stlsoft_cccap_*.h

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
# define STLSOFT_CF_COMPILER_SUPPORTS_CRTP
#endif /* !STLSOFT_COMPILER_IS_WATCOM */

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
/// \ingroup libraries
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types

/// \weakgroup stlsoft_allocator_library Allocator Library (STLSoft)
/// \ingroup STLSoft libraries_allocator
/// \brief This library provides STL-compatible <code><b>allocator</b></code> types
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// STL Allocator base class adaptor, providing much of the boilerplate
/// functionality of an STL-compliant Allocator class.
///
/// \note This uses the SCTP/CRTP (Simulated Compile-time Polymorphism / Curiously
/// Recurring Template Pattern) technique, such that derived classes inherit from
/// parameterisations of the adaptor template which specify their fully derived
/// template-id as the first parameter
///
/// \note By default, an allocation failure results in a thrown std::bad_alloc. If
/// the compiler does not throwing std::bad_alloc by default, this behaviour can be
/// forced by defining STLSOFT_FORCE_ATORS_THROW_BAD_ALLOC. std::bad_alloc can be
/// suppressed in all circumstances by defining STLSOFT_FORCE_ATORS_RETURN_NULL.
///
/// \param T The allocator value_type
/// \param A The adapted/derived allocator type

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
class allocator_base
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                   value_type;
    /// The type of the current parameterisation
    typedef allocator_base<T, A>                class_type;
    /// The pointer type
    typedef value_type                          *pointer;
    /// The non-mutating (const) pointer type
    typedef value_type const                    *const_pointer;
    /// The reference type
    typedef value_type                          &reference;
    /// The non-mutating (const) reference type
    typedef value_type const                    &const_reference;
    /// The difference type
    typedef ptrdiff_t                           difference_type;
    /// The size type
    typedef ss_size_t                           size_type;
private:
    /// The type used in deallocate()
#ifdef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
    typedef pointer                             deallocate_pointer;
#else /* ? STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */
    typedef void                                *deallocate_pointer;
#endif /* STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */
private:
#if defined(STLSOFT_CF_COMPILER_SUPPORTS_CRTP) 
    typedef A                                   concrete_allocator_type;
#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_CRTP */
    typedef class_type                          concrete_allocator_type;
private:
    virtual void    *do_allocate(size_type n, void const *hint) = 0;
    virtual void    do_deallocate(void *pv, size_type n) = 0;
    virtual void    do_deallocate(void *pv) = 0;
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_CRTP */
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the maximum number of allocatable entities
    size_type max_size() const stlsoft_throw_0()
    {
        return static_cast<size_type>(-1) / sizeof(value_type);
    }
/// @}

/// \name Conversion functions
/// @{
public:
    /// Returns the address corresponding to the given reference
    ///
    /// \param x A reference to a \c value_type instance whose address will be calculated
    pointer address(reference x) const stlsoft_throw_0()
    {
        return &x;
    }
    /// Returns the address corresponding to the given non-mutable (const) reference
    ///
    /// \param x A non-mutable (const) reference to a \c value_type instance whose address will be calculated
    const_pointer address(const_reference x) const stlsoft_throw_0()
    {
        return &x;
    }
/// @}

/// \name Allocation
/// @{
public:
    /// Allocates a block of memory sufficient to store \c n elements of type \c value_type
    ///
    /// \param n The number of elements to allocate
    /// \param hint A hint to enhance localisation
    /// \return The allocated block, or the null pointer (if the allocation fails and the 
    ///   translator does not support throwing exceptions upon memory exhaustion)
    pointer allocate(size_type n, void const *hint = NULL)
    {
        void    *p  =   static_cast<concrete_allocator_type*>(this)->do_allocate(n, hint);

#if !defined(STLSOFT_FORCE_ATORS_RETURN_NULL) && \
    (   defined(STLSOFT_FORCE_ATORS_THROW_BAD_ALLOC) || \
        defined(__STLSOFT_CF_THROW_BAD_ALLOC))
        if(p == NULL)
        {
            throw stlsoft_ns_qual_std(bad_alloc)();
        }
#endif /* bad_alloc ?  */

        return static_cast<pointer>(p);
    }

#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
    /// The type used in deallocate
    char *_Charalloc(size_type n)
    {
        return sap_cast<char*>(allocate(n, NULL));
    }
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */

    /// Deallocates a pointer
    ///
    /// \param p The memory block to deallocate
    /// \param n The number of blocks to deallocate
    void deallocate(deallocate_pointer p, size_type n)
    {
        static_cast<concrete_allocator_type*>(this)->do_deallocate(p, n * sizeof(value_type));
    }

    /// Deallocates a pointer
    ///
    /// \param p The memory block to deallocate
    void deallocate(deallocate_pointer p)
    {
        static_cast<concrete_allocator_type*>(this)->do_deallocate(p);
    }
/// @}

/// \name Object initialisation
/// @{
public:
    /// In-place constructs an instance of the \c value_type, with the given value
    ///
    /// \param p The location in which to construct the instance
    /// \param x The value with which to copy construct the instance
    void construct(pointer p, value_type const &x)
    {
        STLSOFT_ASSERT(NULL != p);

        new(p) value_type(x);
    }

    /// In-place constructs an instance of the \c value_type
    ///
    /// \param p The location in which to construct the instance
    void construct(pointer p)
    {
        STLSOFT_ASSERT(NULL != p);

        new(p) value_type();
    }

    /// In-place destroys an instance
    ///
    /// \param p The instance whose destructor is to be called
    void destroy(pointer p) stlsoft_throw_0()
    {
        STLSOFT_ASSERT(NULL != p);

        STLSOFT_DESTROY_INSTANCE(T, value_type, p);
    }
/// @}

// Not to be implemented
private:
//    class_type const &operator =(class_type const &rhs);
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_allocator_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_ALLOCATOR_BASE */

/* ////////////////////////////////////////////////////////////////////////// */
