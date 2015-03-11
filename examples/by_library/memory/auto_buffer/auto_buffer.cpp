/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/memory/auto_buffer/auto_buffer.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Memory library
 *              component auto_buffer.
 *
 * Created:     15th September 2006
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


/* STLSoft Header Files */
#include <stlsoft/memory/auto_buffer.hpp>


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
        stlsoft::auto_buffer<char, 64>  buff(0);

        // Resize within the bounds of the internal buffer
        buff.resize(10);

        ::memset(&buff[0], 1, buff.size());

        // Resize outside the bounds of the internal buffer, and go to the heap
        buff.resize(100);

        ::memset(&buff[0], 2, buff.size());

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
