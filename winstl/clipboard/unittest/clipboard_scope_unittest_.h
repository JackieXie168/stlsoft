
#if !defined(WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE)
# error This file cannot be directly included, and should only be included within winstl/clipboard/clipboard_scope.hpp
#endif /* !WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_SCOPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_clipboard_clipboard_scope(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "clipboard/clipboard_scope", __FILE__);

#if 0
			typedef basic_clipboard_scope<stlsoft_ns_qual_std(string), null_exception_policy>  rsn_a_t;
			typedef basic_clipboard_scope<stlsoft_ns_qual_std(wstring), null_exception_policy> rsn_w_t;

			HINSTANCE	hinst	=	::LoadLibrary("USER32");
			int 		iBad	=	-1;
			int 		iGood	=	-1;

			for(int i = 0; i < 10000; ++i)
			{
				rsn_a_t 	rsn_a_2(hinst, i);
				rsn_w_t 	rsn_w_2(hinst, i);

				if(0 == rsn_a_2.length())
				{
					if(-1 == iBad)
					{
						iBad = i;
					}
				}
				else
				{
					if(-1 == iGood)
					{
						iGood = i;
					}
				}

				if(rsn_a_2.length() != rsn_w_2.length())
				{
					r->report("resource string (null exception) length mismatch between ANSI and Unicode instantiations", __LINE__);
					bSuccess = false;
				}
			}

			if(bSuccess)
			{
				typedef basic_clipboard_scope<stlsoft_ns_qual_std(string), throw_exception> 	rsx_a_t;
				typedef basic_clipboard_scope<stlsoft_ns_qual_std(wstring), throw_exception>	rsx_w_t;

				if(-1 != iGood)
				{
					try
					{
						rsx_a_t 	rsn_a_2(hinst, iGood);
						rsx_w_t 	rsn_w_2(hinst, iGood);
					}
					catch(std::exception &/* x */)
					{
						r->report("resource string (std::exception) failed to load known resource from USER32", __LINE__);
						bSuccess = false;
					}
				}

				if(-1 != iBad)
				{
					try
					{
						rsx_a_t 	rsn_a_2(hinst, iBad);

						r->report("resource string (std::exception) loaded known invalid resource from USER32", __LINE__);
						bSuccess = false;
					}
					catch(std::exception &/* x */)
					{}

					try
					{
						rsx_w_t 	rsn_w_2(hinst, iBad);

						r->report("resource string (std::exception) loaded known invalid resource from USER32", __LINE__);
						bSuccess = false;
					}
					catch(std::exception &/* x */)
					{}
				}
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				winstl::basic_clipboard_scope<std::string>	str(1024);

				std::cout << "String with id 1024: " << str << std::endl;

				fprintf(stdout, "String with id 1024: %.*s\n", str.size(), str.data());
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				winstl::basic_clipboard_scope<std::string>	str(hinst, 9999999);

				WINSTL_ASSERT(0 == str.size());
				WINSTL_ASSERT(str == "");
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				try
				{
					winstl::basic_clipboard_scope<std::string, throw_exception>  str(hinst, 9999999);

					std::cerr << "Should never get here!!" << std::endl;
				}
				catch(throw_exception::thrown_type &/* x */)
				{
					std::cerr << "This is what's expected" << std::endl;
				}
			}
#endif /* 0 */

			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_clipboard_clipboard_scope(test_winstl_clipboard_clipboard_scope);
	} // anonymous namespace

} // namespace unittest
