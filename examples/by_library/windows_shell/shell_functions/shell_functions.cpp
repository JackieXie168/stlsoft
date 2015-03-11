/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/windows_shell/shell_functions/shell_functions.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Windows Shell
 *              library filesystem functions.
 *
 * Created:     9th December 2006
 * Updated:     13th March 2007
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
#include <winstl/error/error_desc.hpp>
#include <winstl/filesystem/current_directory.hpp>
#include <winstl/shell/browse_for_folder.hpp>
#include <winstl/shell/file_operations.hpp>
#include <winstl/shell/memory_functions.h>

/* STLSoft Header Files */
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    try
    {
        CHAR            displayName[_MAX_PATH + 1];
        LPITEMIDLIST    iil;
        HRESULT         hr  =   ::SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &iil);

        if(FAILED(hr))
        {
            cerr << "Could not get the My Computer special folder location: " << winstl::error_desc(hr) << endl;
        }
        else
        {
            stlsoft::scoped_handle<void*>   iil_(iil, winstl::SHMemFree);

            if(winstl::browse_for_folder("Select a file to send to the recycle bin", displayName, BIF_BROWSEINCLUDEFILES, iil))
            {
                winstl::shell_delete(displayName, FOF_ALLOWUNDO);
            }
        }

        return EXIT_SUCCESS;
    }
    catch(std::exception &x)
    {
        cerr << "Error: " << x.what() << endl;

        return EXIT_FAILURE;
    }
    catch(...)
    {
        cerr << "Unknown error" << endl;

        return EXIT_FAILURE;
    }
}

/* ////////////////////////////////////////////////////////////////////// */
