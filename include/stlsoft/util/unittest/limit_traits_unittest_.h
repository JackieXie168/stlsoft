
// Updated: 13th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS)
# error This file cannot be directly included, and should only be included within stlsoft/util/limit_traits.h
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_util_limit_traits(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/limit_traits", __FILE__);

			// bool
			limit_traits<ss_bool_t>::minimum();
			limit_traits<ss_bool_t>::maximum();

			// signed char
			limit_traits<signed char>::minimum();
			limit_traits<signed char>::maximum();

			// unsigned char
			limit_traits<unsigned char>::minimum();
			limit_traits<unsigned char>::maximum();

			// signed short
			limit_traits<signed short>::minimum();
			limit_traits<signed short>::maximum();

			// unsigned short
			limit_traits<unsigned short>::minimum();
			limit_traits<unsigned short>::maximum();

			// signed int
			limit_traits<signed int>::minimum();
			limit_traits<signed int>::maximum();

			// unsigned int
			limit_traits<unsigned int>::minimum();
			limit_traits<unsigned int>::maximum();

			// signed long
			limit_traits<signed long>::minimum();
			limit_traits<signed long>::maximum();

			// unsigned long
			limit_traits<unsigned long>::minimum();
			limit_traits<unsigned long>::maximum();

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_util_limit_traits(test_stlsoft_util_limit_traits);
	} // anonymous namespace

} // namespace unittest
