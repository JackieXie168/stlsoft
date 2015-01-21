
#if !defined(STLSOFT_INCL_STLSOFT_SYNCH_HPP_NULL_MUTEX)
# error This file cannot be directly included, and should only be included within stlsoft/synch/null_mutex.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_NULL_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_synch_null_mutex(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "synch/null_mutex", __FILE__);

			null_mutex				mx;

			mx.lock();
			mx.unlock();

			lock_instance(mx);
			unlock_instance(mx);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_synch_null_mutex(test_stlsoft_synch_null_mutex);
	} // anonymous namespace

} // namespace unittest
