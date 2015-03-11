
#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/filter_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_FILTER_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_iterators_filter_iterator(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "iterators/filter_iterator", __FILE__);

#if 0
			if(NULL != pi1)
			{
				ator1.construct(pi1, 1968);

				if(1968 != *pi1)
				{
					r->report("construct() failed ", __LINE__);
					bSuccess = false;
				}
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_iterators_filter_iterator(test_stlsoft_iterators_filter_iterator);
	} // anonymous namespace

} // namespace unittest

