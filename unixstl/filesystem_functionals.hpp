/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem_functionals.hpp (formerly unixstl_functionals.h)
 *
 * Purpose:     A number of useful functionals .
 *
 * Created:     2nd November 2003
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


/// \file unixstl/filesystem_functionals.hpp
///
/// A number of useful functionals .

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS
#define UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS_MAJOR       3
# define UNIXSTL_VER_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS_MINOR       2
# define UNIXSTL_VER_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS_REVISION    1
# define UNIXSTL_VER_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS_EDIT        32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS
# include <unixstl/string_access.hpp>  // for string access shims
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER
# include <unixstl/file_path_buffer.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER */
#ifndef _UNIXSTL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _UNIXSTL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _UNIXSTL_FUNCTIONALS_NO_STD */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Function object that compares two file-system paths
template <ss_typename_param_k C>
// [[synesis:class:function-class:binary-predicate: path_compare<T<C>>]]
struct path_compare
    : public unixstl_ns_qual_std(binary_function)<const C *, const C *, us_bool_t>
{
public:
    /// The character type
    typedef C                                                                       char_type;
private:
    typedef unixstl_ns_qual_std(binary_function)<const C *, const C *, us_bool_t>   parent_class_type;
public:
    /// The first argument type
    typedef ss_typename_type_k parent_class_type::first_argument_type               first_argument_type;
    /// The second argument type
    typedef ss_typename_type_k parent_class_type::second_argument_type              second_argument_type;
    /// The result type
    typedef ss_typename_type_k parent_class_type::result_type                       result_type;
    /// The traits type
    typedef filesystem_traits<C>                                                    traits_type;
    /// The current parameterisation of the type
    typedef path_compare<C>                                                         class_type;

public:
    /// Function call, compares \c s1 with \c s2
    ///
    /// \note The comparison is determined by evaluation the full-paths of both \c s1 and \c s2
#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k T1, ss_typename_param_k T2>
    result_type operator ()(T1 const &s1, T2 const &s2)
#else /* ? __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    result_type operator ()(first_argument_type s1, second_argument_type s2)
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return compare_(stlsoft_ns_qual(c_str_ptr)(s1), stlsoft_ns_qual(c_str_ptr)(s2));
    }

// Implementation
private:
    result_type compare_(char_type const *s1, char_type const *s2)
    {
        basic_file_path_buffer<char_type>   path1;
        basic_file_path_buffer<char_type>   path2;

        if( !traits_type::get_full_path_name(s1, path1.size(), &path1[0]) ||
            !traits_type::get_full_path_name(s2, path2.size(), &path2[0]))
        {
            return false;
        }
        else
        {
            traits_type::remove_dir_end(&path1[0]);
            traits_type::remove_dir_end(&path2[0]);

            s1 = path1.c_str();
            s2 = path2.c_str();

            return 0 == traits_type::str_compare(s1, s2);
        }
    }
};

/// Predicate that indicates whether a given path exists
///
/// \note Does not expand environment variables in the argument passed to 
/// the function call operator
///
/// \param C The character type
/// \param A The argument type; defaults to C const*
template<   ss_typename_param_k C
        ,   ss_typename_param_k A = C const *
        >
// [[synesis:class:function-class:unary-predicate: path_exists<T<C>, T<A>>]]
struct path_exists
    : public unixstl_ns_qual_std(unary_function)<A, us_bool_t>
{
private:
    typedef unixstl_ns_qual_std(unary_function)<A, us_bool_t>   parent_class_type;
    typedef filesystem_traits<C>                                traits_type;
public:
    /// The character type
    typedef C                                                   char_type;
    /// The argument type
    typedef A                                                   argument_type;
    /// The current parameterisation of the type
    typedef path_exists<C, A>                                   class_type;

public:
#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    us_bool_t operator ()(S const &s) const
#else /* ? __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    us_bool_t operator ()(argument_type s) const
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return traits_type::file_exists(stlsoft_ns_qual(c_str_ptr)(s));
    }
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_functionals(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "functionals", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_functionals(test_unixstl_functionals);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////////// */