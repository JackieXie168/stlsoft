
#if !defined(WINSTL_INCL_WINSTL_HPP_WINDOW_VISIBLE_SCOPE)
# error This file cannot be directly included, and should only be included within winstl/window_visible_scope.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_WINDOW_VISIBLE_SCOPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_window_visible_scope(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			RECT					rc			=	{ 0, 0, 10, 10 };
			HWND					hwndButton	=	::CreateWindowEx(0, "BUTTON", "A button", WS_VISIBLE, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, NULL, (HMENU)0, GetModuleHandle(NULL), NULL);

			unittest_initialiser	init(r, "WinSTL", "window_visible_scope", __FILE__);

			if(!::IsWindow(hwndButton))
			{
				r->report("failed to create test window", __LINE__);
			}
			else
			{
				if(!::IsWindowVisible(hwndButton))
				{
					r->report("test window is invalid (not visible)", __LINE__);
					bSuccess = false;
				}
				else
				{
					{ // Enter scope
						window_visible_scope	scope(hwndButton);

						if(::IsWindowVisible(hwndButton))
						{
							r->report("test window is visible when it should be hidden", __LINE__);
							bSuccess = false;
						}

					} // Exit scope

					if(!::IsWindowVisible(hwndButton))
					{
						r->report("test window is hidden when it should be visible", __LINE__);
						bSuccess = false;
					}

					{ // Enter scope
						window_visible_scope	scope(hwndButton, SW_SHOW, SW_HIDE);

						if(!::IsWindowVisible(hwndButton))
						{
							r->report("test window is hidden when it should be visible", __LINE__);
							bSuccess = false;
						}

					} // Exit scope

					if(::IsWindowVisible(hwndButton))
					{
						r->report("test window is visible when it should be hidden", __LINE__);
						bSuccess = false;
					}
				}

				DestroyWindow(hwndButton);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_window_visible_scope(test_winstl_window_visible_scope);
	} // anonymous namespace

} // namespace unittest
