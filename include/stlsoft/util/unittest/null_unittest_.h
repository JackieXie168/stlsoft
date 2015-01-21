
// Updated: 6th July 2006

// Thanks:	Martin J Moene, for the test cases

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL)
# error This file cannot be directly included, and should only be included within stlsoft/util/null.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		struct A
		{
		   int f();
		};

		ss_bool_t test_stlsoft_null(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/null", __FILE__);

#ifdef _STLSOFT_NULL_v_DEFINED

			int *pi 		=	NULL_v();
			int *pci		=	NULL_v();
# ifdef _STLSOFT_NULL_v_DEFINED_PTR_TO_MEMBER_SUPPORT
			int (A::*fp)()	=	NULL_v();
# endif /* _STLSOFT_NULL_v_DEFINED_PTR_TO_MEMBER_SUPPORT */

# if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
# endif /* 0 */

# ifdef _STLSOFT_NULL_v_DEFINED_PTR_TO_MEMBER_SUPPORT
			STLSOFT_SUPPRESS_UNUSED(fp);
# endif /* _STLSOFT_NULL_v_DEFINED_PTR_TO_MEMBER_SUPPORT */
			STLSOFT_SUPPRESS_UNUSED(pci);
			STLSOFT_SUPPRESS_UNUSED(pi);

#endif /* _STLSOFT_NULL_v_DEFINED */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_null(test_stlsoft_null);
	} // anonymous namespace

} // namespace unittest
