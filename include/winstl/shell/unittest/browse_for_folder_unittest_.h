
// Updated:	14th January 2007

#if !defined(WINSTL_INCL_WINSTL_SHELL_HPP_BROWSE_FOR_FOLDER)
# error This file cannot be directly included, and should only be included within winstl/shell/browse_for_folder.hpp
#endif /* !WINSTL_INCL_WINSTL_SHELL_HPP_BROWSE_FOR_FOLDER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_shell_browse_for_folder(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "shell/browse_for_folder", __FILE__);

			if(0) // Not calling, since don't want dialogs popping in unit-testing
			{
				char				displayName[_MAX_PATH];
				const char			*pcszTitle			=	NULL;
				const std::string	strTitle;
				const char			*pcszDefaultFolder	=	NULL;
				const std::string	strDefaultFolder;
				UINT				flags				=	0;
				HWND				hwndOwner			=	NULL;
				LPCITEMIDLIST		pidlRoot			=	NULL;

				browse_for_folder(pcszTitle, displayName, flags, hwndOwner, pidlRoot);
				browse_for_folder(strTitle, displayName, flags, hwndOwner, pidlRoot);

				browse_for_folder(pcszTitle, displayName, flags, hwndOwner, pidlRoot, pcszDefaultFolder);
				browse_for_folder(strTitle, displayName, flags, hwndOwner, pidlRoot, strDefaultFolder);

				browse_for_folder(pcszTitle, displayName, flags, hwndOwner);
				browse_for_folder(strTitle, displayName, flags, hwndOwner);

				browse_for_folder(pcszTitle, displayName, flags, pidlRoot);
				browse_for_folder(strTitle, displayName, flags, pidlRoot);

				browse_for_folder(pcszTitle, displayName, flags);
				browse_for_folder(strTitle, displayName, flags);

#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	!defined(STLSOFT_COMPILER_IS_MWERKS) && \
	(	!defined(STLSOFT_COMPILER_IS_MSVC) || \
		_MSC_VER != 1300)
				browse_for_folder(pcszTitle, displayName, flags, pcszDefaultFolder);
				browse_for_folder(strTitle, displayName, flags, strDefaultFolder);
#endif /* compiler */

				browse_for_folder(pcszTitle, displayName);
				browse_for_folder(strTitle, displayName);
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

		unittest_registrar	  unittest_winstl_shell_browse_for_folder(test_winstl_shell_browse_for_folder);
	} // anonymous namespace

} // namespace unittest
