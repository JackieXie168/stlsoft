
// Updated: 12th March 2007

#if !defined(INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE)
# error This file cannot be directly included, and should only be included within inetstl/filesystem/findfile_sequence.hpp
#endif /* !INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_inetstl_findfile_sequence_instance(unittest_reporter *r, session &sess, char const* host)
		{
			ss_bool_t				bSuccess	=	true;

			try
			{
				char	sz[201];

				STLSOFT_ASSERT(::strlen(host) < 100);

				::sprintf(&sz[0], "Creating connection to \"%s\"...", host);

				r->report(sz, -1, NULL);

				connection	conn(	sess.get()
								,	host
								,	INTERNET_DEFAULT_FTP_PORT
								,	NULL//"anonynmous"
								,	NULL//""
								,	INTERNET_SERVICE_FTP
								,	INTERNET_FLAG_PASSIVE);

				if(!conn)
				{
					r->report("Connection failed", -1, NULL);
				}
				else
				{
					{
						r->report("Creating findfile search, and enumerating files:", -1, NULL);

						findfile_sequence		ffs(conn, "/", "*.*", findfile_sequence::files);

						findfile_sequence::const_iterator	b	=	ffs.begin();
						findfile_sequence::const_iterator	e	=	ffs.end();
						int 								n	=	0;

						{
							findfile_sequence::const_iterator	b	=	ffs.begin();
							findfile_sequence::const_iterator	b2;

							b2	=	b2;
							b2	=	b;
							b	=	b;
							b2	=	ffs.begin();
						}

						for(; b != e; ++b, ++n)
						{
							if(0 != ::strcmp((*b).c_str(), (*b).get_path()))
							{
								r->report("c_str() returns different value to get_path()", __LINE__);
								bSuccess = false;
							}
							if(NULL == ::strstr((*b).get_path(), (*b).get_filename()))
							{
								r->report("get_filename() not found in get_path()", __LINE__);
								bSuccess = false;
							}
							if((*b).is_directory() == (*b).is_file())
							{
								r->report("is_directory() disagress with is_file()", __LINE__);
								bSuccess = false;
							}

							*b;
						}

						char	sz[101];

						::sprintf(&sz[0], "Number of files: %d\n", n);

						r->report(sz, -1, NULL);
					}

					{
						r->report("Creating findfile search, and enumerating directories:", -1, NULL);

						findfile_sequence		ffs(conn.get(), "/", "*.*", findfile_sequence::directories);

						findfile_sequence::const_iterator	b	=	ffs.begin();
						findfile_sequence::const_iterator	e	=	ffs.end();
						int 								n	=	0;

						for(; b != e; ++b, ++n)
						{
							if(0 != ::strcmp((*b).c_str(), (*b).get_path()))
							{
								r->report("c_str() returns different value to get_path()", __LINE__);
								bSuccess = false;
							}

							*b;
						}

						char	sz[101];

						::sprintf(&sz[0], "Number of directories: %d\n", n);

						r->report(sz, -1, NULL);
					}
				}
			}
			catch(internet_exception &x)
			{
				char	sz[101];

				sprintf(&sz[0], "Error code: %d", static_cast<int>(x.get_error_code()));

				r->report("Component failed. Details following:", -1, NULL);
				r->report(x.what(), -1, NULL);
				r->report(sz, -1, NULL);
			}

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

			return bSuccess;
		}

		ss_bool_t test_inetstl_findfile_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "InetSTL", "filesystem/findfile_sequence", __FILE__);

			try
			{
				r->report("Creating session ...", -1, NULL);

				session 	sess("inetstl-test-session", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

				if(!sess)
				{
					r->report("Session failed", -1, NULL);
				}
				else
				{
					static const char	*hosts[] =
					{
							"ftp.digitalmars.com"
						,	"ftp.microsoft.com"
						,	"ftp.synesis.com.au"
						,
					};

					{ for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(hosts); ++i)
					{
						if(!test_inetstl_findfile_sequence_instance(r, sess, hosts[i]))
						{
							bSuccess = false;
						}
					}}
				}
			}
			catch(internet_exception &x)
			{
				char	sz[101];

				sprintf(&sz[0], "Error code: %d", static_cast<int>(x.get_error_code()));

				r->report("Component failed. Details following:", -1, NULL);
				r->report(x.what(), -1, NULL);
				r->report(sz, -1, NULL);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_inetstl_findfile_sequence(test_inetstl_findfile_sequence);
	} // anonymous namespace

} // namespace unittest
