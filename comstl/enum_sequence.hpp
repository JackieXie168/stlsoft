/* /////////////////////////////////////////////////////////////////////////////
 * File:        comstl/enum_sequence.hpp (formerly comstl_enum_sequence.h; originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose:     STL sequence for IEnumXXXX enumerator interfaces.
 *
 * Created:     17th September 1998
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1998-2006, Matthew Wilson and Synesis Software
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


/// \file comstl/enum_sequence.hpp
///
/// STL sequence for IEnumXXXX enumerator interfaces.

#ifndef COMSTL_INCL_COMSTL_HPP_ENUM_SEQUENCE
#define COMSTL_INCL_COMSTL_HPP_ENUM_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_HPP_ENUM_SEQUENCE_MAJOR      5
# define COMSTL_VER_COMSTL_HPP_ENUM_SEQUENCE_MINOR      2
# define COMSTL_VER_COMSTL_HPP_ENUM_SEQUENCE_REVISION   1
# define COMSTL_VER_COMSTL_HPP_ENUM_SEQUENCE_EDIT       191
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

#ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
# pragma message("This file is now obsolete. Instead include comstl/enumerator_sequence.hpp")
#endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */

#ifndef COMSTL_INCL_COMSTL_HPP_ENUMERATOR_SEQUENCE
# include <comstl/enumerator_sequence.hpp>
#endif /* !COMSTL_INCL_COMSTL_HPP_ENUMERATOR_SEQUENCE */

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

/// \weakgroup comstl_itf_library Interface Library
/// \ingroup COMSTL libraries
/// \brief This library provides facilities for manipulating COM interfaces
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief Deprecated forwarding template for enumerator_sequence, providing backwards compatibility
///
/// \deprecated
template<   ss_typename_param_k I   /* Interface */
        ,   ss_typename_param_k V   /* Value type */
        ,   ss_typename_param_k VP  /* Value policy type */
        ,   ss_typename_param_k R   /* Reference type */
        ,   ss_typename_param_k CP  /* Cloning policy type */
        ,   cs_size_t           Q   /* Quanta */
        >
class enum_simple_sequence
    : public enumerator_sequence<I, V, VP, R, CP, Q>
{
private:
    typedef enumerator_sequence<I, V, VP, R, CP, Q>                     parent_class_type;
public:
    /// Interface type
    typedef ss_typename_type_k parent_class_type::interface_type        interface_type;
    /// Value type
    typedef ss_typename_type_k parent_class_type::value_type            value_type;
    /// Value policy type
    typedef ss_typename_type_k parent_class_type::value_policy_type     value_policy_type;
    /// Reference type
    typedef ss_typename_type_k parent_class_type::reference_type        reference_type;
    /// Cloning policy type
    typedef ss_typename_type_k parent_class_type::cloning_policy_type   cloning_policy_type;
    /// Iterator tag type
    typedef ss_typename_type_k parent_class_type::iterator_tag_type     iterator_tag_type;
    /// Type of the current parameterisation
    typedef enum_simple_sequence<I, V, VP, R, CP, Q>                    class_type;

public:
    /// Constructor
    ///
    /// \param i The enumeration interface pointer to adapt
    /// \param bAddRef Causes a reference to be added if \c true, otherwise the sequence is deemed to <i>sink</i>, or consume, the interface pointer
    enum_simple_sequence(interface_type *i, cs_bool_t bAddRef)
        : parent_class_type(i, bAddRef)
    {}
};

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group comstl_itf_library

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

#endif /* !COMSTL_INCL_COMSTL_HPP_ENUM_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
