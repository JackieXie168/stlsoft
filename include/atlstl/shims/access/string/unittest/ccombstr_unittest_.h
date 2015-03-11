
#if !defined(ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR)
# error This file cannot be directly included, and should only be included within atlstl/shims/access/string/ccombstr.hpp
#endif /* !ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CCOMBSTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl_shims_access_string_ccombstr_CComBSTR(unittest_reporter *r)
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

		ss_bool_t test_atlstl_shims_access_string_ccombstr(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "shims/access/string/string_access", __FILE__);

			// 1. Test CComBSTR
			if(bSuccess)
			{
				bSuccess = test_atlstl_shims_access_string_ccombstr_CComBSTR(r);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_shims_access_string_ccombstr(test_atlstl_shims_access_string_ccombstr);
	} // anonymous namespace

} // namespace unittest
