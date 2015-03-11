
// Updated: 12th February 2006

#if !defined(MFCSTL_INCL_MFCSTL_CONTAINERS_HPP_CARRAY_TRAITS)
# error This file cannot be directly included, and should only be included within mfcstl/containers/carray_traits.hpp
#endif /* !MFCSTL_INCL_MFCSTL_CONTAINERS_HPP_CARRAY_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_mfcstl_containers_carray_traits(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "MFCSTL", "containers/carray_traits", __FILE__);

            STLSOFT_SUPPRESS_UNUSED(bSuccess);

            return bSuccess;
        }

        unittest_registrar    unittest_mfcstl_containers_carray_traits(test_mfcstl_containers_carray_traits);
    } // anonymous namespace

} // namespace unittest
