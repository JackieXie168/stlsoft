
// Updated: 27th December 2006

#if !defined(STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE)
# error This file cannot be directly included, and should only be included within stlsoft/smartptr/scoped_handle.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		void STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl_void(short )
		{}
		bool STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl(short )
		{
			return true;
		}
		void STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl_void_indirect(short *)
		{}
		bool STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl_indirect(short *)
		{
			return true;
		}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
		void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_void(long )
		{}
		bool STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall(long )
		{
			return true;
		}
		void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_void_indirect(long *)
		{}
		bool STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_indirect(long *)
		{
			return true;
		}
#endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#ifdef STLSOFT_CF_STDCALL_SUPPORTED
		void STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall_void(unsigned )
		{}
		bool STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall(unsigned )
		{
			return true;
		}
		void STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall_void_indirect(unsigned *)
		{}
		bool STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall_indirect(unsigned *)
		{
			return true;
		}
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

		ss_bool_t test_stlsoft_scoped_handle(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "smartptr/scoped_handle", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_DMC)
			// cdecl
			{
				scoped_handle<short>	sh1(11, test_stlsoft_scoped_handle__close_short_cdecl_void);

				if(11 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<short>	sh1(12, test_stlsoft_scoped_handle__close_short_cdecl);

				if(12 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// cdecl indirect
			{
				scoped_handle<short>	sh1(13, test_stlsoft_scoped_handle__close_short_cdecl_void_indirect);

				if(13 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<short>	sh1(14, test_stlsoft_scoped_handle__close_short_cdecl_indirect);

				if(14 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
			// fastcall
			{
				scoped_handle<long>    sh1(21, test_stlsoft_scoped_handle__close_long_fastcall_void);

				if(21 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<long>    sh1(22, test_stlsoft_scoped_handle__close_long_fastcall);

				if(22 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// fastcall indirect
			{
				scoped_handle<long>    sh1(23, test_stlsoft_scoped_handle__close_long_fastcall_void_indirect);

				if(23 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<long>    sh1(24, test_stlsoft_scoped_handle__close_long_fastcall_indirect);

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
				scoped_handle<unsigned>    sh1(31, test_stlsoft_scoped_handle__close_unsigned_stdcall_void);

				if(31 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<unsigned>    sh1(32, test_stlsoft_scoped_handle__close_unsigned_stdcall);

				if(32 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// stdcall indirect
			{
				scoped_handle<unsigned>    sh1(33, test_stlsoft_scoped_handle__close_unsigned_stdcall_void_indirect);

				if(33 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				scoped_handle<unsigned>    sh1(34, test_stlsoft_scoped_handle__close_unsigned_stdcall_indirect);

				if(34 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* compiler */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_scoped_handle(test_stlsoft_scoped_handle);
	} // anonymous namespace

} // namespace unittest


////////////////////////////////////////////////////////////////////////////
