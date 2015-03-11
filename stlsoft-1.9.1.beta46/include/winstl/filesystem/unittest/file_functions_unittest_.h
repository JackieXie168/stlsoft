
// Updated: 12th March 2007

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/filesystem_traits.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILE_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_file_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/file_functions", __FILE__);


			if( 0 == ::GetTickCount() &&
				(::Sleep(1000), 0 == ::GetTickCount()))
			{
				stlsoft::simple_string	ss_a;
				stlsoft::simple_wstring ss_w;

				load_text_file(stlsoft::simple_string("fairly unlikely.event"), ss_a);
				load_text_file(stlsoft::simple_string("fairly unlikely.event"), ss_w);

				load_text_file(stlsoft::simple_wstring(L"fairly unlikely.event"), ss_a);
				load_text_file(stlsoft::simple_wstring(L"fairly unlikely.event"), ss_w);

				load_text_file((char const*)"fairly unlikely.event", ss_a);
				load_text_file((char const*)"fairly unlikely.event", ss_w);

				load_text_file((wchar_t const*)L"fairly unlikely.event", ss_a);
				load_text_file((wchar_t const*)L"fairly unlikely.event", ss_w);

#if 0
				if(<<x>>)
				{
					r->report("Directory equivalence failed", __LINE__);
					bSuccess = false;
				}
#endif /* 0 */
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_file_functions(test_winstl_file_functions);
	}

}// namespace unittest
