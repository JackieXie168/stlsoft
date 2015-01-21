
// Updated: 31st May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/filesystem_traits.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        typedef filesystem_traits<char>     traits_a_t;
        typedef filesystem_traits<wchar_t>  traits_w_t;

        ss_bool_t test_get_full_path_name(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            char        sz1[1 + 4096];
            char        sz2[1 + 4096];
            char        cwd[1 + 4096];

            if(NULL == getcwd(cwd, STLSOFT_NUM_ELEMENTS(cwd)))
            {
                r->report("Failed to get current directory", __LINE__);
                bSuccess = false;
            }
            else
            {
                char        *pFile1;
                char        *pFile2;
                ss_size_t   cch1    =   traits_a_t::get_full_path_name(".", STLSOFT_NUM_ELEMENTS(sz1), sz1, &pFile1);
                ss_size_t   cch2    =   traits_a_t::get_full_path_name(cwd, STLSOFT_NUM_ELEMENTS(sz2), sz2, &pFile2);

                STLSOFT_SUPPRESS_UNUSED(cch1);
                STLSOFT_SUPPRESS_UNUSED(cch2);

                if( 0 != traits_a_t::str_compare(sz1, sz2) ||
                    0 != traits_a_t::str_compare(pFile1, pFile2))
                {
                    r->report("Directory equivalence failed", __LINE__);
                    bSuccess = false;
                }

                traits_a_t::str_cat(traits_a_t::ensure_dir_end(cwd), "../..");

                cch1    =   traits_a_t::get_full_path_name("../..", STLSOFT_NUM_ELEMENTS(sz1), sz1, &pFile1);
                cch2    =   traits_a_t::get_full_path_name(cwd, STLSOFT_NUM_ELEMENTS(sz2), sz2, &pFile2);

                STLSOFT_SUPPRESS_UNUSED(cch1);
                STLSOFT_SUPPRESS_UNUSED(cch2);

                if( 0 != traits_a_t::str_compare(sz1, sz2) ||
                    0 != traits_a_t::str_compare(pFile1, pFile2))
                {
                    r->report("Directory equivalence failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }


        ss_bool_t test_unixstl_filesystem_filesystem_traits(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "filesystem/filesystem_traits", __FILE__);

            // (i) get_full_path_name()
            if(bSuccess)
            {
                bSuccess = test_get_full_path_name(r);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_filesystem_filesystem_traits(test_unixstl_filesystem_filesystem_traits);
    }

}// namespace unittest
