
// Updated: 13th January 2006

#if !defined(COMSTL_INCL_COMSTL_HPP_ENUMERATOR_SEQUENCE)
# error This file cannot be directly included, and should only be included within comstl/enumerator_sequence.hpp
#endif /* !COMSTL_INCL_COMSTL_HPP_ENUMERATOR_SEQUENCE */

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

#ifndef __IEnumGUID_FWD_DEFINED__
#define __IEnumGUID_FWD_DEFINED__
            typedef interface IEnumGUID IEnumGUID;

            typedef /* [unique] */ IEnumGUID __RPC_FAR *LPENUMGUID;

            inline IID const &IID_IEnumGUID_()
            {
                static const IID IID_IEnumGUID__    =   { 0x00537963, 0x0003, 0x0013, { 0x00, 0x01, 0x00, 0xc0, 0xdf, 0xe6, 0x4a, 0x64 } };

                return IID_IEnumGUID__;
            }

            interface IEnumGUID : public IUnknown
            {
            public:
                virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE Next(
                    /* [in] */ ULONG celt,
                    /* [length_is][size_is][out] */ GUID __RPC_FAR *rgelt,
                    /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Skip(
                    /* [in] */ ULONG celt) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone(
                    /* [retval][ref][out] */ IEnumGUID __RPC_FAR *__RPC_FAR *ppenum) = 0;

            };
#endif  /* __IEnumGUID_FWD_DEFINED__ */

#ifndef __IEnumBSTR_FWD_DEFINED__
#define __IEnumBSTR_FWD_DEFINED__
            typedef interface IEnumBSTR IEnumBSTR;

            typedef /* [unique] */ IEnumBSTR __RPC_FAR *LPENUMBSTR;

            inline IID const &IID_IEnumBSTR_()
            {
                static const IID IID_IEnumBSTR__    =   { 0x00537963, 0x0003, 0x001b, { 0x00, 0x01, 0x00, 0xc0, 0xdf, 0xe6, 0x4a, 0x64 } };

                return IID_IEnumBSTR__;
            }

            interface IEnumBSTR : public IUnknown
            {
            public:
                virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE Next(
                    /* [in] */ ULONG celt,
                    /* [length_is][size_is][out] */ BSTR __RPC_FAR *rgelt,
                    /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Skip(
                    /* [in] */ ULONG celt) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;

                virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone(
                    /* [retval][ref][out] */ IEnumBSTR __RPC_FAR *__RPC_FAR *ppenum) = 0;

            };

#endif  /* __IEnumBSTR_FWD_DEFINED__ */


#ifdef SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_ENUM_SEQ_CONTEXT
# undef SYFNCOMDECL
#endif /* SYFNCOMDECL_WAS_NOT_DEFINED_IN_COMSTL_ENUM_SEQ_CONTEXT */

        } // namespace Synesis_COM

#if !defined(STLSOFT_COMPILER_IS_DMC)
        ss_bool_t test_comstl_enumerator_sequence_recls_COM(unittest_reporter *r)
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

        ss_bool_t test_comstl_enumerator_sequence_MMCOMBSC_IEnumString(HINSTANCE hinst, unittest_reporter *r)
        {
            using namespace Synesis_COM;

            static const LPCOChar   strings[]   =   
            {
                    L"string-1"
                ,   L"string-2"
                ,   L"string-3"
            };
            ss_bool_t               bSuccess    =   true;
            LPUNKNOWN               punkEnum    =   NULL;
            HRESULT                 hr          =   winstl::dl_call<HRESULT>(hinst, winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(144)), strings, STLSOFT_NUM_ELEMENTS(strings), reinterpret_cast<void**>(&punkEnum));

            if(FAILED(hr))
            {
                r->report("Failed to create string enumerator from Synesis COM server");
                bSuccess = false;
            }
            else
            {
                LPENUMSTRING    lpenStr;

                hr = punkEnum->QueryInterface(IID_IEnumString, reinterpret_cast<void**>(&lpenStr));

                if(FAILED(hr))
                {
                    r->report("Failed to retrieve required enumerator interface from enumerator object", __LINE__);
                    bSuccess = false;
                }
                else
                {
                    typedef enumerator_sequence<IEnumString
                                            ,   LPOLESTR
                                            ,   LPOLESTR_policy
                                            >           enumerator_t;

                    enumerator_t            en(lpenStr, false); // Eat the reference

                    r->report(  "Enumerating strings using IEnumString", -1, NULL);

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

            return bSuccess;
        }

        ss_bool_t test_comstl_enumerator_sequence_MMCOMBSC_IEnumGUID(HINSTANCE hinst, unittest_reporter *r)
        {
            using namespace Synesis_COM;

            GUID   guids[3];

            guids[0] = IID_IUnknown;
            guids[1] = IID_IClassFactory;
            guids[2] = IID_IMarshal;

            ss_bool_t               bSuccess    =   true;
            LPUNKNOWN               punkEnum    =   NULL;
            HRESULT                 hr          =   winstl::dl_call<HRESULT>(hinst, winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(146)), guids, STLSOFT_NUM_ELEMENTS(guids), reinterpret_cast<void**>(&punkEnum));

            if(FAILED(hr))
            {
                r->report("Failed to create GUID enumerator from Synesis COM server");
                bSuccess = false;
            }
            else
            {
                LPENUMGUID    lpenStr;

                hr = punkEnum->QueryInterface(IID_IEnumGUID_(), reinterpret_cast<void**>(&lpenStr));

                if(FAILED(hr))
                {
                    r->report("Failed to retrieve required enumerator interface from enumerator object", __LINE__);
                    bSuccess = false;
                }
                else
                {
                    typedef enumerator_sequence<IEnumGUID
                                            ,   GUID
                                            ,   GUID_policy
                                            >           enumerator_t;

                    enumerator_t            en(lpenStr, false); // Eat the reference

                    r->report(  "Enumerating GUIDs using IEnumGUID", -1, NULL);

                    enumerator_t::iterator  b   =   en.begin();
                    enumerator_t::iterator  e   =   en.end();

                    { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(guids); ++i)
                    {
                        if(en.end() == b)
                        {
                            r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
                            bSuccess = false;
                        }
                        else
                        {
                            if(*b != guids[i])
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

            return bSuccess;
        }

        ss_bool_t test_comstl_enumerator_sequence_MMCOMBSC_IEnumBSTR(HINSTANCE hinst, unittest_reporter *r)
        {
            using namespace Synesis_COM;

            BSTR    bstrs[3] =
            {
                    ::SysAllocString(L"BSTR-1")
                ,   ::SysAllocString(L"BSTR-2")
                ,   ::SysAllocString(L"BSTR-3")
            };

            ss_bool_t               bSuccess    =   true;
            LPUNKNOWN               punkEnum    =   NULL;
            HRESULT                 hr          =   winstl::dl_call<HRESULT>(hinst, winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(147)), bstrs, STLSOFT_NUM_ELEMENTS(bstrs), reinterpret_cast<void**>(&punkEnum));

            if(FAILED(hr))
            {
                r->report("Failed to create BSTR enumerator from Synesis COM server");
                bSuccess = false;
            }
            else
            {
                LPENUMBSTR  lpenStr;

                hr = punkEnum->QueryInterface(IID_IEnumBSTR_(), reinterpret_cast<void**>(&lpenStr));

                if(FAILED(hr))
                {
                    r->report("Failed to retrieve required enumerator interface from enumerator object", __LINE__);
                    bSuccess = false;
                }
                else
                {
                    typedef enumerator_sequence<IEnumBSTR
                                            ,   BSTR
                                            ,   BSTR_policy
                                            >           enumerator_t;

                    enumerator_t            en(lpenStr, false); // Eat the reference

                    r->report(  "Enumerating BSTRs using IEnumBSTR", -1, NULL);

                    enumerator_t::iterator  b   =   en.begin();
                    enumerator_t::iterator  e   =   en.end();

                    { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(bstrs); ++i)
                    {
                        if(en.end() == b)
                        {
                            r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
                            bSuccess = false;
                        }
                        else
                        {
                            if(0 != ::wcscmp(*b, bstrs[i]))
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

            ::SysFreeString(bstrs[0]);
            ::SysFreeString(bstrs[1]);
            ::SysFreeString(bstrs[2]);

            return bSuccess;
        }

        ss_bool_t test_comstl_enumerator_sequence_MMCOMBSC_IEnumVARIANT(HINSTANCE hinst, unittest_reporter *r)
        {
            using namespace Synesis_COM;

            VARIANT variants[3];

            ::VariantInit(&variants[0]);
            ::VariantInit(&variants[1]);
            ::VariantInit(&variants[2]);

            variants[0].vt      =   VT_I4;
            variants[0].lVal    =   123456;
            variants[1].vt      =   VT_BSTR;
            variants[1].bstrVal =   ::SysAllocString(L"a BSTR instance");
            variants[2].vt      =   VT_EMPTY;

            ss_bool_t               bSuccess    =   true;
            LPUNKNOWN               punkEnum    =   NULL;
            HRESULT                 hr          =   winstl::dl_call<HRESULT>(hinst, winstl::fn_desc<STLSOFT_STDCALL_VALUE>(MAKEINTRESOURCE(158)), variants, STLSOFT_NUM_ELEMENTS(variants), reinterpret_cast<void**>(&punkEnum));

            if(FAILED(hr))
            {
                r->report("Failed to create VARIANT enumerator from Synesis COM server");
                bSuccess = false;
            }
            else
            {
                LPENUMVARIANT   lpenStr;

                hr = punkEnum->QueryInterface(IID_IEnumVARIANT, reinterpret_cast<void**>(&lpenStr));

                if(FAILED(hr))
                {
                    r->report("Failed to retrieve required enumerator interface from enumerator object", __LINE__);
                    bSuccess = false;
                }
                else
                {
                    typedef enumerator_sequence<IEnumVARIANT
                                            ,   VARIANT
                                            ,   VARIANT_policy
                                            >           enumerator_t;

                    enumerator_t            en(lpenStr, false); // Eat the reference

                    r->report(  "Enumerating VARIANTs using IEnumVARIANT", -1, NULL);

                    enumerator_t::iterator  b   =   en.begin();
                    enumerator_t::iterator  e   =   en.end();

                    { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(variants); ++i)
                    {
                        if(en.end() == b)
                        {
                            r->report("Enumerator sequence contains the wrong number of elements", __LINE__);
                            bSuccess = false;
                        }
                        else
                        {
//                            b->wReserved1   =   0;

                            if((*b).vt != variants[i].vt)
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

            ::VariantClear(&variants[0]);
            ::VariantClear(&variants[1]);
            ::VariantClear(&variants[2]);

            return bSuccess;
        }

        ss_bool_t test_comstl_enumerator_sequence_MMCOMBSC(unittest_reporter *r)
        {
            using namespace Synesis_COM;

            ss_bool_t   bSuccess    =   true;

            r->report("Loading Synesis COM server ...", -1, NULL);

            try
            {
                winstl::module  module("MMCOMBSC");

                if(!test_comstl_enumerator_sequence_MMCOMBSC_IEnumString(module.get_handle(), r))
                {
                    bSuccess = false;
                }
                if(!test_comstl_enumerator_sequence_MMCOMBSC_IEnumGUID(module.get_handle(), r))
                {
                    bSuccess = false;
                }
                if(!test_comstl_enumerator_sequence_MMCOMBSC_IEnumBSTR(module.get_handle(), r))
                {
                    bSuccess = false;
                }
                if(!test_comstl_enumerator_sequence_MMCOMBSC_IEnumVARIANT(module.get_handle(), r))
                {
                    bSuccess = false;
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

        ss_bool_t test_comstl_enumerator_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "enumerator_sequence", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_DMC)
            if(!test_comstl_enumerator_sequence_recls_COM(r))
            {
                bSuccess = false;
            }
#endif /* compiler */

            if(!test_comstl_enumerator_sequence_MMCOMBSC(r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_enumerator_sequence(test_comstl_enumerator_sequence);
    } // anonymous namespace

} // namespace unittest