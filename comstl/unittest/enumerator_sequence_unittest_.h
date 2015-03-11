
// Updated: 14th December 2005

#if !defined(COMSTL_INCL_COMSTL_HPP_ENUM_SEQUENCE)
# error This file cannot be directly included, and should only be included within comstl/enum_sequence.hpp
#endif /* !COMSTL_INCL_COMSTL_HPP_ENUM_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        namespace Synesis_COM
        {
#if !defined(SYFNCOMDECL)
# define SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_ENUM_SEQ_CONTEXT
# define SYFNCOMDECL    STDMETHODIMP
#endif /* !SYFNCOMDECL */

            typedef OLECHAR         OChar;
            typedef OChar const     *LPCOChar;
            typedef LPCOChar const  *LPCPCOChar;
            typedef size_t          Size;
            typedef void            **LPPVoid;

            SYFNCOMDECL CreateEnumStringFromArray(LPCPCOChar items, Size cItems, LPPVoid ppvEnum);

#ifdef SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_ENUM_SEQ_CONTEXT
# undef SYFNCOMDECL
#endif /* SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_ENUM_SEQ_CONTEXT */

        } // namespace Synesis_COM

#if !defined(STLSOFT_COMPILER_IS_DMC)
        ss_bool_t test_comstl_enum_sequence_recls_COM(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IFileEntry_);
            STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IEnumFileEntry_);
            STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_ISearchCollection_);
            STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IDirectoryPartsCollection_);
            STLSOFT_SUPPRESS_UNUSED(recls_COM::IID_IFileSearch_);

            if(::GetVersion() & 0x80000000)
            {
                r->report(  "Windows 9x system detected. Although comstl::enumerator_sequence and recls both\n"
                            "  work on these systems, I've not been bother to write the even-more-verbose \n"
                            "  client-code to effect unit-tests on these systems. Hence, the test is skipped", -1, NULL);
            }
            else
            {
                r->report("Loading recls COM server ...", -1, NULL);

                recls_COM::IFileSearch_ *pfs;
                HRESULT                 hr          =   ::CoCreateInstance( recls_COM::CLSID_FileSearch_
                                                                        ,   NULL
                                                                        ,   CLSCTX_ALL
                                                                        ,   recls_COM::IID_IFileSearch_
                                                                        ,   reinterpret_cast<void**>(&pfs));

                if(FAILED(hr))
                {
                    r->report("Cannot load recls.COM server, so skipping this test", -1, NULL);
                }
                else
                {
                    using namespace recls_COM;

                    // Find the windows directory
                    WCHAR       szWindowsDir[1 + _MAX_PATH];
                    const WCHAR szPattern[] =   L"*.exe";

                    if(0 == ::GetWindowsDirectoryW(&szWindowsDir[0], STLSOFT_NUM_ELEMENTS(szWindowsDir)))
                    {
                        lstrcpyW(&szWindowsDir[0], L".");
                    }

                    LPUNKNOWN   punkColl;

                    hr = pfs->Search(   ::SysAllocString(szWindowsDir)      // Memory-leak here, but we don't care since UT only
                                    ,   ::SysAllocString(szPattern)         // Memory-leak here, but we don't care since UT only
                                    ,   RECLS_F_FILES_ | RECLS_F_RECURSIVE_
                                    ,   &punkColl);

                    if(FAILED(hr))
                    {
                        r->report("IFileSearch::Search() failed", __LINE__);
                        bSuccess = false;
                    }
                    else
                    {
                        ISearchCollection_  *pSrchColl;

                        hr = punkColl->QueryInterface(IID_ISearchCollection_, reinterpret_cast<void**>(&pSrchColl));

                        if(FAILED(hr))
                        {
                            r->report("Object returned from IFileSearch::Search() did not support IID_ISearchCollection", __LINE__);
                            bSuccess = false;
                        }
                        else
                        {
                            LPUNKNOWN   punkEnum;

                            hr = pSrchColl->get__NewEnum(&punkEnum);

                            if(FAILED(hr))
                            {
                                r->report("Collection could not return item enumerator", __LINE__);
                                bSuccess = false;
                            }
                            else
                            {
                                IEnumFileEntry_ *penFile;

                                hr = punkEnum->QueryInterface(IID_IEnumFileEntry_, reinterpret_cast<void**>(&penFile));

                                if(FAILED(hr))
                                {
                                    r->report("Object returned from IFileSearch::Search() did not support IEnumFileEntry", __LINE__);
                                    bSuccess = false;
                                }
                                else
                                {
                                    typedef enumerator_sequence<IEnumFileEntry_
                                                            ,   IFileEntry_*
                                                            ,   interface_policy<IFileEntry_>
                                                            >           enumerator_t;

                                    enumerator_t            en(penFile, false); // Eat the reference

// For some reason, calling begin() *in this context* causes an ICE for VC++ (pre 7.1), so we skip it
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1310
                                    r->report(  "Enumerating all .exe in Windows Directory. This may take some time. Check"
                                                " the debug window for progress ... [Use w32dblog from"
                                                " http://synesis.com.au/systools.html]", -1, NULL);

                                    enumerator_t::iterator  b   =   en.begin();
                                    enumerator_t::iterator  e   =   en.end();

                                    for(; b != e; ++b)
                                    {
                                        BSTR    bstrPath;
                                        HRESULT hr2 =   (*b)->get_Path(&bstrPath);

                                        if(FAILED(hr2))
                                        {
                                        }
                                        else
                                        {
                                            ss_size_t               cchPath(::SysStringLen(bstrPath));
                                            auto_buffer<OLECHAR>    buff(cchPath + 1 + 1);

                                            ::lstrcpyW(&buff[0], bstrPath);
                                            buff[cchPath] = L'\n';
                                            buff[cchPath + 1] = L'\0';

                                            ::OutputDebugStringW(buff.data());

                                            ::SysFreeString(bstrPath);
                                        }

                                    }
#endif /* 0 */
                                }

                                punkEnum->Release();
                            }

                            pSrchColl->Release();
                        }

                        punkColl->Release();
                    }

                    pfs->Release();
                }
            }

            return bSuccess;
        }
#endif /* compiler */

        ss_bool_t test_comstl_enum_sequence_MMCOMBSC(unittest_reporter *r)
        {
            using namespace Synesis_COM;

            LPCOChar    strings[]   =   
            {
                    L"string-1"
                ,   L"string-2"
                ,   L"string-3"
            };

            ss_bool_t   bSuccess    =   true;

            r->report("Loading Synesis COM server ...", -1, NULL);

            try
            {
                LPUNKNOWN       punkEnum    =   NULL;
                HRESULT         hr;
                winstl::module  module("MMCOMBSC");

                hr = winstl::dl_call<HRESULT>(module.get_handle(), winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(144)), strings, STLSOFT_NUM_ELEMENTS(strings), reinterpret_cast<void**>(&punkEnum));

                if(FAILED(hr))
                {
                    r->report("Failed to create enumerator from Synesis COM server");
                    bSuccess = false;
                }
                else
                {
                    LPENUMSTRING    lpenStr;

                    hr = punkEnum->QueryInterface(IID_IEnumString, reinterpret_cast<void**>(&lpenStr));

                    if(FAILED(hr))
                    {
                        r->report("Cannot load Synesis COM server, so skipping this test", __LINE__);
                        bSuccess = false;
                    }
                    else
                    {
                        typedef enumerator_sequence<IEnumString
                                                ,   LPOLESTR
                                                ,   LPOLESTR_policy
                                                >           enumerator_t;

                        enumerator_t            en(lpenStr, false); // Eat the reference
                        enumerator_t::iterator  b   =   en.begin();
                        enumerator_t::iterator  e   =   en.end();

                        { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(strings); ++i)
                        {
                            if(en.end() == b)
                            {
                                r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
                                bSuccess = false;
                            }
                            else
                            {
                                if(0 != ::wcscmp(*b, strings[i]))
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
                r->report("Cannot load Synesis COM server, so skipping this test", -1, NULL);
            }

            return bSuccess;
        }

        ss_bool_t test_comstl_enum_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "enum_sequence", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_DMC)
            if(!test_comstl_enum_sequence_recls_COM(r))
            {
                bSuccess = false;
            }
#endif /* compiler */

            if(!test_comstl_enum_sequence_MMCOMBSC(r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_enum_sequence(test_comstl_enum_sequence);
    } // anonymous namespace

} // namespace unittest
