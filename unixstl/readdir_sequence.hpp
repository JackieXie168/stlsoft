/* /////////////////////////////////////////////////////////////////////////////
 * File:        unixstl/readdir_sequence.hpp (formerly unixstl_readdir_sequence.h)
 *
 * Purpose:     readdir_sequence class.
 *
 * Created:     15th January 2002
 * Updated:     19th January 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2006, Matthew Wilson and Synesis Software
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


/// \file unixstl/readdir_sequence.hpp
///
/// readdir_sequence class.

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_READDIR_SEQUENCE
#define UNIXSTL_INCL_UNIXSTL_HPP_READDIR_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_HPP_READDIR_SEQUENCE_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_HPP_READDIR_SEQUENCE_MINOR     6
# define UNIXSTL_VER_UNIXSTL_HPP_READDIR_SEQUENCE_REVISION  3
# define UNIXSTL_VER_UNIXSTL_HPP_READDIR_SEQUENCE_EDIT      95
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILESYSTEM_TRAITS */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER
# include <unixstl/file_path_buffer.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_FILE_PATH_BUFFER */
#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS
# include <unixstl/exceptions.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */
#include <unistd.h>
#if defined(PATH_MAX)
# ifndef STLSOFT_INCL_STLSOFT_HPP_STATIC_STRING
#  include <stlsoft/static_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_STATIC_STRING */
#else /* ? PATH_MAX */
# ifndef STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING
#  include <stlsoft/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_SIMPLE_STRING */
#endif /* !PATH_MAX */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS
# include <stlsoft/collections/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_COLLECTIONS */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

/* No STLSoft namespaces means no UNIXSTL namespaces */
#ifdef _STLSOFT_NO_NAMESPACES
# define _UNIXSTL_NO_NAMESPACES
#endif /* _STLSOFT_NO_NAMESPACES */

/* No UNIXSTL namespaces means no unixstl namespace */
#ifdef _UNIXSTL_NO_NAMESPACES
# define _UNIXSTL_NO_NAMESPACE
#endif /* _UNIXSTL_NO_NAMESPACES */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_filesystem File-System Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating file-system objects

/// \defgroup unixstl_filesystem_library File-System Library (UNIXSTL)
/// \ingroup UNIXSTL libraries_filesystem
/// \brief This library provides facilities for defining and manipulating UNIX file-system objects
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

class readdir_sequence_exception
    : public unix_exception
{
/// \name Types
/// @{
public:
    typedef unix_exception              parent_class_type;
    typedef readdir_sequence_exception  class_type;
/// @}

/// \name Construction
/// @{
public:
    readdir_sequence_exception(us_char_a_t const *message, us_int_t erno)
        : parent_class_type(message, erno)
    {}
/// @}
};


/// \brief STL-like readonly sequence based on directory contents
///
/// This class presents and STL-like readonly sequence interface to allow the
/// iteration over the contents of a directory.

class readdir_sequence
    : public stl_collection_tag
{
/// \name Member Types
/// @{
public:
    // This class
    typedef readdir_sequence                                    class_type;
private:
    // These make it easy to move to a template, if ever needed
    typedef us_char_a_t                                         char_type;
    typedef filesystem_traits<char_type>                        traits_type;
public:
    // The size type
    typedef us_size_t                                           size_type;
    // The non-mutating (const) iterator type
    class                                                       const_iterator;
    // The value type
#if defined(UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE)
    typedef struct dirent const                                 *value_type;
#else /* ? UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
    typedef char_type const                                     *value_type;
#endif /* UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */

//    typedef const_iterator::pointer            pointer;
//    typedef const_iterator::pointer const      const_pointer;
//    typedef const_iterator::reference          reference;
//    typedef const_iterator::reference const    const_reference;

public:
#if defined(PATH_MAX)
    typedef stlsoft_ns_qual(basic_static_string)<   char_type
                                                ,   PATH_MAX
                                                >               string_type;
#else /* ? PATH_MAX */
    typedef stlsoft_ns_qual(basic_simple_string)<   char_type
                                                >               string_type;
#endif /* !PATH_MAX */
/// @}

/// \name Flags
/// @{
public:
    enum
    {
            includeDots     =   0x0008  /*!< Requests that dots directories be included in the returned sequence */
        ,   directories     =   0x0010  /*!< Causes the search to include directories */
        ,   files           =   0x0020  /*!< Causes the search to include files */
        ,   fullPath        =   0x0100  /*!< Each file entry is presented as a full path relative to the search directory. */
        ,   absolutePath    =   0x0200  /*!< The search directory is converted to an absolute path. */
    };
/// @}

/// \name Construction
/// @{
public:
    /// \brief Constructs a sequence according to the given criteria
    ///
    /// The constructor initialises a readdir_sequence instance on the given
    /// directory with the given flags.
    ///
    /// \param directory The directory whose contents are to be searched
    /// \param flags Flags to alter the behaviour of the search
    ///
    /// \note The \c flags parameter defaults to <code>directories | files</code> because
    /// this reflects the default behaviour of \c readdir(), and also because it is the
    /// most efficient.
#if 0
    readdir_sequence(char_type const *directory, us_int_t flags = directories | files);
#else /* ? 0 */
    template <ss_typename_param_k S>
    readdir_sequence(S const &directory, us_int_t flags = directories | files)
        : m_flags(validate_flags_(flags))
        , m_directory(prepare_directory_(stlsoft_ns_qual(c_str_ptr)(directory), flags))
    {}
#endif /* 0 */
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;
/// @}

/// \name Attributes
/// @{
public:
    /// \brief Indicates whether the search sequence is empty
    us_bool_t empty() const;

    /// \brief The search directory
    ///
    /// \note The value returned by this method always has a trailing path name separator, so
    /// you can safely concatenate this with the value returned by the iterator's operator *()
    /// with minimal fuss.
    string_type const   &get_directory() const;

    /// \brief The flags used by the sequence
    ///
    /// \note This value is the value used by the sequence, which may, as a result of the
    /// determination of defaults, be different from those specified in its constructor. In
    /// other words, if <code>includeDots</code> is specified, this function
    /// will return <code>includeDots | directories | files</code>
    us_int_t            get_flags() const;
/// @}

/// \name Implementation
/// @{
private:
    /// \brief Ensures that the flags are correct
    static us_int_t     validate_flags_(us_int_t flags);

    /// \brief Prepares the directory, according to the given flags
    static string_type  prepare_directory_(char_type const *directory, us_int_t flags);
/// @}

/// \name Members
/// @{
private:
    const us_int_t      m_flags;
    const string_type   m_directory;
/// @}

/// \name Not to be implemented
/// @{
private:
    readdir_sequence(class_type const &);
    class_type &operator =(class_type const &);
/// @}
};

/// \brief Iterator for readdir_sequence class
///
/// This class performs as a non-mutating iterator (aka const iterator) for the
/// readdir_sequence class.

class readdir_sequence::const_iterator
    : public stlsoft_ns_qual(iterator_base)<unixstl_ns_qual_std(input_iterator_tag)
                                        ,   readdir_sequence::value_type
                                        ,   us_ptrdiff_t
                                        ,   void                            // By-Value Temporary reference
                                        ,   readdir_sequence::value_type    // By-Value Temporary reference
                                        >
{
private:
    typedef readdir_sequence::string_type           string_type;
public:
    /// The class type
    typedef const_iterator                          class_type;
    /// The value type
    typedef readdir_sequence::value_type            value_type;
//    typedef value_type                            *pointer;
//    typedef value_type                            &reference;

// Construction
private:
    friend class readdir_sequence;

    /// Construct an instance and begin a sequence iteration on the given dir.
    const_iterator(DIR *dir, string_type const &directory, us_int_t flags);
public:
    /// Default constructor
    const_iterator();
    /// Copy constructor
    const_iterator(class_type const &rhs);
    /// Release the search handle
    ~const_iterator() stlsoft_throw_0();

    /// Copy assignment operator
    class_type const &operator =(class_type const &rhs);

// Accessors
public:
    /// Returns the value representative
    value_type operator *() const;

    /// Moves the iteration on to the next point in the sequence, or end() if
    /// the sequence is exhausted
    class_type &operator ++();

    /// Post-increment form of operator ++().
    ///
    /// \note Because this version uses a temporary on which to call the
    /// pre-increment form it is thereby less efficient, and should not be used
    /// except where post-increment semantics are required.
    class_type operator ++(int);

    /// Compares \c this for equality with \c rhs
    ///
    /// \param rhs The instance against which to test
    /// \retval true if the iterators are equivalent
    /// \retval false if the iterators are not equivalent
    bool equal(class_type const &rhs) const;

// Members
private:
    struct shared_handle;

    shared_handle   *m_handle;  // The DIR handle, shared with other iterator instances
    struct dirent   *m_entry;   // The current entry
    us_int_t        m_flags;    // flags. (Only non-const, to allow copy assignment)
    string_type     m_scratch;  // Holds the directory, and is a scratch area
    size_type       m_dirLen;   // The length of the directory
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct readdir_sequence::const_iterator::shared_handle
{
public:
    typedef shared_handle   class_type;

// Members
public:
    DIR         *m_dir;
private:
    ss_sint32_t m_refCount;

public:
    ss_explicit_k shared_handle(DIR *d)
        : m_dir(d)
        , m_refCount(1)
    {}
    ss_sint32_t AddRef()
    {
        return ++m_refCount;
    }
    ss_sint32_t Release()
    {
        ss_sint32_t rc = --m_refCount;

        if(0 == rc)
        {
            delete this;
        }

        return rc;
    }
#if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
protected:
#else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
private:
#endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
    ~shared_handle() stlsoft_throw_0()
    {
        UNIXSTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == m_refCount);

        if(NULL != m_dir)
        {
            ::closedir(m_dir);
        }
    }

private:
    shared_handle(class_type const &);
    class_type &operator =(class_type const &);
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////////
// Operators

inline us_bool_t operator ==(   readdir_sequence::const_iterator const &lhs
                            ,   readdir_sequence::const_iterator const &rhs)
{
    return lhs.equal(rhs);
}

inline us_bool_t operator !=(   readdir_sequence::const_iterator const &lhs
                            ,   readdir_sequence::const_iterator const &rhs)
{
    return !lhs.equal(rhs);
}

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/readdir_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// readdir_sequence

inline /* static */ us_int_t readdir_sequence::validate_flags_(us_int_t flags)
{
    const us_int_t  validFlags  =   0
                                |   includeDots
                                |   directories
                                |   files       
                                |   fullPath
                                |   absolutePath
                                |   0;

    UNIXSTL_MESSAGE_ASSERT("Specification of unrecognised/unsupported flags", flags == (flags & validFlags));
    STLSOFT_SUPPRESS_UNUSED(validFlags);

    if(0 == (flags & (directories | files)))
    {
        flags |= (directories | files);
    }

    return flags;
}

inline /* static */ readdir_sequence::string_type readdir_sequence::prepare_directory_(char_type const *directory, us_int_t flags)
{
    if( NULL == directory ||
        '\0' == *directory)
    {
        static const char_type  s_thisDir[] = { '.', '\0' };

        directory = s_thisDir;
    }

    basic_file_path_buffer<char_type>   path;
    size_type                           n;

    if(absolutePath & flags)
    {
        n = traits_type::get_full_path_name(directory, path.size(), &path[0]);

        if(0 == n)
        {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
            throw readdir_sequence_exception("Failed to enumerate directory", errno);
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
            traits_type::str_n_copy(&path[0], directory, path.size());
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    else
    {
        n = traits_type::str_len(traits_type::str_n_copy(&path[0], directory, path.size()));
    }

    traits_type::ensure_dir_end(&path[n - 1]);

    directory = path.c_str();

    return directory;
}

#if 0
inline readdir_sequence::readdir_sequence(char_type const *directory, us_int_t flags /* = directories | files */)
    : m_flags(validate_flags_(flags))
    , m_directory(prepare_directory_(stlsoft_ns_qual(c_str_ptr)(directory), flags))
{}
#endif /* 0 */

inline readdir_sequence::const_iterator readdir_sequence::begin() const
{
    DIR *dir = ::opendir(m_directory.c_str());

    if(NULL == dir)
    {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
        throw readdir_sequence_exception("Failed to enumerate directory", errno);
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
        return const_iterator();
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return const_iterator(dir, m_directory, m_flags);
}

inline readdir_sequence::const_iterator readdir_sequence::end() const
{
    return const_iterator();
}

inline us_bool_t readdir_sequence::empty() const
{
    return begin() != end();
}

inline readdir_sequence::string_type const &readdir_sequence::get_directory() const
{
    return m_directory;
}

inline us_int_t readdir_sequence::get_flags() const
{
    return m_flags;
}


// readdir_sequence::const_iterator;

inline readdir_sequence::const_iterator::const_iterator(DIR *dir, readdir_sequence::string_type const &directory, us_int_t flags)
    : m_handle(new shared_handle(dir))
    , m_entry(NULL)
    , m_flags(flags)
    , m_scratch(directory)
    , m_dirLen(directory.length())
{
    UNIXSTL_ASSERT(traits_type::has_dir_end(m_scratch.c_str()));

    if(NULL != m_handle)
    {
        operator ++();
    }
}

inline readdir_sequence::const_iterator::const_iterator()
    : m_handle(NULL)
    , m_entry(NULL)
    , m_flags(0)
    , m_scratch()
    , m_dirLen(0)
{}

inline readdir_sequence::const_iterator::const_iterator(class_type const &rhs)
    : m_handle(rhs.m_handle)
    , m_entry(rhs.m_entry)
    , m_flags(rhs.m_flags)
    , m_scratch(rhs.m_scratch)
    , m_dirLen(rhs.m_dirLen)
{
    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }
}

inline readdir_sequence::const_iterator::~const_iterator() stlsoft_throw_0()
{
    if(NULL != m_handle)
    {
        m_handle->Release();
    }
}

inline readdir_sequence::const_iterator::class_type const &readdir_sequence::const_iterator::operator =(readdir_sequence::const_iterator::class_type const &rhs)
{
    if(NULL != m_handle)
    {
        m_handle->Release();
    }

    m_handle  =   rhs.m_handle;
    m_entry   =   rhs.m_entry;
    m_flags   =   rhs.m_flags;
    m_scratch =   rhs.m_scratch;
    m_dirLen  =   rhs.m_dirLen;

    if(NULL != m_handle)
    {
        m_handle->AddRef();
    }

    return *this;
}

inline readdir_sequence::const_iterator::value_type readdir_sequence::const_iterator::operator *() const
{
    UNIXSTL_MESSAGE_ASSERT( "Dereferencing invalid iterator", NULL != m_entry);

#if defined(UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE)
    return m_entry;
#else /* ? UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
    return (readdir_sequence::fullPath & m_flags) ? m_scratch.c_str() : m_entry->d_name;
#endif /* UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
}

inline readdir_sequence::const_iterator::class_type &readdir_sequence::const_iterator::operator ++()
{
    UNIXSTL_MESSAGE_ASSERT( "Incrementing invalid iterator", NULL != m_handle);

    for(;;)
    {
        errno = 0;

        m_entry = ::readdir(m_handle->m_dir);

        if(NULL == m_entry)
        {
            if(0 != errno)
            {
#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
                throw readdir_sequence_exception("Partial failure of directory enumeration", errno);
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
        else
        {
            UNIXSTL_ASSERT(NULL != m_entry->d_name);

            if(0 == (m_flags & includeDots))
            {
                if(traits_type::is_dots(m_entry->d_name))
                {
                    continue; // Don't want dots; skip it
                }
            }

            // If either 
            //
            // - eliding files or directories, or
            // - requiring absolute path
            //
            // then need to construct it. 
            if((m_flags & (fullPath | directories | files)) != (directories | files))
            {
                // Truncate the scratch to the directory path, ...
                m_scratch.resize(m_dirLen);
                // ... and add the file
                m_scratch += m_entry->d_name;
            }

            if((m_flags & (directories | files)) != (directories | files))
            {
                // Now need to process the file, by using stat
                traits_type::stat_data_type st;

                if(!traits_type::stat(m_scratch.c_str(), &st))
                {
                    // Failed to get info from entry. Must assume it is
                    // dead, so skip it
                    continue;
                }
                else
                {
                    if(m_flags & directories) // Want directories
                    {
                        if(traits_type::is_directory(&st))
                        {
                            // It is a directory, so accept it
                            break;
                        }
                    }
                    if(m_flags & files) // Want files
                    {
                        if(traits_type::is_file(&st))
                        {
                            // It is a file, so accept it
                            break;
                        }
                    }

                    continue; // Not a match, so skip this entry
                }
            }
        }

        break;
    }

    if(NULL == m_entry)
    {
        UNIXSTL_ASSERT(NULL != m_handle);

        m_handle->Release();

        m_handle = NULL;
    }

    return *this;
}

inline readdir_sequence::const_iterator::class_type readdir_sequence::const_iterator::operator ++(int)
{
    class_type  ret(*this);

    operator ++();

    return ret;
}

inline bool readdir_sequence::const_iterator::equal(readdir_sequence::const_iterator::class_type const &rhs) const
{
    UNIXSTL_ASSERT(NULL == m_handle || NULL == rhs.m_handle || m_handle->m_dir == rhs.m_handle->m_dir);

    return m_entry == rhs.m_entry;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////////// */

/// @} // end of group unixstl_filesystem_library

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_READDIR_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */