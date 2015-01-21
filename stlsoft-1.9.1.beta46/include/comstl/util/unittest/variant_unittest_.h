
// Updated: 2nd September 2006

#if !defined(COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_VARIANT)
# error This file cannot be directly included, and should only be included within comstl/util/variant.hpp
#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_COMSTL_VARIANT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_comstl_variant_invariant(unittest_reporter *r, variant &v)
		{
			ss_bool_t				bSuccess	=	true;

			STLSOFT_SUPPRESS_UNUSED(r);
			STLSOFT_SUPPRESS_UNUSED(v);

#if 0
			if(v.empty() && 0 != v.length())
			{
				r->report("expected length() == 0 when empty()", __LINE__);
				bSuccess = false;
			}

			if(v.empty() && 0 != v.size())
			{
				r->report("expected size() == 0 when empty()", __LINE__);
				bSuccess = false;
			}

			if(!v.empty() && 0 == v.length())
			{
				r->report("expected length() != 0 when !empty()", __LINE__);
				bSuccess = false;
			}

			if(!v.empty() && 0 == v.size())
			{
				r->report("expected size() != 0 when !empty()", __LINE__);
				bSuccess = false;
			}

			if(v.length() != v.size())
			{
				r->report("expected length() == size()", __LINE__);
				bSuccess = false;
			}


			if(NULL == v.c_str())
			{
				r->report("c_str() cannot return NULL", __LINE__);
				bSuccess = false;
			}

			if(NULL == v.data())
			{
				r->report("data() cannot return NULL", __LINE__);
				bSuccess = false;
			}

			if(0 != ::wcsncmp(v.c_str(), v.data(), v.size()))
			{
				r->report("data() and c_str() point to strings with different contents", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		ss_bool_t test_comstl_variant(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "COMSTL", "util/variant", __FILE__);

			{ // Default and copy construction

				variant 	v1(true);

				variant 	v2(v1);

				if(!test_comstl_variant_invariant(r, v1))
				{
					bSuccess = false;
				}

				if(!test_comstl_variant_invariant(r, v2))
				{
					bSuccess = false;
				}

#if 0
				if(!v1.equal(v2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(v1 != v2)
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}

				if(!(v1 == v2))
				{
					r->report("copied instance does not compare equal", __LINE__);
					bSuccess = false;
				}
#endif /* 0 */

				if(VT_BOOL != v1.vt)
				{
					r->report("expected VT_BOOL type", __LINE__);
					bSuccess = false;
				}

				if(VARIANT_TRUE != v1.boolVal)
				{
					r->report("expected VARIANT_TRUE value", __LINE__);
					bSuccess = false;
				}
			}

			{
				variant 	v1(long(123));
			}

			return bSuccess;
		}


		unittest_registrar	  unittest_comstl_variant(test_comstl_variant);
	} // anonymous namespace

} // namespace unittest
