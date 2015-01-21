/* /////////////////////////////////////////////////////////////////////////////
 * File:        dbstl/sqlite/sqlite_.hpp
 *
 * Purpose:     Declaration of namespace
 *
 * Created:     4th December 2004
 * Updated:     17th July 2005
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


#ifndef DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_
#define DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_VER_DBSTL_SQLITE_HPP_SQLITE__MAJOR      0
# define DBSTL_VER_DBSTL_SQLITE_HPP_SQLITE__MINOR      9
# define DBSTL_VER_DBSTL_SQLITE_HPP_SQLITE__REVISION   1
# define DBSTL_VER_DBSTL_SQLITE_HPP_SQLITE__EDIT       3
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file dbstl/sqlite/sqlite_.hpp The root header for the \ref DbSTL project */

/** \weakgroup projects STLSoft Projects
 *
 * \brief The Projects that comprise the STLSoft libraries
 */

/** \defgroup DbSTL DbSTL
 * \ingroup projects
 *
 * \brief <img src = "dbstl32x32.jpg">&nbsp;&nbsp;&nbsp;&nbsp;<i>Template Software for SQLite</i>
 *
 * The philosophy of DbSTL (http://dbstl.org/) is essentially the same as that
 * of the STLSoft (http://stlsoft.org/) organisation: providing robust and
 * lightweight software to the UNIX development
 * community. DbSTL provides template-based software that builds on that
 * provided by UNIX and STLSoft in order to reduce programmer effort and increase
 * robustness in the use of the UNIX.
 *
 * <b>Namespaces</b>
 *
 * The DbSTL namespace <code><b>dbstl</b></code> is actually an alias for the
 * namespace <code><b>stlsoft::dbstl_project</b></code>, and as such all the
 * DbSTL project components actually reside within the
 * <code><b>stlsoft</b></code> namespace. However, there is never any need to
 * use the <code><b>stlsoft::dbstl_project</b></code> namespace in your code,
 * and you should always use the alias <code><b>dbstl</b></code>.
 *
 * <b>Dependencies</b>
 *
 * As with <b><i>all</i></b> parts of the STLSoft libraries, there are no
 * dependencies on DbSTL binary components and no need to compile DbSTL
 * implementation files; DbSTL is <b>100%</b> header-only!
 *
 * As with most of the STLSoft sub-projects, DbSTL depends only on:
 *
 * - Selected headers from the C standard library, such as  <code><b>wchar.h</b></code>
 * - Selected headers from the C++ standard library, such as <code><b>new</b></code>, <code><b>functional</b></code>
 * - Selected header files of the STLSoft main project
 * - The header files particular to the technology area, in this case the UNIX library headers, such as <code><b>dirent.h</b></code>
 * - The binary (static and dynamic libraries) components particular to the technology area, in this case the UNIX libraries that ship with the operating system and your compiler(s)
 */

/* /////////////////////////////////////////////////////////////////////////////
 * DbSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the DBSTL_SQLITE_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the DBSTL_SQLITE_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the DBSTL_SQLITE_VER_REVISIO preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - DBSTL_SQLITE_VER_MAJOR,
 * DBSTL_SQLITE_VER_MINOR and DBSTL_SQLITE_VER_REVISION - a composite symbol DBSTL_SQLITE_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies DBSTL_SQLITE_VER_1_0_1.
 *
 * Thus the symbol DBSTL_SQLITE_VER may be compared meaningfully with a specific
 * version symbol, e.g.# if DBSTL_SQLITE_VER >= DBSTL_SQLITE_VER_1_0_1
 */

/// \def DBSTL_SQLITE_VER_MAJOR
/// The major version number of DbSTL

/// \def DBSTL_SQLITE_VER_MINOR
/// The minor version number of DbSTL

/// \def DBSTL_SQLITE_VER_REVISION
/// The revision version number of DbSTL

/// \def DBSTL_SQLITE_VER
/// The current composite version number of DbSTL

#define DBSTL_SQLITE_VER_MAJOR      0
#define DBSTL_SQLITE_VER_MINOR      9
#define DBSTL_SQLITE_VER_REVISION   1
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define DBSTL_SQLITE_VER_0_9_1     0x00000901  /*!< Version 0.9.1 */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define DBSTL_SQLITE_VER            DBSTL_SQLITE_VER_0_9_1

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <sqlite3.h>

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



/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace sqlite

} // namespace dbstl_project

} // namespace stlsoft

namespace dbstl = ::stlsoft::dbstl_project;

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !DBSTL_INCL_DBSTL_SQLITE_HPP_SQLITE_ */

/* ////////////////////////////////////////////////////////////////////////// */
