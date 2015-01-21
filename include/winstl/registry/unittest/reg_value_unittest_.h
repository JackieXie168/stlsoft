
// Updated: 28th April 2008

#if !defined(WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE)
# error This file cannot be directly included, and should only be included within winstl/registry/reg_value.hpp
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_VALUE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		// This is necessary because this file is included by reg_value.hpp, but
		// that is included by reg_key.hpp. Hence, the reg_key typedef is not
		// defined by the time this is included.
		template <ss_typename_param_k C>
		void test_winstl_registry_with_late_instantiation(C const* )
		{
#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
	!defined(STLSOFT_COMPILER_IS_DMC)
			if(0)
			{
				typedef basic_reg_key<	C
									,	reg_traits<C>
									,	processheap_allocator<C>
									>	reg_key;

				reg_key 	test(HKEY_CURRENT_USER, "SOFTWARE\\Synesis Software\\STLSoft\test");
				reg_key 	WinSTL	=	test.create_sub_key(reg_string_t("WinSTL"));
				reg_key 	RegKey	=	test.create_sub_key("reg_key");

				reg_value	v0;
				reg_value	v1	=	RegKey.get_value("");
				reg_value	v2(v1);
				reg_value	v3;

				v3 = v2;

				v1.type();
				v1.name();
				v1.value_sz();
				v1.value_expand_sz();
				v1.value_dword();
//				  v1.value_dword_littleendian();
//				  v1.value_dword_bigendian();
				v1.value_binary();

#ifndef WINSTL_REG_VALUE_NO_MULTI_SZ
				{
					reg_value::strings_type	strings = v1.value_multi_sz();
				}
#endif /* !WINSTL_REG_VALUE_NO_MULTI_SZ */
			}
#endif /* !STLSOFT_COMPILER_IS_BORLAND */
		}

		ss_bool_t test_winstl_registry_reg_value(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "registry/reg_value", __FILE__);

			test_winstl_registry_with_late_instantiation(static_cast<TCHAR const*>(0));

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_registry_reg_value(test_winstl_registry_reg_value);
	} // anonymous namespace

} // namespace unittest

