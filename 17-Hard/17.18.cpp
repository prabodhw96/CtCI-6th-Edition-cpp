#include <iostream>
#include <algorithm>
using namespace std;
int findNextInstance(int arr[], int n, int element, int index)
{
  for(int i=index; i<n; i++)
    if(arr[i] == element)
      return i;
  return -1;
}
int findClosure(int bigArray[], int smallArray[], int b, int s, int index)
{
  int mx = -1;
  for(int i=0; i<s; i++)
  {
    int next = findNextInstance(bigArray, b, smallArray[i], index);
    if(next == -1)
      return -1;
    mx = max(next, mx);
  }
  return mx;
}
void shortestSupersequence(int bigArray[], int smallArray[], int b, int s)
{
  int bestStart = -1;
  int bestEnd = -1;
  for(int i=0; i<b; i++)
  {
    int end = findClosure(bigArray, smallArray, b, s, i);
    if(end == -1) break;
    if(bestStart == -1 || end - i < bestEnd - bestStart)
    {
      bestStart = i;
      bestEnd = end;
    }
  }
  cout<<bestStart<<", "<<bestEnd<<endl;
}
int main()
{
  int arr[] = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 9, 7};
  int arr_set[] = {1, 5, 9};
  int b = sizeof(arr)/sizeof(arr[0]);
  int s = sizeof(arr_set)/sizeof(arr_set[0]);
  shortestSupersequence(arr, arr_set, b, s);
  return 0;
}
