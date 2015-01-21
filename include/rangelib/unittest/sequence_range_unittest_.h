
#if !defined(RANGELIB_INCL_RANGELIB_HPP_SEQUENCE_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/sequence_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_SEQUENCE_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		template <ss_typename_param_k T>
		ss_bool_t test_container()
		{
			typedef ss_typename_type_k T::value_type	value_t;

			T			cont;
			value_t 	total0	=	0;
			value_t 	total1	=	0;

			STLSOFT_SUPPRESS_UNUSED(total0);	// Borland
			STLSOFT_SUPPRESS_UNUSED(total1);	// Borland

			for(int i = 0; i < 100; i += 5)
			{
				cont.push_back(value_t(i));
			}

			for(sequence_range<T> range(cont); range; ++range)
			{
				total0 += *range;
			}

			total1 = std::accumulate(cont.begin(), cont.end(), value_t(0));

			if(total1 == total0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		ss_bool_t test_rangelib_sequence_range(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "RangeLib", "sequence_range", __FILE__);

			if(!test_container<std::list<int> >())
			{
				r->report("summation over list<int> failed", __LINE__);
				bSuccess = false;
			}

			if(!test_container<std::vector<int> >())
			{
				r->report("summation over vector<int> failed", __LINE__);
				bSuccess = false;
			}

			if(!test_container<std::deque<int> >())
			{
				r->report("summation over deque<short> failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_rangelib_sequence_range(test_rangelib_sequence_range);
	} // anonymous namespace

} // namespace unittest

