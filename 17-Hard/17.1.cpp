#include <iostream>
using namespace std;
int add(int a, int b)
{
  while(b != 0)
  {
    int sum = a^b;
    int carry = (a&b)<<1;
    a = sum;
    b = carry;
  }
  return a;
}
int main()
{
  cout<<add(5, 7);
  return 0;
}
