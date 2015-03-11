
#if !defined(COMSTL_INCL_COMSTL_HPP_SAFEARRAY_SEQUENCE)
# error This file cannot be directly included, and should only be included within comstl/safearray_sequence.h
#endif /* !COMSTL_INCL_COMSTL_HPP_SAFEARRAY_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_safearray_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "safearray_sequence", __FILE__);

            /* Create a safe-array. */
            SAFEARRAYBOUND  bounds[2] =
            {
                    {   10,     0   }
                ,   {   5,      0   }
            };
            LPSAFEARRAY     psa =   ::SafeArrayCreate(VT_I4, stlsoft_num_elements(bounds), bounds);

            if(NULL == psa)
            {
                r->report("failed to create array", __LINE__);
                bSuccess = false;
            }
            else
            {
                void            *pv;
                HRESULT         hr  =   ::SafeArrayAccessData(psa, &pv);

                if(FAILED(hr))
                {
                    r->report("failed to access array data", __LINE__);
                    bSuccess = false;
                }
                else
                {
                    long            *pl =   static_cast<long*>(pv);
                    cs_size_t       l;
                    long            total;

                    for(l = 0, total = 0; l < bounds[0].cElements * bounds[1].cElements; ++l)
                    {
                        pl[l]   =   static_cast<long>(l);
                        total   +=  l;
                    }
                    ::SafeArrayUnaccessData(psa);

                    comstl::safearray_sequence<long>    array(psa);

                    if(stlsoft_ns_qual_std(accumulate)(array.begin(), array.end(), static_cast<long>(0)) != total)
                    {
                        r->report("array contents (forward iteration) test failed", __LINE__);
                        bSuccess = false;
                    }

    #if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
                    if(stlsoft_ns_qual_std(accumulate)(array.rbegin(), array.rend(), static_cast<long>(0)) != total)
                    {
                        r->report("array contents (reverse iteration) test failed", __LINE__);
                        bSuccess = false;
                    }
    #endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
                }

                ::SafeArrayDestroy(psa);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_safearray_sequence(test_comstl_safearray_sequence);
    } // anonymous namespace

} // namespace unittest
