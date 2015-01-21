
// Updated: 6th July 2006

#if !defined(MFCSTL_INCL_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER)
# error This file cannot be directly included, and should only be included within mfcstl/string/grab_cstring_buffer.hpp
#endif /* !MFCSTL_INCL_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_mfcstl_grab_cstring_buffer(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "string/grab_cstring_buffer", __FILE__);

			CString 			str("Str");

			try
			{
				grab_cstring_buffer gcs(str, 6);

				gcs[3] = 'i';
				gcs[4] = 'n';
				gcs[5] = 'g';
			}
			catch(CMemoryException *pe)
			{
				pe->ReportError();
			}
			catch(CException *pe)
			{
				pe->ReportError();
			}

			if(str != "String")
			{
				r->report("grab_cstring_buffer failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_grab_cstring_buffer(test_mfcstl_grab_cstring_buffer);
	} // anonymous namespace

} // namespace unittest
