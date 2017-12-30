#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
int findSmallestDifference(int A[], int B[], int m, int n)
{
  sort(A, A+m);
  sort(B, B+m);
  int a=0, b=0;
  int difference = INT_MAX;
  while(a<m && b<n)
  {
    if(abs(A[a] - B[b]) < difference)
      difference = abs(A[a] - B[b]);
    if(A[a] < B[b])
      a++;
    else
      b++;
  }
  return difference;
}
int main()
{
  int A[] = {1, 3, 15, 11, 2};
  int B[] = {23, 127, 235, 19, 8};
  int m = sizeof(A)/sizeof(A[0]);
  int n = sizeof(B)/sizeof(B[0]);
  cout<<findSmallestDifference(A, B, m, n);
  return 0;
}
