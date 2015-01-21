
// Updated: 5th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/truncation_cast.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{

		ss_bool_t test_stlsoft_conversion_truncation_cast(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/truncation_cast", __FILE__);

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_truncation_cast(test_stlsoft_conversion_truncation_cast);
	} // anonymous namespace

} // namespace unittest
