
#if !defined(RANGELIB_INCL_RANGELIB_HPP_FILTERED_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/filtered_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_FILTERED_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_rangelib_filtered_range(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "filtered_range", __FILE__);

#if 0
            if(NULL != pi1)
            {
                ator1.construct(pi1, 1968);

                if(1968 != *pi1)
                {
                    r->report("construct() failed ", __LINE__);
                    bSuccess = false;
                }
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_rangelib_filtered_range(test_rangelib_filtered_range);
    } // anonymous namespace

} // namespace unittest
