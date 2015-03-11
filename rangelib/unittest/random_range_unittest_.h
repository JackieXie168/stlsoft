
#if !defined(RANGELIB_INCL_RANGELIB_HPP_RANDOM_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/random_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANDOM_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {

        ss_bool_t test_stlsoft_rangelib_random_range(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "random_range", __FILE__);

            random_range    r1(10, -10, 10);
            int             sum;

            STLSOFT_ASSERT(-10 == r1.minimum());
            STLSOFT_ASSERT(+10 == r1.maximum());

            for(sum = 0; r1; ++r1)
            {
                STLSOFT_ASSERT(*r1 >= r1.minimum());
                STLSOFT_ASSERT(*r1 <= r1.maximum());

                sum += *r1;
            }

            if( sum < 10 * r1.minimum() ||
                sum >= 10 * r1.maximum())
            {
                r->report("manual enumeration failed", __LINE__);
                bSuccess = false;
            }

            if(r1.is_open())
            {
                r->report("closed range presents as open (is_open() method)", __LINE__);
                bSuccess = false;
            }

            if(r1)
            {
                r->report("closed range presents as open (operator \"bool\"())", __LINE__);
                bSuccess = false;
            }

            if(random_range(0, 0, 0))
            {
                r->report("closed range presents as open", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_rangelib_random_range(test_stlsoft_rangelib_random_range);
    } // anonymous namespace

} // namespace unittest

