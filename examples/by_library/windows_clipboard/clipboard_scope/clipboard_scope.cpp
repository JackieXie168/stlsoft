/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/windows_clipboard/clipboard_scope/clipboard_scope.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Windows Clipboard
 *              library.
 *
 * Created:     6th June 2006
 * Updated:     11th April 2007
 *
 * www:         http://www.stlsoft.org/
 *
 * License:     Copyright (c) 2006-2007, Synesis Software Pty Ltd.
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
#include <winstl/clipboard/clipboard_scope.hpp>

/* Standard C++ Header Files */
#include <iostream>

int main()
{
    try
    {
        // 1. Set the data on the clipboard
        {
            winstl::clipboard_scope     scope;

            scope.set_data("The data");
        }

        // 2. Get the data from the clipboard
        {
            winstl::clipboard_scope     scope;
            char const                  *str;

            scope.get_data(str);

            std::cout << "Clipboard data: " << str << std::endl;

            scope.get_allocator().deallocate(str);
        }
    }
    catch(winstl::clipboard_scope_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return 0;
}

/* ////////////////////////////////////////////////////////////////////// */
