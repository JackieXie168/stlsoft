
// Updated: 14th January 2007

#if !defined(UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE)
# error This file cannot be directly included, and should only be included within unixstl/filesystem/memory_mapped_file.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_filesystem_memory_mapped_file_1(unittest_reporter *r)
		{
			// 1. Get a temporary file name
			// 2. Create a file
			// 3. Write some bytes to it
			// 4. Close the file
			// 5. Memory map it, and do tests
			// 6. remove the file


			// 1. and 2.
			ss_bool_t				bSuccess	=	true;
			file_path_buffer		path;
			int 					h	=	::open(::tmpnam(&path[0]), O_WRONLY | O_CREAT | O_TRUNC, 0777);

			if(-1 == h)
			{
				r->report("Could not create temporary file to test memory_mapped_file");
			}
			else
			{
				static const byte_t bytes[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

				// 3.
				::write(h, &bytes[0], sizeof(bytes));

				// 4.
				::close(h);

				try
				{
					// 5.

					memory_mapped_file	mmf(path.c_str());

					if(mmf.size() < sizeof(bytes))
					{
						r->report("mapped size is too small", __LINE__);
						bSuccess = false;
					}
					else
					{
						if(0 != ::memcmp(mmf.memory(), &bytes[0], sizeof(bytes)))
						{
							r->report("mapped size is too small", __LINE__);
							bSuccess = false;
						}
					}
				}
				catch(unixstl::unix_exception &/* x */)
				{
					r->report("memory_mapped_file threw an exception", __LINE__);
					bSuccess = false;
				}
				catch(std::exception &/* x */)
				{
					r->report("memory_mapped_file threw a std exception", __LINE__);
					bSuccess = false;
				}

				::remove(path.c_str());
			}

			return bSuccess;
		}

		ss_bool_t test_unixstl_filesystem_memory_mapped_file(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "filesystem/memory_mapped_file", __FILE__);

			if(!test_unixstl_filesystem_memory_mapped_file_1(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_filesystem_memory_mapped_file(test_unixstl_filesystem_memory_mapped_file);
	} // anonymous namespace

} // namespace unittest
