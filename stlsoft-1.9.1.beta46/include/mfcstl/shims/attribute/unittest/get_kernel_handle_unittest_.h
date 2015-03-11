
// Updated: 10th January 2007

#if !defined(MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE)
# error This file cannot be directly included, and should only be included within mfcstl/shims/attribute/get_kernel_handle.hpp
#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_shims_attribute_get_kernel_handle(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "shims/attribute/get_kernel_handle", __FILE__);

			CEvent	ev;

			if(::winstl::get_kernel_handle(ev) != ev)
			{
				r->report("get_kernel_handle(CEvent) failed", __LINE__);
				bSuccess = false;
			}

			CMutex	mx;

			if(::winstl::get_kernel_handle(mx) != mx)
			{
				r->report("get_kernel_handle(CMutex) failed", __LINE__);
				bSuccess = false;
			}

			CSemaphore	sem;

			if(::winstl::get_kernel_handle(sem) != sem)
			{
				r->report("get_kernel_handle(CSemaphore) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_shims_attribute_get_kernel_handle(test_mfcstl_shims_attribute_get_kernel_handle);
	} // anonymous namespace

}// namespace unittest
