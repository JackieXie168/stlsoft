
// Updated: 5th October 2005

#if !defined(WINSTL_INCL_WINSTL_HPP_DROPHANDLE_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/drophandle_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_DROPHANDLE_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_drophandle_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "drophandle_sequence", __FILE__);

            HDROP                   hDrop       =   (0 == ::GetTickCount()) ? (HDROP)::GetTickCount() : NULL;

            if(NULL != hDrop)
            {
                typedef drophandle_sequence     dhs_t;

                dhs_t   dhs(hDrop, false);

                { for(dhs_t::const_iterator b = dhs.begin(), e = dhs.end(); b != e; ++b)
                {
                    if(b == e)
                    {
                        r->report("non-end() compares == to end()", __LINE__);
                        bSuccess = false;
                    }

                    if(b != e)
                    {}

                    dhs_t::value_type       v(*b);

                    dhs_t::const_iterator b2    =   b++;

                    if(e != b2)
                    {
                        dhs_t::const_iterator b3    =   b2--;

                        ++b2;

                        STLSOFT_SUPPRESS_UNUSED(b3); // GCC 3.2 whines
                    }

                    --b;
                }}

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORTx)
                { for(dhs_t::const_reverse_iterator b = dhs.rbegin(), e = dhs.rend(); b != e; ++b)
                {
                    b.base();
                }}
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_drophandle_sequence(test_winstl_drophandle_sequence);
    } // anonymous namespace

} // namespace unittest
