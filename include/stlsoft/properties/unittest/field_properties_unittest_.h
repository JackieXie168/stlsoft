
#if !defined(STLSOFT_INCL_STLSOFT_PROPERTIES_HPP_FIELD_PROPERTIES)
# error This file cannot be directly included, and should only be included within stlsoft/properties/field_properties.hpp
#endif /* !STLSOFT_INCL_STLSOFT_PROPERTIES_HPP_FIELD_PROPERTIES */

#if !defined(STLSOFT_UNITTEST)
# error This file cannot be included when not unit-testing STLSoft
#endif /* !STLSOFT_UNITTEST */

namespace unittest
{
	namespace
	{
		namespace types
		{
			class ClassWithProp
			{
			public:
				ClassWithProp()
					: Index(0)
				{}
			public:
				field_property_get<int, int const &, ClassWithProp> 	Index;
			};

		} // namespace types

		ss_bool_t test_stlsoft_properties_field_properties(unittest_reporter *r)
		{
			ss_bool_t				bSuccess	=	true;

			unittest_initialiser	init(r, "STLSoft", "properties/field_properties", __FILE__);

			types::ClassWithProp	c;
			int 					i	=	c.Index;

			STLSOFT_SUPPRESS_UNUSED(i);

#if 0
			{
				r->report("field_properties value[1] not valid for non-empty field_properties instance", __LINE__);
				bSuccess = false;
			}
#endif /* 0 */

			return bSuccess;
		}

		unittest_registrar	  unittest_stlsoft_properties_field_properties(test_stlsoft_properties_field_properties);
	} // anonymous namespace

} // namespace unittest
