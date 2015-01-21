/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/errorinfo_desc.hpp (formerly comstl_error.h)
 *
 * Purpose:     errorinfo_desc class for accessing description from the COM error.
 *
 * Created:     19th December 2002
 * Updated:     6th June 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file comstl/errorinfo_desc.hpp
///
/// errorinfo_desc class for accessing description from the COM error.
///
/// \note The contents of this file are not a final form, and <b>will</b> change in
/// future releases.

#ifndef COMSTL_INCL_COMSTL_HPP_ERRORINFO_DESC
#define COMSTL_INCL_COMSTL_HPP_ERRORINFO_DESC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_ERRORINFO_DESC_MAJOR     0
# define COMSTL_VER_COMSTL_HPP_ERRORINFO_DESC_MINOR     3
# define COMSTL_VER_COMSTL_HPP_ERRORINFO_DESC_REVISION  2
# define COMSTL_VER_COMSTL_HPP_ERRORINFO_DESC_EDIT      11
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-DOCFILELABEL]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* ////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD
# include <stlsoft/string_access_fwd.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS_FWD */
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
# include <stdexcept>
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */

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

/// \defgroup comstl_error_functions Error Functions
/// \ingroup COMSTL
/// \ingroup functions
/// \brief These functions assist in the handling of COM error info
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

class errorinfo_desc
{
/// \name Types
/// @{
public:
    typedef errorinfo_desc  class_type;
/// @}

/// \name Construction
/// @{
public:
    errorinfo_desc()
        : m_description(NULL)
        , m_description_a(NULL)
        , m_len(0)
    {
        IErrorInfo  *pei;

        if(S_OK == ::GetErrorInfo(0, &pei))
        {
            get_description(pei, m_description, m_len);

            pei->Release();
        }
    }
    errorinfo_desc(IErrorInfo *pei)
        : m_description(NULL)
        , m_description_a(NULL)
    {
        get_description(pei, m_description, m_len);
    }
    errorinfo_desc(errorinfo_desc const &rhs)
        : m_description(::SysAllocString(rhs.m_description))
        , m_description_a(NULL)
        , m_len(rhs.m_len)
    {}

    ~errorinfo_desc() stlsoft_throw_0()
    {
        ::SysFreeString(m_description);
        ::CoTaskMemFree(m_description_a);
    }
/// @}

/// \name Accessors
/// @{
public:
    LPCOLESTR c_str_w() const
    {
        return (NULL == m_description) ? L"" : m_description;
    }
    char const *c_str_a() const
    {
        return const_cast<class_type*>(this)->check_description_a_();
    }
#ifdef UNICODE
    LPCOLESTR c_str() const
    {
        return c_str_w();
    }
#else /* ? UNICODE */
    char const *c_str() const
    {
        return c_str_a();
    }
#endif /* UNICODE */
    cs_size_t length() const
    {
        return m_len;
    }
/// @}

/// \name Implementation
/// @{
private:
    char const *check_description_a_()
    {
        if( NULL == m_description_a &&
            NULL != m_description)
        {
            int cch = ::WideCharToMultiByte(0, 0, m_description, -1, NULL, 0, NULL, NULL);

            m_description_a = (char*)::CoTaskMemAlloc((1 + cch) * sizeof(char));

            if(NULL == m_description_a)
            {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
                throw stlsoft_ns_qual_std(bad_alloc)();
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
            }
            else
            {
                ::WideCharToMultiByte(0, 0, m_description, -1, m_description_a, 1 + cch, NULL, NULL);
            }
        }

        return (NULL == m_description_a) ? "" : m_description_a;
    }

    static void get_description(IErrorInfo *pei, BSTR &description, cs_size_t &len)
    {
        BSTR    bstr;

        if( 0 != pei &&
            SUCCEEDED(pei->GetDescription(&bstr)))
        {
            // Now trim backwards to get rid of any trailing
            // whitespace
            LPOLESTR    begin   =   bstr;
            LPOLESTR    end     =   begin + ::SysStringLen(bstr);
            LPOLESTR    last    =   end;

            for(; begin != last; --last)
            {
                OLECHAR ch = *(last - 1);

                // This is not terribly internationalised, but
                // will suffice for these simple purposes.
                if( ch == ' ' ||
                    ch == '\t' ||
                    ch == '\r' ||
                    ch == '\n')
                {
                }
                else
                {
                    break;
                }
            }

            description = ::SysAllocStringLen(bstr, static_cast<UINT>(last - begin));

            if(NULL == description)
            {
                // Failed, so grab what there is, which is better than nothing
                description = bstr;
            }
            else
            {
                ::SysFreeString(bstr);
            }

            len = static_cast<cs_size_t>(last - begin);
        }
    }
/// @}

/// \name Members
/// @{
protected:
    BSTR        m_description;
    char        *m_description_a;
    cs_size_t   m_len;
/// @}

// Not to be implemented
protected:
    class_type const &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline cs_size_t c_str_len_a(errorinfo_desc const &eid)
{
    return eid.length();
}

inline cs_size_t c_str_len_w(errorinfo_desc const &eid)
{
    return eid.length();
}

inline cs_size_t c_str_len_o(errorinfo_desc const &eid)
{
    return eid.length();
}

inline cs_size_t c_str_len(errorinfo_desc const &eid)
{
    return eid.length();
}

#if 0
inline cs_size_t c_str_size_a(errorinfo_desc const &eid)
{
    return static_cast<cs_size_t>(::WideCharToMultiByte(0, 0, eid.c_str_w(), static_cast<int>(eid.length()), NULL, 0, NULL, NULL));
}
#endif /* 0 */

#if 0
inline cs_size_t c_str_size_w(errorinfo_desc const &eid)
{
    return eid.length() * sizeof(cs_char_w_t);
}
#endif /* 0 */

#if 0
inline cs_size_t c_str_size_o(errorinfo_desc const &eid)
{
    return eid.length() * sizeof(cs_char_o_t);
}
#endif /* 0 */

#if 0
inline cs_size_t c_str_size(errorinfo_desc const &eid)
{
#ifdef UNICODE
    return c_str_size_w(eid);
#else /* ? UNICODE */
    return c_str_size_a(eid);
#endif /* UNICODE */
}
#endif /* 0 */

inline cs_char_a_t const *c_str_ptr_a(errorinfo_desc const &eid)
{
    return eid.c_str_a();
}

inline cs_char_w_t const *c_str_ptr_w(errorinfo_desc const &eid)
{
    return eid.c_str_w();
}

inline cs_char_o_t const *c_str_ptr_o(errorinfo_desc const &eid)
{
    return eid.c_str_w();
}

inline LPCTSTR c_str_ptr(errorinfo_desc const &eid)
{
    return eid.c_str();
}

inline cs_char_a_t const *c_str_data_a(errorinfo_desc const &eid)
{
    return eid.c_str_a();
}

inline cs_char_w_t const *c_str_data_w(errorinfo_desc const &eid)
{
    return eid.c_str_w();
}

inline cs_char_o_t const *c_str_data_o(errorinfo_desc const &eid)
{
    return eid.c_str_w();
}

inline LPCTSTR c_str_data(errorinfo_desc const &eid)
{
    return eid.c_str();
}

inline cs_char_a_t const *c_str_ptr_null_a(errorinfo_desc const &eid)
{
    return (0 != eid.length()) ? eid.c_str_a() : NULL;
}

inline cs_char_w_t const *c_str_ptr_null_w(errorinfo_desc const &eid)
{
    return (0 != eid.length()) ? eid.c_str_w() : NULL;
}

inline cs_char_o_t const *c_str_ptr_null_o(errorinfo_desc const &eid)
{
    return (0 != eid.length()) ? eid.c_str_w() : NULL;
}

inline LPCTSTR c_str_ptr_null(errorinfo_desc const &eid)
{
    return (0 != eid.length()) ? eid.c_str() : NULL;
}

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

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _COMSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::comstl::c_str_ptr_null_a;
using ::comstl::c_str_ptr_null_w;
using ::comstl::c_str_ptr_null_o;
using ::comstl::c_str_ptr_null;

using ::comstl::c_str_ptr_a;
using ::comstl::c_str_ptr_w;
using ::comstl::c_str_ptr_o;
using ::comstl::c_str_ptr;

using ::comstl::c_str_data_a;
using ::comstl::c_str_data_w;
using ::comstl::c_str_data_o;
using ::comstl::c_str_data;

using ::comstl::c_str_len_a;
using ::comstl::c_str_len_w;
using ::comstl::c_str_len_o;
using ::comstl::c_str_len;

#if 0
using ::comstl::c_str_size_a;
using ::comstl::c_str_size_w;
using ::comstl::c_str_size_o;
using ::comstl::c_str_size;
#endif /* 0 */

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_ERRORINFO_DESC */

/* ////////////////////////////////////////////////////////////////////////// */