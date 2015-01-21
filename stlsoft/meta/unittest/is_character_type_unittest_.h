
// Updated: 3rd July 2006

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE)
# error This file cannot be directly included, and should only be included within stlsoft/meta/is_character_type.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		enum is_character_type__test_enum
		{};

		class is_character_type__test_class
		{
		public:
			void method1();

			void check_for_native_wchar_t(char);
			void check_for_native_wchar_t(sint8_t);
			void check_for_native_wchar_t(uint8_t);
			void check_for_native_wchar_t(sint16_t);
			void check_for_native_wchar_t(uint16_t);
			void check_for_native_wchar_t(sint32_t);
			void check_for_native_wchar_t(uint32_t);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			void check_for_native_wchar_t(sint64_t);
			void check_for_native_wchar_t(uint64_t);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT
			void check_for_native_wchar_t(wchar_t);
#endif /* STLSOFT_CF_NATIVE_WCHAR_T_SUPPORT */
		};


#if defined(STLSOFT_COMPILER_IS_COMO)

# define STLSOFT_TEST_IS_CHARACTER_TYPE(T, R)							\
																		\
		STLSOFT_STATIC_ASSERT(R == is_character_type<T>::value);

#else /* ? compiler */

# define STLSOFT_TEST_IS_CHARACTER_TYPE(T, R)							\
																		\
		if(R != is_character_type<T>::value)							\
		{																\
			r->report("is_character_type<" #T "> error", __LINE__); 	\
			bSuccess = false;											\
			STLSOFT_SUPPRESS_UNUSED(bSuccess);							\
		}

#endif /* compiler */


		ss_bool_t test_stlsoft_meta_is_character_type(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "meta/is_character_type", __FILE__);

			// Expected true

			STLSOFT_TEST_IS_CHARACTER_TYPE(char, 1)
			STLSOFT_TEST_IS_CHARACTER_TYPE(wchar_t, 1)

			// Expected false

			STLSOFT_TEST_IS_CHARACTER_TYPE(void, 0)

			STLSOFT_TEST_IS_CHARACTER_TYPE(short, 0)

			STLSOFT_TEST_IS_CHARACTER_TYPE(void*, 0)

			STLSOFT_TEST_IS_CHARACTER_TYPE(char*, 0)

			STLSOFT_TEST_IS_CHARACTER_TYPE(is_character_type__test_enum, 0)

			STLSOFT_TEST_IS_CHARACTER_TYPE(is_character_type__test_class, 0)

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_meta_is_character_type(test_stlsoft_meta_is_character_type);
	} // anonymous namespace

} // namespace unittest
