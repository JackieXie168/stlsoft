
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_signed_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_signed_type__test_enum
		{};

		class is_signed_type__test_class
		{
		public:
			void method1();
		};


#define STLSOFT_TEST_IS_SIGNED_TYPE(T, R)								\
																		\
		if(R != is_signed_type<T>::value)								\
		{																\
			r->report("is_signed_type<" #T "> error", __LINE__);		\
			bSuccess = false;											\
		}

		ss_bool_t test_stlsoft_meta_is_signed_type(unittest_reporter *r)
		{
			using unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_signed_type", __FILE__);

			// Expected true

			STLSOFT_TEST_IS_SIGNED_TYPE(signed char, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(short, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(int, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(long, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(sint8_t, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(sint16_t, 1)

			STLSOFT_TEST_IS_SIGNED_TYPE(sint32_t, 1)

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			STLSOFT_TEST_IS_SIGNED_TYPE(sint64_t, 1)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

			STLSOFT_TEST_IS_SIGNED_TYPE(float, 1)
			STLSOFT_TEST_IS_SIGNED_TYPE(double, 1)
			STLSOFT_TEST_IS_SIGNED_TYPE(long double, 1)

			// Expected false

			typedef int 	(&ar_t)[10];
			typedef void	(*pfn_t)();
			typedef void	(is_signed_type__test_class::*mpfn_t)();

			STLSOFT_TEST_IS_SIGNED_TYPE(unsigned char, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(unsigned short, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(unsigned int, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(unsigned long, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(uint8_t, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(uint16_t, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(uint32_t, 0)

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			STLSOFT_TEST_IS_SIGNED_TYPE(uint64_t, 0)
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


			STLSOFT_TEST_IS_SIGNED_TYPE(char, 0)
			STLSOFT_TEST_IS_SIGNED_TYPE(wchar_t, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(bool, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(ar_t, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(pfn_t, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(int*, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(int&, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(int*, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(is_signed_type__test_class, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(is_signed_type__test_enum, 0)

			STLSOFT_TEST_IS_SIGNED_TYPE(mpfn_t, 0)

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_signed_type(test_stlsoft_meta_is_signed_type);

#undef STLSOFT_TEST_IS_SIGNED_TYPE

	} // anonymous namespace

} // namespace unittest

////////////////////////////////////////////////////////////////////////////
