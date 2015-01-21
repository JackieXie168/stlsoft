
// Updated: 18th July 2006

#if !defined(STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC)
# error This file cannot be directly included, and should only be included within stlsoft/error/error_desc.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_error_desc(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "exceptions/error_desc", __FILE__);

			try
			{
				error_desc		ed1(ENOMEM);

				if(0 != ::strcmp(ed1.get_description(), ed1.c_str()))
				{
					r->report("get_description() and c_str() returned different values", __LINE__);
					bSuccess = false;
				}
			}
			catch(std::exception &)
			{}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_error_desc(test_stlsoft_error_desc);
	} // anonymous namespace

} // namespace unittest
