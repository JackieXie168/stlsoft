
#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_MEMBER_SELECTOR_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/member_selector_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_MEMBER_SELECTOR_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8061
#endif /* STLSOFT_COMPILER_IS_BORLAND */

        struct MSI_Thing
        {
            size_t  n;
        };

        ss_bool_t test_stlsoft_iterators_member_selector_iterator(unittest_reporter *r)
        {
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
            using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "iterators/member_selector_iterator", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
	!defined(STLSOFT_COMPILER_IS_DMC)
            const MSI_Thing         ai[]    =   { { 0 }, { 1 }, { 2 }, { 4 }, { 8 }, { 16 }, { 32 }, { 64 }, { 128 } };
            const MSI_Thing         aci[]   =   { { 0 }, { 1 }, { 2 }, { 4 }, { 8 }, { 16 }, { 32 }, { 64 }, { 128 } };

            typedef member_selector_iterator<MSI_Thing const*, MSI_Thing, const size_t> MSI_Thing_len_const_iterator_t;
            typedef member_selector_iterator<MSI_Thing*, MSI_Thing, size_t>             MSI_Thing_len_iterator_t;

            { MSI_Thing_len_const_iterator_t    it1(&aci[0], &MSI_Thing::n);
              size_t                            i;

            for(i = 0; i < STLSOFT_NUM_ELEMENTS(aci); ++i, ++it1)
            {
                if(aci[i].n != *it1)
                {
                    r->report("member_selector_iterator subscript access failed", __LINE__);
                    bSuccess = false;
                }
            }}

            {
                MSI_Thing_len_const_iterator_t  it2(&aci[0], &MSI_Thing::n);

                if(*(it2 + 2) != aci[2].n)
                {
                    r->report("member_selector_iterator offset failed", __LINE__);
                    bSuccess = false;
                }
            }

            {
                MSI_Thing_len_const_iterator_t  it3(&aci[0], &MSI_Thing::n);
                MSI_Thing_len_const_iterator_t  it4 = it3 + 3;

                if(3 != it4 - it3)
                {
                    r->report("member_selector_iterator subtraction failed", __LINE__);
                    bSuccess = false;
                }
            }

            STLSOFT_SUPPRESS_UNUSED(ai);
#else
			STLSOFT_SUPPRESS_UNUSED(bSuccess);
#endif /* compiler */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_iterators_member_selector_iterator(test_stlsoft_iterators_member_selector_iterator);

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8061
#endif /* STLSOFT_COMPILER_IS_BORLAND */
    } // anonymous namespace

} // namespace unittest
