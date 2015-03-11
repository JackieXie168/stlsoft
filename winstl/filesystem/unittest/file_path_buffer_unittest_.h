
// Updated: 31st May 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER)
# error This file cannot be directly included, and should only be included within winstl/file_path_buffer.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_file_path_buffer(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "filesystem/file_path_buffer", __FILE__);

            basic_file_path_buffer<char>    buf_a;
            basic_file_path_buffer<char>    buf_a_2(buf_a);
            basic_file_path_buffer<char>    buf_a_3;

            buf_a_3 = buf_a;

            if(1 + _MAX_PATH != buf_a.size())
            {
                r->report("ANSI buffer size incorrect", __LINE__);
                bSuccess = false;
            }

            file_path_buffer_w      buf_w;

    //printf("a: %d\n", buf_a.size());
    //printf("w: %d\n", buf_w.size());

            if(::GetVersion() & 0x80000000)
            {
                if(1 + _MAX_PATH != buf_w.size())
                {
                    r->report("Unicode (Win9x) buffer size incorrect", __LINE__);
                    bSuccess = false;
                }
            }
            else
            {
                if(1 + CONST_NT_MAX_PATH != buf_w.size())
                {
                    r->report("Unicode (Win NT) buffer size incorrect", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_file_path_buffer(test_winstl_file_path_buffer);
    } // anonymous namespace

} // namespace unittest
