
// Updated: 13th December 2006

#if !defined(COMSTL_INCL_COMSTL_CONVERSION_HPP_INTERFACE_CAST)
# error This file cannot be directly included, and should only be included within comstl/conversion/interface_cast.hpp
#endif /* !COMSTL_INCL_COMSTL_CONVERSION_HPP_INTERFACE_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_conversion_interface_cast_1(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			LPSTREAM	pstm;
			HRESULT 	hr	=	::CreateStreamOnHGlobal(NULL, true, &pstm);

			if(SUCCEEDED(hr))
			{
				if(interface_cast_test<LPSTREAM>(pstm))
				{}
				else
				{
					r->report("interface_cast_test failed to detect same type ", __LINE__);
					bSuccess = false;
				}

				if(!interface_cast_test<LPSTREAM>(pstm))
				{
					r->report("interface_cast_noaddref did not cast to same type ", __LINE__);
					bSuccess = false;
				}

				try
				{
//#if defined(STLSOFT_COMPILER_IS_DMC) || \
//	(	defined(STLSOFT_COMPILER_IS_MSVC) && \
//		_MSC_VER <= 1200)
//					if(!!interface_cast_test<LPSTORAGE>(pstm))
//#else /* ? compiler */
					if(interface_cast_test<LPSTORAGE>(pstm))
//#endif /* compiler */
					{
						r->report("interface_cast_noaddref cast to wrong type ", __LINE__);
						bSuccess = false;
					}
				}
				catch(bad_interface_cast &x)
				{
					STLSOFT_SUPPRESS_UNUSED(x);
				}

				LPSTREAM	pstm2	=	interface_cast_addref<LPSTREAM>(pstm);
				LPSTORAGE	pstg	=	interface_cast_addref<LPSTORAGE>(pstm);

				if(NULL == pstm2)
				{
					r->report("interface_cast_addref did not cast to same type ", __LINE__);
					bSuccess = false;
				}
				else
				{
					pstm2->Release();
				}

				if(NULL != pstg)
				{
					r->report("interface_cast_addref cast to wrong type ", __LINE__);
					bSuccess = false;
					pstg->Release();
				}

				pstm->Release();
			}

			return bSuccess;
		}

		ss_bool_t test_comstl_conversion_interface_cast_2(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			LPSTREAM	pstm;
			HRESULT 	hr	=	::CreateStreamOnHGlobal(NULL, true, &pstm);

			if(SUCCEEDED(hr))
			{
				stlsoft::ref_ptr<IStream>	stm(pstm, false); // Consume the reference

				if(interface_cast_test<IStream>(stm))
				{}
				else
				{
					r->report("interface_cast_test failed to detect same type ", __LINE__);
					bSuccess = false;
				}

				if(!interface_cast_test<IStream>(stm))
				{
					r->report("interface_cast_noaddref did not cast to same type ", __LINE__);
					bSuccess = false;
				}

				try
				{
					if(interface_cast_test<IStorage>(stm))
					{
						r->report("interface_cast_noaddref cast to wrong type ", __LINE__);
						bSuccess = false;
					}
				}
				catch(bad_interface_cast &x)
				{
					STLSOFT_SUPPRESS_UNUSED(x);
				}

				stlsoft::ref_ptr<IStream>	stm2	=	try_interface_cast<IStream>(stm);
				stlsoft::ref_ptr<IStorage>	stg 	=	try_interface_cast<IStorage>(stm);

				if(NULL == stm2.get())
				{
					r->report("interface_cast_addref did not cast to same type ", __LINE__);
					bSuccess = false;
				}
				else
				{}

				if(NULL != stg.get())
				{
					r->report("interface_cast_addref cast to wrong type ", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		ss_bool_t test_comstl_conversion_interface_cast(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "conversion/interface_cast", __FILE__);

			if(!test_comstl_conversion_interface_cast_1(r))
			{
				bSuccess = false;
			}

			if(!test_comstl_conversion_interface_cast_2(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_comstl_conversion_interface_cast(test_comstl_conversion_interface_cast);
	} // anonymous namespace

} // namespace unittest
