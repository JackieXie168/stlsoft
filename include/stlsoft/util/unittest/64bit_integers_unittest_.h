
// Updated: 6th July 2006

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_64BIT_INTEGERS)
# error This file cannot be directly included, and should only be included within stlsoft/util/64bit_integers.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_64BIT_INTEGERS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_64bit_integers(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/64bit_integers", __FILE__);

			ss_sint8_t	i8		=	8;
			ss_sint16_t i16 	=	16;
			ss_sint32_t i32 	=	32;
			ss_sint32_t high64	=	0;
			ss_sint32_t low64	=	64;

			sinteger64		si1;

			sinteger64		si2(0);

			sinteger64		si3(i8);

			sinteger64		si4(i16);

			sinteger64		si5(i32);

			sinteger64		si6(high64, low64);

			// Test exact values

			if(sinteger64(0) != si2)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(0 != si2)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(si2 != 0)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(!(sinteger64(0) == si2))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}
			if(!(0 == si2))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}
			if(!(si2 == 0))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}

			if(sinteger64(8) != si3)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(8 != si3)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(si3 != 8)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(!(sinteger64(8) == si3))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}
			if(!(8 == si3))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}
			if(!(si3 == 8))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}

			if(sinteger64(16) != si4)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(!(sinteger64(16) == si4))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}

			if(sinteger64(32) != si5)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(!(sinteger64(32) == si5))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}

			if(sinteger64(64) != si6)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(!(sinteger64(64) == si6))
			{
				r->report("Equality comparison failed", __LINE__);
				bSuccess = false;
			}

			// Test relative values

			if(si4 < sinteger64(16))
			{
				r->report("operator < failed", __LINE__);
				bSuccess = false;
			}
			if(si4 < 16)
			{
				r->report("operator < failed", __LINE__);
				bSuccess = false;
			}

			if(32 < si5)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(sinteger64(32) < si5)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}

			STLSOFT_SUPPRESS_UNUSED(si1);


			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_64bit_integers(test_stlsoft_64bit_integers);
	} // anonymous namespace

} // namespace unittest
