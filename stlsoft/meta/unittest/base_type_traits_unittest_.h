
// Updated: 29th December 2005

#if !defined(STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS)
# error This file cannot be directly included, and should only be included within stlsoft/meta/base_type_traits.hpp
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
#if !defined(STLSOFT_COMPILER_IS_WATCOM)

    namespace
    {
        template<   ss_int_t bIsPointer
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_pointer_(T)
        {
            typedef base_type_traits<T>     base_type_traits_t;

            STLSOFT_STATIC_ASSERT(base_type_traits_t::is_pointer    ==  bIsPointer);
        }

        template<   ss_int_t bIsReference
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_reference_(T)
        {
            typedef base_type_traits<T>     base_type_traits_t;

            STLSOFT_STATIC_ASSERT(base_type_traits_t::is_reference  ==  bIsReference);
        }

        template<   ss_int_t bIsConst
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_const_(T&)
        {
            typedef base_type_traits<T>     base_type_traits_t;

            STLSOFT_STATIC_ASSERT(base_type_traits_t::is_const      ==  bIsConst);
        }

        template<   ss_int_t bIsVolatile
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_volatile_(T&)
        {
            typedef base_type_traits<T>     base_type_traits_t;

            STLSOFT_STATIC_ASSERT(base_type_traits_t::is_volatile   ==  bIsVolatile);
        }

        template<   ss_int_t bIsArray
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_array_(T&)
        {
#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            typedef base_type_traits<T>     base_type_traits_t;

            STLSOFT_STATIC_ASSERT(base_type_traits_t::is_array      ==  bIsArray);
#  else /* ? __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
            STLSOFT_STATIC_ASSERT(0                                 ==  bIsArray);
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
        }

        template<   ss_int_t bIsArrayOrPointer
                ,   ss_typename_param_k T
                >
        void type_traits_type_test_array_or_pointer_(T&)
        {
            typedef base_type_traits<T>     base_type_traits_t;

            const int is_array_or_pointer   =   0
#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
                                            ||  (0 != base_type_traits_t::is_array)
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
                                            ||  (0 != base_type_traits_t::is_pointer)
                                            ;

            STLSOFT_STATIC_ASSERT(is_array_or_pointer               ==  bIsArrayOrPointer);

            STLSOFT_SUPPRESS_UNUSED(is_array_or_pointer);
        }

        ss_bool_t test_stlsoft_meta_base_type_traits(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "meta/base_type_traits", __FILE__);

# ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
            int                     i       =   0;
            const int               ci      =   1;
            volatile int            vi      =   2;
            const volatile int      cvi     =   3;

            STLSOFT_SUPPRESS_UNUSED(i);
            STLSOFT_SUPPRESS_UNUSED(ci);
            STLSOFT_SUPPRESS_UNUSED(vi);
            STLSOFT_SUPPRESS_UNUSED(cvi);

            int                     *pi     =   &i;
            int const               *pci    =   &ci;
            int volatile            *pvi    =   &vi;
            int const volatile      *pcvi   =   &cvi;

            STLSOFT_SUPPRESS_UNUSED(pi);
            STLSOFT_SUPPRESS_UNUSED(pci);
            STLSOFT_SUPPRESS_UNUSED(pvi);
            STLSOFT_SUPPRESS_UNUSED(pcvi);

            int                     &ri     =   i;
            int const               &rci    =   ci;
            int volatile            &rvi    =   vi;
            int const volatile      &rcvi   =   cvi;

            STLSOFT_SUPPRESS_UNUSED(ri);
            STLSOFT_SUPPRESS_UNUSED(rci);
            STLSOFT_SUPPRESS_UNUSED(rvi);
            STLSOFT_SUPPRESS_UNUSED(rcvi);

            int                     *&rpi   =   pi;
            int const               *&rpci  =   pci;
            int volatile            *&rpvi  =   pvi;
            int const volatile      *&rpcvi =   pcvi;

            STLSOFT_SUPPRESS_UNUSED(rpi);
            STLSOFT_SUPPRESS_UNUSED(rpci);
            STLSOFT_SUPPRESS_UNUSED(rpvi);
            STLSOFT_SUPPRESS_UNUSED(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            int                     ai[]    =   { 4 };
            int const               aci[]   =   { 5 };
            int volatile            avi[]   =   { 6 };
            int const volatile      acvi[]  =   { 7 };

            STLSOFT_SUPPRESS_UNUSED(ai);
            STLSOFT_SUPPRESS_UNUSED(aci);
            STLSOFT_SUPPRESS_UNUSED(avi);
            STLSOFT_SUPPRESS_UNUSED(acvi);

#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            // 1. Test pointer

            type_traits_type_test_pointer_<0>(i);
            type_traits_type_test_pointer_<0>(ci);
            type_traits_type_test_pointer_<0>(vi);
            type_traits_type_test_pointer_<0>(cvi);

            type_traits_type_test_pointer_<1>(pi);
            type_traits_type_test_pointer_<1>(pci);
            type_traits_type_test_pointer_<1>(pvi);
            type_traits_type_test_pointer_<1>(pcvi);

            type_traits_type_test_pointer_<0>(ri);
            type_traits_type_test_pointer_<0>(rci);
            type_traits_type_test_pointer_<0>(rvi);
            type_traits_type_test_pointer_<0>(rcvi);

            type_traits_type_test_pointer_<1>(rpi);
            type_traits_type_test_pointer_<1>(rpci);
            type_traits_type_test_pointer_<1>(rpvi);
            type_traits_type_test_pointer_<1>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            type_traits_type_test_pointer_<1>(ai);
            type_traits_type_test_pointer_<1>(aci);
            type_traits_type_test_pointer_<1>(avi);
            type_traits_type_test_pointer_<1>(acvi);
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            // 2. Test reference

            type_traits_type_test_reference_<0>(i);
            type_traits_type_test_reference_<0>(ci);
            type_traits_type_test_reference_<0>(vi);
            type_traits_type_test_reference_<0>(cvi);

            type_traits_type_test_reference_<0>(pi);
            type_traits_type_test_reference_<0>(pci);
            type_traits_type_test_reference_<0>(pvi);
            type_traits_type_test_reference_<0>(pcvi);

//          type_traits_type_test_reference_<1>(ri);
//          type_traits_type_test_reference_<1>(rci);
//          type_traits_type_test_reference_<1>(rvi);
//          type_traits_type_test_reference_<1>(rcvi);

//          type_traits_type_test_reference_<1>(rpi);
//          type_traits_type_test_reference_<1>(rpci);
//          type_traits_type_test_reference_<1>(rpvi);
//          type_traits_type_test_reference_<1>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
//          type_traits_type_test_reference_<1>(ai);
//          type_traits_type_test_reference_<1>(aci);
//          type_traits_type_test_reference_<1>(avi);
//          type_traits_type_test_reference_<1>(acvi);
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */


            // 3. Test const

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_DMC)
            type_traits_type_test_const_<0>(i);
            type_traits_type_test_const_<1>(ci);
            type_traits_type_test_const_<0>(vi);
            type_traits_type_test_const_<1>(cvi);

            type_traits_type_test_const_<0>(pi);
            type_traits_type_test_const_<1>(pci);
            type_traits_type_test_const_<0>(pvi);
            type_traits_type_test_const_<1>(pcvi);

            type_traits_type_test_const_<0>(ri);
            type_traits_type_test_const_<1>(rci);
            type_traits_type_test_const_<0>(rvi);
            type_traits_type_test_const_<1>(rcvi);

            type_traits_type_test_const_<0>(rpi);
            type_traits_type_test_const_<1>(rpci);
            type_traits_type_test_const_<0>(rpvi);
            type_traits_type_test_const_<1>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            type_traits_type_test_const_<0>(ai);
#   if !defined(STLSOFT_COMPILER_IS_MSVC)
            type_traits_type_test_const_<1>(aci);
#   endif /* compiler */
            type_traits_type_test_const_<0>(avi);
#   if !defined(STLSOFT_COMPILER_IS_MSVC)
            type_traits_type_test_const_<1>(acvi);
#   endif /* compiler */
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            // 4. Test volatile

            type_traits_type_test_volatile_<0>(i);
            type_traits_type_test_volatile_<0>(ci);
            type_traits_type_test_volatile_<1>(vi);
            type_traits_type_test_volatile_<1>(cvi);

            type_traits_type_test_volatile_<0>(pi);
            type_traits_type_test_volatile_<0>(pci);
            type_traits_type_test_volatile_<1>(pvi);
            type_traits_type_test_volatile_<1>(pcvi);

            type_traits_type_test_volatile_<0>(ri);
            type_traits_type_test_volatile_<0>(rci);
            type_traits_type_test_volatile_<1>(rvi);
            type_traits_type_test_volatile_<1>(rcvi);

            type_traits_type_test_volatile_<0>(rpi);
            type_traits_type_test_volatile_<0>(rpci);
            type_traits_type_test_volatile_<1>(rpvi);
            type_traits_type_test_volatile_<1>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            type_traits_type_test_volatile_<0>(ai);
            type_traits_type_test_volatile_<0>(aci);
#   if !defined(STLSOFT_COMPILER_IS_MSVC)
            type_traits_type_test_volatile_<1>(avi);
            type_traits_type_test_volatile_<1>(acvi);
#   endif /* compiler */
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#endif /* compiler */


            // 5. Test array

            type_traits_type_test_array_<0>(i);
            type_traits_type_test_array_<0>(ci);
            type_traits_type_test_array_<0>(vi);
            type_traits_type_test_array_<0>(cvi);

            type_traits_type_test_array_<0>(pi);
            type_traits_type_test_array_<0>(pci);
            type_traits_type_test_array_<0>(pvi);
            type_traits_type_test_array_<0>(pcvi);

            type_traits_type_test_array_<0>(ri);
            type_traits_type_test_array_<0>(rci);
            type_traits_type_test_array_<0>(rvi);
            type_traits_type_test_array_<0>(rcvi);

            type_traits_type_test_array_<0>(rpi);
            type_traits_type_test_array_<0>(rpci);
            type_traits_type_test_array_<0>(rpvi);
            type_traits_type_test_array_<0>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            type_traits_type_test_array_<1>(ai);
            type_traits_type_test_array_<1>(aci);
            type_traits_type_test_array_<1>(avi);
            type_traits_type_test_array_<1>(acvi);
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

            // 6. Test array or pointer

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_DMC)
            type_traits_type_test_array_or_pointer_<0>(i);
            type_traits_type_test_array_or_pointer_<0>(ci);
            type_traits_type_test_array_or_pointer_<0>(vi);
            type_traits_type_test_array_or_pointer_<0>(cvi);

            type_traits_type_test_array_or_pointer_<1>(pi);
            type_traits_type_test_array_or_pointer_<1>(pci);
            type_traits_type_test_array_or_pointer_<1>(pvi);
            type_traits_type_test_array_or_pointer_<1>(pcvi);

            type_traits_type_test_array_or_pointer_<0>(ri);
            type_traits_type_test_array_or_pointer_<0>(rci);
            type_traits_type_test_array_or_pointer_<0>(rvi);
            type_traits_type_test_array_or_pointer_<0>(rcvi);

            type_traits_type_test_array_or_pointer_<1>(rpi);
            type_traits_type_test_array_or_pointer_<1>(rpci);
            type_traits_type_test_array_or_pointer_<1>(rpvi);
            type_traits_type_test_array_or_pointer_<1>(rpcvi);

#  ifdef __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
            type_traits_type_test_array_or_pointer_<1>(ai);
            type_traits_type_test_array_or_pointer_<1>(aci);
            type_traits_type_test_array_or_pointer_<1>(avi);
            type_traits_type_test_array_or_pointer_<1>(acvi);
#  endif /* __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#endif /* compiler */

# endif /* STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_meta_base_type_traits(test_stlsoft_meta_base_type_traits);
    } // anonymous namespace

#endif /* compiler */

} // namespace unittest
