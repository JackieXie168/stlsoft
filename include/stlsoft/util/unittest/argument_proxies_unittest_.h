
#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES)
# error This file cannot be directly included, and should only be included within stlsoft/util/argument_proxies.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_argument_proxies(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/argument_proxies", __FILE__);

	#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_argument_proxies(test_stlsoft_argument_proxies);
	} // anonymous namespace

} // namespace unittest
