
// Updated: 12th March 2007

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/filesystem/findfile_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FINDFILE_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		// Test files/directories:
		//
		// ./ffs-test/dir0.ffs
		// ./ffs-test/dir0.ffs/file00.ffs
		// ./ffs-test/dir0.ffs/file01.ffs
		// ./ffs-test/dir1.ffs
		// ./ffs-test/dir1.ffs/file10.ffs
		// ./ffs-test/dir1.ffs/file11.ffs
		namespace
		{
			const char	FFS_TEST[]	=	"ffs-test";

			const char	FFS_DIR0[]	=	"dir0.ffs";
			const char	FFS_DIR1[]	=	"dir1.ffs";
			const char	*FFS_DIRS[] =
			{
					FFS_DIR0
				,	FFS_DIR1
			};

			const char	FFS_FILE00[]	=	"file00.ffs";
			const char	FFS_FILE01[]	=	"file01.ffs";
			const char	FFS_FILE10[]	=	"file10.ffs";
			const char	FFS_FILE11[]	=	"file11.ffs";

			const char	*FFS_DIR0_FILES[] =
			{
					FFS_FILE00
				,	FFS_FILE01
			};

		} // anonymous namespace

		ss_bool_t ffs_create_test_fs_entries(basic_file_path_buffer<char> const& dir)
		{
			typedef filesystem_traits<char> traits_t;

			basic_file_path_buffer<char>	subDir;
			basic_file_path_buffer<char>	file;
			HANDLE							hfile;

			// ./ffs-test
			if( !::CreateDirectory(dir.c_str(), NULL) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}

			// ./ffs-test/dir0.ffs
			::lstrcpyA(&subDir[0], dir.c_str());
			traits_t::ensure_dir_end(&subDir[0]);
			::lstrcatA(&subDir[0], FFS_DIR0);
			if( !::CreateDirectory(subDir.c_str(), NULL) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			// ./ffs-test/dir0.ffs/file00.ffs
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE00);
			if( INVALID_HANDLE_VALUE == (hfile = ::CreateFile(file.c_str(), 0, 0, NULL, CREATE_ALWAYS, 0, NULL)) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			::CloseHandle(hfile);
			// ./ffs-test/dir0.ffs/file01.ffs
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE01);
			if( INVALID_HANDLE_VALUE == (hfile = ::CreateFile(file.c_str(), 0, 0, NULL, CREATE_ALWAYS, 0, NULL)) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			::CloseHandle(hfile);

			// ./ffs-test/dir1.ffs
			::lstrcpyA(&subDir[0], dir.c_str());
			traits_t::ensure_dir_end(&subDir[0]);
			::lstrcatA(&subDir[0], FFS_DIR1);
			if( !::CreateDirectory(subDir.c_str(), NULL) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			// ./ffs-test/dir1.ffs/file10.ffs
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE10);
			if( INVALID_HANDLE_VALUE == (hfile = ::CreateFile(file.c_str(), 0, 0, NULL, CREATE_ALWAYS, 0, NULL)) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			::CloseHandle(hfile);
			// ./ffs-test/dir1.ffs/file11.ffs
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE11);
			if( INVALID_HANDLE_VALUE == (hfile = ::CreateFile(file.c_str(), 0, 0, NULL, CREATE_ALWAYS, 0, NULL)) &&
				ERROR_ALREADY_EXISTS != ::GetLastError())
			{
				return false;
			}
			::CloseHandle(hfile);

			return true;
		}

		void ffs_delete_test_fs_entries(basic_file_path_buffer<char> const& dir)
		{
			typedef filesystem_traits<char> traits_t;

			basic_file_path_buffer<char>	subDir;
			basic_file_path_buffer<char>	file;

			::lstrcpyA(&subDir[0], dir.c_str());
			::lstrcatA(&subDir[0], FFS_DIR1);
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE10);
			::DeleteFile(file.c_str());
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE11);
			::DeleteFile(file.c_str());
			::RemoveDirectory(subDir.c_str());

			::lstrcpyA(&subDir[0], dir.c_str());
			::lstrcatA(&subDir[0], FFS_DIR0);
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE00);
			::DeleteFile(file.c_str());
			::lstrcpyA(&file[0], &subDir[0]);
			traits_t::ensure_dir_end(&file[0]);
			::lstrcatA(&file[0], FFS_FILE01);
			::DeleteFile(file.c_str());
			::RemoveDirectory(subDir.c_str());

			::RemoveDirectory(dir.c_str());
		}

		ss_bool_t ffs_is_entry_path_equal_ffs_directory_plus_entry_name(findfile_sequence_a const& ffs, findfile_sequence_a::value_type const& entry)
		{
			typedef filesystem_traits<char> traits_t;

			basic_file_path_buffer<char>	path0;
			basic_file_path_buffer<char>	path1;

			traits_t::str_copy(&path0[0], ffs.get_directory());
			traits_t::ensure_dir_end(&path0[0]);
			traits_t::str_cat(&path0[0], entry.get_filename());

			traits_t::str_copy(&path1[0], entry.get_path());

			return 0 == traits_t::str_compare_no_case(path0.c_str(), path1.c_str());
		}

		ss_bool_t ffs_test_dot_special_case(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef filesystem_traits<char> traits_t;

			findfile_sequence_a 				ffs(".", ".", findfile_sequence_a::directories);
			findfile_sequence_a::const_iterator b	=	ffs.begin();
			findfile_sequence_a::const_iterator e	=	ffs.end();

			{
				findfile_sequence_a::const_iterator b	=	ffs.begin();
				findfile_sequence_a::const_iterator b2;

				b2	=	b;
				b2	=	b2;
				b	=	b;
				b2	=	ffs.begin();
			}

			if(b == e)
			{
				r->report("findfile_sequence '.' special-case: search returned empty sequence", __LINE__);
				bSuccess = false;
			}
			else
			{
				(*b).is_directory();
				(*b).is_file();
				(*b).is_compressed();
#ifdef FILE_ATTRIBUTE_REPARSE_POINT
				(*b).is_reparse_point();
#endif /* FILE_ATTRIBUTE_REPARSE_POINT */
				(*b).is_read_only();
				(*b).is_system();
				(*b).is_hidden();

				// Filename should be "."

				if(0 != ::lstrcmpA(".", (*b).get_filename()))
				{
					r->report("findfile_sequence '.' special-case: (*).get_filename() does not equal \".\"", __LINE__);
					bSuccess = false;
				}

				// Pathname should be "$(cwd)\."

				basic_file_path_buffer<char>	cwd;
				size_t							cwdLen	=	::GetCurrentDirectoryA(cwd.size(), &cwd[0]);

				if(0 != cwdLen)
				{
					traits_t::ensure_dir_end(&cwd[0]);
					traits_t::str_cat(&cwd[0], ".");

					if(0 != ::lstrcmpA(cwd.c_str(), (*b).get_path()))
					{
						r->report("findfile_sequence '.' special-case: (*).get_path() does not equal \"$(cwd)\\.\"", __LINE__);
						bSuccess = false;
					}
				}
			}

			return bSuccess;
		}

		ss_bool_t ffs_test_absolute_pattern_case(basic_file_path_buffer<char> const& wd, unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef filesystem_traits<char> traits_t;

		// ./ffs-test/dir0.ffs/file00.ffs
		// ./ffs-test/dir0.ffs/file01.ffs

			basic_file_path_buffer<char>	pattern(wd);

			traits_t::ensure_dir_end(&pattern[0]);
			traits_t::str_cat(&pattern[0], "./dir0.ffs/./../dir0.ffs/file0?.ffs");

			findfile_sequence_a 				ffs(pattern.c_str(), findfile_sequence_a::files);
			findfile_sequence_a::const_iterator b	=	ffs.begin();
			findfile_sequence_a::const_iterator e	=	ffs.end();

#if 0
{
findfile_sequence_a::const_iterator b	=	ffs.begin();
findfile_sequence_a::const_iterator e	=	ffs.end();

fprintf(err, "Enumerating contents of %s (%s)\n", current_directory_a().c_str(), ffs.get_directory());

::Sleep(2 * 1000);

for(; b != e; ++b)
{
	fprintf(err, " [%s]\n", (*b).get_path());
}

}
#endif /* 0 */
			if(b == e)
			{
				r->report("findfile_sequence <absolute-pattern> case: search returned empty sequence", __LINE__);
				bSuccess = false;
			}
			else
			{
				// Filename should be "."

				if(0 != ::lstrcmpA("file00.ffs", (*b).get_filename()))
				{
					r->report("findfile_sequence <absolute-pattern> case: (*).get_filename() does not equal \"file0?.ffs\"", __LINE__);
					bSuccess = false;
				}

				if(++b == e)
				{
					r->report("findfile_sequence <absolute-pattern> case: search returned one file, not two", __LINE__);
					bSuccess = false;
				}
				else
				{
					if(0 != ::lstrcmpA("file01.ffs", (*b).get_filename()))
					{
						r->report("findfile_sequence <absolute-pattern> case: (*).get_filename() does not equal \"file0?.ffs\"", __LINE__);
						bSuccess = false;
					}
				}
			}

			return bSuccess;
		}

		ss_bool_t test_winstl_filesystem_findfile_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			typedef filesystem_traits<char> traits_t;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "filesystem/findfile_sequence", __FILE__);

			basic_file_path_buffer<char>	tempDir;

			try
			{
				// 1. Test the ".", "." functionality
				if(!ffs_test_dot_special_case(r))
				{
					bSuccess = false;
				}

				// 2. Create the test files/directories
				if(!GetTempPath(tempDir.size(), &tempDir[0]))
				{
					r->report("findfile_sequence: could not acquire a temporary path", __LINE__);

					return bSuccess;
				}
				else
				{
					traits_t::ensure_dir_end(&tempDir[0]);
					::lstrcatA(&tempDir[0], FFS_TEST);

					if(ffs_create_test_fs_entries(tempDir))
					{
						if(!ffs_test_absolute_pattern_case(tempDir, r))
						{
							bSuccess = false;
						}

						{ // 3. Test the explicit directory search
							findfile_sequence_a 				ffs(tempDir.c_str(), "*.ffs", findfile_sequence_a::directories);
							findfile_sequence_a::const_iterator b	=	ffs.begin();
							findfile_sequence_a::const_iterator e	=	ffs.end();
							size_t								i;

							{
								basic_file_path_buffer<char>	dir0(tempDir);
								basic_file_path_buffer<char>	dir1;

								traits_t::str_copy(&dir1[0], ffs.get_directory());

								traits_t::ensure_dir_end(&dir0[0]);
								traits_t::ensure_dir_end(&dir1[0]);

								if(0 != ::lstrcmpiA(dir0.c_str(), dir1.c_str()))
								{
									r->report("findfile_sequence (explicit directory): get_directory() returns invalid value", __LINE__);
									bSuccess = false;
								}
							}

							for(i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(FFS_DIRS); ++i)
							{
								if(b == e)
								{
									r->report("findfile_sequence (explicit directory): directory search empty", __LINE__);
									bSuccess = false;
								}
								else
								{
									if(0 != ::lstrcmpA(FFS_DIRS[i], (*b).get_filename()))
									{
										r->report("findfile_sequence (explicit directory): not expected entry filename", __LINE__);
										bSuccess = false;
									}

									basic_file_path_buffer<char>	dir2(tempDir);

									traits_t::ensure_dir_end(&dir2[0]);
									traits_t::str_cat(&dir2[0], (*b).get_filename());

									if(0 != ::lstrcmpA(dir2.c_str(), (*b).get_path()))
									{
										r->report("findfile_sequence (explicit directory): not expected entry path", __LINE__);
										bSuccess = false;
									}

									if(!ffs_is_entry_path_equal_ffs_directory_plus_entry_name(ffs, *b))
									{
										r->report("findfile_sequence (explicit directory): entry::path != ffs directory+entry::filename", __LINE__);
										bSuccess = false;
									}
								}

								if(bSuccess)
								{
									++b;
								}
							}
						}

						{ // 4. Test the implicit directory search
							basic_file_path_buffer<char>	cwd;
							size_t							cwdLen	=	::GetCurrentDirectoryA(cwd.size(), &cwd[0]);

							if(0 != cwdLen)
							{
								::SetCurrentDirectoryA(tempDir.c_str());

								findfile_sequence_a 				ffs("*.ffs", findfile_sequence_a::directories);
								findfile_sequence_a::const_iterator b	=	ffs.begin();
								findfile_sequence_a::const_iterator e	=	ffs.end();
								size_t								i;

								{
									basic_file_path_buffer<char>	dir0(tempDir);
									basic_file_path_buffer<char>	dir1;

									traits_t::str_copy(&dir1[0], ffs.get_directory());

									traits_t::ensure_dir_end(&dir0[0]);
									traits_t::ensure_dir_end(&dir1[0]);

									if(0 != ::lstrcmpiA(dir0.c_str(), dir1.c_str()))
									{
										r->report("findfile_sequence (implicit directory): get_directory() returns invalid value", __LINE__);
										bSuccess = false;
									}
								}

								for(i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(FFS_DIRS); ++i)
								{
									if(b == e)
									{
										r->report("findfile_sequence (implicit	directory): directory search empty", __LINE__);
										bSuccess = false;
									}
									else
									{
										if(0 != ::lstrcmpA(FFS_DIRS[i], (*b).get_filename()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry filename", __LINE__);
											bSuccess = false;
										}

										basic_file_path_buffer<char>	dir2(tempDir);

										traits_t::ensure_dir_end(&dir2[0]);
										traits_t::str_cat(&dir2[0], (*b).get_filename());

										if(0 != ::lstrcmpA(dir2.c_str(), (*b).get_path()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry path", __LINE__);
											bSuccess = false;
										}

										if(!ffs_is_entry_path_equal_ffs_directory_plus_entry_name(ffs, *b))
										{
											r->report("findfile_sequence (implicit directory): entry::path != ffs directory+entry::filename", __LINE__);
											bSuccess = false;
										}
									}

									if(bSuccess)
									{
										++b;
									}
								}

								::SetCurrentDirectoryA(cwd.c_str());
							}
						}

						{ // 5. Test the implicit directory search of files, with pattern containing subdir
							basic_file_path_buffer<char>	cwd;
							size_t							cwdLen	=	::GetCurrentDirectoryA(cwd.size(), &cwd[0]);

							if(0 != cwdLen)
							{
								::SetCurrentDirectoryA(tempDir.c_str());

								basic_file_path_buffer<char>  pattern;

								traits_t::str_copy(&pattern[0], FFS_DIR0);
								traits_t::ensure_dir_end(&pattern[0]);
								traits_t::str_cat(&pattern[0], "*.ffs");

								findfile_sequence_a 				ffs(pattern.c_str(), findfile_sequence_a::files);
								findfile_sequence_a::const_iterator b	=	ffs.begin();
								findfile_sequence_a::const_iterator e	=	ffs.end();
								size_t								i;

								{
									basic_file_path_buffer<char>	dir0(tempDir);
									basic_file_path_buffer<char>	dir1;

									traits_t::str_copy(&dir1[0], ffs.get_directory());

									traits_t::ensure_dir_end(&dir0[0]);
									traits_t::ensure_dir_end(&dir1[0]);

									if(0 != ::lstrcmpiA(dir0.c_str(), dir1.c_str()))
									{
										r->report("findfile_sequence (implicit directory): get_directory() returns invalid value", __LINE__);
										bSuccess = false;
									}
								}

								for(i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(FFS_DIR0_FILES); ++i)
								{
									if(b == e)
									{
										r->report("findfile_sequence (implicit	directory): directory search empty", __LINE__);
										bSuccess = false;
									}
									else
									{
										if(0 != ::lstrcmpA(FFS_DIR0_FILES[i], (*b).get_filename()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry filename", __LINE__);
											bSuccess = false;
										}

#if 0
										basic_file_path_buffer<char>	dir2(tempDir);

										traits_t::ensure_dir_end(&dir2[0]);
										traits_t::str_cat(&dir2[0], (*b).get_filename());

										if(0 != ::lstrcmpA(dir2.c_str(), (*b).get_path()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry path", __LINE__);
											bSuccess = false;
										}

										if(!ffs_is_entry_path_equal_ffs_directory_plus_entry_name(ffs, *b))
										{
											r->report("findfile_sequence (implicit directory): entry::path != ffs directory+entry::filename", __LINE__);
											bSuccess = false;
										}
#endif /* 0 */
									}

									if(bSuccess)
									{
										++b;
									}
								}

								::SetCurrentDirectoryA(cwd.c_str());
							}
						}

						{ // 5. Test the explicit NULL directory search
							basic_file_path_buffer<char>	cwd;
							size_t							cwdLen	=	::GetCurrentDirectoryA(cwd.size(), &cwd[0]);

							if(0 != cwdLen)
							{
								::SetCurrentDirectoryA(tempDir.c_str());

								findfile_sequence_a 				ffs(NULL, "*.ffs", findfile_sequence_a::directories);
								findfile_sequence_a::const_iterator b	=	ffs.begin();
								findfile_sequence_a::const_iterator e	=	ffs.end();
								size_t								i;

								{
									basic_file_path_buffer<char>	dir0(tempDir);
									basic_file_path_buffer<char>	dir1;

									traits_t::str_copy(&dir1[0], ffs.get_directory());

									traits_t::ensure_dir_end(&dir0[0]);
									traits_t::ensure_dir_end(&dir1[0]);

									if(0 != ::lstrcmpiA(dir0.c_str(), dir1.c_str()))
									{
										r->report("findfile_sequence (implicit directory): get_directory() returns invalid value", __LINE__);
										bSuccess = false;
									}
								}

								for(i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(FFS_DIRS); ++i)
								{
									if(b == e)
									{
										r->report("findfile_sequence (implicit	directory): directory search empty", __LINE__);
										bSuccess = false;
									}
									else
									{
										if(0 != ::lstrcmpA(FFS_DIRS[i], (*b).get_filename()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry filename", __LINE__);
											bSuccess = false;
										}

										basic_file_path_buffer<char>	dir2(tempDir);

										traits_t::ensure_dir_end(&dir2[0]);
										traits_t::str_cat(&dir2[0], (*b).get_filename());

										if(0 != ::lstrcmpA(dir2.c_str(), (*b).get_path()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry path", __LINE__);
											bSuccess = false;
										}

										if(!ffs_is_entry_path_equal_ffs_directory_plus_entry_name(ffs, *b))
										{
											r->report("findfile_sequence (implicit directory): entry::path != ffs directory+entry::filename", __LINE__);
											bSuccess = false;
										}
									}

									if(bSuccess)
									{
										++b;
									}
								}

								::SetCurrentDirectoryA(cwd.c_str());
							}
						}

						{ // 6. Test the explicit empty directory search
							basic_file_path_buffer<char>	cwd;
							size_t							cwdLen	=	::GetCurrentDirectoryA(cwd.size(), &cwd[0]);

							if(0 != cwdLen)
							{
								::SetCurrentDirectoryA(tempDir.c_str());

								findfile_sequence_a 				ffs("", "*.ffs", findfile_sequence_a::directories);
								findfile_sequence_a::const_iterator b	=	ffs.begin();
								findfile_sequence_a::const_iterator e	=	ffs.end();
								size_t								i;

								{
									basic_file_path_buffer<char>	dir0(tempDir);
									basic_file_path_buffer<char>	dir1;

									traits_t::str_copy(&dir1[0], ffs.get_directory());

									traits_t::ensure_dir_end(&dir0[0]);
									traits_t::ensure_dir_end(&dir1[0]);

									if(0 != ::lstrcmpiA(dir0.c_str(), dir1.c_str()))
									{
										r->report("findfile_sequence (implicit directory): get_directory() returns invalid value", __LINE__);
										bSuccess = false;
									}
								}

								for(i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(FFS_DIRS); ++i)
								{
									if(b == e)
									{
										r->report("findfile_sequence (implicit	directory): directory search empty", __LINE__);
										bSuccess = false;
									}
									else
									{
										if(0 != ::lstrcmpA(FFS_DIRS[i], (*b).get_filename()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry filename", __LINE__);
											bSuccess = false;
										}

										basic_file_path_buffer<char>	dir2(tempDir);

										traits_t::ensure_dir_end(&dir2[0]);
										traits_t::str_cat(&dir2[0], (*b).get_filename());

										if(0 != ::lstrcmpA(dir2.c_str(), (*b).get_path()))
										{
											r->report("findfile_sequence (implicit	directory): not expected entry path", __LINE__);
											bSuccess = false;
										}

										if(!ffs_is_entry_path_equal_ffs_directory_plus_entry_name(ffs, *b))
										{
											r->report("findfile_sequence (implicit directory): entry::path != ffs directory+entry::filename", __LINE__);
											bSuccess = false;
										}
									}

									if(bSuccess)
									{
										++b;
									}
								}

								::SetCurrentDirectoryA(cwd.c_str());
							}
						}


					}
				}
			}
			catch(...)
			{
				ffs_delete_test_fs_entries(tempDir);

				throw;
			}

			ffs_delete_test_fs_entries(tempDir);

			if( 0 == ::GetTickCount() &&
				(::Sleep(1000), 0 == ::GetTickCount()))
			{
				findfile_sequence_a 	ffs1("*.*");
				findfile_sequence_a 	ffs2("*.*", findfile_sequence_a::files);
				findfile_sequence_a 	ffs3("*.*", findfile_sequence_a::files | findfile_sequence_a::directories);

				findfile_sequence_a 	ffs4(".", "*.*");
				findfile_sequence_a 	ffs5(".", "*.*", findfile_sequence_a::files);
				findfile_sequence_a 	ffs6(".", "*.*", findfile_sequence_a::files | findfile_sequence_a::directories);

				findfile_sequence_a 	ffs7(".", "*.*", ';');
				findfile_sequence_a 	ffs8(".", "*.*", ';', findfile_sequence_a::files);
				findfile_sequence_a 	ffs9(".", "*.*", ';', findfile_sequence_a::files | findfile_sequence_a::directories);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_filesystem_findfile_sequence(test_winstl_filesystem_findfile_sequence);
	} // anonymous namespace

} // namespace unittest
