
#if !defined(ACESTL_INCL_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS)
# error This file cannot be directly included, and should only be included within acestl/message_block_functions.hpp
#endif /* !ACESTL_INCL_ACESTL_HPP_MESSAGE_BLOCK_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_acestl_message_block_functions(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "ACESTL", "message_block_functions", __FILE__);

            const char              data[]      =   "abcdefghijklmnopqrstuvwxyz0123456789";

            ACE_Message_Block       *bl1        =   make_copied_Message_Block(&data[0], STLSOFT_NUM_ELEMENTS(data) - 1);
#if defined(STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
            ACE_Message_Block       *bl2        =   make_copied_Message_Block(data);
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            if(NULL != bl1)
            {
                if(bl1->wr_ptr() - bl1->rd_ptr() != STLSOFT_NUM_ELEMENTS(data) - 1)
                {
                    r->report("ACE_Message_Block has invalid size", __LINE__);
                    bSuccess = false;
                }

                if(0 != memcmp(bl1->rd_ptr(), &data[0], STLSOFT_NUM_ELEMENTS(data) - 1))
                {
                    r->report("ACE_Message_Block has invalid contents", __LINE__);
                    bSuccess = false;
                }
            }

#if defined(STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)
            if(NULL != bl2)
            {
                if(bl2->wr_ptr() - bl2->rd_ptr() != STLSOFT_NUM_ELEMENTS(data))
                {
                    r->report("ACE_Message_Block has invalid size", __LINE__);
                    bSuccess = false;
                }

                if(0 != memcmp(bl2->rd_ptr(), &data[0], STLSOFT_NUM_ELEMENTS(data)))
                {
                    r->report("ACE_Message_Block has invalid contents", __LINE__);
                    bSuccess = false;
                }
            }
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            return bSuccess;
        }

        unittest_registrar    unittest_acestl_message_block_functions(test_acestl_message_block_functions);
    } // anonymous namespace

} // namespace unittest
