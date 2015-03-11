
#if !defined(STLSOFT_INCL_STLSOFT_HPP_FIXED_ARRAY)
# error This file cannot be directly included, and should only be included within stlsoft/fixed_array.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_FIXED_ARRAY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_fixed_array(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "fixed_array", __FILE__);

            typedef fixed_array_1d<int>     fa1d_t;
            typedef fixed_array_2d<int>     fa2d_t;
            typedef fixed_array_3d<int>     fa3d_t;
            typedef fixed_array_4d<int>     fa4d_t;

            fa1d_t  a1d_1(10);
            fa2d_t  a2d_1(10, 20);
            fa3d_t  a3d_1(10, 20, 30);
            fa4d_t  a4d_1(10, 20, 30, 40);

            fa1d_t  a1d_2(a1d_1);
            fa2d_t  a2d_2(a2d_1);
            fa3d_t  a3d_2(a3d_1);
            fa4d_t  a4d_2(a4d_1);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_fixed_array(test_stlsoft_fixed_array);
    } // anonymous namespace

} // namespace unittest
