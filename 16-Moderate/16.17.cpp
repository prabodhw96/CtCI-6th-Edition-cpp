#include <iostream>
using namespace std;
int getMaxSum(int a[], int n)
{
  int maxSum = 0;
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    sum += a[i];
    if(maxSum < sum)
      maxSum = sum;
    else if(sum < 0)
      sum = 0;
  }
  return maxSum;
}
int main()
{
  int a[] = {2, -8, 3, -2, 4, -10};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<getMaxSum(a, n);
  return 0;
}
