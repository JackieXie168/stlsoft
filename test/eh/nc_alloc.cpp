/************************************************************************************************
 NC_ALLOC.CPP

 * Copyright (c) 1997
 * Mark of the Unicorn, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Mark of the Unicorn makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.

************************************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "nc_alloc.h"
#include <string>

#if defined (EH_NEW_HEADERS)
# include <new>
#else
# include <new.h>
#endif

#if defined (EH_NEW_IOSTREAMS)
# include <iostream>
#else
# include <iostream.h>
#endif

long alloc_count = 0;
long object_count = 0;
const char* TestController::current_test = "<unknown>";
const char* TestController::current_test_category = "no category";
const char* TestController::current_container = 0;
bool  TestController::nc_verbose = true;
bool  TestController::never_fail = false;
bool  TestController::track_allocations = false;
bool  TestController::leak_detection_enabled = false;
TestController gTestController;

EH_USE_STD

//************************************************************************************************
void TestController::maybe_fail(long)
{
    if ( never_fail || Failure_threshold() == kNotInExceptionTest )
        return;

    // throw if allocation would satisfy the threshold
    if ((alloc_count + object_count + 1) >= Failure_threshold() )
    {

        // what about doing some standard new_handler() behavior here (to test it!) ???

        // reset and simulate an out-of-memory failure
        Failure_threshold() = kNotInExceptionTest;
# ifndef EH_NO_EXCEPTIONS
        throw (int)0;
# endif
    }
}

# if defined( EH_HASHED_CONTAINERS_IMPLEMENTED )

#  if defined (__SGI_STL )

#   if defined (EH_NEW_HEADERS)
#    include <hash_set>
#   else
#    include <hash_set.h>
#   endif
#  elif defined (__MSL__)
#   include <hashset.h>
#  else
#   error what do I include to get hash_set?
#  endif

# else

#  if defined (EH_NEW_HEADERS)
#   include <set>
#  else
#  include <set.h>
#  endif
# endif

# if !defined( EH_HASHED_CONTAINERS_IMPLEMENTED )
typedef EH_STD::set<void*, EH_STD::less<void*> > allocation_set;
#else
#  if defined (EH_USE_NAMESPACES)
EH_BEGIN_NAMESPACE
#  endif

struct hash_void
{
  size_t operator()(void* x) const { return (size_t)x; }
};

#  if defined (EH_USE_NAMESPACES)
EH_END_NAMESPACE
using namespace EH_STD;
#  endif

typedef EH_STD::hash_set<void*, hash_void, EH_STD::equal_to<void*> > allocation_set;
# endif

static allocation_set& alloc_set()
{
	static allocation_set s;
	return s;
}

// Prevents infinite recursion during allocation
static bool using_alloc_set = false;

# if !defined (NO_FAST_ALLOCATOR)
//
//	FastAllocator -- speeds up construction of TestClass objects when
// TESTCLASS_DEEP_DATA is enabled, and speeds up tracking of allocations
// when the suite is run with the -t option.
//
class FastAllocator
{
public:
//	FastAllocator() : mFree(0), mUsed(0) {}
	
	static void *Allocate( size_t s )
	{
		if ( s <= sizeof( Block ) )
		{
			if ( mFree != 0 )
			{
				void *result = mFree;
				mFree = mFree->next;
				return result;
			}
			else if ( mBlocks != 0 && mUsed < kBlockCount )
			{
				return (void*)&mBlocks[mUsed++];
			}
		}
	 	return (void*)0;
	}
	
	static bool Free( void* p )
	{
		Block* b = (Block*)p;
		if ( mBlocks == 0 || b < mBlocks || b >= mBlocks + kBlockCount )
			return false;
		b->next = mFree;
		mFree = b;
		return true;
	}
	
	struct Block;
	friend struct Block;
	
	enum
	{
		// Number of fast allocation blocks to create.
		kBlockCount = 1500,
		
		// You may need to adjust this number for your platform.
		// A good choice will speed tests. A bad choice will still work.
		kMinBlockSize = 48
	};
	
	struct Block
	{
		union { 
                    Block *next;
                    double dummy; // fbp - force alignment
                    char dummy2[kMinBlockSize];
                };
	};
	
	static Block* mBlocks;
	static Block *mFree;
	static size_t mUsed;
};

FastAllocator::Block *FastAllocator::mBlocks = 
(FastAllocator::Block*)EH_CSTD::calloc( sizeof(FastAllocator::Block), FastAllocator::kBlockCount );
FastAllocator::Block *FastAllocator::mFree;
size_t FastAllocator::mUsed;

static FastAllocator gFastAllocator;
# endif

inline char* AllocateBlock( size_t s )
{
# if !defined (NO_FAST_ALLOCATOR)    
    char * const p = (char*)gFastAllocator.Allocate( s );
    if ( p != 0 )
    	return p;
# endif    
    return (char*)malloc(s);
}

static void* OperatorNew( size_t s )
{
    if ( !using_alloc_set )
	{
		simulate_possible_failure();
    	alloc_count++;
    }
    
    char *p = AllocateBlock(s);
	
	if ( gTestController.TrackingEnabled()
		&& gTestController.LeakDetectionEnabled()
		&& !using_alloc_set )
	{
		using_alloc_set = true;
		EH_ASSERT( alloc_set().find( p ) == alloc_set().end() );
		alloc_set().insert( p );
		using_alloc_set = false;
	}

    return p;
}

void* operator new(size_t s)
{
	return OperatorNew( s );
}

#ifdef EH_USE_NOTHROW
void* operator new(size_t size, const __STD::nothrow_t&) throw()
{
	try
	{
		return OperatorNew( size );
	}
	catch(...)
	{
		return 0;
	}
}
#endif

# if defined (EH_VECTOR_OPERATOR_NEW)
void* operator new[]( __STD::size_t size )
{
	return OperatorNew( size );
}

void* operator new[](size_t size, const __STD::nothrow_t&) throw()
{
	try
	{
		return OperatorNew( size );
	}
	catch(...)
	{
		return 0;
	}
}

void operator delete[](void* ptr) throw()
{
	operator delete( ptr );
}
# endif

# if defined (EH_DELETE_HAS_THROW_SPEC)
void operator delete(void* s) throw()
# else
void operator delete(void* s)
# endif
{
	if ( s != 0 )
	{
	    if ( !using_alloc_set )
	    {
	    	alloc_count--;

			if ( gTestController.TrackingEnabled() && gTestController.LeakDetectionEnabled() )
			{
				using_alloc_set = true;
				allocation_set::iterator p = alloc_set().find( (char*)s );
				EH_ASSERT( p != alloc_set().end() );
				alloc_set().erase( p );
				using_alloc_set = false;
			}
		}
# if ! defined (NO_FAST_ALLOCATOR)	
		if ( !gFastAllocator.Free( s ) )
# endif   
		    free(s);
	}
}

/*===================================================================================
	ClearAllocationSet  (private helper)

	EFFECTS:  Empty the set of allocated blocks.
====================================================================================*/
void TestController::ClearAllocationSet()
{
	if ( !using_alloc_set )
	{
		using_alloc_set = true;
		alloc_set().clear();
		using_alloc_set = false;
	}
}

bool TestController::ReportLeaked()
{
	EndLeakDetection();
	
	EH_ASSERT( alloc_count == alloc_set().size() );
	
    if ( alloc_count!=0 || object_count!=0 )
    {
        EH_STD::cerr<<"\nEH TEST FAILURE !\n";
        PrintTestName(true);
        if (alloc_count)
            EH_STD::cerr<<"ERROR : "<<alloc_count<<" outstanding allocations."<<EH_STD::endl;
        if (object_count)
            EH_STD::cerr<<"ERROR : "<<object_count<<" non-destroyed objects."<<EH_STD::endl;
        return true;
    }
    return false; 
}

/*===================================================================================
	PrintTestName

	EFFECTS: Prints information about the current test. If err is false, ends with
		an ellipsis, because the test is ongoing. If err is true an error is being
		reported, and the output ends with an endl.
====================================================================================*/
void TestController::PrintTestName(bool err) {
    if (current_container)
        EH_STD::cerr<<"["<<current_container<<"] :";
    EH_STD::cerr<<"testing "<<current_test <<" (" << current_test_category <<")";
    if (err)
        EH_STD::cerr<<EH_STD::endl;
    else
        EH_STD::cerr<<" ... ";
}

void TestController::ReportSuccess(int count) {
    if (nc_verbose)
        EH_STD::cerr<<(count+1)<<" try successful"<<EH_STD::endl;
}

long& TestController::Failure_threshold()
{
	static long failure_threshold = kNotInExceptionTest;
	return failure_threshold;
}