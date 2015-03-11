
// Updated: 6th June 2006

#if !defined(WINSTL_INCL_WINSTL_ERROR_HPP_ERROR_DESC)
# error This file cannot be directly included, and should only be included within winstl/error/error_desc.hpp
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_ERROR_DESC */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_error_error_desc(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "error/error_desc", __FILE__);

			try
			{
				error_desc		ed1(ERROR_ACCESS_DENIED);

				if(0 != lstrcmp(ed1.get_description(), ed1.c_str()))
				{
					r->report("get_description() and c_str() returned different values", __LINE__);
					bSuccess = false;
				}
			}
			catch(std::exception &)
			{}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_error_error_desc(test_winstl_error_error_desc);
	} // anonymous namespace

} // namespace unittest
