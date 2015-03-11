
#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/pod.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_pod_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "pod_algorithms", __FILE__);

			{ // Copying between elements of the same type
				sint8_t 		src[3] = { -1, 0, +1 };
				sint8_t 		dest[STLSOFT_NUM_ELEMENTS(src)];

				memset(&dest[0], 0, sizeof(dest));
				pod_copy(&src[0], &src[STLSOFT_NUM_ELEMENTS(src)], &dest[0]);
				if(0 != memcmp(&src[0], &dest[0], sizeof(src)))
				{
					r->report("pod_copy() failed with elements of same type", __LINE__);
					bSuccess = false;
				}

				memset(&dest[0], 0, sizeof(dest));
				pod_copy_n(&dest[0], &src[0], STLSOFT_NUM_ELEMENTS(src));
				if(0 != memcmp(&src[0], &dest[0], sizeof(src)))
				{
					r->report("pod_copy_n() failed with elements of same type", __LINE__);
					bSuccess = false;
				}
			}

			{ // Copying between elements of the same size
				const sint32_t	src[3] = { -1, 0, +1 };
				uint32_t		dest[STLSOFT_NUM_ELEMENTS(src)];

				memset(&dest[0], 0, sizeof(dest));
				pod_copy(&src[0], &src[STLSOFT_NUM_ELEMENTS(src)], &dest[0]);
				if(0 != memcmp(&src[0], &dest[0], sizeof(src)))
				{
					r->report("pod_copy() failed with elements of same size", __LINE__);
					bSuccess = false;
				}

				memset(&dest[0], 0, sizeof(dest));
				pod_copy_n(&dest[0], &src[0], STLSOFT_NUM_ELEMENTS(src));
				if(0 != memcmp(&src[0], &dest[0], sizeof(src)))
				{
					r->report("pod_copy_n() failed with elements of same size", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_pod_algorithms(test_stlsoft_pod_algorithms);
	} // anonymous namespace

} // namespace unittest
