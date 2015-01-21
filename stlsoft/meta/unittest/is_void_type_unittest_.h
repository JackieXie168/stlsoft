
// Updated: 2nd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_void_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_meta_is_void_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_void_type", __FILE__);

			// Expected true

			if(0 == is_void_type<void>::value)
			{
				r->report("is_void_type<void> failed", __LINE__);
				bSuccess = false;
			}

			// Expected false

			if(0 != is_void_type<short>::value)
			{
				r->report("is_void_type<short> failed", __LINE__);
				bSuccess = false;
			}

			if(0 != is_void_type<bool>::value)
			{
				r->report("is_void_type<bool> failed", __LINE__);
				bSuccess = false;
			}

			if(0 != is_void_type<void*>::value)
			{
				r->report("is_void_type<void*> failed", __LINE__);
				bSuccess = false;
			}

			if(0 != is_void_type<bool*>::value)
			{
				r->report("is_void_type<bool*> failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_void_type(test_stlsoft_meta_is_void_type);
	} // anonymous namespace

} // namespace unittest
