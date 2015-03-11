
// Updated: 29th December 2007

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_PRINTF_TRAITS)
# error This file cannot be directly included, and should only be included within stlsoft/util/printf_traits.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_PRINTF_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
#if 0
#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
	(	defined(STLSOFT_COMPILER_IS_COMO) && \
		defined(_MSC_VER)) || \
	defined(STLSOFT_COMPILER_IS_GCC) || \
	defined(STLSOFT_COMPILER_IS_INTEL) || \
	defined(STLSOFT_COMPILER_IS_MSVC)
		int swprintf(wchar_t *sz, size_t cch, wchar_t const* fmt, ...)
		{
			va_list args;
			int 	iRet;
			va_start(args, fmt);

# if (	 defined(STLSOFT_COMPILER_IS_MSVC) || \
		 (	 defined(STLSOFT_COMPILER_IS_INTEL) && \
			 defined(WIN32))) && \
	  _MSC_VER == 1310
			iRet	=	vswprintf(sz, cch, fmt, args);
# elif (   defined(STLSOFT_COMPILER_IS_MSVC) || \
		   (   defined(STLSOFT_COMPILER_IS_INTEL) && \
			   defined(WIN32))) && \
		_MSC_VER >= 1400
			iRet	=	swprintf_p(::_vswprintf_c, sz, cch, fmt, args);

			sz[iRet] = '\0';
# else /* ? compiler */
			iRet	=	swprintf_p(::vswprintf, sz, cch, fmt, args);
# endif /* compiler */

			va_end(args);

			return iRet;
		}
#endif /* compiler */
#else /* ? 0 */

#endif /* 0 */

		ss_bool_t test_stlsoft_printf_traits(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/printf_traits", __FILE__);

			char				sz[21];
			wchar_t 			szw[21];
			int 				cch;
			static const char	*signed_minimums[] =
			{
				/* 0 */ 		""
				/* 1 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT8_MIN)
				/* 2 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT16_MIN)
				/* 3 */ 	,	""
				/* 4 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT32_MIN)
				/* 5 */ 	,	""
				/* 6 */ 	,	""
				/* 7 */ 	,	""
				/* 4 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT64_MIN)
			};
			static const char	*unsigned_minimums[] =
			{
				/* 0 */ 		""
				/* 1 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT8_MIN)
				/* 2 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT16_MIN)
				/* 3 */ 	,	""
				/* 4 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT32_MIN)
				/* 5 */ 	,	""
				/* 6 */ 	,	""
				/* 7 */ 	,	""
				/* 4 */ 	,	STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT64_MIN)
			};

			// (i) min (with char)

			// 8-bit signed
			cch = sprintf(sz, printf_traits<ss_sint8_t>::format_a(), limit_traits<ss_sint8_t>::minimum());
			if(printf_traits<ss_sint8_t>::size_min != 1 + cch)
			{
				r->report("traits (8-bit, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT8_MIN)))
			{
				r->report("traits (8-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 8-bit unsigned
			cch = sprintf(sz, printf_traits<ss_uint8_t>::format_a(), limit_traits<ss_uint8_t>::minimum());
			if(printf_traits<ss_uint8_t>::size_min != 1 + cch)
			{
				r->report("traits (8-bit, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT8_MIN)))
			{
				r->report("traits (8-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// short
			cch = sprintf(sz, printf_traits<short>::format_a(), limit_traits<short>::minimum());
			if(printf_traits<short>::size_min != 1 + cch)
			{
				r->report("traits (short, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, signed_minimums[sizeof(short)]))
			{
				r->report("traits (short, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// unsigned short
			cch = sprintf(sz, printf_traits<unsigned short>::format_a(), limit_traits<unsigned short>::minimum());
			if(printf_traits<unsigned short>::size_min != 1 + cch)
			{
				r->report("traits (short, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, unsigned_minimums[sizeof(unsigned short)]))
			{
				r->report("traits (short, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// 16-bit signed
			cch = sprintf(sz, printf_traits<ss_sint16_t>::format_a(), limit_traits<ss_sint16_t>::minimum());
			if(printf_traits<ss_sint16_t>::size_min != 1 + cch)
			{
				r->report("traits (16-bit, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT16_MIN)))
			{
				r->report("traits (16-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 16-bit unsigned
			cch = sprintf(sz, printf_traits<ss_uint16_t>::format_a(), limit_traits<ss_uint16_t>::minimum());
			if(printf_traits<ss_uint16_t>::size_min != 1 + cch)
			{
				r->report("traits (16-bit, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT16_MIN)))
			{
				r->report("traits (16-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// int
			cch = sprintf(sz, printf_traits<int>::format_a(), limit_traits<int>::minimum());
			if(printf_traits<int>::size_min != 1 + cch)
			{
				r->report("traits (int, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, signed_minimums[sizeof(int)]))
			{
				r->report("traits (int, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// unsigned int
			cch = sprintf(sz, printf_traits<unsigned int>::format_a(), limit_traits<unsigned int>::minimum());
			if(printf_traits<unsigned int>::size_min != 1 + cch)
			{
				r->report("traits (int, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, unsigned_minimums[sizeof(unsigned int)]))
			{
				r->report("traits (int, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// 32-bit signed
			cch = sprintf(sz, printf_traits<ss_sint32_t>::format_a(), limit_traits<ss_sint32_t>::minimum());
			if(printf_traits<ss_sint32_t>::size_min != 1 + cch)
			{
				r->report("traits (32-bit, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT32_MIN)))
			{
				r->report("traits (32-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 32-bit unsigned
			cch = sprintf(sz, printf_traits<ss_uint32_t>::format_a(), limit_traits<ss_uint32_t>::minimum());
			if(printf_traits<ss_uint32_t>::size_min != 1 + cch)
			{
				r->report("traits (32-bit, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT32_MIN)))
			{
				r->report("traits (32-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			// 64-bit signed
			cch = sprintf(sz, printf_traits<ss_sint64_t>::format_a(), limit_traits<ss_sint64_t>::minimum());
			if(printf_traits<ss_sint64_t>::size_min != 1 + cch)
			{
				r->report("traits (64-bit, signed) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_SINT64_MIN)))
			{
				r->report("traits (64-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 64-bit unsigned
			cch = sprintf(sz, printf_traits<ss_uint64_t>::format_a(), limit_traits<ss_uint64_t>::minimum());
			if(printf_traits<ss_uint64_t>::size_min != 1 + cch)
			{
				r->report("traits (64-bit, unsigned) min invalid", __LINE__);
				bSuccess = false;
			}
			if(0 != strcmp(sz, STLSOFT_STRINGIZE(STLSOFT_PRINTF_TRAITS_UINT64_MIN)))
			{
				r->report("traits (64-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			// (ii) max (with char)

			// 8-bit signed
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_sint8_t>::format_w(), limit_traits<ss_sint8_t>::maximum());
			if(printf_traits<ss_sint8_t>::size_max != 1 + cch)
			{
				r->report("traits (8-bit, signed) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t sint8_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_SINT8_MAX);
			if(0 != wcscmp(szw, sint8_t_max))
			{
				r->report("traits (8-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 8-bit unsigned
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_uint8_t>::format_w(), limit_traits<ss_uint8_t>::maximum());
			if(printf_traits<ss_uint8_t>::size_max != 1 + cch)
			{
				r->report("traits (8-bit, unsigned) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t uint8_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_UINT8_MAX);
			if(0 != wcscmp(szw, uint8_t_max))
			{
				r->report("traits (8-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// 16-bit signed
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_sint16_t>::format_w(), limit_traits<ss_sint16_t>::maximum());
			if(printf_traits<ss_sint16_t>::size_max != 1 + cch)
			{
				r->report("traits (16-bit, signed) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t sint16_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_SINT16_MAX);
			if(0 != wcscmp(szw, sint16_t_max))
			{
				r->report("traits (16-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 16-bit unsigned
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_uint16_t>::format_w(), limit_traits<ss_uint16_t>::maximum());
			if(printf_traits<ss_uint16_t>::size_max != 1 + cch)
			{
				r->report("traits (16-bit, unsigned) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t uint16_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_UINT16_MAX);
			if(0 != wcscmp(szw, uint16_t_max))
			{
				r->report("traits (16-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

			// 32-bit signed
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_sint32_t>::format_w(), limit_traits<ss_sint32_t>::maximum());
			if(printf_traits<ss_sint32_t>::size_max != 1 + cch)
			{
				r->report("traits (32-bit, signed) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t sint32_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_SINT32_MAX);
			if(0 != wcscmp(szw, sint32_t_max))
			{
				r->report("traits (32-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 32-bit unsigned
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_uint32_t>::format_w(), limit_traits<ss_uint32_t>::maximum());
			if(printf_traits<ss_uint32_t>::size_max != 1 + cch)
			{
				r->report("traits (32-bit, unsigned) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t uint32_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_UINT32_MAX);
			if(0 != wcscmp(szw, uint32_t_max))
			{
				r->report("traits (32-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			// 64-bit signed
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_sint64_t>::format_w(), limit_traits<ss_sint64_t>::maximum());
			if(printf_traits<ss_sint64_t>::size_max != 1 + cch)
			{
				r->report("traits (64-bit, signed) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t sint64_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_SINT64_MAX);
			if(0 != wcscmp(szw, sint64_t_max))
			{
				r->report("traits (64-bit, signed) format invalid", __LINE__);
				bSuccess = false;
			}

			// 64-bit unsigned
			cch = swprintf(szw, STLSOFT_NUM_ELEMENTS(szw), printf_traits<ss_uint64_t>::format_w(), limit_traits<ss_uint64_t>::maximum());
			STLSOFT_ASSERT('\0' == szw[cch]);
			if(printf_traits<ss_uint64_t>::size_max != 1 + cch)
			{
				r->report("traits (64-bit, unsigned) max invalid", __LINE__);
				bSuccess = false;
			}
			wchar_t uint64_t_max[] = STLSOFT_STRINGIZE_w(STLSOFT_PRINTF_TRAITS_UINT64_MAX);
			if(0 != wcscmp(szw, uint64_t_max))
			{
				r->report("traits (64-bit, unsigned) format invalid", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_printf_traits(test_stlsoft_printf_traits);
	} // anonymous namespace

} // namespace unittest
