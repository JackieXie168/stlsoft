
// Updated: 6th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/truncation_test.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

#if !defined(STLSOFT_COMPILER_IS_BORLAND)	// Borland has an ICE with the amount of tests here.

namespace unittest
{
	namespace
	{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# define STLSOFT_CONV_TRUNCATION_TEST_CASE(fromType, toType, fromValue) stlsoft_ns_qual(truncation_test)<toType>(static_cast<fromType>(fromValue))
#else /* ? compiler */
# define STLSOFT_CONV_TRUNCATION_TEST_CASE(fromType, toType, fromValue) stlsoft_ns_qual(truncation_test)<toType, fromType>(static_cast<fromType>(fromValue))
#endif /* compiler */

		// To:		char
		//
		// From:
		//			char
		//
		//			unsigned char
		//			signed char
		//			unsigned long
		//			signed long

		ss_bool_t test_stlsoft_conversion_truncation_test_to_char(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			// char => char

			{ for(char i = CHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, char, i))
				{
					r->report("truncation_test<char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(CHAR_MAX == i)
				{
					break;
				}
			}}

			// unsigned char => char

			{ for(unsigned char i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, char, i))
				{
					r->report("truncation_test<char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(CHAR_MAX == i)
				{
					break;
				}
			}}
#ifdef STLSOFT_CF_CHAR_IS_UNSIGNED
			if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, char, UCHAR_MAX))
#else /* ? STLSOFT_CF_CHAR_IS_UNSIGNED */
			if(STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, char, UCHAR_MAX))
#endif /* STLSOFT_CF_CHAR_IS_UNSIGNED */
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// signed long => char

			{ for(signed long i = CHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, i))
				{
					r->report("truncation_test<char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(CHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, CHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, CHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// unsigned long => char

			{ for(unsigned long i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, char, i))
				{
					r->report("truncation_test<char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(CHAR_MAX == i)
				{
					break;
				}
			}}
			if(STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed char, CHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		// To:		signed char
		//
		// From:
		//			unsigned char
		//
		//			unsigned char
		//			signed short
		//			unsigned short
		//			signed int
		//			signed long
		//			signed long long

		ss_bool_t test_stlsoft_conversion_truncation_test_to_signed_char(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			// signed char => signed char

			{ for(signed char i = SCHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}

			// unsigned char => signed char

			{ for(unsigned char i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed char, SCHAR_MAX + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed char, UCHAR_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// signed short => signed char

			{ for(signed short i = SCHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed char, SCHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed char, SCHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed char, SHRT_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed char, SHRT_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// unsigned short => signed char

			{ for(unsigned short i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if(STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed char, SCHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}
			if(STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed char, SHRT_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// signed int => signed char

			{ for(signed int i = SCHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed char, SCHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed char, SCHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed char, INT_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed char, INT_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// signed long => signed char

			{ for(signed long i = SCHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, SCHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, SCHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, LONG_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, LONG_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			// signed ss_sint64_t => signed char

			{ for(ss_sint64_t i = SCHAR_MIN; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed char, i))
				{
					r->report("truncation_test<signed char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(SCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed char, SCHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed char, SCHAR_MAX + 1))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, LONG_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed char, LONG_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		// To:		unsigned char
		//
		// From:
		//			unsigned char
		//
		//			signed char
		//			unsigned long
		//			signed long

		ss_bool_t test_stlsoft_conversion_truncation_test_to_unsigned_char(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			// unsigned char => unsigned char

			{ for(unsigned char i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, unsigned char, i))
				{
					r->report("truncation_test<unsigned char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(UCHAR_MAX == i)
				{
					break;
				}
			}}

			// unsigned short => unsigned char

			{ for(unsigned short i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned char, i))
				{
					r->report("truncation_test<unsigned char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(UCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned char, 0 - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned char, UCHAR_MAX + 1))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned char, SHRT_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned char, SHRT_MAX))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}

			// unsigned int => unsigned char

			{ for(unsigned int i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned char, i))
				{
					r->report("truncation_test<unsigned char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(UCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned char, 0 - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned char, UCHAR_MAX + 1))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned char, INT_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned char, INT_MAX))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}

			// unsigned long => unsigned char

			{ for(unsigned long i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, i))
				{
					r->report("truncation_test<unsigned char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(UCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, 0 - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, UCHAR_MAX + 1))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, LONG_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, LONG_MAX))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}

			// ss_uint64_t => unsigned char

			{ for(ss_uint64_t i = 0; ; ++i)
			{
				if(!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned char, i))
				{
					r->report("truncation_test<unsigned char>() failed ", __LINE__);
					bSuccess = false;
				}

				if(UCHAR_MAX == i)
				{
					break;
				}
			}}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned char, 0 - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned char, UCHAR_MAX + 1))
			{
				r->report("truncation_test<unsigned char>() failed ", __LINE__);
				bSuccess = false;
			}
			if( STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, LONG_MIN) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned char, LONG_MAX))
			{
				r->report("truncation_test<signed char>() failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_signed_short(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_unsigned_int(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_signed_int(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_unsigned_short(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_signed_long(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_unsigned_long(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_signed_long_long(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_to_unsigned_long_long(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(bSuccess);
			STLSOFT_SUPPRESS_UNUSED(r);

			return bSuccess;
		}

		ss_bool_t test_stlsoft_conversion_truncation_test_121(unittest_reporter *r)
		{
			ss_bool_t		bSuccess	=	true;

			// => char (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, char, CHAR_MAX - 1) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, char, SCHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, char, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, char, CHAR_MAX - 1) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, char, SCHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, char, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, char, CHAR_MAX - 1) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, char, SCHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, char, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, char, CHAR_MAX - 1) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, SCHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, char, CHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, char, 0) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, char, SCHAR_MAX - 1) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, char, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, char, CHAR_MAX - 1) ||

				0)
			{
				r->report("truncation_test<char>() failed ", __LINE__);
				bSuccess = false;
			}

			// => char (failure)
			if(
				(	sizeof(char) < sizeof(short) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, char, CHAR_MIN - 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, char, CHAR_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, char, CHAR_MAX + 1))) ||
				(	sizeof(char) < sizeof(int) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, char, CHAR_MIN - 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, char, CHAR_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, char, CHAR_MAX + 1))) ||
				(	sizeof(char) < sizeof(long) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, CHAR_MIN - 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, char, CHAR_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, char, CHAR_MAX + 1))) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, char, CHAR_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, char, CHAR_MAX + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, char, CHAR_MAX + 1)
				)
			{
				r->report("truncation_test<char>() failed ", __LINE__);
				bSuccess = false;
			}



			// => signed short (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, signed short, 0) ||
				(	sizeof(char) < sizeof(short) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, signed short, CHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed short, SCHAR_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed short, SCHAR_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed short, 0) ||
				(	sizeof(char) < sizeof(short) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed short, UCHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed short, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed short, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed short, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed short, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed short, SHRT_MAX) ||

				0)
			{
				r->report("truncation_test<signed short>() failed ", __LINE__);
				bSuccess = false;
			}

			// => signed short (failure)
			if( 
				(	sizeof(short) < sizeof(int) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed short, SHRT_MIN - 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed short, SHRT_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed short, SHRT_MAX + 1))) ||

				(	sizeof(short) < sizeof(long) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed short, SHRT_MIN - 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed short, SHRT_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed short, SHRT_MAX + 1))) ||

				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed short, SHRT_MIN - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed short, SHRT_MAX + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed short, SHRT_MAX + 1) ||

				0)
			{
				r->report("truncation_test<signed short>() failed ", __LINE__);
				bSuccess = false;
			}



			// => unsigned short (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, unsigned short, 0) ||
				(	sizeof(char) < sizeof(short) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, unsigned short, CHAR_MAX)) ||

				(	sizeof(char) < sizeof(short) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, unsigned short, SCHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, unsigned short, UCHAR_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, unsigned short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, unsigned short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, unsigned short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, unsigned short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned short, SHRT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, unsigned short, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned short, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned short, SHRT_MAX) ||

				0)
			{
				r->report("truncation_test<unsigned short>() failed ", __LINE__);
				bSuccess = false;
			}

			// => unsigned short (failure)
			if( 
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, unsigned short, - 1) ||
				(	sizeof(short) < sizeof(int) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, unsigned short, USHRT_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, unsigned short, USHRT_MAX + 1))) ||

				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, unsigned short, - 1) ||
				(	sizeof(short) < sizeof(long) &&
					(	STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, unsigned short, USHRT_MAX + 1) ||
						STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, unsigned short, USHRT_MAX + 1))) ||

				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, unsigned short, - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, unsigned short, USHRT_MAX + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, unsigned short, USHRT_MAX + 1) ||

				0)
			{
				r->report("truncation_test<unsigned short>() failed ", __LINE__);
				bSuccess = false;
			}



			// => signed int (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, signed int, CHAR_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed int, SCHAR_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed int, SCHAR_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed int, 0) ||
				(	sizeof(char) < sizeof(int) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed int, UCHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed int, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed int, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed int, 0) ||
				(	sizeof(short) < sizeof(int) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed int, USHRT_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed int, INT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed int, INT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed int, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed int, INT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed int, INT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed int, INT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed int, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed int, INT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed int, INT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed int, INT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed int, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed int, INT_MAX) ||

				0)
			{
				r->report("truncation_test<signed int>() failed ", __LINE__);
				bSuccess = false;
			}

			// => signed int (failure)
			if( 
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed int, ss_sint64_t(INT_MIN) - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed int, ss_sint64_t(INT_MAX) + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed int, ss_uint64_t(INT_MAX) + 1) ||

				0)
			{
				r->report("truncation_test<signed int>() failed ", __LINE__);
				bSuccess = false;
			}




			// => signed long (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, signed long, CHAR_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed long, SCHAR_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, signed long, SCHAR_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed long, 0) ||
				(	sizeof(char) < sizeof(long) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, signed long, UCHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed long, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, signed long, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed long, 0) ||
				(	sizeof(short) < sizeof(long) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, signed long, USHRT_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed long, INT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, signed long, INT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed long, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, signed long, INT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed long, LONG_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, signed long, LONG_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed long, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, signed long, LONG_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed long, LONG_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed long, LONG_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed long, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed long, LONG_MAX) ||

				0)
			{
				r->report("truncation_test<signed long>() failed ", __LINE__);
				bSuccess = false;
			}

			// => signed long (failure)
			if( 
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed long, ss_sint64_t(LONG_MIN) - 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, signed long, ss_sint64_t(LONG_MAX) + 1) ||
				STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, signed long, ss_uint64_t(LONG_MAX) + 1) ||

				0)
			{
				r->report("truncation_test<signed long>() failed ", __LINE__);
				bSuccess = false;
			}



			// => unsigned long
			if( 
				STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, unsigned long, - 1) ||

				0)
			{
				r->report("truncation_test<unsigned long>() failed ", __LINE__);
				bSuccess = false;
			}



			// => signed long long (success)
			if( 
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(char, ss_sint64_t, CHAR_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, ss_sint64_t, SCHAR_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed char, ss_sint64_t, SCHAR_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, ss_sint64_t, 0) ||
				(	sizeof(char) < sizeof(long) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned char, ss_sint64_t, UCHAR_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, ss_sint64_t, SHRT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed short, ss_sint64_t, SHRT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, ss_sint64_t, 0) ||
				(	sizeof(short) < sizeof(long) &&
					!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned short, ss_sint64_t, USHRT_MAX)) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, ss_sint64_t, INT_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed int, ss_sint64_t, INT_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, ss_sint64_t, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned int, ss_sint64_t, INT_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, ss_sint64_t, LONG_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(signed long, ss_sint64_t, LONG_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, ss_sint64_t, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(unsigned long, ss_sint64_t, LONG_MAX) ||

				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, ss_sint64_t, STLSOFT_LIMIT_TRAITS__SINT64_MIN) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_sint64_t, ss_sint64_t, STLSOFT_LIMIT_TRAITS__SINT64_MAX) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, ss_sint64_t, 0) ||
				!STLSOFT_CONV_TRUNCATION_TEST_CASE(ss_uint64_t, ss_sint64_t, STLSOFT_LIMIT_TRAITS__SINT64_MAX) ||

				0)
			{
				r->report("truncation_test<signed long long>() failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}


		ss_bool_t test_stlsoft_conversion_truncation_test(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/truncation_test", __FILE__);

			if(!test_stlsoft_conversion_truncation_test_to_char(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_signed_char(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_unsigned_char(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_signed_short(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_unsigned_int(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_signed_int(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_unsigned_short(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_signed_long(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_unsigned_long(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_signed_long_long(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_to_unsigned_long_long(r))
			{
				bSuccess = false;
			}
			if(!test_stlsoft_conversion_truncation_test_121(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_truncation_test(test_stlsoft_conversion_truncation_test);
	} // anonymous namespace

} // namespace unittest

#endif /* compiler */
