
// Updated: 31st December 2005

#if !defined(RANGELIB_INCL_RANGELIB_HPP_EXCEPTIONS)
# error This file cannot be directly included, and should only be included within rangelib/exceptions.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_EXCEPTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_rangelib_exceptions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "exceptions", __FILE__);

            {
                range_exception rx1;

                if(0 != ::strcmp(rx1.what(), "Range exception"))
                {
                    r->report("Default construction failed", __LINE__);
                    bSuccess = false;
                }
            }

            {
                range_exception rx2("A custom message");

                if(0 != ::strcmp(rx2.what(), "A custom message"))
                {
                    r->report("Non-default construction failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_rangelib_exceptions(test_rangelib_exceptions);
    } // anonymous namespace

} // namespace unittest
