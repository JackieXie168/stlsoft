
// Updated: 14th December 2005

#if !defined(COMSTL_INCL_COMSTL_HPP_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within comstl/string_access.hpp
#endif /* !COMSTL_INCL_COMSTL_HPP_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_string_access_GUID(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

			/* Check GUID conversion */
			GUID const	guid	=	GUID_NULL;

#ifdef UNICODE
			if(0 != ::wcscmp(c_str_ptr(guid), L"{00000000-0000-0000-0000-000000000000}"))
#else /* ? UNICODE */
			if(0 != ::strcmp(c_str_ptr(guid), "{00000000-0000-0000-0000-000000000000}"))
#endif /* UNICODE */
			{
				r->report("c_str_ptr(GUID) failed", __LINE__);
				bSuccess = false;
			}

#ifdef UNICODE
			if(0 != ::wcscmp(c_str_ptr_null(guid), L"{00000000-0000-0000-0000-000000000000}"))
#else /* ? UNICODE */
			if(0 != ::strcmp(c_str_ptr_null(guid), "{00000000-0000-0000-0000-000000000000}"))
#endif /* UNICODE */
			{
				r->report("c_str_ptr_null(GUID) failed", __LINE__);
				bSuccess = false;
			}

			if(COMSTL_CCH_GUID != c_str_len(guid))
			{
				r->report("c_str_len(GUID) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_comstl_string_access_VARIANT(unittest_reporter *r)
		{
			ss_bool_t	bSuccess = true;

			/* Check VARIANT conversion */
			VARIANT 	var1;

			::VariantInit(&var1);
			var1.vt 	=	VT_I4;
			var1.lVal	=	1968;

#ifdef UNICODE
			if(0 != ::wcscmp(L"1968", c_str_ptr(var1)))
#else /* ? UNICODE */
			if(0 != ::strcmp("1968", c_str_ptr(var1)))
#endif /* UNICODE */
			{
				r->report("c_str_ptr(VARIANT) failed", __LINE__);
				bSuccess = false;
			}

			// TODO: Implement c_str_ptr_null_a / c_str_ptr_null_o / c_str_ptr_null for VARIANT
//#ifdef UNICODE
			if(0 != ::wcscmp(L"1968", c_str_ptr_null_w(var1)))
//#else /* ? UNICODE */
//			  if(0 != ::strcmp("1968", c_str_ptr_null(var1)))
//#endif /* UNICODE */
			{
				r->report("c_str_ptr_null(VARIANT) failed", __LINE__);
				bSuccess = false;
			}

			VARIANT 	var2;

			::VariantInit(&var1);

			// This bit of code makes Borland generate correct code for the following
			// conditional expression. Bob knows why!
			if(0)
			{
#ifdef UNICODE
				::fwprintf(stderr, L"[%s]\n", static_cast<wchar_t const*>(c_str_ptr(var2)));
#else /* ? UNICODE */
				::fprintf(stderr, "[%s]\n", static_cast<char const*>(c_str_ptr(var2)));
#endif /* UNICODE */
			}

#ifdef UNICODE
			if(0 != ::wcscmp(L"", c_str_ptr(var2)))
#else /* ? UNICODE */
			if(0 != ::strcmp("", c_str_ptr(var2)))
#endif /* UNICODE */
			{
				r->report("c_str_ptr(VARIANT) failed", __LINE__);
				bSuccess = false;
			}

			// TODO: Implement c_str_ptr_null_a / c_str_ptr_null_o / c_str_ptr_null for VARIANT
//#ifdef UNICODE
			if(NULL != c_str_ptr_null_w(var2))
//#else /* ? UNICODE */
//			  if(NULL != c_str_ptr_null(var2))
//#endif /* UNICODE */
			{
				r->report("c_str_ptr_null(VARIANT) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_comstl_string_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "string_access", __FILE__);

			// 1. Test GUID
			if(bSuccess)
			{
				bSuccess = test_comstl_string_access_GUID(r);
			}

			// 1. Test CWindow
			if(bSuccess)
			{
				bSuccess = test_comstl_string_access_VARIANT(r);
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_comstl_string_access(test_comstl_string_access);
	} // anonymous namespace

} // namespace unittest

