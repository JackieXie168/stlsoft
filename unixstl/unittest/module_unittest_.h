
// Updated: 2nd September 2005

#if !defined(UNIXSTL_INCL_UNIXSTL_HPP_MODULE)
# error This file cannot be directly included, and should only be included within unixstl/module.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_MODULE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_unixstl_module(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "UNIXSTL", "file_module", __FILE__);

            try
            {
                module                      m1("something_or_other.not_likely.to_exist.so");
                module::module_handle_type  h1  =   m1.get_handle();
                module::module_handle_type  h2;

                m1.get_symbol("and_now_a_symbol_that_is_unlikely_to_exist");

                h2 = m1.detach();

                module                      m2(h2);

                m2.get_symbol("and_now_a_symbol_that_is_unlikely_to_exist");

                m2.unload();

                STLSOFT_SUPPRESS_UNUSED(h1);
                STLSOFT_SUPPRESS_UNUSED(h2);
                STLSOFT_SUPPRESS_UNUSED(m1);
                STLSOFT_SUPPRESS_UNUSED(m2);
            }
            catch(...)
            {}

            return bSuccess;
        }

        unittest_registrar    unittest_unixstl_module(test_unixstl_module);
    } // anonymous namespace

}// namespace unittest
