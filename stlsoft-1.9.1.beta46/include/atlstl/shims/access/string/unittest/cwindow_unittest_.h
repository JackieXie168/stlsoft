
#if !defined(ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW)
# error This file cannot be directly included, and should only be included within atlstl/shims/access/string/cwindow.hpp
#endif /* !ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
#ifdef __ATLWIN_H__
		ss_bool_t test_atlstl_shims_access_string_cwindow_CWindow(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;
			RECT		rc		=	{ 0, 0, 10, 10 };
#if (_ATL_VER & 0xff00) < 0x0300
			HWND		hwnd1	=	::CreateWindowEx(0, "BUTTON", "Window #1", 0, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, NULL, (HMENU)0, _Module.GetModuleInstance(), NULL);
			CWindow 	wnd1(hwnd1);
#else /* ? _ATL_VER */
			CWindow 	wnd1;
			HWND		hwnd1	=	wnd1.Create("BUTTON", NULL, rc, "Window #1");
#endif /* _ATL_VER */

			if( NULL != hwnd1 &&
				0 != strcmp("Window #1", c_str_ptr(wnd1)))
			{
				r->report("c_str_ptr(CWindow) failed", __LINE__);
				bSuccess = false;
			}

			CWindow 	wnd2;

			if(0 != lstrcmp(_T(""), c_str_ptr(wnd2)))
			{
				r->report("c_str_ptr(CWindow) failed with empty window", __LINE__);
				bSuccess = false;
			}

			if(NULL != c_str_ptr_null(wnd2))
			{
				r->report("c_str_ptr_null(CWindow) failed with empty window", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}
#endif /* __ATLWIN_H__ */

		ss_bool_t test_atlstl_shims_access_string_cwindow(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "shims/access/string/string_access", __FILE__);

#ifdef __ATLWIN_H__
			// 1. Test CWindow
			if(bSuccess)
			{
				bSuccess = test_atlstl_shims_access_string_cwindow_CWindow(r);
			}
#endif /* __ATLWIN_H__ */

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_shims_access_string_cwindow(test_atlstl_shims_access_string_cwindow);
	} // anonymous namespace

} // namespace unittest
