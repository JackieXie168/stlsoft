
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_fundamental_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_fundamental_type__test_enum
		{};

		class is_fundamental_type__test_class
		{
		public:
			void method1();
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(T, R) 						\
																		\
		STLSOFT_STATIC_ASSERT(R == is_fundamental_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(T, R) 						\
																		\
		if(R != is_fundamental_type<T>::value)							\
		{																\
			r->report("is_fundamental_type<" #T "> error", __LINE__);	\
			bSuccess = false;											\
		}

#endif /* compiler */




		ss_bool_t test_stlsoft_meta_is_fundamental_type_test_fundamental(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			// Expected true

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(signed char, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(unsigned char, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(short, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(unsigned short, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(int, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(unsigned int, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(long, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(unsigned long, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(sint8_t, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(uint8_t, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(sint16_t, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(uint16_t, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(sint32_t, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(uint32_t, 1)

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(sint64_t, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(uint64_t, 1)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(float, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(double, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(long double, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(bool, 1)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(char, 1)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(wchar_t, 1)

			// Expected false

			typedef int 	(&ar_t)[10];
			typedef void	(*pfn_t)();
			typedef void	(is_fundamental_type__test_class::*mpfn_t)();

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(ar_t, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(pfn_t, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(void*, 0)
			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(int*, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(int&, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(is_fundamental_type__test_class, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(is_fundamental_type__test_enum, 0)

			STLSOFT_TEST_IS_FUNDAMENTAL_TYPE(mpfn_t, 0)

			return bSuccess;
		}

		ss_bool_t test_stlsoft_meta_is_fundamental_type_validate_against_integral(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			if((0 == is_fundamental_type<char>::value) != (0 == is_integral_type<char>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<signed char>::value) != (0 == is_integral_type<signed char>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<unsigned char>::value) != (0 == is_integral_type<unsigned char>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<short>::value) != (0 == is_integral_type<short>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<unsigned short>::value) != (0 == is_integral_type<unsigned short>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<int>::value) != (0 == is_integral_type<int>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<unsigned int>::value) != (0 == is_integral_type<unsigned int>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<long>::value) != (0 == is_integral_type<long>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<unsigned long>::value) != (0 == is_integral_type<unsigned long>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}
			if((0 == is_fundamental_type<bool>::value) != (0 == is_integral_type<bool>::value))
			{
				r->report("is_fundamental_type<X> != is_integral_type<X>", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_meta_is_fundamental_type(unittest_reporter *r)
		{
			using unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_fundamental_type", __FILE__);

			if(!test_stlsoft_meta_is_fundamental_type_test_fundamental(r))
			{
				bSuccess = false;
			}

			if(!test_stlsoft_meta_is_fundamental_type_validate_against_integral(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_fundamental_type(test_stlsoft_meta_is_fundamental_type);

#undef STLSOFT_TEST_IS_FUNDAMENTAL_TYPE

	} // anonymous namespace

} // namespace unittest

////////////////////////////////////////////////////////////////////////////
