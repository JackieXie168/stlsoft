
// Updated: 23rd August 2008

#if !defined(COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/util/CY_functions.h
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_string_CY_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "string/CY_functions", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_string_CY_functions(test_comstl_string_CY_functions);
	} // anonymous namespace

} // namespace unittest
