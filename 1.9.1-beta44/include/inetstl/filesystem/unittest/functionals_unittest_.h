
// Updated: 5th January 2007

#if !defined(INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FUNCTIONALS)
# error This file cannot be directly included, and should only be included within inetstl/filesystem/functionals.hpp
#endif /* !INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FUNCTIONALS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_inetstl_filesystem_functionals(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "InetSTL", "filesystem/functionals", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_inetstl_filesystem_functionals(test_inetstl_filesystem_functionals);
	} // anonymous namespace

} // namespace unittest
