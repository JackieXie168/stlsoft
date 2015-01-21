
// Updated: 25th May 2006

#if !defined(STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE)
# error This file cannot be directly included, and should only be included within stlsoft/scoped_handle.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_SCOPED_HANDLE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        void STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl(short )
        {}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
        void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall(long )
        {}
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
        void STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall(unsigned )
        {}
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

        ss_bool_t test_stlsoft_scoped_handle(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "scoped_handle", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_DMC)
            // cdecl
            {
                scoped_handle<short>    sh1(23, test_stlsoft_scoped_handle__close_short_cdecl);

                if(23 != stlsoft_ns_qual(get_handle)(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
            // fastcall
            {
                scoped_handle<long>    sh1(24, test_stlsoft_scoped_handle__close_long_fastcall);

                if(24 != stlsoft_ns_qual(get_handle)(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
            // stdcall
            {
                scoped_handle<unsigned>    sh1(25, test_stlsoft_scoped_handle__close_unsigned_stdcall);

                if(25 != stlsoft_ns_qual(get_handle)(sh1))
                {
                    r->report("scoped_handle<short> get_handle() failed", __LINE__);
                    bSuccess = false;
                }
            }
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* compiler */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_scoped_handle(test_stlsoft_scoped_handle);
    } // anonymous namespace

} // namespace unittest


////////////////////////////////////////////////////////////////////////////
