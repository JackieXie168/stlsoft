
/*
 * Created: 6th November 2007
 * Updated: 12th November 2007
 */

#if !defined(STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_FILE_PTR_STD_H_FUNDAMENTAL)
# error This file cannot be directly included, and should only be included within stlsoft/shims/attribute/get_FILE_ptr/std/fundamental.h
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_FILE_PTR_STD_H_FUNDAMENTAL */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* !_STLSOFT_NO_NAMESPACE */


namespace stlsoft_get_FILE_ptr_test
{
	class File
	{
	public:
		File(FILE* stm)
			: m_stm(stm)
		{}
	public:
		FILE*	get() const
		{
			return m_stm;
		}
	private:
		FILE*	m_stm;
	};
} // namespace stlsoft_get_FILE_ptr_test


#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft {
#endif /* !_STLSOFT_NO_NAMESPACE */

inline FILE* get_FILE_ptr(::stlsoft_get_FILE_ptr_test::File& file)
{
	return file.get();
}


namespace unittest
{
	namespace
	{
		ss_bool_t test_stlsoft_shims_attribute_get_FILE_ptr_std_fundamental(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "shims/attribute/get_FILE_ptr/std/fundamental", __FILE__);

			FILE*					stm1	=	NULL;
			FILE*					stm2	=	stdout;
			FILE*					stm3	=	stderr;

			if(stlsoft_ns_qual(get_FILE_ptr)(stm1) != stm1)
			{
				r->report("get_FILE_ptr(void*) failed", __LINE__);
				bSuccess = false;
			}

			if(stlsoft_ns_qual(get_FILE_ptr)(stm2) != stm2)
			{
				r->report("get_FILE_ptr(void*) failed", __LINE__);
				bSuccess = false;
			}

			if(stlsoft_ns_qual(get_FILE_ptr)(stm3) != stm3)
			{
				r->report("get_FILE_ptr(void*) failed", __LINE__);
				bSuccess = false;
			}

			::stlsoft_get_FILE_ptr_test::File	file1(stm1);
			::stlsoft_get_FILE_ptr_test::File	file2(stm2);
			::stlsoft_get_FILE_ptr_test::File	file3(stm3);

			if(stlsoft_ns_qual(get_FILE_ptr)(file1) != stm1)
			{
				r->report("get_FILE_ptr() failed", __LINE__);
				bSuccess = false;
			}

			if(stlsoft_ns_qual(get_FILE_ptr)(file2) != stm2)
			{
				r->report("get_FILE_ptr() failed", __LINE__);
				bSuccess = false;
			}

			if(stlsoft_ns_qual(get_FILE_ptr)(file3) != stm3)
			{
				r->report("get_FILE_ptr() failed", __LINE__);
				bSuccess = false;
			}

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_shims_attribute_get_FILE_ptr_std_fundamental(test_stlsoft_shims_attribute_get_FILE_ptr_std_fundamental);
	} // anonymous namespace

} // namespace unittest

