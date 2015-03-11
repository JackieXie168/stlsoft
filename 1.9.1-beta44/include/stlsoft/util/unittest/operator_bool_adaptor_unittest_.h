
// Updated: 6th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL_ADAPTOR)
# error This file cannot be directly included, and should only be included within stlsoft/util/operator_bool_adaptor.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_OPERATOR_BOOL_ADAPTOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_util_operator_bool_adaptor(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "operator_adaptors", __FILE__);

#if 0
			if(NULL != pi1)
			{
				ator1.construct(pi1, 1968);

				if(1968 != *pi1)
				{
					r->report("construct() failed ", __LINE__);
					bSuccess = false;
				}
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_util_operator_bool_adaptor(test_stlsoft_util_operator_bool_adaptor);
	} // anonymous namespace

} // namespace unittest
