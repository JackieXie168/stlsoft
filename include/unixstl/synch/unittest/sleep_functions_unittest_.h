
// Updated: 14th January 2007

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS)
# error This file cannot be directly included, and should only be included within unixstl/synch/sleep_functions.h
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_synch_sleep_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "synch/sleep_functions", __FILE__);

			if(!micro_sleep(10))
			{
				r->report("unixstl::micro_sleep(10) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_synch_sleep_functions(test_unixstl_synch_sleep_functions);
	} // anonymous namespace

}// namespace unittest
