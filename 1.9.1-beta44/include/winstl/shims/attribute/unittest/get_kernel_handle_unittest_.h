
// Updated: 29th December 2006

#if !defined(WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE)
# error This file cannot be directly included, and should only be included within winstl/shims/attribute/get_kernel_handle.hpp
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_shims_attribute_get_kernel_handle(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shims/attribute/get_kernel_handle", __FILE__);

			if(INVALID_HANDLE_VALUE != get_kernel_handle(INVALID_HANDLE_VALUE))
			{
				r->report("get_kernel_handle() failed with INVALID_HANDLE_VALUE", __LINE__);
				bSuccess = false;
			}

			if(::GetCurrentProcess() != get_kernel_handle(::GetCurrentProcess()))
			{
				r->report("get_kernel_handle() failed with ::GetCurrentProcess()", __LINE__);
				bSuccess = false;
			}

			if(NULL != get_kernel_handle(NULL))
			{
				r->report("get_kernel_handle() failed with NULL", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_shims_attribute_get_kernel_handle(test_winstl_shims_attribute_get_kernel_handle);
	} // anonymous namespace

} // namespace unittest

