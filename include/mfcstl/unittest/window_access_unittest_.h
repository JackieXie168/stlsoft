
// Updated: 19th September 2005

#if !defined(MFCSTL_INCL_MFCSTL_HPP_WINDOW_ACCESS)
# error This file cannot be directly included, and should only be included within unixstl/window_access.hpp
#endif /* !MFCSTL_INCL_MFCSTL_HPP_WINDOW_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_window_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "window_access", __FILE__);

			HWND	hwndDesktop =	::GetDesktopWindow();
			CWnd	wndDesktop;

			wndDesktop.Attach(hwndDesktop);

			if(get_hwnd(wndDesktop) != hwndDesktop)
			{
				r->report("get_hwnd(CWindow) failed", __LINE__);
				bSuccess = false;
			}

			wndDesktop.Detach();

			CWnd	*pwndDesktop	=	CWnd::FromHandle(hwndDesktop);

			if(get_hwnd(pwndDesktop) != hwndDesktop)
			{
				r->report("get_hwnd(CWindow*) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_window_access(test_mfcstl_window_access);
	} // anonymous namespace

}// namespace unittest