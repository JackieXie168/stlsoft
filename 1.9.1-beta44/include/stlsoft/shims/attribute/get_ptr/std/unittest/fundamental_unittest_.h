
#if !defined(STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_FUNDAMENTAL)
# error This file cannot be directly included, and should only be included within stlsoft/shims/attribute/get_ptr/std/fundamental.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_FUNDAMENTAL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_shims_attribute_get_ptr_std_fundamental(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "shims/attribute/get_ptr/std/ptr_access", __FILE__);

			int 	i	=	0;
			void	*p	=	&i;

			if(get_ptr(p) != p)
			{
				r->report("get_ptr(void*) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_shims_attribute_get_ptr_std_fundamental(test_stlsoft_shims_attribute_get_ptr_std_fundamental);
	} // anonymous namespace

} // namespace unittest

