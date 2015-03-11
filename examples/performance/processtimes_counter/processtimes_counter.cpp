/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/performance/processtimes_counter.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Performance
 *              library's processtimes_counter component.
 *
 * Created:     9th June 2006
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


/* PlatformSTL Header Files */
#include <platformstl/performance/performance_counter.hpp>
#include <platformstl/performance/processtimes_counter.hpp>
#include <platformstl/synch/sleep_functions.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    // 1.a. Create an instance of the platformstl::processtimes_counter. (On
    // UNIX this will resolve to unixstl::processtimes_counter; on Win32 it
    // will resolve to winstl::processtimes_counter.)
    platformstl::processtimes_counter   usageCounter;
    // 1.b. Create an instance of the platformstl::performance_counter that
    // will be used to measure the elapsed times.
    platformstl::performance_counter    elapsedCounter;

    // 2. Begin the measurement
    usageCounter.start();
    elapsedCounter.start();

    // 3.a. A loop that will consume some user time.
    { for(volatile size_t i = 0; i < 0x1fffffff; ++i)
    {}}
    // 3.b. A loop that will consume some kernel time.
    { for(volatile size_t i = 0; i < 0x1ffff; ++i)
    {
        fprintf(stdout, " \b");
    }}
    // 3.c. A sleep, for five seconds, to separate elapsed and usage times.
    platformstl::micro_sleep(5 * 1000 * 1000);

    // 4. End the measurement
    usageCounter.stop();
    elapsedCounter.stop();

    // 5.a. Display the number of whole seconds of elapsed time
    cout << "elapsed interval (s):  " << static_cast<unsigned>(elapsedCounter.get_seconds()) << endl;
    // 6.a. Display the number of whole milliseconds of user time.
    cout << "elapsed interval (ms): " << static_cast<unsigned>(elapsedCounter.get_milliseconds()) << endl;
    // 7.a. Display the number of whole microseconds of user time.
    cout << "elapsed interval (us): " << static_cast<unsigned>(elapsedCounter.get_microseconds()) << endl;

    // 5.b. Display the number of whole seconds of user time.
    cout << "user interval (s):     " << static_cast<unsigned>(usageCounter.get_user_seconds()) << endl;
    // 6.b. Display the number of whole milliseconds of user time.
    cout << "user interval (ms):    " << static_cast<unsigned>(usageCounter.get_user_milliseconds()) << endl;
    // 7.b. Display the number of whole microseconds of user time.
    cout << "user interval (us):    " << static_cast<unsigned>(usageCounter.get_user_microseconds()) << endl;

    // 5.c. Display the number of whole seconds of kernel time.
    cout << "kernel interval (s):   " << static_cast<unsigned>(usageCounter.get_kernel_seconds()) << endl;
    // 6.c. Display the number of whole milliseconds of kernel time.
    cout << "kernel interval (ms):  " << static_cast<unsigned>(usageCounter.get_kernel_milliseconds()) << endl;
    // 7.c. Display the number of whole microseconds of kernel time.
    cout << "kernel interval (us):  " << static_cast<unsigned>(usageCounter.get_kernel_microseconds()) << endl;

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
