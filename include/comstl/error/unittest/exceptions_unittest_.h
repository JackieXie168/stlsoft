
// Updated: 4th January 2007

#if !defined(COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS)
# error This file cannot be directly included, and should only be included within comstl/error/exceptions.hpp
#endif /* !COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_error_exceptions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "error/exceptions", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_error_exceptions(test_comstl_error_exceptions);
	} // anonymous namespace

} // namespace unittest
