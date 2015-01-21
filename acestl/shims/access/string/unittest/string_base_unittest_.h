
#if !defined(ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE)
# error This file cannot be directly included, and should only be included within acestl/shims/access/string/string_base.hpp
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_acestl_shims_access_string_string_base(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "ACESTL", "shims/access/string/string_string_access", __FILE__);

			typedef ACE_String_Base<as_char_a_t>	ACE_String_char_t;

			ACE_String_char_t		s1;
			ACE_String_char_t		s2("String 1");

			if(0 != ::strcmp("", stlsoft_ns_qual(c_str_ptr)(s1)))
			{
				r->report("c_str_ptr(ACE_String_Base<> const&) (empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_ptr)(s1) != s1.c_str())
			{
				r->report("c_str_ptr(ACE_String_Base<> const&) (empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_data)(s1) != s1.c_str())
			{
				r->report("c_str_data(ACE_String_Base<> const&) (empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_len)(s1) != s1.length())
			{
				r->report("c_str_len(ACE_String_Base<> const&) (empty) failed ", __LINE__);
				bSuccess = false;
			}

			if(0 != ::strcmp("String 1", stlsoft_ns_qual(c_str_ptr)(s2)))
			{
				r->report("c_str_ptr(ACE_String_Base<> const&) (non-empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_ptr)(s2) != s2.c_str())
			{
				r->report("c_str_ptr(ACE_String_Base<> const&) (non-empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_data)(s2) != s2.c_str())
			{
				r->report("c_str_data(ACE_String_Base<> const&) (non-empty) failed ", __LINE__);
				bSuccess = false;
			}
			if(stlsoft_ns_qual(c_str_len)(s2) != s2.length())
			{
				r->report("c_str_len(ACE_String_Base<> const&) (non-empty) failed ", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_acestl_shims_access_string_string_base(test_acestl_shims_access_string_string_base);
	} // anonymous namespace

} // namespace unittest
