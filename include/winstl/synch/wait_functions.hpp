/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/wait_functions.hpp
 *
 * Purpose:     Synchronisation functions.
 *
 * Created:     30th May 2006
 * Updated:     4th December 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/functions.hpp
 *
 * \brief [C++ only] Definition of the winstl::wait_for_multiple_objects()
 *  functions.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_EDIT        5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE
# include <winstl/shims/attribute/get_synch_handle.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#if 0
/** \brief [IMPLEMENTATION]
 *
 * \ingroup group__library__synch
 */

struct your_type_is_implicitly_convertible_to_HANDLE
{};

template <ss_typename_param_k T>
inline your_type_is_implicitly_convertible_to_HANDLE WaitForMultipleObjects_verifier_helper_(T &, HANDLE h );

template <ss_typename_param_k T>
inline HANDLE WaitForMultipleObjects_verifier_helper_(T &t, ...)
{
	return winstl_ns_qual(get_synch_handle)(t);
}

template <ss_typename_param_k T>
inline HANDLE WaitForMultipleObjects_verifier_helper(T &t1, T const &t2)
{
	// If the compiler balks here with a message involving
	// "your_type_is_implicitly_convertible_to_HANDLE", it means that the
	// type of an argument passed to wait_for_multiple_objects() is
	// implicitly convertible to HANDLE. This is dangerous and disallowed,
	// and you must define a winstl::get_synch_handle() shim for it.

	return WaitForMultipleObjects_verifier_helper_(t1, t2);

//	return winstl_ns_qual(get_synch_handle)(t);
}

inline HANDLE WaitForMultipleObjects_verifier_helper(HANDLE h, HANDLE )
{
	return h;
}
#endif /* 0 */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief [IMPLEMENTATION]
 *
 * \ingroup group__library__synch
 */
inline DWORD WaitForMultipleObjects_helper_8(   HANDLE      h0
                                            ,   HANDLE      h1
                                            ,   HANDLE      h2
                                            ,   HANDLE      h3
                                            ,   HANDLE      h4
                                            ,   HANDLE      h5
                                            ,   HANDLE      h6
                                            ,   HANDLE      h7
                                            ,   ws_bool_t   bWaitAll
                                            ,   ws_dword_t  timeout)
{
    HANDLE  handles[8];
    DWORD   numHandles  =   2;

    WINSTL_ASSERT(NULL != h0);
    WINSTL_ASSERT(NULL != h1);

    handles[0]   =   h0;
    handles[1]   =   h1;
    handles[2]   =   h2;
    handles[3]   =   h3;
    handles[4]   =   h4;
    handles[5]   =   h5;
    handles[6]   =   h6;
    handles[7]   =   h7;

    for(size_t i = numHandles; i < STLSOFT_NUM_ELEMENTS(handles); ++i, ++numHandles)
    {
        if(NULL == handles[i])
        {
            break;
        }
    }

    return ::WaitForMultipleObjects(numHandles, &handles[0], bWaitAll, timeout);
}


/** \brief Execute wait for 8 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        ,   ss_typename_param_k L7
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, L6 &l6, L7 &l7, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l7));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   winstl_ns_qual(get_synch_handle)(l3)
        ,   winstl_ns_qual(get_synch_handle)(l4)
        ,   winstl_ns_qual(get_synch_handle)(l5)
        ,   winstl_ns_qual(get_synch_handle)(l6)
        ,   winstl_ns_qual(get_synch_handle)(l7)
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 7 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, L6 &l6, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   winstl_ns_qual(get_synch_handle)(l3)
        ,   winstl_ns_qual(get_synch_handle)(l4)
        ,   winstl_ns_qual(get_synch_handle)(l5)
        ,   winstl_ns_qual(get_synch_handle)(l6)
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 6 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));

#if 0
	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l0, l0));
	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l1, l1));
//	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l2, l2));
	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l3, l3));
	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l4, l4));
	WINSTL_ASSERT(NULL != WaitForMultipleObjects_verifier_helper(l5, l5));
#endif /* 0 */


    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   winstl_ns_qual(get_synch_handle)(l3)
        ,   winstl_ns_qual(get_synch_handle)(l4)
        ,   winstl_ns_qual(get_synch_handle)(l5)
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 5 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   winstl_ns_qual(get_synch_handle)(l3)
        ,   winstl_ns_qual(get_synch_handle)(l4)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 4 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   winstl_ns_qual(get_synch_handle)(l3)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 3 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, L2 &l2, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   winstl_ns_qual(get_synch_handle)(l2)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** \brief Execute wait for 2 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        >
inline DWORD wait_for_multiple_objects(L0 &l0, L1 &l1, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));

    return WaitForMultipleObjects_helper_8(
            winstl_ns_qual(get_synch_handle)(l0)
        ,   winstl_ns_qual(get_synch_handle)(l1)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/wait_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
