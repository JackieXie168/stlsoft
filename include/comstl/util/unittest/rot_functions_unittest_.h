
#if !defined(COMSTL_INCL_COMSTL_UTIL_H_ROT_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/util/rot_functions.h
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_ROT_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_rot_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/rot_functions", __FILE__);

			if(0)
			{
				Rot_Register(0, NULL, NULL, NULL);
				Rot_Revoke(0);
				Rot_IsRunning(NULL);
				Rot_GetObject(NULL, NULL);
				Rot_NoteChangeTime(0, NULL);
				Rot_GetTimeOfLastChange(NULL, NULL);
				Rot_EnumRunning(NULL);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_rot_functions(test_comstl_rot_functions);
	} // anonymous namespace

} // namespace unittest
