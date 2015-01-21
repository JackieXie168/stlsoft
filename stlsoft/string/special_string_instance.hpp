/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/special_string_instance.hpp (originally winstl_current_directory.h)
 *
 * Purpose:     Special string instance class template.
 *
 * Created:     3rd June 2006
 * Updated:     7th June 2006
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


/** \file stlsoft/string/special_string_instance.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::special_string_instance
 *  class template.
 *  (\ref group__library__string "String" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_MAJOR       1
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_MINOR       0
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_REVISION    1
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_EDIT        1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_MSVC: _MSC_VER<1200
[Incompatibilies-end]
 */


/* Compatibility
[<[STLSOFT-AUTO:NO-DOCFILELABEL]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */
#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
#  include <stlsoft/meta/select_first_type_if.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Special string instance class template.
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k P
        >
class special_string_instance_0
{
/// \name Member Types
/// @{
public:
    /// \brief The character type.
    typedef C                                           char_type;
    /// \brief The policy type.
    typedef P                                           policy_type;
    /// \brief The current instantiation of the template.
    typedef special_string_instance_0<C, P>             class_type;
    /// \brief The size type
    typedef ss_typename_type_k policy_type::size_type   size_type;
private:
    /// \brief 
#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT)
    typedef ss_typename_type_k select_first_type_if<char_type const*
                                                ,   void
                                                ,   policy_type::allowImplicitConversion
                                                >::type implicit_conversion_type;
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    typedef char_type const                             *implicit_conversion_type;
#endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    typedef ss_typename_type_k policy_type::ss_template_qual_k buffer_selector<char_type>      selector_type;
    typedef ss_typename_type_k selector_type::buffer_type                   buffer_type;
/// @}

/// \name Construction
/// @{
public:
    special_string_instance_0()
        : m_buffer(selector_type::construct_buffer())
        , m_len(selector_type::init_len_from_buffer(m_buffer))
    {}
    ~special_string_instance_0() stlsoft_throw_0()
    {
    }

/// @}

/// \name Operations
/// @{
public:
    static size_type get(char_type *buffer, size_type cchBuffer)
    {
        return selector_type::get(buffer, cchBuffer);
    }
/// @}

/// \name Attributes
/// @{
public:
    char_type const *c_str() const
    {
        return stlsoft_ns_qual(c_str_ptr)(m_buffer);
    }
    size_type       length() const
    {
        return m_len;
    }
    size_type       size() const
    {
        return m_len;
    }
/// @}

/// \name Operators
/// @{
public:
    operator implicit_conversion_type () const
    {
        return this->c_str();
    }
/// @}

/// \name Implementation
/// @{
private:

/// @}

/// \name Member Types
/// @{
private:
    buffer_type m_buffer;
    size_type   m_len;
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */

/* ////////////////////////////////////////////////////////////////////// */
