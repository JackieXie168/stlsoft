/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/memory/functions.h (formerly comstl/memory_functions.h, comstl_memory_functions.h; originally MOMemory.h/.c, ::SynesisCom)
 *
 * Purpose:     COM memory functions.
 *
 * Created:     2nd March 1996
 * Updated:     25th March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2006, Matthew Wilson and Synesis Software
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


/// \file comstl/memory/functions.h
///
/// COM memory functions.

#ifndef COMSTL_INCL_COMSTL_MEMORY_H_FUNCTIONS
#define COMSTL_INCL_COMSTL_MEMORY_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_MEMORY_H_FUNCTIONS_MAJOR     4
# define COMSTL_VER_COMSTL_MEMORY_H_FUNCTIONS_MINOR     0
# define COMSTL_VER_COMSTL_MEMORY_H_FUNCTIONS_REVISION  3
# define COMSTL_VER_COMSTL_MEMORY_H_FUNCTIONS_EDIT      37
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

/* /////////////////////////////////////////////////////////////////////////////
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

/// \defgroup comstl_memory_functions COM Memory Functions
/// \ingroup COMSTL
/// \ingroup functions
/// \brief These functions expand on the COM API's <code>CoTaskMem*()</code> suite of functions
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * C functions
 */

/* CoTaskMemGetSize, CoTaskMemDidAlloc & CoTaskMemHeapMinimise
 */

/// \brief Gives the size of a memory block
///
/// This function returns the size of a memory block relative to the COM task
/// alloctor, as per IMalloc::GetSize()
///
/// \param pv Pointer to the memory block
/// \return The size of the memory block (in bytes)
STLSOFT_INLINE cs_size_t comstl__CoTaskMemGetSize(void *pv)
{
    LPMALLOC    lpmalloc;
    cs_size_t   ulRet;
    HRESULT     hr  =   STLSOFT_NS_GLOBAL(CoGetMalloc)(MEMCTX_TASK, &lpmalloc);

    if(SUCCEEDED(hr))
    {
        ulRet = COMSTL_ITF_CALL(lpmalloc)->GetSize(COMSTL_ITF_THIS(lpmalloc) pv);
        COMSTL_ITF_CALL(lpmalloc)->Release(COMSTL_ITF_THIS0(lpmalloc));
    }
    else
    {
        ulRet = 0;
    }

    return ulRet;
}

/// \brief Determines allocation ownership of a memory block
///
/// This function returns a value indicating whether a memory block was allocated
/// by the COM task allocator, as per IMalloc::DidAlloc()
///
/// \param pv Pointer to the memory block
/// \return Result indicating ownership
/// \retval 1 The memory block was allocated by the task allocator
/// \retval 0 The memory block was <i>not</i> allocated by the task allocator
/// \retval -1 CoTaskMemDidAlloc() cannot determine whether the memory block was allocated by the task allocator
STLSOFT_INLINE cs_sint_t comstl__CoTaskMemDidAlloc(void *pv)
{
    LPMALLOC    lpmalloc;
    cs_sint_t   iRet;
    HRESULT     hr  =   STLSOFT_NS_GLOBAL(CoGetMalloc)(MEMCTX_TASK, &lpmalloc);

    if(SUCCEEDED(hr))
    {
        iRet = COMSTL_ITF_CALL(lpmalloc)->DidAlloc(COMSTL_ITF_THIS(lpmalloc) pv);
        COMSTL_ITF_CALL(lpmalloc)->Release(COMSTL_ITF_THIS0(lpmalloc));
    }
    else
    {
        iRet = -1;
    }

    return iRet;
}

/// \brief Minimises the heap
///
/// This function minimises the heap as much as possible by releasing unused
/// memory to the operating system, coalescing adjacent free blocks and
/// committing free pages, as as per IMalloc::HeapMinimize().
STLSOFT_INLINE void comstl__CoTaskMemHeapMinimise(void)
{
    LPMALLOC    lpmalloc;

    if(SUCCEEDED(STLSOFT_NS_GLOBAL(CoGetMalloc)(MEMCTX_TASK, &lpmalloc)))
    {
        COMSTL_ITF_CALL(lpmalloc)->HeapMinimize(COMSTL_ITF_THIS0(lpmalloc));
        COMSTL_ITF_CALL(lpmalloc)->Release(COMSTL_ITF_THIS0(lpmalloc));
    }
}


/* /////////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/// \brief Gives the size of a memory block
///
/// This function returns the size of a memory block relative to the COM task
/// alloctor, as per IMalloc::GetSize()
///
/// \param pv Pointer to the memory block
/// \return The size of the memory block (in bytes)
inline cs_size_t CoTaskMemGetSize(void *pv)
{
    return comstl__CoTaskMemGetSize(pv);
}

/// \brief Determines allocation ownership of a memory block
///
/// This function returns a value indicating whether a memory block was allocated
/// by the COM task allocator, as per IMalloc::DidAlloc()
///
/// \param pv Pointer to the memory block
/// \return Result indicating ownership
/// \retval 1 The memory block was allocated by the task allocator
/// \retval 0 The memory block was <i>not</i> allocated by the task allocator
/// \retval -1 CoTaskMemDidAlloc() cannot determine whether the memory block was allocated by the task allocator
inline cs_sint_t CoTaskMemDidAlloc(void *pv)
{
    return comstl__CoTaskMemDidAlloc(pv);
}

/// \brief Minimises the heap
///
/// This function minimises the heap as much as possible by releasing unused
/// memory to the operating system, coalescing adjacent free blocks and
/// committing free pages, as as per IMalloc::HeapMinimize().
inline void CoTaskMemHeapMinimise()
{
    comstl__CoTaskMemHeapMinimise();
}

/// \brief Minimises the heap
///
/// This function minimises the heap as much as possible by releasing unused
/// memory to the operating system, coalescing adjacent free blocks and
/// committing free pages, as as per IMalloc::HeapMinimize().
inline void CoTaskMemHeapMinimize()
{
    comstl__CoTaskMemHeapMinimise();
}

#endif /* __cplusplus */

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/functions_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_memory_functions

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_MEMORY_H_FUNCTIONS */

/* ////////////////////////////////////////////////////////////////////////// */