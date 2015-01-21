
#if !defined(WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS)
# error This file cannot be directly included, and should only be included within winstl/control/functionals.hpp
#endif /* !WINSTL_INCL_WINSTL_CONTROL_HPP_FUNCTIONALS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_control_functionals(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "control/functionals", __FILE__);

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_control_functionals(test_winstl_control_functionals);
	} // anonymous namespace

} // namespace unittest
