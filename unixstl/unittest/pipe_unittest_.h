
// Updated: 2nd September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_PATH)
# error This file cannot be directly included, and should only be included within unixstl/path.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_PATH */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_pipe(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "pipe", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_pipe(test_unixstl_pipe);
    } // anonymous namespace

}// namespace unittest
