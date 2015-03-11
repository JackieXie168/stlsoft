
// Updated: 15th September 2006

#if !defined(MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CLIST_TRAITS)
# error This file cannot be directly included, and should only be included within mfcstl/collections/clist_traits.hpp
#endif /* !MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CLIST_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_collections_clist_traits(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "collections/clist_traits", __FILE__);

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_collections_clist_traits(test_mfcstl_collections_clist_traits);
	} // anonymous namespace

} // namespace unittest

