
#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_SEARCHPATH_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/system/searchpath_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SEARCHPATH_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_searchpath_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/searchpath_sequence", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_searchpath_sequence(test_winstl_system_searchpath_sequence);
	} // anonymous namespace

} // namespace unittest
