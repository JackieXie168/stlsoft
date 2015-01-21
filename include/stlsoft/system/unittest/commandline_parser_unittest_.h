
// Updated: 10th June 2006

#if !defined(STLSOFT_INCL_STLSOFT_SYSTEM_HPP_COMMANDLINE_PARSER)
# error This file cannot be directly included, and should only be included within stlsoft/system/commandline_parser.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SYSTEM_HPP_COMMANDLINE_PARSER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_system_commandline_parser(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "system/commandline_parser", __FILE__);

			{
				commandline_parser_a	cp("");

				if(0 != cp.size())
				{
					r->report("Empty command-line yields sequence that returns 0 != size()", __LINE__);
					bSuccess = false;
				}
			}

			{
				commandline_parser_a	cp("a ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
			}

			{
				commandline_parser_a		cp("a ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" a");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" a ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp("\"a\"");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp("\"a\" ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" \"a\"");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" \"a\" ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp("\"a b\"");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a b", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp("\"a b\" ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a b", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" \"a b\"");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a b", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" \"a b\" ");

				if(1 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("a b", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			{
				commandline_parser_a		cp(" x \"a b\" yz \"012");

				if(4 != cp.size())
				{
					r->report("1-element command-line yields sequence that returns 1 != size()", __LINE__);
					bSuccess = false;
				}
				if(0 != ::strcmp("x", cp[0]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
				if(0 != ::strcmp("a b", cp[1]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
				if(0 != ::strcmp("yz", cp[2]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
				if(0 != ::strcmp("012", cp[3]))
				{
					r->report("command-line yields sequence containing wrong element(s)", __LINE__);
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_system_commandline_parser(test_stlsoft_system_commandline_parser);

	} // anonymous namespace

} // namespace unittest
