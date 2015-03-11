/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/union_cast.hpp (formerly stlsoft_union_cast.h; originally MLTypCnv.h, ::SynesisStd)
 *
 * Purpose:     A powerful cast operator that limits the danger of 
 *              reinterpret_cast, while avoiding the spurious warnings issued by
 *              some compilers.
 *
 * Created:     2nd May 1997
 * Updated:     21st January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1997-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/union_cast.hpp
///
/// A powerful cast operator that limits the danger of reinterpret_cast, while
/// avoiding the spurious warnings issued by some compilers.

#ifndef STLSOFT_INCL_STLSOFT_HPP_UNION_CAST
#define STLSOFT_INCL_STLSOFT_HPP_UNION_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_UNION_CAST_MAJOR       4
# define STLSOFT_VER_STLSOFT_HPP_UNION_CAST_MINOR       3
# define STLSOFT_VER_STLSOFT_HPP_UNION_CAST_REVISION    2
# define STLSOFT_VER_STLSOFT_HPP_UNION_CAST_EDIT        46
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
# include <stlsoft/constraints.hpp>   // for stlsoft_constraint_must_be_pod
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS
# include <stlsoft/meta/base_type_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS */

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

/// This class (union) effects conversion from one type to another, without
/// the use of casts.
///
/// \param TO The type to cast to
/// \param FROM The type to cast from
/// \param B_CHECK_ALIGN Determines the default checking behaviour. If 0, no checking on alignment is conducted
///
/// \note This technique is non-portable, and you use this class at your own 
/// risk. Notwithstanding that, the TO and FROM types have to be the same
/// size, so the technique is widely usable.
template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        ,   ss_bool_t           B_CHECK_ALIGN    =   true
        >
union union_cast
{
/// \name Member Types
/// @{
public:
    typedef TO                                  to_type;
    typedef FROM                                from_type;
    typedef union_cast<TO, FROM, B_CHECK_ALIGN> class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Conversion constructor
    ss_explicit_k union_cast(from_type const from, ss_bool_t bCheckAlign = B_CHECK_ALIGN)
        : m_from(from)
    {
        // The body of the constructor constrains the type conversion according
        // to the following:
        //
        // (i) Sizes must be the same
        // (ii) Both must be of POD type
        // (iii) There must be either a change of const/volatile,  or a change
        //  of type, but not both.
        // (iv) Both must be non-pointers, or must point to POD types

#if !defined(STLSOFT_COMPILER_IS_DMC) || \
    __DMC__ >= 0x0833
        // (i) Sizes must be the same
        STLSOFT_STATIC_ASSERT(sizeof(from_type) == sizeof(to_type));
        // (ii) Both must be of POD type
        stlsoft_constraint_must_be_pod(from_type);
        stlsoft_constraint_must_be_pod(to_type);
# if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
        // (iii) There must be either a change of const/volatile,
        /// or a change of type, but not both.
//        STLSOFT_STATIC_ASSERT(  (1 == is_same_type<from_type, to_type>::value) ||
//                                (   base_type_traits<from_type>::is_const == base_type_traits<to_type>::is_const &&
//                                    base_type_traits<from_type>::is_volatile == base_type_traits<to_type>::is_volatile));

        // (iv) Both must be non-pointers, or must point to POD types
        typedef ss_typename_type_k base_type_traits<from_type>::base_type   from_base_type;
        typedef ss_typename_type_k base_type_traits<to_type>::base_type     to_base_type;

        stlsoft_constraint_must_be_pod_or_void(from_base_type);
        stlsoft_constraint_must_be_pod_or_void(to_base_type);

        if( !base_type_traits<from_type>::is_pointer &&
            base_type_traits<to_type>::is_pointer &&
            0 != from)
        {
            ss_size_t       to_size     =   size_of<to_base_type>::value;
            union U
            {
                ss_size_t   size_;
                from_type   from_;
#  if !defined(STLSOFT_COMPILER_IS_MSVC) || \
      _MSC_VER < 1310
                inline U(from_type from)
                    : from_(from)
                {}
            } u_(from); // Can't be anonymous, otherwise GCC has an ICE!
#  else /* ? compiler */
            } u_;
            u_.from_ = from;
#  endif /* compiler */
            ss_size_t       from_value  =   u_.size_;

            STLSOFT_SUPPRESS_UNUSED(to_size);
            STLSOFT_SUPPRESS_UNUSED(from_value);

            // Need to add to_size, since Metrowerks warns of constant division by zero
            STLSOFT_MESSAGE_ASSERT( "Misalignment in conversion from non-pointer to pointer", !bCheckAlign || (0 == to_size) || (0 == ((from_value + to_size) % to_size)));
        }
# endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
#else /* ? compiler */
        // Sizes must be the same
        STLSOFT_ASSERT(sizeof(from_type) == sizeof(to_type));
#endif /* compiler */

        STLSOFT_SUPPRESS_UNUSED(bCheckAlign);
    }
/// @}

/// \name Conversion
/// @{
public:
    /// Implicit conversion operator
    operator to_type () const
    {
        return m_to;
    }
/// @}

/// \name Members
/// @{
private:
    from_type const  m_from;
    to_type          m_to;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        >
inline union_cast<TO, FROM, true> make_union_cast(FROM const from, ss_bool_t bCheckAlign = true)
{
    return union_cast<TO, FROM, true>(from, bCheckAlign);
}

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        ,   ss_bool_t           B_CHECK_ALIGN
        >
inline ss_bool_t operator < (union_cast<TO, FROM, B_CHECK_ALIGN> const &lhs, TO const &rhs)
{
    TO const    lhs_    =   lhs;

    return lhs_ < rhs;
}

template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        ,   ss_bool_t           B_CHECK_ALIGN
        >
inline ss_bool_t operator < (TO const &lhs, union_cast<TO, FROM, B_CHECK_ALIGN> const &rhs)
{
    TO const    rhs_    =   rhs;

    return lhs < rhs_;
}

template<   ss_typename_param_k TO
        ,   ss_typename_param_k FROM
        ,   ss_bool_t           B_CHECK_ALIGN
        >
inline ss_bool_t operator < (union_cast<TO, FROM, B_CHECK_ALIGN> const &lhs, union_cast<TO, FROM, B_CHECK_ALIGN> const &rhs)
{
    TO const    lhs_    =   lhs;
    TO const    rhs_    =   rhs;

    return lhs_ < rhs_;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/union_cast_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_UNION_CAST */

/* ////////////////////////////////////////////////////////////////////////// */
