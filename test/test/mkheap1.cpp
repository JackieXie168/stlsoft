#ifndef SINGLE
//  An adapted ObjectSpace example for use with SGI STL

#include <algo.h>
#include <iostream.h>

#ifdef MAIN 
#define mkheap1_test main
#endif
#endif
int mkheap1_test(int, char**)
{
  cout<<"Results of mkheap1_test:"<<endl;
int numbers[6] = { 5, 10, 4, 13, 11, 19 };

  make_heap(numbers, numbers + 6, greater<int>());
  for(int i = 6; i >= 1; i--)
  {
    cout << numbers[0] << endl;
    pop_heap(numbers, numbers + i, greater<int>());
  }
  return 0;
}