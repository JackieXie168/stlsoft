
// Updated: 2nd July 2006

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS)
# error This file cannot be directly included, and should only be included within winstl/system/system_traits.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		typedef system_traits<char> 	traits_a_t;
		typedef system_traits<wchar_t>	traits_w_t;

		ss_bool_t test_system_traits_string_handling(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			char	buff1[101];
//			  char	  buff2[101];
//			  char	  buff3[101];

			char	*psz1;
//			  char	  *psz2;
//			  char	  *psz3;

			psz1 = traits_a_t::str_copy(buff1, "Hello");
			if(0 != ::strcmp(buff1, "Hello"))
			{
				r->report("str_copy() failure", __LINE__);
				bSuccess = false;
			}
			if(0 != ::strcmp(buff1, psz1))
			{
				r->report("str_copy() failure", __LINE__);
				bSuccess = false;
			}
#if 0
	/* static char_type    *str_copy(char_type *dest, char_type const *src) */
	static char_type	*str_n_copy(char_type *dest, char_type const *src, size_type cch);
	static char_type	*str_cat(char_type *dest, char_type const *src);
	static char_type	*str_n_cat(char_type *dest, char_type const *src, size_type cch);
	static int_type 	str_compare(char_type const *s1, char_type const *s2);
	static int_type 	str_compare_no_case(char_type const *s1, char_type const *s2);
	static size_type	str_len(char_type const *src);
	static char_type	*str_chr(char_type const *s, char_type ch);
	static char_type	*str_rchr(char_type const *s, char_type ch);
	static char_type	*str_str(char_type const *s, char_type const *sub);
#endif /* 0 */

			;

			return bSuccess;
		}

		ss_bool_t test_system_traits_module_paths(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(r);

#if 0
	static size_type	get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer);
	static size_type	get_system_directory(char_type *buffer, size_type cchBuffer);
	static size_type	get_windows_directory(char_type *buffer, size_type cchBuffer);
#endif /* 0 */


			;

			return bSuccess;
		}

		ss_bool_t test_system_traits_dynamic_loading(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			traits_a_t::module_type hModule 	=	traits_a_t::load_library("KERNEL32");

			if(NULL == hModule)
			{
				r->report("load_library() failed to load KERNEL32", __LINE__);
			}
			else
			{
				FARPROC sym    =   traits_a_t::find_symbol(hModule, "CreateFileA");

				if(NULL == sym)
				{
					r->report("Failed to find \"CreateFileA\" in KERNEL32 - very suspicious!!", __LINE__);
				}

				traits_a_t::free_library(hModule);
			}

#if 0
	static module_type	load_library(char_type const *name);
	static bool_type	free_library(module_type hModule);
	static void 		*find_symbol(module_type hModule, char const *symbolName);
#endif /* 0 */

			;

			return bSuccess;
		}

		ss_bool_t test_system_traits_system_state(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(r);

#if 0
	static bool_type	set_current_directory(char_type const *dir);
	static size_type	get_current_directory(size_type cchBuffer, char_type *buffer);

	static bool_type	file_exists(char_type const *fileName);
	static bool_type	is_file(char_type const *path);
	static bool_type	is_directory(char_type const *path);
	static bool_type	stat(char_type const *spec, stat_data_type *stat_data);
	static bool_type	fstat(file_handle_type fd, fstat_data_type *fstat_data);
#endif /* 0 */

			;

			return bSuccess;
		}

		ss_bool_t test_system_traits_system_control(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(r);

#if 0
	static bool_type	create_directory(char_type const *dir);
	static bool_type	create_directory(char_type const *dir, LPSECURITY_ATTRIBUTES lpsa);
	static bool_type	remove_directory(char_type const *dir);

	static bool_type	unlink_file(char_type const *file);
	static bool_type	delete_file(char_type const *file);
	static bool_type	rename_file(char_type const *currentName, char_type const *newName);
	static bool_type	copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false);
#endif /* 0 */

#if 0
	static file_handle_type create_file(char_type const *fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, HANDLE hTemplateFile);
	static bool_type		close_handle(HANDLE h);
	static bool_type		close_file(file_handle_type h);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
	static ws_uint64_t		get_file_size(file_handle_type h);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#endif /* 0 */

			;

			return bSuccess;
		}

		ss_bool_t test_winstl_system_traits(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/system_traits", __FILE__);

			if(!test_system_traits_string_handling(r))
			{
				bSuccess = false;
			}

			if(!test_system_traits_module_paths(r))
			{
				bSuccess = false;
			}

			if(!test_system_traits_dynamic_loading(r))
			{
				bSuccess = false;
			}

			if(!test_system_traits_system_state(r))
			{
				bSuccess = false;
			}

			if(!test_system_traits_system_control(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_traits(test_winstl_system_traits);
	}

}// namespace unittest
