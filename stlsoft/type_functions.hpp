/** \file stlsoft/type_functions.hpp Redirects inclusion to . This will be changed in a subsequent release, such that this file will contain the component definitions, and  will contain redirect */

namespace stlsoft
{
    template <ss_typename_param_k T>
    void default_assign(T &t)
    {
        t = T();
    }

} // namespace stlsoft

