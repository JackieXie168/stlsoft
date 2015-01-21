
// Updated: 31st May 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/filesystem/directory_functions.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_filesystem_directory_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "filesystem/directory_functions", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_filesystem_directory_functions(test_winstl_filesystem_directory_functions);
    } // anonymous namespace

} // namespace unittest
