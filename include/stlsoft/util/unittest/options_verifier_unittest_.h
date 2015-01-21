
// Updated: 13th September 2006

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_OPTIONS_VERIFIER)
# error This file cannot be directly included, and should only be included within stlsoft/util/options_verifier.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPTIONS_VERIFIER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_stlsoft_options_verifier(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/stlsoft/options_verifier", __FILE__);

#if 0
			try
			{
				const int	i	=	4;

# if 0
				verify_options(i, "i was not a valid value"), 0, 1, 2, 3, 4;
# else /* ? 0 */
				verify_options(i, "i was not a valid value") == 0 || 1 || 2 || 3 || 4;
# endif /* 0 */
			}
			catch(option_verification_exception &/* x */)
			{
				r->report("Option was erroneously reported as not in valid set", __LINE__);
				bSuccess = false;
			}

			try
			{
				const std::string	s	=	"ghi";

# if 0
				verify_options(s, "s was not a valid value"), "abc", "def", "ghi", "jkl", "mno";
# else /* ? 0 */
				verify_options(s, "s was not a valid value")== "abc" || "def" || "ghi" || "jkl" || "mno";
# endif /* 0 */
			}
			catch(option_verification_exception &/* x */)
			{
				r->report("Option was erroneously reported as not in valid set", __LINE__);
				bSuccess = false;
			}

			try
			{
				const int	i	=	4444;

# if 0
				verify_options(i, "i was not a valid value"), 0, 1, 2, 3, 4;
# else /* ? 0 */
				verify_options(i, "i was not a valid value") == 0 || 1 || 2 || 3 || 4;
# endif /* 0 */

				r->report("Option was erroneously reported as in valid set", __LINE__);
				bSuccess = false;
			}
			catch(option_verification_exception &/* x */)
			{
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_stlsoft_options_verifier(test_stlsoft_stlsoft_options_verifier);
	} // anonymous namespace

} // namespace unittest
