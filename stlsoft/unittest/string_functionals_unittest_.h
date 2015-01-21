\
// Updated: 23rd December 2005

#if !defined(STLSOFT_INCL_STLSOFT_HPP_STRING_FUNCTIONALS)
# error This file cannot be directly included, and should only be included within stlsoft/string_functionals.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_STRING_FUNCTIONALS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_string_functionals(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "string_functionals", __FILE__);

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_string_functionals(test_stlsoft_string_functionals);
    } // anonymous namespace

} // namespace unittest
