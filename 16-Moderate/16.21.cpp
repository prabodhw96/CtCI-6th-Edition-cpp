#include <iostream>
using namespace std;
int getSum(int X[], int n)
{
  int sum = 0;
  for(int i=0; i<n; i++)
    sum += X[i];
  return sum;
}
void SumSwap(int A[], int a, int B[], int b)
{
  int sum_a = getSum(A, a);
  int sum_b = getSum(B, b);
  int newsum_a, newsum_b, val_a, val_b;
  for(int i=0; i<a; i++)
  {
    for(int j=0; j<b; j++)
    {
      newsum_a = sum_a - A[i] + B[j];
      newsum_b = sum_b - B[j] + A[i];
      if(newsum_a == newsum_b)
      {
        val_a = A[i];
        val_b = B[j];
      }
    }
  }
  cout<<val_a<<" "<<val_b<<endl;
}
int main()
{
  int A[] = {4, 1, 2, 1, 1, 2};
  int n = sizeof(A)/sizeof(A[0]);
  int B[] = {3, 6, 3, 3};
  int m = sizeof(B)/sizeof(B[0]);
  SumSwap(A, n, B, m);
  return 0;
}
