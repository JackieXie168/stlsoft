
#if !defined(WINSTL_INCL_WINSTL_HPP_CHAR_CONVERSIONS)
# error This file cannot be directly included, and should only be included within winstl/char_conversions.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_CHAR_CONVERSIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_char_conversions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "char_conversion", __FILE__);

            if(0 != strcmp("String #1", w2a(L"String #1")))
            {
                r->report("w2a failed", __LINE__);
                bSuccess = false;
            }

            if(0 != wcscmp(L"String #1", a2w("String #1")))
            {
                r->report("a2w failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_char_conversions(test_winstl_char_conversions);
    } // anonymous namespace

} // namespace unittest
