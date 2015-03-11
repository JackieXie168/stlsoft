
// Updated: 22nd June 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_GLOB_SEQUENCE)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/glob_sequence.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_GLOB_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace unixstl_filesystem_glob_sequence_item_comparator
		{
			struct equal_path
			{
			public:
				bool operator ()(char const *path1, char const *path2) const
				{
					return 0 == strcmp(path1, path2);
				}
			};

		} // namespace unixstl_filesystem_glob_sequence_item_comparator

		ss_bool_t test_unixstl_filesystem_glob_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "filesystem/glob_sequence", __FILE__);

			static const char		s_wildcardsAll[] =
#ifdef _WIN32
														"*.*";
#else /* ? _WIN32 */
														"*";
#endif /* _WIN32 */


			{
				glob_sequence	seq(s_wildcardsAll);

				if(seq.empty() != (0 == seq.size()))
				{
					r->report("glob_sequence empty() and size() contradict", __LINE__);
					bSuccess = false;
				}

				us_size_t	total_forward	=	0;
				us_size_t	total_backward	=	0;

				glob_sequence::const_iterator			b_f =	seq.begin();
				for(; b_f != seq.end(); ++b_f)
				{
					total_forward += strlen(*b_f);
				}

				glob_sequence::const_reverse_iterator	b_b =	seq.rbegin();
				for(; b_b != seq.rend(); ++b_b)
				{
					total_backward += strlen(*b_b);
				}

				if(total_forward != total_backward)
				{
					r->report("glob_sequence forward and backward ranges contradict", __LINE__);
					bSuccess = false;
				}
			}

			{
				const simple_string cwd(".");

				glob_sequence	gs1(s_wildcardsAll, /* (us_int_t) */glob_sequence::absolutePath);
				glob_sequence	gs2(".", s_wildcardsAll, glob_sequence::absolutePath);

				glob_sequence	gs3(".", s_wildcardsAll);
				glob_sequence	gs4(cwd, s_wildcardsAll);

				if( !std::equal(gs1.begin(), gs1.end(), gs2.begin(), unixstl_filesystem_glob_sequence_item_comparator::equal_path()) ||
					!std::equal(gs2.begin(), gs2.end(), gs1.begin(), unixstl_filesystem_glob_sequence_item_comparator::equal_path()))
				{
					r->report("implicit directory instance not equal to explicit current directory instance", __LINE__);
					bSuccess = false;
				}

				if( !std::equal(gs3.begin(), gs3.end(), gs4.begin(), unixstl_filesystem_glob_sequence_item_comparator::equal_path()) ||
					!std::equal(gs4.begin(), gs4.end(), gs3.begin(), unixstl_filesystem_glob_sequence_item_comparator::equal_path()))
				{
					r->report("explicit current directory instance not equal to explicit current directory instance", __LINE__);
					bSuccess = false;
				}
			}


			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_filesystem_glob_sequence(test_unixstl_filesystem_glob_sequence);
	} // anonymous namespace

} // namespace unittest
