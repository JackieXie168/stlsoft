
#if !defined(WINSTL_INCL_WINSTL_HPP_MODULE_FILENAME)
# error This file cannot be directly included, and should only be included within winstl/module_filename.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_MODULE_FILENAME */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_module_filename(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "module_filename", __FILE__);

            TCHAR   mfn[1 + _MAX_PATH];

            ::GetModuleFileName(NULL, &mfn[0], stlsoft_num_elements(mfn));

            if(0 != ::lstrcmp(mfn, module_filename()))
            {
                r->report("module filename failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_module_filename(test_winstl_module_filename);
    } // anonymous namespace

} // namespace unittest
