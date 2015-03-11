
#if !defined(COMSTL_INCL_COMSTL_H_MEMORY_FUNCTIONS)
# error This file cannot be directly included, and should only be included within comstl/memory_functions.h
#endif /* !COMSTL_INCL_COMSTL_H_MEMORY_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_comstl_memory_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "COMSTL", "memory_functions", __FILE__);

            void    *pv =   ::CoTaskMemAlloc(100);

            if(CoTaskMemGetSize(pv) < 100)
            {
                r->report("Memory block has invalid size ", __LINE__);
                bSuccess = false;
            }

            if(0 == CoTaskMemDidAlloc(pv))
            {
                r->report("Memory block was not recognised by task allocator ", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_comstl_memory_functions(test_comstl_memory_functions);
    } // anonymous namespace

} // namespace unittest
