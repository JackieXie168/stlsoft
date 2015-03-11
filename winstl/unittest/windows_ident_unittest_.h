
#if !defined(WINSTL_INCL_WINSTL_HPP_WINDOWS_IDENT)
# error This file cannot be directly included, and should only be included within winstl/windows_ident.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOWS_IDENT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_windows_ident(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "windows_ident", __FILE__);

			HWND	hwndListBox 	=	::CreateWindowA("LISTBOX", "", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
			HWND	hwndComboBox	=	::CreateWindowA("COMBOBOX", "", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
			HWND	hwndListView	=	::CreateWindowA("SysListView32", "", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

			if( NULL != hwndListBox &&
				GetWindowIdent(hwndListBox) != ListBox)
			{
				r->report("Identification of listbox failed", __LINE__);
				bSuccess = false;
			}

			if( NULL != hwndComboBox &&
				GetWindowIdent(hwndComboBox) != ComboBox)
			{
				r->report("Identification of combobox failed", __LINE__);
				bSuccess = false;
			}

			if( NULL != hwndListView &&
				GetWindowIdent(hwndListView) != ListView)
			{
				r->report("Identification of listview failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_windows_ident(test_winstl_windows_ident);
	} // anonymous namespace

} // namespace unittest
