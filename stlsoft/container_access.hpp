/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/container_access.hpp
 *
 * Purpose:     Container accessor functions.
 *
 * Created:     11th November 2004
 * Updated:     7th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2006, Matthew Wilson and Synesis Software
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


/// \file stlsoft/container_access.hpp
///
/// Container accessor functions.

#ifndef STLSOFT_INCL_STLSOFT_HPP_CONTAINER_ACCESS
#define STLSOFT_INCL_STLSOFT_HPP_CONTAINER_ACCESS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_CONTAINER_ACCESS_MAJOR     1
# define STLSOFT_VER_STLSOFT_HPP_CONTAINER_ACCESS_MINOR     3
# define STLSOFT_VER_STLSOFT_HPP_CONTAINER_ACCESS_REVISION  2
# define STLSOFT_VER_STLSOFT_HPP_CONTAINER_ACCESS_EDIT      23
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>      // for discrimination of the MSVC Dinkumware libs (with the bad member types)
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#include <stdexcept>
#ifdef STLSOFT_UNITTEST
# include <map>
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Compiler / library compatibility
 */

#ifdef STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE
# undef STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE
#endif /* STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC)
# if STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION <= STLSOFT_CF_DINKUMWARE_VC_VERSION_6_0
#  define   STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE
# endif /* STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION */
#endif /* STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** \brief Looks up and returns the matching referent for a given key, or throws
 * std::out_of_range if the key is not found in the map
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param m The map to be searched
 * \param key The key to be searched for
 *
 * \return The matching referent
 *
 * \note If \c key does not refer to an entry in the map \c m, then
 * std::out_of_range is thrown
 */
#if (   !defined(STLSOFT_COMPILER_IS_INTEL) && \
        !defined(STLSOFT_COMPILER_IS_MSVC)) || \
    _MSC_VER >= 1310
template<   ss_typename_param_k M
        ,   ss_typename_param_k K
        >
# ifdef STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE
inline ss_typename_type_k M::referent_type &lookup(M &m, K const &key)
# else /* ? STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE */
inline ss_typename_type_k M::mapped_type &lookup(M &m, K const &key)
# endif /* STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE */
{
    ss_typename_type_k M::iterator it = m.find(key);

    if(m.end() == it)
    {
        throw stlsoft_ns_qual_std(out_of_range)("invalid key");
    }

    return (*it).second;
}
#endif /* compiler */

/** \brief Looks up and returns the matching referent for a given key, or throws
 * std::out_of_range if the key is not found in the map
 *
 * \ingroup group__library__<<LIBRARY-ID>>
 *
 * \param m The map to be searched
 * \param key The key to be searched for
 *
 * \return The matching referent
 *
 * \note If \c key does not refer to an entry in the map \c m, then
 * std::out_of_range is thrown
 */
template<   ss_typename_param_k M
        ,   ss_typename_param_k K
        >
#ifdef STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE
inline ss_typename_type_k M::referent_type const &lookup(M const &m, K const &key)
#else /* ? STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE */
inline ss_typename_type_k M::mapped_type const &lookup(M const &m, K const &key)
#endif /* STLSOFT_CONTAINER_ACCESS_MAPPED_TYPE_IS_REFERENT_TYPE */
{
    ss_typename_type_k M::const_iterator it = m.find(key);

    if(m.end() == it)
    {
        throw std::out_of_range("invalid key");
    }

    return (*it).second;
}

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        class FakeMap
        {
        public:
            typedef int                                 key_type;
            typedef int                                 mapped_type;
            typedef int                                 referent_type;
            typedef std::pair<key_type, mapped_type>    value_type;
            typedef value_type                          *iterator;
            typedef value_type const                    *const_iterator;

            const_iterator  end() const                 { return NULL; }
            iterator        end()                       { return NULL; }

            mapped_type &operator [](key_type /* k */)
            {
                return get_ref_();
            }

            const_iterator  find(key_type k) const
            {
                switch(k)
                {
                    case    1:
                    case    2:
                        return &get_value_();
                    default:
                        return end();
                }
            }

            iterator  find(key_type k)
            {
                switch(k)
                {
                    case    1:
                    case    2:
                        return &get_value_();
                    default:
                        return end();
                }
            }

        private:
            static value_type       &get_value_()
            {
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because unit-testing is single-threaded
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

                static value_type       s_value_;

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

                return s_value_;
            }
            static mapped_type      &get_ref_()
            {
                static mapped_type    s_ref_;

                return s_ref_;
            }
        };

        ss_bool_t test_stlsoft_container_access(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "container_access", __FILE__);

//            typedef ::std::map<int, int>  map_t;
            typedef FakeMap                 map_t;

            map_t   m;

            m[1] = 1;
            m[2] = 2;

            try
            {
                (void)lookup(m, 3);

                // Should not get here
                r->report("Search for non-existant erroneously succeeded", __LINE__);
                bSuccess = false;
            }
            catch(stlsoft_ns_qual_std(out_of_range) &)
            {}

            try
            {
                (void)lookup(m, 2);
            }
            catch(stlsoft_ns_qual_std(out_of_range) &)
            {
                // Should not get here
                r->report("Search for existing erroneously failed", __LINE__);
                bSuccess = false;
            }

            map_t const &m2 =   m;

            try
            {
                const int   x   =   3;

                (void)lookup(m2, x);

                // Should not get here
                r->report("Search for non-existant erroneously succeeded", __LINE__);
                bSuccess = false;
            }
            catch(stlsoft_ns_qual_std(out_of_range) &)
            {}

            try
            {
                (void)lookup(m2, 2);
            }
            catch(stlsoft_ns_qual_std(out_of_range) &)
            {
                // Should not get here
                r->report("Search for existing erroneously failed", __LINE__);
                bSuccess = false;
            }

            STLSOFT_SUPPRESS_UNUSED(m2);

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_container_access(test_stlsoft_container_access);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_CONTAINER_ACCESS */

/* ////////////////////////////////////////////////////////////////////// */
