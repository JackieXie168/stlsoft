
// Updated: 30th May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_THREAD_MUTEX)
# error This file cannot be directly included, and should only be included within unixstl/synch/thread_mutex.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_THREAD_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_synch_thread_mutex(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "synch/thread_mutex", __FILE__);

			thread_mutex	mx_r(true);

			mx_r.lock();
			if(!mx_r.try_lock())
			{
				r->report("thread_mutex (recursive) could not lock recursively ", __LINE__);
				bSuccess = false;
			}
			else
			{
				mx_r.unlock();
			}
			mx_r.unlock();

			thread_mutex	mx_nr(false);

			mx_nr.lock();
			if(mx_nr.try_lock())
			{
				r->report("thread_mutex (non-recursive) could lock recursively ", __LINE__);
				mx_nr.unlock();
				bSuccess = false;
			}
			mx_nr.unlock();

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_synch_thread_mutex(test_unixstl_synch_thread_mutex);
	} // anonymous namespace

}// namespace unittest
