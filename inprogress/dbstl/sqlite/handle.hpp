/* /////////////////////////////////////////////////////////////////////////////
 * File:        dbstl/sqlite/handle.hpp
 *
 * Purpose:     Exception class used by the DbSTL SQLite mapping
 *
 * Created:     4th December 2004
 * Updated:     13th December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2005, Matthew Wilson and Synesis Software
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


#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_HANDLE
#define DBSTL_INCL_DBSTL_SQLITE_HPP_HANDLE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_VER_DBSTL_SQLITE_HPP_HANDLE_MAJOR      0
# define DBSTL_VER_DBSTL_SQLITE_HPP_HANDLE_MINOR      9
# define DBSTL_VER_DBSTL_SQLITE_HPP_HANDLE_REVISION   5
# define DBSTL_VER_DBSTL_SQLITE_HPP_HANDLE_EDIT       6
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_
# include <dbstl/sqlite/sqlite_.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_ */

#include <exception>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

namespace dbstl_project
{

namespace sqlite
{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<   ss_typename_param_k H
        ,   int                 (*F)(H )
        >
struct handle
{
public:
    typedef H                       handle_type;
    typedef stlsoft::ss_sint32_t    rc_t;
    typedef handle<H, F>            class_type;

public:
    class ref
    {
    private:
        typedef handle<H, F>        handle_type;
    public:
        ref(handle *ph)
            : m_ph(ph)
        {}
        ~ref() stlsoft_throw_0()
        {
            if(NULL != m_ph)
            {
                m_ph->Release();
            }
        }
        ref(ref const &rhs)
            : m_ph(rhs.m_ph)
        {
            if(NULL != m_ph)
            {
                m_ph->AddRef();
            }
        }
        ref &operator =(ref const &rhs)
        {
            if(NULL != m_ph)
            {
                m_ph->Release();
            }

            m_ph = rhs.m_ph;

            if(NULL != m_ph)
            {
                m_ph->AddRef();
            }

            return *this;
        }

        handle_type *operator ->()
        {
            DBSTL_MESSAGE_ASSERT("instance does not have a non-NULL handle", NULL != m_ph);

            return m_ph;
        }
        handle_type const *operator ->() const
        {
            DBSTL_MESSAGE_ASSERT("instance does not have a non-NULL handle", NULL != m_ph);

            return m_ph;
        }

    private:
        handle_type *m_ph;
    };

public:
    /// The ref-counting policy
    ///
    /// \note Although it is possible, depending on build settings, to use SQLite in a multi-threaded
    /// context, it is never possible to use the same SQLite handle from different threads. Hence, the
    /// refcount_policy for this handle::ref type is always single threaded.
    struct refcount_policy
    {
    public:
        static void addref(rc_t &cRefs)
        {
            ++cRefs;
        }
        static rc_t release(rc_t &cRefs)
        {
            return --cRefs;
        }
    };
public:

    handle(handle_type h_, bool bOwn_)
        : h(h_)
        , bOwn(bOwn_)
        , cRefs(1)
    {}

    handle *AddRef()
    {
        refcount_policy::addref(cRefs);

        return this;
    }

    void Release()
    {
        if(0 == refcount_policy::release(cRefs))
        {
            if(bOwn)
            {
                F(h);
            }

            delete this;
        }
    }

public:
    static void destroy(handle_type h)
    {
        F(h);
    }

/// \name Members
public:
    handle_type h;
private:
    const bool  bOwn;
    rc_t        cRefs;

private:
    class_type &operator =(class_type const &);
};

template<typename H>
inline int destroy_stub(H *)
{
    return 0;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Instantiations
 */

typedef handle<sqlite3*,            sqlite3_close>                      HDatabase_t;
typedef handle<sqlite3_stmt*,       sqlite3_finalize>                   HStatement_t;
typedef handle<sqlite3_context*,    destroy_stub<sqlite3_context> >     HMsgEnum_t;
typedef handle<sqlite3_value*,      destroy_stub<sqlite3_value> >       HValue_t;

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace sqlite

} // namespace dbstl_project

} // namespace stlsoft

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_HANDLE */

/* ////////////////////////////////////////////////////////////////////////// */
