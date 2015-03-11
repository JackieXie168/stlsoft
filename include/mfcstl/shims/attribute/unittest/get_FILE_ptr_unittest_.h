
// Updated: 23rd August 2008

#if !defined(MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR)
# error This file cannot be directly included, and should only be included within mfcstl/shims/attribute/get_FILE_ptr.hpp
#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_shims_attribute_get_FILE_ptr(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "shims/attribute/get_FILE_ptr", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_shims_attribute_get_FILE_ptr(test_mfcstl_shims_attribute_get_FILE_ptr);
	} // anonymous namespace

}// namespace unittest
