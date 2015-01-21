
// Updated: 14th July 2006

#if !defined(COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT)
# error This file cannot be directly included, and should only be included within comstl/shims/access/string/variant.hpp
#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comst_shims_access_string_variant_VARIANT(unittest_reporter *r)
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

		ss_bool_t test_comst_shims_access_string_variant(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "shims/access/string/variant", __FILE__);

			// 1. Test CWindow
			if(bSuccess)
			{
				bSuccess = test_comst_shims_access_string_variant_VARIANT(r);
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_comst_shims_access_string_variant(test_comst_shims_access_string_variant);
	} // anonymous namespace

} // namespace unittest

