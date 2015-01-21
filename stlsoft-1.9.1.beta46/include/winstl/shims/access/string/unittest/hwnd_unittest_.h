
// Updated: 14th July 2006

#if !defined(WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND)
# error This file cannot be directly included, and should only be included within winstl/shims/access/string/hwnd.hpp
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_HWND */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_shims_access_string_hwnd_HWND(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

			HWND		hwnd	=	::CreateWindow("BUTTON", "Window #1", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

			if( NULL != hwnd &&
				0 != strcmp("Window #1", c_str_ptr_a(hwnd)))
			{
				r->report("c_str_ptr(HWND) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_winstl_shims_access_string_hwnd(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shims/access/string/hwnd", __FILE__);

			if(!test_winstl_shims_access_string_hwnd_HWND(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_shims_access_string_hwnd(test_winstl_shims_access_string_hwnd);
	} // anonymous namespace

} // namespace unittest
