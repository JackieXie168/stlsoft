/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/performance/performance.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Performance library.
 *
 * Created:     22nd May 2006
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


/* PlatformSTL Header Files */
#include <platformstl/performance/performance_counter.hpp>

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
    // 1. Create an instance of the platformstl::performance_counter. (On
    // UNIX this will resolve to unixstl::performance_counter; on Win32 it
    // will resolve to winstl::performance_counter.)
    platformstl::performance_counter    counter;

    // 2. Begin the measurement
    counter.start();

    // 3. A loop that will consume some time.
    for(volatile size_t i = 0; i < 0x1fffffff; ++i)
    {}

    // 4. End the measurement
    counter.stop();

    // 5. Display the number of whole seconds that have elapsed.
    cout << "interval (s):  " << static_cast<unsigned>(counter.get_seconds()) << endl;
    // 6. Display the number of whole milliseconds that have elapsed.
    cout << "interval (ms): " << static_cast<unsigned>(counter.get_milliseconds()) << endl;
    // 7. Display the number of whole microseconds that have elapsed.
    cout << "interval (us): " << static_cast<unsigned>(counter.get_microseconds()) << endl;

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
