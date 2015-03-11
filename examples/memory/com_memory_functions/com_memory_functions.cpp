/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/memory/com_memory_functions/com_memory_functions.cpp
 *
 * Purpose:     C++ example program demonstrating use of the COMSTL 
 *              memory functions.
 *
 * Created:     9th December 2006
 * Updated:     9th December 2006
 *
 * Status:      Wizard-generated
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
#include <comstl/memory/functions.h>
#include <comstl/util/initialisers.hpp>

/* WinSTL Header Files */
#include <winstl/error/error_desc.hpp>

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
		/* Initialise the COM libraries with the com_init scoping class */
		comstl::com_init	init;

        void    *p1 =   CoTaskMemAlloc(10);
        void    *p2 =   CoTaskMemAlloc(10000);
        void    *p3 =   CoTaskMemAlloc(0);
        void    *p4 =   CoTaskMemAlloc(2000000000);

        if(NULL == p1)
        {
            cerr << "Failed to allocate 10 bytes: " << winstl::error_desc_a() << endl;
        }
        else
        {
            WINSTL_ASSERT(comstl::CoTaskMemDidAlloc(p1));
        }

        if(NULL == p2)
        {
            cerr << "Failed to allocate 10000 bytes: " << winstl::error_desc_a() << endl;
        }
        else
        {
            WINSTL_ASSERT(comstl::CoTaskMemDidAlloc(p2));
        }

        if(NULL == p3)
        {
            cerr << "Failed to allocate 0 bytes: " << winstl::error_desc_a() << endl;
        }
        else
        {
            WINSTL_ASSERT(comstl::CoTaskMemDidAlloc(p3));
        }

        if(NULL == p4)
        {
            cerr << "Failed to allocate 2000000000 bytes: " << winstl::error_desc_a() << endl;
        }
        else
        {
            WINSTL_ASSERT(comstl::CoTaskMemDidAlloc(p4));
        }

        size_t  cb1 =   comstl::CoTaskMemGetSize(p1);
        size_t  cb2 =   comstl::CoTaskMemGetSize(p2);
        size_t  cb3 =   comstl::CoTaskMemGetSize(p3);
        size_t  cb4 =   comstl::CoTaskMemGetSize(p4);

        p1  =   CoTaskMemRealloc(p1, 0);
        p2  =   CoTaskMemRealloc(p2, 1);
        p3  =   CoTaskMemRealloc(p3, 100);
        p4  =   CoTaskMemRealloc(p4, 10000);

        cb1 =   comstl::CoTaskMemGetSize(p1);
        cb2 =   comstl::CoTaskMemGetSize(p2);
        cb3 =   comstl::CoTaskMemGetSize(p3);
        cb4 =   comstl::CoTaskMemGetSize(p4);

        CoTaskMemFree(p1);
        CoTaskMemFree(p2);
        CoTaskMemFree(p3);
        CoTaskMemFree(p4);

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
