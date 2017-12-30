#include <iostream>
#include <vector>
using namespace std;
int getMissingNo(int a[], int n)
{
  int i, total;
  total  = (n+1)*(n+2)/2;
  for(i=0; i<n; i++)
    total -= a[i];
  return total;
}
void findTwoMissingNos(int arr[], int n)
{
  vector<bool> mark(n+1, false);
  for(int i=0; i<n-2; i++)
    mark[arr[i]] = true;
  cout<<"Two missing nos. are: ";
  for(int i=1; i<=n; i++)
    if(!mark[i])
      cout<<i<<" ";
  cout<<endl;
}
int main()
{
  int a[] = {1,2,4,5,6};
  int miss = getMissingNo(a,5);
  cout<<"Missing no. :"<<miss<<endl;
  int arr[] = {1, 3, 5, 6};
  int n = 2 + sizeof(arr)/sizeof(arr[0]);
  findTwoMissingNos(arr, n);
  return 0;
}
