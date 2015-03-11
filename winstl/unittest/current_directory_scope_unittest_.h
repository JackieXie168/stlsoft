
#if !defined(WINSTL_INCL_WINSTL_HPP_CURRENT_DIRECTORY_SCOPE)
# error This file cannot be directly included, and should only be included within winstl/current_directory_scope.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_CURRENT_DIRECTORY_SCOPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_current_directory_scope(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "current_directory_scope", __FILE__);

            typedef basic_current_directory_scope<char>     current_directory_scope;

            {
                char    szCwd[1 + _MAX_PATH];
                char    szRoot[1 + _MAX_PATH];
                char    *lpFilePart;

                ::GetCurrentDirectoryA(STLSOFT_NUM_ELEMENTS(szCwd), szCwd);
                ::GetFullPathNameA("\\", STLSOFT_NUM_ELEMENTS(szRoot), szRoot, &lpFilePart);

                current_directory_scope cds(szRoot);

                if(0 != strcmp(szCwd, cds.get_previous()))
                {
                    r->report("current_directory_scope failed", __LINE__);
                    bSuccess = false;
                }

                {
                    current_directory_scope cds2(szCwd);

                    if(0 != strcmp(szRoot, cds2.get_previous()))
                    {
                        r->report("current_directory_scope failed", __LINE__);
                        bSuccess = false;
                    }
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_current_directory_scope(test_winstl_current_directory_scope);
    } // anonymous namespace

} // namespace unittest
