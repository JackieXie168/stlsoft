/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/handle_access.hpp
 *
 * Purpose:     Contains the get_handle access shim.
 *
 * Created:     23rd February 2005
 * Updated:     31st May 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/handle_access.hpp
///
/// Contains the get_handle access shim.

#ifndef STLSOFT_INCL_STLSOFT_HPP_HANDLE_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_HANDLE_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_HANDLE_ACCESS_MAJOR    1
# define STLSOFT_VER_STLSOFT_HPP_HANDLE_ACCESS_MINOR    3
# define STLSOFT_VER_STLSOFT_HPP_HANDLE_ACCESS_REVISION 2
# define STLSOFT_VER_STLSOFT_HPP_HANDLE_ACCESS_EDIT     13
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
#ifndef _STLSOFT_HANDLE_ACCESS_NO_AUTO_PTR
# include <memory>                  // for std::auto_ptr
#endif /* _STLSOFT_HANDLE_ACCESS_NO_AUTO_PTR */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup concepts STLSoft Concepts

/// \weakgroup concepts_shims Shims
/// \ingroup concepts

/// \weakgroup concepts_shims_handle_access Handle Access Shims
/// \ingroup concepts_shims
/// \brief These \ref concepts_shims "shims" retrieve the "handle" for arbitrary types

/// \defgroup stlsoft_handle_access_shims Handle Access Shims (STLSoft)
/// \ingroup STLSoft concepts_shims_handle_access
/// \brief These \ref concepts_shims "shims" retrieve the pointer for arbitrary pointer types
/// @{


/* /////////////////////////////////////////////////////////////////////////////
 * Traits types
 */

template <ss_typename_param_k T>
struct handle_traits
{
    typedef ss_typename_type_k T::handle_type   handle_type;
    typedef yes_type                            is_type_a_wrapper_type_type;
};

/* /////////////////////////////////////////////////////////////////////////////
 * Dummy types
 */

struct stlsoft_unknown_handle_type_;
typedef stlsoft_unknown_handle_type_ *stlsoft_unknown_handle_type;

stlsoft_unknown_handle_type get_handle(stlsoft_unknown_handle_type h);

/* /////////////////////////////////////////////////////////////////////////////
 * get_handle functions
 */

template<   ss_typename_param_k T
        ,   ss_typename_param_k R
        >
inline R get_handle_helper(T &t, yes_type)
{
    return t.get();
}
template<   ss_typename_param_k T
        ,   ss_typename_param_k R
        >
inline R get_handle_helper(T &t, no_type)
{
    return t;
}


template <ss_typename_param_k T>
/* inline */ ss_typename_type_k handle_traits<T>::handle_type get_handle(T &t)
{
    typedef ss_typename_type_k handle_traits<T>::handle_type                    handle_t;
    typedef ss_typename_type_k handle_traits<T>::is_type_a_wrapper_type_type    yesno_t;

    return get_handle_helper<T, handle_t>(t, yesno_t());
}

#if 0
template <ss_typename_param_k T>
inline ss_typename_type_k T::handle_type const get_handle(T const &h)
{
    return h.get();
}
#endif /* 0 */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_handle_access(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "handle_access", __FILE__);

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_handle_access(test_stlsoft_handle_access);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group stlsoft_handle_access_shims

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_HANDLE_ACCESS */

/* ////////////////////////////////////////////////////////////////////////// */
