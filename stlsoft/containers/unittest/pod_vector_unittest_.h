
#if !defined(STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_POD_VECTOR)
# error This file cannot be directly included, and should only be included within stlsoft/containers/pod_vector.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_POD_VECTOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_containers_pod_vector(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "containers/pod_vector", __FILE__);

			typedef pod_vector< int
							,	stlsoft::allocator_selector<int>::allocator_type
							,	64
							>			iv_t;

			// Set up some vectors
			iv_t		v1(10);
			iv_t		v2(32, 1);
			iv_t const	v3(100, -1);
			ss_size_t	i;

			for(i = 0; i < v1.size(); ++i)
			{
				v1[i] = static_cast<int>(i);
			}
			for(i = 0; i < v2.size(); ++i)
			{
				v2[i] = static_cast<int>(i * 100);
			}

			// (i) Test copy construction
			iv_t		v4(v1);

#if !defined(STLSOFT_COMPILER_IS_DMC) || \
	__DMC__ < 0x0845
			if(v4 != v1)
			{
				r->report("copy construction failed", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			// (ii) Test iterator construction
			iv_t		v5(const_cast<iv_t const&>(v2).begin(), const_cast<iv_t const&>(v2).end());

#if !defined(STLSOFT_COMPILER_IS_DMC) || \
	__DMC__ < 0x0845
			if(v5 != v2)
			{
				r->report("iterator construction failed", __LINE__);
				bSuccess = false;
			}
#endif /* compiler */

			v1.begin();
			v2.begin();
			v1.end();
			v2.end();
#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
			v1.rbegin();
			v2.rbegin();
			v1.rend();
			v2.rend();
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

			v1.size();
			v2.capacity();
			v3.max_size();
			v4.empty();
			v1.get_allocator();

			STLSOFT_SUPPRESS_UNUSED(v1.at(0));
			STLSOFT_SUPPRESS_UNUSED(v2.at(0));
			STLSOFT_SUPPRESS_UNUSED(v1[0]);
			STLSOFT_SUPPRESS_UNUSED(v2[0]);
			STLSOFT_SUPPRESS_UNUSED(v1.front());
			STLSOFT_SUPPRESS_UNUSED(v2.front());
			STLSOFT_SUPPRESS_UNUSED(v1.back());
			STLSOFT_SUPPRESS_UNUSED(v2.back());

			v1.clear();
			v1.swap(v4);
			v1.reserve(v1.size() * 2);
			v1.resize(v1.capacity());
			v4.resize(1000, 127);
			v1.push_back(101);
			v1.pop_back();

			v1.assign(const_cast<iv_t const&>(v4).begin(), const_cast<iv_t const&>(v4).end());
#if 0
			v3.assign(100, 65535);
#endif /* 0 */

#if 0
			iterator	insert(iterator it, value_type const &value = value_type());
			void		insert(iterator it, size_type cItems, value_type const &value);
			void		insert(iterator it, const_iterator first, const_iterator last);
			iterator	erase(iterator it);
			iterator	erase(iterator first, iterator last);
#endif /* 0 */

//#else /* ? compiler */
//			STLSOFT_SUPPRESS_UNUSED(bSuccess);
//#endif /* compiler */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_containers_pod_vector(test_stlsoft_containers_pod_vector);
	} // anonymous namespace

} // namespace unittest
