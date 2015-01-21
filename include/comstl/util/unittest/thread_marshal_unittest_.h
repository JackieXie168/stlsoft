
// Updated: 4th July 2006

#if !defined(COMSTL_INCL_COMSTL_UTIL_HPP_THREAD_MARSHAL)
# error This file cannot be directly included, and should only be included within comstl/util/thread_marshal.hpp
#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_THREAD_MARSHAL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_thread_marshal(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/thread_marshal", __FILE__);

			typedef HRESULT (WINAPI* PFnCreateEnumStringFromArray)(LPCOLESTR const* , size_t , void** );

			static const LPCOLESTR	strings[] =
			{
					L"string-#1"
				,	L"string-#2"
			};

			HINSTANCE						hinst	=	::LoadLibraryA("MMCOMBSC.DLL");
			PFnCreateEnumStringFromArray	pfn 	=	(NULL != hinst) ? (PFnCreateEnumStringFromArray)::GetProcAddress(hinst, "CreateEnumStringFromArray") : NULL;
			IEnumString 					*pes	=	NULL;
			HRESULT 						hr		=	(NULL != pfn) ? (*pfn)(strings, STLSOFT_NUM_ELEMENTS(strings), reinterpret_cast<void**>(&pes)) : E_FAIL;

			if(SUCCEEDED(hr))
			{
				LPSTREAM	pstm;
				HRESULT 	hr	=	MarshalInterThreadInterfaceInStream(pes, &pstm);

				if(SUCCEEDED(hr))
				{
					IEnumString *pes2;

					hr = GetInterfaceAndReleaseStream(pstm, &pes2);

					if(SUCCEEDED(hr))
					{
						// Test the contents here
						LPOLESTR	str;

						pes2->Reset();
						if(S_OK != pes2->Next(1, &str, NULL))
						{
							r->report("Next() failed on the copy", __LINE__);
							bSuccess = false;
						}
						else
						{
							if(0 != ::lstrcmpW(str, strings[0]))
							{
								r->report("First string retrieved does not match expected value", __LINE__);
								bSuccess = false;
							}
							::CoTaskMemFree(str);
						}

						if(bSuccess)
						{
							if(S_OK != pes2->Next(1, &str, NULL))
							{
								r->report("Next() failed on the copy", __LINE__);
								bSuccess = false;
							}
							else
							{
								if(0 != ::lstrcmpW(str, strings[1]))
								{
									r->report("Second string retrieved does not match expected value", __LINE__);
									bSuccess = false;
								}
								::CoTaskMemFree(str);
							}
						}

						pes2->Release();
					}
				}

				pes->Release();
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_thread_marshal(test_comstl_thread_marshal);
	} // anonymous namespace
} // namespace unittest
