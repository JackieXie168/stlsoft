
#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/file_path_buffer.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_filesystem_file_path_buffer(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "filesystem/file_path_buffer", __FILE__);

            file_path_buffer_a      buf_a;

#ifdef PATH_MAX
            if(1 + PATH_MAX != buf_a.size())
#else /* ? PATH_MAX */
            if(static_cast<ss_size_t>(1 + 1 + pathconf("/", _PC_PATH_MAX)) != buf_a.size())
#endif /* PATH_MAX */
            {
                r->report("ANSI buffer size incorrect", __LINE__);
                bSuccess = false;
            }

            file_path_buffer_w      buf_w;

#ifdef PATH_MAX
            if(1 + PATH_MAX != buf_w.size())
#else /* ? PATH_MAX */
            if(static_cast<ss_size_t>(1 + 1 + pathconf("/", _PC_PATH_MAX)) != buf_w.size())
#endif /* PATH_MAX */
            {
                r->report("Unicode (Win9x) buffer size incorrect", __LINE__);
                bSuccess = false;
            }

            // This is a bogus comparison, serving just to delude the compiler that the
            // unreachable call to the defaulted grow() is reachable.
            if(!buf_a.grow(buf_a.size()))
            {
                buf_a.grow();
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_filesystem_file_path_buffer(test_unixstl_filesystem_file_path_buffer);
    } // anonymous namespace

} // namespace unittest
