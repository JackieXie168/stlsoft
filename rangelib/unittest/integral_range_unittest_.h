
#if !defined(RANGELIB_INCL_RANGELIB_HPP_INTEGRAL_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/integral_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_INTEGRAL_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{

		ss_bool_t test_stlsoft_rangelib_integral_range(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "RangeLib", "integral_range", __FILE__);

			typedef integral_range<int> intrange_t;

			intrange_t	r1(0, 10, 1);
			int 		sum;

			for(sum = 0; r1; ++r1)
			{
				sum += *r1;
			}

			if(45 != sum)
			{
				r->report("manual enumeration failed", __LINE__);
				bSuccess = false;
			}

			if(r1.is_open())
			{
				r->report("closed range presents as open (is_open() method)", __LINE__);
				bSuccess = false;
			}

			if(r1)
			{
				r->report("closed range presents as open (operator \"bool\"())", __LINE__);
				bSuccess = false;
			}

			if(intrange_t(1000, 1000, 1000))
			{
				r->report("closed range presents as open", __LINE__);
				bSuccess = false;
			}

	# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			typedef integral_range<ss_sint64_t, invalid_integral_range_policy>	uint_range_x_t;
	# else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
			typedef integral_range<ss_sint32_t, invalid_integral_range_policy>	uint_range_x_t;
	# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			try
			{
				uint_range_x_t	r2(10, 0, 1);

				r->report("failed to detect invalid range (wrong direction)", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &/* x */)
			{}

			try
			{
				uint_range_x_t	r3(-100, 0, 3);

				r->report("failed to detect invalid range (modulus error)", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &/* x */)
			{}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_rangelib_integral_range(test_stlsoft_rangelib_integral_range);
	} // anonymous namespace

} // namespace unittest

