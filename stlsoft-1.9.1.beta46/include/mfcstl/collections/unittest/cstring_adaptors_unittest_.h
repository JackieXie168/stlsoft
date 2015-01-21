
// Updated: 12th March 2007

#if !defined(MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CSTRING_ADAPTORS)
# error This file cannot be directly included, and should only be included within mfcstl/collections/cstring_adaptors.hpp
#endif /* !MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CSTRING_ADAPTORS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		template<ss_typename_param_k S>
		ss_bool_t test_mfcstl_cstring_adaptor_type_const_(unittest_reporter *r, S const& s)
		{
			ss_bool_t				bSuccess	=	true;

			s.size();
			s.length();
			s.empty();
			s.c_str();
			s.data();

			if(s.size() != s.length())
			{
				r->report("length() != size(): failed", __LINE__);
				bSuccess = false;
			}

			s.begin();
			s.end();
			s.rbegin();
			s.rend();

			(void)s[0];
			(void)s.at(0);

			s == s;
			s == CString("CString inside");
			s == "CString inside";
			s == L"CString inside";
			s == reinterpret_cast<unsigned char const*>("CString inside");
			CString("CString inside") == s;
			"CString inside" == s;
			L"CString inside" == s;
			reinterpret_cast<unsigned char const*>("CString inside") == s;

			return bSuccess;
		}

		template<ss_typename_param_k S>
		ss_bool_t test_mfcstl_cstring_adaptor_type_(unittest_reporter *r, S &s)
		{
			ss_bool_t				bSuccess	=	test_mfcstl_cstring_adaptor_type_const_(r, s);

			s.size();
			s.length();
			s.empty();
			s.c_str();
			s.data();

			if(s.size() != s.length())
			{
				r->report("length() != size(): failed", __LINE__);
				bSuccess = false;
			}

			s.begin();
			s.end();
			s.rbegin();
			s.rend();

			(void)s[0];
			(void)s.at(0);

			S	s2(s);
			S	s3(s);

		//	s2 = s;

			s2.assign("CString inside");
			s2.assign(L"CString inside");
			s2.assign(reinterpret_cast<unsigned char const*>("CString inside"));
			s2.assign("CString inside", 4);
			s2.assign(L"CString inside", 4);
			s2.assign(reinterpret_cast<unsigned char const*>("CString inside"), 4);
			s2.assign(s3);
			s2.assign(s3, 0, 4);
			s2.assign(10, '~');
#if defined(STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION) && \
	STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_7_0
# pragma message("TODO: Fix this up before 1.9.1 proper")
			s2.assign(&*s3.begin(), &*s3.end());
#else /* ? library */
			s2.assign(s3.begin(), s3.end());
#endif /* library */

			s2	=	s3;
			s2	=	CString("CString inside");
			s2	=	"CString inside";
			s2	=	L"CString inside";
			s2	=	reinterpret_cast<unsigned char const*>("CString inside");

			return bSuccess;
		}

		ss_bool_t test_mfcstl_cstring_adaptor_type_(unittest_reporter *r, const_CString_iadaptor const& s)
		{
			return test_mfcstl_cstring_adaptor_type_const_(r, s);
		}
		ss_bool_t test_mfcstl_cstring_adaptor_type_(unittest_reporter *r, const_CString_iadaptor &s)
		{
			return test_mfcstl_cstring_adaptor_type_const_(r, s);
		}

		ss_bool_t test_mfcstl_cstring_adaptors(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "collections/cstring_adaptors", __FILE__);


			{
				CString_cadaptor		sca("CString inside");

				if(!test_mfcstl_cstring_adaptor_type_(r, sca))
				{
					bSuccess = false;
				}
			}

			{
				CString 				str("CString inside");
				CString_iadaptor		sia(str);

				if(!test_mfcstl_cstring_adaptor_type_(r, sia))
				{
					bSuccess = false;
				}
			}

			{
				const CString			str("CString inside");
				const_CString_iadaptor	sia(str);

				if(!test_mfcstl_cstring_adaptor_type_(r, sia))
				{
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_cstring_adaptors(test_mfcstl_cstring_adaptors);
	} // anonymous namespace

} // namespace unittest

