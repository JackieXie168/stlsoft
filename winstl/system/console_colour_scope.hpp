/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/console_colour_scope.hpp
 *
 * Purpose:     Scopes the console colour (and intensity).
 *
 * Created:     20th July 2006
 * Updated:     20th July 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006, Matthew Wilson and Synesis Software
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


/** \file winstl/window/console_colour_scope.hpp
 *
 * \brief [C++ only] Definition of the winstl::console_colour_scope class.
 * (\ref group__library__windows_window "Windows Window" Library.)
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE
#define WINSTL_INCL_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE_MAJOR    1
# define WINSTL_VER_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE_REVISION 1
# define WINSTL_VER_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE_EDIT     1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS
#  include <winstl/error/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief Provides scoping of the colour (and intensity) of the console
 *
 * \ingroup group__library__windows_window
 *
 * This class provides scoping of the colour (and intensity) of the console
 * via the API functions <code>GetConsoleScreenBufferInfo()</code> and
 * <code>SetConsoleTextAttribute()</code>.
 */
class console_colour_scope
{
public:
    typedef console_colour_scope class_type;

// Construction
public:
    /// \brief Toggles the window enable state
    ///
    /// Takes a HWND and changes it's current enable-status, which is set back to
    /// the original state in the destructor.
    ///
    /// \param hBuffer Handle the console screen buffer.
    /// \param 
    ss_explicit_k console_colour_scope(HANDLE hBuffer, WORD textAttributes)
        : m_hBuffer(hBuffer)
        , m_attributes(init_(hBuffer, textAttributes))
    {}

    /// Resets the enable status
    ~console_colour_scope() stlsoft_throw_0()
    {
        ::SetConsoleTextAttribute(m_hBuffer, static_cast<WORD>(m_attributes));
    }

/// \name Implementation
/// @{
private:
    static ws_uint32_t init_(HANDLE hBuffer, WORD textAttributes)
    {
        CONSOLE_SCREEN_BUFFER_INFO  bufferInfo;

        if(!::GetConsoleScreenBufferInfo(hBuffer, &bufferInfo))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            throw windows_exception("Could not retrieve console buffer information", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            return 0xffffffff;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            if(!::SetConsoleTextAttribute(hBuffer, textAttributes))
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                throw windows_exception("Could not set console text attributes", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                return 0xffffffff;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                return bufferInfo.wAttributes;
            }
        }
    }
/// @}

/// \name Members
/// @{
private:
    HANDLE      m_hBuffer;
    ws_uint32_t m_attributes;
/// @}

/// \name Not to be implemented
/// @{
private:
    console_colour_scope(class_type const &rhs);
    class_type const &operator =(class_type const &rhs);
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_WINDOW_HPP_CONSOLE_COLOUR_SCOPE */

/* ////////////////////////////////////////////////////////////////////// */
