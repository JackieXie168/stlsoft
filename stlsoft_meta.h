/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_meta.h (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     Meta programming primitives.
 *
 * Created:     19th November 1998
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft_meta.h
///
/// Meta programming primitives.

#ifndef STLSOFT_INCL_H_STLSOFT_META
#define STLSOFT_INCL_H_STLSOFT_META

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_META_MAJOR       3
# define STLSOFT_VER_H_STLSOFT_META_MINOR       23
# define STLSOFT_VER_H_STLSOFT_META_REVISION    1
# define STLSOFT_VER_H_STLSOFT_META_EDIT        126
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */
#ifndef STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_
# include <stlsoft/meta/util/meta_.hpp>
#endif /* STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_ */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_ARRAY_TYPE
# include <stlsoft/meta/is_array_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_ARRAY_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_BOOL_TYPE
# include <stlsoft/meta/is_bool_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_BOOL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE
# include <stlsoft/meta/is_character_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_CLASS_TYPE
# include <stlsoft/meta/is_class_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CLASS_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_COMPOUND_TYPE
# include <stlsoft/meta/is_compound_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_COMPOUND_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_CONST_TYPE
# include <stlsoft/meta/is_const_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CONST_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE
# include <stlsoft/meta/is_floating_point_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNCTION_POINTER_TYPE
# include <stlsoft/meta/is_function_pointer_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNCTION_POINTER_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE
# include <stlsoft/meta/is_fundamental_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_NUMERIC_TYPE
# include <stlsoft/meta/is_numeric_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_NUMERIC_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_POINTER_TYPE
# include <stlsoft/meta/is_pointer_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_POINTER_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE
# include <stlsoft/meta/is_same_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
# include <stlsoft/meta/is_signed_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE
# include <stlsoft/meta/is_void_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_VOLATILE_TYPE
# include <stlsoft/meta/is_volatile_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_VOLATILE_TYPE */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES
# include <stlsoft/meta/n_types.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
# include <stlsoft/meta/select_first_type_if.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_SIZEOF
# include <stlsoft/meta/size_of.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SIZEOF */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Tests
 */

// is_convertible_to_pointer
//
/** \brief This test determines whether the given type is convertible to a pointer
 * type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct is_convertible_to_pointer
{
};

// is_convertible_to_bool
//

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
struct convertible_index
{
//  typedef <size_type>     type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<int>
{
    typedef size_type<2>    type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<unsigned>
{
    typedef size_type<3>    type;
};

#ifdef STLSOFT_CF_NATIVE_BOOL_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<bool>
{
    typedef size_type<4>    type;
};
#endif /* STLSOFT_CF_NATIVE_BOOL_SUPPORT */

STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<void*>
{
    typedef size_type<5>    type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<long double>
{
    typedef size_type<6>    type;
};


size_type<1>                            convertible_index_function(...);
//convertible_index<int>::type          convertible_index_function(int );
//convertible_index<unsigned>::type     convertible_index_function(unsigned );
# ifdef STLSOFT_COMPILER_IS_MSVC
convertible_index<int>::type            convertible_index_function(int );
convertible_index<int>::type            convertible_index_function(unsigned int );
convertible_index<int>::type            convertible_index_function(long );
convertible_index<int>::type            convertible_index_function(unsigned long );
convertible_index<long double>::type    convertible_index_function(double );
convertible_index<long double>::type    convertible_index_function(long double );
# endif /* compiler */
# ifdef STLSOFT_CF_NATIVE_BOOL_SUPPORT
convertible_index<bool>::type           convertible_index_function(bool );
# endif /* STLSOFT_CF_NATIVE_BOOL_SUPPORT */
convertible_index<void*>::type          convertible_index_function(void const volatile* );

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief This test determines whether the given type is convertible to a pointer
 * type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct is_convertible_to_bool
{
    enum { value = sizeof(convertible_index_function(*static_cast<T*>(0))) == sizeof(convertible_index<bool>::type) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_convertible_to_bool<void>
{
    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief Obsolete form of stlsoft::is_const_type
 *
 * \ingroup group__library__meta
 *
 * \deprecated Use stlsoft::is_const_type instead.
 */
template <ss_typename_param_k T>
struct is_const
{
    enum { value = is_const_type<T>::value };
};


/** \brief Obsolete form of stlsoft::is_volatile_type
 *
 * \ingroup group__library__meta
 *
 * \deprecated Use stlsoft::is_volatile_type instead.
 */
template <ss_typename_param_k T>
struct is_volatile
{
    enum { value = is_volatile_type<T>::value };
};



/** \brief Obsolete form of \link stlsoft::is_void_type is_void_type\endlink.
 *
 * \ingroup group__library__meta
 *
 * \deprecated Use \link stlsoft::is_void_type is_void_type\endlink instead.
 */
template <ss_typename_param_k T>
struct is_void
{
    enum { value = is_void_type<T>::value };
};




#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    (   !defined(STLSOFT_COMPILER_IS_DMC) || \
        __DMC__ >= 0x0845) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1310) && \
    !defined(STLSOFT_COMPILER_IS_VECTORC) && \
    !defined(STLSOFT_COMPILER_IS_WATCOM)

# define STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED

// has_value_type

template <ss_typename_param_k T>
one_t has_value_type_function(...);

template <ss_typename_param_k T>
two_t has_value_type_function(ss_typename_type_k T::value_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c value_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_value_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_value_type_function<T>(0)) == sizeof(two_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_value_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_iterator

template <ss_typename_param_k T>
one_t has_iterator_function(...);

template <ss_typename_param_k T>
three_t has_iterator_function(ss_typename_type_k T::iterator const volatile *);

/** \brief traits type used to determine whether a given type has a member \c iterator
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_iterator
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_iterator_function<T>(0)) == sizeof(three_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_iterator<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_const_iterator

# if !defined(STLSOFT_COMPILER_IS_DMC) || \
     __DMC__ >= 0x0845 || \
     defined(STLSOFT_FORCE_HAS_REFERENCE)

template <ss_typename_param_k T>
one_t has_const_iterator_function(...);

template <ss_typename_param_k T>
four_t has_const_iterator_function(ss_typename_type_k T::const_iterator const volatile *);

/** \brief traits type used to determine whether a given type has a member \c const_iterator
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_const_iterator
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_const_iterator_function<T>(0)) == sizeof(four_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_const_iterator<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

# endif /* compiler */

// has_pointer

template <ss_typename_param_k T>
one_t has_pointer_function(...);

template <ss_typename_param_k T>
five_t has_pointer_function(ss_typename_type_k T::pointer const volatile *);

/** \brief traits type used to determine whether a given type has a member \c pointer
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_pointer
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_pointer_function<T>(0)) == sizeof(five_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_pointer<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_pointer_type

template <ss_typename_param_k T>
one_t has_pointer_type_function(...);

template <ss_typename_param_k T>
six_t has_pointer_type_function(ss_typename_type_k T::pointer_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c pointer_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_pointer_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_pointer_type_function<T>(0)) == sizeof(six_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_pointer_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_reference

# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     defined(STLSOFT_FORCE_HAS_REFERENCE)

template <ss_typename_param_k T>
one_t has_reference_function(...);

template <ss_typename_param_k T>
seven_t has_reference_function(ss_typename_type_k T::reference const volatile *);

/** \brief traits type used to determine whether a given type has a member \c reference
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_reference
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_reference_function<T>(0)) == sizeof(seven_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_reference<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_reference_type

template <ss_typename_param_k T>
one_t has_reference_type_function(...);

template <ss_typename_param_k T>
eight_t has_reference_type_function(ss_typename_type_k T::reference_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c reference_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_reference_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_reference_type_function<T>(0)) == sizeof(eight_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_reference_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// has_const_reference

template <ss_typename_param_k T>
one_t has_const_reference_function(...);

template <ss_typename_param_k T>
nine_t has_const_reference_function(ss_typename_type_k T::const_reference const volatile *);

/** \brief traits type used to determine whether a given type has a member \c const_reference
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_const_reference
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_const_reference_function<T>(0)) == sizeof(nine_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_const_reference<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

# endif /* compiler */


// has_const_pointer

template <ss_typename_param_k T>
one_t has_const_pointer_function(...);

template <ss_typename_param_k T>
sixteen_t has_const_pointer_function(ss_typename_type_k T::const_pointer const volatile *);

/** \brief traits type used to determine whether a given type has a member \c const_pointer
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_const_pointer
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_const_pointer_function<T>(0)) == sizeof(sixteen_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_const_pointer<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_iterator_category

template <ss_typename_param_k T>
one_t has_iterator_category_function(...);

template <ss_typename_param_k T>
ten_t has_iterator_category_function(ss_typename_type_k T::iterator_category const volatile *);

/** \brief traits type used to determine whether a given type has a member \c iterator_category
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_iterator_category
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_iterator_category_function<T>(0)) == sizeof(ten_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_iterator_category<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_distance_type

template <ss_typename_param_k T>
one_t has_distance_type_function(...);

template <ss_typename_param_k T>
eleven_t has_distance_type_function(ss_typename_type_k T::distance_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c distance_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_distance_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_distance_type_function<T>(0)) == sizeof(eleven_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_distance_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_difference_type

template <ss_typename_param_k T>
one_t has_difference_type_function(...);

template <ss_typename_param_k T>
twelve_t has_difference_type_function(ss_typename_type_k T::difference_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c difference_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_difference_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_difference_type_function<T>(0)) == sizeof(twelve_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_difference_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_key_type

template <ss_typename_param_k T>
one_t has_key_type_function(...);

template <ss_typename_param_k T>
thirteen_t has_key_type_function(ss_typename_type_k T::key_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c key_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_key_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_key_type_function<T>(0)) == sizeof(thirteen_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_key_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_mapped_type

template <ss_typename_param_k T>
one_t has_mapped_type_function(...);

template <ss_typename_param_k T>
fourteen_t has_mapped_type_function(ss_typename_type_k T::mapped_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c mapped_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_mapped_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_mapped_type_function<T>(0)) == sizeof(fourteen_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_mapped_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// has_referent_type

template <ss_typename_param_k T>
one_t has_referent_type_function(...);

template <ss_typename_param_k T>
fifteen_t has_referent_type_function(ss_typename_type_k T::referent_type const volatile *);

/** \brief traits type used to determine whether a given type has a member \c referent_type
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
template <ss_typename_param_k T>
struct has_referent_type
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_referent_type_function<T>(0)) == sizeof(fifteen_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_referent_type<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


#else /* ? compiler */

# ifdef STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED
#  undef STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED
# endif /* STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */

#endif /* compiler */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_meta(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "meta", __FILE__);

            STLSOFT_SUPPRESS_UNUSED(bSuccess);

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_meta(test_stlsoft_meta);
    } // anonymous namespace

} /* namespace unittest */


#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_META */

/* ////////////////////////////////////////////////////////////////////// */
