
// Updated: 20th January 2006

#if !defined(STLSOFT_INCL_STLSOFT_HPP_PTR_PROXY)
# error This file cannot be directly included, and should only be included within stlsoft/ptr_proxy.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_PTR_PROXY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_ptr_proxy(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;
            unittest_initialiser    init(r, "STLSoft", "ptr_proxy", __FILE__);

            int             i       =   1;
            int             *pi     =   &i;
            int             *pi2;

            ptr_proxy<int>  ppi1(pi);
            ptr_proxy<int>  ppi2    =   ppi1;
            ptr_proxy<int>  ppi3(NULL);

            ppi3 = ppi1;

            pi2 = ppi1;
            if(pi2 != pi)
            {
                r->report("implicit conversion operator failed", __LINE__);
                bSuccess = false;
            }
            pi2 = ppi1;
            if(pi2 != pi)
            {
                r->report("implicit conversion operator failed", __LINE__);
                bSuccess = false;
            }
            pi2 = ppi2;
            if(pi2 != pi)
            {
                r->report("implicit conversion operator failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_ptr_proxy(test_stlsoft_ptr_proxy);
    } // anonymous namespace

} // namespace unittest
