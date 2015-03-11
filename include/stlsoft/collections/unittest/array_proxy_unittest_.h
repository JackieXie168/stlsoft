
// Updated: 6th July 2006

#if !defined(STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_ARRAY_PROXY)
# error This file cannot be directly included, and should only be included within stlsoft/collections/array_proxy.hpp
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_ARRAY_PROXY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_array_proxy(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "collections/array_proxy", __FILE__);

//			  static const int		  ints[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

//			  array_proxy<int>		  ap1(static_cast<int*>(NULL), 0);

//			  array_proxy<int>		  ap2(&ints[0], STLSOFT_NUM_ELEMENTS(ints));

	#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
	#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_array_proxy(test_stlsoft_array_proxy);
	} // anonymous namespace

} // namespace unittest
