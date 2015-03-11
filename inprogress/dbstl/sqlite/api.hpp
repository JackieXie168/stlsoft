/* /////////////////////////////////////////////////////////////////////////////
 * File:        dbstl/sqlite/api.hpp
 *
 * Purpose:     SQLite API functions: defaulted/contracted and  generalised for
 *              string access
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


#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_API
#define DBSTL_INCL_DBSTL_SQLITE_HPP_API

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_VER_DBSTL_SQLITE_HPP_API_MAJOR      0
# define DBSTL_VER_DBSTL_SQLITE_HPP_API_MINOR      9
# define DBSTL_VER_DBSTL_SQLITE_HPP_API_REVISION   4
# define DBSTL_VER_DBSTL_SQLITE_HPP_API_EDIT       7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_
# include <dbstl/sqlite/sqlite_.hpp>
#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_ */

#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */

#include <stdarg.h>

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
 * Functions
 */

template <ss_typename_param_k S>
inline int sqlite3_exec(sqlite3 *db, S const &sql, sqlite3_callback fn, void *arg, char **errmsg)
{
    return ::sqlite3_exec(db, ::stlsoft::c_str_ptr(sql), fn, arg, errmsg);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C
        >
struct exec_instance_adaptor
{
public:
    static int callback(void *this_, int argc, char **argv, char **s)
    {
        return static_cast<C*>(this_)->OnExec(argc, argv, s);
    }
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline int sqlite3_exec(sqlite3 *db, S const &sql, C *client, char **errmsg)
{
    typedef exec_instance_adaptor<C>    adaptor_t;

    return ::sqlite3_exec(db, ::stlsoft::c_str_ptr(sql), &adaptor_t::callback, client, errmsg);
}

template<ss_typename_param_k S>
inline int sqlite3_exec(sqlite3 *db, S const &sql, char **errmsg)
{
    return ::sqlite3_exec(db, ::stlsoft::c_str_ptr(sql), NULL, NULL, errmsg);
}

template <ss_typename_param_k S>
inline int sqlite3_complete(S const &sql)
{
    return ::sqlite3_complete(::stlsoft::c_str_ptr(sql));
}

template <ss_typename_param_k S>
inline int sqlite3_get_table(sqlite3 *db, S const &sql, char ***resultp, int *nrow, int *ncolumn, char **errmsg)
{
    return ::sqlite3_get_table(db, ::stlsoft::c_str_ptr(sql), resultp, nrow, ncolumn, errmsg);
}

#if 0
template <ss_typename_param_k S>
inline char *sqlite3_mprintf(S const &fmt, ...)
char *sqlite3_mprintf(const char*,...);

template <ss_typename_param_k S>
inline char *sqlite3_vmprintf(const char*, va_list);
char *sqlite3_vmprintf(const char*, va_list);

template <ss_typename_param_k S>
inline char *sqlite3_snprintf(int,char*,const char*, ...);
char *sqlite3_snprintf(int,char*,const char*, ...);
#endif /* 0 */

template <ss_typename_param_k S>
inline int sqlite3_open(S const &filename, sqlite3 **ppDb)
{
    return ::sqlite3_open(::stlsoft::c_str_ptr(filename), ppDb);
}

template <ss_typename_param_k S>
inline int sqlite3_prepare(sqlite3 *db, S const &sql, sqlite3_stmt **ppStmt, const char **pzTail)
{
    return ::sqlite3_prepare(db, ::stlsoft::c_str_data(sql), ::stlsoft::c_str_len(sql), ppStmt, pzTail);
}

template <ss_typename_param_k S>
inline int sqlite3_bind_text(sqlite3_stmt *stmt, int index, S const &s, void (*dtor)(void*))
{
    return ::sqlite3_bind_text(stmt, index, ::stlsoft::c_str_data(s), ::stlsoft::c_str_len(s), dtor);
}

template <ss_typename_param_k S>
inline int sqlite3_bind_parameter_index(sqlite3_stmt *stmt, S const &name)
{
    return ::sqlite3_bind_parameter_index(stmt, ::stlsoft::c_str_ptr(name));
}

template <ss_typename_param_k S>
inline int sqlite3_create_function( sqlite3     *db
                                ,   S const     &functionName
                                ,   int         nArg
                                ,   int         eTextRep
                                ,   void        *p
                                ,   void        (*xFunc)(sqlite3_context*,int,sqlite3_value**)
                                ,   void        (*xStep)(sqlite3_context*,int,sqlite3_value**)
                                ,   void        (*xFinal)(sqlite3_context*))
{
    return ::sqlite3_create_function(db, ::stlsoft::c_str_ptr(functionName), nArg, eTextRep, p, xFunc, xStep, xFinal);
}

template <ss_typename_param_k S>
inline void sqlite3_result_error(sqlite3_context *ctxt, S const &error)
{
    ::sqlite3_result_error(ctxt, ::stlsoft::c_str_data(error), ::stlsoft::c_str_len(error));
}

template <ss_typename_param_k S>
inline void sqlite3_result_text(sqlite3_context *ctxt, S const &text, void(*dtor)(void*))
{
    ::sqlite3_result_text(ctxt, ::stlsoft::c_str_data(text), ::stlsoft::c_str_len(text), dtor);
}

template <ss_typename_param_k S>
inline int sqlite3_create_collation(sqlite3 *db, S const &name, int eTextRep, void *p, int (*xCompare)(void*,int,const void*,int,const void*))
{
    return ::sqlite3_create_collation(db, ::stlsoft::c_str_ptr(name), eTextRep, p, xCompare);
}

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace sqlite

} // namespace dbstl_project

} // namespace stlsoft

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_API */

/* ////////////////////////////////////////////////////////////////////////// */
