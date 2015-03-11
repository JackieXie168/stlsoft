/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/memory/heapwalk_sequence/heapwalk_sequence.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Memory library.
 *
 * Created:     15th September 2006
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
#include <winstl/memory/heapwalk_sequence.hpp>


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
        cout    << "This program demonstrates use of the heapwalk_sequence" << endl
                << " class by enumerating all the currently allocated blocks" << endl
                << " of the process heap." << endl;

        winstl::heapwalk_sequence   blocks;

        { for(winstl::heapwalk_sequence::const_iterator b = blocks.begin(); b != blocks.end(); ++b)
        {
            cout << "  Block of size " << (*b).cbData << " at " << (*b).lpData << endl;
        }}

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
