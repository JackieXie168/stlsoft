
// Updated: 6th July 2006

#if !defined(MFCSTL_INCL_MFCSTL_STRING_HPP_RESOURCE_STRING)
# error This file cannot be directly included, and should only be included within mfcstl/string/resource_string.hpp
#endif /* !MFCSTL_INCL_MFCSTL_STRING_HPP_RESOURCE_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_resource_string(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "string/resource_string", __FILE__);

	#if 0
			HINSTANCE		hinst	=	::LoadLibrary("USER32");
			resource_string rs(hinst, 2);

			if(rs)
			{
				r->report("resource string load failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_resource_string(test_mfcstl_resource_string);
	} // anonymous namespace

} // namespace unittest

