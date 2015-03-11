
// Updated: 6th January 2007

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT)
# error This file cannot be directly included, and should only be included within stlsoft/util/must_init.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_util_must_init(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/must_init", __FILE__);

			{	// bool

				bool_init_t 	b1(false);

				if(false != b1.get())
				{
					r->report("must_init<bool> instance has wrong value", __LINE__);
					bSuccess = false;
				}

				bool_init_t 	b2(true);

				if(true != b2.get())
				{
					r->report("must_init<bool> instance has wrong value", __LINE__);
					bSuccess = false;
				}
			}

#ifndef CHAR_MIN
# define STLSOFT_DEFINING_CHAR_MIN
# ifdef STLSOFT_CF_CHAR_IS_UNSIGNED
#  define CHAR_MIN					(0)
# else /* ? STLSOFT_CF_CHAR_IS_UNSIGNED */
#  define CHAR_MIN					UCHAR_MIN
# endif /* STLSOFT_CF_CHAR_IS_UNSIGNED */
#endif /* STLSOFT_DEFINING_CHAR_MAX */

#ifndef CHAR_MAX
# define STLSOFT_DEFINING_CHAR_MAX
# ifdef STLSOFT_CF_CHAR_IS_UNSIGNED
#  define CHAR_MAX					(0)
# else /* ? STLSOFT_CF_CHAR_IS_UNSIGNED */
#  define CHAR_MAX					UCHAR_MAX
# endif /* STLSOFT_CF_CHAR_IS_UNSIGNED */
#endif /* STLSOFT_DEFINING_CHAR_MAX */

			{	// char

				{ for(char i = CHAR_MIN; ; ++i)
				{
					char_init_t 	ch(i);

					if(ch.get() != i)
					{
						r->report("must_init<char> instance has wrong value", __LINE__);
						bSuccess = false;
					}

					if(CHAR_MAX == i)
					{
						break;
					}
				}}

			}

#ifdef STLSOFT_DEFINING_CHAR_MIN
# undef CHAR_MIN
# undef STLSOFT_DEFINING_CHAR_MIN
#endif /* STLSOFT_DEFINING_CHAR_MIN */

#ifdef STLSOFT_DEFINING_CHAR_MAX
# undef CHAR_MAX
# undef STLSOFT_DEFINING_CHAR_MAX
#endif /* STLSOFT_DEFINING_CHAR_MAX */

			{	// wchar_t


			}

			{	// signed char

				{ for(signed char i = SCHAR_MIN; ; ++i)
				{
					signed_char_init_t	ch(i);

					if(ch.get() != i)
					{
						r->report("must_init<signed char> instance has wrong value", __LINE__);
						bSuccess = false;
					}

					if(SCHAR_MAX == i)
					{
						break;
					}
				}}

			}

			{	// unsigned char

				{ for(unsigned char i = 0; ; ++i)
				{
					unsigned_char_init_t	ch(i);

					if(ch.get() != i)
					{
						r->report("must_init<unsigned char> instance has wrong value", __LINE__);
						bSuccess = false;
					}

					if(UCHAR_MAX == i)
					{
						break;
					}
				}}

			}

			{	// short

				{ for(short i = SHRT_MIN; ; ++i)
				{
					short_init_t	ch(i);

					if(ch.get() != i)
					{
						r->report("must_init<short> instance has wrong value", __LINE__);
						bSuccess = false;
					}

					if(SHRT_MAX == i)
					{
						break;
					}
				}}

			}

			{	// unsigned short

				{ for(unsigned short i = 0; ; ++i)
				{
					unsigned_short_init_t	ch(i);

					if(ch.get() != i)
					{
						r->report("must_init<unsigned short> instance has wrong value", __LINE__);
						bSuccess = false;
					}

					if(USHRT_MAX == i)
					{
						break;
					}
				}}

			}

#if 0
typedef must_init<int>					int_init_t;

typedef must_init<unsigned int> 		unsigned_int_init_t;

typedef must_init<long> 				long_init_t;

typedef must_init<unsigned long>		unsigned_long_init_t;

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

typedef must_init<ss_sint64_t>			sint64_init_t;

typedef must_init<ss_uint64_t>			uint64_init_t;

#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

typedef must_init<float>				float_init_t;

typedef must_init<double>				double_init_t;

typedef must_init<long double>			long_double_init_t;

			;
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_util_must_init(test_stlsoft_util_must_init);
	} // anonymous namespace

} // namespace unittest
