
// Updated: 17th January 2007

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE)
# error This file cannot be directly included, and should only be included within unixstl/current_directory_scope.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_filesystem_current_directory_scope(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "filesystem/current_directory_scope", __FILE__);

			typedef basic_current_directory_scope<char> 	current_directory_scope;

			{
				basic_file_path_buffer<char>	sz;

				::getcwd(&sz[0], sz.size());
#ifdef _WIN32
				current_directory_scope cds("\\");
#else /* ? _WIN32 */
				current_directory_scope cds("/");
#endif /* _WIN32 */

				if(0 != strcmp(sz.c_str(), cds.get_previous()))
				{
					r->report("current_directory_scope failed", __LINE__);
					bSuccess = false;
				}

				{
					current_directory_scope cds2(sz);

#ifdef _WIN32
					if(0 != strcmp("\\", cds2.get_previous() + 2))
#else /* ? _WIN32 */
					if(0 != strcmp("/", cds2.get_previous()))
#endif /* _WIN32 */
					{
						r->report("current_directory_scope failed", __LINE__);
						bSuccess = false;
					}
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_filesystem_current_directory_scope(test_unixstl_filesystem_current_directory_scope);
	} // anonymous namespace

}// namespace unittest
