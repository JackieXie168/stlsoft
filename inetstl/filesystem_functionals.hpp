/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/filesystem_functionals.hpp (formerly inetstl_functionals.h)
 *
 * Purpose:     File-system functionals.
 *
 * Created:     19th January 2002
 * Updated:     10th June 2006
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
 * ////////////////////////////////////////////////////////////////////// */


/// \file inetstl/filesystem_functionals.hpp
///
/// File-system functionals.

#ifndef INETSTL_INCL_INETSTL_HPP_FILESYSTEM_FUNCTIONALS
#define INETSTL_INCL_INETSTL_HPP_FILESYSTEM_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_HPP_FILESYSTEM_FUNCTIONALS_MAJOR       3
# define INETSTL_VER_INETSTL_HPP_FILESYSTEM_FUNCTIONALS_MINOR       2
# define INETSTL_VER_INETSTL_HPP_FILESYSTEM_FUNCTIONALS_REVISION    1
# define INETSTL_VER_INETSTL_HPP_FILESYSTEM_FUNCTIONALS_EDIT        22
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef INETSTL_INCL_INETSTL_HPP_FILESYSTEM_TRAITS
# include <inetstl/filesystem_traits.hpp>
#endif /* !INETSTL_INCL_INETSTL_HPP_FILESYSTEM_TRAITS */
#ifndef _INETSTL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _INETSTL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _INETSTL_FUNCTIONALS_NO_STD */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _INETSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */

namespace stlsoft
{

namespace inetstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Function object that compares two file-system paths
///
/// \param C The character type
/// \param A1 The left-hand argument type; defaults to C const*
/// \param A2 The right-hand argument type; defaults to C const*
// [[synesis:class:function-class:binary-predicate: path_compare<T<C>, T<A1>, T<A2>>]]
template<   ss_typename_param_k C
        ,   ss_typename_param_k A1 = C const *
        ,   ss_typename_param_k A2 = C const *
        >
struct path_compare
    : public inetstl_ns_qual_std(binary_function)<A1, A2, is_bool_t>
{
public:
    /// The character type
    typedef C                                                           char_type;
private:
    typedef inetstl_ns_qual_std(binary_function)<A1, A2, is_bool_t>     parent_class_type;
public:
    /// The first argument type
    typedef ss_typename_type_k parent_class_type::first_argument_type   first_argument_type;
    /// The second argument type
    typedef ss_typename_type_k parent_class_type::second_argument_type  second_argument_type;
    /// The result type
    typedef ss_typename_type_k parent_class_type::result_type           result_type;
    /// The traits type
    typedef filesystem_traits<C>                                        traits_type;
    /// The current parameterisation of the type
    typedef path_compare<C, A1, A2>                                     class_type;

public:
    /// Function call, compares \c s1 with \c s2
    ///
    /// \note The comparison is determined by evaluation the full-paths of both \c s1 and \c s2
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template<ss_typename_param_k T1, ss_typename_param_k T2>
    result_type operator ()(T1 const &s1, T2 const &s2) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    result_type operator ()(first_argument_type s1, second_argument_type s2) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return compare_(stlsoft_ns_qual(c_str_ptr)(s1), stlsoft_ns_qual(c_str_ptr)(s2));
    }

// Implementation
private:
    static result_type compare_(char_type const *s1, char_type const *s2)
    {
        char_type   path1[_MAX_PATH + 1];
        char_type   path2[_MAX_PATH + 1];

        traits_type::str_n_copy(&path1[0], s1, STLSOFT_NUM_ELEMENTS(path1));
        traits_type::str_n_copy(&path2[0], s2, STLSOFT_NUM_ELEMENTS(path2));

        traits_type::remove_dir_end(&path1[0]);
        traits_type::remove_dir_end(&path2[0]);

        s1 = &path1[0];
        s2 = &path2[0];

        return 0 == traits_type::str_compare(s1, s2);
    }
};

/// Predicate that indicates whether a given path exists
///
/// \param C The character type
/// \param A The argument type; defaults to C const*
template<   ss_typename_param_k C
        ,   ss_typename_param_k A = C const*
        >
// [[synesis:class:function-class:unary-predicate: path_exists<T<C>, T<A>>]]
struct path_exists
    : public inetstl_ns_qual_std(unary_function)<A, is_bool_t>
{
public:
    /// The character type
    typedef C                       char_type;
    /// The traits type
    typedef filesystem_traits<C>    traits_type;
    /// The current parameterisation of the type
    typedef path_exists<C>          class_type;

public:
    ss_explicit_k path_exists(HINTERNET hConnection)
        : m_hConnection(hConnection)
    {}

public:
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    is_bool_t operator ()(S const &s) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    is_bool_t operator ()(argument_type s) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return exists_(stlsoft_ns_qual(c_str_ptr)(s));
    }

private:
    is_bool_t exists_(char_type const *s) const
    {
        char_type   sz0[1 + _MAX_PATH];
        is_dword_t  dw;

        if(!traits_type::get_full_path_name(m_hConnection, s, STLSOFT_NUM_ELEMENTS(sz0), sz0))
        {
            dw = 0xFFFFFFFF;
        }
        else
        {
            dw = ::GetFileAttributes(sz0);
        }

        return 0xFFFFFFFF != dw;
    }

private:
    HINTERNET   m_hConnection;
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_inetstl_functionals(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "InetSTL", "functionals", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_inetstl_functionals(test_inetstl_functionals);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _INETSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace inetstl
# else
} // namespace inetstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_INETSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* INETSTL_INCL_INETSTL_HPP_FILESYSTEM_FUNCTIONALS */

/* ////////////////////////////////////////////////////////////////////// */
