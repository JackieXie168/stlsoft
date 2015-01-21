
#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_PID_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/system/pid_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_PID_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_pid_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/pid_sequence", __FILE__);

			winstl::pid_sequence	pids;
			winstl::pid_sequence	pids2(pids);

			if(pids.size() != pids2.size())
			{
				r->report("pid_sequence copy failed", __LINE__);
				bSuccess = false;
			}

			if(!std::equal(pids.begin(), pids.end(), pids2.begin()))
			{
				r->report("pid_sequence copies contents' different", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_pid_sequence(test_winstl_system_pid_sequence);
	} // anonymous namespace

} // namespace unittest
