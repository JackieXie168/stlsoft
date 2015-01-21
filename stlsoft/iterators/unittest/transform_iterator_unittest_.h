
// Updated: 21st March 2006

#if !defined(STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR)
# error This file cannot be directly included, and should only be included within stlsoft/iterators/transform_iterator.hpp
#endif /* !STLSOFT_INCL_STLSOFT_ITERATORS_HPP_TRANSFORM_ITERATOR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
        ss_bool_t test_stlsoft_transform_iterator_1(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;
            const int   ints[]      =   { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };
            int         results[STLSOFT_NUM_ELEMENTS(ints)];

            typedef stlsoft::transform_iterator<int const*
                                            ,   std::pointer_to_unary_function<int, int>
                                            >       abs_iter_t;

            abs_iter_t  b   =   abs_iter_t(&ints[0], std::ptr_fun(::abs));
            abs_iter_t  e   =   abs_iter_t(&ints[0] + STLSOFT_NUM_ELEMENTS(ints), std::ptr_fun(::abs));

            std::copy(b, e, &results[0]);

            { for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ints); ++i)
            {
                if(ints[i] == results[i])
                {
                }
                else if(ints[i] == -results[i])
                {
                }
                else
                {
                    r->report("Elements in the transformed range are not equal, or the abs() equivalent", __LINE__);
                    bSuccess = false;
                }
            }}

            return bSuccess;
        }

        ss_bool_t test_stlsoft_transform_iterator_2(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;
            const int   ints[]      =   { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };
            int         results[STLSOFT_NUM_ELEMENTS(ints)];

            std::copy(  transformer(&ints[0], std::ptr_fun(::abs))
                    ,   transformer(&ints[0] + STLSOFT_NUM_ELEMENTS(ints), std::ptr_fun(::abs))
                    ,   &results[0]);

            { for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ints); ++i)
            {
                if(ints[i] == results[i])
                {
                }
                else if(ints[i] == -results[i])
                {
                }
                else
                {
                    r->report("Elements in the transformed range are not equal, or the abs() equivalent", __LINE__);
                    bSuccess = false;
                }
            }}

            return bSuccess;
        }

        namespace tx_iter_util
        {
            struct stringise
                : public stlsoft_ns_qual_std(unary_function)<int, std::string>
            {
                std::string operator ()(int i)
                {
                    char    sz[21];

                    return integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), i);
                }
            };


        } // namespace tx_iter_util

        ss_bool_t test_stlsoft_transform_iterator_3(unittest_reporter *r)
        {
            ss_bool_t   bSuccess    =   true;

            typedef std::string             string_t;
            typedef std::vector<string_t>   strings_t;

            const int   ints[]      =   { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };

            strings_t   results(STLSOFT_NUM_ELEMENTS(ints));

            std::copy(  transformer(&ints[0], tx_iter_util::stringise())
                    ,   transformer(&ints[0] + STLSOFT_NUM_ELEMENTS(ints), tx_iter_util::stringise())
                    ,   &results[0]);

            { for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ints); ++i)
            {
                char    sz[21];

                ::sprintf(&sz[0], "%d", ints[i]);

                if(sz != results[i])
                {
                    r->report("Elements in the transformed range are not equal", __LINE__);
                    bSuccess = false;
                }
            }}

            return bSuccess;
        }
#endif /* compiler */

        ss_bool_t test_stlsoft_transform_iterator(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "transform_iterator", __FILE__);

#if !defined(STLSOFT_COMPILER_IS_BORLAND)
            if(!test_stlsoft_transform_iterator_1(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_transform_iterator_2(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_transform_iterator_3(r))
            {
                bSuccess = false;
            }
#endif /* compiler */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_transform_iterator(test_stlsoft_transform_iterator);
    } // anonymous namespace

} // namespace unittest

