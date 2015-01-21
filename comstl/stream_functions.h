/* ////////////////////////////////////////////////////////////////////////////
 * File:        comstl/stream_functions.h
 *
 * Purpose:     Stream functions.
 *
 * Created:     22nd October 2005
 * Updated:     21st March 2006
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


/// \file comstl/stream_functions.h
///
/// Stream functions.

#ifndef COMSTL_INCL_COMSTL_H_STREAM_FUNCTIONS
#define COMSTL_INCL_COMSTL_H_STREAM_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_H_STREAM_FUNCTIONS_MAJOR     1
# define COMSTL_VER_COMSTL_H_STREAM_FUNCTIONS_MINOR     1
# define COMSTL_VER_COMSTL_H_STREAM_FUNCTIONS_REVISION  1
# define COMSTL_VER_COMSTL_H_STREAM_FUNCTIONS_EDIT      3
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

/* ////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup comstl_stream_library Stream Library (COMSTL)
/// \ingroup COMSTL libraries
/// \ingroup functions
/// \brief This library provides facilities for manipulating COM streams
/// @{

/* ////////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** \brief Gets the size of a stream
 */
STLSOFT_INLINE HRESULT comstl__get_stream_size(LPSTREAM pstm, ULARGE_INTEGER *psize)
{
    STATSTG statstg;
    HRESULT hr  =   pstm->Stat(&statstg, STATFLAG_NONAME);

    if(SUCCEEDED(hr))
    {
        *psize = statstg.cbSize;
    }

    return hr;
}

/* ////////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus
/// \brief Gets the size of a stream
inline HRESULT get_stream_size(LPSTREAM pstm, ULARGE_INTEGER *psize)
{
    return comstl__get_stream_size(pstm, psize);
}

/// \brief Gets the size of a stream
inline HRESULT get_stream_size(LPSTREAM pstm, ULARGE_INTEGER &size)
{
    return comstl__get_stream_size(pstm, &size);
}

/// \brief Gets the size of a stream
inline HRESULT get_stream_size(LPSTREAM pstm, cs_uint64_t &size)
{
    ULARGE_INTEGER  uli;
    HRESULT         hr  =   comstl__get_stream_size(pstm, &uli);

    if(SUCCEEDED(hr))
    {
        size = uli.QuadPart;
    }

    return hr;
}
#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/stream_functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_stream_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_H_STREAM_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */