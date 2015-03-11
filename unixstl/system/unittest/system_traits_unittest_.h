
// Updated: 7th July 2006

#if !defined(UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS)
# error This file cannot be directly included, and should only be included within unixstl/system/system_traits.hpp
#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		typedef system_traits<char> 	system_traits_a_t;
		typedef system_traits<wchar_t>	system_traits_w_t;

		ss_bool_t test_system_traits_string_handling(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

#if 0
	static char_type	*str_copy(char_type *dest, char_type const *src);
	static char_type	*str_n_copy(char_type *dest, char_type const *src, size_type cch);
	static char_type	*str_cat(char_type *dest, char_type const *src);
	static char_type	*str_n_cat(char_type *dest, char_type const *src, size_type cch);
	static int_type 	str_compare(char_type const *s1, char_type const *s2);
	static int_type 	str_compare_no_case(char_type const *s1, char_type const *s2);
	static int_type 	str_n_compare(char_type const *s1, char_type const *s2, size_type cch);
	static size_type	str_len(char_type const *src);
	static char_type	*str_chr(char_type const *s, char_type ch);
	static char_type	*str_rchr(char_type const *s, char_type ch);
	static char_type	*str_str(char_type const *s, char_type const *sub);
	static char_type	*str_pbrk(char_type const *s, char_type const *charSet);
	static char_type	*str_end(char_type const *s);


			{
				r->report("Failed to get current directory", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		ss_bool_t test_system_traits_dynamic_loading(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			if(0)
			{
				system_traits_a_t::module_type	hmod	=	system_traits_a_t::load_library("a library that does not exist.so");

				if(NULL != hmod)
				{
					void	*symbol =	system_traits_a_t::find_symbol(hmod, "a symbol that does not exist");

					STLSOFT_SUPPRESS_UNUSED(symbol);

					system_traits_a_t::free_library(hmod);
				}
			}

			return bSuccess;
		}

		ss_bool_t test_system_traits_kernel_object_control(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			if(0)
			{
				int fh1 =	3;
				int fh2 =	3;

				system_traits_a_t::close_handle(fh1);
				system_traits_w_t::close_handle(fh2);
			}

			return bSuccess;
		}

		ss_bool_t test_system_traits_error(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			system_traits_a_t::set_last_error(ENOMEM);
			if(ENOMEM != system_traits_a_t::get_last_error())
			{
				r->report("set_last_error() != get_last_error()", __LINE__);
				bSuccess = false;
			}

			system_traits_w_t::set_last_error(ENOMEM);
			if(ENOMEM != system_traits_w_t::get_last_error())
			{
				r->report("set_last_error() != get_last_error()", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_system_traits_environment(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

#if 0
	static size_type	get_environment_variable(char_type const *name, char_type *buffer, size_type cchBuffer);
	static size_type	expand_environment_strings(char_type const *src, char_type *buffer, size_type cchBuffer);

			{
				r->report("Failed to get current directory", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		ss_bool_t test_unixstl_system_system_traits(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "UNIXSTL", "system/system_traits", __FILE__);

			// (i) String handling
			if(!test_system_traits_string_handling(r))
			{
				bSuccess = false;
			}

			// (ii) Dynamic loading
			if(!test_system_traits_dynamic_loading(r))
			{
				bSuccess = false;
			}

			// (iii) Kernel object control
			if(!test_system_traits_kernel_object_control(r))
			{
				bSuccess = false;
			}

			// (iv) Error
			if(!test_system_traits_error(r))
			{
				bSuccess = false;
			}

			// (v) Environment
			if(!test_system_traits_environment(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_unixstl_system_system_traits(test_unixstl_system_system_traits);
	}

}// namespace unittest
