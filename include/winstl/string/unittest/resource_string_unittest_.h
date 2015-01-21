
// Updated: 18th January 2007

#if !defined(WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING)
# error This file cannot be directly included, and should only be included within winstl/string/resource_string.hpp
#endif /* !WINSTL_INCL_WINSTL_STRING_HPP_RESOURCE_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		struct throw_exception
		{
		public:
			/// The exception type
			class thrown_type
				: public std::exception
			{
			public:
				thrown_type(char const *reason) throw()
					: m_reason(reason)
				{}

				~thrown_type() throw()
				{}

				char const *what() const throw()
				{
					return m_reason.c_str();
				}

			private:
				stlsoft_ns_qual_std(string) m_reason;
			};

		public:
			void operator ()(char const *reason, DWORD err, LPCSTR resourceId, LPCSTR resourceType) const
			{
				char	message[1001];
				char	szResourceId[21];
				char	szResourceType[21];

				if(0 == HIWORD(resourceId))
				{
					wsprintfA(szResourceId, "%d", resourceId);
					resourceId = &szResourceId[0];
				}
				if(0 == HIWORD(resourceType))
				{
					wsprintfA(szResourceType, "%d", resourceType);
					resourceType = &szResourceType[0];
				}

				wsprintfA(message, "Failed to load resource %s (of type %s): %s; error=d", resourceId, resourceType, reason, err);

				throw thrown_type(message);
			}
		};

		ss_bool_t test_winstl_resource_string(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "string/resource_string", __FILE__);

			typedef basic_resource_string<stlsoft_ns_qual_std(string), null_exception_policy>  rsn_a_t;
			typedef basic_resource_string<stlsoft_ns_qual_std(wstring), null_exception_policy> rsn_w_t;

			HINSTANCE	hinst	=	::LoadLibrary("USER32");
			int 		iBad	=	-1;
			int 		iGood	=	-1;

			for(int i = 0; i < 10000; ++i)
			{
				rsn_a_t 	rsn_a_2(hinst, i);
				rsn_w_t 	rsn_w_2(hinst, i);

				if(0 == rsn_a_2.length())
				{
					if(-1 == iBad)
					{
						iBad = i;
					}
				}
				else
				{
					if(-1 == iGood)
					{
						iGood = i;
					}
				}

				if(rsn_a_2.length() != rsn_w_2.length())
				{
					r->report("resource string (null exception) length mismatch between ANSI and Unicode instantiations", __LINE__);
					bSuccess = false;
				}
			}

			if(bSuccess)
			{
				typedef basic_resource_string<stlsoft_ns_qual_std(string), throw_exception> 	rsx_a_t;
				typedef basic_resource_string<stlsoft_ns_qual_std(wstring), throw_exception>	rsx_w_t;

				if(-1 != iGood)
				{
					try
					{
						rsx_a_t 	rsn_a_2(hinst, iGood);
						rsx_w_t 	rsn_w_2(hinst, iGood);
					}
					catch(std::exception &/* x */)
					{
						r->report("resource string (std::exception) failed to load known resource from USER32", __LINE__);
						bSuccess = false;
					}
				}

				if(-1 != iBad)
				{
					try
					{
						rsx_a_t 	rsn_a_2(hinst, iBad);

						r->report("resource string (std::exception) loaded known invalid resource from USER32", __LINE__);
						bSuccess = false;
					}
					catch(std::exception &/* x */)
					{}

					try
					{
						rsx_w_t 	rsn_w_2(hinst, iBad);

						r->report("resource string (std::exception) loaded known invalid resource from USER32", __LINE__);
						bSuccess = false;
					}
					catch(std::exception &/* x */)
					{}
				}
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				winstl::basic_resource_string<std::string>	str(1024);

#if !defined(STLSOFT_COMPILER_IS_DMC)
				std::cout << "String with id 1024: " << str << std::endl;
#endif /* compiler */

				fprintf(out, "String with id 1024: %.*s\n", str.size(), str.data());
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				winstl::basic_resource_string<std::string>	str(hinst, 9999999);

				WINSTL_ASSERT(0 == str.size());
				WINSTL_ASSERT(str == "");
			}

			// Documentation example
			if(0) // This is 0 so we don't produce spurious output in the unit-tests
			{
				try
				{
					winstl::basic_resource_string<std::string, throw_exception>  str(hinst, 9999999);

					fprintf(err, "Should never get here!!\n");
				}
				catch(throw_exception::thrown_type &/* x */)
				{
					fprintf(err, "This is what's expected\n");
				}
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_winstl_resource_string(test_winstl_resource_string);
	} // anonymous namespace

} // namespace unittest
