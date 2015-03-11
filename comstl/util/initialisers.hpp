/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/initialisers.hpp (originally MOInit.h, ::SynesisCom)
 *
 * Purpose:     Contains classes for initialising COM/OLE.
 *
 * Created:     8th February 1999
 * Updated:     16th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2006, Matthew Wilson and Synesis Software
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


/// \file comstl/util/initialisers.hpp
///
/// Contains classes for initialising COM/OLE.

#ifndef COMSTL_INCL_COMSTL_HPP_INITIALISERS
#define COMSTL_INCL_COMSTL_HPP_INITIALISERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_INITIALISERS_MAJOR       3
# define COMSTL_VER_COMSTL_HPP_INITIALISERS_MINOR       2
# define COMSTL_VER_COMSTL_HPP_INITIALISERS_REVISION    1
# define COMSTL_VER_COMSTL_HPP_INITIALISERS_EDIT        64
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS
# include <comstl/error/exceptions.hpp>
#endif /* !COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS */

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
 * Exception classes
 */

/** \brief Exception class thrown for COM initialisation failures
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
class com_initialisation_exception
    : public com_exception
{
/// \name Member Types
/// @{
public:
    typedef com_exception                   parent_class_type;
    typedef com_initialisation_exception    class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k com_initialisation_exception(HRESULT hr)
        : parent_class_type(hr)
    {}
    com_initialisation_exception(char const *reason, HRESULT hr)
        : parent_class_type(reason, hr)
    {}
/// @}

/// \name Implementation
/// @{
private:
    virtual char const *real_what_() const throw()
    {
        return "COM initialisation failure";
    }
/// @}
};

////////////////////////////////////////////////////////////////////////////
// Exception policies

/** \brief Exception policy whose action is to do nothing
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
// [[synesis:class:exception-policy: com_initialisation_exception_policy]]
struct com_initialisation_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The exception type
    typedef com_initialisation_exception    thrown_type;
/// @}

/// \name Operators
/// @{
public:
    /// The function call operator, which throws the exception
    ///
    /// \param hr The HRESULT that caused the error
    void operator ()(HRESULT hr)
    {
        throw com_initialisation_exception(hr);
    }
/// @}
};

/** \brief Exception policy whose action is to do nothing
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef stlsoft_ns_qual(null_exception_policy)  ignore_initialisation_exception_policy;

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Initialises the COM libraries
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * This class is used to initialise the COM libraries. It can respond to
 * CoInitializeEx argument flags when translated in a DCOM build.
 */
template<   ss_typename_param_k IP  /* Initialisation policy type */
        ,   ss_typename_param_k XP  /* Exception policy type */
        >
class initialiser
{
/// \name Member Types
/// @{
private:
    typedef initialiser   class_type;
public:
    /// The initialiation policy type
    typedef IP                                                      initialisation_policy_type;
    /// The exception type
    typedef XP                                                      exception_policy_type;
    /// The thrown type
    typedef ss_typename_type_k exception_policy_type::thrown_type   thrown_type;
/// @}

/// \name Construction
/// @{
public:
    /// Initialises via CoInitialize()
    initialiser();
#ifdef __COMSTL_CF_DCOM_SUPPORT
    /// Initialises via CoInitializeEx() taking b>COINIT_*</b> flags
    ss_explicit_k initialiser(cs_dword_t dwInit /* = COINIT_APARTMENTTHREADED */);
#endif /* __COMSTL_CF_DCOM_SUPPORT */
    /// Uninitialises via CoUninitialize()
    ~initialiser() stlsoft_throw_0();
/// @}

/// \name Attributes
/// @{
public:
    /// Reflects whether the COM libraries were initialised
    cs_bool_t is_initialised() const;
    /// Reflects whether the COM libraries were not initialised
    cs_bool_t operator !() const;
    /// The result of the call to CoInitialize()/CoInitializeEx()
    HRESULT get_HRESULT() const;
/// @}

/// \name Members
/// @{
private:
    HRESULT const   m_hr;
/// @}

/// \name Not to be implemented
/// @{
private:
    initialiser(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);
/// @}
};

////////////////////////////////////////////////////////////////////////////
// Value policies

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct CoInitialize_policy
{
public:
    static HRESULT init()
    {
        return ::CoInitialize(NULL);
    }
#ifdef __COMSTL_CF_DCOM_SUPPORT
    static HRESULT init(cs_dword_t coInit)
    {
        return ::CoInitializeEx(NULL, coInit);
    }
#endif /* __COMSTL_CF_DCOM_SUPPORT */
    static void uninit()
    {
        ::CoUninitialize();
    }
};

struct OleInitialize_policy
{
public:
    static HRESULT init()
    {
        return ::OleInitialize(NULL);
    }
    static void uninit()
    {
        ::OleUninitialize();
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////
// Typedefs for common instantiations

/** \brief Instantiation that initialises via CoInitialize() but does not throw on failure.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef initialiser<CoInitialize_policy, ignore_initialisation_exception_policy>    com_init_nothrow;
/** \brief Instantiation that initialises via OleInitialize() but does not throw on failure.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef initialiser<OleInitialize_policy, ignore_initialisation_exception_policy>   ole_init_nothrow;

/** \brief Instantiation that initialises via CoInitialize() and throws on failure.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef initialiser<CoInitialize_policy, com_initialisation_exception_policy>       com_init;
/** \brief Instantiation that initialises via OleInitialize() and throws on failure.
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef initialiser<OleInitialize_policy, com_initialisation_exception_policy>      ole_init;

/** \brief \deprecated
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef com_init_nothrow                                                            com_initialiser;
/** \brief \deprecated
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef ole_init_nothrow                                                            ole_initialiser;

////////////////////////////////////////////////////////////////////////////
// Typedefs for US-English spellers

/** \brief Equivalent to com_initialiser
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef com_initialiser com_initializer;
/** \brief Equivalent to ole_initialiser
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 */
typedef ole_initialiser ole_initializer;

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_initialisers(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "initialisers", __FILE__);

            com_initializer coinit;

    #if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_initialisers(test_comstl_initialisers);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

////////////////////////////////////////////////////////////////////////////
// Implementation

// initialiser

template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline initialiser<IP, XP>::initialiser()
    : m_hr(initialisation_policy_type::init())
{
    if(FAILED(m_hr))
    {
        exception_policy_type   xp;

        xp(m_hr);
    }
}

#ifdef __COMSTL_CF_DCOM_SUPPORT
template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline initialiser<IP, XP>::initialiser(cs_dword_t coInit)
    : m_hr(initialisation_policy_type::init(coInit))
{
    if(FAILED(m_hr))
    {
        exception_policy_type   xp;

        xp(m_hr);
    }
}
#endif // __COMSTL_CF_DCOM_SUPPORT

template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline initialiser<IP, XP>::~initialiser() stlsoft_throw_0()
{
    if(is_initialised())
    {
        initialisation_policy_type::uninit();
    }
}

template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline cs_bool_t initialiser<IP, XP>::is_initialised() const
{
    return SUCCEEDED(m_hr);
}

template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline cs_bool_t initialiser<IP, XP>::operator !() const
{
    return !is_initialised();
}

template<   ss_typename_param_k IP
        ,   ss_typename_param_k XP
        >
inline HRESULT initialiser<IP, XP>::get_HRESULT() const
{
    return m_hr;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _COMSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_HPP_INITIALISERS */

/* ////////////////////////////////////////////////////////////////////// */
