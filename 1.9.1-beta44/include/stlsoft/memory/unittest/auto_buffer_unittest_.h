
// Updated: 30th May 2006

#if !defined(STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER)
# error This file cannot be directly included, and should only be included within stlsoft/memory/auto_buffer.hpp
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace ab_util
		{
			// TODO: Incorporate this into the 1.10/XSTL2 changes

			template<	ss_typename_param_k I
					,	ss_typename_param_k V
					>
			// [[synesis:function:algorithm: std_find(T<I> first, T<I> last, T<V> const &value)]]
			inline I find_not(I first, I last, V const &value)
			{
				for(; first != last; ++first)
				{
					if(value != *first)
					{
						break;
					}
				}

				return first;
			}
		}

		ss_bool_t test_stlsoft_memory_auto_buffer_1(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef auto_buffer_old<int
								,	allocator_selector<int>::allocator_type
								,	16
								>		buffer_t;

			buffer_t	buffer1(10);
			buffer_t	buffer2(100);

			/* Check that resizing within the internal_size() does not
			 * change the pointer.
			 */
			int *pi = buffer1.data();

			for(ss_size_t c = 1; bSuccess && c < buffer1.internal_size(); ++c)
			{
				buffer1.resize(c);

				if(pi != buffer1.data())
				{
					r->report("auto_buffer resize not allocated from internal buffer: failed", __LINE__);
					bSuccess = false;
				}
			}

#if defined(STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT)
			/* Check that forward and backward iteration provide the same result. */
			int total_forward	=	stlsoft_ns_qual_std(accumulate)(buffer2.begin(), buffer2.end(), 0);
			int total_backward	=	stlsoft_ns_qual_std(accumulate)(buffer2.rbegin(), buffer2.rend(), 0);

			if(total_forward != total_backward)
			{
				r->report("Forward and backward enumeration equivalence failed", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */

			return bSuccess;
		}

		ss_bool_t test_stlsoft_memory_auto_buffer_2(unittest_reporter *r)
		{
			typedef auto_buffer<int, 100>	buffer_t;

			ss_bool_t				bSuccess	=	true;

			buffer_t				buffer(0);

			// make it legal to call buffer[0]
			buffer.resize(1);

			// get hold of the pointer to the first element in the internal array
			const buffer_t::pointer p0	=	&buffer[0];

			// 1. Test that resizing to > internal_size() allocates to a separate array

			buffer.resize(buffer.internal_size() + 1);

			if(p0 == &buffer[0])
			{
				r->report("&auto_buffer[0] is not in the external array: failed", __LINE__);
				bSuccess = false;
			}

#if !defined(STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK)
			buffer.resize(buffer.internal_size());

			if(p0 == &buffer[0])
			{
				r->report("&auto_buffer[0] is in the internal array: failed", __LINE__);
				bSuccess = false;
			}
#endif /* !STLSOFT_AUTO_BUFFER_AGGRESSIVE_SHRINK */

			// 3. Test that resizing to 0 makes the

			buffer.resize(0);

			if(p0 != &buffer[0])
			{
				r->report("resize(0) did not return to the internal array: failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_memory_auto_buffer_3(unittest_reporter *r)
		{
			typedef auto_buffer<char, 10>	buffer_t;

			ss_bool_t				bSuccess	=	true;
			buffer_t				buff1(5);
			buffer_t				buff2(50);

			memset(&buff1[0], '1', buff1.size());
			memset(&buff2[0], '2', buff2.size());

			// 1. Verify that buff1 contains only '1'
			if( buff1.begin() != std::find(buff1.begin(), buff1.end(), '1') ||
				buff1.end() != ab_util::find_not(buff1.begin(), buff1.end(), '1'))
			{
				r->report("invalid contents for buff1: failed", __LINE__);
				bSuccess = false;
			}

			// 2. Verify that buff1 contains only '2'
			if( buff2.begin() != std::find(buff2.begin(), buff2.end(), '2') ||
				buff2.end() != ab_util::find_not(buff2.begin(), buff2.end(), '2'))
			{
				r->report("invalid contents for buff2: failed", __LINE__);
				bSuccess = false;
			}

			buff1.swap(buff2);

			// 1. Verify that buff1 contains only '2'
			if( buff1.begin() != std::find(buff1.begin(), buff1.end(), '2') ||
				buff1.end() != ab_util::find_not(buff1.begin(), buff1.end(), '2'))
			{
				r->report("invalid contents for buff1: failed", __LINE__);
				bSuccess = false;
			}

			// 2. Verify that buff1 contains only '1'
			if( buff2.begin() != std::find(buff2.begin(), buff2.end(), '1') ||
				buff2.end() != ab_util::find_not(buff2.begin(), buff2.end(), '1'))
			{
				r->report("invalid contents for buff2: failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_memory_auto_buffer_4(unittest_reporter *r)
		{
			typedef auto_buffer<char, 10>	buffer_t;

			ss_bool_t				bSuccess	=	true;
			buffer_t				buff1(5);
			buffer_t				buff2(50);

			memset(&buff1[0], '1', buff1.size());
			memset(&buff2[0], '2', buff2.size());

			// 1. Verify that buff1 contains only '1'
			if( buff1.begin() != std::find(buff1.begin(), buff1.end(), '1') ||
				buff1.end() != ab_util::find_not(buff1.begin(), buff1.end(), '1'))
			{
				r->report("invalid contents for buff1: failed", __LINE__);
				bSuccess = false;
			}

			// 2. Verify that buff1 contains only '2'
			if( buff2.begin() != std::find(buff2.begin(), buff2.end(), '2') ||
				buff2.end() != ab_util::find_not(buff2.begin(), buff2.end(), '2'))
			{
				r->report("invalid contents for buff2: failed", __LINE__);
				bSuccess = false;
			}

			buff1.resize(11);
			memset(&buff1[0], '1', buff1.size());

			buff1.resize(9);

			buff1.swap(buff2);

			// 1. Verify that buff1 contains only '2'
			if( buff1.begin() != std::find(buff1.begin(), buff1.end(), '2') ||
				buff1.end() != ab_util::find_not(buff1.begin(), buff1.end(), '2'))
			{
				r->report("invalid contents for buff1: failed", __LINE__);
				bSuccess = false;
			}

			// 2. Verify that buff1 contains only '1'
			if( buff2.begin() != std::find(buff2.begin(), buff2.end(), '1') ||
				buff2.end() != ab_util::find_not(buff2.begin(), buff2.end(), '1'))
			{
				r->report("invalid contents for buff2: failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_memory_auto_buffer(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;
			unittest_initialiser	init(r, "STLSoft", "memory/auto_buffer", __FILE__);

			if(!test_stlsoft_memory_auto_buffer_1(r))
			{
				bSuccess	=	false;
			}
			if(!test_stlsoft_memory_auto_buffer_2(r))
			{
				bSuccess	=	false;
			}
			if(!test_stlsoft_memory_auto_buffer_3(r))
			{
				bSuccess	=	false;
			}
			if(!test_stlsoft_memory_auto_buffer_4(r))
			{
				bSuccess	=	false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_memory_auto_buffer(test_stlsoft_memory_auto_buffer);
	} // anonymous namespace

} // namespace unittest
