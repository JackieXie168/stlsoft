
#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP)
# error This file cannot be directly included, and should only be included within stlsoft/containers/frequency_map.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_containers_frequency_map(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "containers/frequency_map", __FILE__);

			frequency_map<int>		fm;

			if(!fm.empty())
			{
				r->report("frequency_map erroneously fails to report empty()", __LINE__);
				bSuccess = false;
			}

			fm.push(1);
			fm.push(1);
			fm.push(1);

			if(1 != fm.size())
			{
				r->report("frequency_map reports incorrect size()", __LINE__);
				bSuccess = false;
			}
			if(fm.empty())
			{
				r->report("frequency_map erroneously reports empty()", __LINE__);
				bSuccess = false;
			}

			if(3 != fm[1])
			{
				r->report("frequency_map value[1] returned incorrect frequency", __LINE__);
				bSuccess = false;
			}

			fm.push(2);

			if(2 != fm.size())
			{
				r->report("frequency_map reports incorrect size()", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_containers_frequency_map(test_stlsoft_containers_frequency_map);
	} // anonymous namespace

} // namespace unittest
