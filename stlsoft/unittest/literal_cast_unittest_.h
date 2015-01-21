
#if !defined(STLSOFT_INCL_STLSOFT_HPP_LITERAL_CAST)
# error This file cannot be directly included, and should only be included within stlsoft/literal_cast.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_LITERAL_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_literal_cast(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "literal_cast", __FILE__);

# if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
# endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_literal_cast(test_stlsoft_literal_cast);
    } // anonymous namespace

} // namespace unittest

