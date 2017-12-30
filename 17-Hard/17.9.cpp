#include <iostream>
using namespace std;
int maxDivide(int a, int b)
{
  while(a%b == 0)
    a = a/b;
  return a;
}
int isMagic(int n)
{
  n = maxDivide(n, 3);
  n = maxDivide(n, 5);
  n = maxDivide(n, 7);
  return (n == 1) ? 1 : 0;
}
int getKthMagicNumber(int n)
{
  int i = 1, count = 1;
  while(n > count)
  {
    i++;
    if(isMagic(i))
      count++;
  }
  return i;
}
int main()
{
  unsigned no = getKthMagicNumber(12);
  cout<<"150th magic number is "<<no<<endl;
  return 0;
}
