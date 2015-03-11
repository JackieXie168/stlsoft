
#if !defined(WINSTL_INCL_WINSTL_H_SCALE_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/scale_functions.hpp
#endif /* !WINSTL_INCL_WINSTL_H_SCALE_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_scale_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "scale_functions", __FILE__);

			SIZE	size	=	{ 100, 100 };
			RECT	rect	=	{ 0, 0, 100, 100 };

			if(calc_width(size) != 100)
			{
				r->report("calc_width(SIZE) failed", __LINE__);
				bSuccess = false;
			}

			if(calc_width(rect) != 100)
			{
				r->report("calc_width(RECT) failed", __LINE__);
				bSuccess = false;
			}

			if(calc_height(size) != 100)
			{
				r->report("calc_height(SIZE) failed", __LINE__);
				bSuccess = false;
			}

			if(calc_height(rect) != 100)
			{
				r->report("calc_height(RECT) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_scale_functions(test_winstl_scale_functions);
	} // anonymous namespace

} // namespace unittest

