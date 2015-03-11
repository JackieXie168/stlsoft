
// Updated: 6th January 2007

#if !defined(MFCSTL_INCL_MFCSTL_STRING_HPP_STRING_TRAITS)
# error This file cannot be directly included, and should only be included within mfcstl/string/string_traits.hpp
#endif /* !MFCSTL_INCL_MFCSTL_STRING_HPP_STRING_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_string_string_traits(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "string/string_traits", __FILE__);

#if 0
			if(<<VOID>>)
			{
				r->report("<<VOID>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_string_string_traits(test_mfcstl_string_string_traits);
	} // anonymous namespace

} // namespace unittest
