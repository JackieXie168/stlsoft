/* /////////////////////////////////////////////////////////////////////////////
 * File:        inetstl/findfile_sequence.hpp  (formerly MInetEnm.h)
 *
 * Purpose:     Contains the basic_findfile_sequence template class, and ANSI
 *              and Unicode specialisations thereof.
 *
 * Created:     30th April 1999
 * Updated:     22nd December 2005
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1999-2005, Matthew Wilson and Synesis Software
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


/// \file inetstl/findfile_sequence.hpp
///
/// Contains the basic_findfile_sequence template class, and ANSI and Unicode specialisations thereof.

#ifndef INETSTL_INCL_INETSTL_HPP_FINDFILE_SEQUENCE
#define INETSTL_INCL_INETSTL_HPP_FINDFILE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_HPP_FINDFILE_SEQUENCE_MAJOR    2
# define INETSTL_VER_INETSTL_HPP_FINDFILE_SEQUENCE_MINOR    5
# define INETSTL_VER_INETSTL_HPP_FINDFILE_SEQUENCE_REVISION 1
# define INETSTL_VER_INETSTL_HPP_FINDFILE_SEQUENCE_EDIT     85
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifndef INETSTL_INCL_INETSTL_HPP_FILESYSTEM_TRAITS
# include <inetstl/filesystem_traits.hpp>
#endif /* !INETSTL_INCL_INETSTL_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS
# include <stlsoft/string_access.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_ACCESS */
#ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
# include <stlsoft/simple_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_TOKENISER_FUNCTIONS
# include <stlsoft/tokeniser_functions.hpp> // for find_next_token
#endif /* !STLSOFT_INCL_STLSOFT_TOKENISER_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _INETSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */

namespace stlsoft
{

namespace inetstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_INETSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_filesystem File-System Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating file-system objects

/// \weakgroup inetstl_filesystem_library File-System Library (InetSTL)
/// \ingroup InetSTL libraries_filesystem
/// \brief This library provides facilities for defining and manipulating file-system objects for the WinInet API
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T>
class basic_findfile_sequence_value_type;

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
class basic_findfile_sequence_const_input_iterator;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class basic_findfile_sequence
/// Presents an STL-like sequence interface over the items on the file-system
///
/// \param C The character type
/// \param T The traits type. On translators that support default template arguments this defaults to filesystem_traits<C>
///
/// \note  This class was described in detail in the article
/// "Adapting Windows Enumeration Models to STL Iterator Concepts"
/// (http://www.windevnet.com/documents/win0303a/), in the March 2003 issue of
/// Windows Developer Network (http://windevnet.com).
template<   ss_typename_param_k C
#ifdef __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = filesystem_traits<C>
#else
        ,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* __STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_findfile_sequence
{
public:
    /// The character type
    typedef C                                                                   char_type;
    /// The traits type
    typedef T                                                                   traits_type;
    /// The current parameterisation of the type
    typedef basic_findfile_sequence<C, T>                                       class_type;
    /// The value type
    typedef basic_findfile_sequence_value_type<C, T>                            value_type;
    /// The non-mutating (const) iterator type supporting the Input Iterator concept
    typedef basic_findfile_sequence_const_input_iterator<C, T, value_type>      const_input_iterator;
    /// The non-mutating (const) iterator type
    typedef const_input_iterator                                                const_iterator;
    /// The reference type
    typedef value_type                                                          &reference;
    /// The non-mutable (const) reference type
    typedef value_type const                                                    &const_reference;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type                      find_data_type;
    /// The difference type
    typedef is_ptrdiff_t                                                        difference_type;
    /// The size type
    typedef is_size_t                                                           size_type;
private:
    typedef stlsoft_ns_qual(basic_simple_string)<char_type>                     string_type;

public:
    enum
    {
            includeDots =   0x0008          //!< Causes the search to include the "." and ".." directories, which are elided by default
        ,   directories =   0x0010          //!< Causes the search to include directories
        ,   files       =   0x0020          //!< Causes the search to include files
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        ,   noSort      =   0 /* 0x0100 */  //!<
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    };

// Construction
public:
    /// Commence a search according to the given search pattern and flags
    basic_findfile_sequence(HINTERNET hconn, char_type const *searchSpec, is_int_t flags = directories | files);
    /// Commence a search according to the given search pattern and flags, relative to \c directory
    basic_findfile_sequence(HINTERNET hconn, char_type const *directory, char_type const *searchSpec, is_int_t flags = directories | files);
    /// Commence a search according to the given search pattern and flags, relative to \c directory
    basic_findfile_sequence(HINTERNET hconn, char_type const *directory, char_type const *patterns, char_type delim, is_int_t flags = directories | files);
    /// Destructor
    ~basic_findfile_sequence() stlsoft_throw_0();

// Iteration
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator      begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator      end() const;

// Attributes
public:
    /// Returns the directory of the search
    ///
    /// \note Will be the empty string for instances created with the first constructor
    char_type const     *get_directory() const;

// State
public:
#ifdef STLSOFT_OBSOLETE
    /// Returns the number of items in the sequence
    ///
    /// \note This is a potentially very expensive operation
    /// \deprecated
    size_type           size() const;
#endif /* STLSOFT_OBSOLETE */
    /// Indicates whether the sequence is empty
    is_bool_t           empty() const;
    /// Returns the maximum number of items in the sequence
    static size_type    max_size();

// Members
private:
    friend class basic_findfile_sequence_value_type<C, T>;
    friend class basic_findfile_sequence_const_input_iterator<C, T, value_type>;

    const HINTERNET     m_hconn;
    const string_type   m_rootDir;
    const string_type   m_patterns;
    const char_type     m_delim;
    const is_int_t      m_flags;

// Implementation
private:
    static is_int_t     validate_flags_(is_int_t flags);
    static void         extract_subpath_(HINTERNET hconn, char_type *dest, char_type const *searchSpec);

    static  HINTERNET   find_first_file_(HINTERNET hconn, char_type const *spec, is_int_t flags, find_data_type *findData);

// Not to be implemented
private:
    basic_findfile_sequence(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/// Instantiation of the basic_findfile_sequence template for the ANSI character type \c char
typedef basic_findfile_sequence<is_char_a_t, filesystem_traits<is_char_a_t> >     findfile_sequence_a;
/// Instantiation of the basic_findfile_sequence template for the Unicode character type \c wchar_t
typedef basic_findfile_sequence<is_char_w_t, filesystem_traits<is_char_w_t> >     findfile_sequence_w;
/// Instantiation of the basic_findfile_sequence template for the Win32 character type \c TCHAR
typedef basic_findfile_sequence<TCHAR, filesystem_traits<TCHAR> >                 findfile_sequence;

/* ////////////////////////////////////////////////////////////////////////// */

// class basic_findfile_sequence_value_type
/// Value type for the basic_findfile_sequence
template<   ss_typename_param_k C
        ,   ss_typename_param_k T
        >
class basic_findfile_sequence_value_type
{
public:
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The current parameterisation of the type
    typedef basic_findfile_sequence_value_type<C, T>        class_type;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type  find_data_type;
private:
    typedef stlsoft_ns_qual(basic_simple_string)<char_type> string_type;

/// \name Construction
// @{
public:
    /// Default constructor
    basic_findfile_sequence_value_type();
private:
    basic_findfile_sequence_value_type(find_data_type const &data, char_type const *path)
        : m_data(data)
    {
        if('/' != data.cFileName[0])
        {
            traits_type::str_copy(m_path, path);
            traits_type::ensure_dir_end(m_path);
        }
        else
        {
            m_path[0] = '\0';
        }
        traits_type::str_cat(m_path, data.cFileName);
    }
public:
    /// Destructor
    ~basic_findfile_sequence_value_type() stlsoft_throw_0();

    /// Copy assignment operator
    class_type &operator =(class_type const &rhs);
// @}

/// Accessors
// @{
public:
    /// Returns a non-mutating reference to find-data
    find_data_type const    &get_find_data() const;
    /// Returns a non-mutating reference to find-data
    ///
    /// \deprecated This method may be removed in a future release. get_find_data() should be used instead
    find_data_type const    &GetFindData() const;   // Deprecated

    /// Returns the filename part of the item
    char_type const         *get_filename() const;
    /// Returns the short form of the filename part of the item
    char_type const         *get_short_filename() const;
    /// Returns the full path of the item
    char_type const         *get_path() const;

    /// Implicit conversion to a pointer-to-const of the full path
    operator char_type const * () const;
// @}

// Members
private:
    friend class basic_findfile_sequence_const_input_iterator<C, T, class_type>;

    find_data_type  m_data;
    char_type       m_path[1 + _MAX_PATH];
};

// class basic_findfile_sequence_const_input_iterator
/// Iterator type for the basic_findfile_sequence supporting the Input Iterator concept
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
class basic_findfile_sequence_const_input_iterator
#ifndef STLSOFT_COMPILER_IS_WATCOM
    : public stlsoft_ns_qual(iterator_base)<inetstl_ns_qual_std(input_iterator_tag), V, is_ptrdiff_t, void, V>
#endif /* !STLSOFT_COMPILER_IS_WATCOM */
{
public:
    /// The character type
    typedef C                                                       char_type;
    /// The traits type
    typedef T                                                       traits_type;
    /// The value type
    typedef V                                                       value_type;
    /// The current parameterisation of the type
    typedef basic_findfile_sequence_const_input_iterator<C, T, V>   class_type;
    /// The find-data type
    typedef ss_typename_type_k traits_type::find_data_type          find_data_type;
private:
    typedef basic_findfile_sequence<C, T>                           sequence_type;
    typedef ss_typename_type_k sequence_type::string_type           string_type;

/// \name Utility classes
/// @{
private:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    struct shared_handle
    {
    public:
        typedef shared_handle   class_type;

    // Members
    public:
        HINTERNET   hSrch;
    private:
        ss_sint32_t cRefs;

    // Construction
    public:
        ss_explicit_k shared_handle(HINTERNET h)
            : hSrch(h)
            , cRefs(1)
        {}
# if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
    protected:
# else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
    private:
# endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
        ~shared_handle() stlsoft_throw_0()
        {
            INETSTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == cRefs);

            if(NULL != hSrch)
            {
                traits_type::find_close(hSrch);
            }
        }

    // Operations
    public:
        void AddRef()
        {
            ++cRefs;
        }
        void Release()
        {
            if(0 == --cRefs)
            {
                delete this;
            }
        }

    // Not to be implemented
    private:
        shared_handle(class_type const &);
        class_type &operator =(class_type const &);
    };
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
private:
    basic_findfile_sequence_const_input_iterator(   sequence_type const &l
                                                ,   char_type const     *rootDir
                                                ,   char_type const     *patterns
                                                ,   char_type           delim
                                                ,   is_int_t            flags);
    basic_findfile_sequence_const_input_iterator(   sequence_type const &l);
public:
    /// Default constructor
    basic_findfile_sequence_const_input_iterator();
    /// <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">Move constructor</a>
    basic_findfile_sequence_const_input_iterator(class_type const &rhs);
    /// Destructor
    ~basic_findfile_sequence_const_input_iterator() stlsoft_throw_0();

    // Copy assignment operator
    basic_findfile_sequence_const_input_iterator &operator =(class_type const &rhs);
/// @}

public:
    /// Pre-increment operator
    class_type &operator ++();
    /// Post-increment operator
    class_type operator ++(int);
    /// Dereference to return the value at the current position
    const value_type operator *() const;
    /// Evaluates whether \c this and \c rhs are equivalent
    is_bool_t operator ==(class_type const &rhs) const;
    /// Evaluates whether \c this and \c rhs are not equivalent
    is_bool_t operator !=(class_type const &rhs) const;

// Implementation
private:
    static is_bool_t    find_next_pattern_(char_type const *&p0, char_type const *&p1, char_type delim);
    static HINTERNET    find_first_file_(HINTERNET hconn, char_type const *spec, is_int_t flags, find_data_type *findData);

// Members
private:
    friend class basic_findfile_sequence<C, T>;

    sequence_type const * const                     m_list;
    shared_handle                                   *m_handle;
    ss_typename_type_k traits_type::find_data_type  m_data;
    char_type const *const                          m_rootDir;
    char_type const                                 *m_pattern0;
    char_type const                                 *m_pattern1;
    const char_type                                 m_delim;
    const is_int_t                                  m_flags;
};

///////////////////////////////////////////////////////////////////////////////
// Shims

template <ss_typename_param_k C, ss_typename_param_k T>
inline C const *c_str_ptr_null(basic_findfile_sequence_value_type<C, T> const &v)
{
    return stlsoft_ns_qual(c_str_ptr_null(v.get_path()));
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline C const *c_str_ptr(basic_findfile_sequence_value_type<C, T> const &v)
{
    return v.get_path();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline C const *c_str_data(basic_findfile_sequence_value_type<C, T> const &v)
{
    return v.get_path();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_size_t c_str_len(basic_findfile_sequence_value_type<C, T> const &v)
{
    return stlsoft_ns_qual(c_str_len(v.get_path()));
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_size_t c_str_size(basic_findfile_sequence_value_type<C, T> const &v)
{
    return stlsoft_ns_qual(c_str_size(v.get_path()));
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_bool_t is_empty(basic_findfile_sequence<C, T> const &s)
{
    return s.empty();
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_inetstl_findfile_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "InetSTL", "findfile_sequence", __FILE__);

# if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
# endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_inetstl_findfile_sequence(test_inetstl_findfile_sequence);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

///////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// basic_findfile_sequence

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */ HINTERNET basic_findfile_sequence<C, T>::find_first_file_(HINTERNET hconn, ss_typename_type_k basic_findfile_sequence<C, T>::char_type const *spec, is_int_t /* flags */, ss_typename_type_k basic_findfile_sequence<C, T>::find_data_type *findData)
{
    HINTERNET   hSrch   =   traits_type::find_first_file(hconn, spec, findData);

#ifdef _DEBUG
    if(NULL == hSrch)
    {
        ::GetLastError();
    }
#endif /* _DEBUG */

    return hSrch;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */ is_int_t basic_findfile_sequence<C, T>::validate_flags_(is_int_t flags)
{
    return (flags & (directories | files)) == 0 ? (flags | (directories | files)) : flags;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */ void basic_findfile_sequence<C, T>::extract_subpath_(HINTERNET hconn, char_type *dest, char_type const *searchSpec)
{
    char_type   *pFile;

    traits_type::get_full_path_name(hconn, searchSpec, _MAX_PATH, dest, &pFile);

    if(NULL != pFile)
    {
        *pFile = '\0';
    }
}

// Construction
template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence<C, T>::basic_findfile_sequence(HINTERNET hconn, char_type const *pattern, is_int_t flags /* = directories | files */)
    : m_hconn(hconn)
    , m_rootDir()
    , m_patterns(pattern)
    , m_delim('\0')
    , m_flags(validate_flags_(flags))
{}

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence<C, T>::basic_findfile_sequence(HINTERNET hconn, char_type const *directory, char_type const * pattern, is_int_t flags /* = directories | files */)
    : m_hconn(hconn)
    , m_rootDir(directory)
    , m_patterns(pattern)
    , m_delim('\0')
    , m_flags(validate_flags_(flags))
{}

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence<C, T>::basic_findfile_sequence(  HINTERNET       hconn
                                                            ,   char_type const *directory
                                                            ,   char_type const *patterns
                                                            ,   char_type       delim
                                                            ,   is_int_t        flags /* = directories | files */)
    : m_hconn(hconn)
    , m_rootDir(directory)
    , m_patterns(patterns)
    , m_delim(delim)
    , m_flags(validate_flags_(flags))
{}

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence<C, T>::~basic_findfile_sequence() stlsoft_throw_0()
{}

// Iteration
template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence<C, T>::const_iterator basic_findfile_sequence<C, T>::begin() const
{
    return const_input_iterator(*this, stlsoft_ns_qual(c_str_ptr)(m_rootDir), stlsoft_ns_qual(c_str_ptr)(m_patterns), m_delim, m_flags);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence<C, T>::const_iterator basic_findfile_sequence<C, T>::end() const
{
    return const_input_iterator(*this);
}

// Attributes
template <ss_typename_param_k C, ss_typename_param_k T>
ss_typename_type_k basic_findfile_sequence<C, T>::char_type const *basic_findfile_sequence<C, T>::get_directory() const
{
    return stlsoft_ns_qual(c_str_ptr)(m_rootDir);
}

// State
#ifdef STLSOFT_OBSOLETE
template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence<C, T>::size_type basic_findfile_sequence<C, T>::size() const
{
    return stlsoft_ns_qual_std(distance)(begin(), end());
}
#endif /* STLSOFT_OBSOLETE */

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_bool_t basic_findfile_sequence<C, T>::empty() const
{
    return begin() == end();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline /* static */ ss_typename_type_k basic_findfile_sequence<C, T>::size_type basic_findfile_sequence<C, T>::max_size()
{
    return static_cast<size_type>(-1);
}

// basic_findfile_sequence_value_type

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence_value_type<C, T>::basic_findfile_sequence_value_type()
{
    m_data.dwFileAttributes         =   0xFFFFFFFF;
    m_data.cFileName[0]             =   '\0';
    m_data.cAlternateFileName[0]    =   '\0';
    m_path[0]                       =   '\0';
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline basic_findfile_sequence_value_type<C, T>::~basic_findfile_sequence_value_type() stlsoft_throw_0()
{}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence_value_type<C, T>::find_data_type const &basic_findfile_sequence_value_type<C, T>::get_find_data() const
{
    return m_data;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence_value_type<C, T>::find_data_type const &basic_findfile_sequence_value_type<C, T>::GetFindData() const
{
    return get_find_data();
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence_value_type<C, T>::char_type const *basic_findfile_sequence_value_type<C, T>::get_filename() const
{
    return m_data.cFileName;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence_value_type<C, T>::char_type const *basic_findfile_sequence_value_type<C, T>::get_short_filename() const
{
    return m_data.cAlternateFileName[0] != '\0' ? m_data.cAlternateFileName : m_data.cFileName;
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline ss_typename_type_k basic_findfile_sequence_value_type<C, T>::char_type const *basic_findfile_sequence_value_type<C, T>::get_path() const
{
    return m_path;
}

template <ss_typename_param_k C, ss_typename_param_k T>
#if defined(STLSOFT_COMPILER_IS_GCC) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1100)
inline basic_findfile_sequence_value_type<C, T>::operator C const * () const
#else
inline basic_findfile_sequence_value_type<C, T>::operator ss_typename_type_k basic_findfile_sequence_value_type<C, T>::char_type const *() const
#endif /* !__GNUC__ */
{
    return get_path();
}

// operator == ()
template <ss_typename_param_k C, ss_typename_param_k T>
inline is_bool_t operator == (basic_findfile_sequence_value_type<C, T> const &lhs, basic_findfile_sequence_value_type<C, T> const &rhs)
{
    return 0 == basic_findfile_sequence_value_type<C, T>::traits_type::str_compare(lhs.get_path(), rhs.get_path());
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_bool_t operator == (basic_findfile_sequence_value_type<C, T> const &lhs, C const *rhs)
{
    return 0 == basic_findfile_sequence_value_type<C, T>::traits_type::str_compare(lhs.get_path(), rhs);
}

template <ss_typename_param_k C, ss_typename_param_k T>
inline is_bool_t operator == (C const *lhs, basic_findfile_sequence_value_type<C, T> const &rhs)
{
    return 0 == basic_findfile_sequence_value_type<C, T>::traits_type::str_compare(lhs, rhs.get_path());
}

// basic_findfile_sequence_const_input_iterator

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline /* static */ is_bool_t basic_findfile_sequence_const_input_iterator<C, T, V>::find_next_pattern_(ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const   *&p0
                                                                                                    ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const   *&p1
                                                                                                    ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type         delim)
{
    INETSTL_ASSERT(NULL != p0);
    INETSTL_ASSERT(NULL != p1);
    INETSTL_ASSERT(p0 <= p1);

    return stlsoft_ns_qual(find_next_token)(p0, p1, delim);
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline /* static */ HINTERNET basic_findfile_sequence_const_input_iterator<C, T, V>::find_first_file_(  HINTERNET                                                                                   hconn
                                                                                                    ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const   *searchSpec
                                                                                                    ,   is_int_t                                                                                    flags
                                                                                                    ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::find_data_type    *findData)
{
    HINTERNET   hSrch = traits_type::find_first_file(hconn, searchSpec, findData);

    if(hSrch != NULL)
    {
        // Now need to validate against the flags
        for(; hSrch != NULL; )
        {
            if(0 == (findData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // A file, and files requested, so break
                if(flags & sequence_type::files)
                {
                    break;
                }
            }
            else
            {
                if(traits_type::is_dots(findData->cFileName))
                {
                    if(flags & sequence_type::includeDots)
                    {
                        // A dots file, and dots are requested
                        break;
                    }
                }
                else if(flags & sequence_type::directories)
                {
                    // A directory, and directories requested
                    break;
                }
            }

            if(!traits_type::find_next_file(hSrch, findData))
            {
                traits_type::find_close(hSrch);

                hSrch = NULL;

                break;
            }
        }
    }

    return hSrch;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator()
    : m_list(NULL)
    , m_handle(NULL)
    , m_rootDir(NULL)
    , m_pattern0(NULL)
    , m_pattern1(NULL)
    , m_delim('\0')
    , m_flags(0)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator( sequence_type const                                                                         &l
                                                                                                        ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const   *rootDir
                                                                                                        ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type const   *patterns
                                                                                                        ,   ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::char_type         delim
                                                                                                        ,   is_int_t                                                                                    flags)

    : m_list(&l)
    , m_handle(NULL)
    , m_rootDir(rootDir)
    , m_pattern0(patterns)
    , m_pattern1(patterns)
    , m_delim(delim)
    , m_flags(flags)
{
    operator ++();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator(sequence_type const &l)
    : m_list(&l)
    , m_handle(NULL)
    , m_rootDir(NULL)
    , m_pattern0(NULL)
    , m_pattern1(NULL)
    , m_delim('\0')
    , m_flags(0)
{}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline basic_findfile_sequence_const_input_iterator<C, T, V>::basic_findfile_sequence_const_input_iterator(class_type const &rhs)
    : m_list(rhs.m_list)
    , m_handle(rhs.m_handle)
    , m_data(rhs.m_data)
    , m_rootDir(rhs.m_rootDir)
    , m_pattern0(rhs.m_pattern0)
    , m_pattern1(rhs.m_pattern1)
    , m_delim(rhs.m_delim)
    , m_flags(rhs.m_flags)
{
    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
#ifndef STLSOFT_COMPILER_IS_WATCOM
inline ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type &basic_findfile_sequence_const_input_iterator<C, T, V>::operator =(ss_typename_param_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type const &rhs)
#else /* ? STLSOFT_COMPILER_IS_WATCOM */
inline basic_findfile_sequence_const_input_iterator<C, T, V> &basic_findfile_sequence_const_input_iterator<C, T, V>::operator =(basic_findfile_sequence_const_input_iterator<C, T, V> const &rhs)
#endif /* STLSOFT_COMPILER_IS_WATCOM */
{
    INETSTL_MESSAGE_ASSERT("Assigning iterators from separate sequences", m_list == rhs.m_list);    // Should only be comparing iterators from same container

    m_handle    =   rhs.m_handle;
    m_data      =   rhs.m_data;
    INETSTL_ASSERT(m_rootDir == rhs.m_rootDir);
    m_pattern0  =   rhs.m_pattern0;
    m_pattern1  =   rhs.m_pattern1;
    INETSTL_ASSERT(m_delim == rhs.m_delim);
    INETSTL_ASSERT(m_flags == rhs.m_flags);

    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline basic_findfile_sequence_const_input_iterator<C, T, V>::~basic_findfile_sequence_const_input_iterator() stlsoft_throw_0()
{
    if(NULL != m_handle)
    {
        m_handle->Release();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type &basic_findfile_sequence_const_input_iterator<C, T, V>::operator ++()
{
    INETSTL_ASSERT(NULL != m_pattern0);
    INETSTL_ASSERT(NULL != m_pattern1);

    INETSTL_MESSAGE_ASSERT("Attempting to increment an invalid iterator!", '\0' != *m_pattern0);

    // Possible call states:
    //
    //  1. starting out
    //  2. 

    for(; '\0' != *m_pattern0 || '\0' != *m_pattern1;)
    {
        if(NULL == m_handle)
        {
            // Need to work through the 

            while(find_next_pattern_(m_pattern0, m_pattern1, m_delim))
            {
                if(m_pattern1 != m_pattern0)    // Will return m_pattern0 == m_pattern1 for empty tokens
                {
                    string_type     pattern(m_pattern0, m_pattern1);
                    string_type     search  =   m_rootDir;

                    if(search.back() != '/')
                    {
                        static const char_type  slash[] = { '/', '\0' };

                        search += slash;
                    }
                    search += pattern;

//printf("[%s]\n", search.c_str());
                    HINTERNET       hSrch   =   find_first_file_(m_list->m_hconn, stlsoft_ns_qual(c_str_ptr)(search), m_flags, &m_data);

                    if(NULL != hSrch)
                    {
                        m_handle = new shared_handle(hSrch);

                        return *this;
                    }
#if 0
                    else
                    {
                        DWORD       dwErr   =   ::GetLastError();

                        dwErr = 0;
                    }
#endif /* 0 */
                }
            }
        }

        if(NULL != m_handle)
        {
            for(; m_handle->hSrch != NULL; )
            {
                if(!traits_type::find_next_file(m_handle->hSrch, &m_data))
                {
                    m_handle->Release();

                    m_handle = NULL;

                    break;
                }
                else
                {
                    if((m_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
                    {
                        // A file, and files requested, so break
                        if(m_flags & sequence_type::files)
                        {
                            return *this;
                        }
                    }
                    else
                    {
                        if(traits_type::is_dots(m_data.cFileName))
                        {
                            if(m_flags & sequence_type::includeDots)
                            {
                                // A dots file, and dots are requested
                                return *this;
                            }
                        }
                        else if(m_flags & sequence_type::directories)
                        {
                            // A directory, and directories requested
                            return *this;
                        }
                    }
                }
            }
        }
    }

    return *this;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::class_type basic_findfile_sequence_const_input_iterator<C, T, V>::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline const ss_typename_type_k basic_findfile_sequence_const_input_iterator<C, T, V>::value_type basic_findfile_sequence_const_input_iterator<C, T, V>::operator *() const
{
    if(NULL != m_handle)
    {
        return value_type(m_data, m_list->get_directory());
    }
    else
    {
        INETSTL_MESSAGE_ASSERT("Dereferencing end()-valued iterator", 0);

        return value_type();
    }
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline is_bool_t basic_findfile_sequence_const_input_iterator<C, T, V>::operator ==(class_type const &rhs) const
{
    is_bool_t    eq;

    // Should only be comparing iterators from same container
    INETSTL_MESSAGE_ASSERT("Comparing iterators from separate sequences", m_list == rhs.m_list);

    // Not equal if one but not both handles is the NULL
    // or if the data is not equal.
    if( (NULL == m_handle) != (NULL == rhs.m_handle) ||
        (   NULL != m_handle &&
            traits_type::str_compare(m_data.cFileName, rhs.m_data.cFileName) != 0))
    {
        eq = is_false_v;
    }
    else
    {
        eq = is_true_v;
    }

    return eq;
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k V>
inline is_bool_t basic_findfile_sequence_const_input_iterator<C, T, V>::operator !=(class_type const &rhs) const
{
    return ! operator ==(rhs);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group inetstl_filesystem_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _INETSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace inetstl
# else
} // namespace inetstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef _INETSTL_NO_NAMESPACE
# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */

using ::inetstl::c_str_ptr_null;

using ::inetstl::c_str_ptr;

using ::inetstl::c_str_data;

using ::inetstl::c_str_len;

using ::inetstl::c_str_size;

using ::inetstl::is_empty;

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? _STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !_STLSOFT_NO_NAMESPACE */
#endif /* !_INETSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* INETSTL_INCL_INETSTL_HPP_FINDFILE_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
