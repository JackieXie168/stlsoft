
// Updated: 14th July 2006

#if !defined(STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING)
# error This file cannot be directly included, and should only be included within stlsoft/shims/access/string/std/basic_string.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_shims_access_string_std_basic_string_a(unittest_reporter *r)
		{
			ss_bool_t			bSuccess	=	true;
			ss_char_a_t const	*s1 		=	"String #1";

			if(NULL != c_str_ptr_null_a(static_cast<ss_char_a_t const*>(NULL)))
			{
				r->report("c_str_ptr_null_a(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL != c_str_ptr_null_a(""))
			{
				r->report("c_str_ptr_null_a(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_ptr_null_a(s1))
			{
				r->report("c_str_ptr_null_a(\"String #1\") failed", __LINE__);
				bSuccess = false;
			}



			if(NULL == c_str_ptr_a(static_cast<ss_char_a_t const*>(NULL)))
			{
				r->report("c_str_ptr_a(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL == c_str_ptr_a(""))
			{
				r->report("c_str_ptr_a(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_ptr_a(s1))
			{
				r->report("c_str_ptr_a(char*) failed", __LINE__);
				bSuccess = false;
			}



			if(NULL == c_str_data_a(static_cast<ss_char_a_t const*>(NULL)))
			{
				r->report("c_str_data_a(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL == c_str_data_a(""))
			{
				r->report("c_str_data_a(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_data_a(s1))
			{
				r->report("c_str_data_a(char*) failed", __LINE__);
				bSuccess = false;
			}



			if(0 != c_str_len_a(static_cast<ss_char_a_t const*>(NULL)))
			{
				r->report("c_str_len_a(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(0 != c_str_len_a(""))
			{
				r->report("c_str_len_a(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(3 != c_str_len_a("abc"))
			{
				r->report("c_str_len_a(\"abc\") failed", __LINE__);
				bSuccess = false;
			}



			if(0 != c_str_size_a(static_cast<ss_char_a_t const*>(NULL)))
			{
				r->report("c_str_size_a(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(0 != c_str_size_a(""))
			{
				r->report("c_str_size_a(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(3 != c_str_size_a("abc"))
			{
				r->report("c_str_size_a(\"abc\") failed", __LINE__);
				bSuccess = false;
			}


			return bSuccess;
		}

		ss_bool_t test_stlsoft_shims_access_string_std_basic_string_w(unittest_reporter *r)
		{
			ss_bool_t			bSuccess	=	true;
			ss_char_w_t const	*s1 		=	L"String #1";

			if(NULL != c_str_ptr_null_w(static_cast<ss_char_w_t const*>(NULL)))
			{
				r->report("c_str_ptr_null_w(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL != c_str_ptr_null_w(L""))
			{
				r->report("c_str_ptr_null_w(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_ptr_null_w(s1))
			{
				r->report("c_str_ptr_null_w(\"String #1\") failed", __LINE__);
				bSuccess = false;
			}



			if(NULL == c_str_ptr_w(static_cast<ss_char_w_t const*>(NULL)))
			{
				r->report("c_str_ptr_w(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL == c_str_ptr_w(L""))
			{
				r->report("c_str_ptr_w(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_ptr_w(s1))
			{
				r->report("c_str_ptr_w(char*) failed", __LINE__);
				bSuccess = false;
			}



			if(NULL == c_str_data_w(static_cast<ss_char_w_t const*>(NULL)))
			{
				r->report("c_str_data_w(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(NULL == c_str_data_w(L""))
			{
				r->report("c_str_data_w(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(s1 != c_str_data_w(s1))
			{
				r->report("c_str_data_w(char*) failed", __LINE__);
				bSuccess = false;
			}



			if(0 != c_str_len_w(static_cast<ss_char_w_t const*>(NULL)))
			{
				r->report("c_str_len_w(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(0 != c_str_len_w(L""))
			{
				r->report("c_str_len_w(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(3 != c_str_len_w(L"abc"))
			{
				r->report("c_str_len_w(\"abc\") failed", __LINE__);
				bSuccess = false;
			}



			if(0 != c_str_size_w(static_cast<ss_char_w_t const*>(NULL)))
			{
				r->report("c_str_size_w(NULL) failed", __LINE__);
				bSuccess = false;
			}
			if(0 != c_str_size_w(L""))
			{
				r->report("c_str_size_w(\"\") failed", __LINE__);
				bSuccess = false;
			}
			if(3 * sizeof(wchar_t) != c_str_size_w(L"abc"))
			{
				r->report("c_str_size_w(\"abc\") failed", __LINE__);
				bSuccess = false;
			}


			return bSuccess;
		}

		ss_bool_t test_stlsoft_shims_access_string_std_basic_string(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "shims/access/string/std/basic_string", __FILE__);

			if(!test_stlsoft_shims_access_string_std_basic_string_a(r))
			{
				bSuccess = false;
			}

			if(!test_stlsoft_shims_access_string_std_basic_string_w(r))
			{
				bSuccess = false;
			}



			ss_char_a_t const	*s1 =	"String #1";


			if(c_str_ptr(s1) != s1)
			{
				r->report("c_str_ptr(char*) failed", __LINE__);
				bSuccess = false;
			}

			ss_char_a_t const	*s2 =	c_str_ptr(static_cast<ss_char_a_t*>(NULL));

			if(*s2 != '\0')
			{
				r->report("c_str_ptr(NULL) failed", __LINE__);
				bSuccess = false;
			}

			if(c_str_ptr_null(static_cast<ss_char_a_t*>(NULL)) != NULL)
			{
				r->report("c_str_ptr_null(NULL) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_shims_access_string_std_basic_string(test_stlsoft_shims_access_string_std_basic_string);
	} // anonymous namespace

} // namespace unittest

