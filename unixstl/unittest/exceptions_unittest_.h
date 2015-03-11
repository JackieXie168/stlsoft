
// Updated: 2nd September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS)
# error This file cannot be directly included, and should only be included within unixstl/exceptions.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_exceptions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "exceptions", __FILE__);

            unix_exception          x1(ENOMEM);
            unix_exception          x2(ENOENT);

            x1.what();
            x1.get_error_code();
            x1.get_errno();
            x1.strerror();

            x2.what();
            x2.get_error_code();
            x2.get_errno();
            x2.strerror();

            unix_exception          x3(x1);
            unix_exception          x4(x2);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_exceptions(test_unixstl_exceptions);
    } // anonymous namespace

}// namespace unittest
