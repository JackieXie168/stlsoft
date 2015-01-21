/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/refcount_functions.h (formerly comstl_refcount_functions.h)
 *
 * Purpose:     Reference-counting helper functions.
 *
 * Created:     25th June 2002
 * Updated:     18th June 2006
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


/// \file comstl/refcount_functions.h
///
/// Reference-counting helper functions.

#ifndef COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS
#define COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_H_REFCOUNT_FUNCTIONS_MAJOR       3
# define COMSTL_VER_COMSTL_H_REFCOUNT_FUNCTIONS_MINOR       1
# define COMSTL_VER_COMSTL_H_REFCOUNT_FUNCTIONS_REVISION    1
# define COMSTL_VER_COMSTL_H_REFCOUNT_FUNCTIONS_EDIT        49
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/// Adds a reference on the interface pointer
///
/// \param punk The interface pointer on which to add the reference. Cannot be null
STLSOFT_INLINE void comstl__addref(LPUNKNOWN punk)
{
    COMSTL_ITF_CALL(punk)->AddRef(COMSTL_ITF_THIS0(punk));
}

/// Releases a reference on the interface pointer
///
/// \param punk The interface pointer on which to release the reference. Cannot be null
STLSOFT_INLINE void comstl__release(LPUNKNOWN punk)
{
    COMSTL_ITF_CALL(punk)->Release(COMSTL_ITF_THIS0(punk));
}

/// Adds a reference on the interface pointer
///
/// \param punk The interface pointer on which to add the reference. Can be null
STLSOFT_INLINE void comstl__safe_addref(LPUNKNOWN punk)
{
    if(NULL != punk)
    {
        comstl__addref(punk);
    }
}

/// Releases a reference on the interface pointer
///
/// \param punk The interface pointer on which to release the reference. Can be null
STLSOFT_INLINE void comstl__safe_release(LPUNKNOWN punk)
{
    if(NULL != punk)
    {
        comstl__release(punk);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/// Adds a reference on the interface pointer
///
/// \param punk The interface pointer on which to add the reference. Cannot be null
inline void addref(LPUNKNOWN punk)
{
    comstl__addref(punk);
}

/// Releases a reference on the interface pointer
///
/// \param punk The interface pointer on which to release the reference. Cannot be null
inline void release(LPUNKNOWN punk)
{
    comstl__release(punk);
}

/// Adds a reference on the interface pointer
///
/// \param punk The interface pointer on which to add the reference. Can be null
inline void safe_addref(LPUNKNOWN punk)
{
    comstl__safe_addref(punk);
}

/// Releases a reference on the interface pointer
///
/// \param punk The interface pointer on which to release the reference. Can be null
inline void safe_release(LPUNKNOWN punk)
{
    comstl__safe_release(punk);
}

/// Releases a reference on the interface pointer, and resets the pointer
///
/// \param pt The interface pointer on which to release the reference. Can be null
template <ss_typename_param_k T>
inline void release_set_null(T *&pt)
{
    if(NULL != pt)
    {
        release(pt);
        pt = NULL;
    }
}

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/refcount_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_H_REFCOUNT_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////// */
