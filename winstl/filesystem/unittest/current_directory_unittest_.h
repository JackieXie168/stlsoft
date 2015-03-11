
#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY)
# error This file cannot be directly included, and should only be included within winstl/current_directory.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_current_directory(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "filesystem/current_directory", __FILE__);

            typedef basic_current_directory<char>   curr_dir_t;

            char        sz[1 + _MAX_PATH];
            curr_dir_t  cd;

            ::GetCurrentDirectoryA(STLSOFT_NUM_ELEMENTS(sz), sz);

            if(0 != strcmp(sz, cd))
            {
                r->report("basic_current_directory<char> failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_current_directory(test_winstl_current_directory);
    } // anonymous namespace

} // namespace unittest
