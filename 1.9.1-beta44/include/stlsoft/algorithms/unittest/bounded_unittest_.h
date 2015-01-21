
#if !defined(STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED)
# error This file cannot be directly included, and should only be included within stlsoft/algorithms/bounded.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_BOUNDED */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_stlsoft_algorithms__copy_n(unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			char		src[]	=	"abcdefghijklm";
			char		dest[]	=	"~~~~~~~~~~~~~";

			// 1. n == 0

			copy_n(src, 0, dest);

			if(dest[0] != '~')
			{
				r->report("copy_n() failed for n == 0", __LINE__);
				bSuccess = false;
			}

			// 2. n == 1

			copy_n(src, 1, dest);

			if( dest[0] != 'a' ||
				dest[1] != '~')
			{
				r->report("copy_n() failed for n == 1", __LINE__);
				bSuccess = false;
			}

			// 3. all n

			copy_n(src, sizeof(src), dest);

			if(0 != strcmp(dest, dest))
			{
				r->report("copy_n() failed for all n", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_stlsoft_algorithms__copy_n_pr(unittest_reporter * /* r */)
		{
			ss_bool_t	bSuccess	=	true;

			return bSuccess;
		}

		ss_bool_t test_stlsoft_bounded_algorithms(unittest_reporter *r)
		{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
			using ::stlsoft::unittest::unittest_initialiser;
#endif /* compiler */

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "bounded_algorithms", __FILE__);

			if(!test_stlsoft_stlsoft_algorithms__copy_n(r))
			{
				bSuccess = false;
			}

			if(!test_stlsoft_stlsoft_algorithms__copy_n_pr(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_bounded_algorithms(test_stlsoft_bounded_algorithms);
	} // anonymous namespace

} // namespace unittest
