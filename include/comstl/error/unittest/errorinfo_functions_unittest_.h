
// Updated: 4th July 2006

#if !defined(COMSTL_INCL_COMSTL_ERROR_H_ERRORINFO_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/error/errorinfo_functions.h
#endif /* !COMSTL_INCL_COMSTL_ERROR_H_ERRORINFO_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_errorinfo_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "error/errorinfo_functions", __FILE__);

			set_error_info(L"Test info #1");

			IErrorInfo	*pei;
			HRESULT 	hr	=	::GetErrorInfo(0, &pei);

			if(S_OK == hr)
			{
				BSTR	bstrDesc;

				hr = pei->GetDescription(&bstrDesc);

				if(SUCCEEDED(hr))
				{
					if(0 != ::wcscmp(bstrDesc, L"Test info #1"))
					{
						r->report("Error information not as expected ", __LINE__);
						bSuccess = false;
					}

					::SysFreeString(bstrDesc);
				}

				pei->Release();
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_errorinfo_functions(test_comstl_errorinfo_functions);
	} // anonymous namespace

} // namespace unittest
