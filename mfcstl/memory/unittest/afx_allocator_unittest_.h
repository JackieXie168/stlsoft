
#if !defined(MFCSTL_INCL_MFCSTL_MEMORY_HPP_AFX_ALLOCATOR)
# error This file cannot be directly included, and should only be included within mfcstl/memory/afx_allocator.hpp
#endif /* !MFCSTL_INCL_MFCSTL_MEMORY_HPP_AFX_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing MFCSTL
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_mfcstl_memory_afx_allocator(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "MFCSTL", "memory/afx_allocator", __FILE__);

            typedef afx_allocator<int>  int_allocator_t;

            int_allocator_t ator1;

            int     *pi1    =   ator1.allocate(100);

            if(NULL != pi1)
            {
                ator1.construct(pi1, 1968);

                if(1968 != *pi1)
                {
                    r->report("construct() failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_mfcstl_memory_afx_allocator(test_mfcstl_memory_afx_allocator);
    } // anonymous namespace

} // namespace unittest
