
#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK)
# error This file cannot be directly included, and should only be included within stlsoft/containers/environment_block.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_containers_environment_block(unittest_reporter *r)
        {
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
            using stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "containers/environment_block", __FILE__);

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_containers_environment_block(test_stlsoft_containers_environment_block);
    } // anonymous namespace

} // namespace unittest
