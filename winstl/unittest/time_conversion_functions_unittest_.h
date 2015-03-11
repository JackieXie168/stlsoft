
#if !defined(WINSTL_INCL_WINSTL_H_TIME_CONVERSION_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/time_conversion_functions.h
#endif /* !WINSTL_INCL_WINSTL_H_TIME_CONVERSION_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_time_conversion_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "time_conversion_functions", __FILE__);

            time_t                  t   =   ::time(NULL);
            FILETIME                ft1;
            FILETIME                ft2;
            time_t                  t1;
            time_t                  t2;
            ws_sint32_t             usec1;
            ws_sint32_t             usec2;

            winstl__UNIXTimeToFILETIME(t, &ft1);
            winstl__UNIXTimeToFILETIME_us(t, 0, &ft2);

            t1  =   winstl__FILETIMEToUNIXTime(&ft1, &usec1);
            t2  =   winstl__FILETIMEToUNIXTime(&ft2, &usec2);

            STLSOFT_SUPPRESS_UNUSED(t1);
            STLSOFT_SUPPRESS_UNUSED(t2);
            

#if 0
            typedef message_queue_sequence<char>    env_var_t;

            env_var_t   path("PATH");

            if(0 != strcmp(getenv("PATH"), path))
            {
                r->report("message_queue_sequence<char> failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_time_conversion_functions(test_winstl_time_conversion_functions);
    } // anonymous namespace

} // namespace unittest