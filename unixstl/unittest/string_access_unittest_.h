
// Updated: 2nd September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within unixstl/string_access.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_string_access(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "string_access", __FILE__);

            struct dirent   de;

            strcpy(de.d_name, "/home/stlsoft");

            if(0 != strcmp("/home/stlsoft", c_str_ptr(de)))
            {
                r->report("c_str_ptr(dirent &) failed", __LINE__);
                bSuccess = false;
            }

            if(0 != strcmp("/home/stlsoft", c_str_ptr(&de)))
            {
                r->report("c_str_ptr(dirent *) failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_string_access(test_unixstl_string_access);
    } // anonymous namespace

}// namespace unittest
