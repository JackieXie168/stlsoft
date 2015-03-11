/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/enumeration_policies.hpp (formerly comstl/enumerator_policies.hpp; comstl_enumerator_policies.h; originally part of comstl_enum_sequence.h)
 *
 * Purpose:     Policies for enumerator interface handling.
 *
 * Created:     20th December 2003
 * Updated:     15th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2005, Matthew Wilson and Synesis Software
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


/// \file comstl/enumeration_policies.hpp
///
/// Policies for enumerator interface handling.

#ifndef COMSTL_INCL_COMSTL_HPP_ENUMERATION_POLICIES
#define COMSTL_INCL_COMSTL_HPP_ENUMERATION_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_ENUMERATION_POLICIES_MAJOR       5
# define COMSTL_VER_COMSTL_HPP_ENUMERATION_POLICIES_MINOR       1
# define COMSTL_VER_COMSTL_HPP_ENUMERATION_POLICIES_REVISION    1
# define COMSTL_VER_COMSTL_HPP_ENUMERATION_POLICIES_EDIT        20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS
# include <comstl/refcount_functions.h> // safe_release, release_set_null
#endif /* !COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_HPP_EXCEPTIONS
#  include <comstl/exceptions.hpp>     // exception base classes
# endif /* !COMSTL_INCL_COMSTL_HPP_EXCEPTIONS */
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup comstl_itf_library Interface Library
/// \ingroup COMSTL libraries
/// \brief This library provides facilities for manipulating COM interfaces
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT

/// Exception class thrown when Clone() method fails
// [[synesis:class:exception: comstl::clone_failure]]
class clone_failure
    : public com_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef com_exception       parent_class_type;
    /// The type of this class
    typedef clone_failure       class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given HRESULT code
    ss_explicit_k clone_failure(HRESULT hr) stlsoft_throw_0()
        : parent_class_type(hr)
    {}
/// @}

/// \name Accessors
/// @{
public:
    /// \brief Returns a human-readable description of the exceptional condition
#if defined(STLSOFT_COMPILER_IS_DMC)
    char const  *what() const throw()
#else /* ? compiler */
    char const  *what() const stlsoft_throw_0()
#endif /* compiler */
    {
        return "Request to clone enumerator failed";
    }
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}
};

#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */

/// Policy type that causes COM enumerator cloning according the STL Input Iterator concept
///
/// \param I The enumeration interface
template<ss_typename_param_k I>
struct input_cloning_policy
{
public:
    typedef I                                       interface_type;
    typedef interface_type                          *value_type;
    typedef comstl_ns_qual_std(input_iterator_tag)  iterator_tag_type;

public:
    /// "Clones" the given COM enumerator interface according to the Input Iterator concept
    static interface_type *clone(interface_type *src)
    {
        interface_type *ret =   src;

        safe_addref(ret);

        return ret;
    }
};

/// Policy type that causes COM enumerator cloning according the STL Forward Iterator concept
///
/// \param I The enumeration interface
template<ss_typename_param_k I>
struct forward_cloning_policy
{
public:
    typedef I                                           interface_type;
    typedef interface_type                              *value_type;
    typedef comstl_ns_qual_std(forward_iterator_tag)    iterator_tag_type;

public:
    /// "Clones" the given COM enumerator interface according to the Forward Iterator concept
    static interface_type *clone(interface_type const *src)
    {
        interface_type  *ret;

        if(NULL == src)
        {
            ret = NULL;
        }
        else
        {
            HRESULT hr  =   const_cast<interface_type*>(src)->Clone(&ret);

            if(FAILED(hr))
            {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
                throw clone_failure(hr);
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
                ret = NULL;
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }

        return ret;
    }
};

/// Policy type that causes COM enumerator cloning according the best available STL Iterator concept
///
/// \param I The enumeration interface
template<ss_typename_param_k I>
struct degenerate_cloning_policy
{
public:
    typedef I                                       interface_type;
    typedef interface_type                          *value_type;
    typedef comstl_ns_qual_std(input_iterator_tag)  iterator_tag_type;

public:
    /// "Clones" the given COM enumerator interface according to the best available concept
    static interface_type *clone(interface_type *src)
    {
        interface_type  *ret;

        if(NULL == src)
        {
            ret = NULL;
        }
        else if(FAILED(src->Clone(&ret)))
        {
            ret = src;

            safe_addref(ret);
        }

        return ret;
    }
};

/// Adapts a value policy to a function object based interface
///
/// \param P The value policy (e.g. BSTR_policy, VARIANT_policy, FORMATETC_policy)
template <ss_typename_param_k P>
struct policy_adaptor
    : public P
{
public:
    typedef ss_typename_type_k P::value_type    value_type;

public:
    /// The initialisation function object type
    struct init_element
    {
        /// The function call operator, which causes the value to be initialised
        void operator ()(value_type &v) const
        {
            P::init(&v);
        }
    };
    /// The copy function object type
    struct copy_element
    {
        /// The function call operator, which causes the destination to be copied from the source
        void operator ()(value_type &dest, value_type const &src) const
        {
            P::copy(&dest, &src);
        }
    };
    /// The clear function object type
    struct clear_element
    {
        /// The function call operator, which causes the value to be cleared
        void operator ()(value_type &v) const
        {
            P::clear(&v);
        }
    };
};


/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_itf_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_ENUMERATION_POLICIES */

/* ////////////////////////////////////////////////////////////////////////// */
