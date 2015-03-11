

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_HPP_WINDOWS_MAJOR    1
# define WINSTL_VER_WINSTL_HPP_WINDOWS_MINOR    1
# define WINSTL_VER_WINSTL_HPP_WINDOWS_REVISION 1
# define WINSTL_VER_WINSTL_HPP_WINDOWS_EDIT     4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */


namespace stlsoft
{

namespace winstl_project
{

    template <ss_typename_param_k S>
    inline HMODULE LoadLibraryA(S const &path)
    {
        return ::LoadLibraryA(stlsoft_ns_qual(c_str_ptr_a)(path));
    }
    template <ss_typename_param_k S>
    inline HMODULE LoadLibraryW(S const &path)
    {
        return ::LoadLibraryA(stlsoft_ns_qual(c_str_ptr_w)(path));
    }

#ifndef LoadLibrary /* Just in case windows.h has _not_ trampled all over the global namespace */
    template <ss_typename_param_k S>
    inline HMODULE LoadLibrary(S const &path)
    {
# ifdef UNICODE
        return LoadLibraryW(path);
# else /* ? UNICODE */
        return LoadLibraryA(path);
# endif // !UNICODE
    }
#endif /* LoadLibrary */


    template <ss_typename_param_k S>
    inline HANDLE CreateFileA(  S const &fileName
                            ,   IN DWORD dwDesiredAccess
                            ,   IN DWORD dwShareMode
                            ,   IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
                            ,   IN DWORD dwCreationDisposition
                            ,   IN DWORD dwFlagsAndAttributes
                            ,   IN HANDLE hTemplateFile)
    {
        return ::CreateFileA(stlsoft_ns_qual(c_str_ptr_a)(fileName), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    }
    template <ss_typename_param_k S>
    inline HANDLE CreateFileW(  S const &fileName
                            ,   IN DWORD dwDesiredAccess
                            ,   IN DWORD dwShareMode
                            ,   IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
                            ,   IN DWORD dwCreationDisposition
                            ,   IN DWORD dwFlagsAndAttributes
                            ,   IN HANDLE hTemplateFile)
    {
        return ::CreateFileW(stlsoft_ns_qual(c_str_ptr_w)(fileName), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    }

#ifndef CreateFile /* Just in case windows.h has _not_ trampled all over the global namespace */
    template <ss_typename_param_k S>
    inline HMODULE CreateFile(  S const &fileName
                            ,   IN DWORD dwDesiredAccess
                            ,   IN DWORD dwShareMode
                            ,   IN LPSECURITY_ATTRIBUTES lpSecurityAttributes
                            ,   IN DWORD dwCreationDisposition
                            ,   IN DWORD dwFlagsAndAttributes
                            ,   IN HANDLE hTemplateFile)
    {
# ifdef UNICODE
        return CreateFileW(fileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
# else /* ? UNICODE */
        return CreateFileA(fileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
# endif // !UNICODE
    }
#endif /* LoadLibrary */


} // namespace winstl_project

} // namespace stlsoft

