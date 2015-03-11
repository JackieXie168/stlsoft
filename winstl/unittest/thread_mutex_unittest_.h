
#if !defined(WINSTL_INCL_WINSTL_HPP_THREAD_MUTEX)
# error This file cannot be directly included, and should only be included within winstl/thread_mutex.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_THREAD_MUTEX */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_thread_mutex(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "thread_mutex", __FILE__);

            thread_mutex   mx_r;

            mx_r.lock();
    #if defined(__WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT)
            if(!mx_r.try_lock())
            {
                r->report("process_mutex (recursive) could not lock recursively ", __LINE__);
                bSuccess = false;
            }
            else
            {
                mx_r.unlock();
            }
    #endif /* __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT */
            mx_r.unlock();

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_thread_mutex(test_winstl_thread_mutex);
    } // anonymous namespace

} // namespace unittest

