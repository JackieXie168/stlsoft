
// Updated: 14th December 2005

#if !defined(STLSOFT_INCL_STLSOFT_STD_HPP_CSTDLIB)
# error This file cannot be directly included, and should only be included within stlsoft/std/cstdlib.hpp
#endif /* !STLSOFT_INCL_STLSOFT_STD_HPP_CSTDLIB */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_std_cstdlib(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "std/cstdlib", __FILE__);

			if(-10 != stlsoft::atoi("-10"))
			{
				r->report("atoi(char*) failed", __LINE__);
				bSuccess = false;
			}

#ifdef STLSOFT_STD_CSTDLIB_WTOI_SUPPORTED
			if(-10 != stlsoft::atoi(L"-10"))
			{
				r->report("atoi(wchar_t*) failed", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_STD_CSTDLIB_WTOI_SUPPORTED */



			if(-10 != stlsoft::atol("-10"))
			{
				r->report("atol(char*) failed", __LINE__);
				bSuccess = false;
			}

#ifdef STLSOFT_STD_CSTDLIB_WTOL_SUPPORTED
			if(-10 != stlsoft::atol(L"-10"))
			{
				r->report("atol(wchar_t*) failed", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_STD_CSTDLIB_WTOL_SUPPORTED */



			{ double d = stlsoft::atof("9.999");

			if( d < 9.99 ||
				d > 10.0)
			{
				r->report("atof(char*) failed", __LINE__);
				bSuccess = false;
			}}

#ifdef STLSOFT_STD_CSTDLIB_WTOF_SUPPORTED
			{ double d = stlsoft::atof(L"9.999");

			if( d < 9.99 ||
				d > 10.0)
			{
				r->report("atof(wchar_t*) failed", __LINE__);
				bSuccess = false;
			}}
#endif /* STLSOFT_STD_CSTDLIB_WTOF_SUPPORTED */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_std_cstdlib(test_stlsoft_std_cstdlib);
	} // anonymous namespace

} // namespace unittest

