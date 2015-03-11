/* /////////////////////////////////////////////////////////////////////////
 * File:        by_library/properties/properties/properties.cpp
 *
 * Purpose:     C++ example program demonstrating use of the Properties
 *              library's field_property_get and
 *              method_property_getset_external components.
 *
 * Created:     10th June 2006
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
#include <stlsoft/properties/method_properties.hpp>

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

class ClassWithProperties
{
public: // Member Types
    typedef std::string     string_type;
    typedef int             index_type;

public: // Construction
    ClassWithProperties(char const *name, char const *value)
        : Name(name)        // Property value can be initialised inside encloding class
        , m_value(value)    // Property value can be initialised inside encloding class
    {}

public: // Operations
    string_type get_Value() const
    {
        return m_value;
    }
    void        set_Value(char const *newValue)
    {
        if( NULL == newValue ||
            '\0' == *newValue)
        {
            throw std::runtime_error("Invalid value of Value");
        }
        else
        {
            m_value = newValue;
        }
    }

public: // Properties
    // A read-only internal field property, whose internal type is string_type, and
    // whose external type is string_type const&, whose name is Name
    stlsoft::field_property_get<string_type, string_type const&, ClassWithProperties> Name;

    // A read/write external method property, whose get-type is string_type
    // and set-type is char const*, whose name is Value. When reading the
    // value of the property, the method get_Value is invoked. When writing
    // the value of the property, the method set_Value - which validates the
    // new name - is invoked.
    STLSOFT_METHOD_PROPERTY_GETSET_EXTERNAL(string_type, char const*, ClassWithProperties, get_Value, set_Value, Value);

private: // Members
    string_type m_value;
};

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    ClassWithProperties c("date", "today");

    cout << "Name:      " << c.Name << endl;
    cout << "Value:     " << c.Value << endl;

    cout << "Changing the value" << endl;

    c.Value = "tomorrow";

    cout << "New Value: " << c.Value << endl;

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////// */
