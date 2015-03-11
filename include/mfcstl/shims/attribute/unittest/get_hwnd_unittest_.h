
// Updated: 25th April 2008

#if !defined(MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND)
# error This file cannot be directly included, and should only be included within mfcstl/shims/attribute/get_HWND.hpp
#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_HWND */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_shims_attribute_get_HWND(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "shims/attribute/get_HWND", __FILE__);

			HWND	hwndDesktop =	::GetDesktopWindow();
			CWnd	wndDesktop;

			wndDesktop.Attach(hwndDesktop);

			if(get_HWND(wndDesktop) != hwndDesktop)
			{
				r->report("get_HWND(CWindow) failed", __LINE__);
				bSuccess = false;
			}

			wndDesktop.Detach();

			CWnd	*pwndDesktop	=	CWnd::FromHandle(hwndDesktop);

			if(get_HWND(pwndDesktop) != hwndDesktop)
			{
				r->report("get_HWND(CWindow*) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_shims_attribute_get_HWND(test_mfcstl_shims_attribute_get_HWND);
	} // anonymous namespace

}// namespace unittest
