
// Updated: 11th December 2006

#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_PTR_CAST)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/ptr_cast.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_PTR_CAST */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace ptr_cast_test_ns
		{
			class Parent
			{
			public:
				virtual ~Parent()
				{}
			};

			class A
				: public Parent
			{
			public:
				~A()
				{}
			};

			class B
				: public Parent
			{
			public:
				~B()
				{}
			};

		} // namespace ptr_cast_test_ns

		ss_bool_t test_stlsoft_conversion_ptr_cast(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/ptr_cast", __FILE__);

			using ptr_cast_test_ns::A;
			using ptr_cast_test_ns::B;

			A	a;
			B	b;

			// (i) dynamic cast of reference that succeeds
			{
				A	&ra1 = dynamic_cast<A&>(a);
				A	&ra2 = stlsoft::ptr_cast<A&>(a);

				if(&ra1 != &ra2)
				{
					r->report("ptr_cast behaves differently to dynamic_cast for successful cast of reference", __LINE__);
					bSuccess = false;
				}
			}

			// (ii) dynamic cast of pointer that succeeds
			{
				A	*pa = dynamic_cast<A*>(&a);

				if(NULL == pa)
				{
					r->report("ptr_cast behaves differently to dynamic_cast for successful cast of pointer", __LINE__);
					bSuccess = false;
				}

				if(stlsoft::ptr_cast<A*>(&a) != pa)
				{
					r->report("ptr_cast behaves differently to dynamic_cast for successful cast of pointer", __LINE__);
					bSuccess = false;
				}
			}

			// (iii) dynamic cast of reference that fails
			{
				try
				{
					B &rb = dynamic_cast<B&>(a);

					STLSOFT_SUPPRESS_UNUSED(rb);

					r->report("dynamic_cast behaves incorrectly for failed cast of reference", __LINE__);
					bSuccess = false;
				}
				catch(std::bad_cast &)
				{}

				try
				{
					B &rb = stlsoft::ptr_cast<B&>(a);

					STLSOFT_SUPPRESS_UNUSED(rb);

					r->report("ptr_cast behaves incorrectly for failed cast of reference", __LINE__);
					bSuccess = false;
				}
				catch(std::bad_cast &)
				{}
			}

			// (iv) dynamic cast of pointer that fails
			{
				if(NULL != dynamic_cast<B*>(&a))
				{
					r->report("dynamic_cast behaves incorrectly for failed cast of pointer", __LINE__);
					bSuccess = false;
				}

				try
				{
					B &rb = stlsoft::ptr_cast<B&>(a);

					STLSOFT_SUPPRESS_UNUSED(rb);

					r->report("ptr_cast behaves incorrectly for failed cast of pointer", __LINE__);
					bSuccess = false;
				}
				catch(std::bad_cast &)
				{}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_ptr_cast(test_stlsoft_conversion_ptr_cast);
	} // anonymous namespace

} // namespace unittest

