
#if !defined(WINSTL_INCL_WINSTL_HPP_MODULE)
# error This file cannot be directly included, and should only be included within winstl/module.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_MODULE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_module(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "module", __FILE__);

            module                  m1("KERNEL32");
            module                  m2(L"KERNEL32");
            module                  m3(m1);

            if(m1.get_handle() != m2.get_handle())
            {
                r->report("copy construction failed", __LINE__);
                bSuccess = false;
            }

            module::proc_pointer    pfnCloseHandle1 =   m1.get_symbol("CloseHandle");
            module::proc_pointer    pfnCloseHandle2 =   m1.get_symbol(1);

            typedef BOOL (WINAPI *Pfn)(HANDLE);

            Pfn                     pfn1;
            Pfn                     pfn2;

            if(pfnCloseHandle1 != m1.get_symbol("CloseHandle", pfn1))
            {
                r->report("copy construction failed", __LINE__);
                bSuccess = false;
            }

            if(pfnCloseHandle2 != m1.get_symbol(1, pfn2))
            {
                r->report("copy construction failed", __LINE__);
                bSuccess = false;
            }

            m2.unload();

            if(NULL != m2.get_handle())
            {
                r->report("unload() failed", __LINE__);
                bSuccess = false;
            }

            module                  m4(m1);

            HINSTANCE               h4  =   m2.detach();

            ::FreeLibrary(h4);

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_module(test_winstl_module);
    } // anonymous namespace

} // namespace unittest
