/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string_tokeniser.hpp (formerly stlsoft_string_tokeniser.h, originally MTToken.h, ::SynesisStl)
 *
 * Purpose:     String token parsing class.
 *
 * Created:     6th January 2001
 * Updated:     31st January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2001-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/string_tokeniser.hpp
///
/// String token parsing class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_TOKENISER
#define STLSOFT_INCL_STLSOFT_HPP_STRING_TOKENISER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_STRING_TOKENISER_MAJOR     4
# define STLSOFT_VER_STLSOFT_HPP_STRING_TOKENISER_MINOR     7
# define STLSOFT_VER_STLSOFT_HPP_STRING_TOKENISER_REVISION  1
# define STLSOFT_VER_STLSOFT_HPP_STRING_TOKENISER_EDIT      191
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_DMC:  __DMC__<0x0839
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1100
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#if defined(STLSOFT_COMPILER_IS_DMC) && \
    __DMC__ < 0x0839
# error stlsoft/string_tokeniser.hpp is not compatible with Digital Mars C/C++ 3.38 or earlier
#endif /* _MSC_VER < 1200 */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1100
# error stlsoft/string_tokeniser.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* _MSC_VER < 1200 */

#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>        // for iterator_base
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>   // for c_str_data(), c_str_len()
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#include <iterator>                     // for std::distance()

#ifdef STLSOFT_UNITTEST
# ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
#  include <stlsoft/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */
# ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_VIEW
#  include <stlsoft/string_view.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_VIEW */
# include <string>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1300) || \
    (   defined(STLSOFT_COMPILER_IS_INTEL) && \
        defined(WIN32) && \
        _MSC_VER < 1300)
# define STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_string String Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating strings

/// \weakgroup libraries_string_tokenising String Tokenising Library
/// \ingroup STLSoft libraries_string
/// \brief This library provides facilities for tokenising and parsing strings
/// @{

/* ////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// string_tokeniser_ignore_blanks

/// \brief A tokenising policy for specifying whether blanks will be included or ignored (now deprecated; replaced by skip_blank_tokens)
///
/// This policy determines whether a tokenisation will ignore blanks, or will present them as
/// (empty) entries in the sequence to the caller.
///
/// \param B A boolean as to whether blanks should be ignored (\c true) or preserved (\c false)
///
/// \deprecated Use skip_blank_tokens instead
template <ss_bool_t B>
struct string_tokeniser_ignore_blanks
{
    enum { value = B };
};

/// \brief A tokenising policy for specifying whether blanks will be included or ignored
///
/// This policy determines whether a tokenisation will ignore blanks, or will present them as
/// (empty) entries in the sequence to the caller.
///
/// \param B A boolean as to whether blanks should be ignored (\c true) or preserved (\c false)
///
/// \note This supercedes string_tokeniser_ignore_blanks
template <ss_bool_t B>
struct skip_blank_tokens
{
    enum { value = B };
};


// string_tokeniser_type_traits
/// \brief A traits class for detecting features of the string type and the value type used to specialise string_tokeniser
///
/// This traits class has three responsibilities. First, it defines a number of
/// member types that are used by the string_tokeniser and 
/// string_tokeniser::iterator classes: value_type, size_type, difference_type,
/// const_iterator_type.
///
/// Second, it provides a means by which the iterators of the string_tokeniser
/// specialisation's string type can be elicited, by defining the (static)
/// methods begin() and end().
///
/// Third, it provides a means by which an instance of the string_tokeniser
/// specialisation's value type can be constructed from a pair of iterator of
/// the string type, by defining the (static) create() method.
///
/// \param S The string tokeniser string type
/// \param V The string tokeniser value type
template<   ss_typename_param_k S
        ,   ss_typename_param_k V
        >
struct string_tokeniser_type_traits
{
/// \name Member Types
/// @{
private:
    /// The string type
    typedef S                                       string_type;
    /// The tokeniser value type
    typedef V                                       tokeniser_value_type;

public:
    /// The value type
    typedef ss_typename_type_k S::value_type        value_type;
    /// The non-mutable (const) iterator type
    typedef ss_typename_type_k S::const_iterator    const_iterator_type;
    /// The size type
    typedef ss_typename_type_k S::size_type         size_type;
    /// The difference type
    typedef ss_typename_type_k S::difference_type   difference_type;
/// @}

/// \name Operations
/// @{
public:
    /// Returns the start of the contained sequence of the given string
    static const_iterator_type begin(S const &s)
    {
        return s.begin();
    }

    /// Returns the end of the contained sequence of the given string
    static const_iterator_type end(S const &s)
    {
        return s.end();
    }

    /// Creates an instance of the string from the given range [f:t)
    static tokeniser_value_type create(const_iterator_type f, const_iterator_type t)
    {
        /* There's a bug in the Metrowerks 3.0 standard library string
         * implementation, such that constructing from a range leaves
         * a corrupted sequence due to an optimistic allocation
         * requirement calculation result being stored as the length
         */
#if defined(STLSOFT_COMPILER_IS_MWERKS) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER >= 1300)
        return tokeniser_value_type(&*f, static_cast<size_type>(t - f));
#else /* ? compiler */
        return tokeniser_value_type(f, t);
#endif /* compiler */
    }
/// @}
};

// string_tokeniser_comparator
/// \brief A generic comparator, used to specialise string_tokeniser, that covers most string and delimiter types
///
/// This the default tokeniser comparator, providing functionality for both 
/// single-character and fixed string delimiters.
///
/// \param D The delimiter type
/// \param S The string type
/// \param T The traits type
template<   ss_typename_param_k D
        ,   ss_typename_param_k S
        ,   ss_typename_param_k T
        >
struct string_tokeniser_comparator
{
/// \name Member Types
/// @{
public:
    /// The delimiter type
    typedef D                                                   delimiter_type;
    /// The string type
    typedef S                                                   string_type;
    /// The traits type
    typedef T                                                   traits_type;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k traits_type::const_iterator_type const_iterator;
private:
    typedef string_tokeniser_comparator<D, S, T>                class_type;
/// @}

/// \name Implementation
/// @{
private:
#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Evaluates whether the contents of the two sequences are equivalent to the given extent
    template<   ss_typename_param_k I1
            ,   ss_typename_param_k I2
            >
    static ss_bool_t is_equal_(I1 p1, I2 p2, ss_size_t c)
    {
        for(; c-- > 0; ++p1, ++p2)
        {
            if(*p1 != *p2)
            {
                return false;
            }
        }

        return true;
    }

    /// Evaluates whether the delimiter and the sequence are equivalent to the extent of the delimiter
    template<   ss_typename_param_k D1
            ,   ss_typename_param_k I
            >
    static ss_bool_t is_equal_(D1 const &delim, I &p2)
    {
        return class_type::is_equal_(delim.begin(), p2, delim.length());
    }

    /// Returns the length of the delimiter
    template <ss_typename_param_k D1>
    static ss_size_t get_length_(D1 const &delim)
    {
        return delim.length();
    }
#else /* ? __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    /// Evaluates whether the contents of the two sequences are equivalent to the given extent
    static ss_bool_t is_equal_(string_type const &lhs, ss_typename_type_k string_type::value_type const *rhs)
    {
        return lhs.compare(rhs) == 0;
    }

    /// Returns the length of the delimiter
    static ss_size_t get_length_(string_type const &s)
    {
        return s.length();
    }
#endif // __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT

    /// Evaluates whether the delimiter and the sequence are equivalent to the extent of the delimiter
    static ss_bool_t is_equal_(ss_char_a_t const delim, const_iterator &it)
    {
        return delim == *it;
    }
    /// Evaluates whether the delimiter and the sequence are equivalent to the extent of the delimiter
    static ss_bool_t is_equal_(ss_char_w_t const delim, const_iterator &it)
    {
        return delim == *it;
    }
    /// Returns the length of the delimiter
    static ss_size_t get_length_(ss_char_a_t const /* delim */)
    {
        return 1;
    }
    /// Returns the length of the delimiter
    static ss_size_t get_length_(ss_char_w_t const /* delim */)
    {
        return 1;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Evaluates whether the delimiter and the sequence are not equivalent to the extent of the delimiter
    static ss_bool_t not_equal(delimiter_type const &delim, const_iterator &it)
    {
        return !is_equal_(delim, it);
    }

    /// Returns the length of the delimiter
    static ss_size_t length(delimiter_type const &delim)
    {
        return get_length_(delim);
    }
/// @}
};

/// \brief A class template that provides string tokenising behaviour
///
/// This class takes a string, and a delimiter, and fashions a sequence from
/// the given string, with each element determined with respect to the 
/// delimiter
///
/// \param S The string type
/// \param D The delimiter type (can be a string type or a character type)
/// \param B The ignore-blanks type. Defaults to skip_blank_tokens&lt;true&gt;
/// \param V The value type (the string type that will be used for the values). Defaults to \c S
/// \param T The string type traits type. Defaults to string_tokeniser_type_traits&lt;S, V&gt;
/// \param P The tokeniser comparator type. Defaults to string_tokeniser_comparator&lt;D, S, T&gt;
///
/// This class template provides tokenising services of a string (of type \c S)
/// with a delimiter (of type \c D). The four other template parameters, which are
/// defaulted, are used for tailoring the tokenising behaviour for special uses.
///
/// The two typical supported tokenising scenarios are:
///
///  - tokenising a string with a character (e.g. '\\n')
///  - tokenising a string with a string (e.g. "\\r\\n")
///
/// More exotic scenarios are supported by customising the comparator and type-traits
/// parameters. (See stlsoft::charset_tokeniser.)
///
/// <b>1. Tokenising a string with a character.</b>
///
/// This uses a specialisation whereby the first template parameter is a string type,
/// and the second parameter is a corresponding character type.
///
/// The following code shows a specialisation using std::string and char, and
/// will output: <b>abc,def,ghi,jkl,</b>
///
/// \htmlonly
/// <pre>
/// 
/// stlsoft::<b>string_tokeniser</b>&lt;std::string, char&gt;  tokens(":abc::def:ghi:jkl::::::::::", ':');
///
/// std::copy(tokens.begin(), tokens.end(), std::ostream_iterator&lt;std::string>(std::cout, ","));
/// </pre>
/// \endhtmlonly
///
/// The following code shows a specialisation using 
/// stlsoft::basic_simple_string&lt;wchar_t&gt; and wchar_t, and
/// will output: <b>abc-def-ghi-jkl-</b>
///
/// \htmlonly
/// <pre>
/// 
/// typedef stlsoft::basic_simple_string&lt;wchar_t>   string_t;
/// string_t                                        s(L"|abc||def|ghi|jkl||||||||||");
/// stlsoft::<b>string_tokeniser</b>&lt;string_t, wchar_t>    tokens(s, L'|');
///
/// std::copy(tokens.begin(), tokens.end(), std::ostream_iterator&lt;string_t, wchar_t>(std::wcout, L"-"));
/// </pre>
/// \endhtmlonly
///
/// Optionally, you can stipulate that the blanks be retained by specifying the third
/// template parameter as skip_blank_tokens<false>, as in the following, which will 
/// output: <b>,abc,,def,ghi,jkl,,,,,,,,,,</b>
///
/// \htmlonly
/// <pre>
/// 
/// stlsoft::<b>string_tokeniser</b>&lt;  std::string
///                         ,   char
///                         ,   stlsoft::skip_blank_tokens&lt;false>
///                         >                tokens(":abc::def:ghi:jkl::::::::::", ':');
///
/// std::copy(tokens.begin(), tokens.end(), std::ostream_iterator&lt;std::string>(std::cout, ","));
/// </pre>
/// \endhtmlonly
///
/// \note The tokeniser uses \ref concepts_shims_string_access "String Access Shims" to elicit the
/// string from the given type, so any type that for which shims are defined can be passed to the
/// constructor, as in the following, which will output: <b>abc;def;ghi;jkl;</b>
///
/// \htmlonly
/// <pre>
///
/// #include &lt;stlsoft/<b>string_tokeniser</b>.hpp&gt;
/// #include &lt;winstl/string_access.hpp&gt;
/// 
/// #include &lt;iostream&gt;
/// #include &lt;iterator&gt;
/// 
/// int main()
/// {
///   HWND  hwndButton = ::CreateWindowEx(0, "BUTTON", "+abc++def+ghi+jkl++++++++++", 0, 0, 0, 0, 0, NULL, (HMENU)0, NULL, NULL);
/// 
///   stlsoft::<b>string_tokeniser</b>&lt;  std::string
///                           ,   char
///                           ,   stlsoft::skip_blank_tokens&lt;true&gt;
///                           &gt;                tokens(hwndButton, ';');
///   std::copy(tokens.begin(), tokens.end(), std::ostream_iterator&lt;std::string&gt;(std::cout, ";"));
///   return 0;
/// }
/// </pre>
/// \endhtmlonly
///
/// <b>2. Tokenising a string with a string.</b>
///
/// This uses a specialisation whereby the first template parameter is a string type,
/// and the second parameter is a corresponding string type.
///
/// The following code shows a specialisation using std::string and std::string, and
/// will output: <b>abc,def,ghi,jkl,</b>
///
/// \htmlonly
/// <pre>
/// 
/// stlsoft::<b>string_tokeniser</b>&lt;std::string, std::string&gt;  tokens("\r\nabc\r\n\r\ndef\r\nghi\r\njkl\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n", "\r\n");
///
/// std::copy(tokens.begin(), tokens.end(), std::ostream_iterator&lt;std::string>(std::cout, ","));
/// </pre>
/// \endhtmlonly
template<   ss_typename_param_k S
        ,   ss_typename_param_k D
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k B = skip_blank_tokens<true>
        ,   ss_typename_param_k V = S
        ,   ss_typename_param_k T = string_tokeniser_type_traits<S, V>
        ,   ss_typename_param_k P = string_tokeniser_comparator<D, S, T>
#else /* ? __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k B
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        ,   ss_typename_param_k P
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class string_tokeniser
    : public stl_collection_tag
{
/// \name Member Types
/// @{
public:
    /// The current parameterisation of the type
    typedef string_tokeniser<S, D, B, V, T, P>              class_type;
    /// This tokeniser parameterisation
    typedef string_tokeniser<S, D, B, V, T, P>              tokeniser_type;
    /// The sequence string type
    typedef S                                               string_type;
    /// The delimiter type
    typedef D                                               delimiter_type;
    /// The blanks policy type
    typedef B                                               blanks_policy_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef blanks_policy_type                              ignore_blanks_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The value type
    typedef V                                               value_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The tokeniser comparator type
    typedef P                                               comparator_type;
    /// The character type
    typedef ss_typename_type_k traits_type::value_type      char_type;
    /// The size type
    typedef ss_typename_type_k traits_type::size_type       size_type;
    /// The difference type
    typedef ss_typename_type_k traits_type::difference_type difference_type;
    /// The non-mutating (const) reference type
    typedef const value_type                                const_reference;
    /// The non-mutating (const) iterator type
    class                                                   const_iterator;
/// @}

/// \name Construction
/// @{
public:
    /// Tokenise the given C-string with the given delimiter
    ///
    /// \param psz Pointer to C-string whose contents will be tokenised
    /// \param delim The delimiter to perform the tokenisation
    ///
    /// \note The tokeniser class takes a copy of \c psz. It does not alter the contents of \c psz
    string_tokeniser(char_type const *psz, delimiter_type const &delim)
        : m_str(psz)
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }

// Define the string_type overload if there member template ctors are not supported, or
// they are correctly discriminated
#if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Tokenise the given string with the given delimiter
    ///
    /// \param str The string whose contents will be tokenised
    /// \param delim The delimiter to perform the tokenisation
    ///
    /// \note The tokeniser class takes a copy of \c str. It does not alter the contents of \c str
    string_tokeniser(string_type const &str, delimiter_type const &delim)
        : m_str(str)
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }
#endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

// Define the template overload if member template ctors are supported
#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Tokenise the given string with the given delimiter
    ///
    /// \param str The string whose contents will be tokenised
    /// \param delim The delimiter to perform the tokenisation
    ///
    /// \note The tokeniser class takes a copy of \c str. It does not alter the contents of \c str
    template <ss_typename_param_k S1>
    string_tokeniser(S1 const &str, delimiter_type const &delim)
        : m_str(c_str_data(str), c_str_len(str))
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

    /// Tokenise the specified length of the given string with the given delimiter
    ///
    /// \param psz Pointer to C-string whose contents will be tokenised
    /// \param cch The number of characters in \c psz to use
    /// \param delim The delimiter to perform the tokenisation
    ///
    /// \note The tokeniser class takes a copy of \c psz. It does not alter the contents of \c psz
    string_tokeniser(char_type const *psz, size_type cch, delimiter_type const &delim)
        : m_str(psz, cch)
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }

#if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// \brief Tokenise the given range with the given delimiter
    ///
    /// \param from The start of the asymmetric range to tokenise
    /// \param to The start of the asymmetric range to tokenise
    /// \param delim The delimiter to use
    string_tokeniser(char_type const *from, char_type const *to, delimiter_type const &delim)
        : m_str(from, to)
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }
#endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Tokenise the given range with the given delimiter
    ///
    /// \param from The start of the asymmetric range to tokenise
    /// \param to The start of the asymmetric range to tokenise
    /// \param delim The delimiter to use
    template <ss_typename_param_k I>
    string_tokeniser(I from, I to, delimiter_type const &delim)
        : m_str(from, to)
        , m_delimiter(delim)
    {
        STLSOFT_MESSAGE_ASSERT("Delimiter of zero-length", 0 != comparator_type::length(m_delimiter));

        STLSOFT_ASSERT(is_valid());
    }
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
/// @}

/// \name Iteration
/// @{
public:
    /// Iterator for string_tokeniser, supporting the Forward Iterator concept
    class const_iterator
        : public iterator_base< stlsoft_ns_qual_std(forward_iterator_tag)
                            ,   value_type
                            ,   ss_ptrdiff_t
                            ,   void
                            ,   value_type
                            >
    {
    /// \name Member Types
    /// @{
    public:
        /// The type
        typedef const_iterator                                      class_type;
#if (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ <= 0x0843) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
        /// The delimiter type
        typedef delimiter_type                                      delimiter_type;
        /// The value type
        typedef value_type                                          value_type;
        /// The traits type
        typedef traits_type                                         traits_type;
#else /* ? compiler */
        /// The delimiter type
        typedef ss_typename_type_k tokeniser_type::delimiter_type   delimiter_type;
        /// The value type
        typedef ss_typename_type_k tokeniser_type::value_type       value_type;
        /// The traits type
        typedef ss_typename_type_k tokeniser_type::traits_type      traits_type;
#endif /* compiler */
        typedef value_type                                          effective_const_reference;
    private:
        typedef ss_typename_type_k traits_type::const_iterator_type underlying_iterator_type;
    /// @}

    /// \name Construction
    /// @{
    private:
        friend class    string_tokeniser<S, D, B, V, T, P>;

        /// Conversion constructor
        const_iterator(underlying_iterator_type first, underlying_iterator_type last, delimiter_type const &delimiter)
            : m_find0(first)
            , m_find1(first)
            , m_next(first)
            , m_end(last)
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
            , m_delimiter(&delimiter)
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
            , m_delimiter(delimiter)
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
            , m_cchDelimiter(comparator_type::length(delimiter))
        {
            if(m_end != m_find0)
            {
                increment_();
            }
        }
    public:
        /// Default constructor
        const_iterator()
            : m_find0(NULL)
            , m_find1(NULL)
            , m_next(NULL)
            , m_end(NULL)
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
            , m_delimiter(NULL)
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
            , m_delimiter(delimiter_type())
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
            , m_cchDelimiter(0)
        {}

        /// Copy constructor
        ///
        /// \param rhs The iterator whose current search position will be copied
        const_iterator(class_type const &rhs)
            : m_find0(rhs.m_find0)
            , m_find1(rhs.m_find1)
            , m_next(rhs.m_next)
            , m_end(rhs.m_end)
            , m_delimiter(rhs.m_delimiter)
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
            , m_cchDelimiter(comparator_type::length(*rhs.m_delimiter))
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
            , m_cchDelimiter(comparator_type::length(rhs.m_delimiter))
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
        {}

        /// Copy-assignment operator
        ///
        /// \param rhs The iterator whose current search position will be copied
        class_type const &operator =(class_type const &rhs)
        {
            m_find0         =   rhs.m_find0;
            m_find1         =   rhs.m_find1;
            m_next          =   rhs.m_next;
            m_end           =   rhs.m_end;
            m_delimiter     =   rhs.m_delimiter;
            m_cchDelimiter  =   rhs.m_cchDelimiter;

            return *this;
        }
    /// @}

    /// \name Forward Iterator Methods
    /// @{
    public:
        /// Dereference operator
        //
        // This has to be V, rather than value_type, because Visual C++ thinks that S is the value_type!!
        V operator *() const
        {
            return traits_type::create(m_find0, m_find1);
        }

        /// Pre-increment operator
        class_type &operator ++()
        {
            increment_();

            return *this;
        }

        /// Post-increment operator
        const class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        /// Evaluates whether \c this and \c rhs are equivalent
        ss_bool_t equal(class_type const &rhs) const
        {
            STLSOFT_MESSAGE_ASSERT("Comparing iterators from different tokenisers", m_end == rhs.m_end);

            return m_find0 == rhs.m_find0;
        }

        /// Evaluates whether \c this and \c rhs are equivalent
        ss_bool_t operator == (class_type const &rhs) const
        {
            return equal(rhs);
        }

        /// Evaluates whether \c this and \c rhs are not equivalent
        ss_bool_t operator != (class_type const &rhs) const
        {
            return !equal(rhs);
        }
    /// @}

    /// \name Implementation
    /// @{
    private:
        void increment_()
        {
            STLSOFT_MESSAGE_ASSERT("Attempting to increment an invalid iterator", m_find0 != m_end);

            // This is a two-phase algorithm:
            //
            // 1. If skipping blanks, then do that. Otherwise, locate the the start-of-item
            //     iterator (m_find0) to the previously identified start of the next item (m_next)
            // 2. Starting from m_find0, determine the end-of-item (m_find1)

// TODO: Make this into a overload-selector, to avoid the "conditional expression is constant" warning
            if(blanks_policy_type::value)
            {
                // 1. Skip blanks until at start of next item
                for(m_find0 = m_next; m_find0 != m_end; )
                {
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
                    if(comparator_type::not_equal(*m_delimiter, m_find0))
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
                    if(comparator_type::not_equal(m_delimiter, m_find0))
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
                    {
                        break;
                    }
                    else
                    {
                        m_find0 +=  static_cast<ss_ptrdiff_t>(m_cchDelimiter);
                    }
                }
            }
            else
            {
                m_find0 = m_next;
            }

            // 2. Determine the end-of-item (m_find1), starting from m_find0
            for(m_find1 = m_find0; ; )
            {
                if(m_find1 == m_end)
                {
                    // End of sequence. Item will be [m_find0, m_end (== m_find1))
                    m_next = m_find1;
                    break;
                }
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
                else if(comparator_type::not_equal(*m_delimiter, m_find1))
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
                else if(comparator_type::not_equal(m_delimiter, m_find1))
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
                {
                    // current item does not hold a delimiter, so advance one position
                    ++m_find1;
                }
                else
                {
                    // Determine the start of the next potential element, ready
                    // for the next call of increment_()
                    m_next = m_find1 + static_cast<ss_ptrdiff_t>(m_cchDelimiter);

                    break;
                }
            }
        }
    /// @}

    /// \name Members
    /// @{
    private:
        underlying_iterator_type    m_find0;        // the start of the current item
        underlying_iterator_type    m_find1;        // the end of the current item
        underlying_iterator_type    m_next;         // the start of the next valid (non-null) item
        underlying_iterator_type    m_end;          // end point of controlled sequence
# if defined(STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION)
        delimiter_type const        *m_delimiter;
# else /* ? STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
        delimiter_type              m_delimiter;
# endif /* STLSOFT_STRING_TOKENISER_CF_REQUIRE_DELIMITER_INDIRECTION */
        ss_size_t                   m_cchDelimiter;
    /// @}
    };

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator begin() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_iterator(traits_type::begin(m_str), traits_type::end(m_str), m_delimiter);
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator end() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_iterator(traits_type::end(m_str), traits_type::end(m_str), m_delimiter);
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the search sequence is empty
    ss_bool_t   empty() const
    {
        STLSOFT_ASSERT(is_valid());

        return begin() == end();
    }
/// @}

/// \name Invariant
/// @{
private:
    ss_bool_t is_valid() const
    {
        return true;
    }
/// @}

/// \name Members
/// @{
private:
    string_type const       m_str;
    delimiter_type const    m_delimiter;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type const &operator =(class_type const &);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Operators
 */

#if 0
/// Evaluates whether \c this and \c rhs are equivalent
template<   ss_typename_param_k S
        ,   ss_typename_param_k D
        ,   ss_typename_param_k B
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        ,   ss_typename_param_k P
        >
inline ss_bool_t operator ==(   ss_typename_type_k string_tokeniser<S, D, B, V, T, P>::const_iterator const &lhs
                            ,   ss_typename_type_k string_tokeniser<S, D, B, V, T, P>::const_iterator const &rhs)
{
    return lhs.equal(rhs);
}

/// Evaluates whether \c this and \c rhs are not equivalent
template<   ss_typename_param_k S
        ,   ss_typename_param_k D
        ,   ss_typename_param_k B
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        ,   ss_typename_param_k P
        >
inline ss_bool_t operator !=(   ss_typename_type_k string_tokeniser<S, D, B, V, T, P>::const_iterator const &lhs
                            ,   ss_typename_type_k string_tokeniser<S, D, B, V, T, P>::const_iterator const &rhs)
{
    return !lhs.equal(rhs);
}
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_tokeniser_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_COMPILER_IS_DMC) && \
    !defined(_STLPORT_VERSION)
template<   ss_typename_param_k S
        ,   ss_typename_param_k D
        ,   ss_typename_param_k B
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        ,   ss_typename_param_k P
        >
inline forward_iterator_tag iterator_category(string_tokeniser<S, D, B, V, T, P>::const_iterator const &)
{
    return forward_iterator_tag();
}

template<   ss_typename_param_k S
        ,   ss_typename_param_k D
        ,   ss_typename_param_k B
        ,   ss_typename_param_k V
        ,   ss_typename_param_k T
        ,   ss_typename_param_k P
        >
inline ptrdiff_t* distance_type(string_tokeniser<S, D, B, V, T, P>::const_iterator const &)
{
    return static_cast<ptrdiff_t*>(0);
}
#endif /* STLSOFT_COMPILER_IS_DMC */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group libraries_string_tokenising

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_TOKENISER */

/* ////////////////////////////////////////////////////////////////////////// */
