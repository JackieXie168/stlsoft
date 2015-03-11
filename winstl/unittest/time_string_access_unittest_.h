
// Updated: 20th June 2006

#if !defined(WINSTL_INCL_WINSTL_HPP_TIME_STRING_ACCESS)
# error This file cannot be directly included, and should only be included within winstl/time_string_access.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_TIME_STRING_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_time_string_access(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "time_string_access", __FILE__);

			{
				SYSTEMTIME	st1;
				FILETIME	ft;
				SYSTEMTIME	st2;

				::GetLocalTime(&st1);
				::SystemTimeToFileTime(&st1, &ft);

				st2 = FILETIME2SYSTEMTIME(ft);

				if( st1.wDay != st2.wDay ||
					st1.wYear != st2.wYear ||
					st1.wMonth != st2.wMonth ||
					st1.wDayOfWeek != st2.wDayOfWeek ||
					st1.wDay != st2.wDay ||
					st1.wHour != st2.wHour ||
					st1.wMinute != st2.wMinute ||
					st1.wSecond != st2.wSecond ||
					st1.wMilliseconds != st2.wMilliseconds)
				{
					r->report("FILETIME2SYSTEMTIME() failed ", __LINE__);
					bSuccess = false;
				}
			}

			{
				SYSTEMTIME	st;

				::GetLocalTime(&st);

				stlsoft::c_str_len_a(st);
				stlsoft::c_str_len_w(st);
				stlsoft::c_str_len(st);

				stlsoft::c_str_ptr_a(st);
				stlsoft::c_str_ptr_w(st);
				stlsoft::c_str_ptr(st);

				stlsoft::c_str_ptr_null_a(st);
				stlsoft::c_str_ptr_null_w(st);
				stlsoft::c_str_ptr_null(st);

				stlsoft::c_str_data_a(st);
				stlsoft::c_str_data_w(st);
				stlsoft::c_str_data(st);

			}

			{
				SYSTEMTIME	st;
				FILETIME	ft;

				::GetLocalTime(&st);
				::SystemTimeToFileTime(&st, &ft);

				stlsoft::c_str_len_a(ft);
				stlsoft::c_str_len_w(ft);
				stlsoft::c_str_len(ft);

				stlsoft::c_str_ptr_a(ft);
				stlsoft::c_str_ptr_w(ft);
				stlsoft::c_str_ptr(ft);

				stlsoft::c_str_ptr_null_a(ft);
				stlsoft::c_str_ptr_null_w(ft);
				stlsoft::c_str_ptr_null(ft);

				stlsoft::c_str_data_a(ft);
				stlsoft::c_str_data_w(ft);
				stlsoft::c_str_data(ft);

			}


			{
				SYSTEMTIME	st;

				::GetLocalTime(&st);

				stlsoft::c_str_len_a(st, true);
				stlsoft::c_str_len_w(st, true);
				stlsoft::c_str_len(st, true);

				stlsoft::c_str_ptr_a(st, true);
				stlsoft::c_str_ptr_w(st, true);
				stlsoft::c_str_ptr(st, true);

				stlsoft::c_str_ptr_null_a(st, true);
				stlsoft::c_str_ptr_null_w(st, true);
				stlsoft::c_str_ptr_null(st, true);

				stlsoft::c_str_data_a(st, true);
				stlsoft::c_str_data_w(st, true);
				stlsoft::c_str_data(st, true);

			}

			{
				SYSTEMTIME	st;
				FILETIME	ft;

				::GetLocalTime(&st);
				::SystemTimeToFileTime(&st, &ft);

				stlsoft::c_str_len_a(ft, true);
				stlsoft::c_str_len_w(ft, true);
				stlsoft::c_str_len(ft, true);

				stlsoft::c_str_ptr_a(ft, true);
				stlsoft::c_str_ptr_w(ft, true);
				stlsoft::c_str_ptr(ft, true);

				stlsoft::c_str_ptr_null_a(ft, true);
				stlsoft::c_str_ptr_null_w(ft, true);
				stlsoft::c_str_ptr_null(ft, true);

				stlsoft::c_str_data_a(ft, true);
				stlsoft::c_str_data_w(ft, true);
				stlsoft::c_str_data(ft, true);

			}


			{
				SYSTEMTIME	st;
				FILETIME	ft;

				::GetLocalTime(&st);
				::SystemTimeToFileTime(&st, &ft);

				const FILETIME		t1		=	ft;
				const SYSTEMTIME	t2		=	st;
				const size_t		len1	=	stlsoft::c_str_len(t1);
				const size_t		len2	=	stlsoft::c_str_len(t2);

				if(len1 != len2)
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}

				if(len1 != stlsoft::c_str_len_a(t1))
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}

				if(len1 != stlsoft::c_str_len_w(t1))
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}

				if(len1 != stlsoft::c_str_len_a(t2))
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}

				if(len1 != stlsoft::c_str_len_w(t2))
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}
			}


			{
				SYSTEMTIME	st;
				FILETIME	ft;

				::GetLocalTime(&st);
				::SystemTimeToFileTime(&st, &ft);

				const FILETIME		t1		=	ft;
				const SYSTEMTIME	t2		=	st;
				const size_t		len1	=	stlsoft::c_str_len(t1);
				const size_t		len2	=	stlsoft::c_str_len(t2);

				if(len1 != len2)
				{
					r->report("c_str_len() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
					bSuccess = false;
				}
				else
				{
					if(0 != ::strcmp(stlsoft::c_str_ptr(t1), stlsoft::c_str_ptr(t2)))
					{
						r->report("c_str_ptr() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::strcmp(stlsoft::c_str_ptr_a(t1), stlsoft::c_str_ptr_a(t2)))
					{
						r->report("c_str_ptr() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::wcscmp(stlsoft::c_str_ptr_w(t1), stlsoft::c_str_ptr_w(t2)))
					{
						r->report("c_str_ptr() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}

					if(0 != ::strcmp(stlsoft::c_str_ptr_null(t1), stlsoft::c_str_ptr_null(t2)))
					{
						r->report("c_str_ptr_null() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::strcmp(stlsoft::c_str_ptr_null_a(t1), stlsoft::c_str_ptr_null_a(t2)))
					{
						r->report("c_str_ptr_null() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::wcscmp(stlsoft::c_str_ptr_null_w(t1), stlsoft::c_str_ptr_null_w(t2)))
					{
						r->report("c_str_ptr_null() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}

					if(0 != ::strncmp(stlsoft::c_str_data(t1), stlsoft::c_str_data(t2), len1))
					{
						r->report("c_str_data() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::strncmp(stlsoft::c_str_data_a(t1), stlsoft::c_str_data_a(t2), len1))
					{
						r->report("c_str_data() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}
					if(0 != ::wcsncmp(stlsoft::c_str_data_w(t1), stlsoft::c_str_data_w(t2), len1))
					{
						r->report("c_str_data() error (for FILETIME and/or SYSTEMTIME)", __LINE__);
						bSuccess = false;
					}

				}
			}


			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_time_string_access(test_winstl_time_string_access);
	} // anonymous namespace

} // namespace unittest
