#ifndef SINGLE
//  An adapted ObjectSpace example for use with SGI STL

#include <iostream.h>
#include <algo.h>

#ifdef MAIN 
#define bind2nd1_test main
#endif
#endif
int bind2nd1_test(int, char**)
{
  cout<<"Results of bind2nd1_test:"<<endl;
int array [3] = { 1, 2, 3 };

  replace_if(array, array + 3, 
    binder2nd<greater<int> >(greater<int>(), 2), 4);
  for(int i = 0; i < 3; i++)
    cout << array[i] << endl;
  return 0;
}