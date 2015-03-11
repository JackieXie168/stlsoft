
// Created: 12th November 2007
// Updated: 12th November 2007

#if !defined(PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/file_lines.hpp
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_filesystem_file_lines_1(unittest_reporter *r)
		{
			// 1. Get a temporary file name
			// 2. Create a file
			// 3. Write some bytes to it
			// 4. Close the file
			// 5. Memory map it, and do tests
			// 6. remove the file


			// 1. and 2.
			ss_bool_t				bSuccess = true;
			file_path_buffer		path;
			FILE*					f = ::fopen(::tmpnam(&path[0]), "w");

			if(NULL == f)
			{
				r->report("Could not create temporary file to test file_lines");
			}
			else
			{
				static char const*	strings[] =
				{
					"line 1",
					"line 2",
					"line 3",
					"line 4",
				};

				// 3.
				{ for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS_(strings); ++i)
				{
					::fprintf(f, "%s\n", strings[i]);
				}}

				// 4.
				::fclose(f);

				try
				{
					// 5.

					file_lines	lines(path.c_str());

					if(STLSOFT_NUM_ELEMENTS_(strings) != lines.size())
					{
						r->report("invalid number of lines", __LINE__);
						bSuccess = false;
					}
					else
					{
						{ for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS_(strings); ++i)
						{
							if(strings[i] != lines[i])
							{
								r->report("lines is not expected", __LINE__);
								bSuccess = false;
							}
						}}
					}
				}
				catch(std::exception &/* x */)
				{
					r->report("file_lines threw a std exception", __LINE__);
					bSuccess = false;
				}

				::remove(path.c_str());
			}

			return bSuccess;
		}

		ss_bool_t test_unixstl_filesystem_file_lines(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "PlatformSTL", "filesystem/file_lines", __FILE__);

			if(!test_unixstl_filesystem_file_lines_1(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_filesystem_file_lines(test_unixstl_filesystem_file_lines);
	} // anonymous namespace

} // namespace unittest

