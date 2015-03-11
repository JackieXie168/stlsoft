
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_floating_point_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_floating_point_type__test_enum
		{};

		class is_floating_point_type__test_class
		{
		public:
			void method1();
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_FLOATING_POINT_TYPE(T, R)						\
																		\
		STLSOFT_STATIC_ASSERT(R == is_floating_point_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_FLOATING_POINT_TYPE(T, R)						\
																		\
		if(R != is_floating_point_type<T>::value)						\
		{																\
			r->report("is_floating_point_type<" #T "> error", __LINE__);\
			bSuccess = false;											\
			STLSOFT_SUPPRESS_UNUSED(bSuccess);							\
		}

#endif /* compiler */


		ss_bool_t test_stlsoft_meta_is_floating_point_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_floating_point_type", __FILE__);

			// Expected true

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(float, 1)
			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(double, 1)
			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(long double, 1)

			// Expected false

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(void, 0)

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(short, 0)

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(void*, 0)

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(float*, 0)

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(is_floating_point_type__test_enum, 0)

			STLSOFT_TEST_IS_FLOATING_POINT_TYPE(is_floating_point_type__test_class, 0)

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_floating_point_type(test_stlsoft_meta_is_floating_point_type);
	} // anonymous namespace

} // namespace unittest
