
#if !defined(ATLSTL_INCL_ATLSTL_HPP_ATLSTL)
# error This file cannot be directly included, and should only be included within atlstl/atlstl.hpp
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;
			char					szVersion[101];
			unsigned				atlverHi	=	HIBYTE(_ATL_VER);
			unsigned				atlverLo	=	HIBYTE(_ATL_VER);

			sprintf(szVersion, "ATL %u.%u", atlverHi, atlverLo);

			unittest_initialiser	init(r, "ATLSTL", szVersion, __FILE__);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_string_tokeniser(test_atlstl);
	} // anonymous namespace

} // namespace unittest
