/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/toolhelp/process_sequence/process_sequence.cpp
 *
 * Purpose:     C++ example program demonstrating use of the ToolHelp library.
 *
 * Created:     22nd May 2006
 * Updated:     9th December 2006
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
#include <winstl/toolhelp/process_sequence.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

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
        // 1. Construct an instance of process_sequence. There is no parameter
        // required for process_sequence.
        winstl::process_sequence    processes;

        // 2. Declare iterator instances (since we're using a manual loop, 
        // rather than an algorithm).
        winstl::process_sequence::const_iterator    b   =   processes.begin();
        winstl::process_sequence::const_iterator    e   =   processes.end();

        // 3. Loop through the range.
        for(; b != e; ++b)
        {
            // 3.1. Print out the process id and the file name.
            cout << (*b).th32ProcessID << ": " << (*b).szExeFile << endl;
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
