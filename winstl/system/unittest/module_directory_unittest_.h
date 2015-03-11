
#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY)
# error This file cannot be directly included, and should only be included within winstl/system/module_directory.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_system_module_directory(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "system/module_directory", __FILE__);

            HINSTANCE               hinst   =   ::GetModuleHandle(NULL);

            //
            if(module_directory_a(hinst).length() != module_directory_w(hinst).length())
            {
                r->report("Disagreement on length() between ANSI and Unicode instantiations", __LINE__);
                bSuccess = false;
            }

            module_directory        mw(hinst);

            //
            if(module_directory_a(hinst).length() != module_directory_w(hinst).length())
            {
                r->report("Disagreement on length() between ANSI and Unicode instantiations", __LINE__);
                bSuccess = false;
            }

            module_directory::size_type cch     =   module_directory::get_path(hinst, static_cast<ws_char_a_t*>(NULL), 0);
            char                        *buff   =   (char*)malloc(1 + cch);

            if(NULL == buff)
            {
                r->report("Could not allocate buffer", __LINE__);
                bSuccess = false;
            }
            else
            {
                module_directory::get_path(hinst, buff, 1 + cch);

                if(0 != strcmp(buff, mw.get_path()))
                {
                    r->report("Disagreement on contents between get_path (static) and get_path()", __LINE__);
                    bSuccess = false;
                }

                if(0 != strcmp(buff, mw.c_str()))
                {
                    r->report("Disagreement on contents between get_path (static) and c_str()", __LINE__);
                    bSuccess = false;
                }

                if(0 != strcmp(buff, mw))
                {
                    r->report("Disagreement on contents between get_path (static) and implicit conversion operator", __LINE__);
                    bSuccess = false;
                }

                free(buff);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_system_module_directory(test_winstl_system_module_directory);
    } // anonymous namespace

} // namespace unittest
