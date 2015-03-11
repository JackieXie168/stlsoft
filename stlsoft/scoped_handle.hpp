/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/scoped_handle.hpp (evolved from MLResPtr.h, ::SynesisStd)
 *
 * Purpose:     scoped_handle - parameterisable RAII class for arbitrary
 *              resource types.
 *
 * Created:     1st November 1994
 * Updated:     18th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2005, Matthew Wilson and Synesis Software
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


/// \file stlsoft/scoped_handle.hpp
///
/// scoped_handle - parameterisable RAII class for arbitrary resource types.

#ifndef STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE
#define STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_SCOPED_HANDLE_MAJOR    4
# define STLSOFT_VER_STLSOFT_HPP_SCOPED_HANDLE_MINOR    3
# define STLSOFT_VER_STLSOFT_HPP_SCOPED_HANDLE_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_SCOPED_HANDLE_EDIT     641
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# pragma warning(push)
# pragma warning(disable : 4191)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k H
        ,   ss_typename_param_k R
        >
struct function_translator_cdecl
{
private:
    typedef void    (STLSOFT_CDECL *degenerate_function_type)();    // C++-98; 5.2.10;6
public:
    typedef R       (STLSOFT_CDECL *function_type)(H);

    static void translate(H h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        fn(h);
    }
};

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template<   ss_typename_param_k H
        ,   ss_typename_param_k R
        >
struct function_translator_fastcall
{
private:
    typedef void    (STLSOFT_CDECL *degenerate_function_type)();
public:
    typedef R       (STLSOFT_FASTCALL *function_type)(H);

    static void translate(H h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        fn(h);
    }
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template<   ss_typename_param_k H
        ,   ss_typename_param_k R
        >
struct function_translator_stdcall
{
private:
    typedef void    (STLSOFT_CDECL *degenerate_function_type)();
public:
    typedef R       (STLSOFT_STDCALL *function_type)(H);

    static void translate(H h, degenerate_function_type pv)
    {
        function_type   fn  =   reinterpret_cast<function_type>(pv);

        fn(h);
    }
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/// Provides automated scope-based cleanup of arbitrary resource types
///
/// The template is parameterised on the resource type (e.g. FILE*, int, void*)
/// and instances are initialised from a resource handle and the address of a
/// (single-parameter) cleanup function, as in:
///
/// \htmlonly
/// <pre>
///  ::stlsoft::scoped_handle<int>    h1(::open("file.ext"), ::close);
/// </pre>
/// \endhtmlonly
///
/// or:
///
/// \htmlonly
/// <pre>
///  FILE                             *file = ::fopen("file.ext", "r");
///  ::stlsoft::scoped_handle<FILE*>  h2(file, ::fclose);
/// </pre>
/// \endhtmlonly
///
/// or:
///
/// \htmlonly
/// <pre>
///  ::stlsoft::scoped_handle<void*>  h3(::malloc(100), ::free);
/// </pre>
/// \endhtmlonly
///
/// \note This class provides externally-initialised immutable-RAII (see section
/// 3.5 of Imperfect C++; http://imperfectcplusplus.com/). The managed resource
/// must be provided in the constructor, and the managing instance cannot be set
/// to manage another resource. However, there is a nod to convenience in so far
/// as there is a detach() method, which can be used to clear the resource from
/// the managing instance and return it to the calling context.

template<ss_typename_param_k H>
class scoped_handle
{
/// \name Types
/// @{
private:
    typedef void (STLSOFT_CDECL *degenerate_function_type)();
public:
    typedef H                   resource_type;
    typedef H                   handle_type;
    typedef scoped_handle<H>    class_type;
/// @}

/// \name Construction
/// @{
public:
#if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_CDECL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
#endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

#if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_CDECL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_cdecl<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
# if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "fastcall" function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_FASTCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
# endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "fastcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_FASTCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_fastcall<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
# endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */


#ifdef STLSOFT_CF_STDCALL_SUPPORTED
# if !defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) || \
     defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED)
    /// Construct from a resource handle and a clean-up "stdcall" function with void return type
    scoped_handle(  resource_type   h
                ,   void            (STLSOFT_STDCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, void>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
# endif /* !__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED */

# if defined(__STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Construct from a resource handle and a clean-up "stdcall" function with non-void return type
    template <ss_typename_param_k R>
    scoped_handle(  resource_type   h
                ,   R               (STLSOFT_STDCALL *f)(resource_type)
                ,   resource_type   hNull = 0)
        : m_h(h)
        , m_hNull(hNull)
        , m_tfn(&function_translator_stdcall<H, R>::translate)
        , m_fn(reinterpret_cast<degenerate_function_type>(f))
    {}
# endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

    /// Destructor
    ///
    /// Here is where the resource is cleaned up
    ~scoped_handle()
    {
        if(!empty())
        {
            m_tfn(m_h, m_fn);
        }
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the instance holds a non-"null" resource
    bool empty() const
    {
        return get_null_value_() == m_h;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Closes the handle
    ///
    /// \note Calling this method more than once has no effect.
    void close()
    {
        if(!empty())
        {
            m_tfn(m_h, m_fn);

            m_h   =   get_null_value_();
        }
    }

    /// Detaches the resource, and returns it to the calling context.
    ///
    /// \note Calling this method removes the resource from the managing
    /// instance, and it will not be automatically closed.
    resource_type detach()
    {
        resource_type   h   =   get_null_value_();

        std_swap(m_h, h);

        return h;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Provides the bare resource handle to the caller. Does not detach the
    /// handle from the managing instance.
    ///
    /// \deprecated
    resource_type handle() const
    {
#if defined(STLSOFT_COMPILER_IS_WATCOM)
        return (resource_type)(m_h);
#else /* ? compiler */
        return const_cast<resource_type>(m_h);
#endif /* compiler */
    }
    /// Provides the bare resource handle to the caller. Does not detach the
    /// handle from the managing instance.
    resource_type get() const
    {
        return const_cast<class_type&>(*this).m_h;
    }
/// @}

/// \name Implementation
/// @{
private:
    resource_type get_null_value_() const
    {
        return m_hNull;
    }
/// @}

/// \name Members
/// @{
private:
    resource_type               m_h;                                    //!< The handle to the managed resource
    const resource_type         m_hNull;                                //!< The value for the null handle
    void                        (*m_tfn)(H , degenerate_function_type); //!< The function translator function
    degenerate_function_type    m_fn;                                   //!< The actual resource release function
/// @}

// Not to be implemented
private:
    scoped_handle(class_type const &);
    scoped_handle &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<   ss_typename_param_k H
        >
inline void swap(scoped_handle<H> &lhs, scoped_handle<H> &rhs)
{
    lhs.swap(rhs);
}

////////////////////////////////////////////////////////////////////////////////
// Shims

#if 0
template<ss_typename_param_k H>
inline H get_handle(scoped_handle<H> &h)
{
    return h.get();
}
#endif /* 0 */

template<ss_typename_param_k H>
#if defined(STLSOFT_COMPILER_IS_WATCOM)
inline H get_handle(scoped_handle<H> const &h)
#else /* ? compiler */
inline ss_typename_type_k scoped_handle<H>::handle_type get_handle(scoped_handle<H> const &h)
#endif /* compiler */
{
    return h.get();
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        void STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl(short )
        {}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
        void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall(long )
        {}
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
        void STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall(unsigned )
        {}
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

        ss_bool_t test_stlsoft_scoped_handle(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "scoped_handle", __FILE__);

            // cdecl
            {
                scoped_handle<short>    sh1(23, test_stlsoft_scoped_handle__close_short_cdecl);

                if(23 != ::stlsoft::get_handle(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
            // fastcall
            {
                scoped_handle<long>    sh1(24, test_stlsoft_scoped_handle__close_long_fastcall);

                if(24 != ::stlsoft::get_handle(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
            // stdcall
            {
                scoped_handle<unsigned>    sh1(25, test_stlsoft_scoped_handle__close_unsigned_stdcall);

                if(25 != ::stlsoft::get_handle(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_scoped_handle(test_stlsoft_scoped_handle);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we 
 * illegally insert into the std namespace.
 */
#if defined(__STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k H
            >
    inline void swap(stlsoft_ns_qual(scoped_handle)<H> &lhs, stlsoft_ns_qual(scoped_handle)<H> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace std
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* __STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# pragma warning(pop)
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */

/* ////////////////////////////////////////////////////////////////////////// */
