
#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY)
# error This file cannot be directly included, and should only be included within stlsoft/containers/static_array.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
	 (	!defined(STLSOFT_COMPILER_IS_DMC) || \
		__DMC__ <= 0x0843)

namespace unittest
{
	namespace
	{
		template <ss_typename_param_k T>
		ss_bool_t test_4d(unittest_reporter *r)
		{
			const ss_size_t 		DIM0		=	2;
			const ss_size_t 		DIM1		=	3;
			const ss_size_t 		DIM2		=	4;
			const ss_size_t 		DIM3		=	5;
			ss_bool_t				bSuccess	=	true;

			typedef static_array_4d<T, DIM0, DIM1, DIM2, DIM3>	array_4d_t;


			array_4d_t	ar;

			if(DIM0 != ar.dimension0())
			{
				r->report("4d: dim0 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM1 != ar.dimension1())
			{
				r->report("4d: dim1 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM2 != ar.dimension2())
			{
				r->report("4d: dim2 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM3 != ar.dimension3())
			{
				r->report("4d: dim3 invalid", __LINE__);
				bSuccess = false;
			}

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	 _MSC_VER >= 1200
			if(array_size(ar) != ar.size())
			{
				r->report("4d: array_size() != ar.size()", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			// Initialise the array contents
			T	total = 0;
			T	totals0[DIM0];

			stlsoft_ns_qual_std(fill_n)(&totals0[0], STLSOFT_NUM_ELEMENTS(totals0), 0);

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				{ for(ss_size_t i1 = 0; i1 < ar.dimension1(); ++i1)
				{
					{ for(ss_size_t i2 = 0; i2 < ar.dimension2(); ++i2)
					{
						{ for(ss_size_t i3 = 0; i3 < ar.dimension3(); ++i3)
						{
							T	value			=	static_cast<T>(0)
												+	static_cast<T>(i3)
												+	static_cast<T>(i2 * DIM3)
												+	static_cast<T>(i1 * DIM3 * DIM2)
												+	static_cast<T>(i0 * DIM3 * DIM2 * DIM1)
												;

							ar[i0][i1][i2][i3]	=	value;
							total				+=	value;
							totals0[i0] 		+=	value;
						}}
					}}
				}}
			}}

			// Now do a accumulate
			const T total2	=	stlsoft_ns_qual_std(accumulate)(ar.begin(), ar.end(), T());

			if(total != total2)
			{
				r->report("4d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
				bSuccess = false;
			}

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				const T totalN	=	stlsoft_ns_qual_std(accumulate)(ar[i0].begin(), ar[i0].end(), T());

				if(totals0[i0] != totalN)
				{
					r->report("4d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
					bSuccess = false;
				}

			}}

			// Test the range-validation

			// DIM0
			try
			{
				ar.at(DIM0);

				r->report("4d: ar.at() out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			try
			{
				ar.at(DIM0, 0, 0, 0);

				r->report("4d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM1
			try
			{
				ar.at(0, DIM1, 0, 0);

				r->report("4d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM2
			try
			{
				ar.at(0, 0, DIM2, 0);

				r->report("4d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM3
			try
			{
				ar.at(0, 0, 0, DIM3);

				r->report("4d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			return bSuccess;
		}

		template <ss_typename_param_k T>
		ss_bool_t test_3d(unittest_reporter *r)
		{
			const ss_size_t 		DIM0		=	2;
			const ss_size_t 		DIM1		=	3;
			const ss_size_t 		DIM2		=	4;
			ss_bool_t				bSuccess	=	true;

			typedef static_array_3d<T, DIM0, DIM1, DIM2>  array_3d_t;


			array_3d_t	ar;

			if(DIM0 != ar.dimension0())
			{
				r->report("3d: dim0 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM1 != ar.dimension1())
			{
				r->report("3d: dim1 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM2 != ar.dimension2())
			{
				r->report("3d: dim2 invalid", __LINE__);
				bSuccess = false;
			}

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	 _MSC_VER >= 1200
			if(array_size(ar) != ar.size())
			{
				r->report("3d: array_size() != ar.size()", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			// Initialise the array contents
			T	total = 0;
			T	totals0[DIM0];

			stlsoft_ns_qual_std(fill_n)(&totals0[0], STLSOFT_NUM_ELEMENTS(totals0), 0);

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				{ for(ss_size_t i1 = 0; i1 < ar.dimension1(); ++i1)
				{
					{ for(ss_size_t i2 = 0; i2 < ar.dimension2(); ++i2)
					{
						T	value		=	static_cast<T>(0)
										+	static_cast<T>(i2)
										+	static_cast<T>(i1 * DIM2)
										+	static_cast<T>(i0 * DIM2 * DIM1)
										;

						ar[i0][i1][i2]	=	value;
						total			+=	value;
						totals0[i0] 	+=	value;
					}}
				}}
			}}

			// Now do a accumulate
			const T total2	=	stlsoft_ns_qual_std(accumulate)(ar.begin(), ar.end(), T());

			if(total != total2)
			{
				r->report("3d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
				bSuccess = false;
			}

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				const T totalN	=	stlsoft_ns_qual_std(accumulate)(ar[i0].begin(), ar[i0].end(), T());

				if(totals0[i0] != totalN)
				{
					r->report("3d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
					bSuccess = false;
				}

			}}

			// Test the range-validation

			// DIM0
			try
			{
				ar.at(DIM0);

				r->report("3d: ar.at() out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			try
			{
				ar.at(DIM0, 0, 0);

				r->report("3d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM1
			try
			{
				ar.at(0, DIM1, 0);

				r->report("3d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM2
			try
			{
				ar.at(0, 0, DIM2);

				r->report("3d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			return bSuccess;
		}

		template <ss_typename_param_k T>
		ss_bool_t test_2d(unittest_reporter *r)
		{
			const ss_size_t 		DIM0		=	2;
			const ss_size_t 		DIM1		=	3;
			ss_bool_t				bSuccess	=	true;

			typedef static_array_2d<T, DIM0, DIM1>	array_2d_t;

			array_2d_t	ar;

			if(DIM0 != ar.dimension0())
			{
				r->report("2d: dim0 invalid", __LINE__);
				bSuccess = false;
			}

			if(DIM1 != ar.dimension1())
			{
				r->report("2d: dim1 invalid", __LINE__);
				bSuccess = false;
			}

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	 _MSC_VER >= 1200
			if(array_size(ar) != ar.size())
			{
				r->report("2d: array_size() != ar.size()", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			// Initialise the array contents
			T	total = 0;
			T	totals0[DIM0];

			stlsoft_ns_qual_std(fill_n)(&totals0[0], STLSOFT_NUM_ELEMENTS(totals0), 0);

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				{ for(ss_size_t i1 = 0; i1 < ar.dimension1(); ++i1)
				{
					T	value		=	static_cast<T>(0)
									+	static_cast<T>(i1)
									+	static_cast<T>(i0 * DIM1)
									;

					ar[i0][i1]		=	value;
					total			+=	value;
					totals0[i0] 	+=	value;
				}}
			}}

			// Now do a accumulate
			const T total2	=	stlsoft_ns_qual_std(accumulate)(ar.begin(), ar.end(), T());

			if(total != total2)
			{
				r->report("2d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
				bSuccess = false;
			}

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				const T totalN	=	stlsoft_ns_qual_std(accumulate)(ar[i0].begin(), ar[i0].end(), T());

				if(totals0[i0] != totalN)
				{
					r->report("2d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
					bSuccess = false;
				}

			}}

			// Test the range-validation

			// DIM0
			try
			{
				ar.at(DIM0);

				r->report("2d: ar.at() out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			try
			{
				ar.at(DIM0, 0);

				r->report("2d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			// DIM1
			try
			{
				ar.at(0, DIM1);

				r->report("2d: ar.at(,,,) out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			return bSuccess;
		}

		template <ss_typename_param_k T>
		ss_bool_t test_1d(unittest_reporter *r)
		{
			const ss_size_t 		DIM0	=	2;
			ss_bool_t				bSuccess	=	true;

			typedef static_array_1d<T, DIM0>  array_1d_t;

			array_1d_t	ar;

			if(DIM0 != ar.dimension0())
			{
				r->report("1d: dim0 invalid", __LINE__);
				bSuccess = false;
			}

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	 _MSC_VER >= 1200
			if(array_size(ar) != ar.size())
			{
				r->report("1d: array_size() != ar.size()", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			// Initialise the array contents
			T	total = 0;

			{ for(ss_size_t i0 = 0; i0 < ar.dimension0(); ++i0)
			{
				T	value	=	static_cast<T>(0)
							+	static_cast<T>(i0)
							;

				ar[i0]		=	value;
				total		+=	value;
			}}

			// Now do a accumulate
			const T total2	=	stlsoft_ns_qual_std(accumulate)(ar.begin(), ar.end(), T());

			if(total != total2)
			{
				r->report("1d: accumulate(ar.begin(), ar,begin(), T()) != initialisation total", __LINE__);
				bSuccess = false;
			}

			// Test the range-validation

			// DIM0
			try
			{
				ar.at(DIM0);

				r->report("1d: ar.at() out of range failed to throw", __LINE__);
				bSuccess = false;
			}
			catch(::std::out_of_range &)
			{}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_containers_static_array(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "containers/static_array", __FILE__);

			if(bSuccess)
			{
				bSuccess = test_4d<int>(r);
			}

			if(bSuccess)
			{
				bSuccess = test_3d<int>(r);
			}

			if(bSuccess)
			{
				bSuccess = test_2d<int>(r);
			}

			if(bSuccess)
			{
				bSuccess = test_1d<int>(r);
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_containers_static_array(test_stlsoft_containers_static_array);
	} // anonymous namespace

} // namespace unittest

# endif /* compiler */
