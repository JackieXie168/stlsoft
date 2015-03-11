
#if !defined(WINSTL_INCL_WINSTL_CONTROLS_HPP_LISTBOX_DATA_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/controls/listbox_data_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_CONTROLS_HPP_LISTBOX_DATA_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_listbox_data_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "listbox_data_sequence", __FILE__);

			if(0)
			{
				HWND					hwnd		=	NULL;
				listbox_data_sequence	lbds(hwnd);

				lbds.size();
				lbds.empty();
				lbds.max_size();
				lbds.begin();
				lbds.end();
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
				lbds.rbegin();
				lbds.rend();
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
				lbds[1];
			}

#if 0
			if(0 != i)
			{
				r->report("lock() - unlock() sequence failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_listbox_data_sequence(test_winstl_listbox_data_sequence);
	} // anonymous namespace

} // namespace unittest
