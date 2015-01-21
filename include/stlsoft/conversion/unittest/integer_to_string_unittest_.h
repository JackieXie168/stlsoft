
// Updated: 12th March 2007

#if !defined(STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING)
# error This file cannot be directly included, and should only be included within stlsoft/conversion/integer_to_string.hpp
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		template <ss_typename_param_k T, ss_typename_param_k C>
		struct int2str_candidate
		{
			T			value;
			C const*	string;
		};

#define STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(v)	\
																\
	{	v,	#v	},

#define STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY_W(v)	\
																\
	{	v,	#v	},

		ss_bool_t test_stlsoft_conversion_integer_to_string(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "conversion/integer_to_string", __FILE__);

			char					buffer[21];
#if 0
			wchar_t 				bufferw[21];
#endif /* 0 */

			// 8-bit signed integer
			{ for(ss_sint8_t i = limit_traits<ss_sint8_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%d", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 8-bit signed integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_sint8_t>::maximum())
				{
					break;
				}
			}}

			int2str_candidate<ss_sint8_t, char> si8s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-128)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-127)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-12)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(0)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(9)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(10)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(45)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(127)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(si8s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), si8s[i].value), si8s[i].string))
				{
					r->report("conversion of 8-bit signed integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// 8-bit unsigned integer
			{ for(ss_uint8_t i = limit_traits<ss_uint8_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%u", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 8-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_uint8_t>::maximum())
				{
					break;
				}
			}}

			int2str_candidate<ss_uint8_t, char> ui8s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(0)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(1)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(9)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(10)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(45)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(127)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(128)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(200)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(254)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(255)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ui8s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), ui8s[i].value), ui8s[i].string))
				{
					r->report("conversion of 8-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// 16-bit signed integer
			{ for(ss_sint16_t i = limit_traits<ss_sint16_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%d", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 16-bit signed integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_sint16_t>::maximum())
				{
					break;
				}
			}}

			int2str_candidate<ss_sint16_t, char>	si16s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-32768)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-32767)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-127)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-12)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(0)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(9)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(10)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(45)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(127)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32766)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32767)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(si16s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), si16s[i].value), si16s[i].string))
				{
					r->report("conversion of 16-bit signed integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// 16-bit unsigned integer
			{ for(ss_uint16_t i = limit_traits<ss_uint16_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%u", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 16-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_uint16_t>::maximum())
				{
					break;
				}
			}}

			int2str_candidate<ss_uint16_t, char>	ui16s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(0)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(1)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(9)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(10)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(45)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(127)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32767)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32768)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32769)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(65534)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(65535)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ui16s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), ui16s[i].value), ui16s[i].string))
				{
					r->report("conversion of 16-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// 32-bit signed integer
#if 0 // Too slow to use!!
			{ for(ss_sint32_t i = limit_traits<ss_sint32_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%d", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 32-bit signed integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_sint32_t>::maximum())
				{
					break;
				}
			}}
#endif /* 0 */

			int2str_candidate<ss_sint32_t, char>	si32s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-32727)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-14301)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-26434)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-6268)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-13599)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-17044)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-21290)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-3410)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-5806)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-8304)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-27063)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-4623)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(41)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(18467)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(6334)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26500)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(19169)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(15724)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(11478)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(29358)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26962)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(24464)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(5705)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(28145)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(23281)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(si32s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), si32s[i].value), si32s[i].string))
				{
					r->report("conversion of 32-bit signed integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// 32-bit unsigned integer
#if 0 // Too slow to use!!
			{ for(ss_uint32_t i = limit_traits<ss_uint32_t>::minimum(); ; ++i)
			{
				char	sprintfForm[21];

				sprintf(sprintfForm, "%d", i);
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), i), sprintfForm))
				{
					r->report("conversion of 32-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}

				if(i == limit_traits<ss_uint32_t>::maximum())
				{
					break;
				}
			}}
#endif /* 0 */

			int2str_candidate<ss_uint32_t, char>	ui32s[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(41)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(18467)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(6334)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26500)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(19169)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(15724)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(11478)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(29358)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26962)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(24464)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(5705)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(28145)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(23281)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(32809)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(51235)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(39102)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(59268)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(51937)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(48492)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(44246)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(62126)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(59730)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(57232)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(38473)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(60913)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(ui32s); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), ui32s[i].value), ui32s[i].string))
				{
					r->report("conversion of 32-bit unsigned integer failed", __LINE__);
					bSuccess = false;
				}
			}}

			// int
			int2str_candidate<int, char>	is[] =
			{
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-32727)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-14301)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-26434)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-6268)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-13599)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-17044)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-21290)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-3410)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-5806)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-8304)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-27063)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(-4623)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(41)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(18467)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(6334)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26500)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(19169)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(15724)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(11478)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(29358)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(26962)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(24464)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(5705)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(28145)
				STLSOFT_INTEGER_TO_STRING_INT2STR_CANDIDATE_ENTRY(23281)
			};

			{ for(ss_size_t i = 0; i < STLSOFT_NUM_ELEMENTS(is); ++i)
			{
				if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), is[i].value), is[i].string))
				{
					r->report("conversion of int failed", __LINE__);
					bSuccess = false;
				}
			}}

#if 0
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
			// 64-bit signed integer
			if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), si64), "-12012012012012"))
			{
				r->report("conversion of 64-bit signed integer failed", __LINE__);
				bSuccess = false;
			}

			// 64-bit unsigned integer
			if(0 != strcmp(integer_to_string(buffer, STLSOFT_NUM_ELEMENTS(buffer), ui64), "45045045045045"))
			{
				r->report("conversion of 64-bit unsigned integer failed", __LINE__);
				bSuccess = false;
			}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_conversion_integer_to_string(test_stlsoft_conversion_integer_to_string);
	} // anonymous namespace

} // namespace unittest
