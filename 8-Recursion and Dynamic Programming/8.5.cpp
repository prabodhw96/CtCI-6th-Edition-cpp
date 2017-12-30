#include <iostream>
using namespace std;
int multiply(int a, int b)
{
  if(b==0)
    return 0;
  if(b>0)
    return (a + multiply(a, b-1));
  if(b<0)
    return -multiply(a, -b);
}
int main()
{
  cout<<multiply(5, -11);
  return 0;
}
