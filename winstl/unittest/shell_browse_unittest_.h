
#if !defined(WINSTL_INCL_WINSTL_HPP_SHELL_BROWSE)
# error This file cannot be directly included, and should only be included within winstl/shell_browse.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_SHELL_BROWSE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_shell_browse(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "shell_browse", __FILE__);

            if(0) // Not calling, since don't want dialogs popping in unit-testing
            {
                char                displayName[_MAX_PATH];
                const char          *pcszTitle          =   NULL;
                const std::string   strTitle;
                const char          *pcszDefaultFolder  =   NULL;
                const std::string   strDefaultFolder;
                UINT                flags               =   0;
                HWND                hwndOwner           =   NULL;
                LPCITEMIDLIST       pidlRoot            =   NULL;

                shell_browse(pcszTitle, displayName, flags, hwndOwner, pidlRoot);
                shell_browse(strTitle, displayName, flags, hwndOwner, pidlRoot);

                shell_browse(pcszTitle, displayName, flags, hwndOwner, pidlRoot, pcszDefaultFolder);
                shell_browse(strTitle, displayName, flags, hwndOwner, pidlRoot, strDefaultFolder);

                shell_browse(pcszTitle, displayName, flags, hwndOwner);
                shell_browse(strTitle, displayName, flags, hwndOwner);

                shell_browse(pcszTitle, displayName, flags, pidlRoot);
                shell_browse(strTitle, displayName, flags, pidlRoot);

                shell_browse(pcszTitle, displayName, flags);
                shell_browse(strTitle, displayName, flags);

#if !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER != 1300)
                shell_browse(pcszTitle, displayName, flags, pcszDefaultFolder);
                shell_browse(strTitle, displayName, flags, strDefaultFolder);
#endif /* compiler */

                shell_browse(pcszTitle, displayName);
                shell_browse(strTitle, displayName);
            }

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_shell_browse(test_winstl_shell_browse);
    } // anonymous namespace

} // namespace unittest
