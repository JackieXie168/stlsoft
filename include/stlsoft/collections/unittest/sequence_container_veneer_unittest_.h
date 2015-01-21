
// Updated: 5th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_SEQUENCE_CONTAINER_VENEER)
# error This file cannot be directly included, and should only be included within stlsoft/collections/sequence_container_veneer.hpp
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_SEQUENCE_CONTAINER_VENEER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
# if (   defined(STLSOFT_COMPILER_IS_MSVC) || \
         (   defined(STLSOFT_COMPILER_IS_INTEL) && \
             defined(WIN32))) && \
     _MSC_VER < 1300
 // Can't do it, because stupid Dinkumware headers are chocca with warnings
# else /* ? compiler */
    namespace
    {
        struct null_int_functor
        {
        public:
            void operator ()(int const &)
            {}
        };

        ss_bool_t test_stlsoft_collections_sequence_container_veneer(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "collections/sequence_container_veneer", __FILE__);

            typedef stlsoft_ns_qual_std(list)<int>      list_t;
            typedef stlsoft_ns_qual_std(vector)<int>    vector_t;

            sequence_container_veneer<list_t, null_int_functor>     l;
            sequence_container_veneer<vector_t, null_int_functor>   v;
            int                                                     i;
            int                                                     total;

            for(i = 0, total = 0; i < 10; ++i)
            {
                l.push_front(i);
                v.push_back(i);

                total += i;
            }

            if(stlsoft_ns_qual_std(accumulate)(l.begin(), l.end(), static_cast<long>(0)) != total)
            {
                r->report("sequence_container_veneer<list> contents (forward iteration) test failed", __LINE__);
                bSuccess = false;
            }

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
            if(stlsoft_ns_qual_std(accumulate)(l.rbegin(), l.rend(), static_cast<long>(0)) != total)
            {
                r->report("sequence_container_veneer<list> contents (forward iteration) test failed", __LINE__);
                bSuccess = false;
            }
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

            if(stlsoft_ns_qual_std(accumulate)(v.begin(), v.end(), static_cast<long>(0)) != total)
            {
                r->report("sequence_container_veneer<vector> contents (forward iteration) test failed", __LINE__);
                bSuccess = false;
            }

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
            if(stlsoft_ns_qual_std(accumulate)(v.rbegin(), v.rend(), static_cast<long>(0)) != total)
            {
                r->report("sequence_container_veneer<vector> contents (forward iteration) test failed", __LINE__);
                bSuccess = false;
            }
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_collections_sequence_container_veneer(test_stlsoft_collections_sequence_container_veneer);
    } // anonymous namespace

# endif /* compiler */

} // namespace unittest

