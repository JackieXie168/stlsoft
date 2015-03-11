
// Updated: 6th June 2006

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_INFO)
# error This file cannot be directly included, and should only be included within winstl/system/system_info.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_INFO */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_system_info(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/system_info", __FILE__);

			system_info::number_of_processors();
			system_info::page_size();
			system_info::allocation_granularity();
			system_info::get_systeminfo();

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_system_info(test_winstl_system_system_info);
	} // anonymous namespace

} // namespace unittest

