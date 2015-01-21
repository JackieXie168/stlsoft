
#if !defined(WINSTL_INCL_WINSTL_HPP_COMBOBOX_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/combobox_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_COMBOBOX_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_combobox_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "combobox_sequence", __FILE__);

#if 0
            if(0 != i)
            {
                r->report("lock() - unlock() sequence failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_combobox_sequence(test_winstl_combobox_sequence);
    } // anonymous namespace

} // namespace unittest
