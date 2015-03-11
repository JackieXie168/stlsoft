
// Updated: 14th July 2006

#if !defined(COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID)
# error This file cannot be directly included, and should only be included within comstl/shims/access/string/guid.hpp
#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comst_shims_access_string_guid_GUID(unittest_reporter *r)
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

		ss_bool_t test_comst_shims_access_string_guid(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "shims/access/string/guid", __FILE__);

			// 1. Test GUID
			if(bSuccess)
			{
				bSuccess = test_comst_shims_access_string_guid_GUID(r);
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_comst_shims_access_string_guid(test_comst_shims_access_string_guid);
	} // anonymous namespace

} // namespace unittest

