
#if !defined(COMSTL_INCL_COMSTL_STRING_H_OLESTRING_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/string/olestring_functions.h
#endif /* !COMSTL_INCL_COMSTL_STRING_H_OLESTRING_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_string_olestring_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "string/olestring_functions", __FILE__);

			LPOLESTR	str1   =   olestring_create("Hello, Sailor!");
			LPOLESTR	str2   =   olestring_create(L"Hello, Sailor!");

			if( NULL != str1 &&
				NULL != str2 &&
				0 != wcscmp(str1, str2))
			{
				r->report("OLE string (ANSI + Unicode) creation failed", __LINE__);
				bSuccess = false;
			}

			LPOLESTR	str3   =   olestring_dup(str1);

			if( NULL != str1 &&
				NULL != str3 &&
				0 != wcscmp(str1, str3))
			{
				r->report("OLE string duplication failed", __LINE__);
				bSuccess = false;
			}

			olestring_destroy(str3);
			olestring_destroy(str2);
			olestring_destroy(str1);

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_string_olestring_functions(test_comstl_string_olestring_functions);
	} // anonymous namespace

} // namespace unittest
