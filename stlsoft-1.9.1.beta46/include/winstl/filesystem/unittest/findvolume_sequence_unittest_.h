
// Updated: 1st June 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDVOLUME_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/filesystem/findvolume_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDVOLUME_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_filesystem_findvolume_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/findvolume_sequence", __FILE__);

			findvolume_sequence_a	fvsa;
			findvolume_sequence_w	fvsw;

			{

				findvolume_sequence_a::const_iterator	b	=	fvsa.begin();
				findvolume_sequence_a::const_iterator	b2;

				b2	=	b;
				b	=	b;
				b	=	b2;
				b2	=	fvsa.begin();
			}

			if(fvsa.empty() != fvsw.empty())
			{
				r->report("findvolume_sequence(ANSI)::empty() != findvolume_sequence(Unicode)::empty()", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_filesystem_findvolume_sequence(test_winstl_filesystem_findvolume_sequence);
	} // anonymous namespace

} // namespace unittest
