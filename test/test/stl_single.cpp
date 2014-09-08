//  An adapted ObjectSpace example for use with SGI STL
#define SINGLE
#include "stl_test.h"
#include "accum1.cpp"
#include "accum2.cpp"
#include "adjdiff0.cpp"
#include "adjdiff1.cpp"
#include "adjdiff2.cpp"
#include "adjfind0.cpp"
#include "adjfind1.cpp"
#include "adjfind2.cpp"
#include "advance.cpp"
#include "alg1.cpp"
#include "alg2.cpp"
#include "alg3.cpp"
#include "alg4.cpp"
#include "alg5.cpp"
#include "bcompos1.cpp"
#include "bcompos2.cpp"
#include "bind1st1.cpp"
#include "bind1st2.cpp"
#include "bind2nd1.cpp"
#include "bind2nd2.cpp"
#include "binsert1.cpp"
#include "binsert2.cpp"
#include "binsrch1.cpp"
#include "binsrch2.cpp"
#include "bnegate1.cpp"
#include "bnegate2.cpp"
#include "bvec1.cpp"
#include "copy1.cpp"
#include "copy2.cpp"
#include "copy3.cpp"
#include "copy4.cpp"
#include "copyb.cpp"
#include "copyb0.cpp"
#include "count0.cpp"
#include "count1.cpp"
#include "countif1.cpp"
#include "deque1.cpp"
#include "divides.cpp"
#include "eqlrnge0.cpp"
#include "eqlrnge1.cpp"
#include "eqlrnge2.cpp"
#include "equal0.cpp"
#include "equal1.cpp"
#include "equal2.cpp"
#include "equalto.cpp"
#include "error1.cpp"
#include "fill1.cpp"
#include "filln1.cpp"
#include "find0.cpp"
#include "find1.cpp"
#include "findif0.cpp"
#include "findif1.cpp"
#include "finsert1.cpp"
#include "finsert2.cpp"
#include "foreach0.cpp"
#include "foreach1.cpp"
#include "func1.cpp"
#include "func2.cpp"
#include "func3.cpp"
#include "gener1.cpp"
#include "gener2.cpp"
#include "genern1.cpp"
#include "genern2.cpp"
#include "greateq.cpp"
#include "greater.cpp"
#include "incl0.cpp"
#include "incl1.cpp"
#include "incl2.cpp"
#include "inplmrg1.cpp"
#include "inplmrg2.cpp"
#include "inrprod0.cpp"
#include "inrprod1.cpp"
#include "inrprod2.cpp"
#include "insert1.cpp"
#include "insert2.cpp"
#include "iota1.cpp"
#include "istmit1.cpp"
#include "iter1.cpp"
#include "iter2.cpp"
#include "iter3.cpp"
#include "iter4.cpp"
#include "iterswp0.cpp"
#include "iterswp1.cpp"
#include "less.cpp"
#include "lesseq.cpp"
#include "lexcmp1.cpp"
#include "lexcmp2.cpp"
#include "list1.cpp"
#include "list2.cpp"
#include "list3.cpp"
#include "list4.cpp"
#include "logicand.cpp"
#include "logicnot.cpp"
#include "logicor.cpp"
#include "lwrbnd1.cpp"
#include "lwrbnd2.cpp"
#include "map1.cpp"
#include "max1.cpp"
#include "max2.cpp"
#include "maxelem1.cpp"
#include "maxelem2.cpp"
#include "merge0.cpp"
#include "merge1.cpp"
#include "merge2.cpp"
#include "min1.cpp"
#include "min2.cpp"
#include "minelem1.cpp"
#include "minelem2.cpp"
#include "minus.cpp"
#include "mismtch0.cpp"
#include "mismtch1.cpp"
#include "mismtch2.cpp"
#include "mkheap0.cpp"
#include "mkheap1.cpp"
#include "mmap1.cpp"
#include "mmap2.cpp"
#include "modulus.cpp"
#include "mset1.cpp"
#include "mset3.cpp"
#include "mset4.cpp"
#include "mset5.cpp"
#include "negate.cpp"
#include "nequal.cpp"
#include "nextprm0.cpp"
#include "nextprm1.cpp"
#include "nextprm2.cpp"
#include "nthelem0.cpp"
#include "nthelem1.cpp"
#include "nthelem2.cpp"
#include "ostmit.cpp"
#include "pair0.cpp"
#include "pair1.cpp"
#include "pair2.cpp"
#include "parsrt0.cpp"
#include "parsrt1.cpp"
#include "parsrt2.cpp"
#include "parsrtc0.cpp"
#include "parsrtc1.cpp"
#include "parsrtc2.cpp"
#include "partsrt0.cpp"
#include "partsum0.cpp"
#include "partsum1.cpp"
#include "partsum2.cpp"
#include "pheap1.cpp"
#include "pheap2.cpp"
#include "plus.cpp"
#include "pqueue1.cpp"
#include "prevprm0.cpp"
#include "prevprm1.cpp"
#include "prevprm2.cpp"
#include "ptition0.cpp"
#include "ptition1.cpp"
#include "ptrbinf1.cpp"
#include "ptrbinf2.cpp"
#include "ptrunf1.cpp"
#include "ptrunf2.cpp"
#include "queue1.cpp"
#include "rawiter.cpp"
#include "remcopy1.cpp"
#include "remcpif1.cpp"
#include "remif1.cpp"
#include "remove1.cpp"
#include "repcpif1.cpp"
#include "replace0.cpp"
#include "replace1.cpp"
#include "replcpy1.cpp"
#include "replif1.cpp"
#include "revbit1.cpp"
#include "revbit2.cpp"
#include "revcopy1.cpp"
#include "reverse1.cpp"
#include "reviter1.cpp"
#include "reviter2.cpp"
#include "rndshuf0.cpp"
#include "rndshuf1.cpp"
#include "rndshuf2.cpp"
#include "rotate0.cpp"
#include "rotate1.cpp"
#include "rotcopy0.cpp"
#include "rotcopy1.cpp"
#include "search0.cpp"
#include "search1.cpp"
#include "search2.cpp"
#include "set1.cpp"
#include "set2.cpp"
#include "setdiff0.cpp"
#include "setdiff1.cpp"
#include "setdiff2.cpp"
#include "setintr0.cpp"
#include "setintr1.cpp"
#include "setintr2.cpp"
#include "setsymd0.cpp"
#include "setsymd1.cpp"
#include "setsymd2.cpp"
#include "setunon0.cpp"
#include "setunon1.cpp"
#include "setunon2.cpp"
#include "single.cpp"
#include "sort1.cpp"
#include "sort2.cpp"
#include "stack1.cpp"
#include "stack2.cpp"
#include "stat.cpp"
#include "stblptn0.cpp"
#include "stblptn1.cpp"
#include "stblsrt1.cpp"
#include "stblsrt2.cpp"
#include "swap1.cpp"
#include "swprnge1.cpp"
#include "times.cpp"
#include "trnsfrm1.cpp"
#include "trnsfrm2.cpp"
#include "ucompos1.cpp"
#include "ucompos2.cpp"
#include "unegate1.cpp"
#include "unegate2.cpp"
#include "uniqcpy1.cpp"
#include "uniqcpy2.cpp"
#include "unique1.cpp"
#include "unique2.cpp"
#include "uprbnd1.cpp"
#include "uprbnd2.cpp"
#include "vec1.cpp"
#include "vec2.cpp"
#include "vec3.cpp"
#include "vec4.cpp"
#include "vec5.cpp"
#include "vec6.cpp"
#include "vec7.cpp"
#include "vec8.cpp"
#include "stl_test.cpp"