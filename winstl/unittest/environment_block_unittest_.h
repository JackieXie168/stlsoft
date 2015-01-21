
#if !defined(WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_BLOCK)
# error This file cannot be directly included, and should only be included within winstl/environment_block.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_BLOCK */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_environment_block(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "environment_block", __FILE__);

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_environment_block(test_winstl_environment_block);
    } // anonymous namespace

} // namespace unittest

