/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/c_str_ptr_inserter.hpp
 *
 * Purpose:     Contains the c_str_ptr_insert_iterator template class and c_str_ptr_inserter creator function.
 *
 * Created:     12th October 2004
 * Updated:     10th June 2006
 *
 * Thanks to:   Pablo Aguilar for spotting missing inclusions.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/c_str_ptr_inserter.hpp
///
/// Contains the c_str_ptr_insert_iterator template class and c_str_ptr_inserter creator function.

#ifndef STLSOFT_INCL_STLSOFT_HPP_C_STR_PTR_INSERTER
#define STLSOFT_INCL_STLSOFT_HPP_C_STR_PTR_INSERTER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_C_STR_PTR_INSERTER_MAJOR       1
# define STLSOFT_VER_STLSOFT_HPP_C_STR_PTR_INSERTER_MINOR       3
# define STLSOFT_VER_STLSOFT_HPP_C_STR_PTR_INSERTER_REVISION    1
# define STLSOFT_VER_STLSOFT_HPP_C_STR_PTR_INSERTER_EDIT        17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief This iterator adaptor translates the values assigned to it via the
/// c_str_ptr access shim, and passes the result to the function on which it's
/// parameterised.
///
/// It would be used as shown in the following example, which copies all files
/// found in the local directory to the vector of strings:
///
/// \htmlonly
/// <pre>
///
///   std::vector&lt;std::string&gt;  c1;
///   unixstl::readdir_sequence files(".");
///
///   std::copy(files.begin(), files.end(), c_str_ptr_inserter(std::back_inserter(c1)));
///
/// </pre>
/// \endhtmlonly

template <ss_typename_param_k F>
struct c_str_ptr_extract_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
public:
    typedef F                               function_type;
    typedef c_str_ptr_extract_iterator<F>   class_type;

public:
    ss_explicit_k c_str_ptr_extract_iterator(F &f)
        : m_f(f)
    {}

    template <ss_typename_param_k S>
    class_type &operator =(S const &s)
    {
        // Double application to ensure the function understands
        // the C-style string.
        m_f = stlsoft_ns_qual(c_str_ptr)(stlsoft_ns_qual(c_str_ptr)(s));

        return *this;
    }

    class_type &operator *()
    {
        return *this;
    }
    class_type &operator ++()
    {
        return *this;
    }
    class_type operator ++(int)
    {
        return class_type(m_f);
    }

private:
    F   m_f;
};

template <ss_typename_param_k F>
inline c_str_ptr_extract_iterator<F> c_str_ptr_inserter(F &f)
{
    return c_str_ptr_extract_iterator<F>(f);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_C_STR_PTR_INSERTER */

/* ////////////////////////////////////////////////////////////////////// */
