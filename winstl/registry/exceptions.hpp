/* /////////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/exceptions.hpp
 *
 * Purpose:     Exceptions used by the Registry library.
 *
 * Created:     8th February 2006
 * Updated:     21st March 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/// \file winstl/registry/exceptions.hpp
///
/// Exceptions used by the Registry library.

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_EXCEPTIONS_MAJOR    1
# define WINSTL_VER_WINSTL_REGISTRY_HPP_EXCEPTIONS_MINOR    0
# define WINSTL_VER_WINSTL_REGISTRY_HPP_EXCEPTIONS_REVISION 3
# define WINSTL_VER_WINSTL_REGISTRY_HPP_EXCEPTIONS_EDIT     4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_EXCEPTIONS
# include <winstl/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_EXCEPTIONS */

/* /////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup winstl_reg_library Registry Library
/// \ingroup WinSTL libraries
/// \brief This library provides facilities for working with the Windows registry
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Root exception thrown by the Registry library
class registry_exception
    : public windows_exception
{
/// \name Member Types
/// @{
public:
    typedef windows_exception           parent_class_type;
    typedef registry_exception          class_type;
/// @}

/// \name Construction
/// @{
public:
    registry_exception(char const *reason, error_code_type err)
        : windows_exception(reason, err)
    {}
/// @}
};

/// Exception class representing a mismatch of value type
class wrong_value_type_exception
    : public registry_exception
{
/// \name Member Types
/// @{
public:
    typedef registry_exception          parent_class_type;
    typedef wrong_value_type_exception  class_type;
/// @}

/// \name Construction
/// @{
public:
    wrong_value_type_exception(char const *reason, error_code_type err, ws_dword_t type)
        : parent_class_type(reason, err)
        , m_valueType(type)
    {}
/// @}

/// \name Accessors
/// @{
public:
    ws_dword_t actual_value_type() const
    {
        return m_valueType;
    }
/// @}

/// \name Members
/// @{
private:
    const ws_dword_t    m_valueType;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}
};

/// Exception class representing insufficient rights to access a key
class access_denied_exception
    : public registry_exception
{
/// \name Member Types
/// @{
public:
    typedef registry_exception          parent_class_type;
    typedef access_denied_exception     class_type;
/// @}

/// \name Construction
/// @{
public:
    access_denied_exception(char const *reason, error_code_type err)
        : parent_class_type(reason, err)
    {}
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type &operator =(class_type const &);
/// @}
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group winstl_reg_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_REGISTRY_HPP_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
