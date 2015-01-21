
#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_DEPRECATED)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/deprecated.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_DEPRECATED */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_deprecated_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "deprecated_algorithms", __FILE__);

#if 0
			// copy_if

			{ // test copy_if() - doing something

				const int	src[]	=	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				int 		dest[STLSOFT_NUM_ELEMENTS(src)];
				const int	ref[]	=	{ 1, 3, 5, 7, 9 };

				stlsoft_ns_qual(copy_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), &dest[0], is_odd());

				if(0 != ::memcmp(&dest[0], &ref[0], sizeof(ref)))
				{
					r->report("copy_if() failed to filter out non-matching elements", __LINE__);
					bSuccess = false;
				}
			}

			{ // test copy_if() - doing nothing

				const int	src[]	=	{ 0, 2, 4, 6, 8, 10, 12, 14, 16 };
				int 		dest[STLSOFT_NUM_ELEMENTS(src)];

				stlsoft_ns_qual(copy_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), &dest[0], is_odd());

				if(0 != ::memcmp(&dest[0], &src[0], sizeof(src)))
				{
					r->report("copy_if() incorrectly filtered out matching elements", __LINE__);
					bSuccess = false;
				}
			}

			// for_each_if

			{ // test for_each_if() - doing something
				const int	src[]	=	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				int 		total	=	0;

				stlsoft_ns_qual(for_each_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), add_count(&total), is_odd());

				if(21 != total)
				{
					r->report("for_each_if() failed to select matching elements", __LINE__);
					bSuccess = false;
				}
			}

			{ // test for_each_if() - doing nothing
				const int	src[]	=	{ 0, 2, 4, 6, 8 };
				int 		total	=	0;

				stlsoft_ns_qual(for_each_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), add_count(&total), is_odd());

				if(0 != total)
				{
					r->report("for_each_if() incorrectly selected non-matching elements", __LINE__);
					bSuccess = false;
				}
			}

			// fill_if

			{ // test fill_if() - doing something

				int 		src[]	=	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				const int	ref[]	=	{ 0, -1, 2, -1, 4, -1, 6, -1, 8, -1 };

				stlsoft_ns_qual(fill_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), -1, is_odd());

				if(0 != ::memcmp(&dest[0], &ref[0], sizeof(ref)))
				{
					r->report("fill_if() failed to overwrite matching elements", __LINE__);
					bSuccess = false;
				}
			}

			{ // test fill_if() - doing nothing

				const int	src[]	=	{ 0, 2, 4, 6, 8, 10, 12, 14, 16 };
				int 		dest[STLSOFT_NUM_ELEMENTS(src)];

				stlsoft_ns_qual(fill_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), -1, is_odd());

				if(0 != ::memcmp(&dest[0], &src[0], sizeof(src)))
				{
					r->report("fill_if() incorrectly overwrite non-matching elements", __LINE__);
					bSuccess = false;
				}
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_deprecated_algorithms(test_stlsoft_deprecated_algorithms);
	} // anonymous namespace

} // namespace unittest
