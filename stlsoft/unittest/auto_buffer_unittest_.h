
#if !defined(STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER)
# error This file cannot be directly included, and should only be included within stlsoft/auto_buffer.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_AUTO_BUFFER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_auto_buffer(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "auto_buffer", __FILE__);

            typedef auto_buffer<int
                            ,   allocator_selector<int>::allocator_type
                            ,   16
                            >       buffer_t;

            buffer_t    buffer1(10);
            buffer_t    buffer2(100);

            /* Check that resizing within the internal_size() does not
             * change the pointer.
             */
            int *pi = buffer1.data();

            for(ss_size_t c = 1; bSuccess && c < buffer1.internal_size(); ++c)
            {
                buffer1.resize(c);

                if(pi != buffer1.data())
                {
                    r->report("auto_buffer resize not allocated from internal buffer: failed", __LINE__);
                    bSuccess = false;
                }
            }

#if defined(__STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
            /* Check that forward and backward iteration provide the same result. */
            int total_forward   =   stlsoft_ns_qual_std(accumulate)(buffer2.begin(), buffer2.end(), 0);
            int total_backward  =   stlsoft_ns_qual_std(accumulate)(buffer2.rbegin(), buffer2.rend(), 0);

            if(total_forward != total_backward)
            {
                r->report("Forward and backward enumeration equivalence failed", __LINE__);
                bSuccess = false;
            }
#endif /* __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_auto_buffer(test_stlsoft_auto_buffer);
    } // anonymous namespace

} // namespace unittest
