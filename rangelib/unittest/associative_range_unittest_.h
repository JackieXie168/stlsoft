
#if !defined(RANGELIB_INCL_RANGELIB_HPP_ASSOCIATIVE_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/associative_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_ASSOCIATIVE_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace associative_range_util
		{
			template <ss_typename_param_k T>
			ss_bool_t test_container()
			{
				typedef ss_typename_type_k T::key_type											key_t;
#if defined(STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED)
				typedef ss_typename_type_k associative_mapped_type_detector<T>::mapped_type 	mapped_t;
#else /* ? STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */
				typedef ss_typename_type_k T::mapped_type										mapped_t;
#endif /* STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */

				T			cont;
				mapped_t	total0	=	0;
				mapped_t	total1	=	0;

				for(key_t i = 0; i < key_t(100); i += key_t(5))
				{
					cont[i] = mapped_t(1.1) * i;

					total0 += cont[i];
				}

				for(associative_range<T> range(cont); range; ++range)
				{
					total1 += (*range).second;
				}

				return total0 == total1;
			}
		} // namespace associative_range_util

		ss_bool_t test_rangelib_associative_range(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "RangeLib", "associative_range", __FILE__);

#if !defined(STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED) && \
	defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
	STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION <= STLSOFT_CF_DINKUMWARE_VC_VERSION_6_0
			// Do nothing, since std::map has 'referent_type', not 'mapped_type'

#else /* ? 'referent_type' */

			{ typedef ::std::map<int, int>	map_t;	// Must have separate typedef, otherwise CodeWarrior gets the sniffles
				if(!associative_range_util::test_container<map_t>())
				{
					r->report("summation over map<int, int> failed", __LINE__);
					bSuccess = false;
				}
			}

			{ typedef ::std::map<short, double> 	map_t;	// Must have separate typedef, otherwise CodeWarrior gets the sniffles
				if(!associative_range_util::test_container<map_t>())
				{
					r->report("summation over map<short, double> failed", __LINE__);
					bSuccess = false;
				}
			}
#endif /* 'referent_type' */

			return bSuccess;
		}

		unittest_registrar	  unittest_rangelib_associative_range(test_rangelib_associative_range);

	} // anonymous namespace

} // namespace unittest

