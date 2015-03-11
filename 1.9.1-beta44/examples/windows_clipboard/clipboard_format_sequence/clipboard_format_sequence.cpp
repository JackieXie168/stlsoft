/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/windows_clipboard/clipboard_format_sequence/clipboard_format_sequence.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Windows Clipboard
 *              library.
 *
 * Created:     6th June 2006
 * Updated:     15th September 2006
 *
 * www:         http://www.stlsoft.org/
 *
 * License:     Copyright (c) 2006, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* WinSTL Header Files */
#include <winstl/clipboard/clipboard_format_sequence.hpp>

/* Standard C++ Header Files */
#include <iostream>

int main()
{
    try
    {
        winstl::clipboard_format_sequence   formats;

        { for(winstl::clipboard_format_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
        {
            std::cout << "    " << *b << std::endl;
        }}
    }
    catch(winstl::clipboard_scope_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return 0;
}

/* ////////////////////////////////////////////////////////////////////// */
