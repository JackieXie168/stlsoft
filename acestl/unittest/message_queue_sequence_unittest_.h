
#if !defined(ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE)
# error This file cannot be directly included, and should only be included within acestl/message_queue_sequence.hpp
#endif /* !ACESTL_INCL_ACESTL_HPP_MESSAGE_QUEUE_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_acestl_message_queue_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "ACESTL", "message_queue_sequence", __FILE__);

            typedef ACE_DEFAULT_MESSAGE_QUEUE_TYPE      mq_t;
            typedef message_queue_sequence<ACE_SYNCH>   mqs_t;

            mq_t    mq;
            mqs_t   mqs(mq);

            {
                mqs_t::iterator  b   =   mqs.begin();
                mqs_t::iterator  b2;

                b2  =   b2;
                b   =   b;
                b2  =   b;
                b2  =   mqs.begin();
            }
            {
                mqs_t::iterator  b   =   mqs.begin();
                mqs_t::iterator  e   =   mqs.end();

                for(; b != e; ++b)
                {}
            }

            ACE_Message_Block   *block1 =   make_copied_Message_Block("some contents.", 14);
            ACE_Message_Block   *block2 =   make_copied_Message_Block("some more contents.", 19);

            mq.enqueue(block1);
            mq.enqueue(block2);

            {
                mqs_t::iterator  b   =   mqs.begin();
                mqs_t::iterator  b2;

                b2  =   b2;
                b   =   b;
                b2  =   b;
                b2  =   mqs.begin();
            }
            {
                mqs_t::iterator  b   =   mqs.begin();
                mqs_t::iterator  e   =   mqs.end();

                for(; b != e; ++b)
                {}
            }

#if 0
            typedef message_queue_sequence<char>    env_var_t;

            {
                r->report("message_queue_sequence<char> failed ", __LINE__);
                bSuccess = false;
            }
#endif /* 0 */

            return bSuccess;
        }

        unittest_registrar    unittest_acestl_message_queue_sequence(test_acestl_message_queue_sequence);
    } // anonymous namespace

} // namespace unittest
