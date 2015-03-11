/* /////////////////////////////////////////////////////////////////////////////
 * File:        dbstl/sqlite/exceptions.hpp
 *
 * Purpose:     Exception class used by the DbSTL SQLite mapping
 *
 * Created:     4th December 2004
 * Updated:     26th December 2005
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


#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_EXCEPTIONS
#define DBSTL_INCL_DBSTL_SQLITE_HPP_EXCEPTIONS

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_VER_DBSTL_SQLITE_HPP_EXCEPTIONS_MAJOR    0
# define DBSTL_VER_DBSTL_SQLITE_HPP_EXCEPTIONS_MINOR    10
# define DBSTL_VER_DBSTL_SQLITE_HPP_EXCEPTIONS_REVISION 1
# define DBSTL_VER_DBSTL_SQLITE_HPP_EXCEPTIONS_EDIT     5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_
# include <dbstl/sqlite/sqlite_.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_ */
#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_HANDLE
# include <dbstl/sqlite/handle.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_HANDLE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
# include <stlsoft/util/exception_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

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

/// Exception thrown by the DbSTL SQLite library
class sqlite_exception
    : public ::std::exception
{
private:
    typedef stlsoft_ns_qual(exception_string)	string_type;
    typedef sqlite_exception					class_type;

public:
    sqlite_exception(sqlite3 *db)
        : m_message(sqlite3_errmsg(db))
        , m_res(sqlite3_errcode(db))
    {}
    sqlite_exception(int res, char const *message)
        : m_message(message)
        , m_res(res)
    {}

public:
    virtual char const *what() const throw()
    {
        return m_message.empty() ? "SQLite exception" : m_message.c_str();
    }

    int errcode() const throw()
    {
        return m_res;
    }

private:
    string_type m_message;
    const int   m_res;

private:
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace sqlite

} // namespace dbstl_project

} // namespace stlsoft

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_EXCEPTIONS */

/* ////////////////////////////////////////////////////////////////////////// */
