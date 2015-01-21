
// Updated: 14th January 2006

#if !defined(STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_EXTERNAL_ITERATOR_INVALIDATION)
# error This file cannot be directly included, and should only be included within stlsoft/exceptions/active_end_iterator_exhaustion.hpp
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_HPP_EXTERNAL_ITERATOR_INVALIDATION */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_external_iterator_invalidation(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "exceptions/external_iterator_invalidation", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_external_iterator_invalidation(test_stlsoft_external_iterator_invalidation);
	} // anonymous namespace

} // namespace unittest
