#include <iostream>
#include <algorithm>
using namespace std;
int flipBit(unsigned a)
{
  if(~a == 0)
    return 8*sizeof(int);
  int currLen=0, prevLen=0, maxLen=0;
  while(a!=0)
  {
    if((a&1)==1)
      currLen++;
    else if((a&1) == 0)
    {
      prevLen = (a&2)==0?0:currLen;
      currLen = 0;
    }
    maxLen = max(prevLen+currLen, maxLen);
    a >>= 1;
  }
  return maxLen+1;
}
int main()
{
  cout<<flipBit(13)<<endl;
  cout<<flipBit(1775)<<endl;
  cout<<flipBit(15)<<endl;
  return 0;
}
