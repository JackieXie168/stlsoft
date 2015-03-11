
#include <stlsoft/stlsoft.h>

#include <functional>

namespace stlsoft
{

#ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

    template <typename T>
    struct ref2ptr_1_CDECL_void_t
        : stlsoft_ns_qual_std(unary_function)<T*, void>
    {
    public:
        ref2ptr_1_CDECL_void_t(void (STLSOFT_CDECL *p)(T*))
            : m_p(p)
        {}

    public:
        void operator ()(T &t) const
        {
            (*m_p)(&t);
        }

    private:
        void (STLSOFT_CDECL *m_p)(T*);
    };
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
    template <typename T>
    struct ref2ptr_1_FASTCALL_void_t
        : stlsoft_ns_qual_std(unary_function)<T*, void>
    {
    public:
        ref2ptr_1_FASTCALL_void_t(void (STLSOFT_FASTCALL *p)(T*))
            : m_p(p)
        {}

    public:
        void operator ()(T &t) const
        {
            (*m_p)(&t);
        }

    private:
        void (STLSOFT_FASTCALL *m_p)(T*);
    };
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    template <typename T>
    struct ref2ptr_1_STDCALL_void_t
        : stlsoft_ns_qual_std(unary_function)<T*, void>
    {
    public:
        ref2ptr_1_STDCALL_void_t(void (STLSOFT_STDCALL *p)(T*))
            : m_p(p)
        {}

    public:
        void operator ()(T &t) const
        {
            (*m_p)(&t);
        }

    private:
        void (STLSOFT_STDCALL *m_p)(T*);
    };
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


    template <typename T, typename R>
    struct ref2ptr_1_CDECL_t
        : stlsoft_ns_qual_std(unary_function)<T*, R>
    {
    public:
        ref2ptr_1_CDECL_t(R (STLSOFT_CDECL *p)(T*))
            : m_p(p)
        {}

    public:
        R operator ()(T &t) const
        {
            return (*m_p)(&t);
        }

    private:
        R (STLSOFT_CDECL *m_p)(T*);
    };
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
    template <typename T, typename R>
    struct ref2ptr_1_FASTCALL_t
        : stlsoft_ns_qual_std(unary_function)<T*, R>
    {
    public:
        ref2ptr_1_FASTCALL_t(R (STLSOFT_FASTCALL *p)(T*))
            : m_p(p)
        {}

    public:
        R operator ()(T &t) const
        {
            return (*m_p)(&t);
        }

    private:
        R (STLSOFT_FASTCALL *m_p)(T*);
    };
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    template <typename T, typename R>
    struct ref2ptr_1_STDCALL_t
        : stlsoft_ns_qual_std(unary_function)<T*, R>
    {
    public:
        ref2ptr_1_STDCALL_t(R (STLSOFT_STDCALL *p)(T*))
            : m_p(p)
        {}

    public:
        R operator ()(T &t) const
        {
            return (*m_p)(&t);
        }

    private:
        R (STLSOFT_STDCALL *m_p)(T*);
    };
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

    template <typename T, typename R>
    inline ref2ptr_1_CDECL_t<T, R> ref2ptr(R (STLSOFT_CDECL *p)(T*))
    {
        return ref2ptr_1_CDECL_t<T, R>(p);
    }
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
    template <typename T, typename R>
    inline ref2ptr_1_FASTCALL_t<T, R> ref2ptr(R (STLSOFT_FASTCALL *p)(T*))
    {
        return ref2ptr_1_FASTCALL_t<T, R>(p);
    }
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    template <typename T, typename R>
    inline ref2ptr_1_STDCALL_t<T, R> ref2ptr(R (STLSOFT_STDCALL *p)(T*))
    {
        return ref2ptr_1_STDCALL_t<T, R>(p);
    }
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#ifdef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID
    template <typename T>
    inline ref2ptr_1_CDECL_t<T, void> ref2ptr_void(void (STLSOFT_CDECL *p)(T*))
    {
        return ref2ptr_1_CDECL_t<T, void>(p);
    }
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
    template <typename T>
    inline ref2ptr_1_FASTCALL_t<T, void> ref2ptr_void(void (STLSOFT_FASTCALL *p)(T*))
    {
        return ref2ptr_1_FASTCALL_t<T, void>(p);
    }
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    template <typename T>
    inline ref2ptr_1_STDCALL_t<T, void> ref2ptr_void(void (STLSOFT_STDCALL *p)(T*))
    {
        return ref2ptr_1_STDCALL_t<T, void>(p);
    }
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
    template <typename T>
    inline ref2ptr_1_CDECL_void_t<T> ref2ptr_void(void (STLSOFT_CDECL *p)(T*))
    {
        return ref2ptr_1_CDECL_void_t<T>(p);
    }
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
    template <typename T>
    inline ref2ptr_1_FASTCALL_void_t<T> ref2ptr_void(void (STLSOFT_FASTCALL *p)(T*))
    {
        return ref2ptr_1_FASTCALL_void_t<T>(p);
    }
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
    template <typename T>
    inline ref2ptr_1_STDCALL_void_t<T> ref2ptr_void(void (STLSOFT_STDCALL *p)(T*))
    {
        return ref2ptr_1_STDCALL_void_t<T>(p);
    }
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


} // namespace stlsoft
