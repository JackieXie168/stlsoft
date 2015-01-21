
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_CLASS_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_class_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CLASS_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
#ifdef STLSOFT_IS_CLASS_TYPE_SUPPORTED

		enum is_class_type__test_enum
		{};

		class is_class_type__test_class
		{
		public:
			void method1();
		};


# if defined(STLSOFT_COMPILER_IS_COMO)

#  define STLSOFT_TEST_IS_CLASS_TYPE(T, R)								\
																		\
		STLSOFT_STATIC_ASSERT(R == is_class_type<T>::value);

# else /* ? compiler */

#  define STLSOFT_TEST_IS_CLASS_TYPE(T, R)								\
																		\
		if(R != is_class_type<T>::value)								\
		{																\
			r->report("is_class_type<" #T "> error", __LINE__); 		\
			bSuccess = false;											\
			STLSOFT_SUPPRESS_UNUSED(bSuccess);							\
		}

# endif /* compiler */


		ss_bool_t test_stlsoft_meta_is_class_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_class_type", __FILE__);

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

# if !defined(STLSOFT_COMPILER_IS_BORLAND)
			// Expected true

			STLSOFT_TEST_IS_CLASS_TYPE(is_class_type__test_class, 1)

			// Expected false

			STLSOFT_TEST_IS_CLASS_TYPE(void, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(bool, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(char, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(signed char, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned char, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(short, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned short, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(int, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned int, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(long, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned long, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(float, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(double, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(long double, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(is_class_type__test_enum, 0)




			STLSOFT_TEST_IS_CLASS_TYPE(void*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(bool*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(char*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(signed char*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned char*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(short*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned short*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(int*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned int*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(long*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(unsigned long*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(float*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(double*, 0)
			STLSOFT_TEST_IS_CLASS_TYPE(long double*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(is_class_type__test_enum*, 0)

			STLSOFT_TEST_IS_CLASS_TYPE(is_class_type__test_class*, 0)
# endif /* compiler */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_class_type(test_stlsoft_meta_is_class_type);

# undef STLSOFT_TEST_IS_CLASS_TYPE

#endif /* STLSOFT_IS_CLASS_TYPE_SUPPORTED */
	} // anonymous namespace

} // namespace unittest
