
// Updated: 19th September 2005

#if !defined(COMSTL_INCL_COMSTL_HPP_SECURITY_INITIALISERS)
# error This file cannot be directly included, and should only be included within comstl/security_initialisers.hpp
#endif /* !COMSTL_INCL_COMSTL_HPP_SECURITY_INITIALISERS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_security_initialisers(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "security_initialisers", __FILE__);

            if(0)
            {
#ifdef __IAccessControl_INTERFACE_DEFINED__
                CoInitSecurity(static_cast<LPUNKNOWN>(0), 0, NULL, 0, 0, NULL, 0);
#endif // __IAccessControl_INTERFACE_DEFINED__
                CoInitSecurity(GUID(), 0, NULL, 0, 0, NULL, 0);
                CoInitSecurity(static_cast<SECURITY_DESCRIPTOR*>(0), 0, NULL, 0, 0, NULL, 0);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_security_initialisers(test_comstl_security_initialisers);
    } // anonymous namespace

} // namespace unittest

