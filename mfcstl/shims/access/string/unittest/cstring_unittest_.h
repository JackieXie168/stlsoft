
// Updated: 14th July 2006

#if !defined(MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CSTRING)
# error This file cannot be directly included, and should only be included within mfcstl/shims/access/string/cstring.hpp
#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CSTRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_shims_access_string_cstring_CString(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

			CString 	str1("String #1");

			if(0 != _tcscmp(_T("String #1"), c_str_ptr(str1)))
			{
				r->report("c_str_ptr(CString) failed", __LINE__);
				bSuccess = false;
			}

			if(0 != _tcscmp(_T("String #1"), c_str_ptr_null(str1)))
			{
				r->report("c_str_ptr_null(CString) failed", __LINE__);
				bSuccess = false;
			}

			CString 	str2;

			if(NULL != c_str_ptr_null(str2))
			{
				r->report("c_str_ptr_null(CString) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_mfcstl_shims_access_string_cstring(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "shims/access/string/string_access", __FILE__);

			// 1. Test CString
			if(bSuccess)
			{
				bSuccess = test_mfcstl_shims_access_string_cstring_CString(r);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_shims_access_string_cstring(test_mfcstl_shims_access_string_cstring);
	} // anonymous namespace

}// namespace unittest
