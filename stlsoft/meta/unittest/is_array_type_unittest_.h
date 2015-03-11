
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_ARRAY_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_array_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_ARRAY_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_array_type__test_enum
		{};

		class is_array_type__test_class
		{
		public:
			void method1();
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_ARRAY_TYPE(T, R)								\
																		\
		STLSOFT_STATIC_ASSERT(R == is_array_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_ARRAY_TYPE(T, R)								\
																		\
		if(R != is_array_type<T>::value)								\
		{																\
			r->report("is_array_type<" #T "> error", __LINE__); 		\
			bSuccess = false;											\
			STLSOFT_SUPPRESS_UNUSED(bSuccess);							\
		}

#endif /* compiler */


		ss_bool_t test_stlsoft_meta_is_array_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_array_type", __FILE__);

			STLSOFT_SUPPRESS_UNUSED(bSuccess);


			typedef int 		(&ar1_t)[1];
			typedef const int	(&ar2_t)[1];

			// Expected true

#if !defined(STLSOFT_COMPILER_IS_BORLAND)
			STLSOFT_TEST_IS_ARRAY_TYPE(ar1_t, 1)

			STLSOFT_TEST_IS_ARRAY_TYPE(ar2_t, 1)
#endif /* compiler */

			// Expected false

			STLSOFT_TEST_IS_ARRAY_TYPE(void, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(bool, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(char, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(signed char, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned char, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(short, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned short, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(int, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned int, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(long, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned long, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(float, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(double, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(long double, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(is_array_type__test_enum, 0)


# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

			STLSOFT_TEST_IS_ARRAY_TYPE(void*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(bool*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(char*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(signed char*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned char*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(short*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned short*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(int*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned int*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(long*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(unsigned long*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(float*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(double*, 0)
			STLSOFT_TEST_IS_ARRAY_TYPE(long double*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(is_array_type__test_enum*, 0)

			STLSOFT_TEST_IS_ARRAY_TYPE(is_array_type__test_class*, 0)

# endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_array_type(test_stlsoft_meta_is_array_type);

#undef STLSOFT_TEST_IS_ARRAY_TYPE

	} // anonymous namespace

} // namespace unittest
