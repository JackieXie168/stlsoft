
// Updated: 14th January 2007

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SEMAPHORE)
# error This file cannot be directly included, and should only be included within unixstl/synch/semaphore.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SEMAPHORE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_synch_semaphore(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "synch/semaphore", __FILE__);

			try
			{
				semaphore				sem(1);

				sem.lock();
				sem.unlock();
			}
			catch(synchronisation_exception &x)
			{
				if(r->verbosity() > 1)
				{
					r->report(x.what(), __LINE__);
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_synch_semaphore(test_unixstl_synch_semaphore);
	} // anonymous namespace

} // namespace unittest
