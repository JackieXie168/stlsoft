
// Updated: 6th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/number/grouping_functions.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

#if !defined(STLSOFT_COMPILER_IS_BORLAND)	// Borland has an ICE with the amount of tests here.

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_conversion_number_grouping_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/number/grouping_functions", __FILE__);

			{ // 1

				{ for(int i = 0; i < 100000; ++i)
				{
					char	dest1[101];
					char	dest2[101];

					format_thousands(&dest1[0], STLSOFT_NUM_ELEMENTS(dest1), "6;", i);

					::sprintf(&dest2[0], "%d", i);

					if(0 != ::strcmp(&dest1[0], &dest2[0]))
					{
						r->report("stlsoft::format_thousands(, , \"6;\", ) failed ", __LINE__);
						bSuccess = false;
					}
				}}
			}

			{ // 2

				char		dest[101];
				const int	n	=	987654321;

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";1", n);
				if(0 != ::strcmp(dest, "98765432,1"))
				{
					r->report("stlsoft::format_thousands(, , \";1\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";2", n);
				if(0 != ::strcmp(dest, "9876543,21"))
				{
					r->report("stlsoft::format_thousands(, , \";2\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";3", n);
				if(0 != ::strcmp(dest, "987654,321"))
				{
					r->report("stlsoft::format_thousands(, , \";3\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";4", n);
				if(0 != ::strcmp(dest, "98765,4321"))
				{
					r->report("stlsoft::format_thousands(, , \";4\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";5", n);
				if(0 != ::strcmp(dest, "9876,54321"))
				{
					r->report("stlsoft::format_thousands(, , \";5\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";6", n);
				if(0 != ::strcmp(dest, "987,654321"))
				{
					r->report("stlsoft::format_thousands(, , \";6\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";7", n);
				if(0 != ::strcmp(dest, "98,7654321"))
				{
					r->report("stlsoft::format_thousands(, , \";7\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";8", n);
				if(0 != ::strcmp(dest, "9,87654321"))
				{
					r->report("stlsoft::format_thousands(, , \";8\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";9", n);
				if(0 != ::strcmp(dest, "987654321"))
				{
					r->report("stlsoft::format_thousands(, , \";9\", ) failed ", __LINE__);
					bSuccess = false;
				}
			}

			{ // 3

				char		dest[101];
				const int	n	=	987654321;

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), ";2", n);
				if(0 != ::strcmp(dest, "9876543,21"))
				{
					r->report("stlsoft::format_thousands(, , \";2\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;2", n);
				if(0 != ::strcmp(dest, "98765,43,21"))
				{
					r->report("stlsoft::format_thousands(, , \"2;2\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;2;2", n);
				if(0 != ::strcmp(dest, "987,65,43,21"))
				{
					r->report("stlsoft::format_thousands(, , \"2;2;2\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;2;2;2", n);
				if(0 != ::strcmp(dest, "9,87,65,43,21"))
				{
					r->report("stlsoft::format_thousands(, , \"2;2;2;2\", ) failed ", __LINE__);
					bSuccess = false;
				}

				format_thousands(&dest[0], STLSOFT_NUM_ELEMENTS(dest), "2;2;2;2;2", n);
				if(0 != ::strcmp(dest, "9,87,65,43,21"))
				{
					r->report("stlsoft::format_thousands(, , \"2;2;2;2;2\", ) failed ", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_number_grouping_functions(test_stlsoft_conversion_number_grouping_functions);
	} // anonymous namespace

} // namespace unittest

#endif /* compiler */
