
#if !defined(WINSTL_INCL_WINSTL_HPP_EVENT)
# error This file cannot be directly included, and should only be included within winstl/event.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_EVENT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_event(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "event", __FILE__);

    #if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_event(test_winstl_event);
    } // anonymous namespace

} // namespace unittest

