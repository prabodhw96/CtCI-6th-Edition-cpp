#include <iostream>
using namespace std;
int getNextLarger(int num)
{
  int c=num;
  int c0=0;
  int c1=0;
  while(((c&1)==0) && (c!=0))
  {
    c0++;
    c>>=1;
  }
  while((c&1)==1)
  {
    c1++;
    c>>=1;
  }
  if (c0 +c1 == 31 || c0 +c1== 0)
    return -1;
  return num+(1<<c0)+(1<<(c1-1))-1;
}
int getNextSmaller(int num)
{
  return ~getNextLarger(~num);
}
int main()
{
  cout<<"No.: "<<5<<endl;
  cout<<"Next smallest no.: "<<getNextSmaller(5)<<endl;
  cout<<"Next greatest no.: "<<getNextLarger(5)<<endl;
  return 0;
}
