/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/functions.hpp
 *
 * Purpose:     Synchronisation functions.
 *
 * Created:     30th May 2006
 * Updated:     10th June 2006
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
 * \brief [C++ only] Definition of the winstl::WaitForMultipleObjects()
 *  functions.
 *  (\ref group__library__synch "Synchronisation" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_FUNCTIONS_MAJOR    1
# define WINSTL_VER_WINSTL_SYNCH_HPP_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_SYNCH_HPP_FUNCTIONS_REVISION 2
# define WINSTL_VER_WINSTL_SYNCH_HPP_FUNCTIONS_EDIT     4
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
#ifndef WINSTL_INCL_WINSTL_HPP_HANDLE_ACCESS
# include <winstl/handle_access.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_HANDLE_ACCESS */

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

/** \brief [IMPLEMENTATION]
 *
 * \ingroup group__library__synch
 */
inline DWORD WaitForMultipleObjects_helper_8(   HANDLE		h0
                                            ,   HANDLE		h1
                                            ,   HANDLE		h2
                                            ,   HANDLE		h3
                                            ,   HANDLE		h4
                                            ,   HANDLE		h5
                                            ,   HANDLE		h6
                                            ,   HANDLE		h7
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, L6 &l6, L7 &l7, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l3));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l4));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l5));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l6));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l7));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
        ,   stlsoft_ns_qual(get_handle)(l3)
        ,   stlsoft_ns_qual(get_handle)(l4)
        ,   stlsoft_ns_qual(get_handle)(l5)
        ,   stlsoft_ns_qual(get_handle)(l6)
        ,   stlsoft_ns_qual(get_handle)(l7)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, L6 &l6, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l3));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l4));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l5));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l6));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
        ,   stlsoft_ns_qual(get_handle)(l3)
        ,   stlsoft_ns_qual(get_handle)(l4)
        ,   stlsoft_ns_qual(get_handle)(l5)
        ,   stlsoft_ns_qual(get_handle)(l6)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, L5 &l5, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l3));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l4));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l5));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
        ,   stlsoft_ns_qual(get_handle)(l3)
        ,   stlsoft_ns_qual(get_handle)(l4)
        ,   stlsoft_ns_qual(get_handle)(l5)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, L4 &l4, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l3));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l4));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
        ,   stlsoft_ns_qual(get_handle)(l3)
        ,   stlsoft_ns_qual(get_handle)(l4)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, L3 &l3, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l3));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
        ,   stlsoft_ns_qual(get_handle)(l3)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, L2 &l2, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l2));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
        ,   stlsoft_ns_qual(get_handle)(l2)
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
inline DWORD WaitForMultipleObjects(L0 &l0, L1 &l1, ws_bool_t bWaitAll, ws_dword_t timeout)
{
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l0));
    WINSTL_ASSERT(NULL != stlsoft_ns_qual(get_handle)(l1));

    return WaitForMultipleObjects_helper_8(
            stlsoft_ns_qual(get_handle)(l0)
        ,   stlsoft_ns_qual(get_handle)(l1)
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
# include "./unittest/functions_unittest_.h"
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
