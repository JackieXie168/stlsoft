
// Updated: 30th May 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/readdir_sequence.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_filesystem_readdir_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "filesystem/readdir_sequence", __FILE__);

			readdir_sequence		files(".", readdir_sequence::files);
			int 					bFilesTestedEmpty = true;

			{
				readdir_sequence::const_iterator b	=	files.begin();

				b	=	b;
				b	=	files.begin();
			}

			{ for(readdir_sequence::const_iterator b = files.begin(); b != files.end(); ++b)
			{
				bFilesTestedEmpty = false;
			}}

			if(!bFilesTestedEmpty != !!files.empty())
			{
				r->report("readdir_sequence empty() contradiction when enumerating files", __LINE__);
				bSuccess = false;
			}

			readdir_sequence		directories(".", readdir_sequence::directories);
			int 					bDirectoriesTestedEmpty = true;

			{ for(readdir_sequence::const_iterator b = directories.begin(); b != directories.end(); ++b)
			{
				bDirectoriesTestedEmpty = false;
			}}

			if(!bDirectoriesTestedEmpty != !!directories.empty())
			{
				r->report("readdir_sequence empty() contradiction when enumerating files", __LINE__);
				bSuccess = false;
			}

#if 0
			if(seq.empty() == (0 == seq.size()))
			{
				r->report("readdir_sequence empty() and size() contradict ", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

#if 0
			readdir_sequence::size_type   total_forward   =   0;
			readdir_sequence::size_type   total_backward  =   0;

			readdir_sequence::const_iterator			b_f =	seq.begin();
			for(; b_f != seq.end(); ++b_f)
			{
				total_forward += strlen((*b_f)->d_name);
			}

			readdir_sequence::const_reverse_iterator	b_b =	seq.rbegin();
			for(; b_b != seq.rend(); ++b_b)
			{
				total_backward += strlen((*b_b)->d_name);
			}

			if(total_forward != total_backward)
			{
				r->report("readdir_sequence forward and backward ranges contradict ", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_filesystem_readdir_sequence(test_unixstl_filesystem_readdir_sequence);
	} // anonymous namespace

} // namespace unittest
