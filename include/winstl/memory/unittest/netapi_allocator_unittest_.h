
// Created: 27th March 2006
// Updated: 27th March 2006

#if !defined(WINSTL_INCL_WINSTL_MEMORY_HPP_NETAPI_ALLOCATOR)
# error This file cannot be directly included, and should only be included within winstl/memory/netapi_allocator.hpp
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_NETAPI_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_memory_netapi_allocator(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "memory/netapi_allocator", __FILE__);

			typedef netapi_allocator<int>  int_allocator_t;

			int_allocator_t ator1;

			int 	*pi1	=	ator1.allocate(100);

			if(NULL != pi1)
			{
				ator1.construct(pi1, 1968);

				if(1968 != *pi1)
				{
					r->report("construct() failed", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_memory_netapi_allocator(test_winstl_memory_netapi_allocator);
	} // anonymous namespace

} // namespace unittest
