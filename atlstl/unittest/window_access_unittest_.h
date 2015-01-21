
#if !defined(ATLSTL_INCL_ATLSTL_HPP_WINDOW_ACCESS)
# error This file cannot be directly included, and should only be included within atlstl/window_access.hpp
#endif /* !ATLSTL_INCL_ATLSTL_HPP_WINDOW_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl_window_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "window_access", __FILE__);

			HWND	hwndDesktop =	::GetDesktopWindow();
			CWindow wndDesktop;

			wndDesktop.Attach(hwndDesktop);

			if(get_hwnd(wndDesktop) != hwndDesktop)
			{
				r->report("get_hwnd(CWindow) failed", __LINE__);
				bSuccess = false;
			}

			wndDesktop.Detach();

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_window_access(test_atlstl_window_access);
	} // anonymous namespace

} // namespace unittest
