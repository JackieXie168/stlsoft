
#if !defined(WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HKEY)
# error This file cannot be directly included, and should only be included within winstl/shims/attribute/get_HKEY.hpp
#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HKEY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_shims_attribute_get_HKEY(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shims/attribute/get_HKEY", __FILE__);

			HKEY					hkey		=	HKEY_LOCAL_MACHINE;

			if(get_HKEY(hkey) != hkey)
			{
				r->report("get_HKEY(HKEY) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_shims_attribute_get_HKEY(test_winstl_shims_attribute_get_HKEY);
	} // anonymous namespace

} // namespace unittest
