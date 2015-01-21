
#if !defined(RANGELIB_INCL_RANGELIB_HPP_ITERATOR_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/iterator_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_ITERATOR_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace iterator_range_util
    {
        template <ss_typename_param_k T>
        ss_bool_t test_container()
        {
            T           cont;
            int         total0  =   0;
            int         total1  =   0;

            for(int i = 0; i < 100; i += 5)
            {
#if defined(STLSOFT_COMPILER_IS_DMC)
                typedef ss_typename_type_k T::value_type    value_t;

                cont.push_back(value_t(i));
#else /* ? compiler */
                cont.push_back(ss_typename_type_k T::value_type(i));
#endif /* compiler */
            }

            for(iterator_range<ss_typename_type_k T::iterator> range(cont.begin(), cont.end()); range; ++range)
            {
                total0 += *range;
            }

#if defined(STLSOFT_COMPILER_IS_DMC)
            typedef ss_typename_type_k T::value_type    value_t;

            total1 = std::accumulate(cont.begin(), cont.end(), value_t(0));
#else /* ? compiler */
            total1 = std::accumulate(cont.begin(), cont.end(), ss_typename_type_k T::value_type(0));
#endif /* compiler */

            return total0 == total1;
        }
    } // namespace iterator_range_util

    ss_bool_t test_rangelib_iterator_range(unittest_reporter *r)
    {
        using stlsoft::unittest::unittest_initialiser;

        ss_bool_t               bSuccess    =   true;

        unittest_initialiser    init(r, "RangeLib", "iterator_range", __FILE__);

        if(!iterator_range_util::test_container<std::list<int> >())
        {
            r->report("summation over list<int> failed", __LINE__);
            bSuccess = false;
        }

        if(!iterator_range_util::test_container<std::vector<int> >())
        {
            r->report("summation over vector<int> failed", __LINE__);
            bSuccess = false;
        }

        if(!iterator_range_util::test_container<std::deque<short> >())
        {
            r->report("summation over deque<short> failed", __LINE__);
            bSuccess = false;
        }

        return bSuccess;
    }

    unittest_registrar    unittest_rangelib_iterator_range(test_rangelib_iterator_range);

} // namespace unittest

