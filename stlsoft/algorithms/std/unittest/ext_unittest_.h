
// Updated: 10th August 2005

#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_STD_HPP_EXT)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/std/ext.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_STD_HPP_EXT */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace stlsoft_algorithms_ext_unittest
		{
			struct is_odd
			{
				bool operator ()(int i) const
				{
					return 0 != (i % 2);
				}
			};

			struct add_count
			{
			public:
				add_count(int *pi)
					: m_pi(pi)
				{}

			public:
				void operator ()(int const &i) const
				{
					*m_pi += i;
				}

			private:
				int *m_pi;
			};
		}

		ss_bool_t test_stlsoft_std_ext_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */
			using stlsoft_algorithms_ext_unittest::add_count;
			using stlsoft_algorithms_ext_unittest::is_odd;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "std_ext_algorithms", __FILE__);

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
				int 		dest_control[STLSOFT_NUM_ELEMENTS(src)];

				::memset(&dest[0], 0, sizeof(dest));
				::memcpy(&dest_control[0], &dest[0], sizeof(dest));

				stlsoft_ns_qual(copy_if)(&src[0], &src[0] + STLSOFT_NUM_ELEMENTS(src), &dest[0], is_odd());

				if(0 != ::memcmp(&dest[0], &dest_control[0], sizeof(dest_control)))
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

				if(25 != total)
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

				if(0 != ::memcmp(&src[0], &ref[0], sizeof(ref)))
				{
					r->report("fill_if() failed to overwrite matching elements", __LINE__);
					bSuccess = false;
				}
			}

			{ // test fill_if() - doing nothing

				const int	src[]	=	{ 0, 2, 4, 6, 8, 10, 12, 14, 16 };
				int 		dest[STLSOFT_NUM_ELEMENTS(src)];
				int 		dest_control[STLSOFT_NUM_ELEMENTS(src)];

				::memset(&dest[0], 0, sizeof(dest));
				::memcpy(&dest_control[0], &dest[0], sizeof(dest));

				stlsoft_ns_qual(fill_if)(&dest[0], &dest[0] + STLSOFT_NUM_ELEMENTS(src), -1, is_odd());

				if(0 != ::memcmp(&dest[0], &dest_control[0], sizeof(dest_control)))
				{
					r->report("fill_if() incorrectly overwrite non-matching elements", __LINE__);
					bSuccess = false;
				}

				STLSOFT_SUPPRESS_UNUSED(src);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_std_ext_algorithms(test_stlsoft_std_ext_algorithms);
	} // anonymous namespace

} // namespace unittest
