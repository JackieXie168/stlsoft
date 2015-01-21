
#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FUNCTIONALS)
# error This file cannot be directly included, and should only be included within winstl/filesystem/functionals.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FUNCTIONALS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_filesystem_functionals(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/functionals", __FILE__);


			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_filesystem_functionals(test_winstl_filesystem_functionals);
	} // anonymous namespace

} // namespace unittest
