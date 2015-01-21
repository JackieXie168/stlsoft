
// Updated: 6th July 2006

#if !defined(ATLSTL_INCL_ATLSTL_STRING_HPP_STRING_TRAITS)
# error This file cannot be directly included, and should only be included within atlstl/string/string_traits.hpp
#endif /* !ATLSTL_INCL_ATLSTL_STRING_HPP_STRING_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl_string_traits(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "string/string_traits", __FILE__);

#if 0
			if(<<VOID>>)
			{
				r->report("<<VOID>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_string_traits(test_atlstl_string_traits);
	} // anonymous namespace

} // namespace unittest
