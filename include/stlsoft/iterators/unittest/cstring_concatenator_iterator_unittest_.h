
// Updated: 21st March 2006

#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/cstring_concatenator_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_CSTRING_CONCATENATOR_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_iterators_cstring_concatenator_iterator(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "iterators/cstring_concatenator_iterator", __FILE__);

			{
				char const	*strings[] =
				{
						"abc"
					,	"defg"
					,	"h"
					,	"i"
					,	"jklm"
				};

				char		result[14];
				size_t		n	=	0;

				std::copy(	&strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
						,	stlsoft::cstring_concatenator(&result[0], &n));
				result[STLSOFT_NUM_ELEMENTS(result) - 1] = '\0';

				if(0 != ::strcmp(result, "abcdefghijklm"))
				{
					r->report("c-string concatenation failed: incorrect contents", __LINE__);
					bSuccess = false;
				}
				if(13 != n)
				{
					r->report("c-string concatenation failed: incorrect length", __LINE__);
					bSuccess = false;
				}
			}

			{
				char const	*strings[] =
				{
						"abc"
					,	"defg"
					,	"h"
					,	"i"
					,	"jklm"
				};

				char		result[14];

				std::copy(	&strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
						,	stlsoft::cstring_concatenator(&result[0]));
				result[STLSOFT_NUM_ELEMENTS(result) - 1] = '\0';

				if(0 != ::strcmp(result, "abcdefghijklm"))
				{
					r->report("c-string concatenation failed", __LINE__);
					bSuccess = false;
				}
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_iterators_cstring_concatenator_iterator(test_stlsoft_iterators_cstring_concatenator_iterator);
	} // anonymous namespace

} // namespace unittest

