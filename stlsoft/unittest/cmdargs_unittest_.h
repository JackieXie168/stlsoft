
#if !defined(STLSOFT_INCL_STLSOFT_HPP_CMDARGS)
# error This file cannot be directly included, and should only be included within stlsoft/cmdargs.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_CMDARGS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_cmdargs(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "cmdargs", __FILE__);

            { // empty
                char    *argv[] = 
                {
                        "dummyprocname"
                    ,   NULL
                };

                cmdargs     args(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

                if(0 != args.options_size())
                {
                    r->report("cmdargs::options_size() returned invalid value for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(0 != args.values_size())
                {
                    r->report("cmdargs::values_size() returned invalid value for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(0 != args.size())
                {
                    r->report("cmdargs::size() returned invalid value for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.options_begin() != args.options_end())
                {
                    r->report("cmdargs::options_begin() != cmdargs::options_end() for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.values_begin() != args.values_end())
                {
                    r->report("cmdargs::values_begin() != cmdargs::values_end() for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(!args.options().empty())
                {
                    r->report("cmdargs::options() returns non-empty collection for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(!args.values().empty())
                {
                    r->report("cmdargs::values() returns non-empty collection for empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }
            }


            { // non-empty
                char    *argv[] = 
                {
                        "dummyprocname"
                    ,   "value0"
                    ,   "-option0=ov0"
                    ,   "--option1=ov1"
                    ,   "value1"
                    ,   "-option2"
                    ,   "---option3"
                    ,   NULL
                };

                cmdargs     args(STLSOFT_NUM_ELEMENTS(argv) - 1, argv);

                if(4 != args.options_size())
                {
                    r->report("cmdargs::options_size() returned invalid value for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(2 != args.values_size())
                {
                    r->report("cmdargs::values_size() returned invalid value for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(6 != args.size())
                {
                    r->report("cmdargs::size() returned invalid value for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.options_begin() == args.options_end())
                {
                    r->report("cmdargs::options_begin() == cmdargs::options_end() for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.values_begin() == args.values_end())
                {
                    r->report("cmdargs::values_begin() == cmdargs::values_end() for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.options().empty())
                {
                    r->report("cmdargs::options() returns empty collection for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(args.values().empty())
                {
                    r->report("cmdargs::values() returns empty collection for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                cmdargs::option const   &option0    =   args.options()[0];
                cmdargs::option const   &option1    =   args.options()[1];
                cmdargs::option const   &option2    =   args.options()[2];
                cmdargs::option const   &option3    =   args.options()[3];

                cmdargs::value const    &value0     =   args.values()[0];
                cmdargs::value const    &value1     =   args.values()[1];

                if(option0.m_name != "option0")
                {
                    r->report("cmdargs option[0] not valid (name) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(option0.m_value != "ov0")
                {
                    r->report("cmdargs option[0] not valid (value) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(option0.m_type != cmdargs::singleDash)
                {
                    r->report("cmdargs option[0] not valid (type) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(option0.m_index != 2)
                {
                    r->report("cmdargs option[0] not valid (index) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(option0.m_original != "-option0=ov0")
                {
                    r->report("cmdargs option[0] not valid (original) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if( option1.m_name != "option1" ||
                    option1.m_value != "ov1" ||
                    option1.m_type != cmdargs::doubleDash ||
                    option1.m_index != 3 ||
                    option1.m_original != "--option1=ov1")
                {
                    r->report("cmdargs option[1] not valid for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if( option2.m_name != "option2" ||
                    option2.m_value != "" ||
                    option2.m_type != cmdargs::singleDash ||
                    option2.m_index != 5 ||
                    option2.m_original != "-option2")
                {
                    r->report("cmdargs option[2] not valid for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if( option3.m_name != "-option3" ||
                    option3.m_value != "" ||
                    option3.m_type != cmdargs::doubleDash ||
                    option3.m_index != 6 ||
                    option3.m_original != "---option3")
                {
                    r->report("cmdargs option[3] not valid for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(value0.m_value != "value0")
                {
                    r->report("cmdargs value[0] not valid (value) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if(value0.m_index != 1)
                {
                    r->report("cmdargs value[0] not valid (index) for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }

                if( value1.m_value != "value1" ||
                    value1.m_index != 4)
                {
                    r->report("cmdargs value[1] not valid for non-empty cmdargs instance", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_cmdargs(test_stlsoft_cmdargs);
    } // anonymous namespace

} // namespace unittest
