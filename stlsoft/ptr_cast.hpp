/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/ptr_cast.hpp (formerly stlsoft_ptr_cast.h)
 *
 * Purpose:     A cast that throws bad_cast for dynamic pointer casting, as well
 *              as references.
 *
 * Created:     28th December 2002
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file stlsoft/ptr_cast.hpp (formerly stlsoft_ptr_cast.h)
///
/// A cast that throws bad_cast for dynamic pointer casting, as well as references.

#ifndef STLSOFT_INCL_STLSOFT_HPP_PTR_CAST
#define STLSOFT_INCL_STLSOFT_HPP_PTR_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_PTR_CAST_MAJOR     3
# define STLSOFT_VER_STLSOFT_HPP_PTR_CAST_MINOR     2
# define STLSOFT_VER_STLSOFT_HPP_PTR_CAST_REVISION  2
# define STLSOFT_VER_STLSOFT_HPP_PTR_CAST_EDIT      22
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1310
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS
# include <stlsoft/meta/base_type_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS */
#include <typeinfo>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// A cast that throws bad_cast for pointer cast failures, as well as for
/// reference casts.
///
/// \note This is described in detail in chapter 19 of <a href = "http://www.imperfectcplusplus.com/">Imperfect C++</a>.
template <ss_typename_param_k Target>
struct ptr_cast
{
public:
    typedef Target                                                          target_type;
    typedef ptr_cast<Target>                                                class_type;
    typedef ss_typename_type_k stlsoft::base_type_traits<Target>::cv_type   target_base_type;
    typedef target_base_type                                                &reference_type;
    typedef target_base_type                                                *pointer_type;

private:
    typedef ss_typename_type_k stlsoft::base_type_traits<Target>::base_type   target_base_type_;
    static target_base_type_ *manage_const(target_base_type_ *p)
    {
        return p;
    }
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    static target_base_type_ *manage_const(target_base_type_ const *p)
    {
        return const_cast<target_base_type_ *>(p);
    }
#else /* ? compiler */
    static target_base_type_ const *manage_const(target_base_type_ const *p)
    {
        return p;
    }
#endif /* compiler */

public:
    template <ss_typename_param_k Source>
    ptr_cast(Source &s)
        : m_p(manage_const(&dynamic_cast<Target>(s)))
    {
        // Nothing to do: dynamic_cast throws for reference types
    }

    template <ss_typename_param_k Source>
#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    defined(STLSOFT_COMPILER_IS_MWERKS)
    ptr_cast(Source *&s)
#else /* ? compiler */
    ptr_cast(Source *s)
#endif /* compiler */
        : m_p(manage_const(dynamic_cast<Target>(s)))
    {
        if(NULL == m_p)
        {
            throw std::bad_cast();
        }
    }

    ptr_cast(pointer_type pt)
        : m_p(pt)
    {}
    ptr_cast(reference_type t)
        : m_p(&t)
    {}

public:
    operator reference_type () const
    {
        return const_cast<reference_type>(*m_p);
    }
    operator pointer_type () const
    {
        return const_cast<pointer_type>(m_p);
    }

protected:
    pointer_type  m_p;

// Not to be implemented
private:
    ptr_cast(class_type const &);
};

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_PTR_CAST */

/* ////////////////////////////////////////////////////////////////////////// */