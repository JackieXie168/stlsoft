
// Updated: 1st June 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX)
# error This file cannot be directly included, and should only be included within unixstl/synch/spin_mutex.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_synch_spin_mutex(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "synch/spin_mutex", __FILE__);

			spin_mutex::atomic_int_type i	=	0;
			spin_mutex					mx(&i);

			mx.lock();
			if(1 != mx.spun_count())
			{
				r->report("lock() - unlock() sequence failed: wrong spun count", __LINE__);
				bSuccess = false;
			}
			mx.unlock();
			if(0 != mx.spun_count())
			{
				r->report("lock() - unlock() sequence failed: wrong spun count", __LINE__);
				bSuccess = false;
			}

			if(0 != i)
			{
				r->report("lock() - unlock() sequence failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_synch_spin_mutex(test_unixstl_synch_spin_mutex);
	} // anonymous namespace

} // namespace unittest
