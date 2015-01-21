
// Updated: 10th June 2006

#if !defined(WINSTL_INCL_WINSTL_MEMORY_HPP_HEAPWALK_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/memory/heapwalk_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_HEAPWALK_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_memory_heapwalk_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "memory/heapwalk_sequence", __FILE__);

			{
				heapwalk_sequence	blocks;
				const size_t		n1	=	static_cast<size_t>(winstl_ns_qual_std(distance)(blocks.begin(), blocks.end()));
				size_t				n2	=	0;

				{ for(winstl::heapwalk_sequence::const_iterator b = blocks.begin(); b != blocks.end(); ++b, ++n2)
				{}}

				// NOTE: Can't test these against each other, as something else in
				// the process might (de-)allocate a block.
				STLSOFT_SUPPRESS_UNUSED(n1);
				STLSOFT_SUPPRESS_UNUSED(n2);
			}

			{
				HANDLE	hHeap	=	::HeapCreate(0, 0, 0);

				::HeapAlloc(hHeap, 0, 100);
				::HeapAlloc(hHeap, 0, 100);

				heapwalk_sequence	blocks(hHeap);
				const size_t		n1	=	static_cast<size_t>(winstl_ns_qual_std(distance)(blocks.begin(), blocks.end()));
				size_t				n2	=	0;

				{ for(winstl::heapwalk_sequence::const_iterator b = blocks.begin(); b != blocks.end(); ++b, ++n2)
				{}}

				if(n1 != n2)
				{
					r->report("repeated iteration returned inconsistent value", __LINE__);
					bSuccess = false;
				}

				::HeapDestroy(hHeap);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_memory_heapwalk_sequence(test_winstl_memory_heapwalk_sequence);
	} // anonymous namespace

} // namespace unittest
