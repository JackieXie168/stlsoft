
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_CONST_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_const_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CONST_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_const_type__test_enum
		{};

		class is_const_type__test_class
		{
		public:
			void method1();
			void method2() const;
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_CONST_TYPE(T, R)								\
																		\
		STLSOFT_STATIC_ASSERT(R == is_const_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_CONST_TYPE(T, R)								\
																		\
		if(R != is_const_type<T>::value)								\
		{																\
			r->report("is_const_type<" #T "> error", __LINE__); 		\
			bSuccess = false;											\
			STLSOFT_SUPPRESS_UNUSED(bSuccess);							\
		}

#endif /* compiler */

		ss_bool_t test_stlsoft_meta_is_const_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_const_type", __FILE__);

			STLSOFT_SUPPRESS_UNUSED(bSuccess);


			// fundamental types

			STLSOFT_TEST_IS_CONST_TYPE(void, 0)

			STLSOFT_TEST_IS_CONST_TYPE(int, 0)
			STLSOFT_TEST_IS_CONST_TYPE(volatile int, 0)
			STLSOFT_TEST_IS_CONST_TYPE(const int, 1)
#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	!defined(STLSOFT_COMPILER_IS_MWERKS)
			STLSOFT_TEST_IS_CONST_TYPE(const volatile int, 1)
#endif /* compiler */

			// arrays

#if 0
			// TODO is_const_type does not work for arrays

			typedef int (&arc1_t)[1];
			typedef const int (&arc2_t)[1];

			STLSOFT_TEST_IS_CONST_TYPE(arc1_t, 0)

			STLSOFT_TEST_IS_CONST_TYPE(arc2_t, 0)
#endif /* 0 */

			// functions

			typedef void (*pfn_t)();

			STLSOFT_TEST_IS_CONST_TYPE(pfn_t, 0)

			STLSOFT_TEST_IS_CONST_TYPE(const pfn_t, 1)

			// pointers

			STLSOFT_TEST_IS_CONST_TYPE(int const*, 0)
			STLSOFT_TEST_IS_CONST_TYPE(int* const, 1)

			// references

			STLSOFT_TEST_IS_CONST_TYPE(int &, 0)
			STLSOFT_TEST_IS_CONST_TYPE(int const&, 1)

			// classes

			STLSOFT_TEST_IS_CONST_TYPE(is_const_type__test_class, 0)

			STLSOFT_TEST_IS_CONST_TYPE(const is_const_type__test_class, 1)

			// enumerations

			STLSOFT_TEST_IS_CONST_TYPE(is_const_type__test_enum, 0)

			STLSOFT_TEST_IS_CONST_TYPE(const is_const_type__test_enum, 1)

			// pointers to (non-static) member functions

			typedef void (is_const_type__test_class::*mpfn_t)();
			typedef void (is_const_type__test_class::*mpfn_c_t)() const;

			STLSOFT_TEST_IS_CONST_TYPE(mpfn_t, 0)
			STLSOFT_TEST_IS_CONST_TYPE(mpfn_c_t, 0)

			STLSOFT_TEST_IS_CONST_TYPE(const mpfn_t, 1)
			STLSOFT_TEST_IS_CONST_TYPE(const mpfn_c_t, 1)

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_const_type(test_stlsoft_meta_is_const_type);

#undef STLSOFT_TEST_IS_CONST_TYPE

	} // anonymous namespace

} // namespace unittest
