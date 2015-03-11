
// Updated: 22nd January 2006

#if !defined(WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/time_format_functions.h
#endif /* !WINSTL_INCL_WINSTL_H_TIME_FORMAT_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_time_format_functions_withPicture(unittest_reporter   *r
                                                            ,   SYSTEMTIME const    &t
                                                            ,   ws_char_a_t const   *picture
                                                            ,   ws_char_a_t const   *result)
        {
            ss_bool_t               bSuccess    =   true;
            ws_char_a_t             sz[201];

            if(0 == GetTimeFormat_msA(LOCALE_USER_DEFAULT, 0, &t, picture, &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msA() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else if(0 != ::lstrcmpA(&sz[0], result))
            {
                r->report("GetTimeFormat_msA() failed: wrongly formatted", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }
        ss_bool_t test_winstl_time_format_functions_withPicture(unittest_reporter   *r
                                                            ,   SYSTEMTIME const    &t
                                                            ,   ws_char_w_t const   *picture
                                                            ,   ws_char_w_t const   *result)
        {
            ss_bool_t               bSuccess    =   true;
            ws_char_w_t             sz[201];

            if(0 == GetTimeFormat_msW(LOCALE_USER_DEFAULT, 0, &t, picture, &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msW() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else if(0 != ::lstrcmpW(&sz[0], result))
            {
                r->report("GetTimeFormat_msW() failed: wrongly formatted", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_winstl_time_format_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            typedef stlsoft_ns_qual(auto_buffer_old)<   char
                                                    ,   processheap_allocator<char>
                                                    >                   buffer_a_t;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "time_format_functions", __FILE__);

            char                    sz[201];
            SYSTEMTIME              st;

            st.wYear            =   2005;
            st.wMonth           =   4;
            st.wDayOfWeek       =   3;
            st.wDay             =   27;
            st.wHour            =   12;
            st.wMinute          =   46;
            st.wSecond          =   01;
            st.wMilliseconds    =   333;

            HKEY        hkey;
            LONG        res =   ::RegOpenKey(HKEY_CURRENT_USER, "Control Panel\\International", &hkey);
            buffer_a_t  am(0);
            buffer_a_t  pm(0);

            if(ERROR_SUCCESS == res)
            {
                size_t  cchAM   =   0;
                size_t  cchPM   =   0;
                LONG    r;

                if( ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s1159", static_cast<char*>(NULL), cchAM)) ||
                    ERROR_SUCCESS != (r = (am.resize(cchAM), cchAM = am.size(), reg_get_string_value(hkey, "s1159", &am[0], cchAM))))
                {
                    res = r;
                }
                else if(ERROR_SUCCESS != (r = reg_get_string_value(hkey, "s2359", static_cast<char*>(NULL), cchPM)) ||
                        ERROR_SUCCESS != (r = (pm.resize(cchPM), cchPM = pm.size(), reg_get_string_value(hkey, "s2359", &pm[0], cchPM))))
                {
                    res = r;
                }

                ::RegCloseKey(hkey);
            }

            if(ERROR_SUCCESS != res)
            {
                am.resize(3);
                pm.resize(3);

                ::lstrcpyA(&am[0], "AM");
                ::lstrcpyA(&pm[0], "PM");
            }


            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh/mm", "12/46");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh/mm", L"12/46");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh/mm/ss", "12/46/01.333");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh/mm/ss", L"12/46/01.333");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh:mm", "12:46");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh:mm", L"12:46");
            }

            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, "hh:mm:ss", "12:46:01.333");
            }
            if(bSuccess)
            {
                bSuccess = test_winstl_time_format_functions_withPicture(r, st, L"hh:mm:ss", L"12:46:01.333");
            }

            if(0 == GetTimeFormat_msA(LOCALE_USER_DEFAULT, 0, &st, "hh:mm:ss tt", &sz[0], stlsoft_num_elements(sz)))
            {
                r->report("GetTimeFormat_msA() failed: call failed", __LINE__);
                bSuccess = false;
            }
            else
            {
                char    result[101] = "12:46:01.333 ";

                ::lstrcatA(&result[0], &pm[0]);

                if(0 != ::lstrcmpA(&sz[0], result))
                {
                    r->report("GetTimeFormat_msA() failed: wrongly formatted", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_time_format_functions(test_winstl_time_format_functions);
    } // anonymous namespace

} // namespace unittest
