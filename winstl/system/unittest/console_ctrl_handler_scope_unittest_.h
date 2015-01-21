
// Updated: 10th June 2006

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE)
# error This file cannot be directly included, and should only be included within winstl/system/console_ctrl_handler_scope.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_console_ctrl_handler_scope(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/console_ctrl_handler_scope", __FILE__);

	#if 0
			if()
			{
				r->report("Unicode (Win9x) buffer size incorrect", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_console_ctrl_handler_scope(test_winstl_system_console_ctrl_handler_scope);
	} // anonymous namespace

} // namespace unittest

