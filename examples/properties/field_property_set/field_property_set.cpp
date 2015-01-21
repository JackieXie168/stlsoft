/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/properties/field_property_set/field_property_set.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Properties
 *              library's field_property_set component.
 *
 * Created:     10th June 2006
 * Updated:     10th June 2006
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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h> // for EXIT_FAILURE, EXIT_SUCCESS

/* /////////////////////////////////////////////////////////////////////////////
 * Classes
 */

class ClassWithReadOnlyProp
{
public: // Member Types
    typedef std::string     string_type;
    typedef int             index_type;

public: // Construction
    ClassWithReadOnlyProp(char const *instanceName, index_type instanceIndex)
        : name(instanceName)    // Property value can be initialised inside encloding class
        , index(1)              // Property value can be initialised inside encloding class
    {}

public: // Operations
    void ReBadge(char const *newInstanceName, index_type newInstanceIndex)
    {
        name    =   newInstanceName;    // Property value can be assigned inside encloding class
        index   =   newInstanceIndex;   // Property value can be assigned inside encloding class
    }

public: // Properties
    stlsoft::field_property_get<index_type, index_type, ClassWithReadOnlyProp>          index;
    stlsoft::field_property_get<string_type, string_type const&, ClassWithReadOnlyProp> name;
};

/* ////////////////////////////////////////////////////////////////////////// */

int main()
{
    ClassWithReadOnlyProp   c("Object-#1", 1);

    int                 index   =   c.index;    // Ok: access the value of the read-only property
    std::string const   &name   =   c.name;     // Ok: access the value of the read-only property

    c.index =   2;          // Compile error: cannnot write to the read-only property
    c.name  =   "new name"; // Compile error: cannnot write to the read-only property

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */
