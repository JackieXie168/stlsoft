
#if !defined(ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_TIME_VALUE)
# error This file cannot be directly included, and should only be included within acestl/shims/access/string/time_value.hpp
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_TIME_VALUE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_acestl_shims_access_string_time_value(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ACESTL", "shims/access/string/time_value", __FILE__);

#if 0
			typedef message_queue_sequence<as_char_a_t>    env_var_t;

			env_var_t	path("PATH");

			if(0 != strcmp(getenv("PATH"), path))
			{
				r->report("message_queue_sequence<as_char_a_t> failed ", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_acestl_shims_access_string_time_value(test_acestl_shims_access_string_time_value);
	} // anonymous namespace

} // namespace unittest
