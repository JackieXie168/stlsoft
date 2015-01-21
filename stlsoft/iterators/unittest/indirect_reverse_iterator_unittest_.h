
// Updated: 26th December 2005

#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_INDIRECT_REVERSE_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/indirect_reverse_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_INDIRECT_REVERSE_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_iterators_indirect_reverse_iterator(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "iterators/indirect_reverse_iterator", __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_iterators_indirect_reverse_iterator(test_stlsoft_iterators_indirect_reverse_iterator);
	} // anonymous namespace

} // namespace unittest

