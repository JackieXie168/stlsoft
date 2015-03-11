
// Updated: 10th June 2006

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_COMMANDLINE_PARSER)
# error This file cannot be directly included, and should only be included within winstl/system/commandline_parser.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_COMMANDLINE_PARSER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_commandline_parser(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/commandline_parser", __FILE__);

			{
				commandline_parser	cp("");

				if(0 != cp.size())
				{
					r->report("Empty command-line yields sequence that returns 0 != size()", __LINE__);
					bSuccess = false;
				}
			}

			{
				commandline_parser	cp("a ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
			}


			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_system_commandline_parser(test_winstl_system_commandline_parser);

	} // anonymous namespace

} // namespace unittest
