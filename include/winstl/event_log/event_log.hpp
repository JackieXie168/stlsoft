

# include <winstl/error/exceptions.hpp>

# include <stlsoft/shims/access/string.hpp>


namespace stlsoft
{

namespace winstl_project
{

#define event_log_exception		windows_exception

class event_log
{
public:
	typedef ws_bool_t			bool_type;
	typedef event_log			class_type;


public:
	bool_type report_N(WORD type, WORD category, DWORD eventId, LPCTSTR strings[], WORD numStrings)
	{
		if(!::ReportEvent(m_log, type, category, eventId, NULL, numStrings, 0, strings, NULL))
		{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
			throw event_log_exception("Could not report event", ::GetLastError());
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
			return false;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
		}

		return true;
	}

	bool_type report_1(WORD type, WORD category, DWORD eventId, LPCTSTR s0)
	{
		LPCTSTR	strings[] = { s0 };

		return report_N(type, category, eventId, strings, STLSOFT_NUM_ELEMENTS(strings));
	}

	bool_type report_2(WORD type, WORD category, DWORD eventId, LPCTSTR s0, LPCTSTR s1)
	{
		LPCTSTR	strings[] = { s0, s1 };

		return report_N(type, category, eventId, strings, STLSOFT_NUM_ELEMENTS(strings));
	}

	bool_type report_3(WORD type, WORD category, DWORD eventId, LPCTSTR s0, LPCTSTR s1, LPCTSTR s2)
	{
		LPCTSTR	strings[] = { s0, s1, s2 };

		return report_N(type, category, eventId, strings, STLSOFT_NUM_ELEMENTS(strings));
	}

	bool_type report_4(WORD type, WORD category, DWORD eventId, LPCTSTR s0, LPCTSTR s1, LPCTSTR s2, LPCTSTR s3)
	{
		LPCTSTR	strings[] = { s0, s1, s2, s3 };

		return report_N(type, category, eventId, strings, STLSOFT_NUM_ELEMENTS(strings));
	}


	template <ss_typename_param_k S0>
	bool_type report(WORD type, WORD category, DWORD eventId, S0 const &s0)
	{
		return report_1(type, category, eventId, ::stlsoft::c_str_ptr(s0));
	}
	template <ss_typename_param_k S0, ss_typename_param_k S1>
	bool_type report(WORD type, WORD category, DWORD eventId, S0 const &s0, S1 const &s1)
	{
		return report_1(type, category, eventId, ::stlsoft::c_str_ptr(s0), ::stlsoft::c_str_ptr(s1));
	}
	template <ss_typename_param_k S0, ss_typename_param_k S1, ss_typename_param_k S2>
	bool_type report(WORD type, WORD category, DWORD eventId, S0 const &s0, S1 const &s1, S2 const &s2)
	{
		return report_1(type, category, eventId, ::stlsoft::c_str_ptr(s0), ::stlsoft::c_str_ptr(s1), ::stlsoft::c_str_ptr(s2));
	}
	template <ss_typename_param_k S0, ss_typename_param_k S1, ss_typename_param_k S2, ss_typename_param_k S3>
	bool_type report(WORD type, WORD category, DWORD eventId, S0 const &s0, S1 const &s1, S2 const &s2, S3 const &s3)
	{
		return report_1(type, category, eventId, ::stlsoft::c_str_ptr(s0), ::stlsoft::c_str_ptr(s1), ::stlsoft::c_str_ptr(s2), ::stlsoft::c_str_ptr(s3));
	}

private:
	HANDLE	m_log;
};






} // namespace winstl_project
} // namespace stlsoft

