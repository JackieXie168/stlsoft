
// Updated: 30th December 2006

#if !defined(STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_FUNCTIONS)
# error This file cannot be directly included, and should only be included within stlsoft/collections/functions.hpp
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_HPP_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		class FakeMap
		{
		public:
			typedef int 								key_type;
			typedef int 								mapped_type;
			typedef int 								referent_type;
			typedef std::pair<key_type, mapped_type>	value_type;
			typedef value_type							*iterator;
			typedef value_type const					*const_iterator;

			const_iterator	end() const 				{ return NULL; }
			iterator		end()						{ return NULL; }

			mapped_type &operator [](key_type /* k */)
			{
				return get_ref_();
			}

			const_iterator	find(key_type k) const
			{
				switch(k)
				{
					case	1:
					case	2:
						return &get_value_();
					default:
						return end();
				}
			}

			iterator  find(key_type k)
			{
				switch(k)
				{
					case	1:
					case	2:
						return &get_value_();
					default:
						return end();
				}
			}

		private:
			static value_type		&get_value_()
			{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER >= 1310
  // Safe to suppress these warnings, because unit-testing is single-threaded
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

				static value_type		s_value_;

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

				return s_value_;
			}
			static mapped_type		&get_ref_()
			{
				static mapped_type	  s_ref_;

				return s_ref_;
			}
		};

		ss_bool_t test_stlsoft_collections_functions(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "collections/functions", __FILE__);

//			  typedef ::std::map<int, int>	map_t;
			typedef FakeMap 				map_t;

			map_t	m;

			m[1] = 1;
			m[2] = 2;

			try
			{
				(void)lookup(m, 3);

				// Should not get here
				r->report("Search for non-existant erroneously succeeded", __LINE__);
				bSuccess = false;
			}
			catch(stlsoft_ns_qual_std(out_of_range) &)
			{}

			try
			{
				(void)lookup(m, 2);
			}
			catch(stlsoft_ns_qual_std(out_of_range) &)
			{
				// Should not get here
				r->report("Search for existing erroneously failed", __LINE__);
				bSuccess = false;
			}

			map_t const &m2 =	m;

			try
			{
				const int	x	=	3;

				(void)lookup(m2, x);

				// Should not get here
				r->report("Search for non-existant erroneously succeeded", __LINE__);
				bSuccess = false;
			}
			catch(stlsoft_ns_qual_std(out_of_range) &)
			{}

			try
			{
				(void)lookup(m2, 2);
			}
			catch(stlsoft_ns_qual_std(out_of_range) &)
			{
				// Should not get here
				r->report("Search for existing erroneously failed", __LINE__);
				bSuccess = false;
			}

			STLSOFT_SUPPRESS_UNUSED(m2);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_collections_functions(test_stlsoft_collections_functions);
	} // anonymous namespace

} // namespace unittest
