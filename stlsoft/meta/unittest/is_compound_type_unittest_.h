
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_COMPOUND_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_compound_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_COMPOUND_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_compound_type__test_enum
		{};

		class is_compound_type__test_class
		{
		public:
			void method1();
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_COMPOUND_TYPE(T, R)							\
																		\
		STLSOFT_STATIC_ASSERT(R == is_compound_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_COMPOUND_TYPE(T, R)							\
																		\
		if(R != is_compound_type<T>::value) 							\
		{																\
			r->report("is_compound_type<" #T "> error", __LINE__);		\
			bSuccess = false;											\
		}

#endif /* compiler */



		ss_bool_t test_stlsoft_meta_is_compound_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_compound_type", __FILE__);

			// Expected true

			typedef int 	(&ar_t)[10];
			typedef void	(*pfn_t)();
			typedef void	(is_fundamental_type__test_class::*mpfn_t)();

			STLSOFT_TEST_IS_COMPOUND_TYPE(ar_t, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(pfn_t, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(void*, 1)
			STLSOFT_TEST_IS_COMPOUND_TYPE(int*, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(int&, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(is_fundamental_type__test_class, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(is_fundamental_type__test_enum, 1)

			STLSOFT_TEST_IS_COMPOUND_TYPE(mpfn_t, 1)

			// Expected false

			STLSOFT_TEST_IS_COMPOUND_TYPE(char, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(signed char, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(unsigned char, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(wchar_t, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(short, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(unsigned short, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(int, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(unsigned int, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(long, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(unsigned long, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(sint8_t, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(uint8_t, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(sint16_t, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(uint16_t, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(sint32_t, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(uint32_t, 0)

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			STLSOFT_TEST_IS_COMPOUND_TYPE(sint64_t, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(uint64_t, 0)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			STLSOFT_TEST_IS_COMPOUND_TYPE(float, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(double, 0)
			STLSOFT_TEST_IS_COMPOUND_TYPE(long double, 0)

			STLSOFT_TEST_IS_COMPOUND_TYPE(bool, 0)

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_compound_type(test_stlsoft_meta_is_compound_type);

#undef STLSOFT_TEST_IS_COMPOUND_TYPE

	} // anonymous namespace

} // namespace unittest
