
#if !defined(WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/registry/reg_value_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_registry_reg_value_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "registry/reg_value_sequence", __FILE__);

            if(0)
            {
                reg_value_sequence_a    seq_a(HKEY_CURRENT_USER, "SOFTWARE");

                reg_value_sequence_a::const_iterator    b   =   seq_a.begin();
                reg_value_sequence_a::const_iterator    e   =   seq_a.end();

                for(; b != e; ++b)
                {
                    reg_value_sequence_a::value_type    v   =   *b;
                }
            }

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_registry_reg_value_sequence(test_winstl_registry_reg_value_sequence);
    } // anonymous namespace

} // namespace unittest

