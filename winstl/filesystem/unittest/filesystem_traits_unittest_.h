
// Updated: 31st May 2006

#if !defined(WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS)
# error This file cannot be directly included, and should only be included within winstl/filesystem/filesystem_traits.hpp
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        typedef filesystem_traits<char>     traits_a_t;
        typedef filesystem_traits<wchar_t>  traits_w_t;

        ss_bool_t test_get_full_path_name(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            char        sz1[1 + 4096];
            char        sz2[1 + 4096];
            char        cwd[1 + 4096];

            if(0 == ::GetCurrentDirectoryA(STLSOFT_NUM_ELEMENTS(cwd), cwd))
            {
                r->report("Failed to get current directory", __LINE__);
                bSuccess = false;
            }
            else
            {
                char        *pFile1;
                char        *pFile2;
                ss_size_t   cch1    =   traits_a_t::get_full_path_name(".", STLSOFT_NUM_ELEMENTS(sz1), sz1, &pFile1);
                ss_size_t   cch2    =   traits_a_t::get_full_path_name(cwd, STLSOFT_NUM_ELEMENTS(sz2), sz2, &pFile2);

                STLSOFT_SUPPRESS_UNUSED(cch1);
                STLSOFT_SUPPRESS_UNUSED(cch2);

                if( 0 != traits_a_t::str_compare(sz1, sz2) ||
                    0 != traits_a_t::str_compare(pFile1, pFile2))
                {
                    r->report("Directory equivalence failed", __LINE__);
                    bSuccess = false;
                }

                traits_a_t::str_cat(traits_a_t::ensure_dir_end(cwd), "..\\..");

                cch1    =   traits_a_t::get_full_path_name("..\\..", STLSOFT_NUM_ELEMENTS(sz1), sz1, &pFile1);
                cch2    =   traits_a_t::get_full_path_name(cwd, STLSOFT_NUM_ELEMENTS(sz2), sz2, &pFile2);

                STLSOFT_SUPPRESS_UNUSED(cch1);
                STLSOFT_SUPPRESS_UNUSED(cch2);

                if( 0 != traits_a_t::str_compare(sz1, sz2) ||
                    0 != traits_a_t::str_compare(pFile1, pFile2))
                {
                    r->report("Directory equivalence failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        ss_bool_t test_string_handling(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            char    buff1[101];
//            char    buff2[101];
//            char    buff3[101];

            char    *psz1;
//            char    *psz2;
//            char    *psz3;

            psz1 = traits_a_t::str_copy(buff1, "Hello");
            if(0 != strcmp(buff1, "Hello"))
            {
                r->report("str_copy() failure", __LINE__);
                bSuccess = false;
            }
            if(0 != strcmp(buff1, psz1))
            {
                r->report("str_copy() failure", __LINE__);
                bSuccess = false;
            }
#if 0
    /* static char_type    *str_copy(char_type *dest, char_type const *src) */
    static char_type    *str_n_copy(char_type *dest, char_type const *src, size_type cch);
    static char_type    *str_cat(char_type *dest, char_type const *src);
    static char_type    *str_n_cat(char_type *dest, char_type const *src, size_type cch);
    static int_type     str_compare(char_type const *s1, char_type const *s2);
    static int_type     str_compare_no_case(char_type const *s1, char_type const *s2);
    static size_type    str_len(char_type const *src);
    static char_type    *str_chr(char_type const *s, char_type ch);
    static char_type    *str_rchr(char_type const *s, char_type ch);
    static char_type    *str_str(char_type const *s, char_type const *sub);
#endif /* 0 */

            ;

            return bSuccess;
        }

        ss_bool_t test_filesystem_entry_names(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            if(!test_get_full_path_name(r))
            {
                bSuccess = false;
            }

#if 0
    static char_type    *ensure_dir_end(char_type *dir);
    static char_type    *remove_dir_end(char_type *dir);
    static bool_type    has_dir_end(char_type const *dir);
#endif /* 0 */

            // has_dir_end()
            {
                static const char   *ended_dirs[] =
                {
                        "\\"
                    ,   "/"
                    ,   "a\\"
                    ,   "a/"
                    ,   "\\a\\"
                    ,   "/a/"
                    ,   "H:\\"
                    ,   "H:/"
                    ,   "H:a\\"
                    ,   "H:a/"
                    ,   "\\\\a\\"
                    ,   "\\\\a\b\\"
                    ,   "\\\\a\b/"
                };

                static const char   *unended_dirs[] =
                {
                        "a"
                    ,   "a"
                    ,   "\\a"
                    ,   "/a"
                    ,   "H:"
                    ,   "H:"
                    ,   "H:a"
                    ,   "H:a"
                    ,   "H:\\a"
                    ,   "H:/a"
                    ,   "\\\\a"
                };

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ended_dirs); ++i)
                {
                    if(!traits_a_t::has_dir_end(ended_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" not identified by has_dir_end()", ended_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(unended_dirs); ++i)
                {
                    if(traits_a_t::has_dir_end(unended_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" wrongly identified by has_dir_end()", unended_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}
            }

#if 0
    /* static bool_type    is_dots(char_type const *dir); */
    /* static bool_type    is_path_rooted(char_type const *path); */
    /* static bool_type    is_path_absolute(char_type const *path); */
    /* static bool_type    is_path_UNC(char_type const *path); */
    /* static bool_type    is_path_name_separator(char_type ch); */
#endif /* 0 */


            // is_dots()
            if(!traits_a_t::is_dots("."))
            {
                r->report("Failed to identify \".\" as a dots directory", __LINE__);
                bSuccess = false;
            }
            if(!traits_a_t::is_dots(".."))
            {
                r->report("Failed to identify \".\" as a dots directory", __LINE__);
                bSuccess = false;
            }
            if(traits_a_t::is_dots(".a"))
            {
                r->report("Falsely identified \".a\" as a dots directory", __LINE__);
                bSuccess = false;
            }
            if(traits_a_t::is_dots("..a"))
            {
                r->report("Falsely identified \"..a\" as a dots directory", __LINE__);
                bSuccess = false;
            }
            if(traits_a_t::is_dots("a."))
            {
                r->report("Falsely identified \"a.\" as a dots directory", __LINE__);
                bSuccess = false;
            }
            if(traits_a_t::is_dots("..a"))
            {
                r->report("Falsely identified \"a..\" as a dots directory", __LINE__);
                bSuccess = false;
            }

            // is_path_rooted()
            {
                static const char   *rooted_dirs[] =
                {
                        "\\"
                    ,   "/"
                    ,   "\\a"
                    ,   "/a"
                    ,   "\\a\\"
                    ,   "/a/"
                    ,   "H:\\"
                    ,   "H:/"
                    ,   "H:\\a"
                    ,   "H:/a"
                    ,   "\\\\a"
                    ,   "\\\\a\\"
                    ,   "\\\\a\b\\"
                    ,   "\\\\a\b/"
                };

                static const char   *unrooted_dirs[] =
                {
                        "a"
                    ,   "a"
                    ,   "a\\"
                    ,   "a/"
                    ,   "H:"
                    ,   "H:"
                    ,   "H:a"
                    ,   "H:a"
                    ,   "H:a\\"
                    ,   "H:a/"
                };

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(rooted_dirs); ++i)
                {
                    if(!traits_a_t::is_path_rooted(rooted_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" not identified by is_path_rooted()", rooted_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(unrooted_dirs); ++i)
                {
                    if(traits_a_t::is_path_rooted(unrooted_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" wrongly identified by is_path_rooted()", unrooted_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}
            }

            // is_path_absolute()
            {
                static const char   *absolute_dirs[] =
                {
                        "H:\\"
                    ,   "H:/"
                    ,   "H:\\a"
                    ,   "H:/a"
                    ,   "\\\\a"
                    ,   "\\\\a\\"
                    ,   "\\\\a\b\\"
                    ,   "\\\\a\b/"
                };

                static const char   *unabsolute_dirs[] =
                {
                        "a"
                    ,   "a"
                    ,   "a\\"
                    ,   "a/"
                    ,   "H:"
                    ,   "H:"
                    ,   "H:a"
                    ,   "H:a"
                    ,   "H:a\\"
                    ,   "H:a/"
                    ,   "\\"
                    ,   "/"
                    ,   "\\a"
                    ,   "/a"
                    ,   "\\a\\"
                    ,   "/a/"
                };

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(absolute_dirs); ++i)
                {
                    if(!traits_a_t::is_path_absolute(absolute_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" not identified by is_path_absolute()", absolute_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(unabsolute_dirs); ++i)
                {
                    if(traits_a_t::is_path_absolute(unabsolute_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" wrongly identified by is_path_absolute()", unabsolute_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}
            }

            // is_path_UNC()
            {
                static const char   *UNC_dirs[] =
                {
                        "\\\\a"
                    ,   "\\\\a\\"
                    ,   "\\\\a\b\\"
                    ,   "\\\\a\b/"
                };

                static const char   *unUNC_dirs[] =
                {
                        "a"
                    ,   "a"
                    ,   "a\\"
                    ,   "a/"
                    ,   "H:"
                    ,   "H:"
                    ,   "H:a"
                    ,   "H:a"
                    ,   "H:a\\"
                    ,   "H:a/"
                    ,   "H:\\"
                    ,   "H:/"
                    ,   "H:\\a"
                    ,   "H:/a"
                    ,   "\\"
                    ,   "/"
                    ,   "\\a"
                    ,   "/a"
                    ,   "\\a\\"
                    ,   "/a/"
                };

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(UNC_dirs); ++i)
                {
                    if(!traits_a_t::is_path_UNC(UNC_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" not identified by is_path_UNC()", UNC_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}

                { for(size_t i = 0; i < STLSOFT_NUM_ELEMENTS(unUNC_dirs); ++i)
                {
                    if(traits_a_t::is_path_UNC(unUNC_dirs[i]))
                    {
                        char    message[101];

                        wsprintf(message, "\"%s\" wrongly identified by is_path_UNC()", unUNC_dirs[i]);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }}
            }

            // is_path_name_separator()

            { for(traits_a_t::char_type ch = 0; ch <= ~static_cast<traits_a_t::char_type>(0); ++ch)
            {
                if(traits_a_t::is_path_name_separator(ch))
                {
                    if( '/' != ch &&
                        '\\' != ch)
                    {
                        char    message[101];

                        wsprintf(message, "'%c' (%d) not identified as a path name separator", ch, ch);

                        r->report(message, __LINE__);
                        bSuccess = false;
                    }
                }
                else
                {
                    if('/' == ch)
                    {
                        r->report("'/' not identified as a path name separator", __LINE__);
                        bSuccess = false;
                    }
                    if('\\' == ch)
                    {
                        r->report("'\' not identified as a path name separator", __LINE__);
                        bSuccess = false;
                    }
                }
            }}

#if 0
    static char_type    path_separator();
    static char_type    path_name_separator();
    static char_type const *pattern_all();
    static size_type    path_max();
#endif /* 0 */

#if 0
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer, char_type **ppFile);
    static size_type    get_full_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
    static size_type    get_short_path_name(char_type const *fileName, size_type cchBuffer, char_type *buffer);
#endif /* 0 */


            ;

            return bSuccess;
        }

        ss_bool_t test_filesystem_enumeration(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            STLSOFT_SUPPRESS_UNUSED(r);

#if 0
    static HANDLE       find_first_file(char_type const *spec, find_data_type *findData);
#if _WIN32_WINNT >= 0x0400
    static HANDLE       find_first_file_ex(char_type const *spec, FINDEX_SEARCH_OPS flags, find_data_type *findData);
#endif /* _WIN32_WINNT >= 0x0400 */
    static bool_type    find_next_file(HANDLE h, find_data_type *findData);
    static void         find_file_close(HANDLE h);
#ifndef _WINSTL_NO_FINDVOLUME_API
    static HANDLE       find_first_volume(char_type *volume_name, size_type cch_volume_name);
    static bool_type    find_next_volume(HANDLE h, char_type *volume_name, size_type cch_volume_name);
    static void         find_volume_close(HANDLE h);
#endif // !_WINSTL_NO_FINDVOLUME_API
#endif /* 0 */


            ;

            return bSuccess;
        }

        ss_bool_t test_module_paths(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            STLSOFT_SUPPRESS_UNUSED(r);

#if 0
    static size_type    get_module_filename(HINSTANCE hModule, char_type *buffer, size_type cchBuffer);
    static size_type    get_system_directory(char_type *buffer, size_type cchBuffer);
    static size_type    get_windows_directory(char_type *buffer, size_type cchBuffer);
#endif /* 0 */


            ;

            return bSuccess;
        }

        ss_bool_t test_dynamic_loading(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            traits_a_t::module_type hModule     =   traits_a_t::load_library("KERNEL32");

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
    static module_type  load_library(char_type const *name);
    static bool_type    free_library(module_type hModule);
    static void         *find_symbol(module_type hModule, char const *symbolName);
#endif /* 0 */

            ;

            return bSuccess;
        }

        ss_bool_t test_filesystem_state(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            STLSOFT_SUPPRESS_UNUSED(r);

#if 0
    static bool_type    set_current_directory(char_type const *dir);
    static size_type    get_current_directory(size_type cchBuffer, char_type *buffer);

    static bool_type    file_exists(char_type const *fileName);
    static bool_type    is_file(char_type const *path);
    static bool_type    is_directory(char_type const *path);
    static bool_type    stat(char_type const *spec, stat_data_type *stat_data);
    static bool_type    fstat(file_handle_type fd, fstat_data_type *fstat_data);
#endif /* 0 */

            ;

            return bSuccess;
        }

        ss_bool_t test_filesystem_control(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            STLSOFT_SUPPRESS_UNUSED(r);

#if 0
    static bool_type    create_directory(char_type const *dir);
    static bool_type    create_directory(char_type const *dir, LPSECURITY_ATTRIBUTES lpsa);
    static bool_type    remove_directory(char_type const *dir);

    static bool_type    unlink_file(char_type const *file);
    static bool_type    delete_file(char_type const *file);
    static bool_type    rename_file(char_type const *currentName, char_type const *newName);
    static bool_type    copy_file(char_type const *sourceName, char_type const *newName, bool_type bFailIfExists = false);
#endif /* 0 */

#if 0
    static file_handle_type create_file(char_type const *fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, HANDLE hTemplateFile);
    static bool_type        close_handle(HANDLE h);
    static bool_type        close_file(file_handle_type h);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static ws_uint64_t      get_file_size(file_handle_type h);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#endif /* 0 */

            ;

            return bSuccess;
        }

        ss_bool_t test_winstl_filesystem_traits(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "filesystem/filesystem_traits", __FILE__);

            if(!test_string_handling(r))
            {
                bSuccess = false;
            }

            if(!test_filesystem_entry_names(r))
            {
                bSuccess = false;
            }

            if(!test_filesystem_enumeration(r))
            {
                bSuccess = false;
            }

            if(!test_module_paths(r))
            {
                bSuccess = false;
            }

            if(!test_dynamic_loading(r))
            {
                bSuccess = false;
            }

            if(!test_filesystem_state(r))
            {
                bSuccess = false;
            }

            if(!test_filesystem_control(r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_filesystem_traits(test_winstl_filesystem_traits);
    }

}// namespace unittest
