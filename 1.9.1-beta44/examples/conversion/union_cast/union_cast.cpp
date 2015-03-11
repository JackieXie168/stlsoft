/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/conversion/union_cast/union_cast.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Conversion
 *              library's union_cast component.
 *
 * Created:     10th June 2006
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


/* STLSoft Header Files */
#include <stlsoft/conversion/union_cast.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

int main()
{

    short   *ps;
    int     i   =   stlsoft::union_cast<int>(ps);       // Ok: both same size
    double  d   =   stlsoft::union_cast<double>(ps);    // Compile error: different size


    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
