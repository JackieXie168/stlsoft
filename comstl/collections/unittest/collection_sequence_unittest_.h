
// Updated: 4th July 2006

#if !defined(COMSTL_INCL_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE)
# error This file cannot be directly included, and should only be included within comstl/collections/collection_sequence.hpp
#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_COLLECTION_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace Synesis_COM_coll
		{
#if !defined(SYFNCOMDECL)
# define SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_COLL_SEQ_CONTEXT
# define SYFNCOMDECL	STDMETHODIMP
#endif /* !SYFNCOMDECL */

			typedef OLECHAR 		OChar;
			typedef OChar const 	*LPCOChar;
			typedef LPCOChar const	*LPCPCOChar;
			typedef size_t			Size;
			typedef void			**LPPVoid;

			SYFNCOMDECL CreateEnumStringFromArray(LPCPCOChar items, Size cItems, LPPVoid ppvEnum);

#ifdef SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_COLL_SEQ_CONTEXT
# undef SYFNCOMDECL
#endif /* SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_COLL_SEQ_CONTEXT */

		} // namespace Synesis_COM_coll

#if !defined(STLSOFT_COMPILER_IS_DMC)
		ss_bool_t test_comstl_coll_sequence_recls_COM(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IFileEntry_);
			STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IEnumFileEntry_);
			STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_ISearchCollection_);
			STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IDirectoryPartsCollection_);
			STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IFileSearch_);

			if(::GetVersion() & 0x80000000)
			{
				r->report(	"Windows 9x system detected. Although comstl::collection_sequence and recls both\n"
							"  work on these systems, I've not been bother to write the even-more-verbose \n"
							"  client-code to effect unit-tests on these systems. Hence, the test is skipped");
			}
			else
			{
				r->report("Loading recls COM server ...", -1, NULL);

				recls_COM::IFileSearch_ *pfs;
				HRESULT 				hr	=	::CoCreateInstance( recls_COM::CLSID_FileSearch_
																,	NULL
																,	CLSCTX_ALL
																,	recls_COM::IID_IFileSearch_
																,	reinterpret_cast<void**>(&pfs));

				if(FAILED(hr))
				{
					r->report("Cannot load recls.COM server, so skipping this test");
				}
				else
				{
					using namespace recls_COM;

					// Find the windows directory
					WCHAR		szWindowsDir[1 + _MAX_PATH];
					const WCHAR szPattern[] =	L"*.dll";

					if(0 == ::GetWindowsDirectoryW(&szWindowsDir[0], STLSOFT_NUM_ELEMENTS(szWindowsDir)))
					{
						lstrcpyW(&szWindowsDir[0], L".");
					}

					LPUNKNOWN	punkColl;

					hr = pfs->Search(	::SysAllocString(szWindowsDir)		// Memory-leak here, but we don't care since UT only
									,	::SysAllocString(szPattern) 		// Memory-leak here, but we don't care since UT only
									,	RECLS_F_FILES_ | RECLS_F_RECURSIVE_
									,	&punkColl);

					if(FAILED(hr))
					{
						r->report("IFileSearch::Search() failed", __LINE__);
						bSuccess = false;
					}
					else
					{
						ISearchCollection_	*pSrchColl;

#ifdef _DEBUG
						IID iid =	IID_traits<IFileEntry_>::iid();

						STLSOFT_SUPPRESS_UNUSED(iid);
#endif /* _DEBUG */

#if 0
						hr = punkColl->QueryInterface(IID_ISearchCollection_, reinterpret_cast<void**>(&pSrchColl));
#else /* ? 0 */
						hr = punkColl->QueryInterface(::comstl::IID_traits<ISearchCollection_>::iid(), reinterpret_cast<void**>(&pSrchColl));
#endif /* 0 */

						if(FAILED(hr))
						{
							r->report("Object returned from IFileSearch::Search() did not support IID_ISearchCollection", __LINE__);
							bSuccess = false;
						}
						else
						{
							typedef collection_sequence<ISearchCollection_
													,	IEnumFileEntry_
													,	IFileEntry_*
													,	interface_policy<IFileEntry_>
#if 0
													,	IFileEntry_*
#endif /* 0 */
													>		collection_t;

							collection_t		coll(pSrchColl, false); // Eat the reference


							r->report(	"Enumerating all .dll in Windows Directory. This may take some time. Check"
										" the debug window for progress ... [Use w32dblog from"
										" http://synesis.com.au/systools.html]", -1, NULL);

// For some reason, calling begin() *in this context* causes an ICE for VC++ (pre 7.1), so we skip it
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER >= 1310
							collection_t::iterator	b	=	coll.begin();
							collection_t::iterator	e	=	coll.end();

							for(; b != e; ++b)
							{
								BSTR	bstrPath;
								HRESULT hr2;

								if(0 == (::GetTickCount() & 0x07))
								{
									hr2 = (*b)->get_Path(&bstrPath);
								}
								else
								{
									IFileEntry_ *pfe	=	*(b.operator ->());

									hr2 = pfe->get_Path(&bstrPath);
								}

								if(FAILED(hr2))
								{
								}
								else
								{
									ss_size_t				cchPath(::SysStringLen(bstrPath));
									auto_buffer<OLECHAR>	buff(cchPath + 1 + 1);

									::lstrcpyW(&buff[0], bstrPath);
									buff[cchPath] = L'\n';
									buff[cchPath + 1] = L'\0';

									::OutputDebugStringW(buff.data());

									::SysFreeString(bstrPath);
								}

							}
#endif /* 0 */
						}

						punkColl->Release();
					}

					pfs->Release();
				}
			}

			return bSuccess;
		}
#endif /* compiler */

#if 0
		ss_bool_t test_comstl_coll_sequence_MMCOMBSC(unittest_reporter *r)
		{
			using namespace Synesis_COM;

			LPCOChar	strings[]	=
			{
					L"string-1"
				,	L"string-2"
				,	L"string-3"
			};

			ss_bool_t	bSuccess	=	true;

			r->report("Loading Synesis COM server ...");

			try
			{
				LPUNKNOWN		punkEnum	=	NULL;
				HRESULT 		hr			=	E_FAIL;
				winstl::module	module("MMCOMBSC");

				hr = winstl::dl_call<HRESULT>(module.get_handle(), winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(144)), strings, STLSOFT_NUM_ELEMENTS(strings), reinterpret_cast<void**>(&punkEnum));

				if(FAILED(hr))
				{
					r->report("Failed to create enumerator from Synesis COM server", __LINE__);
					bSuccess = false;
				}
				else
				{
					LPENUMSTRING	lpenStr;

					hr = punkEnum->QueryInterface(IID_IEnumString, reinterpret_cast<void**>(&lpenStr));

					if(FAILED(hr))
					{
						r->report("Cannot load Synesis COM server, so skipping this test", __LINE__);
						bSuccess = false;
					}
					else
					{
						typedef enumerator_sequence<IEnumString
												,	LPOLESTR
												,	LPOLESTR_policy
												>			enumerator_t;

						enumerator_t			en(lpenStr, false); // Eat the reference
						enumerator_t::iterator	b	=	en.begin();
						enumerator_t::iterator	e	=	en.end();

						{ for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(strings); ++i)
						{
							if(en.end() == b)
							{
								r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
								bSuccess = false;
							}
							else
							{
								LPCOLESTR	str;

								if(0 == (::GetTickCount() & 0x07))
								{
									str =	*b;
								}
								else
								{
									str =	*(b.operator ->());
								}

								if(0 != ::wcscmp(str, strings[i]))
								{
									r->report("Enumerator sequence element contains the wrong value", __LINE__);
									bSuccess = false;
								}

								++b;
							}
						}}

						if(en.end() != b)
						{
							r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
							bSuccess = false;
						}
					}

					punkEnum->Release();
				}
			}
			catch(winstl::missing_entry_point_exception &)
			{
				r->report("Entry point not located in Synesis COM server", __LINE__);
				bSuccess = false;
			}
			catch(winstl::windows_exception &)
			{
				r->report("Cannot load Synesis COM server, so skipping this test", __LINE__);
			}

			return bSuccess;
		}
#endif /* 0 */

		ss_bool_t test_comstl_coll_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "collections/coll_sequence", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_DMC)
			if(!test_comstl_coll_sequence_recls_COM(r))
			{
				bSuccess = false;
			}
#endif /* compiler */

#if 0
			if(!test_comstl_coll_sequence_MMCOMBSC(r))
			{
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_coll_sequence(test_comstl_coll_sequence);
	} // anonymous namespace

} // namespace unittest
