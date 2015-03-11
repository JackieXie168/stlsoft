
// Updated: 20th March 2007

#if !defined(STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR)
# error This file cannot be directly included, and should only be included within stlsoft/smartptr/ref_ptr.hpp
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace RCIs
		{

			// This definition extracted from Synesis Software's MIRefCnt.h
			//
			// (Licensed under the Synesis Software Standard Public License)
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
				long	m_refCount;

			private:
				Base(Base const&);
				Base& operator =(Base const&);
			};

			class Derived1
				: public Base
			{
			public:
				Derived1()
				{}
			private:
				Derived1(Derived1 const&);
				Derived1& operator =(Derived1 const&);
			};

			class Derived2
				: public Base
			{
			public:
				Derived2()
				{}
			private:
				Derived2(Derived2 const&);
				Derived2& operator =(Derived2 const&);
			};

			class Derived11
				: public Derived1
			{
			public:
				Derived11()
				{}
			private:
				Derived11(Derived11 const&);
				Derived11& operator =(Derived11 const&);
			};

		} // namespace RCIs

		namespace RCIs2
		{

			struct IRefCounter
			{
			public:
				virtual unsigned long	AddRef() = 0;
				virtual unsigned long	Release() = 0;
			};

			struct IBase
				: public IRefCounter
			{
			public:
				virtual void BaseMethod() = 0;
			};

			struct IDerived
				: public IBase
			{
			public:
				virtual void DerivedMethod() = 0;
			};

			class Base
				: public IBase
			{
			public:
				unsigned long	AddRef()
				{
					return 0;
				}
				unsigned long	Release()
				{
					return 0;
				}
			public:
				void BaseMethod()
				{
				}
			};

			class Derived
				: public Base
				, public IDerived
			{
			public:
				unsigned long	AddRef()
				{
					return 0;
				}
				unsigned long	Release()
				{
					return 0;
				}
			public:
				void BaseMethod()
				{
				}
			public:
				void DerivedMethod()
				{
				}
			};

		} // namespace RCIs2

		ss_bool_t test_stlsoft_ref_ptr_1(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>		Base_ptr;

			Base_ptr	p1;
			Base_ptr	p2(NULL, false);
			Base_ptr	p3(NULL, false);
			Base_ptr	p4(p1);
			Base_ptr	p5;
			Base_ptr	p6;

			p5 = p1;

			p6.set(NULL, false);

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
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(p2 != p1)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}

			if(p1 != p3)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}
			if(p3 != p1)
			{
				r->report("Conversion construction failed", __LINE__);
				bSuccess = false;
			}

			if(p1 != p4)
			{
				r->report("Copy construction failed", __LINE__);
				bSuccess = false;
			}
			if(p4 != p1)
			{
				r->report("Copy construction failed", __LINE__);
				bSuccess = false;
			}

			if(p1 != p5)
			{
				r->report("Copy assignment failed", __LINE__);
				bSuccess = false;
			}
			if(p5 != p1)
			{
				r->report("Copy assignment failed", __LINE__);
				bSuccess = false;
			}

			if(p1 != p6)
			{
				r->report("Assignment by set() failed", __LINE__);
				bSuccess = false;
			}
			if(p6 != p1)
			{
				r->report("Assignment by set() failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_ref_ptr_2(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>		Base_ptr;

			{
				{
					RCIs::Base	base;
					const long	startCount	=	base.Count();
					Base_ptr	p1(&base, false);

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
					RCIs::Base	base;
					const long	startCount	=	base.Count();
					Base_ptr	p1;

					p1.set(&base, false);

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
			}

			{
				RCIs::Base	base;
				const long	startCount	=	base.Count();
				Base_ptr	p1(&base, true);

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
				RCIs::Base	base;
				const long	startCount	=	base.Count();
				Base_ptr	p1(&base, false);

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

				Base_ptr	p2(p1);

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
				RCIs::Base	base;
				const long	startCount	=	base.Count();
				Base_ptr	p1(&base, false);

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

				Base_ptr	p2;

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
			ss_bool_t				bSuccess	=	true;

			typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>		Base_ptr;
			typedef ref_ptr<RCIs::Derived1, RCIs::IRefCounter>	Derived1_ptr;

			{
				RCIs::Derived1	derived;
				const long		startCount	=	derived.Count();

				Derived1_ptr	p1(&derived, true);

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
	(	_MSC_VER > 1100 && \
		_MSC_VER != 1300)
				Base_ptr		p2(p1);

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
				RCIs::Derived1	derived;
				const long		startCount	=	derived.Count();

				Derived1_ptr	p1(&derived, true);

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

				Base_ptr		p2;

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	(	_MSC_VER > 1100 && \
		_MSC_VER != 1300)
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
			ss_bool_t				bSuccess	=	true;

			typedef ref_ptr<RCIs::Base, RCIs::IRefCounter>		Base1_ptr;
			typedef ref_ptr<RCIs::Base, RCIs::Base> 			Base2_ptr;

//#error
			Base1_ptr	p1;
			Base1_ptr	p2(NULL, false);
			Base1_ptr	p3(NULL, false);
			Base1_ptr	p4(p1);

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

			RCIs::Base	base;
			const long	startCount	=	base.Count();

			{
				Base1_ptr	p1_1(&base, true);

				Base2_ptr	p2_1;
				Base2_ptr	p2_2(&base, true);

				Base2_ptr	p2_3;

				p2_3	=	p2_1;

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER > 1100
				p1		=	p2_3;
				p2_3	=	p1;
#endif /* compiler */
			}

			if(base.Count() != startCount)
			{
				r->report("Constructor erroneously took/lost a reference when bAddRef was false", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		ss_bool_t test_stlsoft_ref_ptr_5(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			typedef stlsoft::ref_ptr<RCIs2::Derived, RCIs2::IDerived>			Derived_ptr;
			typedef stlsoft::ref_ptr<RCIs2::Derived, RCIs2::IBase, RCIs2::Base> Base_ptr;

			Derived_ptr 	d1(new RCIs2::Derived(), false);

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER > 1100

			Base_ptr		d2(d1);

			if(d1.get() != d2.get())
			{
				r->report("Copy construction failed", __LINE__);
				bSuccess = false;
			}

			d1 = d2;

			if(d1.get() != d2.get())
			{
				r->report("Copying failed", __LINE__);
				bSuccess = false;
			}

#else /* compiler */

			STLSOFT_SUPPRESS_UNUSED(bSuccess);

#endif /* compiler */

			return bSuccess;
		}

		ss_bool_t test_stlsoft_ref_ptr(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "smartptr/ref_ptr", __FILE__);

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

			if(!test_stlsoft_ref_ptr_5(r))
			{
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_ref_ptr(test_stlsoft_ref_ptr);
	} // anonymous namespace

} // namespace unittest

