
// Updated: 22nd October 2006

#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_TRIP_BOOL)
# error This file cannot be directly included, and should only be included within stlsoft/util/trip_bool.hpp
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_TRIP_BOOL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_trip_bool(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "util/trip_bool", __FILE__);

			// 1. trip_bool<false> tripping
			{
				trip_bool<false>	b;

				if(!b)
				{
					r->report("trip_bool<false>() construction failed: should start in true state", __LINE__);
					bSuccess = false;
				}

				b.trip();

				if(b)
				{
					r->report("trip_bool<false>::trip() failed: should be tripped to false", __LINE__);
					bSuccess = false;
				}
			}

			// 2. trip_bool<true> tripping
			{
				trip_bool<true> b;

				if(b)
				{
					r->report("trip_bool<true>() construction failed: should start in false state", __LINE__);
					bSuccess = false;
				}

				b.trip();

				if(!b)
				{
					r->report("trip_bool<true>::trip() failed: should be tripped to true", __LINE__);
					bSuccess = false;
				}
			}

			// 3. trip_bool<false> pre-tripped
			{
				trip_bool<false>	b(false);

				if(b)
				{
					r->report("trip_bool<false>(false) construction failed: should start in false state", __LINE__);
					bSuccess = false;
				}

				b.trip();

				if(b)
				{
					r->report("trip_bool<false>::trip() failed: should be tripped to false", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_trip_bool(test_stlsoft_trip_bool);
	} // anonymous namespace

} // namespace unittest

