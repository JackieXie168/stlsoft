
#if !defined(WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS)
# error This file cannot be directly included, and should only be included within winstl/synch/atomic_functions.h
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		ss_bool_t test_winstl_synch_atomic_functions(unittest_reporter *r)
		{
			using stlsoft::unittest::unittest_initialiser;

			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "WinSTL", "synch/atomic_functions", __FILE__);

			ws_sint32_t 	i	=	0;

			if(1 != atomic_preincrement_up(&i))
			{
				r->report("atomic_preincrement_up() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_predecrement_up(&i))
			{
				r->report("atomic_predecrement_up() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_postincrement_up(&i))
			{
				r->report("atomic_postincrement_up() failed", __LINE__);
				bSuccess = false;
			}
			if(1 != atomic_postdecrement_up(&i))
			{
				r->report("atomic_postdecrement_up() failed", __LINE__);
				bSuccess = false;
			}
			atomic_increment_up(&i);
			if(1 != i)
			{
				r->report("atomic_increment_up() failed", __LINE__);
				bSuccess = false;
			}
			atomic_decrement_up(&i);
			if(0 != i)
			{
				r->report("atomic_decrement_up() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_write_up(&i, 1968))
			{
				r->report("atomic_write_up() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_read_up(&i))
			{
				r->report("atomic_read_up() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_postadd_up(&i, 35))
			{
				r->report("atomic_postadd_up() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_preadd_up(&i, -35))
			{
				r->report("atomic_preadd_up() failed", __LINE__);
				bSuccess = false;
			}

			ws_sint32_t 	j	=	0;

			if(1 != atomic_preincrement_smp(&j))
			{
				r->report("atomic_preincrement_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_predecrement_smp(&j))
			{
				r->report("atomic_predecrement_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_postincrement_smp(&j))
			{
				r->report("atomic_postincrement_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(1 != atomic_postdecrement_smp(&j))
			{
				r->report("atomic_postdecrement_smp() failed", __LINE__);
				bSuccess = false;
			}
			atomic_increment_smp(&j);
			if(1 != j)
			{
				r->report("atomic_increment_smp() failed", __LINE__);
				bSuccess = false;
			}
			atomic_decrement_smp(&j);
			if(0 != j)
			{
				r->report("atomic_decrement_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_write_smp(&j, 1968))
			{
				r->report("atomic_write_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_read_smp(&j))
			{
				r->report("atomic_read_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_postadd_smp(&j, 35))
			{
				r->report("atomic_postadd_smp() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_preadd_smp(&j, -35))
			{
				r->report("atomic_preadd_smp() failed", __LINE__);
				bSuccess = false;
			}

			ws_sint32_t 	k	=	0;

			if(1 != atomic_preincrement(&k))
			{
				r->report("atomic_preincrement() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_predecrement(&k))
			{
				r->report("atomic_predecrement() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_postincrement(&k))
			{
				r->report("atomic_postincrement() failed", __LINE__);
				bSuccess = false;
			}
			if(1 != atomic_postdecrement(&k))
			{
				r->report("atomic_postdecrement() failed", __LINE__);
				bSuccess = false;
			}
			atomic_increment(&k);
			if(1 != k)
			{
				r->report("atomic_increment() failed", __LINE__);
				bSuccess = false;
			}
			atomic_decrement(&k);
			if(0 != k)
			{
				r->report("atomic_decrement() failed", __LINE__);
				bSuccess = false;
			}
			if(0 != atomic_write(&k, 1968))
			{
				r->report("atomic_write() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_read(&k))
			{
				r->report("atomic_read() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_postadd(&k, 35))
			{
				r->report("atomic_postadd() failed", __LINE__);
				bSuccess = false;
			}
			if(1968 != atomic_preadd(&k, -35))
			{
				r->report("atomic_preadd() failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_winstl_synch_atomic_functions(test_winstl_synch_atomic_functions);
	} // anonymous namespace

} // namespace unittest
