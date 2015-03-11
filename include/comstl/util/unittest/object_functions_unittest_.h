
// Created: 27th March 2006
// Updated: 4th July 2006

#if !defined(COMSTL_INCL_COMSTL_UTIL_H_OBJECT_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/util/object_functions.h
#endif /* !COMSTL_INCL_COMSTL_H_UTIL_H_OBJECT_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_object_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/object_functions", __FILE__);

			if(0)
			{
				LPUNKNOWN	punk1	=	NULL;
				LPUNKNOWN	punk2	=	NULL;
				LPUNKNOWN	identity;

				get_object_identity(punk1, &identity);

				is_same_object(punk1, punk2);

				is_interface_implemented(punk1, IID_IUnknown);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_object_functions(test_comstl_object_functions);
	} // anonymous namespace

} // namespace unittest
