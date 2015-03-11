
// Updated: 6th July 2006

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_ZERO)
# error This file cannot be directly included, and should only be included within stlsoft/util/zero.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_ZERO */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_zero(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/zero", __FILE__);

	#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_zero(test_stlsoft_zero);
	} // anonymous namespace

} // namespace unittest
