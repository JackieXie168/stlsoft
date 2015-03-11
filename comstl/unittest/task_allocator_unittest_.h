
#if !defined(COMSTL_INCL_COMSTL_HPP_TASK_ALLOCATOR)
# error This file cannot be directly included, and should only be included within comstl/task_allocator.hpp
#endif /* !COMSTL_INCL_COMSTL_HPP_TASK_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_task_allocator(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "task_allocator", __FILE__);

            typedef task_allocator<int>  int_allocator_t;

            int_allocator_t ator1;

            int     *pi1    =   ator1.allocate(100);

            if(NULL != pi1)
            {
                ator1.construct(pi1, 1968);

                if(1968 != *pi1)
                {
                    r->report("construct() and allocate() failed", __LINE__);
                    bSuccess = false;
                }
            }

            ator1.deallocate(pi1);

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_task_allocator(test_comstl_task_allocator);
    } // anonymous namespace

} // namespace unittest

