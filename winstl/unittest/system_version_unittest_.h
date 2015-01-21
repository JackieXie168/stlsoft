
// Updated: 19th September 2005

#if !defined(WINSTL_INCL_WINSTL_HPP_SYSTEM_VERSION)
# error This file cannot be directly included, and should only be included within winstl/system_version.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_SYSTEM_VERSION */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_system_version(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "system_version", __FILE__);

            ws_bool_t   bIsWinNT    =   system_version::winnt();
            ws_bool_t   bIsWin9x    =   system_version::win9x();
            ws_bool_t   bIsWin32s   =   system_version::win32s();

            if( bIsWinNT &&
                bIsWin9x)
            {
                r->report("system version reported as both 9x and NT", __LINE__);
                bSuccess = false;
            }

            if( !bIsWinNT &&
                !bIsWin9x &&
                !bIsWin32s)
            {
                r->report("system version reported as none of 9x, NT, Win32s", __LINE__);
                bSuccess = false;
            }

            const DWORD dwVersion   =   ::GetVersion();

            if(0x80000000 == (0x80000000 & dwVersion))
            {
                if(!bIsWin9x)
                {
                    r->report("failed to recognise 9x system", __LINE__);
                    bSuccess = false;
                }
            }
            else
            {
                if(bIsWin9x)
                {
                    r->report("system version incorrectly recognised system as 9x", __LINE__);
                    bSuccess = false;
                }
            }

            const ws_uint_t verMajor    =   system_version::major();
            const ws_uint_t verMinor    =   system_version::minor();
            const ws_uint_t verBuildNum =   system_version::build_number();

            if(verMajor != (DWORD)(LOBYTE(LOWORD(dwVersion))))
            {
                r->report("incorrectly reported system major version", __LINE__);
                bSuccess = false;
            }

            if(verMinor != (DWORD)(HIBYTE(LOWORD(dwVersion))))
            {
                r->report("incorrectly reported system major version", __LINE__);
                bSuccess = false;
            }

            if(0x00000000 == (0x80000000 & dwVersion))
            {
                if(verBuildNum != (DWORD)(HIWORD(dwVersion)))
                {
                    r->report("incorrectly reported system build number", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_system_version(test_winstl_system_version);
    } // anonymous namespace

} // namespace unittest
