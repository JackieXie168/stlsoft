
// Updated: 23rd December 2005

#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_STRING_CONCATENATOR_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/string_concatenator_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_STRING_CONCATENATOR_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        ss_bool_t test_stlsoft_iterators_string_concatenator_iterator(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "iterators/string_concatenator_iterator", __FILE__);

            typedef std::string             string_t;
            typedef std::vector<string_t>   strings_t;

            {
                strings_t       strings;
                string_t        result;

                strings.push_back("abc");
                strings.push_back("def");
                strings.push_back("ghi");

                std::copy(  strings.begin(), strings.end()
                        ,   stlsoft::string_concatenator(result, ","));

                if(result != "abc,def,ghi")
                {
                    r->report("string_concatenator() failed", __LINE__);
                    bSuccess = false;
                }
            }

            {
                strings_t       strings;
                string_t        result;
                const string_t  sep(",");

                strings.push_back("abc");
                strings.push_back("def");
                strings.push_back("ghi");

                std::copy(  strings.begin(), strings.end()
                        ,   stlsoft::string_concatenator(result, sep));

                if(result != "abc,def,ghi")
                {
                    r->report("string_concatenator() failed", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_iterators_string_concatenator_iterator(test_stlsoft_iterators_string_concatenator_iterator);
    } // anonymous namespace

} // namespace unittest
