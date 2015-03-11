
// Updated: 24th March 2008

#if !defined(UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_STRING_HPP_DIRENT)
# error This file cannot be directly included, and should only be included within unixstl/shims/access/string/dirent.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_STRING_HPP_DIRENT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_unixstl_shims_access_string_dirent(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "shims/access/string/dirent", __FILE__);

			struct dirent	de;

			::strcpy(de.d_name, "/home/stlsoft");

			if(0 != strcmp("/home/stlsoft", c_str_ptr(de)))
			{
				r->report("c_str_ptr(dirent &) failed", __LINE__);
				bSuccess = false;
			}

			if(0 != strcmp("/home/stlsoft", c_str_ptr(&de)))
			{
				r->report("c_str_ptr(dirent *) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_shims_access_string_dirent(test_unixstl_shims_access_string_dirent);
	} // anonymous namespace

}// namespace unittest
