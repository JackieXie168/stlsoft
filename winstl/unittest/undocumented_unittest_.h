
#if !defined(WINSTL_INCL_WINSTL_HPP_UNDOCUMENTED)
# error This file cannot be directly included, and should only be included within winstl/undocumented.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_UNDOCUMENTED */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_undocumented(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "undocumented", __FILE__);

	#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_undocumented(test_winstl_undocumented);
	} // anonymous namespace

} // namespace unittest

