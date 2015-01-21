
#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/union_cast.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        namespace union_cast_test_types_namespace
        {
            struct S1
            {
                uint8_t     c1;
                uint8_t     c2;
                uint8_t     c3;
                uint8_t     c4;
            };

            struct S2
            {
                uint16_t    s1;
                uint16_t    s2;
            };

        } // namespace union_cast_test_types_namespace

        ss_bool_t test_stlsoft_conversion_union_cast(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "conversion/union_cast", __FILE__);

            int     i;
            void    *pv =   &i;
            short   *ps =   reinterpret_cast<short*>(&i);

            if(union_cast<short*>(pv) != ps)
            {
                r->report("union_cast failed", __LINE__);
                bSuccess = false;
            }

            {
                using namespace union_cast_test_types_namespace;

                S1      *ps1    =   NULL;
                S2      *ps2    =   union_cast<S2*>(ps1);

                STLSOFT_SUPPRESS_UNUSED(ps2);
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_conversion_union_cast(test_stlsoft_conversion_union_cast);
    } // anonymous namespace

} // namespace unittest
