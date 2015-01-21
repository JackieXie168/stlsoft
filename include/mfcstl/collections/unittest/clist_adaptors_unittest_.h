
// Updated: 16th September 2006

#if !defined(MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CLIST_ADAPTORS)
# error This file cannot be directly included, and should only be included within mfcstl/collections/clist_adaptors.hpp
#endif /* !MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_CLIST_ADAPTORS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		template<	ss_typename_param_k C1
				,	ss_typename_param_k C2
				>
		ss_bool_t test_mfcstl_clist_adaptors_2_(C1 &c1, C2 &c2, unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;
			LPCTSTR 	strings1[]	=
			{
					"String 1 (MFC)"
				,	"String 2 (MFC)"
				,	"String 3 (MFC)"
			};

			{
				ss_typename_type_k C1::allocator_type::pointer	p =   c1.get_allocator().allocate(10);

				c1.get_allocator().deallocate(p, 10);
			}

			// size()
			if(static_cast<int>(c1.size()) != c1.get_CList().GetSize())
			{
				r->report("size() failed", __LINE__);
				bSuccess = false;
			}
			if(static_cast<int>(c2.size()) != c2.get_CList().GetSize())
			{
				r->report("size() failed", __LINE__);
				bSuccess = false;
			}

			// max_size()
			if(c1.max_size() != c1.get_allocator().max_size())
			{
				r->report("max_size() failed", __LINE__);
				bSuccess = false;
			}
			if(c2.max_size() != c2.get_allocator().max_size())
			{
				r->report("max_size() failed", __LINE__);
				bSuccess = false;
			}

			c1.resize(0);
			if(!c1.empty())
			{
				r->report("resize() failed", __LINE__);
				bSuccess = false;
			}

			c1.resize(1);
			// Can't pass reference, since push_back() invalidates it
			c1.push_back(static_cast<ss_typename_type_k C1::value_type>(c1.front()));
			if( 2 != c1.size() ||
				c1[1] != c1[0])
			{
				r->report("push_back() failed", __LINE__);
				bSuccess = false;
			}
			c1.pop_back();
			if(1 != c1.size())
			{
				r->report("pop_back() failed", __LINE__);
				bSuccess = false;
			}
			// Can't pass reference, since insert() invalidates it
			c1.insert(c1.end(), static_cast<ss_typename_type_k C1::value_type>(c1.front()));
			if( 2 != c1.size() ||
				c1[1] != c1[0])
			{
				r->report("insert() failed", __LINE__);
				bSuccess = false;
			}
			// Can't pass reference, since insert() invalidates it
			c1.insert(c1.end(), 2, static_cast<ss_typename_type_k C1::value_type>(c1.front()));
			if( 4 != c1.size() ||
				c1[2] != c1[0] ||
				c1[3] != c1[0])
			{
				r->report("insert() failed", __LINE__);
				bSuccess = false;
			}
			c1.erase(c1.begin());
			if(3 != c1.size())
			{
				r->report("erase() failed", __LINE__);
				bSuccess = false;
			}

			c1.resize(10, c1[0]);
			if(10 != c1.size())
			{
				r->report("resize() failed", __LINE__);
				bSuccess = false;
			}

			c1.clear();
			if(!c1.empty())
			{
				r->report("clear() failed", __LINE__);
				bSuccess = false;
			}

			try
			{
				c1.at(0);

				r->report("at(0) failed to throw when instance empty", __LINE__);
				bSuccess = false;
			}
			catch(std::out_of_range &)
			{}

			c1.resize(1);
			if(c1[0] != c1.at(0))
			{
				r->report("c1[0] != c1.at(0)", __LINE__);
				bSuccess = false;
			}
			if(c1.front() != c1.back())
			{
				MFCSTL_ASSERT(1 == c1.size());
				r->report("c1.front() != c1.back() for instance with one item", __LINE__);
				bSuccess = false;
			}

			c1.erase(c1.begin(), c1.end());
			if(!c1.empty())
			{
				r->report("erase(begin(), end()) failed", __LINE__);
				bSuccess = false;
			}

			// MFC manipulation
			c1.get_CList().Add(strings1[0]);
			c1.get_CList().InsertAt(1, strings1[1]);
			c1.get_CList().SetSize(3);
			c1.get_CList()[2] = strings1[2];

			// STL manipulation
			{	ss_typename_type_k C1::iterator b	=	c1.begin();
				size_t							i	=	0;

				for(; bSuccess && i < STLSOFT_NUM_ELEMENTS(strings1); ++i, ++b)
				{
#if 0
					if(c1.end() == b)
#else /* ? 0 */
					if(b == c1.end())
#endif /* 0 */
					{
						r->report("iterator not valid", __LINE__);
						bSuccess = false;
					}
					else if(*b != strings1[i])
					{
						r->report("iterator not valid", __LINE__);
						bSuccess = false;
					}
				}
			}

			LPCTSTR 	strings2[]	=
			{
					"String 6 (MFC)"
				,	"String 5 (MFC)"
				,	"String 4 (MFC)"
			};

			// STL manipulation
			c1.insert(c1.begin() + 1, &strings2[0], &strings2[0] + STLSOFT_NUM_ELEMENTS(strings2));

			// MFC manipulation
			{ for(int i = 0; bSuccess && i < STLSOFT_NUM_ELEMENTS(strings2); ++i)
			{
				if(c1.get_CList()[1 + i] != strings2[i])
				{
					r->report("indexed contents not valid", __LINE__);
					bSuccess = false;
				}
			}}

			// empty()
			if(c1.empty() != (0 == c1.size()))
			{
				r->report("empty() failed", __LINE__);
				bSuccess = false;
			}
			if(c2.empty() != (0 == c2.size()))
			{
				r->report("empty() failed", __LINE__);
				bSuccess = false;
			}

			// Comparison
			if(c1 == c2)
			{
				r->report("comparison failed", __LINE__);
				bSuccess = false;
			}
			if(!(c1 != c2))
			{
				r->report("comparison failed", __LINE__);
				bSuccess = false;
			}

			c2.assign(1, c1[0]);
			if(c1[0] != c2[0])
			{
				r->report("assign(1) failed", __LINE__);
				bSuccess = false;
			}

			c2.assign(const_cast<C1 const&>(c1).begin(), const_cast<C1 const&>(c1).end());
			if(c1 != c2)
			{
				r->report("assign(<iterators>) failed", __LINE__);
				bSuccess = false;
			}
			if(!(c1 == c2))
			{
				r->report("assign(<iterators>) failed", __LINE__);
				bSuccess = false;
			}

			c2.assign(c1.rbegin(), c1.rend());
			c1.assign(c2.rbegin(), c2.rend());
			c2.assign(const_cast<C1 const&>(c1).rbegin(), const_cast<C1 const&>(c1).rend());
			std::sort(c1.begin(), c1.end());
			std::sort(c2.rbegin(), c2.rend());
			std::sort(c1.rbegin(), c1.rend());
			if(c1 != c2)
			{
				r->report("assign(<reverse iterators>) failed", __LINE__);
				bSuccess = false;
			}
			if(!(c1 == c2))
			{
				r->report("assign(<reverse iterators>) failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_mfcstl_clist_adaptors(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;
			using stlsoft::null_exception_policy;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "MFCSTL", "collections/clist_adaptors", __FILE__);

#if 0
			{ // CStringArray & CStringArray
				typedef CStringArray					array_type_1;
				typedef CStringArray					array_type_2;
				typedef CList_cadaptor<array_type_1>	facade_type;
				typedef CList_iadaptor<array_type_2>	proxy_type;

				facade_type 	arf;
				array_type_2	ar;
				proxy_type		arp(ar);

				if(!test_mfcstl_clist_adaptors_2_(arf, arp, r))
				{
					bSuccess = false;
				}
			}

			{ // CStringArray & CList<CString>
				typedef CStringArray							array_type_1;
				typedef CList<CString, LPCTSTR> 			array_type_2;
				typedef CList_specific_traits< CString
											,	CString const&
											,	CStringArray
											>					traits_type;
				typedef CList_cadaptor<  array_type_1
//									,	traits_type
									>							facade_type;
				typedef CList_iadaptor<   array_type_2
									,	traits_type
									>							proxy_type;

				facade_type 	arf;
				array_type_2	ar;
				proxy_type		arp(ar);

				if(!test_mfcstl_clist_adaptors_2_(arf, arp, r))
				{
					bSuccess = false;
				}
			}

			{ // CList<simple_string> & CList<simple_string>
				typedef CList< simple_string
							,	simple_string const&
							>								array_type_1;
				typedef CList< simple_string
							,	simple_string const&
							>								array_type_2;
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1310
				typedef CList_specific_traits< simple_string
											,	simple_string const&
											,	array_type_2
											>				traits_type;
#endif /* compiler */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER < 1310
				CList_cadaptor<array_type_1, traits_type>	arf;
				array_type_2								ar;
				CList_iadaptor<array_type_2, traits_type>	arp(ar);
#else /* ? compiler */
				CList_cadaptor<array_type_1>				arf;
				array_type_2								ar;
				CList_iadaptor<array_type_2>				arp(ar);
#endif /* compiler */

				if(!test_mfcstl_clist_adaptors_2_(arf, arp, r))
				{
					bSuccess = false;
				}
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_mfcstl_clist_adaptors(test_mfcstl_clist_adaptors);
	} // anonymous namespace

} // namespace unittest

