
// Updated: 5th January 2007

#if !defined(COMSTL_INCL_COMSTL_UTIL_HPP_INITIALISERS)
# error This file cannot be directly included, and should only be included within comstl/util/initialisers.hpp
#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_INITIALISERS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_util_initialisers(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/initialisers", __FILE__);

			com_initializer coinit;

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_util_initialisers(test_comstl_util_initialisers);
	} // anonymous namespace

} // namespace unittest
