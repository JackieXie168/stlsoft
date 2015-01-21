
#if !defined(WINSTL_INCL_WINSTL_HPP_DL_CALL)
# error This file cannot be directly included, and should only be included within winstl/dl_call.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_DL_CALL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_dl_call(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "dl_call", __FILE__);

            // 1. Try something we "know" will work: KERNEL32:GetTickCount
            {
                try
                {
                    dl_call<DWORD>("KERNEL32.DLL", "S:GetTickCount");
                }
                catch(std::exception &)
                {
                    r->report("Unable to invoke \"GetTickCount()\" in \"KERNEL32\"", __LINE__);
                }
            }

            // 2. Try something we "know" will not work
            {
                try
                {
                    dl_call<int>("abcdefghijklmnopqrstuvwxyz.012", "asrfsdfsdlkjdslfkjsldkjfs098sdf)(*(");

                    r->report("Failed to detect bad dl_call() invocation", __LINE__);
                    bSuccess = false;
                }
                catch(std::exception &)
                {
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_dl_call(test_winstl_dl_call);
    } // anonymous namespace

} // namespace unittest
