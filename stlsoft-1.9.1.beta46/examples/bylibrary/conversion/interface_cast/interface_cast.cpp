/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/conversion/interface_cast/interface_cast.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Conversion
 *              library's interface_cast component.
 *
 * Created:     9th December 2006
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


/* COMSTL Header Files */
#include <comstl/conversion/interface_cast.hpp>

/* STLSoft Header Files */
#include <stlsoft/smartptr/ref_ptr.hpp>

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
    try
    {
        /* Get a stream to play with ... */
        LPSTREAM    pstm;
        HRESULT     hr = ::CreateStreamOnHGlobal(NULL, true, &pstm);

        if(SUCCEEDED(hr))
        {
            stlsoft::ref_ptr<IStream>   stm(pstm, false);   /* Eat the reference */

            /* Can the pointer be cast to IStorage*? */
            if(comstl::interface_cast_test<IStorage*>(pstm))
            {
				comstl::interface_cast_noaddref<IStorage*>->SetClass(CLSID_NULL);

				comstl::interface_cast_noaddref<IStorage*>->SetClass(CLSID_NULL);
            }

            /* Can the wrapper be cast to IStorage*? */
            if(comstl::interface_cast_test<IStorage*>(stm))
            {
				// . . .
            }

        }
    }

    short   *ps;
    int     i   =   stlsoft::interface_cast<int>(ps);       // Ok: both same size
    double  d   =   stlsoft::interface_cast<double>(ps);    // Compile error: different size


    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
