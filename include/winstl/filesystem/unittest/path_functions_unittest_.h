
// Updated: 11th June 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/filesystem/path_functions.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_filesystem_path_functions_driveRooted(unittest_reporter *r)
		{
			static const char	s_path[]	=	"H:\\STLSoft\\Releases\\current\\STLSoft\\include\\winstl\\filesystem\\path_functions.hpp";
			static const char	s_file[]	=	"path_functions.hpp";
			ss_bool_t			bSuccess	=	true;
			const size_t		PATH_LEN	=	STLSOFT_NUM_ELEMENTS(s_path) - 1;
			char				sz[PATH_LEN + 1 + 10];

#if defined(STLSOFT_COMPILER_IS_BORLAND)
			STLSOFT_SUPPRESS_UNUSED(&PATH_LEN); // Borland. Again!
#endif /* compiler */

			if(0 != winstl::path_squeeze(s_path, &sz[0], 0))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			// For any that are less <= len(file)
			{ for(size_t i = 1; i < STLSOFT_NUM_ELEMENTS(s_file); ++i)
			{
				if(i != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}
			// For any that cannot fit the file name and 'H:\...\'
			{ for(size_t i = STLSOFT_NUM_ELEMENTS(s_file); i < STLSOFT_NUM_ELEMENTS(s_file) + 6; ++i)
			{
				if(STLSOFT_NUM_ELEMENTS(s_file) - 1 != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}

			if(25 != winstl::path_squeeze(s_path, &sz[0], 25))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "H:\\...\\path_functions.hpp", 25))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(26 != winstl::path_squeeze(s_path, &sz[0], 26))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "H:\\S...\\path_functions.hpp", 26))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 1))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 2))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_winstl_filesystem_path_functions_dirRooted(unittest_reporter *r)
		{
			static const char	s_path[]	=	"\\STLSoft\\Releases\\current\\STLSoft\\include\\winstl\\filesystem\\path_functions.hpp";
			static const char	s_file[]	=	"path_functions.hpp";
			ss_bool_t			bSuccess	=	true;
			const size_t		PATH_LEN	=	STLSOFT_NUM_ELEMENTS(s_path) - 1;
			char				sz[PATH_LEN + 1 + 10];

#if defined(STLSOFT_COMPILER_IS_BORLAND)
			STLSOFT_SUPPRESS_UNUSED(&PATH_LEN); // Borland. Again!
#endif /* compiler */
			if(0 != winstl::path_squeeze(s_path, &sz[0], 0))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			// For any that are less <= len(file)
			{ for(size_t i = 1; i < STLSOFT_NUM_ELEMENTS(s_file); ++i)
			{
				if(i != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}
			// For any that cannot fit the file name and '\...\'
			{ for(size_t i = STLSOFT_NUM_ELEMENTS(s_file); i < STLSOFT_NUM_ELEMENTS(s_file) + 4; ++i)
			{
				if(STLSOFT_NUM_ELEMENTS(s_file) - 1 != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}

			if(23 != winstl::path_squeeze(s_path, &sz[0], 23))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "\\...\\path_functions.hpp", 23))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(24 != winstl::path_squeeze(s_path, &sz[0], 24))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "\\S...\\path_functions.hpp", 24))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 1))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 2))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_winstl_filesystem_path_functions_uncRooted(unittest_reporter *r)
		{
			static const char	s_path[]	=	"\\\\host\\share\\dir1\\dir2\\dir3\\name.ext";
			static const char	s_file[]	=	"name.ext";
			ss_bool_t			bSuccess	=	true;
			const size_t		PATH_LEN	=	STLSOFT_NUM_ELEMENTS(s_path) - 1;
			char				sz[PATH_LEN + 1 + 10];

#if defined(STLSOFT_COMPILER_IS_BORLAND)
			STLSOFT_SUPPRESS_UNUSED(&PATH_LEN); // Borland. Again!
#endif /* compiler */
			if(0 != winstl::path_squeeze(s_path, &sz[0], 0))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			// For any that are less <= len(file)
			{ for(size_t i = 1; i < STLSOFT_NUM_ELEMENTS(s_file); ++i)
			{
				if(i != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}
			// For any that cannot fit the file name and '\...\'
			{ for(size_t i = STLSOFT_NUM_ELEMENTS(s_file); i < STLSOFT_NUM_ELEMENTS(s_file) + 8; ++i)
			{
				if(STLSOFT_NUM_ELEMENTS(s_file) - 1 != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}

			if(19 != winstl::path_squeeze(s_path, &sz[0], 19))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "\\\\host\\...\\name.ext", 19))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(20 != winstl::path_squeeze(s_path, &sz[0], 20))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "\\\\host\\s...\\name.ext", 20))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 1))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 2))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_winstl_filesystem_path_functions_relative(unittest_reporter *r)
		{
			static const char	s_path[]	=	"dir1\\dir2\\dir3\\name.ext";
			static const char	s_file[]	=	"name.ext";
			ss_bool_t			bSuccess	=	true;
			const size_t		PATH_LEN	=	STLSOFT_NUM_ELEMENTS(s_path) - 1;
			char				sz[PATH_LEN + 1 + 10];

#if defined(STLSOFT_COMPILER_IS_BORLAND)
			STLSOFT_SUPPRESS_UNUSED(&PATH_LEN); // Borland. Again!
#endif /* compiler */
			if(0 != winstl::path_squeeze(s_path, &sz[0], 0))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			// For any that are less <= len(file)
			{ for(size_t i = 1; i < STLSOFT_NUM_ELEMENTS(s_file); ++i)
			{
				if(i != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}
			// For any that cannot fit the file name and '\...\'
			{ for(size_t i = STLSOFT_NUM_ELEMENTS(s_file); i < STLSOFT_NUM_ELEMENTS(s_file) + 3; ++i)
			{
				if(STLSOFT_NUM_ELEMENTS(s_file) - 1 != winstl::path_squeeze(s_path, &sz[0], i))
				{
					r->report("path_squeeze failed: incorrect length", __LINE__);
					bSuccess = false;
				}
				if(0 != static_cast<size_t>(::strncmp(sz, s_file, i)))
				{
					r->report("path_squeeze failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}}

			if(12 != winstl::path_squeeze(s_path, &sz[0], 12))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "...\\name.ext", 12))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(13 != winstl::path_squeeze(s_path, &sz[0], 13))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "d...\\name.ext", 13))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(18 != winstl::path_squeeze(s_path, &sz[0], 18))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "dir1\\d...\\name.ext", 18))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(22 != winstl::path_squeeze(s_path, &sz[0], 22))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, "dir1\\dir2\\...\\name.ext", 22))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 1))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			if(PATH_LEN != winstl::path_squeeze(s_path, &sz[0], PATH_LEN + 2))
			{
				r->report("path_squeeze failed: incorrect length", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strncmp(sz, s_path, PATH_LEN))
			{
				r->report("path_squeeze failed: incorrect contents", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}


		ss_bool_t test_winstl_filesystem_path_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/path_functions", __FILE__);

			if(!test_winstl_filesystem_path_functions_driveRooted(r))
			{
				bSuccess = false;
			}
			if(!test_winstl_filesystem_path_functions_dirRooted(r))
			{
				bSuccess = false;
			}
			if(!test_winstl_filesystem_path_functions_uncRooted(r))
			{
				bSuccess = false;
			}
			if(!test_winstl_filesystem_path_functions_relative(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_filesystem_path_functions(test_winstl_filesystem_path_functions);
	} // anonymous namespace

} // namespace unittest
