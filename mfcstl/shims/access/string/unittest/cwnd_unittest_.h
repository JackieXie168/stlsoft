
// Updated: 14th July 2006

#if !defined(MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND)
# error This file cannot be directly included, and should only be included within mfcstl/shims/access/string/cwnd.hpp
#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_shims_access_string_cwnd_CWnd(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

			CWnd	wnd1;
			CWnd	*pwndDesktopWindow	=	CWnd::GetDesktopWindow();
			RECT	rc					=	{ 0, 0, 10, 10 };

			if( wnd1.Create("BUTTON", "Window #1", NULL, rc, pwndDesktopWindow, 0) &&
				0 != strcmp("Window #1", c_str_ptr(wnd1)))
			{
				r->report("c_str_ptr(CWnd) failed", __LINE__);
				bSuccess = false;
			}

			wnd1.DestroyWindow();

			CWnd	wnd2;

			if(0 != strcmp("", c_str_ptr(wnd2)))
			{
				r->report("c_str_ptr(CWnd) failed", __LINE__);
				bSuccess = false;
			}

			if(NULL != c_str_ptr_null(wnd2))
			{
				r->report("c_str_ptr_null(CWnd) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}


		ss_bool_t test_mfcstl_shims_access_string_cwnd(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "shims/access/string/cwnd", __FILE__);

			// 1. Test CWnd
			if(bSuccess)
			{
				bSuccess = test_mfcstl_shims_access_string_cwnd_CWnd(r);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_shims_access_string_cwnd(test_mfcstl_shims_access_string_cwnd);
	} // anonymous namespace

}// namespace unittest