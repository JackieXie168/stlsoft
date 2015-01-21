
#if !defined(STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS)
# error This file cannot be directly included, and should only be included within stlsoft/ptr_access.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_PTR_ACCESS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_ptr_access(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "ptr_access", __FILE__);

			int 	i;
			void	*p	=	&i;

			if(get_ptr(p) != p)
			{
				r->report("get_ptr(void*) failed", __LINE__);
				bSuccess = false;
			}

#ifndef _STLSOFT_PTR_ACCESS_NO_AUTO_PTR
			stlsoft_ns_qual_std(auto_ptr)<int>	api(new int(1));

			if(get_ptr(api) != api.get())
			{
				r->report("get_ptr(auto_ptr<int>) failed", __LINE__);
				bSuccess = false;
			}
#endif /* _STLSOFT_PTR_ACCESS_NO_AUTO_PTR */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_ptr_access(test_stlsoft_ptr_access);
	} // anonymous namespace

} // namespace unittest

