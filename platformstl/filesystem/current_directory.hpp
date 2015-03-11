/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/current_directory.hpp
 *
 * Purpose:     Platform header for the current_directory components.
 *
 * Created:     13th June 2005
 * Updated:     20th June 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/current_directory.hpp
 *
 * \brief [C++ only] Definition of the platformstl::basic_current_directory
 *  type.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MAJOR     2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MINOR     0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_REVISION  1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_EDIT      10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY
#  include <unixstl/filesystem/current_directory.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */
#elif defined(PLATFORMSTL_OS_IS_WIN32)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY
#  include <winstl/filesystem/current_directory.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{

namespace platformstl_project
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

    /** \brief A facade for the platform's basic_current_directory functionality.
     *
     * \ingroup group__library__file_system
     *
     * The class is not actually defined in the
     * \link ::platformstl platformstl\endlink namespace. Rather, it
     * resolves to the appropriate type for the given platform, relying on
     * \ref group__principle__intersecting_structural_conformance "Intersecting Structural Conformance"
     * of the resolved platform-specific types.
     *
     * When compiling on UNIX platforms, the platformstl::basic_current_directory
     * type resolves to the unixstl::basic_current_directory class. On Windows
     * platforms it resolves to the winstl::basic_current_directory class. It
     * is not defined for other platforms.
     */
    template<   ss_typename_param_k C
            ,   ss_typename_param_k T = unixstl_ns_qual(filesystem_traits)<C>
            >
    class basic_current_directory
    {};

#elif defined(PLATFORMSTL_OS_IS_UNIX)

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = unixstl_ns_qual(filesystem_traits)<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = winstl::filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_current_directory
        : public unixstl_ns_qual(basic_current_directory__)<C, T>
    {
    private:
        typedef unixstl_ns_qual(basic_current_directory__)<C, T>        parent_class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef basic_current_directory<C, T>                           class_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        basic_current_directory()
            : parent_class_type()
        {}

    // Not to be implemented
    private:
        basic_current_directory(class_type const &);
        class_type &operator =(class_type const &);
    };

    typedef basic_current_directory<char>       current_directory_a;
    typedef basic_current_directory<wchar_t>    current_directory_w;
    typedef basic_current_directory<char>       current_directory;

# else /* ? compiler */

#  ifdef _UNIXSTL_NO_NAMESPACE
    using ::basic_current_directory;
    using ::current_directory_a;
#  else /* ? _UNIXSTL_NO_NAMESPACE */
    using ::unixstl::basic_current_directory;
    using ::unixstl::current_directory_a;
#  endif /* _UNIXSTL_NO_NAMESPACE */

# endif /* compiler */

#elif defined(PLATFORMSTL_OS_IS_WIN32)

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = winstl_ns_qual(filesystem_traits)<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = winstl::filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_current_directory
        : public winstl_ns_qual(basic_current_directory__)<C, T>
    {
    private:
        typedef winstl_ns_qual(basic_current_directory__)<C, T>         parent_class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef basic_current_directory<C, T>                           class_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        basic_current_directory()
            : parent_class_type()
        {}

    // Not to be implemented
    private:
        basic_current_directory(class_type const &);
        class_type &operator =(class_type const &);
    };

    typedef basic_current_directory<char>       current_directory_a;
    typedef basic_current_directory<wchar_t>    current_directory_w;
    typedef basic_current_directory<TCHAR>      current_directory;

# else /* ? compiler */

#  ifdef _WINSTL_NO_NAMESPACE
    using ::basic_current_directory;
    using ::current_directory_a;
    using ::current_directory_w;
    using ::current_directory;
#  else /* ? _WINSTL_NO_NAMESPACE */
    using ::winstl::basic_current_directory;
    using ::winstl::current_directory_a;
    using ::winstl::current_directory_w;
    using ::winstl::current_directory;
#  endif /* _WINSTL_NO_NAMESPACE */

# endif /* compiler */

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */

/* ////////////////////////////////////////////////////////////////////// */
