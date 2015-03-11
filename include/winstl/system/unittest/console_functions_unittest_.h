
// Updated: 30th December 2006

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
		ss_bool_t test_winstl_system_console_functions_get_console_window(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
	!defined(STLSOFT_COMPILER_IS_WATCOM)
			ss_bool_t	bSuccess = true;

			try
			{
				HWND	hwnd1	=	winstl::dl_call<HWND>("KERNEL32", "S:GetConsoleWindow");
				HWND	hwnd2	=	winstl::get_console_window();

				if(hwnd1 != hwnd2)
				{
					r->report("get_console_window() failed ", __LINE__);

					bSuccess = false;
				}
			}
			catch(winstl::missing_entry_point_exception &)
			{
				r->report("Cannot test get_console_window() on systems other than Windows 2000 or later", __LINE__);
			}

			return bSuccess;
#else /* ? compiler */
			STLSOFT_SUPPRESS_UNUSED(r);

			return true;
#endif /* compiler */
		}

		ss_bool_t test_winstl_system_console_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/console_functions", __FILE__);

			if(!test_winstl_system_console_functions_get_console_window(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_system_console_functions(test_winstl_system_console_functions);

	} // anonymous namespace

} // namespace unittest
