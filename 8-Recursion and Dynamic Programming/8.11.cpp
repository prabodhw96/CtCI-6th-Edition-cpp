#include <iostream>
using namespace std;
int makeChange(int total)
{
  int ways = 0, sum;
  for(int i=0; i*25<=total; ++i)
  {
    for(int j=0; j*10<=total; ++j)
    {
      for(int k=0; k*5<=total; ++k)
      {
        sum = i*25 + j*10 + k*5;
        if(sum <= total)
          ++ways;
      }
    }
  }
  return ways;
}
int main()
{
  int amount = 15;
  cout<<makeChange(amount);
  return 0;
}
