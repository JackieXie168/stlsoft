
#if !defined(WINSTL_INCL_WINSTL_HPP_WINDOWS_DIRECTORY)
# error This file cannot be directly included, and should only be included within winstl/windows_directory.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOWS_DIRECTORY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_windows_directory(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "windows_directory", __FILE__);

            windows_directory_a win_dir_a_1;
            windows_directory_a win_dir_a_2;
            windows_directory_w win_dir_w_1;
            windows_directory_w win_dir_w_2;
            WCHAR               wszBuffer[_MAX_PATH];

            if( !win_dir_a_1.is_valid_() ||
                !win_dir_a_2.is_valid_() ||
                !win_dir_w_1.is_valid_() ||
                !win_dir_w_2.is_valid_())
            {
                r->report("Class invariant fails for one or more instances", __LINE__);
                bSuccess = false;
            }

            if(0 != lstrcmpiA(win_dir_a_1, win_dir_a_2))
            {
                r->report("Two (ANSI) instances do not report same Windows directory", __LINE__);
                bSuccess = false;
            }

            if(0 != lstrcmpiW(win_dir_w_1, win_dir_w_2))
            {
                r->report("Two (Unicode) instances do not report same Windows directory", __LINE__);
                bSuccess = false;
            }

            if( 0 == ::MultiByteToWideChar(0, 0, win_dir_a_1, -1, wszBuffer, stlsoft_num_elements(wszBuffer)) ||
                0 != lstrcmpiW(wszBuffer, win_dir_w_1))
            {
                r->report("ANSI and Unicode instances do not report same Windows directory", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_windows_directory(test_winstl_windows_directory);
    } // anonymous namespace

} // namespace unittest
