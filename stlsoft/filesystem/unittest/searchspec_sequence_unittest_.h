
#if !defined(STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_SEARCHSPEC_SEQUENCE)
# error This file cannot be directly included, and should only be included within stlsoft/searchspec_sequence.hpp
#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_SEARCHSPEC_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_filesystem_searchspec_sequence(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "filesystem/searchspec_sequence", __FILE__);

    #if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
    #endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_filesystem_searchspec_sequence(test_stlsoft_filesystem_searchspec_sequence);
    } // anonymous namespace

} // namespace unittest

