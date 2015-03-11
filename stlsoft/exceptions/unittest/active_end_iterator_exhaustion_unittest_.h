
// Updated: 14th January 2006

#if !defined(STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION)
# error This file cannot be directly included, and should only be included within stlsoft/exceptions/active_end_iterator_exhaustion.hpp
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_ACTIVE_END_ITERATOR_EXHAUSTION */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_active_end_iterator_exhaustion(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "exceptions/active_end_iterator_exhaustion", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_active_end_iterator_exhaustion(test_stlsoft_active_end_iterator_exhaustion);
	} // anonymous namespace

} // namespace unittest
