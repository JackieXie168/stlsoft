/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/properties/field_property_get/field_property_get.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Properties
 *              library's field_property_get component
 *
 * Created:     9th December 2006
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
#include <stlsoft/properties/field_properties.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class ClassWithFieldGetProperty
{
public: // Member Types
    typedef std::string     string_type;

public: // Construction
    explicit ClassWithFieldGetProperty(char const *name)
        : Name(name)        // Property value can be initialised inside encloding class
    {}

public: // Properties
    // A read-only internal field property, whose internal type is string_type, and
    // whose external type is string_type const&, whose name is Name
    stlsoft::field_property_get<string_type, string_type const&, ClassWithFieldGetProperty> Name;
};

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    ClassWithFieldGetProperty   c("date");

    cout << "Name:      " << c.Name << endl;

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
