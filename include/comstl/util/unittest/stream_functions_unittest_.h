
// Updated: 4th July 2006

#if !defined(COMSTL_INCL_COMSTL_UTIL_H_STREAM_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/util/stream_functions.h
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_STREAM_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_stream_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/stream_functions", __FILE__);


			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_stream_functions(test_comstl_stream_functions);

	} // anonymous namespace

} // namespace unittest
