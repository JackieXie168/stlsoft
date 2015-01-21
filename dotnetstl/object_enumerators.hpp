/* /////////////////////////////////////////////////////////////////////////////
 * File:        dotnetstl/object_enumerators.hpp (formerly dotnetstl_object_enumerators.h)
 *
 * Purpose:     A simple object enumerator, based on ArrayList.
 *
 * Created:     24th June 2003
 * Updated:     21st March 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2006, Matthew Wilson and Synesis Software
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


/// \file dotnetstl/object_enumerators.hpp
///
/// A simple object enumerator, based on ArrayList.

#ifndef DOTNETSTL_INCL_DOTNETSTL_HPP_OBJECT_ENUMERATORS
#define DOTNETSTL_INCL_DOTNETSTL_HPP_OBJECT_ENUMERATORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DOTNETSTL_VER_DOTNETSTL_HPP_OBJECT_ENUMERATORS_MAJOR       3
# define DOTNETSTL_VER_DOTNETSTL_HPP_OBJECT_ENUMERATORS_MINOR       1
# define DOTNETSTL_VER_DOTNETSTL_HPP_OBJECT_ENUMERATORS_REVISION    1
# define DOTNETSTL_VER_DOTNETSTL_HPP_OBJECT_ENUMERATORS_EDIT        17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef DOTNETSTL_INCL_DOTNETSTL_HPP_DOTNETSTL
# include <dotnetstl/dotnetstl.hpp>
#endif /* !DOTNETSTL_INCL_DOTNETSTL_HPP_DOTNETSTL */

/* ////////////////////////////////////////////////////////////////////////// */

#ifdef _STLSOFT_NO_NAMESPACE
/* There is no stlsoft namespace, so must define ::dotnetstl */
namespace dotnetstl
{
#else
/* Define stlsoft::dotnet_project */

namespace stlsoft
{

namespace dotnetstl_project
{

#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_container Container Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulation containers

/// \defgroup dotnetstl_container_library Container Library (.netSTL)
/// \ingroup dotnetSTL libraries_container
/// \brief This library provides facilities for defining and manipulation containers in .NET
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Provides an IEnumerator implementation on an ArrayList
public __gc class ArrayListEnumerator
    : public System::Collections::IEnumerator
{
//    typedef System::Collections::ArrayList  ArrayList;

public:
    /// Creates an enumerator for the given list.
    ArrayListEnumerator(System::Collections::ArrayList *objects)
        : m_objects(objects)
        , m_index(-1)
    {}

public: // VC++ 7.1 requires that these be public
    /// Returns the current object
    Object* get_Current()
    {
        if( m_index < 0 ||
            !(m_index < m_objects->get_Count()))
        {
            throw new System::InvalidOperationException();
        }

        return m_objects->get_Item(m_index);
    }

    /// Advances the search by one position
    ///
    /// \retval true An object is available at the new position
    /// \retval false The enumeration is complete
    bool MoveNext()
    {
        if(m_index < m_objects->get_Count() - 1)
        {
            ++m_index;

            return true;
        }
        else
        {
            return false;
        }
    }

    /// Resets the enumeration
    void Reset()
    {
        m_index = -1;
    }

// Members
private:
    System::Collections::ArrayList  *m_objects;
    int                             m_index;

// Not to be implemented
private:
    ArrayListEnumerator(ArrayListEnumerator const &)
    {}
//  ArrayListEnumerator &operator =(ArrayListEnumerator const &);
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/object_enumerators_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group dotnetstl_container_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifdef _STLSOFT_NO_NAMESPACE
} // namespace dotnetstl
#else
} // namespace dotnetstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* DOTNETSTL_INCL_DOTNETSTL_HPP_OBJECT_ENUMERATORS */

/* ////////////////////////////////////////////////////////////////////////// */