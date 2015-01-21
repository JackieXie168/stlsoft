
#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_UNORDERED)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/unordered.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_UNORDERED */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_unordered_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "unordered_algorithms", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_unordered_algorithms(test_stlsoft_unordered_algorithms);
	} // anonymous namespace

} // namespace unittest
