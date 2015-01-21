
#if !defined(WINSTL_INCL_WINSTL_H_TIME_COMPARISON_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/time_comparison_functions.h
#endif /* !WINSTL_INCL_WINSTL_H_TIME_COMPARISON_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_time_comparison_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "time_comparison_functions", __FILE__);

            FILETIME                ftNow;
            SYSTEMTIME              stNow;

#if 0
            FILETIME                ftThen;
            SYSTEMTIME              stThen;
#endif /* 0 */

            ::GetSystemTimeAsFileTime(&ftNow);
            ::GetSystemTime(&stNow);

            if(0 != compare(ftNow, ftNow))
            {
                r->report("compare(FILETIME, FILETIME) failed to compare equal", __LINE__);
                bSuccess = false;
            }

            if(0 > compare(ftNow, stNow))
            {
                r->report("compare(FILETIME, SYSTEMTIME) failed to compare less then or equal", __LINE__);
                bSuccess = false;
            }

#if 0
            inline ws_sint_t 
            inline ws_sint_t compare(FILETIME const &lhs, SYSTEMTIME const &rhs)
            inline ws_sint_t compare(SYSTEMTIME const &lhs, FILETIME const &rhs)
            inline ws_sint_t compare(SYSTEMTIME const &lhs, SYSTEMTIME const &rhs)
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_time_comparison_functions(test_winstl_time_comparison_functions);
    } // anonymous namespace

} // namespace unittest
