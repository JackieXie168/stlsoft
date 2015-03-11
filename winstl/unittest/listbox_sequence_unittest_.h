
#if !defined(WINSTL_INCL_WINSTL_HPP_LISTBOX_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/listbox_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_LISTBOX_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_listbox_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "listbox_sequence", __FILE__);

#if 0
            if(0 != i)
            {
                r->report("lock() - unlock() sequence failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_listbox_sequence(test_winstl_listbox_sequence);
    } // anonymous namespace

} // namespace unittest
