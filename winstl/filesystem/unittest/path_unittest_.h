
// Updated: 1st June 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH)
# error This file cannot be directly included, and should only be included within winstl/filesystem/path.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_filesystem_path(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "filesystem/path", __FILE__);

            path_a  path1("..");
            path_a  path2(".\\..\\.\\.\\lower\\..");

            if(!path1.equivalent(path2))
            {
                r->report("equivalence test failed", __LINE__);
                bSuccess = false;
            }

            path_a  path3(path1);

            if(path1 != path3)
            {
                r->report("copy-construction failed", __LINE__);
                bSuccess = false;
            }

            path3 /= "sub1";

            path_a  path4("..\\sub1");

            if(path4 != path3)
            {
                r->report("concatenation failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_filesystem_path(test_winstl_filesystem_path);
    } // anonymous namespace

} // namespace unittest
