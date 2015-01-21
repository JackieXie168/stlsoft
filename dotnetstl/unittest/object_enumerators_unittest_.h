
#if !defined(DOTNETSTL_INCL_DOTNETSTL_HPP_OBJECT_ENUMERATORS)
# error This file cannot be directly included, and should only be included within dotnetstl/object_enumerators.hpp
#endif /* !DOTNETSTL_INCL_DOTNETSTL_HPP_OBJECT_ENUMERATORS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_dotnetstl_object_enumerators(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, ".netSTL", "object_enumerators", __FILE__);

#if 0
            if(<<TODO>>)
            {
                r->report("<<TODO>> failed", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_dotnetstl_object_enumerators(test_dotnetstl_object_enumerators);
    } // anonymous namespace

} // namespace unittest
