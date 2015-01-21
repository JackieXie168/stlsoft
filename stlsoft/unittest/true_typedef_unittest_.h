
// Updated: 19th September 2005

#if !defined(STLSOFT_INCL_STLSOFT_HPP_TRUE_TYPEDEF)
# error This file cannot be directly included, and should only be included within stlsoft/true_typedef.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_TRUE_TYPEDEF */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        typedef struct {}                   int_u;
        typedef true_typedef<int, int_u>    int_tt;

        ss_bool_t test_stlsoft_true_typedef(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "true_typedef", __FILE__);

            int_tt  i0;
            int_tt  i1(10);

            if(0 != i0.base_type_value())
            {
                r->report("base_type_value() returns unexpected value after default construction", __LINE__);
                bSuccess = false;
            }

            if(!(10 == i1))
            {
                r->report("operator ==() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(!(i1 == 10))
            {
                r->report("operator ==() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(10 != i1)
            {
                r->report("operator !=() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(i1 != 10)
            {
                r->report("operator ==() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            ++i1;
            i1++;
            --i1;
            i1--;

            if(10 != i1.base_type_value())
            {
                r->report("base_type_value() returns unexpected value after pre & post increment and decrement operators", __LINE__);
                bSuccess = false;
            }

            if(i0 < 0)
            {
                r->report("operator <() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(i0 <= -1)
            {
                r->report("operator <=() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(i0 > 10)
            {
                r->report("operator >() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(i0 >= 11)
            {
                r->report("operator >=() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(11 != i1 + 1)
            {
                r->report("operator +() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(11 != 1 + i1)
            {
                r->report("operator +() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(9 != i1 - 1)
            {
                r->report("operator -() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(-9 != 1 - i1)
            {
                r->report("operator -() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(90 != i1 * 9)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(9 * i1 != 90)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(2 != i1 / 5)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(20 / i1 != 2)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            if(2 != i1 % 4)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }
            if(22 % i1 != 2)
            {
                r->report("operator *() does not evaluate to correct value", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_true_typedef(test_stlsoft_true_typedef);
    } // anonymous namespace

} // namespace unittest
