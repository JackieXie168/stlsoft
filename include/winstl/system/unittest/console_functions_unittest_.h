
// Updated: 10th June 2006

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/system/console_functions.h
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_console_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/console_functions", __FILE__);


			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_system_console_functions(test_winstl_system_console_functions);

	} // anonymous namespace

} // namespace unittest