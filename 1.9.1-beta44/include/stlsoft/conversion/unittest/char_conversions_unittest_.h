
#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR_CONVERSIONS)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/char_conversions.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR_CONVERSIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_conversion_char_conversions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/char_conversions", __FILE__);

			if(0 != ::strcmp("String #1", w2a(L"String #1")))
			{
				r->report("w2a failed", __LINE__);
				bSuccess = false;
			}

			if(0 != ::wcscmp(L"String #1", a2w("String #1")))
			{
				r->report("a2w failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_char_conversions(test_stlsoft_conversion_char_conversions);
	} // anonymous namespace

} // namespace unittest
