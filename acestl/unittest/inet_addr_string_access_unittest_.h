
#if !defined(ACESTL_INCL_ACESTL_HPP_INET_ADDR_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within acestl/inet_addr_string_access.hpp
#endif /* !ACESTL_INCL_ACESTL_HPP_INET_ADDR_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_acestl_inet_addr_string_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ACESTL", "inet_addr_string_access", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_acestl_inet_addr_string_access(test_acestl_inet_addr_string_access);
	} // anonymous namespace

} // namespace unittest
