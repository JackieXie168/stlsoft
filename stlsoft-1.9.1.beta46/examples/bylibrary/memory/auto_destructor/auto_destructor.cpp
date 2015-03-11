/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/memory/auto_destructor/auto_destructor.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Memory library.
 *
 * Created:     15th September 2006
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


/* STLSoft Header Files */
#include <stlsoft/memory/auto_destructor.hpp>


/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class MyClass
{
public:
    MyClass(int i, int j)
        : m_i(i)
        , m_j(j)
    {}

public:
    int total() const
    {
        return m_i + m_j;
    }

private:
    int m_i;
    int m_j;
};

/* ////////////////////////////////////////////////////////////////////// */

stlsoft::return_value_destructor<MyClass> f(int i, int j)
{
    stlsoft::auto_destructor<MyClass>  adi(new MyClass(i, j));

    int total   =   adi->total();

    return adi;

} // The MyClass instance is deleted here

int main()
{
    try
    {
        stlsoft::auto_destructor<MyClass>  adi2 = f(1, 2);

        int total = adi2->total();

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
