
// Updated: 2nd September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_ENVIRONMENT_VARIABLE)
# error This file cannot be directly included, and should only be included within unixstl/environment_variable.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_ENVIRONMENT_VARIABLE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_environment_variable(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "environment_variable", __FILE__);

            typedef basic_environment_variable<char>    env_var_t;

            env_var_t   path("PATH");

            if(0 != strcmp(getenv("PATH"), path))
            {
                r->report("basic_environment_variable<char> failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_environment_variable(test_unixstl_environment_variable);
    } // anonymous namespace

}// namespace unittest
