
// Updated: 5th February 2006

#if !defined(WINSTL_INCL_WINSTL_HPP_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within winstl/string_access.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_string_access_HWND(unittest_reporter *r)
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

		ss_bool_t test_winstl_string_access_LSA_UNICODE_STRING(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

#ifdef _NTSECAPI_
			WCHAR				buffer[100] = L"LSA-String #1";
			LSA_UNICODE_STRING	lsa1 =
			{
					static_cast<USHORT>(wcslen(buffer))
				,	STLSOFT_NUM_ELEMENTS(buffer)
				,	buffer
			};

			if(0 != wcscmp(c_str_ptr(lsa1), L"LSA-String #1"))
			{
				r->report("c_str_ptr(LSA_UNICODE_STRING) failed", __LINE__);
				bSuccess = false;
			}
#else  /* ?_NTSECAPI_ */
			STLSOFT_SUPPRESS_UNUSED(r);
#endif /* _NTSECAPI_ */

			return bSuccess;
		}

		ss_bool_t test_winstl_string_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "string_access", __FILE__);

			if(!test_winstl_string_access_HWND(r))
			{
				bSuccess = false;
			}

			if(!test_winstl_string_access_LSA_UNICODE_STRING(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_string_access(test_winstl_string_access);
	} // anonymous namespace

} // namespace unittest
