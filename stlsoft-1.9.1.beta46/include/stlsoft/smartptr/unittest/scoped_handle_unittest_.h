
// Updated: 9th March 2007

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
		void STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl_void_indirect(short *p)
		{
			*p = 0;
		}
		bool STLSOFT_CDECL test_stlsoft_scoped_handle__close_short_cdecl_indirect(short *p)
		{
			*p = 0;

			return true;
		}

#ifdef STLSOFT_CF_FASTCALL_SUPPORTED
		void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_void(long )
		{}
		bool STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall(long )
		{
			return true;
		}
		void STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_void_indirect(long *p)
		{
			*p = 0;
		}
		bool STLSOFT_FASTCALL test_stlsoft_scoped_handle__close_long_fastcall_indirect(long *p)
		{
			*p = 0;

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
		void STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall_void_indirect(unsigned *p)
		{
			*p = 0;
		}
		bool STLSOFT_STDCALL test_stlsoft_scoped_handle__close_unsigned_stdcall_indirect(unsigned *p)
		{
			*p = 0;

			return true;
		}
#endif /* STLSOFT_CF_STDCALL_SUPPORTED */

		ss_bool_t test_stlsoft_scoped_handle_short(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

#if !defined(STLSOFT_COMPILER_IS_BORLAND)
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
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1200
				scoped_handle<short>	sh1(12, (void (STLSOFT_CDECL *)(short ))test_stlsoft_scoped_handle__close_short_cdecl);
#else /* ? compiler */
				scoped_handle<short>	sh1(12, test_stlsoft_scoped_handle__close_short_cdecl);
#endif /* compiler */

				if(12 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// cdecl indirect
			{
				short						v	=	13;

				{
					scoped_handle<short>	sh1(&v, test_stlsoft_scoped_handle__close_short_cdecl_void_indirect);

					if(13 != stlsoft_ns_qual(get_handle)(sh1))
					{
						r->report("scoped_handle<short> get_handle() failed", __LINE__);
						bSuccess = false;
					}
				}

				if(0 != v)
				{
					r->report("scoped_handle<short> did not reset to 'null' value", __LINE__);
					bSuccess = false;
				}
			}

			{
				short					v	=	14;
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1200
				scoped_handle<short>	sh1(&v, (void (STLSOFT_CDECL *)(short *))test_stlsoft_scoped_handle__close_short_cdecl_indirect);
#else /* ? compiler */
				scoped_handle<short>	sh1(&v, test_stlsoft_scoped_handle__close_short_cdecl_indirect);
#endif /* compiler */

				if(14 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<short> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}
#else /* ? compiler */
			STLSOFT_SUPPRESS_UNUSED(r);
			STLSOFT_SUPPRESS_UNUSED(bSuccess);
#endif /* compiler */

			return bSuccess;
		}

		ss_bool_t test_stlsoft_scoped_handle_long(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
			// fastcall
			{
				scoped_handle<long> 	sh1(21, test_stlsoft_scoped_handle__close_long_fastcall_void);

				if(21 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<long> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
#  if defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER < 1200
				scoped_handle<long> 	sh1(22, (void (STLSOFT_FASTCALL *)(long ))test_stlsoft_scoped_handle__close_long_fastcall);
#  else /* ? compiler */
				scoped_handle<long> 	sh1(22, test_stlsoft_scoped_handle__close_long_fastcall);
#  endif /* compiler */

				if(22 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<long> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// fastcall indirect
			{
				long					v	=	23;
				scoped_handle<long> 	sh1(&v, test_stlsoft_scoped_handle__close_long_fastcall_void_indirect);

				if(23 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<long> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				long					v	=	24;
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1200
				scoped_handle<long> 	sh1(&v, (void (STLSOFT_FASTCALL *)(long *))test_stlsoft_scoped_handle__close_long_fastcall_indirect);
#else /* ? compiler */
				scoped_handle<long> 	sh1(&v, test_stlsoft_scoped_handle__close_long_fastcall_indirect);
#endif /* compiler */

				if(24 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<long> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}
# else /* ? STLSOFT_CF_FASTCALL_SUPPORTED */
			STLSOFT_SUPPRESS_UNUSED(r);
			STLSOFT_SUPPRESS_UNUSED(bSuccess);
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */

#else /* ? compiler */
			STLSOFT_SUPPRESS_UNUSED(r);
			STLSOFT_SUPPRESS_UNUSED(bSuccess);
#endif /* compiler */

			return bSuccess;
		}

		ss_bool_t test_stlsoft_scoped_handle_unsigned(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

# ifdef STLSOFT_CF_STDCALL_SUPPORTED
			// stdcall
			{
				scoped_handle<unsigned> sh1(31, test_stlsoft_scoped_handle__close_unsigned_stdcall_void);

				if(31 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<unsigned> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1200
				scoped_handle<unsigned> sh1(32, (void (STLSOFT_STDCALL *)(unsigned ))test_stlsoft_scoped_handle__close_unsigned_stdcall);
#else /* ? compiler */
				scoped_handle<unsigned> sh1(32, test_stlsoft_scoped_handle__close_unsigned_stdcall);
#endif /* compiler */

				if(32 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<unsigned> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			// stdcall indirect
			{
				unsigned				v	=	33;
				scoped_handle<unsigned> sh1(&v, test_stlsoft_scoped_handle__close_unsigned_stdcall_void_indirect);

				if(33 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<unsigned> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				unsigned				v	=	34;
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1200
				scoped_handle<unsigned> sh1(&v, (void (STLSOFT_STDCALL *)(unsigned *))test_stlsoft_scoped_handle__close_unsigned_stdcall_indirect);
#else /* ? compiler */
				scoped_handle<unsigned> sh1(&v, test_stlsoft_scoped_handle__close_unsigned_stdcall_indirect);
#endif /* compiler */

				if(34 != stlsoft_ns_qual(get_handle)(sh1))
				{
					r->report("scoped_handle<unsigned> get_handle() failed", __LINE__);
					bSuccess = false;
				}
			}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#else /* ? compiler */
			STLSOFT_SUPPRESS_UNUSED(r);
			STLSOFT_SUPPRESS_UNUSED(bSuccess);
#endif /* compiler */

			return bSuccess;
		}

		ss_bool_t test_stlsoft_scoped_handle(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "smartptr/scoped_handle", __FILE__);

			if(!test_stlsoft_scoped_handle_short(r))
			{
				bSuccess = false;
			}

			if(!test_stlsoft_scoped_handle_long(r))
			{
				bSuccess = false;
			}

			if(!test_stlsoft_scoped_handle_unsigned(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_scoped_handle(test_stlsoft_scoped_handle);
	} // anonymous namespace

} // namespace unittest


////////////////////////////////////////////////////////////////////////////
