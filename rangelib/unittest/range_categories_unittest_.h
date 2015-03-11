
#if !defined(RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES)
# error This file cannot be directly included, and should only be included within rangelib/range_categories.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_RANGE_CATEGORIES */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_rangelib_range_categories(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "range_categories", __FILE__);

            // Just check the relationship between the indirect ranges
            const indirect_range_tag        irt     =   indirect_range_tag();
            basic_indirect_range_tag const  &birt   =   irt;

            STLSOFT_SUPPRESS_UNUSED(birt);

            return bSuccess;
        }

        unittest_registrar    unittest_rangelib_range_categories(test_rangelib_range_categories);
    } // anonymous namespace

} // namespace unittest

