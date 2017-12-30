#include <iostream>
using namespace std;
bool validate(int array[], int n, int majority)
{
  int count = 0;
  for (int i=0; i<n; i++)
  {
    if(array[i] == majority)
      count++;
  }
  return (count>n/2);
}
int getCandidate(int array[], int n)
{
  int majority= 0;
  int count = 0;
  for(int i=0; i<n; i++)
  {
    if(count== 0)
      majority = array[i];
    if(array[i] == majority)
      count++;
    else
      count--;
  }
  return majority;
}
int findMajorityElement(int array[], int n)
{
  int candidate = getCandidate(array, n);
  return validate(array, n, candidate) ? candidate : -1;
}
int main()
{
  int a[] = {1, 2, 5, 9, 5, 9, 5, 5, 5};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<findMajorityElement(a, n);
  return 0;
}
