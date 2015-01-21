
// Updated: 28th March 2006

#if !defined(STLSOFT_INCL_STLSOFT_HPP_REF_PTR)
# error This file cannot be directly included, and should only be included within stlsoft/ref_ptr.hpp
#endif /* !STLSOFT_INCL_STLSOFT_HPP_REF_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
    namespace
    {
        namespace RCIs
        {
            /// This definition extracted from Synesis Software's MIRefCnt.h
            ///
            /// (Licensed under the Synesis Software Standard Public License)
            struct IRefCounter
            {
                virtual void AddRef() throw() = 0;
                virtual void Release() throw() = 0;
            };

            class Base
                : public IRefCounter
            {
            public:
                Base()
                    : m_refCount(1)
                {}

            public:
                void AddRef() throw()
                {
                    ++m_refCount;
                }
                void Release() throw()
                {
                    --m_refCount;
                }

            public:
                long Count() const throw()
                {
                    return m_refCount;
                }

            private:
                long    m_refCount;

            private:
                Base(Base const &);
                Base &operator =(Base const &);
            };

            class Derived1
                : public Base
            {
            public:
                Derived1()
                {}
            private:
                Derived1(Derived1 const &);
                Derived1 &operator =(Derived1 const &);
            };

            class Derived2
                : public Base
            {
            public:
                Derived2()
                {}
            private:
                Derived2(Derived2 const &);
                Derived2 &operator =(Derived2 const &);
            };

            class Derived11
                : public Derived1
            {
            public:
                Derived11()
                {}
            private:
                Derived11(Derived11 const &);
                Derived11 &operator =(Derived11 const &);
            };

        } // namespace RCIs

        ss_bool_t test_stlsoft_ref_ptr_1(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>      Base_ptr;

            Base_ptr    p1;
            Base_ptr    p2(NULL, false);
            Base_ptr    p3(NULL, false);
            Base_ptr    p4(p1);

            if(NULL != p1.get())
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p2)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p2 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p3)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p3 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p4)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p4 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_ref_ptr_2(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>      Base_ptr;

            {
                RCIs::Base  base;
                const long  startCount  =   base.Count();
                Base_ptr    p1(&base, false);

                if(base.Count() != startCount)
                {
                    r->report("Constructor erroneously took a reference when bAddRef was false", __LINE__);
                    bSuccess = false;
                }

                if(&base != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
            }

            {
                RCIs::Base  base;
                const long  startCount  =   base.Count();
                Base_ptr    p1(&base, true);

                if(base.Count() != startCount + 1)
                {
                    r->report("Constructor failed to take a reference when bAddRef was true", __LINE__);
                    bSuccess = false;
                }

                if(&base != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
            }

            {
                RCIs::Base  base;
                const long  startCount  =   base.Count();
                Base_ptr    p1(&base, false);

                if(base.Count() != startCount)
                {
                    r->report("Constructor erroneously took a reference when bAddRef was false", __LINE__);
                    bSuccess = false;
                }

                if(&base != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }

                Base_ptr    p2(p1);

                if(base.Count() != startCount + 1)
                {
                    r->report("Copy constructor failed to take a reference", __LINE__);
                    bSuccess = false;
                }

                if(&base != p2.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
            }

            {
                RCIs::Base  base;
                const long  startCount  =   base.Count();
                Base_ptr    p1(&base, false);

                if(base.Count() != startCount)
                {
                    r->report("Constructor erroneously took a reference when bAddRef was false", __LINE__);
                    bSuccess = false;
                }

                if(&base != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }

                Base_ptr    p2;

                p2 = p1;

                if(base.Count() != startCount + 1)
                {
                    r->report("Copy constructor failed to take a reference", __LINE__);
                    bSuccess = false;
                }

                if(&base != p2.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_ref_ptr_3(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>      Base_ptr;
            typedef ref_ptr<RCIs::Derived1, RCIs::IRefCounter>  Derived1_ptr;

            {
                RCIs::Derived1  derived;
                const long      startCount  =   derived.Count();

//fprintf(stderr, "Derived::Count(): %ld\n", derived.Count());

                Derived1_ptr    p1(&derived, true);

//fprintf(stderr, "Derived::Count(): %ld\n", derived.Count());

                if(derived.Count() != startCount + 1)
                {
                    r->report("Constructor failed to take reference when bAddRef was true", __LINE__);
                    bSuccess = false;
                }

                if(&derived != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER != 1300
                Base_ptr        p2(p1);

                if(derived.Count() != startCount + 2)
                {
                    r->report("Constructor failed to take reference when bAddRef was true", __LINE__);
                    bSuccess = false;
                }

                if(p2.get() != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
#endif /* compiler */
            }

            {
                RCIs::Derived1  derived;
                const long      startCount  =   derived.Count();

//fprintf(stderr, "Derived::Count(): %ld\n", derived.Count());

                Derived1_ptr    p1(&derived, true);

//fprintf(stderr, "Derived::Count(): %ld\n", derived.Count());

                if(derived.Count() != startCount + 1)
                {
                    r->report("Constructor failed to take reference when bAddRef was true", __LINE__);
                    bSuccess = false;
                }

                if(&derived != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }

                Base_ptr        p2;

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER != 1300
                p2 = p1;

                if(derived.Count() != startCount + 2)
                {
                    r->report("Constructor failed to take reference when bAddRef was true", __LINE__);
                    bSuccess = false;
                }

                if(p2.get() != p1.get())
                {
                    r->report("get() returns invalid value", __LINE__);
                    bSuccess = false;
                }
#endif /* compiler */
            }


            return bSuccess;
        }

        ss_bool_t test_stlsoft_ref_ptr_4(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>      Base1_ptr;
            typedef ref_ptr<RCIs::Base, RCIs::Base>             Base2_ptr;

//#error
            Base1_ptr   p1;
            Base1_ptr   p2(NULL, false);
            Base1_ptr   p3(NULL, false);
            Base1_ptr   p4(p1);

            if(NULL != p1.get())
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p2)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p2 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p3)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p3 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            if(p1 != p4)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }
            if(p4 != p1)
            {
                r->report("Default construction failed", __LINE__);
                bSuccess = false;
            }

            RCIs::Base  base;
            const long  startCount  =   base.Count();

            {
                Base1_ptr   p1_1(&base, true);

                Base2_ptr   p2_1;
                Base2_ptr   p2_2(&base, true);

                Base2_ptr   p2_3;

                p2_3    =   p2_1;

                p1      =   p2_3;
                p2_3    =   p1;
            }

            if(base.Count() != startCount)
            {
                r->report("Constructor erroneously took/lost a reference when bAddRef was false", __LINE__);
                bSuccess = false;
            }

            return bSuccess;
        }

        ss_bool_t test_stlsoft_ref_ptr(unittest_reporter *r)
        {
            ss_bool_t               bSuccess    =   true;

            unittest_initialiser    init(r, "STLSoft", "ref_ptr", __FILE__);

            if(!test_stlsoft_ref_ptr_1(r))
            {
                bSuccess = false;
            }
            if(!test_stlsoft_ref_ptr_2(r))
            {
                bSuccess = false;
            }
            if(!test_stlsoft_ref_ptr_3(r))
            {
                bSuccess = false;
            }

            if(!test_stlsoft_ref_ptr_4(r))
            {
                bSuccess = false;
            }

            return bSuccess;
        }

        unittest_registrar    unittest_stlsoft_ref_ptr(test_stlsoft_ref_ptr);
    } // anonymous namespace

} // namespace unittest

