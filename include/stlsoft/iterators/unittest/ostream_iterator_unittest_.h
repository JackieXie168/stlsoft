
// Updated: 21st March 2006

#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/ostream_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_OSTREAM_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_ostream_iterator(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "ostream_iterator", __FILE__);

			char const				*strings[] =
			{
					"abc"
				,	"de"
				,	"fgh"
				,	""
				,	"i"
				,	"jkl"
			};

#if !defined(STLSOFT_COMPILER_IS_DMC)
			{
				std::stringstream		ss;

				stlsoft_ns_qual_std(copy)(	&strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
										,	stlsoft_ns_qual(ostream_iterator)<char const*>(ss));

				if(ss.str() != "abcdefghijkl")
				{
					r->report("stream concatenation failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}

			{
				std::stringstream		ss;

				stlsoft_ns_qual_std(copy)(	&strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
										,	stlsoft_ns_qual(ostream_iterator)<char const*>(ss, ","));

				if(ss.str() != "abc,de,fgh,,i,jkl,")
				{
					r->report("stream concatenation failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}

			{
				std::stringstream		ss;

				stlsoft_ns_qual_std(copy)(	&strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
										,	stlsoft_ns_qual(ostream_iterator)<char const*>(ss, "<<", "]]"));

				if(ss.str() != "<<abc]]<<de]]<<fgh]]<<]]<<i]]<<jkl]]")
				{
					r->report("stream concatenation failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
			}
#endif /* compiler */

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_ostream_iterator(test_stlsoft_ostream_iterator);
	} // anonymous namespace

} // namespace unittest
