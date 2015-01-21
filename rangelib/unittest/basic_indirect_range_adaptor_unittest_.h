
#if !defined(RANGELIB_INCL_RANGELIB_HPP_BASIC_INDIRECT_RANGE_ADAPTOR)
# error This file cannot be directly included, and should only be included within rangelib/basic_indirect_range_adaptor.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_BASIC_INDIRECT_RANGE_ADAPTOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_rangelib_indirect_range_adaptors(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "indirect_range_adaptors", __FILE__);

#if 0
            if(
            {
                r->report("construct() failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_rangelib_indirect_range_adaptors(test_rangelib_indirect_range_adaptors);
    } // anonymous namespace

} // namespace unittest

