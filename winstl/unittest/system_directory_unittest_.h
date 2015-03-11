
#if !defined(WINSTL_INCL_WINSTL_HPP_SYSTEM_DIRECTORY)
# error This file cannot be directly included, and should only be included within winstl/system_directory.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_SYSTEM_DIRECTORY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_system_directory(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t   bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "system_directory", __FILE__);

            TCHAR       szSysDir[_MAX_PATH + 1];

            if(0 == ::GetSystemDirectory(&szSysDir[0], STLSOFT_NUM_ELEMENTS(szSysDir)))
            {
                r->report("Could not elicit system directory", __LINE__);
            }
            else
            {
                system_directory    sd;

                if(0 != lstrcmp(&szSysDir[0], sd.c_str()))
                {
                    r->report("system_directory instance returned wrong directory with c_str()", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_system_directory(test_winstl_system_directory);
    } // anonymous namespace

} // namespace unittest
