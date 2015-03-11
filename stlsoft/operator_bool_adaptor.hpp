/* /////////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/operator_bool_adaptor.hpp
 *
 * Purpose:     Definition of the operator_bool_adaptor class.
 *
 * Created:     21st October 2004
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


/// \file stlsoft/operator_bool_adaptor.hpp Definition of the operator_bool_adaptor class.

#ifndef STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR
#define STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR_MAJOR    1
# define STLSOFT_VER_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR_MINOR    2
# define STLSOFT_VER_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR_REVISION 1
# define STLSOFT_VER_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR_EDIT     12
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL
# include <stlsoft/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// \brief This class is a reverse bolt-in, which provides the "safe" operator
/// bool to its parameterising type, in terms of its \c is_open method
template<ss_typename_param_k T>
class operator_bool_adaptor
{
public:
    /// The adapted type
    typedef T                           adapted_type;
    /// The type of this instantiation
    typedef operator_bool_adaptor<T>    class_type;

protected:
    /// \brief Default constructor
    ///
    /// This is defined protected to ensure that the adaptor may only be used
    /// as a base class, and not instantiated directly
    operator_bool_adaptor()
    {}

/// \name Range operators
/// @{
private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, boolean_generator_type, boolean_type);
public:
    /// Indicates whether the range is open
    operator boolean_type() const
    {
        return boolean_generator_type::translate(static_cast<adapted_type const*>(this)->is_open());
    }
/// @}
};

////////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST

namespace unittest
{
    namespace
    {
        ss_bool_t test_rangelib_operator_adaptor(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "operator_adaptors", __FILE__);

    #if 0
            if(NULL != pi1)
            {
                ator1.construct(pi1, 1968);

                if(1968 != *pi1)
                {
                    r->report("construct() failed ", __LINE__);
                    bSuccess = false;
                }
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_rangelib_operator_adaptor(test_rangelib_operator_adaptor);
    } // anonymous namespace

} // namespace unittest

#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOK_ADAPTOR */

/* ////////////////////////////////////////////////////////////////////////// */
