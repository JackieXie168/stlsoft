/* /////////////////////////////////////////////////////////////////////////////
 * File:        dbstl/sqlite/database.hpp
 *
 * Purpose:     database class
 *
 * Created:     4th December 2004
 * Updated:     27th July 2005
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


#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_DATABASE
#define DBSTL_INCL_DBSTL_SQLITE_HPP_DATABASE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_VER_DBSTL_SQLITE_HPP_DATABASE_MAJOR      0
# define DBSTL_VER_DBSTL_SQLITE_HPP_DATABASE_MINOR      9
# define DBSTL_VER_DBSTL_SQLITE_HPP_DATABASE_REVISION   1
# define DBSTL_VER_DBSTL_SQLITE_HPP_DATABASE_EDIT       4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_
# include <dbstl/sqlite/sqlite_.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_ */
#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_EXCEPTIONS
# include <dbstl/sqlite/exceptions.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_EXCEPTIONS */

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

/// Represents a SQLite 3 database
class database
{
/// \name Members
/// @{
public:
    typedef sqlite3     *handle_type;
    typedef database    class_type;
/// @}

/// \name Construction
/// @{
protected:
    database(HDatabase_t::ref db);
public:
    /// Default constructor
    database();
    /// Creates a database instance on the given database
    ///
    /// \note Throws an instance of sqlite_exception if the database cannot be
    //// opened/created, or is not a valid SQLite database
    ss_explicit_k database(char const *databasePath)
        : m_handle(open_database_(databasePath))
    {}
    template <ss_typename_param_k S>
    ss_explicit_k database(S const &databasePath)
        : m_handle(open_database_(::stlsoft::c_str_ptr(databasePath)))
    {}
    /// Copy constructor
    explicit database(class_type const &rhs);

    /// Closes the database
    void close();
/// @}

/// \name Operations
/// @{
public:
    void    exec(char const *sql);
    template <ss_typename_param_k S>
    void    exec(S const &sql)
    {
        this->exec(::stlsoft::c_str_ptr(sql));
    }

    void    exec(char const *sql, sqlite3_callback fn, void *arg);
    template <ss_typename_param_k S>
    void    exec(S const &sql, sqlite3_callback fn, void *arg)
    {
        this->exec(::stlsoft::c_str_ptr(sql), fn, arg);
    }
/// @}

/// \name Attributes
/// @{
public:
    ss_bool_t       is_open() const;
    handle_type     get_handle() const;
/// @}

/// \name Implementation
/// @{
private:
    static HDatabase_t::ref open_database_(char const *databasePath);
/// @}

/// \name Members
/// @{
private:
    HDatabase_t::ref    m_handle;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline database::handle_type get_handle(database const &db)
{
    return db.get_handle();
}

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

// Implementation

inline /* static */ HDatabase_t::ref database::open_database_(char const *databasePath)
{
    sqlite3 *db;
    int     res = sqlite3_open(databasePath, &db);

    if(SQLITE_OK != res)
    {
#if 0
        throw sqlite_exception(res, "Could not open database");
#else /* ? 0 */
        throw sqlite_exception(db);
#endif /* 0 */
    }

    try
    {
        return HDatabase_t::ref(new HDatabase_t(db, true));
    }
    catch(std::exception &)
    {
        HDatabase_t::destroy(db);

        throw;
    }
}

// Construction

inline database::database()
    : m_handle(NULL)
{}

inline database::database(class_type const &rhs)
    : m_handle(rhs.m_handle)
{}

inline void database::close()
{
    m_handle = HDatabase_t::ref(NULL);
}

// Operations

inline void database::exec(char const *sql)
{
    this->exec(sql, NULL, NULL);
}

inline void database::exec(char const *sql, sqlite3_callback fn, void *arg)
{
    char    *errmsg;
    int     res =   ::sqlite3_exec(m_handle->h, sql, fn, arg, &errmsg);

    if(SQLITE_OK != res)
    {
#if 0
        throw sqlite_exception(res, "Could not open database");
#else /* ? 0 */
        throw sqlite_exception(m_handle->h);
#endif /* 0 */
    }
}

// Attributes

inline ss_bool_t database::is_open() const
{
    return NULL != m_handle->h;
}

inline database::handle_type database::get_handle() const
{
    return m_handle->h;
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace sqlite

} // namespace dbstl_project

} // namespace stlsoft

// Push the shim(s) into the Shim namespace: stlsoft
namespace stlsoft
{

    using ::dbstl::sqlite::get_handle;

} // namespace stlsoft

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_DATABASE */

/* ////////////////////////////////////////////////////////////////////////// */
