
// Updated: 21st January 2007

#if !defined(STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_ARRAY_VIEW)
# error This file cannot be directly included, and should only be included within stlsoft/collections/array_view.hpp
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_ARRAY_VIEW */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_collections_array_view(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "collections/array_view", __FILE__);

			{
				int 						ar[10];

				stlsoft::array_view<int>	av(&ar[0], STLSOFT_NUM_ELEMENTS(ar));

				av.base();
				av.size();
				av.empty();
				av.max_size();

				(void)av[0];
				(void)av.at(1);

				av.begin();
				av.end();
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
				av.rbegin();
				av.rend();
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
			}


#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_collections_array_view(test_stlsoft_collections_array_view);
	} // anonymous namespace

} // namespace unittest
