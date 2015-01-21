
#if !defined(WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR)
# error This file cannot be directly included, and should only be included within winstl/processheap_allocator.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_PROCESSHEAP_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_processheap_allocator(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "processheap_allocator", __FILE__);

            typedef processheap_allocator<int>  int_allocator_t;

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

            ator1.deallocate(pi1);

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_processheap_allocator(test_winstl_processheap_allocator);
    } // anonymous namespace

} // namespace unittest

