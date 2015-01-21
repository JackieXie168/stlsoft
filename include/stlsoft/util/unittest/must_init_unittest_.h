
// Updated: 28th December 2005

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT)
# error This file cannot be directly included, and should only be included within stlsoft/util/must_init.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_util_must_init(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/must_init", __FILE__);

#if 0
			{
				must_init		xs1;

				if(!xs1.empty())
				{
					r->report("empty() returned erroneous value", __LINE__);
					bSuccess = false;
				}
			}

			{
				must_init		xs2("1");

				if(xs2.empty())
				{
					r->report("empty() returned erroneous value", __LINE__);
					bSuccess = false;
				}

				if(0 != ::strcmp("1", xs2.c_str()))
				{
					r->report("c_str() returned erroneous value", __LINE__);
					bSuccess = false;
				}
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_util_must_init(test_stlsoft_util_must_init);
	} // anonymous namespace

} // namespace unittest
