
// Updated: 6th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_PAIR)
# error This file cannot be directly included, and should only be included within stlsoft/util/pair.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_PAIR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_util_pair(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/pair", __FILE__);


#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_util_pair(test_stlsoft_util_pair);
	} // anonymous namespace

} // namespace unittest
