
#if !defined(COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/util/refcount_functions.h
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_REFCOUNT_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_refcount_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/refcount_functions", __FILE__);

			LPSTREAM	pstm;
			HRESULT 	hr	=	::CreateStreamOnHGlobal(NULL, true, &pstm);

			if(SUCCEEDED(hr))
			{
				addref(pstm);
				release(pstm);

				safe_addref(NULL);
				safe_release(NULL);

				release_set_null(pstm);

				if(NULL != pstm)
				{
					r->report("release_set_null() failed to set to NULL", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_refcount_functions(test_comstl_refcount_functions);
	} // anonymous namespace

} // namespace unittest