
// Updated: 27th March 2006

#if !defined(STLSOFT_INCL_STLSOFT_MEMORY_HPP_MALLOC_ALLOCATOR)
# error This file cannot be directly included, and should only be included within stlsoft/memory/malloc_allocator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_MALLOC_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_memory_malloc_allocator(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "memory/malloc_allocator", __FILE__);

			typedef malloc_allocator<int>  int_allocator_t;

			int_allocator_t ator1;

			int 	*pi1	=	ator1.allocate(100);

			if(NULL != pi1)
			{
				ator1.construct(pi1, 1968);

				if(1968 != *pi1)
				{
					r->report("malloc_allocator failed", __LINE__);
					bSuccess = false;
				}
			}

			ator1.deallocate(pi1);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_memory_malloc_allocator(test_stlsoft_memory_malloc_allocator);
	} // anonymous namespace

} // namespace unittest

