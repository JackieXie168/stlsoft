
#if !defined(RANGELIB_INCL_RANGELIB_HPP_CSTRING_RANGE)
# error This file cannot be directly included, and should only be included within rangelib/cstring_range.hpp
#endif /* !RANGELIB_INCL_RANGELIB_HPP_CSTRING_RANGE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {

        ss_bool_t test_stlsoft_rangelib_cstring_range(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "RangeLib", "cstring_range", __FILE__);

            typedef cstring_range<char> cstring_range_t;

            cstring_range_t r1("Hello, Natty!");
            size_t          len;

            for(len = 0; r1; ++r1, ++len)
            {}

            if(13 != len)
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

            if(cstring_range_t(""))
            {
                r->report("closed range presents as open", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_rangelib_cstring_range(test_stlsoft_rangelib_cstring_range);
    } // anonymous namespace

} // namespace unittest

