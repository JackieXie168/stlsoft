
#if !defined(ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within atlstl/string_access.hpp
#endif /* !ATLSTL_INCL_ATLSTL_HPP_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl_string_access_CComBSTR(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;
#if defined(STLSOFT_COMPILER_IS_BORLAND)
			CComBSTR	bstr1(L"String #1");
#else /* ? compiler */
			CComBSTR	bstr1("String #1"); // Borland's CComBSTR(LPCSTR) leaves a character off the end!!
#endif /* compiler */

			if(0 != wcscmp(L"String #1", c_str_ptr(bstr1)))
			{
				r->report("c_str_ptr(CComBSTR) failed", __LINE__);
				bSuccess = false;
			}

			if(0 != wcscmp(L"String #1", c_str_ptr_null(bstr1)))
			{
				r->report("c_str_ptr_null(CComBSTR) failed", __LINE__);
				bSuccess = false;
			}

			CComBSTR	bstr2;

			if(0 != wcscmp(L"", c_str_ptr(bstr2)))
			{
				r->report("c_str_ptr(CComBSTR) failed with empty string", __LINE__);
				bSuccess = false;
			}

			if(NULL != c_str_ptr_null(bstr2))
			{
				r->report("c_str_ptr_null(CComBSTR) failed with empty string", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

#ifdef __ATLWIN_H__
		ss_bool_t test_atlstl_string_access_CWindow(unittest_reporter *r)
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

		ss_bool_t test_atlstl_string_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "string_access", __FILE__);

			// 1. Test CComBSTR
			if(bSuccess)
			{
				bSuccess = test_atlstl_string_access_CComBSTR(r);
			}

#ifdef __ATLWIN_H__
			// 2. Test CWindow
			if(bSuccess)
			{
				bSuccess = test_atlstl_string_access_CWindow(r);
			}
#endif /* __ATLWIN_H__ */

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_string_access(test_atlstl_string_access);
	} // anonymous namespace

} // namespace unittest
