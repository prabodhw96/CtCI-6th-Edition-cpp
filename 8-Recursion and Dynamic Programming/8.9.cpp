#include <iostream>
using namespace std;
void _printParanthesis(int pos, int n, int open, int close)
{
  static char str[100];
  if(close == n)
  {
    cout<<str<<endl;
    return;
  }
  else
  {
    if(open>close)
    {
      str[pos] = ')';
      _printParanthesis(pos+1, n, open, close+1);
    }
    if(open<n)
    {
      str[pos] = '(';
      _printParanthesis(pos+1, n, open+1, close);
    }
  }
}
void printParanthesis(int n)
{
  if(n>0)
    _printParanthesis(0, n, 0, 0);
  return;
}
int main()
{
  int n = 3;
  printParanthesis(n);
  return 0;
}
