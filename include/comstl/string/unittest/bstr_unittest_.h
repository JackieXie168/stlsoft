
// Updated: 4th August 2007

#if !defined(COMSTL_INCL_COMSTL_STRING_HPP_BSTR)
# error This file cannot be directly included, and should only be included within comstl/string/bstr.hpp
#endif /* !COMSTL_INCL_COMSTL_STRING_HPP_BSTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_string_bstr_invariant(unittest_reporter *r, bstr &s)
		{
			ss_bool_t				bSuccess	=	true;

			if(s.empty() && 0 != s.length())
			{
				r->report("expected length() == 0 when empty()", __LINE__);
				bSuccess = false;
			}

			if(s.empty() && 0 != s.size())
			{
				r->report("expected size() == 0 when empty()", __LINE__);
				bSuccess = false;
			}

			if(!s.empty() && 0 == s.length())
			{
				r->report("expected length() != 0 when !empty()", __LINE__);
				bSuccess = false;
			}

			if(!s.empty() && 0 == s.size())
			{
				r->report("expected size() != 0 when !empty()", __LINE__);
				bSuccess = false;
			}

			if(s.length() != s.size())
			{
				r->report("expected length() == size()", __LINE__);
				bSuccess = false;
			}


			if(NULL == s.c_str())
			{
				r->report("c_str() cannot return NULL", __LINE__);
				bSuccess = false;
			}

			if(NULL == s.data())
			{
				r->report("data() cannot return NULL", __LINE__);
				bSuccess = false;
			}

			if(0 != ::wcsncmp(s.c_str(), s.data(), s.size()))
			{
				r->report("data() and c_str() point to strings with different contents", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_comstl_string_bstr(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "string/bstr", __FILE__);

			{
				bstr	s1;

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!s1.empty())
				{
					r->report("expected empty string", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1;
				bstr	s2(s1);

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s2))
				{
					bSuccess = false;
				}

				if(!s1.equal(s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(s1 != s2)
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(!(s1 == s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1;
				bstr	s2;

				s2 = s1;

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s2))
				{
					bSuccess = false;
				}

				if(!s1.equal(s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(s1 != s2)
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(!(s1 == s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1("abc");
				bstr	s2(s1);

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s2))
				{
					bSuccess = false;
				}

				if(!s1.equal(s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(s1 != s2)
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(!(s1 == s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(L"abc" != s2)
				{
					r->report("copied instance has wrong contents", __LINE__);
					bSuccess = false;
				}

				if(s2 != L"abc")
				{
					r->report("copied instance has wrong contents", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1(L"abc");
				bstr	s2;

				s2 = s1;

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s2))
				{
					bSuccess = false;
				}

				if(!s1.equal(s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(s1 != s2)
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(!(s1 == s2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(L"abc" != s2)
				{
					r->report("copied instance has wrong contents", __LINE__);
					bSuccess = false;
				}

				if(s2 != L"abc")
				{
					r->report("copied instance has wrong contents", __LINE__);
					bSuccess = false;
				}
			}

			{
				if(L"abc" != bstr("abcd", 3))
				{
					r->report("length construction yielded wrong answer", __LINE__);
					bSuccess = false;
				}

				if(L"abc" != bstr(L"abcde", 3))
				{
					r->report("length construction yielded wrong answer", __LINE__);
					bSuccess = false;
				}
			}

			{
				if(L"abc" != bstr(L"xyz").assign("abc", 3))
				{
					r->report("length construction yielded wrong answer", __LINE__);
					bSuccess = false;
				}

				if(L"abc" != bstr("xyz").assign(L"abcde", 3))
				{
					r->report("length construction yielded wrong answer", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1(3, 'x');

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(L"xxx" != s1)
				{
					r->report("length construction yielded wrong answer", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1(3, 'x');
				bstr	s2("abc");

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s2))
				{
					bSuccess = false;
				}

				s1.swap(s2);

				if(L"abc" != s1)
				{
					r->report("swap() failed", __LINE__);
					bSuccess = false;
				}

				if(L"xxx" != s2)
				{
					r->report("swap() failed", __LINE__);
					bSuccess = false;
				}
			}

			{
				bstr	s1("abc");

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}

				s1.clear();

				if(!s1.empty())
				{
					r->report("clear() failed", __LINE__);
					bSuccess = false;
				}

				if(!test_comstl_string_bstr_invariant(r, s1))
				{
					bSuccess = false;
				}
			}

			{
				bstr	s1;
				BSTR	bstr1	=	::SysAllocString(L"abc");

				if(NULL != bstr1)
				{
					s1.attach(bstr1);

					if(s1.empty())
					{
						r->report("attach() failed", __LINE__);
						bSuccess = false;
					}

					if(3 != s1.size())
					{
						r->report("attach() failed", __LINE__);
						bSuccess = false;
					}

					if(L"abc" != s1)
					{
						r->report("attach() failed", __LINE__);
						bSuccess = false;
					}
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_string_bstr(test_comstl_string_bstr);

	} // anonymous namespace

} // namespace unittest
