
// Updated: 2nd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_integral_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_meta_is_integral_type(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_integral_type", __FILE__);

			if(stlsoft::is_integral_type<char>::value == 0)
			{
				r->report("is_integral_type<char> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<signed char>::value == 0)
			{
				r->report("is_integral_type<signed char> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<unsigned char>::value == 0)
			{
				r->report("is_integral_type<unsigned char> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<short>::value == 0)
			{
				r->report("is_integral_type<short> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<unsigned short>::value == 0)
			{
				r->report("is_integral_type<unsigned short> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<int>::value == 0)
			{
				r->report("is_integral_type<int> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<unsigned int>::value == 0)
			{
				r->report("is_integral_type<unsigned int> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<long>::value == 0)
			{
				r->report("is_integral_type<long> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<unsigned long>::value == 0)
			{
				r->report("is_integral_type<unsigned long> == 0", __LINE__);
				bSuccess = false;
			}

			if(stlsoft::is_integral_type<bool>::value == 0)
			{
				r->report("is_integral_type<bool> == 0", __LINE__);
				bSuccess = false;
			}

			if(stlsoft::is_integral_type<ss_uint8_t>::value == 0)
			{
				r->report("is_integral_type<ss_uint8_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_sint8_t>::value == 0)
			{
				r->report("is_integral_type<ss_sint8_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_uint16_t>::value == 0)
			{
				r->report("is_integral_type<ss_uint16_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_sint16_t>::value == 0)
			{
				r->report("is_integral_type<ss_sint16_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_uint32_t>::value == 0)
			{
				r->report("is_integral_type<ss_uint32_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_sint32_t>::value == 0)
			{
				r->report("is_integral_type<ss_sint32_t> == 0", __LINE__);
				bSuccess = false;
			}
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			if(stlsoft::is_integral_type<ss_uint64_t>::value == 0)
			{
				r->report("is_integral_type<ss_uint64_t> == 0", __LINE__);
				bSuccess = false;
			}
			if(stlsoft::is_integral_type<ss_sint64_t>::value == 0)
			{
				r->report("is_integral_type<ss_sint64_t> == 0", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_integral_type(test_stlsoft_meta_is_integral_type);
	} // anonymous namespace

} // namespace unittest

////////////////////////////////////////////////////////////////////////////
