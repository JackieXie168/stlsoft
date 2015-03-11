
// Updated: 4th August 2007

#if !defined(WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY)
# error This file cannot be directly included, and should only be included within registry/reg_key.hpp
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REG_KEY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_registry_reg_key(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "registry/reg_key", __FILE__);

			if(0)
			{
				reg_key 	test(HKEY_CURRENT_USER, "SOFTWARE\\Synesis Software\\STLSoft\test");
				reg_key 	WinSTL	=	test.create_sub_key(reg_string_t("WinSTL"));
				reg_key 	RegKey	=	test.create_sub_key("reg_key");

				RegKey.set_value("dw1", DWORD(1));
				RegKey.set_value(reg_string_t("dw2"), DWORD(2));

				RegKey.set_value("qw1", ws_uint64_t(1));
				RegKey.set_value(reg_string_t("qw2"), ws_uint64_t(2));

				RegKey.set_value("i1", 1);
				RegKey.set_value(reg_string_t("i2"), 2);

				RegKey.set_value("sz1", "string-1");
				RegKey.set_value(reg_string_t("sz2"), "string-2");

				RegKey.set_value("xsz1", "xstring-1", REG_EXPAND_SZ);
				RegKey.set_value(reg_string_t("xsz2"), "xstring-2", REG_EXPAND_SZ);

				static const char	*strings[] =
				{
						"multi-string-1"
					,	"multi-string-2"
					,	"multi-string-3"
				};

				RegKey.set_value("msz1", &strings[0], STLSOFT_NUM_ELEMENTS(strings));
				RegKey.set_value(reg_string_t("msz2"), &strings[0], STLSOFT_NUM_ELEMENTS(strings));

				static int	blob[20];

				RegKey.set_value("binary1", &blob[0], sizeof(blob));
				RegKey.set_value(reg_string_t("binary2"), &blob[0], sizeof(blob));

				RegKey.get_value("dw1");
				RegKey.get_value(reg_string_t("dw1"));

				reg_key 	k2(RegKey);
				reg_key 	k3	=	RegKey;
				reg_key 	k4;

				k4	=	RegKey;

				k4.swap(k3);
			}

			if(0)
			{
				reg_key 	WinSTL	=	reg_key::create_key(HKEY_CURRENT_USER, reg_string_t("SOFTWARE\\Synesis Software\\STLSoft\\test\\WinSTL"));
				reg_key 	RegKey	=	reg_key::create_key(HKEY_CURRENT_USER, "SOFTWARE\\Synesis Software\\STLSoft\\test\\reg_key");

			}

#if 0
			if(<<TODO>>)
			{
				r->report("<<TODO>> failed", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_registry_reg_key(test_winstl_registry_reg_key);
	} // anonymous namespace

} // namespace unittest
