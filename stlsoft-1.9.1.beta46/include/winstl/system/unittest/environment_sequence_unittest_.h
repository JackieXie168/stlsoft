
// Updated: 12th March 2007

#if !defined(WINSTL_INCL_WINSTL_SYSTEM_HPP_ENVIRONMENT_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/system/environment_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_ENVIRONMENT_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_system_environment_sequence_instance(environment_sequence const& es, unittest_reporter *r)
		{
			ss_bool_t	bSuccess	=	true;

			if(es.empty() != (0 == es.size()))
			{
				r->report("empty() == !size() failed", __LINE__);
				bSuccess = false;
			}

			{ environment_sequence::const_iterator	b	=	es.begin();
			  size_t								i	=	0;
			for(; b != es.end(); ++b, ++i)
			{
				if((*b).name != es[i].name)
				{
					r->report("iterator / subscript match failed", __LINE__);
					bSuccess = false;
				}
			}}

			{ environment_sequence::const_iterator	b	=	es.begin();
			  size_t								i	=	0;
			for(; b != es.end(); ++b, ++i)
			{
				environment_sequence::const_iterator	b2;

				if(b != (b2 = es.find((*b).name)))
				{
					r->report("find(name) failed to find existing name", __LINE__);
					bSuccess = false;
				}

				if(b != (b2 = es.find((*b).name, (*b).value)))
				{
					r->report("find(name, value) failed to find existing name/value", __LINE__);
					bSuccess = false;
				}

				// Now munge the value, to something that it is not
				TCHAR	badValue[2];

				lstrcpyn(badValue, (*b).value, STLSOFT_NUM_ELEMENTS(badValue));

				badValue[0]++;
				badValue[1] = '\0';

				if(b == (b2 = es.find((*b).name, badValue)))
				{
					r->report("find(name, value) erroneously found non-existant name/value", __LINE__);
					bSuccess = false;
				}

				STLSOFT_SUPPRESS_UNUSED(b2);
			}}

			return bSuccess;
		}

		ss_bool_t test_winstl_system_environment_sequence(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "system/environment_sequence", __FILE__);

			environment_sequence	es0(0);

			if(!test_winstl_system_environment_sequence_instance(es0, r))
			{
				bSuccess = false;
			}

			environment_sequence	es1(environment_sequence::showHidden);

			if(!test_winstl_system_environment_sequence_instance(es1, r))
			{
				bSuccess = false;
			}

			environment_sequence	es2(environment_sequence::noSort);

			if(!test_winstl_system_environment_sequence_instance(es2, r))
			{
				bSuccess = false;
			}

			environment_sequence	es3(environment_sequence::showHidden | environment_sequence::noSort);

			if(!test_winstl_system_environment_sequence_instance(es3, r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_system_environment_sequence(test_winstl_system_environment_sequence);
	} // anonymous namespace

} // namespace unittest
