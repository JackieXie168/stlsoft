
// Updated: 6th July 2006

#if !defined(ATLSTL_INCL_ATLSTL_STRING_HPP_CCOMBSTR_VENEER)
# error This file cannot be directly included, and should only be included within atlstl/string/ccombstr_veneer.hpp
#endif /* !ATLSTL_INCL_ATLSTL_STRING_HPP_CCOMBSTR_VENEER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_atlstl_ccombstr_veneer_correctness(ccombstr_veneer &s)
		{
			if(s.length() != s.size())
			{
				return false;
			}

			if(s.data() != s.c_str())
			{
				return false;
			}

			if(NULL == s.c_str())
			{
				return false;
			}

			return true;
		}

		ss_bool_t test_atlstl_ccombstr_veneer_equality(ccombstr_veneer const &s1, ccombstr_veneer const &s2)
		{
			if(s1.length() != s2.length())
			{
				return false;
			}

			if(s1.size() != s2.size())
			{
				return false;
			}

			if(s1.empty() != s2.empty())
			{
				return false;
			}

			if(s1 != s2)
			{
				return false;
			}

			if(!(s1 == s2))
			{
				return false;
			}

			return true;
		}

		ss_bool_t test_atlstl_ccombstr_veneer(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ATLSTL", "string/ccombstr_veneer", __FILE__);

			ccombstr_veneer 		bs1;
			ccombstr_veneer 		bs2(static_cast<char const*>(NULL));

			ccombstr_veneer 		bs3( "Hello");
			ccombstr_veneer 		bs4(L"Hello");

			if(!test_atlstl_ccombstr_veneer_correctness(bs1))
			{
				r->report("Correctness test failed", __LINE__);
				bSuccess = false;
			}

			if(!test_atlstl_ccombstr_veneer_correctness(bs2))
			{
				r->report("Correctness test failed", __LINE__);
				bSuccess = false;
			}

			if(!test_atlstl_ccombstr_veneer_correctness(bs3))
			{
				r->report("Correctness test failed", __LINE__);
				bSuccess = false;
			}

			if(!test_atlstl_ccombstr_veneer_correctness(bs4))
			{
				r->report("Correctness test failed", __LINE__);
				bSuccess = false;
			}

			if(!test_atlstl_ccombstr_veneer_equality(bs1, bs2))
			{
				r->report("Equality between empty instances failed", __LINE__);
				bSuccess = false;
			}

			if(!test_atlstl_ccombstr_veneer_equality(bs3, bs3))
			{
				r->report("Equality between non-empty instances failed", __LINE__);
				bSuccess = false;
			}

			if(bs3 != L"Hello")
			{
				r->report("Construction (from ANSI) failed", __LINE__);
				bSuccess = false;
			}

			if(bs4 != L"Hello")
			{
	//			wprintf(L"bs4: %u, %s\n", bs4.length(), bs4);

				r->report("Construction (from Unicode) failed", __LINE__);
				bSuccess = false;
			}

	//		wprintf(L"bs3: %u, %s\nbs2: %u, %s\n", bs3.length(), bs3, bs4.length(), bs4);

			if(bs3 != bs4)
			{
	//			wprintf(L"bs3: %u, %s\nbs2: %u, %s\n", bs3.length(), bs3, bs4.length(), bs4);

				r->report("Copy construction failed", __LINE__);
				bSuccess = false;
			}

			ccombstr_veneer 		bs5(bs3);

			if(bs3 != bs5)
			{
				r->report("Copy assignment failed", __LINE__);
				bSuccess = false;
			}

			bs5 = bs3;

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER >= 1200
			if(bs5 != "Hello")
			{
				r->report("Comparison to LPCSTR failed", __LINE__);
				bSuccess = false;
			}

			if("Hello" != bs5)
			{
				r->report("Comparison to LPCSTR failed", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			if(bs3 != L"Hello")
			{
				r->report("Comparison to LPCWSTR failed", __LINE__);
				bSuccess = false;
			}

			if(L"Hello" != bs3)
			{
				r->report("Comparison to LPCWSTR failed", __LINE__);
				bSuccess = false;
			}

			bs5 = "Hello";

			if(bs5 != L"Hello")
			{
				r->report("Assigment to LPCSTR failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_atlstl_ccombstr_veneer(test_atlstl_ccombstr_veneer);
	} // anonymous namespace

} // namespace unittest
