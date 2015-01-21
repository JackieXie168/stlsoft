
// Updated: 11th June 2006

#if !defined(PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_ENVIRONMENT_MAP)
# error This file cannot be directly included, and should only be included within platformstl/system/environment_map.hpp
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_ENVIRONMENT_MAP */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_platformstl_system_environment_map(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "PLATFORMSTL", "system/environment_map", __FILE__);

			environment_map 				env;
			environment_map::second_type	value;

			try
			{
				env["PATH"];
			}
			catch(std::out_of_range &)
			{}

			env.lookup("PATH", value);



#if 0
			if(0 != strcmp(getenv("PATH"), path))
			{
				r->report("basic_environment_map<char> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_platformstl_system_environment_map(test_platformstl_system_environment_map);
	} // anonymous namespace

}// namespace unittest
