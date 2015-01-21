
#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/sap_cast.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_conversion_sap_cast(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/sap_cast", __FILE__);

			int 	i;
			void	*pv =	&i;
			short	*ps =	reinterpret_cast<short*>(&i);

			if(sap_cast<short*>(pv) != ps)
			{
				r->report("sap_cast failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_sap_cast(test_stlsoft_conversion_sap_cast);
	} // anonymous namespace

} // namespace unittest
