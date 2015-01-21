
// Updated: 9th August 2006

#if !defined(DOTNETSTL_INCL_DOTNETSTL_CONVERSION_HPP_CHECK_CAST)
# error This file cannot be directly included, and should only be included within dotnetstl/conversion/check_cast.hpp
#endif /* !DOTNETSTL_INCL_DOTNETSTL_CONVERSION_HPP_CHECK_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace check_cast_namespace_
	{
		public __gc class Example_Class
			: public System::Object
		{};

	} // namespace check_cast_namespace_

	namespace
	{
		ss_bool_t test_dotnetstl_conversion_check_cast(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, ".netSTL", "conversion/check_cast", __FILE__);

			// A cast that succeeds

			try
			{
				System::String		*str	=	new System::String("");
				System::Object		*obj	=	str;

				::dotnetstl::check_cast<System::String*>(obj);
			}
			catch(System::InvalidCastException *)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}
			catch(System::Exception *)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}
			catch(std::exception &)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}

			// A cast that fails

			try
			{
				System::String		*str	=	new System::String("");
				System::Object		*obj	=	str;

				__try_cast<check_cast_namespace_::Example_Class*>(obj);

				r->report("Failed to detect invalid cast", __LINE__);
				bSuccess = false;
			}
			catch(System::InvalidCastException *)
			{
			}
			catch(System::Exception *)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}
			catch(std::exception &)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}

#ifdef _DEBUG
			// A cast that fails

			try
			{
				System::String		*str	=	new System::String("");
				System::Object		*obj	=	str;

				dotnetstl::check_cast<check_cast_namespace_::Example_Class*>(obj);

				r->report("Failed to detect invalid cast", __LINE__);
				bSuccess = false;
			}
			catch(System::InvalidCastException *)
			{
			}
			catch(System::Exception *)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}
			catch(std::exception &)
			{
				r->report("Caught wrong exception", __LINE__);
				bSuccess = false;
			}
#endif /* _DEBUG */

			return bSuccess;
		}

		unittest_registrar	  unittest_dotnetstl_conversion_check_cast(test_dotnetstl_conversion_check_cast);
	} // anonymous namespace

} // namespace unittest
