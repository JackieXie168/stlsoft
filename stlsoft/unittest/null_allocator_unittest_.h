
#if !defined(STLSOFT_INCL_STLSOFT_HPP_NULL_ALLOCATOR)
# error This file cannot be directly included, and should only be included within stlsoft/null_allocator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_NULL_ALLOCATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_null_allocator(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "null_allocator", __FILE__);

            typedef null_allocator<int>  int_allocator_t;

            int             i;
            int_allocator_t ator1;

            ator1.construct(&i, 1968);

            if(1968 != i)
            {
                r->report("failed to construct ", __LINE__);
                bSuccess = false;
            }

#ifdef __STLSOFT_CF_THROW_BAD_ALLOC
            try
            {
                ator1.allocate(1);

                r->report("null_allocator provided a non-NULL allocation ", __LINE__);
                bSuccess = false;
            }
            catch(std::bad_alloc &)
            {
            }
#else /* ? __STLSOFT_CF_THROW_BAD_ALLOC */
            if(ator1.allocate(1) != NULL)
            {
                r->report("null_allocator provided a non-NULL allocation ", __LINE__);
                bSuccess = false;
            }
#endif /* __STLSOFT_CF_THROW_BAD_ALLOC */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_null_allocator(test_stlsoft_null_allocator);
    } // anonymous namespace

} // namespace unittest

