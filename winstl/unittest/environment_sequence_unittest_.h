
// Updated: 4th October 2005

#if !defined(WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_SEQUENCE)
# error This file cannot be directly included, and should only be included within winstl/environment_sequence.hpp
#endif /* !WINSTL_INCL_WINSTL_HPP_ENVIRONMENT_SEQUENCE */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_winstl_environment_sequence_instance(environment_sequence const &es, unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            if(es.empty() != (0 == es.size()))
            {
                r->report("empty() == !size() failed", __LINE__);
                bSuccess = false;
            }

            { environment_sequence::const_iterator  b   =   es.begin();
              size_t                                i   =   0;
            for(; b != es.end(); ++b, ++i)
            {
                if((*b).name != es[i].name)
                {
                    r->report("iterator / subscript match failed", __LINE__);
                    bSuccess = false;
                }
            }}

            { environment_sequence::const_iterator  b   =   es.begin();
              size_t                                i   =   0;
            for(; b != es.end(); ++b, ++i)
            {
                environment_sequence::const_iterator    b2;

//b2 = es.find((*b).name);
//fprintf(stderr, "Finding [%p, %s]=[%p, %s]\n        [%s=%s]\n        [%p, %s]\n", b, (*b).name, b2, (*b2).name, (*b).name, (*b).value, (*b2).name, (*b2).value);

                if(b != (b2 = es.find((*b).name)))
                {
//fprintf(stderr, "%s(%d):\n\t[%s]\n\t[%s]\n\t[%s]\n\n", __FILE__, __LINE__, (*b).name, (*b2).name, es[i].name);

                    r->report("find(name) failed to find existing name", __LINE__);
                    bSuccess = false;
                }

                if(b != (b2 = es.find((*b).name, (*b).value)))
                {
//fprintf(stderr, "%s(%d): \n\t[%s=%s]\n\t[%s=%s]\n\t[%s=%s]\n\n", __FILE__, __LINE__, (*b).name, (*b).value, (*b2).name, (*b2).value, es[i].name, es[i].value);

                    r->report("find(name, value) failed to find existing name/value", __LINE__);
                    bSuccess = false;
                }

                // Now munge the value, to something that it is not
                TCHAR   badValue[2];

                lstrcpyn(badValue, (*b).value, stlsoft_num_elements(badValue));

                badValue[0]++;
                badValue[1] = '\0';

//fprintf(stdout, "Finding [%s=%s] (real value=[%s])\n", (*b).name, badValue, (*b).value);
                if(b == (b2 = es.find((*b).name, badValue)))
                {
//fprintf(stderr, "%s(%d): \n\t[%s=%s]\n\t[%s=%s]\n\t[%s=%s]\n\n", __FILE__, __LINE__, (*b).name, (*b).value, (*b2).name, (*b2).value, es[i].name, es[i].value);

                    r->report("find(name, value) erroneously found non-existant name/value", __LINE__);
                    bSuccess = false;
                }

                STLSOFT_SUPPRESS_UNUSED(b2);
            }}

            return bSuccess;
        }

        ss_bool_t test_winstl_environment_sequence(unittest_reporter *r)
        {
            using stlsoft::unittest::unittest_initialiser;

            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "WinSTL", "environment_sequence", __FILE__);

            environment_sequence    es0(0);

            if(!test_winstl_environment_sequence_instance(es0, r))
            {
                bSuccess = false;
            }

            environment_sequence    es1(environment_sequence::showHidden);

            if(!test_winstl_environment_sequence_instance(es1, r))
            {
                bSuccess = false;
            }

            environment_sequence    es2(environment_sequence::noSort);

            if(!test_winstl_environment_sequence_instance(es2, r))
            {
                bSuccess = false;
            }

            environment_sequence    es3(environment_sequence::showHidden | environment_sequence::noSort);

            if(!test_winstl_environment_sequence_instance(es3, r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_winstl_environment_sequence(test_winstl_environment_sequence);
    } // anonymous namespace

} // namespace unittest
