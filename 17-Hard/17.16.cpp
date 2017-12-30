#include <iostream>
#include <algorithm>
using namespace std;
int maxMinutes(int massages[], int n)
{
  int oneAway = 0, twoAway = 0;
  for(int i=n-1; i>=0; i--)
  {
    int bestWith = massages[i] + twoAway;
    int bestWithout = oneAway;
    int current = max(bestWith, bestWithout);
    twoAway = oneAway;
    oneAway = current;
  }
  return oneAway;
}
int main()
{
  int massages[] = {30, 15, 60, 75, 45, 15, 15, 45};
  int n = sizeof(massages)/sizeof(massages[0]);
  cout<<maxMinutes(massages, n);
  return 0;
}
