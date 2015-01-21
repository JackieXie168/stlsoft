
#if !defined(WINSTL_INCL_WINSTL_SHELL_HPP_FILE_OPERATIONS)
# error This file cannot be directly included, and should only be included within winstl/shell/file_operations.hpp
#endif /* !WINSTL_INCL_WINSTL_SHELL_HPP_FILE_OPERATIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_shell_file_operations(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "shell/file_operations", __FILE__);

            if(0) // Not calling, since don't want dialogs popping in unit-testing
            {
                HWND            hwndOwner   =   NULL;
                char const      *file_a     =   "H:\\temp\\delete_file_test";
                wchar_t const   *file_w     =  L"H:\\temp\\delete_file_test";
                ws_bool_t       bAborted    =   false;
                FILEOP_FLAGS    flags       =   FOF_ALLOWUNDO;
                char const      *title_a    =   "deleting using shell_delete";
                wchar_t const   *title_w    =  L"deleting using shell_delete";

                shell_delete(file_a);
                shell_delete(file_a, bAborted);
                shell_delete(file_a, flags);
                shell_delete(file_a, flags, bAborted);
                shell_delete(file_a, title_a);
                shell_delete(file_a, title_a, bAborted);
                shell_delete(file_a, title_a, flags);
                shell_delete(file_a, title_a, flags, bAborted);
                shell_delete(hwndOwner, file_a);
                shell_delete(hwndOwner, file_a, bAborted);
                shell_delete(hwndOwner, file_a, flags);
                shell_delete(hwndOwner, file_a, flags, bAborted);
                shell_delete(hwndOwner, file_a, title_a);
                shell_delete(hwndOwner, file_a, title_a, bAborted);
                shell_delete(hwndOwner, file_a, title_a, flags);
                shell_delete(hwndOwner, file_a, title_a, flags, bAborted);

                shell_delete(file_w);
                shell_delete(file_w, bAborted);
                shell_delete(file_w, flags);
                shell_delete(file_w, flags, bAborted);
                shell_delete(file_w, title_w);
                shell_delete(file_w, title_w, bAborted);
                shell_delete(file_w, title_w, flags);
                shell_delete(file_w, title_w, flags, bAborted);
                shell_delete(hwndOwner, file_w);
                shell_delete(hwndOwner, file_w, bAborted);
                shell_delete(hwndOwner, file_w, flags);
                shell_delete(hwndOwner, file_w, flags, bAborted);
                shell_delete(hwndOwner, file_w, title_w);
                shell_delete(hwndOwner, file_w, title_w, bAborted);
                shell_delete(hwndOwner, file_w, title_w, flags);
                shell_delete(hwndOwner, file_w, title_w, flags, bAborted);
            }

            STLSOFT_SUPPRESS_UNUSED(bSuccess);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_shell_file_operations(test_winstl_shell_file_operations);
    } // anonymous namespace

} // namespace unittest
