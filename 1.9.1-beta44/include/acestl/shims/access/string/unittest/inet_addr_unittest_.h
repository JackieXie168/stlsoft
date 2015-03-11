
#if !defined(ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_INET_ADDR)
# error This file cannot be directly included, and should only be included within acestl/shims/access/string/inet_addr.hpp
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_INET_ADDR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_acestl_shims_access_string_inet_addr(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ACESTL", "shims/access/string/inet_addr_string_access", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_acestl_shims_access_string_inet_addr(test_acestl_shims_access_string_inet_addr);
	} // anonymous namespace

} // namespace unittest
