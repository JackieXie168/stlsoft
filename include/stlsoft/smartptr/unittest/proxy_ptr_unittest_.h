
// Updated: 22nd April 2007

#if !defined(STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PROXY_PTR)
# error This file cannot be directly included, and should only be included within stlsoft/smartptr/proxy_ptr.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PROXY_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_smartptr_proxy_ptr(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;
			unittest_initialiser	init(r, "STLSoft", "smartptr/proxy_ptr", __FILE__);

			int 			i		=	1;
			int 			*pi 	=	&i;
			int 			*pi2;

			proxy_ptr<int>	ppi1(pi);
			proxy_ptr<int>	ppi2	=	ppi1;
			proxy_ptr<int>	ppi3(NULL);

			ppi3 = ppi1;

			pi2 = ppi1;
			if(pi2 != pi)
			{
				r->report("implicit conversion operator failed", __LINE__);
				bSuccess = false;
			}
			pi2 = ppi1;
			if(pi2 != pi)
			{
				r->report("implicit conversion operator failed", __LINE__);
				bSuccess = false;
			}
			pi2 = ppi2;
			if(pi2 != pi)
			{
				r->report("implicit conversion operator failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_smartptr_proxy_ptr(test_stlsoft_smartptr_proxy_ptr);
	} // anonymous namespace

} // namespace unittest
