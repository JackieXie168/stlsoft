/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft_meta.h (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     Meta programming primitives.
 *
 * Created:     19th November 1998
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft_meta.h
///
/// Meta programming primitives.

#ifndef STLSOFT_INCL_H_STLSOFT_META
#define STLSOFT_INCL_H_STLSOFT_META

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_META_MAJOR       3
# define STLSOFT_VER_H_STLSOFT_META_MINOR       12
# define STLSOFT_VER_H_STLSOFT_META_REVISION    1
# define STLSOFT_VER_H_STLSOFT_META_EDIT        106
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNCTION_POINTER_TYPE
# include <stlsoft/meta/is_function_pointer_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNCTION_POINTER_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES
# include <stlsoft/meta/n_types.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros
 */

/// \def STLSOFT_GEN_TRAIT_SPECIALISATION
/// \ingroup code_modification_macros
///
/// \brief Used to define a specialisation of a traits type
///
#define STLSOFT_GEN_TRAIT_SPECIALISATION(TR, T, V)  \
                                                    \
    STLSOFT_TEMPLATE_SPECIALISATION                 \
    struct TR<T>                                    \
    {                                               \
        enum { value = V };                         \
    };


/// \def STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE
/// \ingroup code_modification_macros
///
/// \brief Used to define a specialisation of a traits type that contains a member type
///
#define STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(TR, T, V, MT)    \
                                                                    \
    STLSOFT_TEMPLATE_SPECIALISATION                                 \
    struct TR<T>                                                    \
    {                                                               \
        enum { value = V };                                         \
                                                                    \
        typedef MT type;                                            \
    };

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs and basic support types
 */


#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

/// This template provides compile-time type selection between the two types
/// specified in its first two parameters, based on a (compile-time) boolean
/// value specified as its third parameter. If the third parameter evaluates
/// to non-zero, then the member type \c type is defined to be equivalent to
/// the first type, otherwise it is defined to be equivalent to the second.
template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        ,   bool                B //!< Selects T1
        >
struct select_first_type_if
{
    typedef T1          type;   //!< The
};

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct select_first_type_if<T1, T2, false>
{
    typedef T2          type;
};



// Obsolete
template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        ,   bool                B //!< Selects T1
        >
struct select_first_type
{
    typedef T1          type;   //!< The
};

template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct select_first_type<T1, T2, false>
{
    typedef T2          type;
};




# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#endif // __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

/// \brief Converts compile time constants to type
template <int N>
struct int_to_type
{};

/* /////////////////////////////////////////////////////////////////////////////
 * Tests
 */

// is_pointer_type
//
/// Constraint to ensure that a type is a pointer type

template <ss_typename_param_k U>
one_t is_pointer_type_func(U const volatile *);

two_t is_pointer_type_func(...);

/// traits type used to determine whether the given type is a pointer
template <ss_typename_param_k T>
struct is_pointer_type
{
    typedef T   test_type;

private:
    static T    t;
public:
    enum { value = sizeof(is_pointer_type_func(t)) == sizeof(one_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_pointer_type<void>
{
    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// is_array_type
//
/// Constraint to ensure that a type is a pointer type

template <ss_typename_param_k U>
one_t is_array_type_func(U const volatile *);

two_t is_array_type_func(...);

/// traits type used to determine whether the given type is an array
template <ss_typename_param_k T>
struct is_array_type
{
    typedef T   test_type;

private:
    static T    t;
public:
    enum { value = sizeof(is_array_type_func(t)) == sizeof(one_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_array_type<void>
{
    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// is_convertible_to_pointer
//
/// This test determines whether the given type is convertible to a pointer
/// type
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

#ifdef __STLSOFT_CF_NATIVE_BOOL_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct convertible_index<bool>
{
    typedef size_type<4>    type;
};
#endif /* __STLSOFT_CF_NATIVE_BOOL_SUPPORT */

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
# endif /* STLSOFT_COMPILER_IS_MSVC */
# ifdef __STLSOFT_CF_NATIVE_BOOL_SUPPORT
convertible_index<bool>::type           convertible_index_function(bool );
# endif /* __STLSOFT_CF_NATIVE_BOOL_SUPPORT */
convertible_index<void*>::type          convertible_index_function(void const volatile* );

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// This test determines whether the given type is convertible to a pointer
/// type
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


/// traits type used to determine whether the given type is a numeric type
template <ss_typename_param_k T>
struct is_numeric_type
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_sint8_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_uint8_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_sint16_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_uint16_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_sint32_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_uint32_t, 1)
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_sint64_t, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, ss_uint64_t, 1)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER == 1200
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, signed char, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, unsigned char, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, signed short, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, unsigned short, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, signed int, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, unsigned int, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, signed long, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, unsigned long, 1)
#elif defined(__STLSOFT_CF_INT_DISTINCT_TYPE)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, signed int, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, unsigned int, 1)
#endif /* _MSC_VER == 1200 */
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, float, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, double, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_numeric_type, long double, 1)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether a given type is integral
template <ss_typename_param_k T>
struct is_integral_type
{
    enum { value = 0 };

    typedef no_type     type;
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_sint8_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_uint8_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_sint16_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_uint16_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_sint32_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_uint32_t, 1, yes_type)
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_sint64_t, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_uint64_t, 1, yes_type)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER == 1200
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, signed char, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, unsigned char, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, signed short, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, unsigned short, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, signed int, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, unsigned int, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, signed long, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, unsigned long, 1, yes_type)
#elif defined(__STLSOFT_CF_INT_DISTINCT_TYPE)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, signed int, 1, yes_type)
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, unsigned int, 1, yes_type)
#endif /* _MSC_VER == 1200 */
#ifdef __STLSOFT_CF_NATIVE_BOOL_SUPPORT
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_bool_t, 1, yes_type)
#endif /* __STLSOFT_CF_NATIVE_BOOL_SUPPORT */
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_char_a_t, 1, yes_type)
#ifdef __STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT
STLSOFT_GEN_TRAIT_SPECIALISATION_WITH_TYPE(is_integral_type, ss_char_w_t, 1, yes_type)
#endif /* __STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether the given type is floating point
template <ss_typename_param_k T>
struct is_floating_point_type
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION(is_floating_point_type, float, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_floating_point_type, double, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_floating_point_type, long double, 1)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/// traits type used to determine whether the given type is of char type
template <ss_typename_param_k T>
struct is_char_type
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION(is_char_type, char, 1)
STLSOFT_GEN_TRAIT_SPECIALISATION(is_char_type, wchar_t, 1)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether the given type is \c bool
template <ss_typename_param_k T>
struct is_bool_type
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION(is_bool_type, ss_bool_t, 1)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether a given type is \c void
template <ss_typename_param_k T>
struct is_void_type
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_GEN_TRAIT_SPECIALISATION(is_void_type, void, 1)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether a given type is a fundamental type
template <ss_typename_param_k T>
struct is_fundamental_type
{
    enum
    {
        value   =   is_integral_type<T>::value
                |   is_floating_point_type<T>::value
                |   is_bool_type<T>::value
                |   is_void_type<T>::value
    };
};


/// traits type used to determine whether a given type is a compound type
template <ss_typename_param_k T>
struct is_compound_type
{
    enum { value = (0 == is_fundamental_type<T>::value) };
};



// is_class_type

/// Compatibility
///
/// Borland C/C++ 5.6 compiles but thinks everything is a class type
/// CodePlay compiles but thinks that nothing is a class type
/// Comeau works with most things (not references)
/// CodeWarrior 3.0+ compiles and works from version 8 onwards
/// Digital Mars 8.40+ compiles and works with most things (not references)
/// GCC works with most things (not references)
/// Intel works with most things (not references)
/// Visual C++ compiles and works from version 7.1 onwards with most things (not references)

#if (   !defined(STLSOFT_COMPILER_IS_MWERKS) || \
        (__MWERKS__ & 0xFF00) >= 0x3000) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1100) && \
    !defined(STLSOFT_COMPILER_IS_WATCOM)

template <ss_typename_param_k C>
one_t is_class_type_func(int C::*);

template <ss_typename_param_k C>
two_t is_class_type_func(...);

/// traits type used to determine whether a given type is of class type
template <ss_typename_param_k T>
struct is_class_type
{
    typedef T   test_type;

    enum { value = sizeof(is_class_type_func<test_type>(0)) == sizeof(one_t) };
};

#endif /* !STLSOFT_COMPILER_IS_MWERKS || (__MWERKS__ & 0xFF00) >= 0x3000 */


// is_const

#if defined(STLSOFT_COMPILER_IS_MWERKS)
one_t is_const_type_func(void const *);

two_t is_const_type_func(void *);
#else /* ? STLSOFT_COMPILER_IS_MWERKS */
one_t is_const_type_func(void volatile const *);

two_t is_const_type_func(void volatile *);
#endif /* STLSOFT_COMPILER_IS_MWERKS */

two_t is_const_type_func(...);

/// traits type used to determine whether a given type is \c const
template <ss_typename_param_k T>
struct is_const
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(is_const_type_func(&t)) == sizeof(one_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_const<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


// is_volatile

one_t is_volatile_type_func(void const volatile *);

two_t is_volatile_type_func(void const *);

two_t is_volatile_type_func(...);

/// traits type used to determine whether a given type has volatile qualifier
template <ss_typename_param_k T>
struct is_volatile
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(is_volatile_type_func(&t)) == sizeof(one_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_volatile<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// traits type used to determine whether a given type is \c void
template <ss_typename_param_k T>
struct is_void
{
    enum { value = 0 };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct is_void<void>
{
    enum { value = 1 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/// \brief Provides the sizeof the type, and works with void (for which it
/// provides the value 0)
template <ss_typename_param_k T>
struct size_of
{
    enum { value = sizeof(T) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct size_of<void>
{
    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



#ifdef __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

/// \brief Determines whether the type is the same type
template <ss_typename_param_k T1, ss_typename_param_k T2>
struct is_same_type
{
    enum { value = 0 };
};

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
struct is_same_type<T, T>
{
    enum { value = 1 };
};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

#endif // __STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT


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

/// traits type used to determine whether a given type has a member \c value_type
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

/// traits type used to determine whether a given type has a member \c iterator
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

/// traits type used to determine whether a given type has a member \c const_iterator
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

# endif /* !STLSOFT_COMPILER_IS_DMC || STLSOFT_FORCE_HAS_REFERENCE */

// has_pointer

template <ss_typename_param_k T>
one_t has_pointer_function(...);

template <ss_typename_param_k T>
five_t has_pointer_function(ss_typename_type_k T::pointer const volatile *);

/// traits type used to determine whether a given type has a member \c pointer
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

/// traits type used to determine whether a given type has a member \c pointer_type
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

/// traits type used to determine whether a given type has a member \c reference
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

/// traits type used to determine whether a given type has a member \c reference_type
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

/// traits type used to determine whether a given type has a member \c const_reference
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

# endif /* STLSOFT_COMPILER_IS_MWERKS || STLSOFT_FORCE_HAS_REFERENCE */


// has_const_pointer

template <ss_typename_param_k T>
one_t has_const_pointer_function(...);

template <ss_typename_param_k T>
sixteen_t has_const_pointer_function(ss_typename_type_k T::const_pointer const volatile *);

/// traits type used to determine whether a given type has a member \c const_pointer
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

/// traits type used to determine whether a given type has a member \c iterator_category
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

/// traits type used to determine whether a given type has a member \c distance_type
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

/// traits type used to determine whether a given type has a member \c difference_type
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

/// traits type used to determine whether a given type has a member \c key_type
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

/// traits type used to determine whether a given type has a member \c mapped_type
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

/// traits type used to determine whether a given type has a member \c referent_type
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

#endif /* !STLSOFT_COMPILER_IS_BORLAND && (!STLSOFT_COMPILER_IS_MSVC || _MSC_VER >= 1310) && !STLSOFT_COMPILER_IS_WATCOM */


/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_H_STLSOFT_META */

/* ////////////////////////////////////////////////////////////////////////// */
