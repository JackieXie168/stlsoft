
// Updated: 17th September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_DIRECTORY_FUNCTIONS)
# error This file cannot be directly included, and should only be included within unixstl/directory_functions.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_DIRECTORY_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_directory_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "directory_functions", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_directory_functions(test_unixstl_directory_functions);
    } // anonymous namespace

} // namespace unittest
