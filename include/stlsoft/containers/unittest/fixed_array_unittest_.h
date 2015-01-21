
#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_ARRAY)
# error This file cannot be directly included, and should only be included within stlsoft/containers/fixed_array.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FIXED_ARRAY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_containers_fixed_array(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "containers/fixed_array", __FILE__);

			typedef fixed_array_1d<int> 	fa1d_t;
			typedef fixed_array_2d<int> 	fa2d_t;
			typedef fixed_array_3d<int> 	fa3d_t;
			typedef fixed_array_4d<int> 	fa4d_t;

			fa1d_t	a1d_1(10);
			fa2d_t	a2d_1(10, 20);
			fa3d_t	a3d_1(10, 20, 30);
			fa4d_t	a4d_1(10, 20, 30, 40);

			fa1d_t	a1d_2(a1d_1);
			fa2d_t	a2d_2(a2d_1);
			fa3d_t	a3d_2(a3d_1);
			fa4d_t	a4d_2(a4d_1);

			////////////////////////////////////////////////
			// 1-dimension

			// values, via at_unchecked(), (), []

			{ for(size_t i = 0; i < a1d_1.dimension0(); ++i)
			{
				if(a1d_1.at_unchecked(i) != a1d_1[i])
				{
					r->report("at_unchecked() does not match []", __LINE__);
					bSuccess = false;
				}
				if(a1d_1.at_unchecked(i) != a1d_1(i))
				{
					r->report("at_unchecked() does not match ()", __LINE__);
					bSuccess = false;
				}
				if(a1d_1.at_unchecked(i) != a1d_1.at(i))
				{
					r->report("at_unchecked() does not match ()", __LINE__);
					bSuccess = false;
				}
			}}

			// values, via at()

			try
			{
				static_cast<void>(a1d_1.at(a1d_1.dimension0()));

				r->report("at() failed", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &)
			{}

			// pointers, via at_unchecked(), (), []

			{ for(size_t i = 0; i < a1d_1.dimension0(); ++i)
			{
				if(&a1d_1.at_unchecked(i) != &a1d_1[i])
				{
					r->report("at_unchecked() does not match []", __LINE__);
					bSuccess = false;
				}
				if(&a1d_1.at_unchecked(i) != &a1d_1(i))
				{
					r->report("at_unchecked() does not match ()", __LINE__);
					bSuccess = false;
				}
				if(&a1d_1.at_unchecked(i) != &a1d_1.at(i))
				{
					r->report("at_unchecked() does not match ()", __LINE__);
					bSuccess = false;
				}
			}}

			////////////////////////////////////////////////
			// 2-dimensions

			// values, via at_unchecked(), (), []

			{ for(size_t i = 0; i < a2d_1.dimension0(); ++i)
			{
				{ for(size_t j = 0; j < a2d_1.dimension1(); ++j)
				{
#if !defined(STLSOFT_COMPILER_IS_GCC) || \
    __GNUC__ < 4					
					if(a2d_1.at_unchecked(i, j) != a2d_1[i][j])
					{
						r->report("at_unchecked() does not match []", __LINE__);
						bSuccess = false;
					}
#endif
					if(a2d_1.at_unchecked(i, j) != a2d_1(i, j))
					{
						r->report("at_unchecked() does not match ()", __LINE__);
						bSuccess = false;
					}
					if(a2d_1.at_unchecked(i, j) != a2d_1.at(i, j))
					{
						r->report("at_unchecked() does not match ()", __LINE__);
						bSuccess = false;
					}
				}}
			}}

			// values, via at()

			try
			{
				static_cast<void>(a2d_1.at(a2d_1.dimension0(), 0));

				r->report("at() failed", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &)
			{}

			////////////////////////////////////////////////
			// 3-dimensions

			// values, via at_unchecked(), (), []

			{ for(size_t i = 0; i < a3d_1.dimension0(); ++i)
			{
				{ for(size_t j = 0; j < a3d_1.dimension1(); ++j)
				{
					{ for(size_t k = 0; k < a3d_1.dimension2(); ++k)
					{
#if !defined(STLSOFT_COMPILER_IS_GCC) || \
    __GNUC__ < 4					
						if(a3d_1.at_unchecked(i, j, k) != a3d_1[i][j][k])
						{
							r->report("at_unchecked() does not match []", __LINE__);
							bSuccess = false;
						}
#endif
						if(a3d_1.at_unchecked(i, j, k) != a3d_1(i, j, k))
						{
							r->report("at_unchecked() does not match ()", __LINE__);
							bSuccess = false;
						}
						if(a3d_1.at_unchecked(i, j, k) != a3d_1.at(i, j, k))
						{
							r->report("at_unchecked() does not match ()", __LINE__);
							bSuccess = false;
						}
					}}
				}}
			}}

			// values, via at()

			try
			{
				static_cast<void>(a3d_1.at(0, a3d_1.dimension1(), 0));

				r->report("at() failed", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &)
			{}

			////////////////////////////////////////////////
			// 4-dimensions

			// values, via at_unchecked(), (), []

			{ for(size_t i = 0; i < a4d_1.dimension0(); ++i)
			{
				{ for(size_t j = 0; j < a4d_1.dimension1(); ++j)
				{
					{ for(size_t k = 0; k < a4d_1.dimension2(); ++k)
					{
						{ for(size_t l = 0; l < a4d_1.dimension3(); ++l)
						{
#if !defined(STLSOFT_COMPILER_IS_GCC) || \
    __GNUC__ < 4					
							if(a4d_1.at_unchecked(i, j, k, l) != a4d_1[i][j][k][l])
							{
								r->report("at_unchecked() does not match []", __LINE__);
								bSuccess = false;
							}
#endif
							if(a4d_1.at_unchecked(i, j, k, l) != a4d_1(i, j, k, l))
							{
								r->report("at_unchecked() does not match ()", __LINE__);
								bSuccess = false;
							}
							if(a4d_1.at_unchecked(i, j, k, l) != a4d_1.at(i, j, k, l))
							{
								r->report("at_unchecked() does not match ()", __LINE__);
								bSuccess = false;
							}
						}}
					}}
				}}
			}}

			// values, via at()

			try
			{
				static_cast<void>(a4d_1.at(0, 0, 0, a4d_1.dimension3()));

				r->report("at() failed", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &)
			{}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_containers_fixed_array(test_stlsoft_containers_fixed_array);
	} // anonymous namespace

} // namespace unittest
