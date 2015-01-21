
// Updated: 11th August 2007

#if !defined(COMSTL_INCL_COMSTL_ERROR_H_EXCEPINFO_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/error/excepinfo_functions.h
#endif /* !COMSTL_INCL_COMSTL_ERROR_H_EXCEPINFO_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_excepinfo_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "error/excepinfo_functions", __FILE__);

			EXCEPINFO				xi;

			xi.bstrSource		=	::SysAllocString(L"source");
			xi.bstrDescription	=	::SysAllocString(L"description");
			xi.bstrHelpFile 	=	::SysAllocString(L"help file");

			EXCEPINFO_free(&xi);

			if(NULL != xi.bstrSource)
			{
				r->report("EXCEPINFO_free failed to free source string", __LINE__);
				bSuccess = false;
			}

			if(NULL != xi.bstrDescription)
			{
				r->report("EXCEPINFO_free failed to free description string", __LINE__);
				bSuccess = false;
			}

			if(NULL != xi.bstrHelpFile)
			{
				r->report("EXCEPINFO_free failed to free help file string", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_excepinfo_functions(test_comstl_excepinfo_functions);
	} // anonymous namespace

} // namespace unittest
