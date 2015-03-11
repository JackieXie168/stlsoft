
#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING)
# error This file cannot be directly included, and should only be included within stlsoft/util/exception_string.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_util_exception_string(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "util/exception_string", __FILE__);

			{
				exception_string		xs1;

				if(!xs1.empty())
				{
                    r->report("empty() returned erroneous value", __LINE__);
                    bSuccess = false;
				}

			}

			{
				exception_string		xs2("1");

				if(xs2.empty())
				{
                    r->report("empty() returned erroneous value", __LINE__);
                    bSuccess = false;
				}

				if(0 != ::strcmp("1", xs2.c_str()))
				{
                    r->report("c_str() returned erroneous value", __LINE__);
                    bSuccess = false;
				}

			}


			return bSuccess;
		}

        unittest_registrar    unittest_stlsoft_util_exception_string(test_stlsoft_util_exception_string);
    } // anonymous namespace

} // namespace unittest
