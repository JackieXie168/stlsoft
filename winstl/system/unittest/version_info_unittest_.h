
#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_VERSION_INFO)
# error This file cannot be directly included, and should only be included within winstl/system/version_info.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_VERSION_INFO */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_system_version_info(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "system/version_info", __FILE__);

            version_info            vi1("USER32");
            ss_size_t               l       =   vi1.Length();
            ss_size_t               vl      =   vi1.ValueLength();
            ss_size_t               t       =   vi1.Type();
            wchar_t const           *key    =   vi1.Key();
            fixed_file_info         ffi     =   vi1.FixedFileInfo();

            STLSOFT_SUPPRESS_UNUSED(l);
            STLSOFT_SUPPRESS_UNUSED(vl);
            STLSOFT_SUPPRESS_UNUSED(t);
            STLSOFT_SUPPRESS_UNUSED(key);
            STLSOFT_SUPPRESS_UNUSED(ffi);

            if(vi1.HasVarFileInfo())
            {
                VsVarFileInfo       vfi =   vi1.VarFileInfo();

                VsVarFileInfo::const_iterator   b   =   vfi.begin();
                VsVarFileInfo::const_iterator   e   =   vfi.end();

                for(; b != e; ++b)
                {
                    VsVar   var =   *b;

                    for(size_t i = 0; i < var.length(); ++i)
                    {
                        VsVar::LangCodePage lcp =   var[i];

                        STLSOFT_SUPPRESS_UNUSED(lcp);
                    }
                }
            }

            if(vi1.HasStringFileInfo())
            {
                VsStringFileInfo    sfi =   vi1.StringFileInfo();

                VsStringFileInfo::const_iterator    b   =   sfi.begin();
                VsStringFileInfo::const_iterator    e   =   sfi.end();

                for(; b != e; ++b)
                {
                    VsStringTable   st  =   *b;

                    VsStringTable::const_iterator   b   =   st.begin();
                    VsStringTable::const_iterator   e   =   st.end();

                    for(; b != e; ++b)
                    {
                        VsString    str =   *b;

                        str.name();
                        str.value();
                    }
                }
            }

    #if 0
            if(  )
            {
                r->report("construct() failed", __LINE__);
                bSuccess = false;
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_system_version_info(test_winstl_system_version_info);
    } // anonymous namespace

} // namespace unittest
