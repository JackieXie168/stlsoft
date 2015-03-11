
// Updated: 10th June 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_PERFORMANCE_HPP_PROCESSTIMES_COUNTER)
# error This file cannot be directly included, and should only be included within unixstl/performance/processtimes_counter.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_PERFORMANCE_HPP_PROCESSTIMES_COUNTER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_performance_processtimes_counter(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "performance/processtimes_counter", __FILE__);

            processtimes_counter counter_1;
            processtimes_counter counter_2;

            /* Check that the periods of two enclosing measured intervals are enclosed */
            counter_1.start();
            counter_2.start();
            counter_2.stop();
            counter_1.stop();

            if(counter_1.get_period_count() < counter_2.get_period_count())
            {
                r->report("Enclosed interval is reported longer than enclosing interval", __LINE__);
                bSuccess = false;
            }

            /* Check that the relationships between s, ms & us are valid */

            if( counter_1.get_seconds()      * 1000 != counter_1.get_milliseconds() &&
                counter_1.get_milliseconds() / 1000 != counter_1.get_seconds())
            {
                r->report("get_seconds() and get_milliseconds() report contradictory values", __LINE__);
                bSuccess = false;
            }

            if( counter_1.get_milliseconds() * 1000 != counter_1.get_microseconds() &&
                counter_1.get_microseconds() / 1000 != counter_1.get_milliseconds())
            {
                r->report("get_milliseconds() and get_microseconds() report contradictory values", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_performance_processtimes_counter(test_unixstl_performance_processtimes_counter);
    } // anonymous namespace

} // namespace unittest

