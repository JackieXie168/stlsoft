
// Updated: 12th November 2007

#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_UNSORTED_MAP)
# error This file cannot be directly included, and should only be included within stlsoft/containers/unsorted_map.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_UNSORTED_MAP */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER > 1100

	namespace
	{
		ss_bool_t test_stlsoft_containers_unsorted_map(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "containers/unsorted_map", __FILE__);

			typedef stlsoft_ns_qual_std(string) string_t;
			typedef unsorted_map<string_t, int> um_t;

			um_t	um;

			if(!um.empty())
			{
				r->report("unsorted_map erroneously fails to report empty()", __LINE__);
				bSuccess = false;
			}

			um.push_back("string 1", 1);
			um.push_back("string 2", 2);
			um.push_back("string 3", 3);
			um.push_back("string 4", 4);

			if(4 != um.size())
			{
				r->report("unsorted_map reports incorrect size()", __LINE__);
				bSuccess = false;
			}
			if(um.empty())
			{
				r->report("unsorted_map erroneously reports empty()", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_containers_unsorted_map(test_stlsoft_containers_unsorted_map);
	} // anonymous namespace

#endif /* compiler */

} // namespace unittest
