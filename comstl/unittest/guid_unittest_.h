
#if !defined(COMSTL_INCL_HPP_COMSTL_GUID)
# error This file cannot be directly included, and should only be included within comstl/guid.hpp
#endif /* !COMSTL_INCL_HPP_COMSTL_GUID */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_guid(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;
            using stlsoft::null_exception_policy;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "guid", __FILE__);

#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
            try
            {
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
                guid        g1;

#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
            }
            catch(com_exception &)
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
            if(GUID_NULL != g1)
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
            {
                r->report("default construction failed", __LINE__);
                bSuccess = false;
            }

            guid        g2(IID_IUnknown);

            if(IID_IUnknown != g2)
            {
                r->report("conversion construction failed", __LINE__);
                bSuccess = false;
            }

            guid        g3(g2);

            if(g2 != g3)
            {
                r->report("copy construction failed", __LINE__);
                bSuccess = false;
            }

            try
            {
                guid    g4(c_str_ptr_a(g3));

                if(g4 != g3)
                {
                    r->report("conversion construction from ANSI string failed", __LINE__);
                    bSuccess = false;
                }

                guid    g5(c_str_ptr_w(g3));

                if(g5 != g3)
                {
                    r->report("conversion construction from Unicode string failed", __LINE__);
                    bSuccess = false;
                }

                guid    g6(c_str_ptr(g3));

                if(g6 != g3)
                {
                    r->report("conversion construction from string failed", __LINE__);
                    bSuccess = false;
                }
            }
            catch(comstl::com_exception &/* x */)
            {
                r->report("conversion construction from string failed", __LINE__);
                bSuccess = false;
            }

            try
            {
                guid    g7("lemon scented");

#ifdef __STLSOFT_CF_EXCEPTION_SUPPORT
#else /* ? __STLSOFT_CF_EXCEPTION_SUPPORT */
                if(m_guid != GUID_NULL)
#endif /* __STLSOFT_CF_EXCEPTION_SUPPORT */
                {
                    r->report("conversion construction from string succeeded when it should not", __LINE__);
                    bSuccess = false;
                }
            }
            catch(comstl::com_exception &/* x */)
            {
            }

            return bSuccess;
        }


        unittest_registrar    unittest_comstl_guid(test_comstl_guid);
    } // anonymous namespace

} // namespace unittest
