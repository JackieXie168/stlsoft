
#if !defined(COMSTL_INCL_COMSTL_H_BSTR_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/bstr_functions.h
#endif /* !COMSTL_INCL_COMSTL_H_BSTR_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_bstr_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "bstr_functions", __FILE__);

            BSTR    bstr1   =   bstr_create("Hello, Sailor!");
            BSTR    bstr2   =   bstr_create(L"Hello, Sailor!");

            if( NULL != bstr1 &&
                NULL != bstr2 &&
                0 != wcscmp(bstr1, bstr2))
            {
                r->report("BSTR (ANSI + Unicode) creation failed", __LINE__);
                bSuccess = false;
            }

            bstr_destroy(bstr1);
            bstr_destroy(bstr2);

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_bstr_functions(test_comstl_bstr_functions);
    } // anonymous namespace

} // namespace unittest
