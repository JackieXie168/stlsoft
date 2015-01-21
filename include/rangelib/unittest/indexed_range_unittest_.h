
#if !defined(RANGELIB_INCL_RANGELIB_HPP_INDEXED_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/indexed_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_INDEXED_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{

		ss_bool_t test_stlsoft_rangelib_indexed_range(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "RangeLib", "indexed_range", __FILE__);

			typedef integral_range<int> int_range_t;

			{ for(indexed_range<int_range_t> rng(int_range_t(0, 1000, 1)); rng; ++rng)
			{
				if(rng.index() != *rng)
				{
					r->report("indexes mismatch", __LINE__);
					bSuccess = false;
					break;
				}
			}}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_rangelib_indexed_range(test_stlsoft_rangelib_indexed_range);
	} // anonymous namespace

} // namespace unittest
