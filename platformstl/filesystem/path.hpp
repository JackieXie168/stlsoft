/* /////////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/path.hpp
 *
 * Purpose:     Platform header for the path components.
 *
 * Created:     20th March 2005
 * Updated:     4th June 2006
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
 * ////////////////////////////////////////////////////////////////////////// */


/** \file platformstl/filesystem/path.hpp
 *
 * \brief [C++ only] Definition of the platformstl::basic_path
 *  type.
 *  (\ref group__library__file_system "File System" Library.)
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_MAJOR      2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_MINOR      0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_REVISION   1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_EDIT       13
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PLATFORMSTL */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH
#  include <unixstl/filesystem/path.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH */
#elif defined(PLATFORMSTL_OS_IS_WIN32)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
#  include <winstl/filesystem/path.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////////
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

/* ////////////////////////////////////////////////////////////////////////// */

#if defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef _UNIXSTL_NO_NAMESPACE
    using ::basic_path;
# else /* ? _UNIXSTL_NO_NAMESPACE */
    using ::unixstl::basic_path;
    using ::unixstl::path;
# endif /* _UNIXSTL_NO_NAMESPACE */

#elif defined(PLATFORMSTL_OS_IS_WIN32)

    // Because early incarnations of Visual C++ are pretty stupid, we need to
    // work around their inability to introduce a template via using by
    // defining and deriving here
    //
    // This one required an *extra* degree of trickery, by defining a derivation
    // of winstl::basic_path _within_ winstl, in the form of
    // basic_path__, and then deriving from that. If we just try and
    // derive from winstl::basic_path directly, the compiler gets
    // confused between the winstl one and the local one, and fails and says that
    // it cannot derive from itself (which happens to be incomplete).

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template<   ss_typename_param_k C
#  ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = winstl_ns_qual(filesystem_traits)<C>
            ,   ss_typename_param_k A = winstl_ns_qual(processheap_allocator)<C>
#  else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = filesystem_traits<C> */
            ,   ss_typename_param_k A /* = processheap_allocator<C> */
#  endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_path
        : public winstl_ns_qual(basic_path__)<C, T, A>
    {
    private:
        typedef winstl_ns_qual(basic_path__)<C, T, A>                   parent_class_type;
        typedef basic_path<C, T, A>                                     class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        ss_explicit_k basic_path(char_type const *path)
            : parent_class_type(path)
        {}
        basic_path(parent_class_type const &s)
            : parent_class_type(s)
        {}
#  ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        /// Constructs a path from \c path
        template<ss_typename_param_k S>
        basic_path(S const &s)
            : parent_class_type(s)
        {}
#  endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
        basic_path(char_type const *path, size_type cch)
            : parent_class_type(path, cch)
        {}
        basic_path(class_type const &rhs)
            : parent_class_type(rhs)
        {}

        class_type &operator =(class_type const &rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type &operator =(parent_class_type const &rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type &operator =(char_type const *rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
#  ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        template<ss_typename_param_k S>
        class_type &operator =(S const &s)
        {
            parent_class_type::operator =(s);

            return *this;
        }
#  endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    };

    typedef basic_path<TCHAR>   path;

# else /* ? compiler */

#  ifdef _WINSTL_NO_NAMESPACE
     using ::basic_path;
#  else /* ? _WINSTL_NO_NAMESPACE */
     using ::winstl::basic_path;
     using ::winstl::path;
#  endif /* _WINSTL_NO_NAMESPACE */

# endif /* compiler */

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* ////////////////////////////////////////////////////////////////////////// */

#if defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH */

/* ////////////////////////////////////////////////////////////////////////// */