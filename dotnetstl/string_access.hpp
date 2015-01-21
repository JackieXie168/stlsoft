
#ifndef DOTNETSTL_INCL_DOTNETSTL_HPP_DOTNETSTL
# include <dotnetstl/dotnetstl.hpp>
#endif /* !DOTNETSTL_INCL_DOTNETSTL_HPP_DOTNETSTL */
#ifndef DOTNETSTL_INCL_DOTNETSTL_HPP_STRING_ACCESSOR
# include <dotnetstl/string_accessor.hpp>
#endif /* !DOTNETSTL_INCL_DOTNETSTL_HPP_STRING_ACCESSOR */

namespace stlsoft
{
    namespace dotnetstl_project
    {
        namespace impl
        {
            typedef c_string_accessor<char>     accessor_a_t;
            typedef c_string_accessor<wchar_t>  accessor_w_t;
#ifdef UNICODE
            typedef accessor_w_t                accessor_t_t;
#else /* ? UNICODE */
            typedef accessor_a_t                accessor_t_t;
#endif /* UNICODE */

#if defined(DOTNETSTL_HAT_SYNTAX_SUPPORT)
            typedef System::String const        ^string_pointer_const_type;
            typedef System::String              ^string_pointer_type;
#else /* DOTNETSTL_HAT_SYNTAX_SUPPORT */
            typedef System::String const        *string_pointer_const_type;
            typedef System::String              *string_pointer_type;
#endif /* DOTNETSTL_HAT_SYNTAX_SUPPORT */

        } // namespace impl


        inline size_t c_str_len(impl::string_pointer_const_type s)
        {
#if defined(DOTNETSTL_HAT_SYNTAX_SUPPORT)
            if(nullptr == s)
#else /* DOTNETSTL_HAT_SYNTAX_SUPPORT */
            if(NULL == s)
#endif /* DOTNETSTL_HAT_SYNTAX_SUPPORT */
            {
                return 0;
            }
            else
            {
                impl::string_pointer_type   s_ =   const_cast<impl::string_pointer_type>(s);

#if defined(DOTNETSTL_HAT_SYNTAX_SUPPORT)
                return static_cast<size_t>(s_->Length);
#else /* DOTNETSTL_HAT_SYNTAX_SUPPORT */
                return static_cast<size_t>(s_->get_Length());
#endif /* DOTNETSTL_HAT_SYNTAX_SUPPORT */
            }
        }

        inline impl::accessor_a_t c_str_ptr_a(impl::string_pointer_const_type s)
        {
            return impl::accessor_a_t(s);
        }

        inline impl::accessor_w_t c_str_ptr_w(impl::string_pointer_const_type s)
        {
            return impl::accessor_w_t(s);
        }

        inline impl::accessor_t_t c_str_ptr(impl::string_pointer_const_type s)
        {
            return impl::accessor_t_t(s);
        }

        inline impl::accessor_a_t c_str_data_a(impl::string_pointer_const_type s)
        {
            return c_str_ptr_a(s);
        }

        inline impl::accessor_w_t c_str_data_w(impl::string_pointer_const_type s)
        {
            return c_str_ptr_w(s);
        }

        inline impl::accessor_t_t c_str_data(impl::string_pointer_const_type s)
        {
            return c_str_ptr(s);
        }



    }

    using dotnetstl_project::c_str_len;
    using dotnetstl_project::c_str_ptr_a;
    using dotnetstl_project::c_str_ptr_w;
    using dotnetstl_project::c_str_ptr;
    using dotnetstl_project::c_str_data_a;
    using dotnetstl_project::c_str_data_w;
    using dotnetstl_project::c_str_data;
}
