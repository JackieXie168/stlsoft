
// Updated: 30th May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX)
# error This file cannot be directly included, and should only be included within unixstl/synch/process_mutex.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_PROCESS_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_synch_process_mutex(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "synch/process_mutex", __FILE__);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
			try
			{
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
				process_mutex	mx_r(true);

				mx_r.lock();
				if(!mx_r.try_lock())
				{
//fprintf(stderr, "try_lock: %d %s\n", errno, strerror(errno));
					r->report("process_mutex (recursive) could not lock recursively ", __LINE__);
					bSuccess = false;
				}
				else
				{
					mx_r.unlock();
				}
				mx_r.unlock();

				process_mutex	mx_nr(false);

				mx_nr.lock();
				if(mx_nr.try_lock())
				{
					r->report("process_mutex (non-recursive) could lock recursively ", __LINE__);
					mx_nr.unlock();
					bSuccess = false;
				}
				mx_nr.unlock();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
			}
			catch(unix_exception &x)
			{
				char	sz[1001] = "process_mutex exception failure: ";

				strncpy(&sz[0] + strlen(sz), x.what(), (STLSOFT_NUM_ELEMENTS(sz) - 1) - strlen(sz));
				sz[STLSOFT_NUM_ELEMENTS(sz) - 1] = '\0';

				r->report(sz, __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_synch_process_mutex(test_unixstl_synch_process_mutex);
	} // anonymous namespace

} // namespace unittest
