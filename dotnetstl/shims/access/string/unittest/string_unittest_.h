
// Updated: 14th July 2006

#if !defined(DOTNETSTL_INCL_DOTNETSTL_SHIMS_ACCESS_STRING_HPP_STRING)
# error This file cannot be directly included, and should only be included within dotnetstl/shims/access/string/string.hpp
#endif /* !DOTNETSTL_INCL_DOTNETSTL_SHIMS_ACCESS_STRING_HPP_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_dotnetstl_shims_access_string_string(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, ".netSTL", "shims/access/string/string.hpp", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_dotnetstl_shims_access_string_string(test_dotnetstl_shims_access_string_string);
	} // anonymous namespace

} // namespace unittest
