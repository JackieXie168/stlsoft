
#if !defined(ACESTL_INCL_ACESTL_HPP_CUSTOM_EVENT_HANDLER)
# error This file cannot be directly included, and should only be included within acestl/custom_event_handler.hpp
#endif /* !ACESTL_INCL_ACESTL_HPP_CUSTOM_EVENT_HANDLER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_acestl_custom_event_handler(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "ACESTL", "custom_event_handler", __FILE__);

#if 0
            typedef custom_event_handler<char>    env_var_t;

            {
                r->report("custom_event_handler<char> failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_acestl_custom_event_handler(test_acestl_custom_event_handler);
    } // anonymous namespace

} // namespace unittest
