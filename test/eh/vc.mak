# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103


!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
RSC=rc.exe
CPP=cl.exe
F90=fl32.exe

OUTDIR=.
INTDIR=.

# set this directories 
STL_INCL=../../stl
VC_INCL=.
# d:/vc41/msdev/include

Dep_stl = TestClass.obj main.obj nc_alloc.obj \
random_number.obj test_algo.obj test_algobase.obj test_bit_vector.obj test_deque.obj \
test_hash_map.obj test_hash_set.obj test_list.obj test_map.obj test_rope.obj test_set.obj \
test_slist.obj test_vector.obj test_string.obj test_bitset.obj test_valarray.obj

LINK32=link.exe

# 5.0 won't work with NO_NEW_IOSTREAMS.  

CPP_PROJ=/nologo /W3 /GX /Zd /D "WIN32" \
/D "_CONSOLE" /D "__STL_NO_NEW_IOSTREAMS" /D "__STL_USE_SGI_STRING" /I$(STL_INCL) /I.

CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32"\ /D_REENTRANT /D__STL_NO_NEW_IOSTREAMS \
/D "_CONSOLE"  /I$(STL_INCL) /I.

CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32" /D__STL_DEBUG /D "_CONSOLE"   /I$(STL_INCL) /I.

check: eh_test.out

eh_test.out : $(Dep_stl)
	$(CPP) $(CPP_PROJ) $(Dep_stl) -o eh_test.exe
	eh_test
	echo done

clean :
	-@erase "$(INTDIR)\*.obj"
	-@erase "$(OUTDIR)\*.exe"
	-@erase "$(OUTDIR)\*.obj"


.exe.out:
	$< > $@

.cpp.exe:
  $(CPP) $(CPP_PROJ) -DMAIN $<

.c.obj:
   $(CPP) $(CPP_PROJ) /c $<

.cpp.obj:
   $(CPP) $(CPP_PROJ) /c $<

.cxx.obj:
   $(CPP) $(CPP_PROJ) /c $<

.cpp.E:
   $(CPP) $(CPP_PROJ) -E $< >$*.E  

.cpp.sbr:
   $(CPP) $(CPP_PROJ) $<  