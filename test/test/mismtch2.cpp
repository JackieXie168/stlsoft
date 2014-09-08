#ifndef SINGLE
//  An adapted ObjectSpace example for use with SGI STL

#include <algo.h>
#include <iostream.h>
#include <string.h>

#ifdef MAIN 
#define mismtch2_test main
#endif
bool str_equal(const char* a_, const char* b_)
{
  return ::strcmp(a_, b_) == 0 ? 1 : 0;
}
#endif
int mismtch2_test(int, char**)
{
  cout<<"Results of mismtch2_test:"<<endl;

const unsigned size = 5;
char* n1[size] = { "Brett", "Graham", "Jack", "Mike", "Todd" };

  char* n2[size];
  copy(n1, n1 + 5, (char**)n2);
  pair <char**, char**> result = mismatch((char**)n1, (char**)n1 + size, (char**)n2, str_equal);
  if(result.first == n1 + size && result.second == n2 + size)
    cout << "n1 and n2 are the same" << endl;
  else
    cout << "mismatch at index: " <<(result.first - n1) << endl;
  n2[2] = "QED";
  result = mismatch((char**)n1, (char**)n1 + size, (char**)n2, str_equal);
  if(result.first == n2 + size && result.second == n2 + size)
    cout << "n1 and n2 are the same" << endl;
  else
    cout << "mismatch at index: " <<(result.first - n1) << endl;
  return 0;
}