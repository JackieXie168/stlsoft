
// Updated: 30th December 2006

#if !defined(WINSTL_INCL_WINSTL_UTIL_HPP_STRUCT_INITIALISERS)
# error This file cannot be directly included, and should only be included within winstl/util/struct_initialisers.hpp
#endif /* !WINSTL_INCL_WINSTL_UTIL_HPP_STRUCT_INITIALISERS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_util_struct_initialisers(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "util/struct_initialisers", __FILE__);

			// WinBase.h
			{
				PROCESS_INFORMATION 					process_information;
				OVERLAPPED								overlapped;
				FILETIME								filetime;
				SYSTEMTIME								systemtime;
				COMMPROP								commprop;
				COMSTAT 								comstat;
				COMMTIMEOUTS							commtimeouts;
				SYSTEM_INFO 							system_info;
				EXCEPTION_DEBUG_INFO					exception_debug_info;
				CREATE_THREAD_DEBUG_INFO				create_thread_debug_info;
				CREATE_PROCESS_DEBUG_INFO				create_process_debug_info;
				EXIT_THREAD_DEBUG_INFO					exit_thread_debug_info;
				LOAD_DLL_DEBUG_INFO 					load_dll_debug_info;
				UNLOAD_DLL_DEBUG_INFO					unload_dll_debug_info;
				OUTPUT_DEBUG_STRING_INFO				output_debug_string_info;
				RIP_INFO								rip_info;
				DEBUG_EVENT 							debug_event;
				PROCESS_HEAP_ENTRY						process_heap_entry;
				BY_HANDLE_FILE_INFORMATION				by_handle_file_information;
				TIME_ZONE_INFORMATION					time_zone_information;
				WIN32_STREAM_ID 						win32_stream_id;
				WIN32_FIND_DATAA						win32_find_dataa;
				WIN32_FIND_DATAW						win32_find_dataw;
				WIN32_FILE_ATTRIBUTE_DATA				win32_file_attribute_data;
				SYSTEM_POWER_STATUS 					system_power_status;
#ifdef WINTRUST_H
				WIN_CERTIFICATE 						win_certificate;
				WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT	win_trust_actdata_context_with_subject;
				WIN_TRUST_ACTDATA_SUBJECT_ONLY			win_trust_actdata_subject_only;
				WIN_TRUST_SUBJECT_FILE					win_trust_subject_file;
				WIN_TRUST_SUBJECT_FILE_AND_DISPLAY		win_trust_subject_file_and_display;
				WIN_SPUB_TRUSTED_PUBLISHER_DATA 		win_spub_trusted_publisher_data;
#endif /* WINTRUST_H */

				STARTUPINFOA		startupinfoa;
				STARTUPINFOW		startupinfow;

				OFSTRUCT			ofstruct;

				MEMORYSTATUS		memorystatus;

				OSVERSIONINFOA		osversioninfoa;
				OSVERSIONINFOW		osversioninfow;
#if !defined(STLSOFT_COMPILER_IS_DMC)
				OSVERSIONINFOEXA	osversioninfoexa;
				OSVERSIONINFOEXW	osversioninfoexw;
#endif /* compiler */

				COMMCONFIG			commconfig;

				SECURITY_ATTRIBUTES security_attributes;


				winstl::init_struct(process_information);
				winstl::init_struct(overlapped);
				winstl::init_struct(filetime);
				winstl::init_struct(systemtime);
				winstl::init_struct(commprop);
				winstl::init_struct(comstat);
				winstl::init_struct(commtimeouts);
				winstl::init_struct(system_info);
				winstl::init_struct(exception_debug_info);
				winstl::init_struct(create_thread_debug_info);
				winstl::init_struct(create_process_debug_info);
				winstl::init_struct(exit_thread_debug_info);
				winstl::init_struct(load_dll_debug_info);
				winstl::init_struct(unload_dll_debug_info);
				winstl::init_struct(output_debug_string_info);
				winstl::init_struct(rip_info);
				winstl::init_struct(debug_event);
				winstl::init_struct(process_heap_entry);
				winstl::init_struct(by_handle_file_information);
				winstl::init_struct(time_zone_information);
				winstl::init_struct(win32_stream_id);
				winstl::init_struct(win32_find_dataa);
				winstl::init_struct(win32_find_dataw);
				winstl::init_struct(win32_file_attribute_data);
				winstl::init_struct(system_power_status);
#ifdef WINTRUST_H
				winstl::init_struct(win_certificate);
				winstl::init_struct(win_trust_actdata_context_with_subject);
				winstl::init_struct(win_trust_actdata_subject_only);
				winstl::init_struct(win_trust_subject_file);
				winstl::init_struct(win_trust_subject_file_and_display);
				winstl::init_struct(win_spub_trusted_publisher_data);
#endif /* WINTRUST_H */

				winstl::init_struct(startupinfoa);
				winstl::init_struct(startupinfow);

				winstl::init_struct(ofstruct);

				winstl::init_struct(memorystatus);

				winstl::init_struct(osversioninfoa);
				winstl::init_struct(osversioninfow);
#if !defined(STLSOFT_COMPILER_IS_DMC)
				winstl::init_struct(osversioninfoexa);
				winstl::init_struct(osversioninfoexw);
#endif /* compiler */

				winstl::init_struct(commconfig);

				winstl::init_struct(security_attributes);

			}

			// ShellApi.h
			{
				SHFILEOPSTRUCTA 	shfileopstructa;
				SHFILEOPSTRUCTW 	shfileopstructw;
#if !defined(STLSOFT_COMPILER_IS_GCC)
				SHNAMEMAPPINGA		shnamemappinga;
				SHNAMEMAPPINGW		shnamemappingw;
#endif /* compiler */
				SHFILEINFOA 	shfileinfoa;
				SHFILEINFOW 	shfileinfow;


#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	!defined(STLSOFT_COMPILER_IS_GCC) && \
	defined(WINVER) && \
	WINVER >= 0x0400
				DRAGINFOA		draginfoa;
				DRAGINFOW		draginfow;
#endif /* WINVER */
				APPBARDATA		appbardata;
				SHELLEXECUTEINFOA		shellexecuteinfoa;
				SHELLEXECUTEINFOW		shellexecuteinfow;
#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	(	!defined(STLSOFT_COMPILER_IS_GCC) || \
		__GNUC__ > 3 || \
		(	__GNUC__ == 3 && \
			__GNUC_MINOR__ > 2))
				SHQUERYRBINFO		shqueryrbinfo;
#endif /* compiler */
				NOTIFYICONDATAA 	notifyicondataa;
				NOTIFYICONDATAW 	notifyicondataw;


				winstl::init_struct(shfileopstructa);
				winstl::init_struct(shfileopstructw);
#if !defined(STLSOFT_COMPILER_IS_GCC)
				winstl::init_struct(shnamemappinga);
				winstl::init_struct(shnamemappingw);
#endif /* compiler */
				winstl::init_struct(shfileinfoa);
				winstl::init_struct(shfileinfow);


#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	!defined(STLSOFT_COMPILER_IS_GCC) && \
	defined(WINVER) && \
	WINVER >= 0x0400
				winstl::init_struct(draginfoa);
				winstl::init_struct(draginfow);
#endif /* WINVER */
				winstl::init_struct(appbardata);
				winstl::init_struct(shellexecuteinfoa);
				winstl::init_struct(shellexecuteinfow);
#if !defined(STLSOFT_COMPILER_IS_DMC) && \
	(	!defined(STLSOFT_COMPILER_IS_GCC) || \
		__GNUC__ > 3 || \
		(	__GNUC__ == 3 && \
			__GNUC_MINOR__ > 2))
				winstl::init_struct(shqueryrbinfo);
#endif /* compiler */
				winstl::init_struct(notifyicondataa);
				winstl::init_struct(notifyicondataw);
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

		unittest_registrar	  unittest_winstl_util_struct_initialisers(test_winstl_util_struct_initialisers);
	} // anonymous namespace

} // namespace unittest

