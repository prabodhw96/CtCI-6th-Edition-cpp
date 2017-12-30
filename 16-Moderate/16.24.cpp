#include <iostream>
using namespace std;
void PairSums(int arr[], int n, int sum)
{
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(arr[i]+arr[j] == sum)
        cout<<arr[i]<<" "<<arr[j]<<endl;
}
int main()
{
  int arr[] = {1, 5, 7, -1, 5} ;
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 6;
  PairSums(arr, n, sum);
  return 0;
}
