/*
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

// Workaround for a "misbehaviour" when compiling resource scripts using
// eMbedded Visual C++. The standard .rc file includes windows header files,
// which in turn include stdlib.h, which results in warnings and errors
#if !defined(RC_INVOKED)

# if !defined (_STLP_OUTERMOST_HEADER_ID)
#  define _STLP_OUTERMOST_HEADER_ID 0x265
#  include <stl/_prolog.h>
# elif (_STLP_OUTERMOST_HEADER_ID == 0x265) && ! defined (_STLP_DONT_POP_HEADER_ID)
#  define _STLP_DONT_POP_HEADER_ID
# endif

# include _STLP_NATIVE_C_HEADER(stdlib.h)

# if (_STLP_OUTERMOST_HEADER_ID == 0x265)
#  if ! defined (_STLP_DONT_POP_HEADER_ID)
#   include <stl/_epilog.h>
#   undef  _STLP_OUTERMOST_HEADER_ID
#  else
#   undef  _STLP_DONT_POP_HEADER_ID
#  endif
# endif

#endif /* RC_INVOKED */

// Local Variables:
// mode:C++
// End:
