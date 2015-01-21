
// Updated: 19th September 2005

#if !defined(MFCSTL_INCL_MFCSTL_HPP_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within unixstl/string_access.hpp
#endif /* !MFCSTL_INCL_MFCSTL_HPP_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_mfcstl_string_access_CString(unittest_reporter *r)
        {
            ss_bool_t   bSuccess = true;

            CString     str1("String #1");

            if(0 != _tcscmp(_T("String #1"), c_str_ptr(str1)))
            {
                r->report("c_str_ptr(CString) failed", __LINE__);
                bSuccess = false;
            }

            if(0 != _tcscmp(_T("String #1"), c_str_ptr_null(str1)))
            {
                r->report("c_str_ptr_null(CString) failed", __LINE__);
                bSuccess = false;
            }

            CString     str2;

            if(NULL != c_str_ptr_null(str2))
            {
                r->report("c_str_ptr_null(CString) failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_mfcstl_string_access_CWnd(unittest_reporter *r)
        {
            ss_bool_t   bSuccess = true;

            CWnd    wnd1;
            CWnd    *pwndDesktopWindow  =   CWnd::GetDesktopWindow();
            RECT    rc                  =   { 0, 0, 10, 10 };

            if( wnd1.Create("BUTTON", "Window #1", NULL, rc, pwndDesktopWindow, 0) &&
                0 != strcmp("Window #1", c_str_ptr(wnd1)))
            {
                r->report("c_str_ptr(CWnd) failed", __LINE__);
                bSuccess = false;
            }

            wnd1.DestroyWindow();

            CWnd    wnd2;

            if(0 != strcmp("", c_str_ptr(wnd2)))
            {
                r->report("c_str_ptr(CWnd) failed", __LINE__);
                bSuccess = false;
            }

            if(NULL != c_str_ptr_null(wnd2))
            {
                r->report("c_str_ptr_null(CWnd) failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }


        ss_bool_t test_mfcstl_string_access(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "MFCSTL", "string_access", __FILE__);

            // 1. Test CString
            if(bSuccess)
            {
                bSuccess = test_mfcstl_string_access_CString(r);
            }

            // 1. Test CWnd
            if(bSuccess)
            {
                bSuccess = test_mfcstl_string_access_CWnd(r);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_mfcstl_string_access(test_mfcstl_string_access);
    } // anonymous namespace

}// namespace unittest
