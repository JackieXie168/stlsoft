
// Updated: 31st December 2005

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_same_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)

    namespace
    {
        namespace
        {
            class ist_Parent
            {};

            class ist_Child
                : public ist_Parent
            {};

        } // anonymous namespace

        ss_bool_t test_stlsoft_meta_is_same_type(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "meta/is_same_type", __FILE__);

#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

            // Same type

            if(0 == is_same_type<void, void>::value)
            {
                r->report("is_same_type<void, void> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<int, int>::value)
            {
                r->report("is_same_type<int, int> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<short, short>::value)
            {
                r->report("is_same_type<short, short> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<double, double>::value)
            {
                r->report("is_same_type<double, double> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<int*, int*>::value)
            {
                r->report("is_same_type<int*, int*> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<ist_Parent, ist_Parent>::value)
            {
                r->report("is_same_type<ist_Parent, ist_Parent> failed", __LINE__);
                bSuccess = false;
            }
            if(0 == is_same_type<ist_Child, ist_Child>::value)
            {
                r->report("is_same_type<ist_Child, ist_Child> failed", __LINE__);
                bSuccess = false;
            }

            // Different types
            if(0 != is_same_type<void, int>::value)
            {
                r->report("is_same_type<void, int> failed", __LINE__);
                bSuccess = false;
            }
            if(0 != is_same_type<int*, int>::value)
            {
                r->report("is_same_type<int*, int> failed", __LINE__);
                bSuccess = false;
            }
            if(0 != is_same_type<ist_Parent, ist_Child>::value)
            {
                r->report("is_same_type<ist_Parent, ist_Child> failed", __LINE__);
                bSuccess = false;
            }

#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
            STLSOFT_SUPPRESS_UNUSED(bSuccess);
#endif // STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_meta_is_same_type(test_stlsoft_meta_is_same_type);
    } // anonymous namespace

#endif /* compiler */

} // namespace unittest
