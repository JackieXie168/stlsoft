
/*
 * Created:
 * Updated: 31st March 2007
 */

#if !defined(STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_AUTO_PTR)
# error This file cannot be directly included, and should only be included within stlsoft/shims/attribute/get_ptr/std/auto_ptr.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_AUTO_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_shims_attribute_get_ptr_std_auto_ptr(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "shims/attribute/get_ptr/std/auto_ptr", __FILE__);

#ifndef _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
			stlsoft_ns_qual_std(auto_ptr)<int>	api(new int(1));

			if(get_ptr(api) != api.get())
			{
				r->report("get_ptr(auto_ptr<int>) failed", __LINE__);
				bSuccess = false;
			}
#endif /* _stlsoft_shims_attribute_get_ptr_std_auto_ptr_NO_AUTO_PTR */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_shims_attribute_get_ptr_std_auto_ptr(test_stlsoft_shims_attribute_get_ptr_std_auto_ptr);
	} // anonymous namespace

} // namespace unittest
