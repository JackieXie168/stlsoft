
#if !defined(WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND)
# error This file cannot be directly included, and should only be included within winstl/shims/attribute/get_hwnd.hpp
#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_window_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shims/attribute/window_access", __FILE__);

			HWND	hwndDesktopWindow	=	::GetDesktopWindow();

			if(get_hwnd(hwndDesktopWindow) != hwndDesktopWindow)
			{
				r->report("get_hwnd(HWND) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_window_access(test_winstl_window_access);
	} // anonymous namespace

} // namespace unittest

