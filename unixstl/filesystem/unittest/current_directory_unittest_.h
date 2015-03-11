
// Updated: 30th May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY)
# error This file cannot be directly included, and should only be included within unixstl/current_directory.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_filesystem_current_directory(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "filesystem/current_directory", __FILE__);

            typedef basic_current_directory<char>   curr_dir_t;

            basic_file_path_buffer<char>    sz;
            curr_dir_t                      cd;

            getcwd(&sz[0], sz.size());

            if(0 != strcmp(sz.c_str(), cd.c_str()))
            {
                r->report("basic_current_directory<char> failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_filesystem_current_directory(test_unixstl_filesystem_current_directory);
    } // anonymous namespace

}// namespace unittest
