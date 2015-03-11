/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/containers/frequency_map.hpp
 *
 * Purpose:     A container that measures the frequency of the unique elements it contains.
 *
 * Created:     1st October 2005
 * Updated:     12th March 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2007, Matthew Wilson and Synesis Software
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


/** \file stlsoft/containers/frequency_map.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::frequency_map container
 *   class template
 *   (\ref group__library__containers "Containers" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MAJOR    2
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MINOR    0
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_REVISION 7
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_EDIT     16
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#include <map>
#include <stdexcept>

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

/** \brief A container that measures the frequency of the unique elements it
 *    contains.
 *
 * \ingroup group__library__containers
 *
 */
template<   ss_typename_param_k T
        ,   ss_typename_param_k N = uint32_t
        >
class frequency_map
    : public stl_collection_tag
{
private:
    typedef stlsoft_ns_qual_std(map)<T, N>                  map_type;

public:
    typedef ss_typename_param_k map_type::value_type        value_type;
    typedef ss_typename_param_k map_type::const_iterator    const_iterator;
//    typedef ss_typename_param_k map_type::const_pointer     const_pointer;
    typedef ss_typename_param_k map_type::const_reference   const_reference;

    typedef ss_typename_param_k map_type::key_type          key_type;
//    typedef ss_typename_param_k map_type::mapped_type       mapped_type
    typedef N                                               count_type;
    typedef ss_size_t                                       size_type;
    typedef ss_ptrdiff_t                                    difference_type;

public:
    frequency_map()
    {}

public:
    count_type  push(key_type const& key)
    {
        return ++m_map[key];
    }

    void        clear()
    {
        m_map.clear();
    }

    count_type  operator [](key_type const& key) const // stlsoft_throw_1(std::out_of_range)
    {
        const_iterator  it  =   m_map.find(key);

        if(m_map.end() == it)
        {
            STLSOFT_THROW_X(stlsoft_ns_qual_std(out_of_range)("invalid key"));
        }

        return (*it).second;
    }

public:
    ss_bool_t   empty() const
    {
        return m_map.empty();
    }

    size_type   size() const
    {
        return m_map.size();
    }

public:
    const_iterator  begin() const
    {
        return m_map.begin();
    }
    const_iterator  end() const
    {
        return m_map.end();
    }

private:
    map_type    m_map;
};

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/frequency_map_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP */

/* ////////////////////////////////////////////////////////////////////// */
