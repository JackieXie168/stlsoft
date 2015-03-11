
#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_COLLECTION)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/collection.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_COLLECTION */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_collection_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "collection_algorithms", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_collection_algorithms(test_stlsoft_collection_algorithms);
	} // anonymous namespace

} // namespace unittest
