
#if !defined(DOTNETSTL_INCL_DOTNETSTL_HPP_STRING_ACCESSOR)
# error This file cannot be directly included, and should only be included within dotnetstl/string_accessor.hpp
#endif /* !DOTNETSTL_INCL_DOTNETSTL_HPP_STRING_ACCESSOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_dotnetstl_string_accessor(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, ".netSTL", "string_accessor", __FILE__);

			System::String	*s1 =	new System::String("String #1");
			System::String	*s2 =	new System::String("String #2");

			if(0 != strcmp(c_string_accessor<char>(s1), "String #1"))
			{
				r->report("c_string_accessor<char>() failed", __LINE__);
				bSuccess = false;
			}

			if(0 != wcscmp(c_string_accessor<wchar_t>(s2), L"String #2"))
			{
				r->report("c_string_accessor<char>() failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_dotnetstl_string_accessor(test_dotnetstl_string_accessor);
	} // anonymous namespace

} // namespace unittest
