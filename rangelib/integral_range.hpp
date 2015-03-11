/* /////////////////////////////////////////////////////////////////////////////
 * File:        rangelib/integral_range.hpp
 *
 * Purpose:     Integral range class.
 *
 * Created:     4th November 2003
 * Updated:     22nd December 2005
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


/** \file rangelib/integral_range.hpp Integral range class */

#ifndef STLSOFT_INCL_RANGELIB_HPP_INTEGRAL_RANGE
#define STLSOFT_INCL_RANGELIB_HPP_INTEGRAL_RANGE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_RANGELIB_HPP_INTEGRAL_RANGE_MAJOR    2
# define STLSOFT_VER_RANGELIB_HPP_INTEGRAL_RANGE_MINOR    2
# define STLSOFT_VER_RANGELIB_HPP_INTEGRAL_RANGE_REVISION 4
# define STLSOFT_VER_RANGELIB_HPP_INTEGRAL_RANGE_EDIT     32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC:     _MSC_VER < 1200
STLSOFT_COMPILER_IS_MWERKS:   (__MWERKS__ & 0xFF00) < 0x3000
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGELIB
# include <rangelib/rangelib.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGELIB */
#ifndef RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES
# include <rangelib/range_categories.hpp>
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES */
#ifndef STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL
# include <stlsoft/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS
# include <stlsoft/exceptions.hpp>        // for null_exception_policy
#endif /* !STLSOFT_INCL_STLSOFT_HPP_EXCEPTIONS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS
# include <stlsoft/constraints.hpp>       // for not_implicitly_comparable
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONSTRAINTS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_META
# include <stlsoft/meta.hpp>              // for is_integral_type, is_numeric_type
#endif /* !STLSOFT_INCL_STLSOFT_HPP_META */
#ifndef STLSOFT_INCL_STLSOFT_HPP_PRINTF_TRAITS
# include <stlsoft/printf_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_PRINTF_TRAITS */
#include <stdexcept>                    // for std::out_of_range
#include <stdio.h>                      // for sprintf

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::rangelib */
namespace rangelib
{
# else
/* Define stlsoft::rangelib_project */

namespace stlsoft
{

namespace rangelib_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \defgroup rangelib_ranges Range Classes
/// \ingroup rangelib
/// \brief Range Classes
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Error policy class for integral_range
struct invalid_integral_range_policy
{
public:
    /// The thrown type
    typedef std::out_of_range   thrown_type;

public:
    /// Function call operator, taking three 32-bit signed integer parameters
    void operator ()(ss_sint32_t first, ss_sint32_t last, ss_sint32_t increment) const
    {
        char    message[101];

        sprintf(message, "Invalid integral range [%ld, %ld), %ld", first, last, increment);

        throw thrown_type(message);
    }
    /// Function call operator, taking three 32-bit unsigned integer parameters
    void operator ()(ss_uint32_t first, ss_uint32_t last, ss_uint32_t increment) const
    {
        char    message[101];

        sprintf(message, "Invalid integral range [%lu, %lu), %lu", first, last, increment);

        throw thrown_type(message);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
private:
    static char const *format_sint64()
    {
        return printf_traits<ss_sint64_t>::format_a();
    }
    static char const *format_uint64()
    {
        return printf_traits<ss_uint64_t>::format_a();
    }

public:
    /// Function call operator, taking three 64-bit signed integer parameters
    void operator ()(ss_sint64_t first, ss_sint64_t last, ss_sint64_t increment) const
    {
        char    format[81];
        char    message[101];

        sprintf(format, "Invalid integral range [%s, %s), %s", format_sint64(), format_sint64(), format_sint64());
        sprintf(message, format, first, last, increment);

        throw thrown_type(message);
    }
    /// Function call operator, taking three 64-bit unsigned integer parameters
    void operator ()(ss_uint64_t first, ss_uint64_t last, ss_uint64_t increment) const
    {
        char    format[81];
        char    message[101];

        sprintf(format, "Invalid integral range [%s, %s), %s", format_uint64(), format_uint64(), format_uint64());
        sprintf(message, format, first, last, increment);

        throw thrown_type(message);
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
};

/// This range class represents an integral range.
///
/// It is categoried as a Notional Range
///
/// It could be used as follows
/// \htmlonly
/// <code>
/// <pre>
///   // Create a range of integer values, in the range [-100, 200), in increments of 5
///   stlsoft::integral_range&lt;int&gt;   r(-100, +100, 5);
///
///   // Calculate the total
///   int total = stlsoft::r_accumulate(r, 0);
/// </pre>
/// </code>
/// \endhtmlonly
template<   ss_typename_param_k T
        ,   ss_typename_param_k XP = null_exception_policy
        >
class integral_range
    : public notional_range_tag
{
/// \name Types
/// @{
public:
    typedef T                       value_type;
    typedef T const                 &const_reference;
    typedef XP                      exception_policy_type;
    typedef notional_range_tag      range_tag_type;
    typedef integral_range<T, XP>   class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs from a start and end position, and an increment
    integral_range(value_type first, value_type last, value_type increment = +1)
        : m_position(first)
        , m_last(last)
        , m_increment(increment)
    {
        validate_range(first, last, increment);
    }
    /// Destructor
    ~integral_range() stlsoft_throw_0()
    {
        // These constraints are to ensure that this template is not used
        // for any other types, especially floating point types!!
        STLSOFT_STATIC_ASSERT(0 != is_integral_type<value_type>::value);
        STLSOFT_STATIC_ASSERT(0 != is_numeric_type<value_type>::value || 0 != is_char_type<value_type>::value);
    }
/// @}

/// \name Notional Range methods
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    /// Indicates whether the range is open
    ss_bool_t is_open() const
    {
        return m_position != m_last;
    }
    /// Returns the current value in the range
    const_reference current() const
    {
        STLSOFT_MESSAGE_ASSERT("Attempting to access the value of a closed range", is_open());

        return m_position;
    }
    /// Advances the current position in the range
    class_type &advance()
    {
        STLSOFT_MESSAGE_ASSERT("Attempting to advance a closed range", is_open());
        STLSOFT_MESSAGE_ASSERT("Attempting to increment the range past its end point", (m_increment > 0 && m_position < m_last) || (m_increment < 0 && m_position > m_last));

        m_position += m_increment;

        return *this;
    }

    /// Indicates whether the range is open
    operator operator_bool_type() const
    {
        return operator_bool_generator_type::translate(is_open());
    }
    /// Returns the current value in the range
    const_reference operator *() const
    {
        return current();
    }
    /// Advances the current position in the range
    class_type &operator ++()
    {
        return advance();
    }
    /// Advances the current position in the range, returning a copy of the
    /// range prior to its being advanced
    class_type operator ++(int)
    {
        class_type  ret(*this);

        operator ++();

        return ret;
    }
/// @}

/// \name Comparison
/// @{
public:
    /// Evaluates whether two ranges are equal
    bool operator ==(class_type const &rhs) const
    {
        STLSOFT_MESSAGE_ASSERT("Comparing unrelated ranges!", m_last == rhs.m_last);

        return m_position == rhs.m_position;
    }
    /// Evaluates whether two ranges are unequal
    bool operator !=(class_type const &rhs) const
    {
        return ! operator ==(rhs);
    }
/// @}

// Implementation
private:
    static void validate_range(value_type first, value_type last, value_type increment)
    {
        ss_bool_t   bValid = true;

        // Check modulus
        if(bValid)
        {
            if( first != last &&
                0 != increment)
            {
                bValid = (0 == ((last - first) % increment));
            }
        }

        // Check direction
        if(bValid)
        {
            if( (   last < first &&
                    increment > 0) ||
                (   first < last &&
                    increment < 0))
            {
                bValid = false;
            }
        }

//        STLSOFT_MESSAGE_ASSERT("The range you have specified will not close with the given increment", first == last || (increment > 0 && last > first) || (increment < 0 && last < first));
//        STLSOFT_MESSAGE_ASSERT("The range you have specified will not close with the given increment", 0 == ((last - first) % increment));

        if(!bValid)
        {
            exception_policy_type()(first, last, increment);
        }

        // Assert here, in case using a null exception policy
        STLSOFT_MESSAGE_ASSERT("invalid integral range", bValid);
    }

// Members
private:
    value_type  m_position;
    value_type  m_last;
    value_type  m_increment;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Creator functions
 */

template <typename T>
inline integral_range<T> make_integral_range(T first, T last, T increment = +1)
{
    return integral_range<T>(first, last, increment);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {

        ss_bool_t test_stlsoft_rangelib_integral_range(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "integral_range", __FILE__);

            typedef integral_range<int> intrange_t;

            intrange_t  r1(0, 10, 1);
            int         sum;

            for(sum = 0; r1; ++r1)
            {
                sum += *r1;
            }

            if(45 != sum)
            {
                r->report("manual enumeration failed", __LINE__);
                bSuccess = false;
            }

            if(r1.is_open())
            {
                r->report("closed range presents as open (is_open() method)", __LINE__);
                bSuccess = false;
            }

            if(r1)
            {
                r->report("closed range presents as open (operator \"bool\"())", __LINE__);
                bSuccess = false;
            }

            if(intrange_t(1000, 1000, 1000))
            {
                r->report("closed range presents as open", __LINE__);
                bSuccess = false;
            }

    # ifdef STLSOFT_CF_64BIT_INT_SUPPORT
            typedef integral_range<ss_sint64_t, invalid_integral_range_policy>  uint_range_x_t;
    # else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
            typedef integral_range<ss_sint32_t, invalid_integral_range_policy>  uint_range_x_t;
    # endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

            try
            {
                uint_range_x_t  r2(10, 0, 1);

                r->report("failed to detect invalid range (wrong direction)", __LINE__);
                bSuccess = false;
            }
            catch(std::out_of_range &/* x */)
            {}

            try
            {
                uint_range_x_t  r3(-100, 0, 3);

                r->report("failed to detect invalid range (modulus error)", __LINE__);
                bSuccess = false;
            }
            catch(std::out_of_range &/* x */)
            {}

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_rangelib_integral_range(test_stlsoft_rangelib_integral_range);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group rangelib_classes

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef RANGELIB_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace rangelib
# else
} // namespace rangelib_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !RANGELIB_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_RANGELIB_HPP_INTEGRAL_RANGE */

/* ////////////////////////////////////////////////////////////////////////// */
