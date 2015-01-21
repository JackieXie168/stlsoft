
// Updated: 12th April 2007

#if !defined(RANGELIB_INCL_RANGELIB_HPP_ALGORITHMS)
# error This file cannot be directly included, and should only be included within rangelib/algorithms.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_ALGORITHMS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		int mult(int a, int b)
		{
			return a * b;
		}

		int is_odd(int i)
		{
			return 0 != (i & 1);
		}

		ss_bool_t test_rangelib_algorithms(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "RangeLib", "algorithms", __FILE__);

			integral_range<int> 				r0(-10, 10);
			std::vector<int>					v1;

			r_copy(r0, std::back_inserter(v1));

			sequence_range<std::vector<int> >	r1(v1);

			if(v1.empty())
			{
				r->report("v1 is empty", __LINE__);
				bSuccess = false;
			}

			if(20 != v1.size())
			{
				r->report("v1 does not have 20 elements", __LINE__);
				bSuccess = false;
			}

			// r_accumulate()

			if(-10 != r_accumulate(r0, 0))
			{
				r->report("r_accumulate() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(-10 != r_accumulate(r1, 0))
			{
				r->report("r_accumulate() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_accumulate() + pred

			std::vector<int>					v2;

			r_copy_if(r1, std::back_inserter(v2), is_odd);

			sequence_range<std::vector<int> >	r2(v2);

			if(-893025 != r_accumulate(r2, 1, mult))
			{
				r->report("r_accumulate() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_count()

			if(1 != r_count(r0, 1))
			{
				r->report("r_count() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(1 != r_count(r1, 1))
			{
				r->report("r_count() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(1 != r_count(r2, 1))
			{
				r->report("r_count() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_count_if()

			if(10 != r_count_if(r0, is_odd))
			{
				r->report("r_count_if() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(10 != r_count_if(r1, is_odd))
			{
				r->report("r_count_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(10 != r_count_if(r2, is_odd))
			{
				r->report("r_count_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(10 != r_count_if(r0, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_count_if() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(10 != r_count_if(r1, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_count_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(0 != r_count_if(r2, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_count_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_distance()

			if(20 != r_distance(r0))
			{
				r->report("r_distance() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(20 != r_distance(r1))
			{
				r->report("r_distance() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(10 != r_distance(r2))
			{
				r->report("r_distance() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_equal()

			if(!r_equal(r0, r0))
			{
				r->report("r_equal() [notional + notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_equal(r0, r1))
			{
				r->report("r_equal() [notional + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_equal(r1, r0))
			{
				r->report("r_equal() [iterable + notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_equal(r1, r1))
			{
				r->report("r_equal() [iterable + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_equal(r2, r2))
			{
				r->report("r_equal() [iterable + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_equal(r0, r2))
			{
				r->report("r_equal() [notional + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_equal(r2, r0))
			{
				r->report("r_equal() [iterable + notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_equal(r1, r2))
			{
				r->report("r_equal() [iterable + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_equal(r2, r1))
			{
				r->report("r_equal() [iterable + iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_exists()

			if(!r_exists(r0, -10))
			{
				r->report("r_exists() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_exists(r0, 10))
			{
				r->report("r_exists() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_exists(r1, -10))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_exists(r1, 10))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_exists_if()

			if(!r_exists_if(r0, is_odd))
			{
				r->report("r_exists() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_exists_if(r0, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_exists() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_exists_if(r1, is_odd))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_exists_if(r1, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(!r_exists_if(r2, is_odd))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(r_exists_if(r2, std::not1(std::ptr_fun(is_odd))))
			{
				r->report("r_exists() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_fill()

			// r_fill_n()

			// r_find()

			if(0 == r_distance(r_find(r1, -10)))
			{
				r->report("r_find() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(0 != r_distance(r_find(r1, 10)))
			{
				r->report("r_find() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_find_if()

			if(0 == r_distance(r_find_if(r1, is_odd)))
			{
				r->report("r_find_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(0 == r_distance(r_find_if(r1, std::not1(std::ptr_fun(is_odd)))))
			{
				r->report("r_find_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(0 == r_distance(r_find_if(r2, is_odd)))
			{
				r->report("r_find_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(0 != r_distance(r_find_if(r2, std::not1(std::ptr_fun(is_odd)))))
			{
				r->report("r_find_if() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}


			// r_for_each()

			// r_generate()


			// r_max_element()

			if(9 != r_max_element(r0))
			{
				r->report("r_max_element() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(9 != r_max_element(r1))
			{
				r->report("r_max_element() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(9 != r_max_element(r2))
			{
				r->report("r_max_element() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			// r_min_element()

			if(-10 != r_min_element(r0))
			{
				r->report("r_min_element() [notional range] failed ", __LINE__);
				bSuccess = false;
			}

			if(-10 != r_min_element(r1))
			{
				r->report("r_min_element() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			if(-9 != r_min_element(r2))
			{
				r->report("r_min_element() [iterable range] failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_rangelib_algorithms(test_rangelib_algorithms);
	} // anonymous namespace

} // namespace unittest
