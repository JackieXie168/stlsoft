
#if !defined(ACESTL_INCL_ACESTL_HPP_SOCKET_FUNCTIONS)
# error This file cannot be directly included, and should only be included within acestl/socket_functions.hpp
#endif /* !ACESTL_INCL_ACESTL_HPP_SOCKET_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_acestl_socket_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ACESTL", "socket_functions", __FILE__);

#if 0
			typedef message_queue_sequence<char>	env_var_t;

			env_var_t	path("PATH");

			if(0 != strcmp(getenv("PATH"), path))
			{
				r->report("message_queue_sequence<char> failed ", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_acestl_socket_functions(test_acestl_socket_functions);
	} // anonymous namespace

} // namespace unittest
