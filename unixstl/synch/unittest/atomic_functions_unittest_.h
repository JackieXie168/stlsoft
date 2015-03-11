
// Updated: 30th May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS)
# error This file cannot be directly included, and should only be included within unixstl/synch/atomic_functions.h
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_synch_atomic_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "synch/atomic_functions", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_synch_atomic_functions(test_unixstl_synch_atomic_functions);
    } // anonymous namespace

}// namespace unittest
