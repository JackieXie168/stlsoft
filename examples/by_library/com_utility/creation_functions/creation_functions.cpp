/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/creation_functions/creation_functions.cpp
 *
 * Purpose:     C++ example program demonstrating use the COMSTL
 *              creation functions.
 *
 * Created:     13th December 2006
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


/* COMSTL Header Files */
#include <comstl/conversion/interface_cast.hpp>
#include <comstl/error/errorinfo_desc.hpp>
#include <comstl/util/creation_functions.hpp>
#include <comstl/util/initialisers.hpp>

/* STLSoft Header Files */
#include <stlsoft/smartptr/ref_ptr.hpp>

/* PlatformSTL Header Files */
#include <platformstl/error/error_desc.hpp>

/* Pantheios.COM Header Files - available from http://pantheios.org/ */
#include "pantheios.COM.h"

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void CreateLoggersAndLog(ILoggerManager *plogmgr, char const *message);

/* ////////////////////////////////////////////////////////////////////// */

static int main_()
{
    // (i) Create an instance of Pantheios.COM.LoggerManager into a pointer,
    //  by specifying the CLSID
    {
        ILoggerManager *plogmgr;
        if(SUCCEEDED(comstl::co_create_instance(CLSID_LoggerManager, &plogmgr)))
        {
			CreateLoggersAndLog(plogmgr, "example 1");

            plogmgr->Release();
        }
    }

    // (ii) Create an instance of Pantheios.COM.LoggerManager into a pointer,
    //  by specifying a text form of the CLSID
    {
        ILoggerManager *plogmgr;
        if(SUCCEEDED(comstl::co_create_instance(L"{4E7D5C47-8F96-45DE-905D-AA3E9E592DE3}", &plogmgr)))
        {
			CreateLoggersAndLog(plogmgr, "example 2");

            plogmgr->Release();
        }
    }

    // (iii) Create an instance of Pantheios.COM.LoggerManager into a pointer,
    //  by specifying the ProgID
    {
        ILoggerManager *plogmgr;
        if(SUCCEEDED(comstl::co_create_instance(L"pantheios.COM.LoggerManager", &plogmgr)))
        {
			CreateLoggersAndLog(plogmgr, "example 3");

            plogmgr->Release();
        }
    }

    // (iv) Create an instance of Pantheios.COM.LoggerManager into a wrapper
    //  instance, by specifying the CLSID
    {
        stlsoft::ref_ptr<ILoggerManager>   logmgr;
        if(SUCCEEDED(comstl::co_create_instance(CLSID_LoggerManager, logmgr)))
        {
			CreateLoggersAndLog(logmgr.get(), "example 4");
            
        } // Release() automatically invoked here
    }

    // (v) Create an instance of Pantheios.COM.LoggerManager into a pointer,
    //  by specifying a text form of the CLSID
    {
        stlsoft::ref_ptr<ILoggerManager>   logmgr;
        if(SUCCEEDED(comstl::co_create_instance(L"{4E7D5C47-8F96-45DE-905D-AA3E9E592DE3}", logmgr)))
        {
			CreateLoggersAndLog(logmgr.get(), "example 5");

        } // Release() automatically invoked here
    }

    // (vi) Create an instance of Pantheios.COM.LoggerManager into a pointer,
    //  by specifying the ProgID
    {
        stlsoft::ref_ptr<ILoggerManager>   logmgr;
        if(SUCCEEDED(comstl::co_create_instance(L"pantheios.COM.LoggerManager", logmgr)))
        {
			CreateLoggersAndLog(logmgr.get(), "example 6");

        } // Release() automatically invoked here
    }

    return EXIT_SUCCESS;
}

int main()
{
    try
    {
        // Initialise the COM libraries
        comstl::com_initialiser coinit;

        return main_();
    }
    catch(std::exception &x)
    {
        cerr << "Unhandled error: " << x.what() << endl;

        return EXIT_FAILURE;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;

        return EXIT_FAILURE;
    }
}

/* ////////////////////////////////////////////////////////////////////// */

static void CreateLoggersAndLog(ILoggerManager *plogmgr, char const *message)
{
	stlsoft::ref_ptr<ILoggerManagerMultibyte>	logmgrmb = comstl::interface_cast<ILoggerManagerMultibyte>(plogmgr);

	VARIANT	initArguments;
	VARIANT	filterSpec;

	::VariantInit(&initArguments);
	::VariantInit(&filterSpec);

	ILogger	*plogger;
	HRESULT	hr	=	logmgrmb->GetLoggerMultibyte("Console", "creation_functions example", initArguments, filterSpec, &plogger);

	if(SUCCEEDED(hr))
	{
		stlsoft::ref_ptr<ILogger>			logger(plogger, false); // Consume the reference
		stlsoft::ref_ptr<ILoggerMultibyte>	loggermb = comstl::interface_cast<ILoggerMultibyte>(logger);

		loggermb->LogMultibyte(5, message);
	}
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

const CLSID CLSID_LoggerManager = { 0x4E7D5C47, 0x8F96, 0x45DE, { 0x90, 0x5D, 0xAA, 0x3E, 0x9E, 0x59, 0x2D, 0xE3 } };

/* ////////////////////////////////////////////////////////////////////// */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

