/* /////////////////////////////////////////////////////////////////////////////
 * File:        acestl/message_queue_sequence.hpp
 *
 * Purpose:     Sequence class for adapting ACE_Message_Queue to an STL sequence.
 *
 * Created:     15th September 2004
 * Updated:     22nd December 2005
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


/// \file acestl/message_queue_sequence.hpp
///
/// Simple class that provides access to an environment variable.

#ifndef ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE
#define ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE_MINOR     1
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE_REVISION  5
# define ACESTL_VER_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE_EDIT      25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifndef STLSOFT_INCL_STLSOFT_HPP_ITERATOR
# include <stlsoft/iterator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_ITERATOR */
#include <ace/Message_Queue_T.h>            // for ACE_Message_Queue_Iterator<>

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */

namespace stlsoft
{

namespace acestl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

/// \weakgroup libraries STLSoft Libraries
/// \brief The individual libraries

/// \weakgroup libraries_messaging Messaging Library
/// \ingroup libraries
/// \brief This library provides facilities for defining and manipulating messaging constructs

/// \defgroup acestl_messaging_library Messaging Library (ACESTL)
/// \ingroup ACESTL libraries_messaging
/// \brief This library provides facilities for defining and manipulating messaging constructs with ACE
/// @{

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// Provides sequence over all the elements in a memory queue
///
template <ACE_SYNCH_DECL>
class message_queue_sequence
{
/// \name Types
/// @{
public:
    /// The value type
    typedef char                                    value_type;
    /// The current parameterisation of the type
    typedef message_queue_sequence<ACE_SYNCH_USE>   class_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef class_type                              sequence_class_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The size type
    typedef ss_size_t                               size_type;

    /// Iterator type for the message_queue_sequence class template
    class iterator
        : public stlsoft_ns_qual(iterator_base)<acestl_ns_qual_std(input_iterator_tag), char, ss_ptrdiff_t, char*, char&>
    {
    private:
        friend class message_queue_sequence<ACE_SYNCH_USE>;

        typedef ACE_Message_Queue_Iterator<ACE_SYNCH_USE>   mq_iterator_type;

/// \name Utility classes
/// @{
    private:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        struct shared_handle
        {
        public:
            typedef shared_handle       class_type;

        // Members
        public:
            mq_iterator_type    m_mqi;
            ACE_Message_Block   *m_entry;
            size_t              m_entryLength;
            size_t              m_entryIndex;
        private:
            ss_sint32_t         cRefs;

        /// Construction
        public:
            ss_explicit_k shared_handle(ACE_Message_Queue<ACE_SYNCH_USE> &mq)
                : m_mqi(mq)
                , m_entry(NULL)
                , m_entryLength(0)
                , m_entryIndex(0)
                , cRefs(1)
            {
                if(m_mqi.next(m_entry))
                {
                    for(;;)
                    {
                        if(0 != (m_entryLength = m_entry->length()))
                        {
                            break;
                        }
                        else if(NULL == (m_entry = nextEntry()))
                        {
                            break;
                        }
                    }
                }
            }
# if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
        protected:
# else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
        private:
# endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
            ~shared_handle() stlsoft_throw_0()
            {
                ACESTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == cRefs);
            }

        /// Accessors
        public:
            char    current() const
            {
                ACESTL_ASSERT(NULL != m_entry);
                ACESTL_ASSERT(m_entryIndex != m_entryLength);

                return m_entryIndex[m_entry->rd_ptr()];
            }

            ss_bool_t   advance()
            {
                ACESTL_ASSERT(m_entryIndex < m_entryLength);

                if(++m_entryIndex == m_entryLength)
                {
                    m_entryIndex = 0;

                    for(;;)
                    {
                        if(NULL == (m_entry = nextEntry()))
                        {
                            return false;
                        }
                        else if(0 != (m_entryLength = m_entry->length()))
                        {
                            break;
                        }
                    }
                }

                return true;
            }

        /// Operations
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

        // Implementation
        private:
            ACE_Message_Block   *nextEntry()
            {
                ACE_Message_Block   *entry  =   NULL;

                return m_mqi.advance() ? (m_mqi.next(entry), entry) : NULL;
            }


        // Not to be implemented
        private:
            shared_handle(class_type const &);
            class_type &operator =(class_type const &);
        };
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

    public:
        typedef iterator                                    class_type;
        /// The value type
        typedef char                                        value_type;

    private:
        iterator(ACE_Message_Queue<ACE_SYNCH_USE> &mq)
            : m_handle(new shared_handle(mq))
        {}
    public:
        iterator()
            : m_handle(NULL)
        {}
        iterator(class_type const &rhs)
            : m_handle(rhs.m_handle)
        {
            if(NULL != m_handle)
            {
                m_handle->AddRef();
            }
        }
        ~iterator() stlsoft_throw_0()
        {
            if(NULL != m_handle)
            {
                m_handle->Release();
            }
        }

        class_type &operator =(class_type const &rhs)
        {
            m_handle    =   rhs.m_handle;
            m_data      =   rhs.m_data;

            if(NULL != m_handle)
            {
                m_handle->AddRef();
            }

            return *this;
        }

    public:
        class_type &operator ++()
        {
            ACESTL_ASSERT(NULL != m_handle);

            if(!m_handle->advance())
            {
                m_handle->Release();

                m_handle = NULL;
            }

            return *this;
        }

        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        value_type operator *() const
        {
            ACESTL_ASSERT(NULL != m_handle);

            return m_handle->current();
        }

    public:
        ss_bool_t operator ==(class_type const &rhs) const
        {
            return m_handle == rhs.m_handle;
        }
        ss_bool_t operator !=(class_type const &rhs) const
        {
            return !operator ==(rhs);
        }

    private:
        shared_handle   *m_handle;
    };
/// @}

// Construction
/// @{
public:
    /// Create an instance representing the given environment variable
    ss_explicit_k message_queue_sequence(ACE_Message_Queue<ACE_SYNCH_USE> &mq)
        : m_mq(mq)
    {}
#ifdef __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Create an instance representing the given environment variable
    template<ss_typename_param_k S>
    ss_explicit_k message_queue_sequence(S const &name)
        : m_buffer(1 + traits_type::get_message_queue_sequence(c_str_ptr(name), 0, 0))
    {
        if( 0 == traits_type::get_message_queue_sequence(c_str_ptr(name), m_buffer, m_buffer.size()) &&
            0 != m_buffer.size())
        {
            m_buffer[0] = 0;
        }
    }
#endif /* __STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
/// @}

/// \name Iteration
/// @{
public:
    iterator begin()
    {
        return iterator(m_mq);
    }
    iterator end()
    {
        return iterator();
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the number of bytes in the message queue
    size_type size() const
    {
        return m_mq.message_length() /* - 1 */;
    }
/// @]

/// \name Operations
/// @{
public:
/// @}

/// \name Members
/// @{
private:
    ACE_Message_Queue<ACE_SYNCH_USE>    &m_mq;
/// @}

// Not to be implemented
private:
    message_queue_sequence(message_queue_sequence const &);
    message_queue_sequence &operator =(message_queue_sequence const &);
};

////////////////////////////////////////////////////////////////////////////////

/// @} // acestl_messaging_library

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/message_queue_sequence_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _ACESTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace acestl
# else
} // namespace acestl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_ACESTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE */

/* ////////////////////////////////////////////////////////////////////////// */
