
#if !defined(DOTNETSTL_INCL_DOTNETSTL_UTIL_HPP_DISPOSE_FUNCTIONS)
# error This file cannot be directly included, and should only be included within dotnetstl/util/dispose_functions.hpp
#endif /* !DOTNETSTL_INCL_DOTNETSTL_UTIL_HPP_DISPOSE_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_dotnetstl_utility_dispose_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, ".netSTL", "utility/dispose_functions", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_dotnetstl_utility_dispose_functions(test_dotnetstl_utility_dispose_functions);
	} // anonymous namespace

} // namespace unittest
