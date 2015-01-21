
#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH)
# error This file cannot be directly included, and should only be included within winstl/absolute_path.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_ABSOLUTE_PATH */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_absolute_path(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/absolute_path", __FILE__);

			TCHAR	cwd[1 + _MAX_PATH];

			::GetCurrentDirectory(STLSOFT_NUM_ELEMENTS(cwd), cwd);

			if(0 != ::lstrcmp(cwd, absolute_path(".").c_str()))
			{
				r->report("absolute path for \".\" failed", __LINE__);
				bSuccess = false;
			}

#if !defined(STLSOFT_COMPILER_IS_GCC)	// I'm really starting to hate GCC!
			if(0 != ::lstrcmp(cwd, stlsoft::c_str_ptr(absolute_path("."))))
			{
				r->report("absolute path for \".\" failed", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_absolute_path(test_winstl_absolute_path);
	} // anonymous namespace

} // namespace unittest
