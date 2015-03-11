
/*
 * Created: 24th December 2006
 * Updated: 31st March 2007
 */

#if !defined(STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_STD_HPP_CONTAINER)
# error This file cannot be directly included, and should only be included within stlsoft/shims/logical/is_empty/std/container.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_STD_HPP_CONTAINER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_shims_attribute_is_empty_std_container(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "shims/attribute/is_empty/std/container", __FILE__);

			{ // 1. deque

				stlsoft_ns_qual_std(deque)<int>	cont;

				if(!is_empty(cont))
				{
					r->report("is_empty(deque<int>) failed", __LINE__);

					bSuccess = false;
				}

				cont.push_back(1);

				if(is_empty(cont))
				{
					r->report("is_empty(deque<int>) failed", __LINE__);

					bSuccess = false;
				}
			}

			{ // 2. list

				stlsoft_ns_qual_std(list)<int>	cont;

				if(!is_empty(cont))
				{
					r->report("is_empty(list<int>) failed", __LINE__);

					bSuccess = false;
				}

				cont.push_back(1);

				if(is_empty(cont))
				{
					r->report("is_empty(list<int>) failed", __LINE__);

					bSuccess = false;
				}
			}

			{ // 3. vector

				stlsoft_ns_qual_std(vector)<int>	cont;

				if(!is_empty(cont))
				{
					r->report("is_empty(vector<int>) failed", __LINE__);

					bSuccess = false;
				}

				cont.push_back(1);

				if(is_empty(cont))
				{
					r->report("is_empty(vector<int>) failed", __LINE__);

					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_shims_attribute_is_empty_std_container(test_stlsoft_shims_attribute_is_empty_std_container);
	} // anonymous namespace

} // namespace unittest

