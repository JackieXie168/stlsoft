
// Updated: 6th July 2006

#if !defined(COMSTL_INCL_COMSTL_SMARTPTR_HPP_INTERFACE_PTR)
# error This file cannot be directly included, and should only be included within comstl/smartptr/interface_ptr.hpp
#endif /* !COMSTL_INCL_COMSTL_SMARTPTR_HPP_INTERFACE_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_interface_ptr(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "smartptr/interface_ptr", __FILE__);

			LPSTREAM	pstm;
			HRESULT 	hr	=	::CreateStreamOnHGlobal(NULL, true, &pstm);

			if(SUCCEEDED(hr))
			{
				const interface_ptr<IStream>	stm0;
				interface_ptr<IStream>			stm1(pstm, false);
				const interface_ptr<IStream>	stm2(stm1);
				const interface_ptr<IStream>	stm3(*pstm, true);
				{
				interface_ptr<IStream>			stm4;

				stm4 = stm1;
				}

				{
				interface_ptr<IStream>			stm4;
				stm4.set(pstm, true);
				stm4.set(*pstm, true);
				stm4.release();
				}

				{
				interface_ptr<IStream>			stm4;
				stm4 = stm1;
				stm4.release(false);
				pstm->Release();
				}

				{
				interface_ptr<IStream>			stm4;
				stm4 = stm1;
				stm4.detach()->Release();
				}

				{
				interface_ptr<IStream>			stm4;
				stm4 = stm1;
				stm4.swap(stm1);
				}

				if(stm1.get_interface_ptr() != stm2.get_interface_ptr())
				{
					r->report("copy construction failed", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_interface_ptr(test_comstl_interface_ptr);
	} // anonymous namespace

} // namespace unittest
