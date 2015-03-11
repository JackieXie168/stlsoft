
// Updated: 16th July 2006

#if !defined(WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS)
# error This file cannot be directly included, and should only be included within winstl/error/exceptions.hpp
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_EXCEPTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_exceptions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "error/exceptions", __FILE__);

			windows_exception		x1(ERROR_NOT_ENOUGH_MEMORY);
			windows_exception		x2(ERROR_FILE_EXISTS);

			x1.what();
			x1.get_error_code();
			x1.last_error();
			x1.strerror();

			x2.what();
			x2.get_error_code();
			x2.last_error();
			x2.strerror();

			windows_exception		x3(x1);
			windows_exception		x4(x2);

	#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_exceptions(test_winstl_exceptions);
	} // anonymous namespace

} // namespace unittest
