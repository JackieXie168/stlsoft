/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/file_lines.hpp
 *
 * Purpose:     Platform header for the file_lines components.
 *
 * Created:     25th October 2007
 * Updated:     29th December 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2007, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_MAJOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_MINOR    3
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_REVISION 1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_EDIT     10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file platformstl/filesystem/memory_mapped_file.hpp
 *
 * \brief [C++ only] Definition of the platformstl::file_lines type
 *   (\ref group__library__filesystem "File System" Library).
 *
 * When compiling on UNIX platforms, the platformstl::file_lines
 * type resolves to the unixstl::file_lines class. On Windows
 * platforms it resolves to the winstl::file_lines class. It is
 * not defined for other platforms.
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE
# include <platformstl/filesystem/memory_mapped_file.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST
# include <stlsoft/conversion/truncation_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TOKENISER
# include <stlsoft/string/string_tokeniser.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TOKENISER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
# include <stlsoft/string/string_view.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
# include <stlsoft/string/simple_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */

#include <algorithm>
#include <vector>

#ifdef STLSOFT_UNITTEST
# include <platformstl/filesystem/file_path_buffer.hpp>
#endif /* STLSOFT_UNITTEST */

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

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<   typename C
        ,   typename V = stlsoft::basic_string_view<C>
        ,   typename B = stlsoft::basic_simple_string<C>
        >
class basic_file_lines
{
/// \name Member Types
/// @{
public:
    typedef basic_file_lines<C, V, B>                           class_type;
    typedef C                                                   char_type;
private:
    typedef B                                                   base_string_type_;
    typedef std::vector<V>                                      strings_type_;
public:
    typedef ss_typename_type_k strings_type_::value_type        value_type;
    typedef ss_typename_type_k strings_type_::size_type         size_type;
    typedef ss_typename_type_k strings_type_::const_iterator    const_iterator;
    typedef ss_typename_type_k strings_type_::const_reference   const_reference;
    typedef ss_bool_t                                           bool_type;
/// @}

/// \name Construction
/// @{
public:
    template <typename S>
    basic_file_lines(S const& path)
        : m_mmf(new memory_mapped_file(stlsoft_ns_qual(c_str_ptr)(path)))
        , m_contents()
        , m_strings()
    {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        STLSOFT_ASSERT(NULL != m_mmf);
#else /* ? STLSOFT_CF_THROW_BAD_ALLOC */
        if(NULL != m_mmf)
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
        {
            memory_mapped_file& mmf = *m_mmf;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            m_strings.reserve(stlsoft_ns_qual(truncation_cast)<size_type>(mmf.size() / 40));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            m_strings.reserve(static_cast<size_type>(mmf.size() / 40));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#if defined(PLATFORMSTL_OS_IS_UNIX)

            typedef stlsoft::string_tokeniser<  value_type
                                            ,   char
                                            ,   stlsoft::skip_blank_tokens<false>
                                            ,   value_type
                                            >   tokeniser_t;

            static const char_type  sep = '\n';

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

            typedef stlsoft::string_tokeniser<  value_type
                                            ,   value_type
                                            ,   stlsoft::skip_blank_tokens<false>
                                            ,   value_type
                                            >   tokeniser_t;

            static const char_type  sep[] = { '\r', '\n', '\0' };

#else /* ? OS */
# error Platform not discriminated
#endif /* OS */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            m_contents.assign(static_cast<C const*>(mmf.memory()), stlsoft_ns_qual(truncation_cast)<size_type>(mmf.size()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            m_contents.assign(static_cast<C const*>(mmf.memory()), static_cast<size_type>(mmf.size()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

            tokeniser_t     lines(m_contents.data(), m_contents.size(), sep);

            std::copy(lines.begin(), lines.end(), std::back_inserter(m_strings));

            // Now determine whether we can discard the underlying mapping. This
            // is ok if:
            //  - there are no lines, or
            //  - the string type copies. This is determined by checking whether
            //    the first string's contents point to the base of the mapping.
            if( m_strings.empty() ||
                m_strings.front().data() != static_cast<C const*>(mmf.memory()))
            {
                delete m_mmf;
                m_mmf = NULL;
            }
        }
    }

    ~basic_file_lines() stlsoft_throw_0()
    {
        delete m_mmf;
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Returns the number of lines in the file
    size_type size() const
    {
        return m_strings.size();
    }

    /// Returns a non-mutable (const) reference to the line at \c index
    ///
    /// \note The behaviour is undefined if index >= size()
    const_reference operator [](size_type index) const
    {
        STLSOFT_MESSAGE_ASSERT("index out of range", index < size());

        return m_strings[index];
    }

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator begin() const
    {
        return m_strings.begin();
    }

    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator end() const
    {
        return m_strings.end();
    }
/// @}

/// \name Comparison
/// @{
public:
#if !defined(STLSOFT_COMPILER_IS_DMC)
    template<   ss_typename_param_k V2
            ,   ss_typename_param_k B2
            >
    bool_type equal(basic_file_lines<char_type, V2, B2> const& rhs) const
#else /* ? compiler */
    bool_type equal(class_type const& rhs) const
#endif /* compiler */
    {
        if(size() != rhs.size())
        {
            return false;
        }

        return stlsoft_ns_qual_std(equal)(begin(), end(), rhs.begin());
    }

/// @}

/// \name Member Variables
/// @{
private:
    memory_mapped_file* m_mmf;
    base_string_type_   m_contents;
    strings_type_       m_strings;
/// @}

/// \name Not to be implemented
/// @{
private:
    basic_file_lines(class_type const& );
    class_type& operator =(class_type const& );
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/** \brief Specialisation of the basic_file_lines template for the ANSI character type \c char
 *
 * \ingroup group__library__filesystem
 */
typedef basic_file_lines<ss_char_a_t>       file_lines_a;

/** \brief Specialisation of the basic_file_lines template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__filesystem
 */
typedef basic_file_lines<ss_char_w_t>       file_lines_w;

#ifdef TCHAR
/** \brief Specialisation of the basic_file_lines template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__filesystem
 */
typedef basic_file_lines<TCHAR>             file_lines;
#else /* ? TCHAR */
typedef file_lines_a                        file_lines;
#endif /* TCHAR */

/** \brief Alias for platformstl::file_lines_w;
 *
 * \ingroup group__library__filesystem
 */
typedef file_lines_w                        wfile_lines;

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

#if !defined(STLSOFT_COMPILER_IS_DMC)
template<   ss_typename_param_k C
        ,   ss_typename_param_k V1
        ,   ss_typename_param_k B1
        ,   ss_typename_param_k V2
        ,   ss_typename_param_k B2
        >
inline ss_typename_type_ret_k basic_file_lines<C, V1, B1>::bool_type operator ==(basic_file_lines<C, V1, B1> const& lhs, basic_file_lines<C, V2, B2> const& rhs)
#else /* ? compiler */
template<   ss_typename_param_k C
        ,   ss_typename_param_k V
        ,   ss_typename_param_k B
        >
inline ss_typename_type_ret_k basic_file_lines<C, V, B>::bool_type operator ==(basic_file_lines<C, V, B> const& lhs, basic_file_lines<C, V, B> const& rhs)
#endif /* compiler */
{
    return lhs.equal(rhs);
}

#if !defined(STLSOFT_COMPILER_IS_DMC)
template<   ss_typename_param_k C
        ,   ss_typename_param_k V1
        ,   ss_typename_param_k B1
        ,   ss_typename_param_k V2
        ,   ss_typename_param_k B2
        >
inline ss_typename_type_ret_k basic_file_lines<C, V1, B1>::bool_type operator !=(basic_file_lines<C, V1, B1> const& lhs, basic_file_lines<C, V2, B2> const& rhs)
#else /* ? compiler */
template<   ss_typename_param_k C
        ,   ss_typename_param_k V
        ,   ss_typename_param_k B
        >
inline ss_typename_type_ret_k basic_file_lines<C, V, B>::bool_type operator !=(basic_file_lines<C, V, B> const& lhs, basic_file_lines<C, V, B> const& rhs)
#endif /* compiler */
{
    return !lhs.equal(rhs);
}

/* ////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/file_lines_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES */

/* ////////////////////////////////////////////////////////////////////// */
