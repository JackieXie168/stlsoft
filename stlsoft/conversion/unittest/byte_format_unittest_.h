
#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/byte_format_functions.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_BYTE_FORMAT_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_conversion_byte_format_functions(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/byte_format_functions", __FILE__);

#if 0
			{
				r->report("byte_format_functions failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_byte_format_functions(test_stlsoft_conversion_byte_format_functions);
	} // anonymous namespace

} // namespace unittest
