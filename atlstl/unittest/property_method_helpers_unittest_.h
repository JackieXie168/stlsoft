
#if !defined(ATLSTL_INCL_ATLSTL_HPP_PROPERTY_METHOD_HELPERS)
# error This file cannot be directly included, and should only be included within atlstl/property_method_helpers.hpp
#endif /* !ATLSTL_INCL_ATLSTL_HPP_PROPERTY_METHOD_HELPERS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        class SimpleServer
        {
        public:
            SimpleServer()
                : m_bstrUserName("[No username]")
                , m_logonKey(-1)
            {}

        // Property accessors
        public:
            STDMETHODIMP SimpleServer::get_UserName(/* [retval][out] */ BSTR *pVal)
            {
                return get_MemberValue(this, pVal, &SimpleServer::m_bstrUserName);
            }

            STDMETHODIMP SimpleServer::put_UserName(/* [in] */ BSTR newVal)
            {
                return put_MemberValue(this, newVal, &SimpleServer::m_bstrUserName);
            }

            STDMETHODIMP SimpleServer::get_LogonKey(/* [retval][out] */ short *pVal)
            {
                return get_MemberValue(this, pVal, &SimpleServer::m_logonKey);
            }

            STDMETHODIMP SimpleServer::put_LogonKey(/* [in] */ short newVal)
            {
                return put_MemberValue(this, newVal, &SimpleServer::m_logonKey);
            }

        // Members
        protected:
            friend ss_bool_t test_atlstl_property_method_helpers(unittest_reporter *r);

            CComBSTR    m_bstrUserName;
            short       m_logonKey;
        };

        ss_bool_t test_atlstl_property_method_helpers(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;
            HRESULT                 hr;

            unittest_initialiser    init(r, "ATLSTL", "property_method_helpers", __FILE__);

            SimpleServer    simpleserver;
            short           logonKey(-1);
            CComBSTR        bstrUserName;

            hr = simpleserver.put_LogonKey(12);
            if(FAILED(hr))
            {
                r->report("call to put_LogonKey() failed", __LINE__);
                bSuccess = false;
            }

            hr = simpleserver.get_LogonKey(&logonKey);
            if(FAILED(hr))
            {
                r->report("call to get_LogonKey() failed", __LINE__);
                bSuccess = false;
            }
            else
            {
                if(12 != logonKey)
                {
                    r->report("put/get_MemberValue failed", __LINE__);
                    bSuccess = false;
                }
            }

            simpleserver.put_UserName(L"Matty");
            hr = simpleserver.get_UserName(&bstrUserName);
            if(SUCCEEDED(hr))
            {
#if _ATL_VER < 0x0300
                if(0 != wcscmp(bstrUserName, L"Matty"))
#else /* ? _ATL_VER < 0x0300 */
                if(!(bstrUserName == L"Matty"))
#endif /* _ATL_VER < 0x0300 */
                {
                    r->report("put/get_MemberValue failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_atlstl_property_method_helpers(test_atlstl_property_method_helpers);
    } // anonymous namespace

} // namespace unittest
