
// Updated: 14th July 2006

#if !defined(WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING)
# error This file cannot be directly included, and should only be included within winstl/shims/access/string/lsa_unicode_string.hpp
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_shims_access_string_lsa_unicode_string_LSA_UNICODE_STRING(unittest_reporter *r)
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

		ss_bool_t test_winstl_shims_access_string_lsa_unicode_string(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shims/access/string/lsa_unicode_string", __FILE__);

			if(!test_winstl_shims_access_string_lsa_unicode_string_LSA_UNICODE_STRING(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_string_access(test_winstl_shims_access_string_lsa_unicode_string);
	} // anonymous namespace

} // namespace unittest
