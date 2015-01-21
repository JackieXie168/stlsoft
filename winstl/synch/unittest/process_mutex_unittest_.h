
#if !defined(WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX)
# error This file cannot be directly included, and should only be included within winstl/synch/process_mutex.hpp
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_synch_process_mutex(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "synch/process_mutex", __FILE__);

            process_mutex   mx_r(true);

            mx_r.lock();
            if(!mx_r.try_lock())
            {
                r->report("process_mutex could not lock recursively ", __LINE__);
                bSuccess = false;
            }
            else
            {
                mx_r.unlock();
            }
            mx_r.unlock();

            process_mutex   mx_named("STLSoft.WinSTL.process_mutex");

            mx_named.lock();
            if(!mx_named.try_lock())
            {
                r->report("process_mutex could not lock recursively ", __LINE__);
                mx_named.unlock();
                bSuccess = false;
            }
            mx_named.unlock();

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_synch_process_mutex(test_winstl_synch_process_mutex);
    } // anonymous namespace

} // namespace unittest

